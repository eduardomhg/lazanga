#region Dependancies
using System;
using System.Collections.Generic;
using System.Text;
using System.Net;
using System.Net.Sockets;
#endregion

namespace SMOCG {
    /// <summary>
    /// The NetManager sets up and controls all the NetConnections
    /// </summary>
    public class NetManager {
        private CardGameScene _game; // a reference to the cardGameScene object that created the NetManager

        private AsyncCallback _aSyncCallback; // the function to call when a client connects
        private Socket _listener; // a socket to listen for incoming connections
        private int _listenPort = 9000; // the port to open to listen to incoming communications
        private int _connectionNum = 0; // a number to identify the connection

        private int _playerControlled; // which player is this client controlling

        private bool _gameStarter = false; // is this the game starter, that other clients connect to

        public string Current = "";

        // a list of the connections managed and connections before the player (in case the gamestarter drops)
        private List<NetConnection> _connections = new List<NetConnection>(SMOCGGame.Settings.MaxPlayers);
        private List<NetConnection> _connectionsBeforeMe = new List<NetConnection>(SMOCGGame.Settings.MaxPlayers);

        private bool _sendThisCustomisation = false;
        private int _numConnectionsToRegister = -1;
        private int _numConnectionsRegistered = 0;

        #region GetSet Properties

        /// <summary>
        /// Set the number of connections to register
        /// </summary>
        public int NumConnectionToRegister {
            set { this._numConnectionsToRegister = value; }
        }

        /// <summary>
        /// Get and set the port to open to listen to incoming communications
        /// </summary>
        public int ListenPort {
            get { return this._listenPort; }
            set { this._listenPort = value; }
        }

        /// <summary>
        /// Get and set whether this is the game starter that other clients connect to.
        /// This is necessary to know if the command to open ports should go out
        /// </summary>
        public bool GameStarter {
            get { return this._gameStarter; }
            set { this._gameStarter = value; }
        }

        /// <summary>
        /// Get the reference to the CardGameScene
        /// </summary>
        public CardGameScene CardGame {
            get { return this._game; }
        }

        /// <summary>
        /// Get and set which player this client is controlling
        /// </summary>
        public int PlayerControlled {
            get { return this._playerControlled; }
            set { 
                this._playerControlled = value;
                this.Current = "Controlling player " + this._playerControlled;
            }
        }

        /// <summary>
        /// Get the list of NetConnections that the manager holds
        /// </summary>
        public List<NetConnection> Connections {
            get { return this._connections; }
        }

        #endregion

        /// <summary>
        /// Create the NetManager and setup the connection callback
        /// </summary>
        public NetManager(CardGameScene cgs) {
            this._game = cgs;
            this._aSyncCallback = new AsyncCallback(OnConnection);
        }

        /// <summary>
        /// Get the computer's local IP address
        /// </summary>
        /// <returns>A string of the computer's ip address</returns>
        public string GetThisIp() {
            IPHostEntry ip = Dns.GetHostEntry(Dns.GetHostName());
            foreach (IPAddress sip in ip.AddressList)
                if (sip.ToString().Length > 7) // minimum address length of 1.1.1.1
                    return sip.ToString();
            return "127.0.0.1"; // return the local ip
        }

        /// <summary>
        /// Listen for any incoming connections
        /// </summary>
        public void Listen() {
            Console.WriteLine("*** NetManager::Listen() *** ");
            try {
                Console.WriteLine("NetManager is listening on port " + this._listenPort);
                //create the listening socket
                this._listener = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                IPEndPoint local = new IPEndPoint(IPAddress.Any, this._listenPort);
                this._listener.Bind(local); //bind to local ip address
                this._listener.Listen(SMOCGGame.Settings.MaxPlayers); // setup number of pending connections
                this._listener.BeginAccept(this._aSyncCallback, null); // begin accepting anyone who connects
                if(this._gameStarter) this.Current = "Player 0";
            }
            catch (SocketException se) {
                Console.WriteLine("ERROR! In Listen() - " + se.Message);
            }
        }

        /// <summary>
        /// Called when a connection is being established
        /// </summary>
        /// <param name="iar">The async result</param>
        private void OnConnection(IAsyncResult iar) {
            Console.WriteLine("*** NetManager::OnConnection() *** ");
            try {
                Console.WriteLine("connecting a client");
                // don't allow the connection if there's too many people
                if ((this._gameStarter && this._game.NumberOfPlayers == SMOCGGame.Settings.MaxPlayers) ||
                    this._game.GameStarted)
                    return;
                NetConnection conn = new NetConnection(this, this._connectionNum++);
                conn.Socket = this._listener.EndAccept(iar); // set the NetConnection's socket
                Console.WriteLine(conn.Socket.RemoteEndPoint + " endpoint");
                Console.WriteLine(this._listener.LocalEndPoint + " listener endpoint");
                this._connections.Add(conn);
                Console.WriteLine("connected connection number " + conn.ConnectionNumber);
                // begin to accept the next one
                if (this._connections.Count < SMOCGGame.Settings.MaxPlayers) this._listener.BeginAccept(this._aSyncCallback, null);
                // if this is the game that other clients connect to, tell the new connection which port to open for listening
                if (this._gameStarter) {
                    Console.WriteLine("***** PLAYER ADDED BECAUSE OF ON CONNECTION AND GAMESTARTER ***** ");
                    this._game.AddPlayer(false);
                    conn.PlayerNumber = this._game.NumberOfPlayers - 1; // set the connection's player number
                    string welcomeMessage = "WP" + conn.PlayerNumber;
                    if (this._game.GetUser != null) welcomeMessage += "" + (int)this._game.GetUser.HairType + "" + (int)this._game.GetUser.HairColor + "" + (int)this._game.GetUser.SkinColor + "" + this._game.GetUser.Name;
                    else welcomeMessage += "000no_name";
                    conn.Send(welcomeMessage); // welcome the player
                    conn.Send("OP" + (this._listenPort + this._connectionNum));
                    RegisterWithPlayer(conn); // register the connection with the player

                    // if the game has already been dealt, then call for a reset
                    this.Current = "Player " + this._playerControlled;
                    if (this._game.GameDealt)
                        this._game.Reset(true);
                }
                conn.WaitForData(); // listen for some data
            }
            catch (ObjectDisposedException) {
                Console.WriteLine("ERROR! In OnClientConnect() - Socket has been closed (ObjectDisposedException)");
            }
            catch (SocketException se) {
                Console.WriteLine("ERROR! In OnClientConnect() - " + se.Message);
            }
        }

        /// <summary>
        /// Register the connection with the relevant player
        /// </summary>
        /// <param name="conn">The connection to register</param>
        public void RegisterWithPlayer(NetConnection conn) {
            Console.WriteLine("*** NetManager::RegisterWithPlayer(NetConnection " + conn.ConnectionNumber + ") *** ");
            Player player = this._game.GetPlayer(conn.PlayerNumber);
            if (player != null) {
                player.FNRegisterNetConnection(conn); // register the connection with the relevant player
                if (player.PlayerNumber < this._playerControlled)
                    this.AddConnectionBeforeMe(conn); // add it to one of the connections before me
            }
            this._numConnectionsRegistered++;
        }

        /// <summary>
        /// Add a blank connection for yourself, so we can call different methods direct from the Player class
        /// </summary>
        public void AddBlankConnection() {
            Console.WriteLine("*** NetManager::AddBlankConnection() *** ");
            NetConnection conn = new NetConnection(this, this._connectionNum++);
            conn.PlayerNumber = this._playerControlled; // for this player
            this._connections.Add(conn); // add it to the connections list
            this.RegisterWithPlayer(conn); // register it with the player
            this._numConnectionsRegistered++;
        }

        /// <summary>
        /// Add a connection for a player that was there before you. e.g. if you're player 2, then add the connections
        /// for player 0 and player1
        /// </summary>
        /// <param name="conn">The connection to add</param>
        public void AddConnectionBeforeMe(NetConnection conn) {
            lock (this._connectionsBeforeMe)
                this._connectionsBeforeMe.Add(conn);
        }

        /// <summary>
        /// Removes a connection for a player that was there before you, for example, if that player drops his connection
        /// </summary>
        /// <param name="conn">The connection to remove</param>
        public void RemoveConnectionBeforeMe(NetConnection conn) {
            Console.WriteLine("Removing connection before me: connection number " + conn.ConnectionNumber + ", player number " + conn.PlayerNumber);
            Console.WriteLine("Number of connections in this list before doing check = " + this._connectionsBeforeMe.Count);
            lock (this._connectionsBeforeMe) {
                if (this._connectionsBeforeMe.Contains(conn)) // if it's there
                    this._connectionsBeforeMe.Remove(conn); // remove it
                else
                    Console.WriteLine("In RemoveConnectionBeforeMe() - connection isn't in the list");
            }
            Console.WriteLine("Number of connections in this list after doing check = " + this._connectionsBeforeMe.Count);
        }

        /// <summary>
        /// Send data to a particular connection
        /// </summary>
        /// <param name="n">The connection number to send to</param>
        /// <param name="data">The data to send</param>
        public void SendToConnection(int n, string data) {
            Console.WriteLine("sending data to connection - " + n + " - " + data);
            foreach (NetConnection nc in this._connections) {
                if (nc.ConnectionNumber == n) {
                    nc.Send(data);
                    break;
                }
            }
        }

        /// <summary>
        /// Send data to all the connections
        /// </summary>
        /// <param name="data">The data to send</param>
        public void SendToAll(string data) {
            Console.WriteLine("sending data to all connections - " + data);
            lock (this._connections)
                foreach (NetConnection nc in this._connections)
                    nc.Send(data);
        }

        /// <summary>
        /// Send data to all the connections, bar the one specified
        /// </summary>
        /// <param name="n">The connection number not to send to</param>
        /// <param name="data">The data to send</param>
        public void SendToAllExcept(int n, string data) {
            Console.WriteLine("\tsending message " + data + " to all except connection " + n + " - total number of connections = " + this._connections.Count);
            foreach (NetConnection nc in this._connections) {
                if (nc.PlayerNumber != n) {
                    Console.WriteLine("\t\tsending message to connection " + nc.ConnectionNumber);
                    nc.Send(data);
                }
            }
        }

        /// <summary>
        /// Give the addresses that are currently being held out to the connections (bar the one specified)
        /// </summary>
        /// <param name="portNum">The port number that the player who's listening has open</param>
        /// <param name="playerNum">The player who's open for listening and so doesn't receive this message</param>
        public void GiveAddress(NetConnection conn, int portNum, int playerNum) {
            Console.WriteLine("*** NetManager::GiveAddress(NetConnection " + conn.ConnectionNumber + ", int " + portNum + ", playerNum " + playerNum + ") *** ");
            // get the ip address of the socket
            string ip = ((IPEndPoint)conn.Socket.RemoteEndPoint).Address.ToString();
            this.SendToAllExcept(playerNum, "IP" + ip + ":" + portNum + "" + playerNum);
        }

        /// <summary>
        /// Send the shuffled position of the cards to all over the network
        /// </summary>
        /// <param name="sp">The shuffled position</param>
        public void SendShufflePos(string sp) {
            this.SendToAll("SP" + sp);
        }

        /// <summary>
        /// Send that the player is ready to begin
        /// </summary>
        public void SendReadyToBegin() {
            this.SendToAll("RB");
        }

        /// <summary>
        /// Send that the player has put some cards on the pickup pile
        /// </summary>
        /// <param name="pc">The cards that the player has placed, in string form</param>
        public void SendPutCardsInPickupPile(string pc) {
            this.SendToAll("PP" + pc);
        }

        /// <summary>
        /// Send that the player has ended his turn
        /// </summary>
        public void SendEndTurn() {
            this.SendToAll("ET");
        }

        /// <summary>
        /// Send that the player has just picked up
        /// </summary>
        public void SendPickup() {
            this.SendToAll("PU");
        }

        /// <summary>
        /// Tell all the players to reset the game
        /// </summary>
        public void SendReset() {
            this.SendToAll("RG");
        }

        /// <summary>
        /// Send this customisation to all the players
        /// </summary>
        public void SendThisCustomisation() {
            string registerMessage = "RP";
            if (this._game.GetUser != null) registerMessage += "" + (int)this._game.GetUser.HairType + "" + (int)this._game.GetUser.HairColor + "" + (int)this._game.GetUser.SkinColor + "" + this._game.GetUser.Name;
            else registerMessage += "000no_name";
            this.SendToAll(registerMessage); // register the player that this client is controlling with the client you're connecting to
        }

        /// <summary>
        /// Send that a player has left the game
        /// </summary>
        /// <param name="deleted">The player index to be deleted</param>
        /// <param name="newPlayerNumber">This client's new player number</param>
        public void SendDeletePlayer(int deleted, int newPlayerNumber) {
            Console.WriteLine("*** NetManager::SendDeletePlayer(int " + deleted + ", int " + newPlayerNumber + ") *** ");
            Console.WriteLine("NetManager has changed his playerControlled number from " + this._playerControlled + " to " + newPlayerNumber);
            this.PlayerControlled = newPlayerNumber;
            foreach (NetConnection conn in this._connections)
                conn.Send("DP" + deleted + "" + conn.PlayerNumber);
        }

        /// <summary>
        /// Remove a connection from the list of managed connections
        /// </summary>
        /// <param name="conn">The connection to remove</param>
        public void RemoveConnection(NetConnection conn) {
            Console.WriteLine("Removing connection " + conn.ConnectionNumber + " from list");
            Console.WriteLine("number of connections before " + this._connections.Count);
            lock (this._connections) {
                conn.Close(); // close the connection
                this._connections.Remove(conn); // remove it
            }
            Console.WriteLine("number of connection after " + this._connections.Count);
        }

        /// <summary>
        /// Make sure all of the connections are active
        /// </summary>
        public void Update() {
            //check to see if we have to send this clients customisations yet
            if (this._numConnectionsToRegister != -1 && this._numConnectionsRegistered > this._numConnectionsToRegister && !this._sendThisCustomisation) {
                this.SendThisCustomisation();
                this._sendThisCustomisation = true;
            }
            // go through the connections list and remove any inactive ones (one at a time)
            NetConnection conn = null;
            foreach (NetConnection nc in this._connections)
                if (!nc.Active)
                    conn = nc;
            if (conn != null) {
                Console.WriteLine("==== in NetManager Update ====");
                Console.WriteLine("conn connection number = " + conn.ConnectionNumber + ", conn.player number = " + conn.PlayerNumber);
                Console.WriteLine("this player controlled = " + this._playerControlled);
                Console.WriteLine("========");
                this.RemoveConnectionBeforeMe(conn);
                Console.WriteLine("Number of connections before me = " + this._connectionsBeforeMe.Count);
                if (this._connectionsBeforeMe.Count == 0 && !this._gameStarter && this._game.PlayersLeftInGame > 0) {
                    Console.WriteLine("There's no connections before me - I'm assuming the gameStater tag");
                    AssumeGameStarter();
                    if (!this._game.GameDealt)
                        this._game.HUD.ButtonActivation(HUDButtons.Deal, true);
                }
                if (conn.Connected && this._gameStarter) {
                    Player player = this._game.GetPlayer(conn.PlayerNumber);
                    Console.WriteLine("how many cards does the player have in his hand? " + player.Cards.Count);
                    if (player.Cards.Count > 0) {
                        if (this._game.GameStarted) {
                            Console.WriteLine("Burning player " + player.PlayerNumber + "'s cards, as a game is underway");
                            Console.WriteLine("Is it the player's turn? " + player.IsMyTurn);
                            this._game.BurnPlayersCards(player.Cards);
                            this.SendToAll("BC" + player.PlayerNumber); // tell the other clients to burn the cards
                            this._game.RemovePlayer(conn.PlayerNumber); // remove the player
                            if (this._game.NumberOfPlayers == 1)
                                this._game.Reset(false); // reset the game
                        } else {
                            this._game.RemovePlayer(conn.PlayerNumber); // remove the player
                            if (this._game.NumberOfPlayers > 1) {
                                Console.WriteLine("Should redeal the cards");
                                this._game.Deal(); // redeal the cards
                            } else {
                                Console.WriteLine("Only one person left");
                                this._game.HUD.ButtonActivation(HUDButtons.Deal, false); // hide the deal button if it isn't already
                                this._game.Reset(false); // reset the game
                            }
                        }
                    } else
                        this._game.RemovePlayer(conn.PlayerNumber); // just remove the player
                }
                this.RemoveConnection(conn);
            }
        }

        /// <summary>
        /// Assume the GameStater tag, so reset the listen port
        /// </summary>
        private void AssumeGameStarter() {
            this._gameStarter = true;
            if (this._listener.Connected) {
                this._listener.Shutdown(SocketShutdown.Both);
                this._listener.Disconnect(true);
            }
            this._listenPort = 9000;
            this.Listen();
            // change the game ip
            this._game.GameIP = this.GetThisIp();
            this.SendToAll("GI" + this._game.GameIP); // send the new ip to everybody
        }

        /// <summary>
        /// Set up a NetConnection object, and try and connect to someone
        /// </summary>
        /// <param name="ip">The ip to connect to</param>
        /// <param name="port">The port to connect to</param>
        /// <param name="connPlayer">The player available on this connection</param>
        /// <param name="createPlayer">Whether to create a player because of the connection</param>
        public bool ConnectToAddress(string ip, int port, int connPlayer, bool createPlayer) {
            Console.WriteLine("*** NetManager::ConnectToAddress(string " + ip + ", int " + port + ", int " + connPlayer + ", bool " + createPlayer + ") ***");
            NetConnection conn = new NetConnection(this, this._connectionNum++);
            this._connections.Add(conn);
            conn.PlayerNumber = connPlayer; // set the player that this connection will lead to
            bool connected = conn.Connect(ip, port);
            if (connected && createPlayer) {
                Console.WriteLine("***** PLAYER ADDED BECAUSE OF CONNECT TO ADDRESS *****");
                Console.WriteLine("Client " + this._playerControlled + " added a connection - number " + conn.ConnectionNumber + " - for player " + conn.PlayerNumber);
                string registerMessage = "RP";
                if (this._game.GetUser != null) registerMessage += "" + (int)this._game.GetUser.HairType + "" + (int)this._game.GetUser.HairColor + "" + (int)this._game.GetUser.SkinColor + "" + this._game.GetUser.Name;
                else registerMessage += "000no_name";
                conn.Send(registerMessage); // register the player that this client is controlling with the client you're connecting to
                this._game.AddPlayer(false);
                this.RegisterWithPlayer(conn); // register the connection with the player
            }
            if(connected && connPlayer == 0)
                this._game.GameIP = ((IPEndPoint)conn.Socket.RemoteEndPoint).Address.ToString(); // hold the game ip
            return connected;
        }

        public void Write() {
            Console.WriteLine("----");
            Console.WriteLine("Number of connections = " + this._connections.Count);
            foreach (NetConnection c in this._connections)
                Console.WriteLine("\t\t connection number " + c.ConnectionNumber + " controls player number " + c.PlayerNumber);
            Console.WriteLine("Number of connections before me = " + this._connectionsBeforeMe.Count);
            foreach (NetConnection c in this._connectionsBeforeMe)
                Console.WriteLine("\t\t connection number " + c.ConnectionNumber + " controls player number " + c.PlayerNumber);
            Console.WriteLine("----");
        }
    }
}
