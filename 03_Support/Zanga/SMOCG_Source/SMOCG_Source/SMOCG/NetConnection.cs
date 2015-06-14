#region Dependancies
using System;
using System.Collections.Generic;
using System.Text;
using System.Net;
using System.Net.Sockets;
#endregion

namespace SMOCG {
    /// <summary>
    /// The NetConnection class handles the sending and receiving of data from other player connections
    /// </summary>
    public class NetConnection {
        private NetManager _manager; // a reference to the manager object

        private int _connectionNum; // the connection number, just used for internal identification
        private int _playerNum; // the player number that the connection is supposed to control
        private Socket _socket; // the socket used for receiving data
        private EndPoint _ep; // the end point of the netConnection
        private byte[] _buffer = new byte[256]; // the data buffer

        private bool _active = true; // is this connection active
        private bool _connected = false; // is the socket connected

        private IAsyncResult _iaSyncResult; // the async result from waiting for data
        private AsyncCallback _aSyncCallback; // the onDataReceived callback

        private StringBuilder _sb = new StringBuilder(); // a string builder object - to hold incoming commands
        private int _currentMsgLength = 0; // the length of the current message being received
        private bool _currentMsgLengthReceived = false; // has the current message length been parsed

        #region GetSet Properties

        /// <summary>
        /// Get the connection number
        /// </summary>
        public int ConnectionNumber {
            get { return this._connectionNum; }
            set { this._connectionNum = value; }
        }

        /// <summary>
        /// The player that this connection leads to
        /// </summary>
        public int PlayerNumber {
            get { return this._playerNum; }
            set { this._playerNum = value; }
        }

        /// <summary>
        /// Get the NetConnection's receiving socket
        /// </summary>
        public Socket Socket {
            get { return this._socket; }
            set { 
                this._socket = value;
                this._ep = this._socket.LocalEndPoint;
                this._connected = true;
            }
        }

        /// <summary>
        /// Get the endPoint for this connection
        /// </summary>
        public EndPoint EndPoint {
            get { return this._ep; }
            set { this._ep = value; }
        }

        /// <summary>
        /// Get and Set whether the NetConnection is active
        /// </summary>
        public bool Active {
            get { return this._active; }
            set { this._active = value; }
        }

        /// <summary>
        /// Get whether the NetConnection object is connected or not
        /// </summary>
        public bool Connected {
            get { return this._connected; }
        }

        #endregion

        /// <summary>
        /// Create a new NetConnection object, and set up the onDataReceived callback
        /// </summary>
        /// <param name="nm">A reference to the NetManager object</param>
        /// <param name="n">The number of the netConnection</param>
        public NetConnection(NetManager nm, int n) {
            this._manager = nm;
            this._connectionNum = n;
            this._aSyncCallback = new AsyncCallback(OnDataReceived);
        }

        /// <summary>
        /// Connect the socket of the NetConnection to a specific ip
        /// </summary>
        public bool Connect(string ip, int port) {
            try {
                Console.WriteLine("trying to connect connection number " + this._connectionNum + " to ip " + ip);
                //create a new socket
                this._socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                IPAddress ipParse = IPAddress.Parse(ip); //get the remote ip address
                IPEndPoint ep = new IPEndPoint(ipParse, port); //create the endpoint
                this._socket.Connect(ep); //connect to the remote host
                this._connected = true; // the socket has connected
                WaitForData(); //watch for data (asynchronously)
                return true;
            }
            catch (SocketException se) {
                this._active = false;
                Console.WriteLine("ERROR! In Connect() - " + se.Message);
                return false;
            }
        }

        /// <summary>
        /// Close the NetConnection
        /// </summary>
        public void Close(){
            Console.WriteLine("closing socket on connection number " + this._connectionNum);
            try {
                if (this._socket.Connected) {
                    this._socket.Shutdown(SocketShutdown.Both); // shutdown the send and receive
                    this._socket.Disconnect(true); // close the socket connection, and allow reuse
                }
            }
            catch (SocketException se) {
                Console.WriteLine("ERROR! In Close() - " + se.Message);
            }
        }

        /// <summary>
        /// Wait for data
        /// </summary>
        public void WaitForData() {
            if (this._active && this._connected) {
                try {
                    Console.WriteLine("waiting for data for connection " + this._connectionNum);
                    //start listening for any data
                    this._iaSyncResult = this._socket.BeginReceive(this._buffer,
                                                                        0,
                                                                        this._buffer.GetLength(0),
                                                                        SocketFlags.None,
                                                                        this._aSyncCallback,
                                                                        null);
                }
                catch (SocketException se) {
                    this._active = false;
                    Console.WriteLine("ERROR! In WaitForData() - connection " + this._connectionNum + " - " + se.Message);
                }
            }
        }

        /// <summary>
        /// Some data has been received
        /// </summary>
        /// <param name="iar">The async result object</param>
        private void OnDataReceived(IAsyncResult iar) {
            if (this._active && this._connected) {
                try {
                    //end receive
                    int n = this._socket.EndReceive(iar);
                    char[] chars = new char[n];
                    Decoder d = Encoding.UTF8.GetDecoder();
                    int charLen = d.GetChars(this._buffer, 0, n, chars, 0);
                    this._sb.Append(chars);
                    Console.WriteLine("\n--------------------------");
                    Console.WriteLine("Data received from connection " + this._connectionNum + " - player number - " + this._playerNum + " - " + this._sb.ToString());
                    Console.WriteLine("--------------------------");
                    lock (this) {
                        ParseData(); // parse the data to see if there's a full command in there
                    }
                    WaitForData(); // wait for more data
                }
                catch (ObjectDisposedException) {
                    this._active = false;
                    Console.WriteLine("ERROR! In OnDataReceived() - The socket has been closed (ObjectDisposedException) - connection " + this._connectionNum);
                }
                catch (SocketException se) {
                    this._active = false;
                    Console.WriteLine("ERROR! In OnDataReceived() - connection " + this._connectionNum + " - " + se.Message);
                }
            }
        }

        /// <summary>
        /// Parse the stringbuilder object to get the messages out
        /// </summary>
        private void ParseData() {
            Console.WriteLine("Parsing data in string builder - " + this._sb.ToString());
            if (this._sb.Length >= 4 && !this._currentMsgLengthReceived) { // we first need to know the length of the message
                char[] len = new char[4]; // create a new char array to hold the length
                this._sb.CopyTo(0, len, 0, 4); // copy the length into the char array
                this._sb.Remove(0, 4); // remove it from the string
                this._currentMsgLength = int.Parse(new string(len)); // get the length of the message coming in
                this._currentMsgLengthReceived = true;
            }
            if (this._currentMsgLengthReceived && this._sb.Length >= this._currentMsgLength) {
                char[] charMsg = new char[this._currentMsgLength]; // create a new char array to hold the message
                this._sb.CopyTo(0, charMsg, 0, this._currentMsgLength); // copy the chars over
                this._sb.Remove(0, this._currentMsgLength); // remove them from the string builder
                this._currentMsgLengthReceived = false; // reset the bool for the next message
                ParseCommands(charMsg); // parse the commands sent
                if (this._sb.Length > 0)
                    ParseData(); // if there's any more to the message, parse it
            }
        }

        /// <summary>
        /// Parse the commands contained in the last message
        /// </summary>
        /// <param name="charMsg">The char array that is the last command</param>
        private void ParseCommands(char[] charMsg) {
            if (charMsg[0] == 'W' && charMsg[1] == 'P') // WELCOME PLAYER
            {
                /*
                 * the player is being welcomed into the game, and should receive his playerNumber and connection id
                 */
                this._manager.PlayerControlled = int.Parse(new string(charMsg[2], 1)); // this is the player that the client will control
                this._playerNum = int.Parse(new string(charMsg[charMsg.Length - 1], 1)); // this is the player number that this connection is from

                this._manager.CardGame.Player0HairType = int.Parse(new string(charMsg[3], 1));
                this._manager.CardGame.Player0HairColour = int.Parse(new string(charMsg[4], 1));
                this._manager.CardGame.Player0SkinColour = int.Parse(new string(charMsg[5], 1));
                this._manager.CardGame.Player0Name = new string(charMsg, 5, charMsg.Length - 7);

                // the number of players there before you is the player number you control + 1
                // so add the relevant players
                this._manager.CardGame.NumPlayersToAdd = this._manager.PlayerControlled + 1;
                this._manager.CardGame.PlayerControlled = this._manager.PlayerControlled;
                this._manager.CardGame.MustAddPlayers = true;
            } 
            else if (charMsg[0] == 'R' && charMsg[1] == 'P') // REGISTER PLAYER
            {
                /*
                 * we're being asked to register a player to a connection
                 */
                this._playerNum = int.Parse(new string(charMsg[charMsg.Length - 1], 1)); // this is the player number that this connection is from
                int playerHairType = int.Parse(new string(charMsg[2], 1));
                int playerHairColour = int.Parse(new string(charMsg[3], 1));
                int playerSkinColour = int.Parse(new string(charMsg[4], 1));
                string playerName = new string(charMsg, 5, charMsg.Length - 6);
                Console.WriteLine("Received register request to register player " + this._playerNum + " on connection " + this._connectionNum);
                Console.WriteLine("Player " + this._playerNum + " has hair type " + playerHairType + ", hair colour " + playerHairColour + ", skin colour " + playerSkinColour + ", name " + playerName);
                this._manager.RegisterWithPlayer(this); // register the net connection with the player
                this._manager.CardGame.FNCustomisePlayer(this._playerNum, playerHairType, playerHairColour, playerSkinColour, playerName); // customise the player
            } 
            else if (charMsg[0] == 'O' && charMsg[1] == 'P') // OPEN PORT
            {
                /*
                 * we're to open a port so other people can connect to us
                 */
                string portNum = new string(charMsg, 2, 4);
                //this._manager.Current = "opening port on port number " + portNum;
                this._manager.ListenPort = int.Parse(portNum); // set the port number with the manager
                this._manager.Listen(); // tell the manager to listen to incoming communications
            } 
            else if (charMsg[0] == 'P' && charMsg[1] == 'O') // PORT OPEN
            {
                /*
                 * another player has told us that his port is open for listening
                 * so pass the player's ip to everyone else
                 * NOTE: only the player that started the game should receive this message
                 */
                string portNum = new string(charMsg, 2, 4); // the port number that the player has open
                string playerNum = new string(charMsg[charMsg.Length - 1], 1); // the player that the message is coming from
                Console.WriteLine("portNum = " + portNum + ", playerNum = " + playerNum);
                //this._manager.Current = "player " + playerNum + " has opened his port for listening";
                this._manager.GiveAddress(this, int.Parse(portNum), int.Parse(playerNum)); // get the manager class to give out the ips
            } 
            else if (charMsg[0] == 'I' && charMsg[1] == 'P') // IP ADDRESS RECEIVED
            {
                /*
                 * we're after receiving an ip / port combination to connect to
                 */
                string ipPort = new string(charMsg, 2, charMsg.Length - 4); // take out the ip and port part of the message
                //this._manager.Current = "making connection to " + ipPort;
                int n = ipPort.IndexOf(':'); // get the divider pos
                string ip = ipPort.Substring(0, n); // substring out the ip address
                string port = ipPort.Substring(n + 1, 4); // substring out the port num
                int connPlayer = int.Parse(new string(charMsg, charMsg.Length - 2, 1)); // the player available on this connection
                this._manager.ConnectToAddress(ip, int.Parse(port), connPlayer, true); // connect to the address
            } 
            else if (charMsg[0] == 'S' && charMsg[1] == 'P') // SHUFFLE POSITIONS
            {
                /*
                 * we're after receiving a command to shuffle the cards, along with their shuffled position
                 * the shuffled position begins after the 'SP' command, and ends before the ' 0' tag that
                 * signifies the player it came from
                 */
                string sp = new string(charMsg, 2, charMsg.Length - 4);
                this._manager.CardGame.FNSetShuffledCardsAndDeal(sp); // get the card game to set the cards position and deal
            } 
            else if (charMsg[0] == 'S' && charMsg[1] == 'C') // SWAP CARDS
            {
                /*
                 * we're after receiving a command to swap two cards of the client
                 * the message contains the original card numbers of the two cards to be swapped, as
                 * well as the player who initially sent the message
                 */
                string sc = new string(charMsg, 2, charMsg.Length - 3);
                int pn = int.Parse(new string(charMsg[charMsg.Length - 1], 1)); // the player who requested the move
                Console.WriteLine("Player " + pn + " requested that we swap two of his cards: " + sc);
                this._manager.CardGame.FNSwapPlayersCards(sc, pn); // swap the cards
            } 
            else if (charMsg[0] == 'R' && charMsg[1] == 'B') // READY TO BEGIN
            {
                /*
                 * we received a message from a player telling us that he's ready to begin
                 */
                int pn = int.Parse(new string(charMsg[2], 1));
                Console.WriteLine("Player " + pn + " is ready to begin playing");
                this._manager.CardGame.FNPlayerReadyToBegin(pn); // tell the card game that the player is ready
            } 
            else if (charMsg[0] == 'P' && charMsg[1] == 'P') // PUT CARDS ON PICKUP PILE
            {
                /*
                 * we received a message from a player telling us that he's put some cards in the pickup pile
                 */
                string pc = new string(charMsg, 2, charMsg.Length - 4); // the cards being put down
                int pn = int.Parse(new string(charMsg[charMsg.Length - 1], 1)); // the player doing it
                Console.WriteLine("Player " + pn + " has put cards (" + pc + ") in the pickup pile");
                this._manager.CardGame.FNPlaceCardsInPickupPile(pc, pn); // tell the card game that the player is putting the cards on the pickup pile
            }
            else if (charMsg[0] == 'E' && charMsg[1] == 'T') // END TURN
            {
                /*
                 * we've received a message from a player telling us that he's ended his turn
                 */
                int pn = int.Parse(new string(charMsg[2], 1)); // the player telling us
                Console.WriteLine("Player " + pn + " has ended his turn");
                this._manager.CardGame.FNEndTurn(pn); // tell the card game that the player has ended his turn
            } 
            else if (charMsg[0] == 'P' && charMsg[1] == 'U') // PICKUP
            {
                /*
                 * we've received a message from a player telling us that he's just picked up
                 */
                int pn = int.Parse(new string(charMsg[2], 1)); // the player telling us
                Console.WriteLine("Player " + pn + " has just picked up");
                this._manager.CardGame.FNPickup(pn); // tell the card game that the player has just picked up
            } 
            else if (charMsg[0] == 'D' && charMsg[1] == 'P') // DELETE PLAYER
            {
                /*
                 * we've received a message telling us that a player has been deleted
                 */
                int dpn = int.Parse(new string(charMsg[2], 1));
                int npn = int.Parse(new string(charMsg[3], 1));
                int fpn = int.Parse(new string(charMsg[4], 1));
                Console.WriteLine("Just been asked to delete a player");
                Console.WriteLine("\tDeleted player number = " + dpn);
                Console.WriteLine("\tThis new player number = " + npn + ", player controlled = " + this._manager.PlayerControlled);
                Console.WriteLine("\tReceived message from player number = " + fpn + ", previous number = " + this._playerNum);
                this._manager.PlayerControlled = npn; // assing the new player controlled
                this._manager.CardGame.PlayerControlled = npn; // assign it with the card game as well
                lock (this._manager.CardGame.Players) {
                    Console.WriteLine("\tNew manager player controlled = player " + this._manager.PlayerControlled);
                    Console.WriteLine("\tNew manager card game player controlled = player " + this._manager.CardGame.PlayerControlled);
                    Console.WriteLine("\tChanging player " + this._manager.CardGame.GetPlayer(this._playerNum).PlayerNumber + "'s number to " + fpn + " log number to " + (fpn + 1));
                    this._manager.CardGame.GetPlayer(this._playerNum).LogNumber = fpn + 1; // change the log number
                    this._manager.CardGame.GetPlayer(this._playerNum).PlayerNumber = fpn; // change the player number with the player
                }
                this._playerNum = fpn; // if the player number has changed
                this._manager.CardGame.FNRemovePlayer(dpn);
                this._manager.SendToAll("CN"); // send to change the number
            }
            else if (charMsg[0] == 'C' && charMsg[1] == 'N') // CHANGE NUMBER
            {
                /*
                 * we've been asked to change the number that this connection lead to
                 */
                int npn = int.Parse(new string(charMsg[2], 1));
                Console.WriteLine("Just been asked to change the player number that this connection leads to");
                Console.WriteLine("changing the player number from " + this._playerNum + " to " + npn);
                this._manager.CardGame.FNArrangePlayer(this._playerNum, npn); // tell the card game to arrange the player
                this._playerNum = npn;
            } 
            else if (charMsg[0] == 'B' && charMsg[1] == 'C') // BURN CARDS
            {
                /*
                 * we've been asked to burn a specific player's cards
                 */
                int pn = int.Parse(new string(charMsg[2], 1));
                Console.WriteLine("Burning player " + pn + "'s card's because he's left the game");
                this._manager.CardGame.FNBurnPlayersCards(pn);
            } 
            else if (charMsg[0] == 'R' && charMsg[1] == 'G') // RESET GAME
            {
                /*
                 * we've been asked to reset the game
                 */
                Console.WriteLine("Resetting the game as as result of being asked over the network");
                this._manager.CardGame.Reset(false);
            } 
            else if (charMsg[0] == 'G' && charMsg[1] == 'I') // CHANGE THE GAME IP
            {
                /*
                 * we've been asked to change the game ip
                 */
                string nip = new string(charMsg, 2, charMsg.Length - 3); // the new game ip
                lock (this._manager.CardGame.GameIP)
                    this._manager.CardGame.GameIP = nip;
            } 
            else if (charMsg[0] == 'C' && charMsg[1] == 'M') // CHAT MESSAGE
            {
                /*
                 * we've received a chat message
                 */
                string msg = new string(charMsg, 2, charMsg.Length - 3); // the chat message
                int pn = int.Parse(new string(charMsg[charMsg.Length - 1], 1)); // the player who sent it
                PlayerColorChoice color = PlayerColorChoice.White;
                Player p = this._manager.CardGame.GetPlayer(pn);
                if (p != null)
                    color = p.SkinColor;
                this._manager.CardGame.HUD.AddLogMessage(msg, color);
            }
            else 
            {
                /*
                 * bad message
                 */
                string msg = new string(charMsg);
                Console.WriteLine("ERROR! Bad Message - " + msg);
                //this._manager.Current = "error - bad command - " + msg;
            }
            //this._manager.Current = "this id is " + this._connectionID;
        }

        /// <summary>
        /// Send data down the socket
        /// </summary>
        /// <param name="sendData">The data to send in string form</param>
        public void Send(string sendData) {
            if (this._active && this._connected) {
                Console.WriteLine("appending length of message to the message itself");
                // append the length of the message onto the string
                byte[] data = Encoding.UTF8.GetBytes(this.AppendMessage(sendData));
                try {
                    this._socket.Send(data);
                }
                catch (SocketException se) {
                    this._active = false;
                    Console.WriteLine("ERROR! In Send(string) - connection " + this._connectionNum + " - " + se.Message);
                }
            }
        }

        /// <summary>
        /// Send the message that the port is open so people can connect to us
        /// </summary>
        public void SendPortOpenCall() {
            this.Send("PO" + this._manager.ListenPort);
        }

        /// <summary>
        /// Send a message stating that the player has swapped two of his cards
        /// </summary>
        /// <param name="sc">A string representing the two cards that were swapped</param>
        public void SendSwapCards(string sc) {
            this._manager.SendToAll("SC" + sc);
        }

        /// <summary>
        /// Send a chat message to the other players
        /// </summary>
        /// <param name="cm">The message to send</param>
        public void SendChatMessage(string cm) {
            this._manager.SendToAll("CM" + cm);
        }

        /// <summary>
        /// Append the length of the message to the message itself, so when data is received, it can be parsed correctly.
        /// it also appends the player controlled onto the end of every message, so the client receiving it knows who it's from
        /// </summary>
        /// <param name="data">The string to append it's length onto</param>
        /// <returns>A new string with the length of the message appending to the end</returns>
        private string AppendMessage(string data) {
            int n = data.Length + 1;
            string temp;
            if (n < 10)
                //data.Insert(0, "000" + n);
                temp = "000" + n + data;
            else if (n < 100)
                //data.Insert(0, "00" + n);
                temp = "00" + n + data;
            else if (n < 1000)
                //data.Insert(0, "0" + n);
                temp = "0" + n + data;
            else
                //data.Insert(0, n.ToString());
                temp = n + data;

            temp += "" + this._manager.PlayerControlled;

            Console.WriteLine("message to send = " + temp);

            return temp;
        }
    }
}
