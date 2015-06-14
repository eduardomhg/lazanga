#region Dependancies
using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using SMOCG.Cameras;
#endregion

namespace SMOCG {
    /// <summary>
    /// The CardGameScene class sets up a new card game between players, setting up the player objects,
    /// table, and deck
    /// </summary>
    public class CardGameScene : Scene {
        private bool _TRACE = false;

        private InputHelper _input; // the input helper
        private NetManager _netManager; // the net manager

        private bool _startGame; // start the game, or join one
        
        // when a client connects to another client, he receives a welcome message with his player number
        // on the end of it. this tells him to add n number of players to the game (using the _mustAddPlayers)
        // bool. after that he gets a message telling him to open a port so other people can connect and
        // register their connections with a particular player. the _returnNCcall int keeps a record of the
        // NetConnection that asked for players to be added and is waiting on connections. we want the players
        // to have been added before other players can connect, otherwise we try to register connections to null
        // player objects.
        private int _returnNCCall;

        private List<Player> _players = new List<Player>(SMOCGGame.Settings.MaxPlayers);
        private Player _user; // a reference to the player that's the user
        private int _currPlayer = 0; // the current player - who's go it it
        private int _numStartPlayers; // the number of players at the start, when the game is being made
        private int _playerControlled; // the player being controlled
        private int _highestPlayerNumber; // the number of players that started the game

        private bool _mustAddPlayers = false; // do i have to add any players (when connecting to a game)
        private int _numPlayersToAdd; // the number of players to add (when connecting to a game)
        private int _numPlayersLeftToGetReady; // the number of players left to get ready
        private int _player0HairType = 0;
        private int _player0HairColour = 0;
        private int _player0SkinColour = 0;
        private string _player0Name = "no_name";


        private Table _table; // the table where the player sit
        private GameObject _tableFocus; // the focus model for the table
        private GameObject _turnArrow; // the arrow that points to the player whos turn it is
        private InGameHUD _hud; // the in-game hud

        private Deck _deck; // the game deck
        private Rectangle _focusDrawRect; // the focused card draw rectangle
        private Rectangle[] _selectedDrawRect = new Rectangle[4]; // the 4 selected cards draw rectangle
        private Rectangle[] _lastCardsDrawRect = new Rectangle[4]; // the last 4 cards to be placed on the pickup pile
        private Rectangle _drawSourceRect; // which part of the card texture to draw
        private Color _focusCardAlpha = new Color(new Vector4(1.0f, 1.0f, 1.0f, 0.8f)); // what alpha to draw the focus card with

        //variables for the focused / selected card drawing
        private int _cardDrawWidth = 50;
        private int _cardDrawHeight = 100;
        private int _cardDrawSpace = 10;

        private bool _gameStarted = false; // has the game started yet
        private bool _gameDealt = false; // has the game been dealt yet
        private bool _gameFinished = false; // has the game been finished
        private bool _selectSameWithMouse = false; // has the select same card button been pressed by the mouse
                                                    // this is so we don't clear the selected card array when it detects a click that's not on a card
        private string _gameip = ""; // the games ip

        #region GetSet Parameters

        /// <summary>
        /// Get the players list
        /// </summary>
        public List<Player> Players {
            get { return this._players; }
        }

        /// <summary>
        /// Get the game hud
        /// </summary>
        public InGameHUD HUD {
            get { return this._hud; }
        }

        /// <summary>
        /// Get the controlling camera of the user's player
        /// </summary>
        public override BasicCamera ControllingCamera {
            get {
                if (this._user != null)
                    return this._user.Camera;
                else
                    return this.Game.Camera;
            }
        }

        /// <summary>
        /// Get the number of players currently playing
        /// </summary>
        public int NumberOfPlayers {
            get { return this._players.Count; }
        }

        /// <summary>
        /// Get the number of players left in the game
        /// </summary>
        public int PlayersLeftInGame {
            get {
                int n = 0;
                lock (this._players)
                    foreach (Player p in this._players)
                        if (p.GameState != PlayerInGameState.Out)
                            n++;
                return n;
            }
        }

        /// <summary>
        /// Get a particular player based on his number
        /// </summary>
        /// <param name="i">The number of the player you wish to return</param>
        /// <returns>The player object, or null if no players have that number</returns>
        public Player GetPlayer(int i) {
            lock (this._players) {
                foreach (Player p in this._players)
                    if (p.PlayerNumber == i)
                        return p;
            }
            return null;
        }

        /// <summary>
        /// Get the user
        /// </summary>
        /// <returns>The user, or null if it's not set</returns>
        public Player GetUser {
            get {
                if (this._user != null)
                    return this._user;
                return null;
            }
        }

        /// <summary>
        /// Get a particular player at position i in the list of players
        /// </summary>
        /// <param name="i">The position to look for the player</param>
        /// <returns>The player at that position, or null if no player is found</returns>
        public Player GetPlayerAtPos(int i) {
            if (this._players.Count > i)
                return this._players[i];
            return null;
        }

        /// <summary>
        /// Get the deck
        /// </summary>
        public Deck Deck {
            get { return this._deck; }
        }

        /// <summary>
        /// Get and set whether the card game scene should add players
        /// </summary>
        public bool MustAddPlayers {
            get { return this._mustAddPlayers; }
            set { this._mustAddPlayers = value; }
        }

        /// <summary>
        /// Get and set the number of players to add
        /// </summary>
        public int NumPlayersToAdd {
            get { return this._numPlayersToAdd; }
            set { this._numPlayersToAdd = value; }
        }

        /// <summary>
        /// Get and set the player controlled number
        /// </summary>
        public int PlayerControlled {
            get { return this._playerControlled; }
            set { this._playerControlled = value; }
        }

        /// <summary>
        /// Player 0's hair type
        /// </summary>
        public int Player0HairType {
            get { return this._player0HairType; }
            set { this._player0HairType = value; }
        }

        /// <summary>
        /// Player 0's hair colour
        /// </summary>
        public int Player0HairColour {
            get { return this._player0HairColour; }
            set { this._player0HairColour = value; }
        }

        /// <summary>
        /// player 0's skin colour
        /// </summary>
        public int Player0SkinColour {
            get { return this._player0SkinColour; }
            set { this._player0SkinColour = value; }
        }

        /// <summary>
        /// player 0's name
        /// </summary>
        public string Player0Name {
            get { return this._player0Name; }
            set { this._player0Name = value; }
        }

        /// <summary>
        /// Get the current player playing
        /// </summary>
        public int CurrentPlayerPlaying {
            get { return this._currPlayer; }
        }

        /// <summary>
        /// The number of the NetConnection to call after the players have been added
        /// </summary>
        public int ReturnNetConnectionCallNumber {
            get { return this._returnNCCall; }
            set { this._returnNCCall = value; }
        }

        /// <summary>
        /// See if the game has been dealt or not
        /// </summary>
        public bool GameDealt {
            get { return this._gameDealt; }
        }

        /// <summary>
        /// See if the game has been started or not
        /// </summary>
        public bool GameStarted {
            get { return this._gameStarted; }
        }

        /// <summary>
        /// Has the select same cards button been clicked with the mouse
        /// </summary>
        public bool SelectSameWithMouse {
            get { return this._selectSameWithMouse; }
            set { this._selectSameWithMouse = value; }
        }

        /// <summary>
        /// Get and set the GameIp - the IP that users use to connect to the game
        /// </summary>
        public string GameIP {
            get { return this._gameip; }
            set { this._gameip = value; }
        }

        #endregion

        /// <summary>
        /// Create a new card game object
        /// </summary>
        /// <param name="game">A reference to the main game object</param>
        /// <param name="numPlayers">The number of players to make at the start</param>
        /// <param name="playerControlled">The player being controlled</param>
        /// <param name="startGame">Start a game, or join one</param>
        public CardGameScene(SMOCGGame game, int numPlayers, int playerControlled, bool startGame) : base(game) {
            this._input = this.Game.InputHelper; // keep a reference to the input helper
            this._numStartPlayers = numPlayers;
            this._playerControlled = playerControlled;
            this._startGame = startGame;

            // create the draw rectangle for the currently focused card
            int viewportHeight = SMOCGGame.Graphics.GraphicsDevice.Viewport.Height;
            int viewportWidth = SMOCGGame.Graphics.GraphicsDevice.Viewport.Width;
            this._focusDrawRect = new Rectangle(this._cardDrawSpace, viewportHeight - this._cardDrawHeight - this._cardDrawSpace, this._cardDrawWidth, this._cardDrawHeight);
            for (int i = 0; i < 4; i++) {// create the four selected cards draw rectangle
                this._selectedDrawRect[i] = new Rectangle((this._cardDrawWidth + this._cardDrawSpace * 2) + ((this._cardDrawWidth + this._cardDrawSpace) * i),
                                                            viewportHeight - this._cardDrawHeight - this._cardDrawSpace,
                                                            this._cardDrawWidth,
                                                            this._cardDrawHeight);
                this._lastCardsDrawRect[i] = new Rectangle(viewportWidth - 240 + ((this._cardDrawWidth + this._cardDrawSpace) * i),
                                                        viewportHeight - this._cardDrawHeight - this._cardDrawSpace,
                                                        this._cardDrawWidth,
                                                        this._cardDrawHeight);
            }

            //set up the netManager
            this._netManager = new NetManager(this);
        }

        /// <summary>
        /// Create the player, table, and cards
        /// </summary>
        public override void Init() {
            // create the players
            lock (this._players) {
                for (int i = 0; i < this._numStartPlayers; i++)
                    this._players.Add(new Player(this.Game, this)); // add the player's there at the start
            }

            if (this.GetPlayer(this._playerControlled) != null) {
                this._user = this.GetPlayer(this._playerControlled);// this._players[this._playerControlled]; // set the user
                this._user.UserControlled = true; // set who's user controlled
                this._user.Load(SMOCGGame.Settings.PlayerSave); // load what the player looks like
            }

            // create the table
            this._table = new Table(this.Game,                                             // pass the reference to the main game object
                                    this.ControllingCamera,                                 // the camera to view the table with
                                    new Vector3(0),                                         // position
                                    new Vector3(MathHelper.PiOver2, 0.0f, 0.0f),            // rotation - used to correctly orient the model after loading in
                                    new Vector3(10.0f),                                     // scale
                                    SMOCGGame.Settings.ModelLoadPath + "table",             // model path
                                    SMOCGGame.Settings.ModelTexturePath + "darkWood",       // texture path
                                    this._players.Count);                         // number of stools around the table
            this.AddObject(this._table); // add the table to the list

            this._tableFocus = new GameObject(this.Game,
                                                new Vector3(0.0f, 1.5f, 0.0f),
                                                this._table.Rotation,
                                                new Vector3(0.5f),
                                                SMOCGGame.Settings.ModelLoadPath + "tableFocus"); // create the tableFocus

            this._turnArrow = new GameObject(this.Game,
                                                new Vector3(0.0f, 1.0f, 0.0f),
                                                new Vector3(MathHelper.PiOver2, 0.0f, 0.0f),
                                                new Vector3(1.0f),
                                                SMOCGGame.Settings.ModelLoadPath + "arrow"); // create the turn arrow

            this._deck = new Deck(this.Game, this, this.ControllingCamera); // create the deck

            for (int i = 0; i < this._numStartPlayers; i++)
                this.InitPlayer(this.GetPlayer(i));//this._players[i]); // init the players

            this._tableFocus.Camera = this.ControllingCamera;
            this._tableFocus.Shape.Alpha = 0.1f;

            this._turnArrow.Camera = this.ControllingCamera;
            this._turnArrow.Shape.Alpha = 0.2f;

            // define the source rectangle so we only draw the front half of any focused / selected textures
            this._drawSourceRect = new Rectangle(0, 0, this._deck.GetCard(0).Shape.Texture.Width, this._deck.GetCard(0).Shape.Texture.Height / 2);

            //setup the hud
            this._overlay = new InGameHUD(this.Game, this);
            this._hud = (InGameHUD)this._overlay;
            this._hud.Deck = this._deck;
            this._hud.DrawSourceRect = this._drawSourceRect;

            // start or join a game
            if (this._startGame)
                this.StartNetworkGame();
            else
                this.JoinNetworkGame();
        }

        /// <summary>
        /// Start a network game
        /// </summary>
        private void StartNetworkGame() {
            this._netManager.GameStarter = true; // this is the one that other clients connect to
            Console.WriteLine("***** PLAYER ADDED BECAUSE NETWORK LISTEN PRESSED *****");
            this.AddPlayer(true); // add the user as the first player
            this._netManager.Listen();
            this._netManager.AddBlankConnection(); // add a blank connection for the player
            // the game's ip
            this._gameip = this._netManager.GetThisIp(); // get the game's ip
        }

        /// <summary>
        /// Join a network game - show up the input box to input the proper ip
        /// </summary>
        private void JoinNetworkGame() {
            this._hud.Overlay = new JoinGamePopup(this, this.Game);
        }

        /// <summary>
        /// Called by JoinGamePopup class when an ip is submitted - it tries to join to a game at the ip address given
        /// </summary>
        /// <param name="ipAddress">the ip address of the game you want to try to join</param>
        public bool TryToJoinGame(string ipAddress) {
            return this._netManager.ConnectToAddress(ipAddress, 9000, 0, false);
        }

        /// <summary>
        /// Init the player's attributes etc
        /// </summary>
        /// <param name="i">The player to init</param>
        private void InitPlayer(Player p) {
            p.Rotation = this._table.GetChairAngle(p.PlayerNumber);
            p.Position = this._table.GetChairPosition(p.PlayerNumber);
            p.Scale = this._table.Scale;
            p.SetupCamera();
            //p.SkinColor = (PlayerColorChoice)p.PlayerNumber;
            p.Table = this._table;
            p.TableFocus = this._tableFocus;
            this.AddObject(p); // add the player to the gameObject list
        }

        /// <summary>
        /// Add another player to the game
        /// </summary>
        /// <param name="userControlled">Is the player being added user controlled</param>
        public void AddPlayer(bool userControlled) {
            if (this._players.Count < SMOCGGame.Settings.MaxPlayers) {
                this._table.AddStool(); // add another stool to the table

                Player p = new Player(this.Game, this); // create the player
                lock(this._players)
                    this._players.Add(p); // add another player to the list
                if (userControlled) { // if the player is user controlled
                    this._user = p;
                    p.Load(SMOCGGame.Settings.PlayerSave); // load what the player looks like
                    p.UserControlled = true;
                    this._table.Camera = this.ControllingCamera; // set the table's camera
                    this._deck.Camera = this.ControllingCamera; // set the deck's camera
                    this._tableFocus.Camera = this.ControllingCamera; // set the table focus' camera
                    this._turnArrow.Camera = this.ControllingCamera; // set the turn arrow's camera
                }
                this.InitPlayer(p); // init the player

                foreach (Player pl in this._players) {
                    pl.Position = this._table.GetChairPosition(pl.PlayerNumber); // reposition the player around the table
                    pl.Rotation = this._table.GetChairAngle(pl.PlayerNumber); // get the player's new rotation
                    pl.SetCameraPos(); // set the player's camera position
                }

                // log a welcome message in the hud
            this._hud.AddLogMessage(p.PlayerNumber, SMOCGGame.Settings.LogMessages[(int)Log.Player_joined_game], PlayerColorChoice.White);
                if(this._players.Count > 1 && this._netManager.GameStarter) this._hud.ButtonActivation(HUDButtons.Deal, true); // activate the deal button
                // remove the join hud
                this._hud.Overlay = null;
            } else
                if(this._TRACE) Console.WriteLine("too many players, can't do it");
        }

        /// <summary>
        /// Remove a player from the game
        /// </summary>
        /// <param name="i">The player to remove</param>
        public void RemovePlayer(int i) {
            Console.WriteLine("*** CardGameScene::RemovePlayer(int " + i + ") ***");
            if (this._players.Count > 0) {
                this._table.RemoveStool(i); // remove the player's stool
                Player pl = this.GetPlayer(i);

                // log the message with the hud
                this._hud.AddLogMessage(pl.LogNumber, SMOCGGame.Settings.LogMessages[(int)Log.Player_exited_game], pl.SkinColor);

                bool isUser = pl.UserControlled; // are we deleting the user
                this.RemoveObject(pl); // remove the player from the scene object list
                lock(this._players)
                    this._players.Remove(pl); // remove the player
                Player.StatPlayerNumber--;

                if (isUser) { // if we're deleting the user
                    this._user = null;
                    this._table.Camera = this.ControllingCamera; // set the table's camera
                    this._deck.Camera = this.ControllingCamera; // set the deck's camera
                }

                // go through the players
                int n = 0;
                foreach (Player player in this._players) {
                    Console.WriteLine("\tChanging player " + player.PlayerNumber + "'s number to " + n + ", log number to " + (n + 1));
                    player.PlayerNumber = n;
                    player.LogNumber = n + 1;
                    player.NetConnection.PlayerNumber = n; // set the connection's player number
                    player.Position = this._table.GetChairPosition(n); // get their new position
                    player.Rotation = this._table.GetChairAngle(n++); // get their new rotation
                    if (isUser) player.SetupCamera(); // set up the camera if necessary
                    player.SetCameraPos(); // set the camera position
                    player.ArrangeCards(); // arrange the players cardss
                }

                Console.WriteLine("\t\tChanging the user, so settin the player controlled on the manager and card game scene to " + this._user.PlayerNumber);
                this._netManager.PlayerControlled = this._user.PlayerNumber;
                this._playerControlled = this._user.PlayerNumber;

                // tell the netManager to send the delete player message
                this._netManager.SendDeletePlayer(i, this._user.PlayerNumber);
            } else
                if(this._TRACE) Console.WriteLine("no players left to remove");
        }

        /// <summary>
        /// Gets called when a message comes over the network saying that we need to delete a player
        /// </summary>
        /// <param name="i">The player to remove</param>
        public void FNRemovePlayer(int i) {
            Console.WriteLine("*** CardGameScene::FNRemovePlayer(int " + i + ") ***");
            Console.WriteLine("Removing player " + i + " after call from network");
            if (this._players.Count > 0) {
                lock(this._table)
                    this._table.RemoveStool(i); // remove the player's stool

                lock (this._players) {
                    Player pl = this.GetPlayer(i);

                    // log the message with the hud
                    this._hud.AddLogMessage(pl.LogNumber, SMOCGGame.Settings.LogMessages[(int)Log.Player_exited_game], pl.SkinColor);

                    this.RemoveObject(pl); // remove the player from the scene object list
                    this._players.Remove(pl); // remove the player
                    Player.StatPlayerNumber--;
                    Console.WriteLine(Player.StatPlayerNumber + " = stat player number after");
                    Console.WriteLine("The user is changing his player controlled from " + this._user.PlayerNumber + " to " + this._netManager.PlayerControlled);
                    this._user.PlayerNumber = this._netManager.PlayerControlled; // get the new player number
                }

                Console.WriteLine("Number of players left in the game = " + this.PlayersLeftInGame);

                Console.WriteLine("Arranging the user");
                lock (this._players)
                    foreach (Player p in this._players)
                        this.ArrangePlayersAfterRemoval(p);
                //this.ArrangePlayersAfterRemoval(this._user); // arrange the players
            } else
                if (this._TRACE) Console.WriteLine("no players left to remove");
        }

        /// <summary>
        /// Arranges a player around the table - called when removing a player
        /// </summary>
        /// <param name="player">The player we are arranging</param>
        private void ArrangePlayersAfterRemoval(Player player) {
            Console.WriteLine("*** CardGameScene::ArrangePlayersAfterRemoval(Player " + player.PlayerNumber + ") ***");
            // go through the players
            player.NetConnection.PlayerNumber = player.PlayerNumber; // set the connection's player number
            Console.WriteLine("---");
            Console.WriteLine("Arranging player " + player.PlayerNumber);
            Console.WriteLine("\tPosition before = " + player.Position);
            Console.WriteLine("\tRotation before = " + player.Rotation);
            player.Position = this._table.GetChairPosition(player.PlayerNumber); // get their new position
            player.Rotation = this._table.GetChairAngle(player.PlayerNumber); // get their new rotation
            Console.WriteLine("\tPosition after = " + player.Position);
            Console.WriteLine("\tRotation after = " + player.Rotation);
            Console.WriteLine("---");
            if (player.UserControlled) player.SetupCamera(); // set up the camera if necessary
            player.SetCameraPos(); // set the camera position
            player.ArrangeCards(); // arrange the players cards
            Console.WriteLine("+++ from ArrangePlayersAfterRemoval +++");
            Console.WriteLine("Current player's turn = " + this._currPlayer + ", this player number " + player.PlayerNumber);
            Console.WriteLine("Current player on his turn? " + player.IsMyTurn);
            if (this._currPlayer == player.PlayerNumber && !player.IsMyTurn)
                player.OnMyTurn();
            Console.WriteLine("+++");
        }

        /// <summary>
        /// Gets called when a message comes over the network saying that we need to arrange a player
        /// </summary>
        /// <param name="p">The player to arrange</param>
        /// <param name="npn">The player's new player number</param>
        public void FNArrangePlayer(int p, int npn) {
            Console.WriteLine("*** CardGameScene::FNArrangePlayer(int " + p + ", int " + npn + ") ***");
            lock (this._players) {
                Player pl = this.GetPlayer(p);
                if (pl != null) {
                    Console.WriteLine("FNArrangePlayer - arranging player number " + p + " (now " + npn + ")");
                    pl.PlayerNumber = npn;
                    pl.LogNumber = npn + 1;
                    this.ArrangePlayersAfterRemoval(pl);
                    Console.WriteLine("+++");
                    Console.WriteLine("Current player's turn = " + this._currPlayer + ", this player number " + pl.PlayerNumber);
                    Console.WriteLine("+++");
                } else
                    Console.WriteLine("Player " + p + " doesn't exist - when trying to arrange it in FNArrangePlayer");
            }
        }

        /// <summary>
        /// Gets called when a message comes over the network saying that we need to customise one of the players
        /// </summary>
        /// <param name="playerNum">The player to customise</param>
        /// <param name="hairType">the hair type of the player</param>
        /// <param name="hairColour">the hair colour of the player</param>
        /// <param name="skinColour">the skin colour of the player</param>
        /// <param name="name">the name of the player</param>
        public void FNCustomisePlayer(int playerNum, int hairType, int hairColour, int skinColour, string name) {
            lock (this._players) {
                Player p = this.GetPlayer(playerNum);
                if (p != null) {
                    p.HairType = (PlayerHairType)hairType;
                    p.HairColor = (PlayerColorChoice)hairColour;
                    p.SkinColor = (PlayerColorChoice)skinColour;
                    p.Name = name;
                }
            }
        }

        /// <summary>
        /// Place the cards that the player has selected into the pickup pile in the center of the table
        /// </summary>
        /// <param name="player">The player placing the cards</param>
        public void PlaceCardsInPickupPile(Player player) {
            if (player.IsMyTurn) {
                string cardsToSend = ""; // what card's to send across the network

                // log the placement
                if (player.CurrentlySelectedCards.Count > 1) {
                    this._hud.AddLogMessage(player.LogNumber, "played " + player.CurrentlySelectedCards.Count
                                            + " " + player.CurrentlySelectedCards[0].CardValue + "s",
                                            player.SkinColor);
                } else {
                    string desc = player.CurrentlySelectedCards[0].CardDescription.ToString();
                    int n = desc.IndexOf("Of");
                    string print = desc.Substring(0, n) + " of " + desc.Substring(n + 2);
                    this._hud.AddLogMessage(player.LogNumber, "played the " + print,
                                            player.SkinColor);
                }

                //do a quick check to see if it's a valid card
                if (!PlayHelper.CanPlaceCard(player, player.CurrentlySelectedCards[0], this._deck)) {
                    Console.WriteLine("When placing cards in pickup pile, the card was found to be invalid - Pick that shit up!");
                    player.JustPickedUp = true;
                }

                foreach (Card card in player.CurrentlySelectedCards) { // remove the cards from the player's hand

                    Console.WriteLine("\tPlayer " + player.PlayerNumber + " put the " + card.CardDescription + " on the pickup pile");
                    cardsToSend += card.OriginalCardNum + " "; // add the cards to the string to be sent

                    card.Selected = false;
                    card.CanShowValue = true;
                    if(player.UserControlled) card.WithUser = false; // card is no longer with the user
                    player.RemoveCardFromHand(card); // remove the card from the player's hand
                    if(this._TRACE) Console.WriteLine("Player " + player.PlayerNumber + " played " + card.CardDescription);
                }
                this._deck.AddToPickUpPile(player, player.CurrentlySelectedCards); // add the cards to the pick up pile

                player.ClearAllSelectedCards();

                // if the player is the user, inform the other players that he's put some cards in the pickup pile
                if (player == this._user)
                    this._netManager.SendPutCardsInPickupPile(cardsToSend);
            }
        }

        /// <summary>
        /// Gets called when a message comes over the network that a player has placed cards in the pickup pile
        /// </summary>
        /// <param name="pc">The cards that were placed</param>
        /// <param name="p">The player who placed them</param>
        public void FNPlaceCardsInPickupPile(string pc, int p) {
            Player pl = this.GetPlayer(p);
            string[] split = pc.Split(' '); // split the card string into an array
            for (int i = 0; i < split.Length; i++)
                pl.CurrentlySelectedCards.Add(pl.GetCardByOriginalNumber(int.Parse(split[i])));
            this.PlaceCardsInPickupPile(pl); // call the other place cards method
        }

        /// <summary>
        /// Gets called when a player loses his connection in the middle of a match - his cards get burned
        /// </summary>
        /// <param name="cards">The cards to burn</param>
        public void BurnPlayersCards(List<Card> cards) {
            Console.WriteLine("*** CardGameScene::BurnPlayersCards(List<Card> cards) ***");
            this._deck.BurnSpecificCards(cards);
        }

        /// <summary>
        /// Gets called when a message comes over the network telling us to burn a player's cards
        /// </summary>
        /// <param name="p">The player who's cards need to be burned</param>
        public void FNBurnPlayersCards(int p) {
            Console.WriteLine("*** CardGameScene::FNBurnPlayersCards(int " + p + ") ***");
            lock (this._players)
                this.BurnPlayersCards(this.GetPlayer(p).Cards); // burn the player's cards
        }

        /// <summary>
        /// The player has to pick up, so give him all the cards from the pickup pile
        /// </summary>
        /// <param name="player">The player to give the cards to</param>
        public void Pickup(Player player) {
            foreach (Card card in this._deck.PickupPile)
                card.CardType = CardType.InHandCard; // set the card type

            player.GiveCards(this._deck.PickupPile, false); // give the cards to the player
            this._deck.PickupPile.Clear(); // clear the pickup pile

            this._hud.AddLogMessage(player.LogNumber, SMOCGGame.Settings.LogMessages[(int)Log.Player_picked_up], player.SkinColor);

            if (player == this._user)
                this._netManager.SendPickup(); // tell the other players, that we've just picked up
        }

        /// <summary>
        /// Gets called when a message comes over the network that a player has just picked up
        /// </summary>
        /// <param name="p">The player who has just picked up</param>
        public void FNPickup(int p) {
            Player pl = this.GetPlayer(p);
            pl.JustPickedUp = true;
            this.Pickup(pl); // call the other pickup method
        }

        /// <summary>
        /// Called when the user clicks the pickup button
        /// </summary>
        public void Pickup() {
            this._hud.ButtonActivation(HUDButtons.Pickup, false);
            this._user.JustPickedUp = true;
            this.Pickup(this._user);
            this.EndTurn(this._user);
        }

        /// <summary>
        /// Called by the player when it's the end of his turn
        /// </summary>
        /// <param name="player">The player making the call</param>
        public void EndTurn(Player player) {
            Console.WriteLine("*** CardGameScene::EndTurn(Player " + player.PlayerNumber + ") ***");
            if(this._TRACE) Console.WriteLine("end turn called by player " + player.PlayerNumber);
            Console.WriteLine("______");
            Console.WriteLine("\tPlayer " + player.PlayerNumber + " just cancelled pile? " + player.JustCancelledPile);
            Console.WriteLine("\tPlayer " + player.PlayerNumber + "'s gamestate = " + player.GameState);
            Console.WriteLine("\tPlayer " + player.PlayerNumber + "'s turn? " + player.IsMyTurn);
            Console.WriteLine("______");
            // if the player has just cancelled the pile, then it's his turn again
            if (player.JustCancelledPile && player.GameState != PlayerInGameState.Out) {
                player.JustCancelledPile = false;
                player.OnMyTurn();
                // if it's the user, and he's ended his turn, inform the other players
                if (player == this._user) {
                    Console.WriteLine("The player is the user, and he's just cancelled the pile, so sending the end turn message");
                    this._netManager.SendEndTurn();
                }
                return;
            }

            Console.WriteLine("Player hasn't just cancelled the pile, so continuing");
            Console.WriteLine("*** Number of players left in the game = " + this.PlayersLeftInGame + " ***");
            if (this.PlayersLeftInGame > 1) {
                Console.WriteLine("There are more players left in the game");
                player.IsMyTurn = false;
                Console.WriteLine("Player " + player.PlayerNumber + " just picked up? " + player.JustPickedUp);
                Console.WriteLine("Player " + player.PlayerNumber + " forced picked up? " + player.ForcePickedUp);
                Console.WriteLine(this._currPlayer + " = this._current player before change");
                if (player.JustPickedUp) {
                    Console.WriteLine("going backwards with current player");
                    do{
                        --this._currPlayer;
                        if (this._currPlayer == -1) this._currPlayer = this._highestPlayerNumber;
                    } while (this.GetPlayer(this._currPlayer) == null);
                    Console.WriteLine(this._currPlayer + " = this._current player after going backwards");
                } else {
                    Console.WriteLine("going forwards with current player");
                    do{
                        Console.WriteLine("this._currentplayer before = " + this._currPlayer);
                        ++this._currPlayer;
                        Console.WriteLine("this._currentplayer after ++ = " + this._currPlayer);
                        this._currPlayer %= this._highestPlayerNumber + 1;
                        Console.WriteLine("this._currentplayer after % = " + this._currPlayer);
                    } while (this.GetPlayer(this._currPlayer) == null);
                    Console.WriteLine(this._currPlayer + " = this._current player after going forwards");
                }
                Console.WriteLine(this._currPlayer + " = this._current player final");

                if (this.GetPlayer(this._currPlayer).GameState != PlayerInGameState.Out) 
                {
                    if (player.JustPickedUp) player.JustPickedUp = false; // reset the picked up bool
                    if (player.ForcePickedUp) player.ForcePickedUp = false; // reset the forced pick up bool
                    Console.WriteLine("Calling player " + this.GetPlayer(this._currPlayer).PlayerNumber + " to take his turn");
                    // if it's the user, then activate the pickup button
                    if (this.GetPlayer(this._currPlayer) == this._user && this._deck.PickupPile.Count > 0)
                        this._hud.ButtonActivation(HUDButtons.Pickup, true);
                    else
                        this._hud.ButtonActivation(HUDButtons.Pickup, false);
                    this.GetPlayer(this._currPlayer).OnMyTurn(); // set the next player's turn
                } else {
                    Console.WriteLine("Recalling the function to find the next player");
                    EndTurn(player); // recall it to move to the next player
                }

            } else {
                Console.WriteLine("Ther is only one player left - he is the shithead");
                Player lastPlayerLeft = null;
                foreach (Player p in this._players) {
                    if (p.GameState != PlayerInGameState.Out) {
                        lastPlayerLeft = p;
                        break;
                    }
                }
                this._hud.AddLogMessage(lastPlayerLeft.LogNumber, SMOCGGame.Settings.LogMessages[(int)Log.Player_loser], lastPlayerLeft.SkinColor);
                this._hud.ButtonActivation(HUDButtons.Reset, true);
                this._hud.ButtonActivation(HUDButtons.Pickup, false);
                this._gameFinished = true; // the game has been finished
            }

            // if it's the user, and he's ended his turn, inform the other players
            if (player == this._user && !player.EndTurnSent) {
                player.EndTurnSent = true;
                this._netManager.SendEndTurn();
            }
        }

        /// <summary>
        /// Gets called when a message comes over the network that a player ended his turn
        /// </summary>
        /// <param name="p">The player ending his turn</param>
        public void FNEndTurn(int p) {
            Console.WriteLine("*** CardGameScene::FNEndTurn(int " + p + ") ***");
            Player pl = this.GetPlayer(p);
            this.EndTurn(pl); // end the players turn
        }

        /// <summary>
        /// Called when a player get's rid of all of his cards
        /// </summary>
        /// <param name="player">The player to retire</param>
        public void PlayerOut(Player player) {
            if(this._TRACE) Console.WriteLine("***** PLAYER " + player.PlayerNumber + " JUST RETIRED *****");
            this._hud.AddLogMessage(player.LogNumber, SMOCGGame.Settings.LogMessages[(int)Log.Player_out], player.SkinColor);
        }

        /// <summary>
        /// Deal the cards
        /// </summary>
        public void Deal() {
            this._gameDealt = true;

            this._hud.ButtonActivation(HUDButtons.Deal, false); // deactivate the deal button
            this._hud.ButtonActivation(HUDButtons.Ready, true); // activate the ready button

            // find the highest player number
            foreach (Player player in this._players) {
                if (player.PlayerNumber > this._highestPlayerNumber)
                    this._highestPlayerNumber = player.PlayerNumber;
                player.ReadyToBegin = false;
            }

            Console.WriteLine("Highest player number is " + this._highestPlayerNumber);

            this._deck.Deal(true); // deal the cards
            this._netManager.SendShufflePos(this._deck.ShufflePos); // send the shuffled pos over the network
        }

        /// <summary>
        /// Gets called when a message comes over the network with the shuffled cards position
        /// sort the position and deal the cards
        /// </summary>
        /// <param name="sp">The string containing the shuffled cards position</param>
        public void FNSetShuffledCardsAndDeal(string sp) {
            this._gameDealt = true;

            this._hud.ButtonActivation(HUDButtons.Ready, true); // activate the ready button

            // find the highest player number
            foreach (Player player in this._players)
                if (player.PlayerNumber > this._highestPlayerNumber)
                    this._highestPlayerNumber = player.PlayerNumber;

            Console.WriteLine("Highest player number is " + this._highestPlayerNumber);

            this._deck.FNArrangeShuffledCards(sp); // get the deck to arrange the shuffled cards
            this._deck.Deal(false);
        }

        /// <summary>
        /// Gets called when a message comes over the network with the two cards to be shuffled, 
        /// and the player who made the call
        /// </summary>
        /// <param name="sc">A string containing the two cards to shuffle</param>
        /// <param name="p">The player who made the request</param>
        public void FNSwapPlayersCards(string sc, int p) {
            if (this.GetPlayer(p) == null)
                Console.WriteLine("ERROR! Player number " + p + " doesn't exist");
            else {
                string[] split = sc.Split(' ');
                lock (this.GetPlayer(p)) {
                    // swap the two cards
                    this.GetPlayer(p).SwapCards(int.Parse(split[0]), int.Parse(split[1]));
                }
            }
        }

        /// <summary>
        /// Get the player to select the same cards
        /// </summary>
        public void SelectSameCards() {
            Console.WriteLine("selecting same cards");
            if (this._gameDealt && this._user != null)
                this._user.SelectSameCards();
            this._hud.ButtonActivation(HUDButtons.SelectSame, false);
        }

        /// <summary>
        /// The player is ready to begin the game
        /// </summary>
        public void PlayerIsReady() {
            if (this._user != null) {
                this._user.ReadyToBegin = true;
                //this._netManager.Current = "Player " + this._user.PlayerNumber + " is ready to begin";
                this._hud.AddLogMessage(this._user.LogNumber, SMOCGGame.Settings.LogMessages[(int)Log.Player_ready], this._user.SkinColor);
                this._hud.ButtonActivation(HUDButtons.Ready, false); // deactivate the button
                this._netManager.SendReadyToBegin(); // tell the other players that you're ready to begin
                this.CheckIfShouldBeginPlay();
            }
        }

        /// <summary>
        /// Gets called when a message comes over the network saying that a player is ready to begin
        /// </summary>
        /// <param name="p">The player who is ready to begin</param>
        public void FNPlayerReadyToBegin(int p) {
            lock (this._players) {
                Player pl = this.GetPlayer(p); // get the player
                pl.ReadyToBegin = true;
                // log the message
                this._hud.AddLogMessage(pl.LogNumber, SMOCGGame.Settings.LogMessages[(int)Log.Player_ready], pl.SkinColor);
                CheckIfShouldBeginPlay(); // check to see should we begin playing
            }
        }

        /// <summary>
        /// Check to see if every player has signalled that their ready, if they are, then begin the game
        /// </summary>
        private void CheckIfShouldBeginPlay() {
            bool start = true;
            this._numPlayersLeftToGetReady = 0;
            foreach (Player p in this._players) {
                Console.WriteLine("Player " + p.PlayerNumber + " is ready to begin? " + p.ReadyToBegin);
                if (!p.ReadyToBegin) {
                    start = false;
                    this._numPlayersLeftToGetReady++;
                }
            }
            Console.WriteLine("Can we start playing? " + start);
            if (start) {
                foreach (Player player in this._players)
                    player.GameState = PlayerInGameState.HandCards; // start the game
                this._gameStarted = true;
                this.GetPlayer(this._currPlayer).OnMyTurn(); // set who's to start
                this._hud.AddLogMessage("Game underway", PlayerColorChoice.White);
            }
        }

        /// <summary>
        /// Reset the game
        /// </summary>
        public void Reset(bool sendToAll) {
            this._gameDealt = false;
            this._gameStarted = false;
            this._gameFinished = false;
            this._highestPlayerNumber = 0;
            //this._lastAction = "";
            //this._loser = "";
            //this._pickup = "";
            this._numStartPlayers = 0;
            this._currPlayer = 0;

            this._deck.Reset(); // reset the deck
            lock (this._players)
                foreach (Player player in this._players)
                    player.Reset(); //reset all of the player

            if (this._players.Count > 1 && this._netManager.GameStarter)
                this._hud.ButtonActivation(HUDButtons.Deal, true); // activate the deal button
            this._hud.ButtonActivation(HUDButtons.Ready, false); // deactivate the ready button
            this._hud.ButtonActivation(HUDButtons.Pickup, false); // deactivate the pickup button
            this._hud.ButtonActivation(HUDButtons.Reset, false);// deactivate the reset button
            this._hud.ButtonActivation(HUDButtons.SelectSame, false); // deactivate the select same button

            if(sendToAll) this._netManager.SendReset(); // tell the rest of the players to reset
        }

        /// <summary>
        /// Update all the objects
        /// </summary>
        /// <param name="totalTime">The total time since the program started</param>
        /// <param name="deltaTime">The time since the last call to update</param>
        /// <returns>The next GameState, or GameState.None is it's to stay with this one</returns>
        public override GameState Update(TimeSpan totalTime, TimeSpan deltaTime) {
            this._deck.Update(deltaTime); // update the deck
            this._tableFocus.Update(deltaTime); // update the table focus object

            Player currPlayer = this.GetPlayer(this._currPlayer);
            if (currPlayer != null && this._gameStarted) {
                this._turnArrow.Update(deltaTime); // update the turn arrow
                this._turnArrow.Position = new Vector3((float)Math.Sin(currPlayer.Rotation.Y) * 25.0f, 0.3f, (float)Math.Cos(currPlayer.Rotation.Y) * 25.0f);
                this._turnArrow.Rotation = new Vector3(MathHelper.PiOver2, currPlayer.Rotation.Y, 0.0f);
            }

            // only do keyboard commands if we're not in a text input
            if (!this.Game.InTextInput) {
                if (this._input.DealCardsPressed && this._players.Count > 1 && this._netManager.GameStarter && !this._gameStarted) {
                    this.Deal();
                } else if (this._input.SelectSameCardsPressed) {
                    SelectSameCards();
                } else if (this._input.PickUpPressed) {
                    /*
                     * pick the cards up
                     */
                    if (this._TRACE) Console.WriteLine("pickup cards button pressed");
                    if (this._gameDealt && this._user != null && this._user.IsMyTurn)
                        this._user.ForcePickup(); // the player wants to pick up even if he doesn't have to
                } else if (this._input.ArrangeKeysPressed) {
                    /*
                     * arrange cards
                     */
                    if (this._user != null) this._user.ArrangeCards();
                } else if (this._input.ResetGamePressed) {
                    /*
                     * reset the game
                     */
                    if (this._gameFinished)
                        this.Reset(true);
                }
                else if (this._players.Count > 1 && this._gameDealt && this._input.ReadyToBeginPressed)
                {
                    PlayerIsReady();
                } else if (this._input.RightPressed) {
                    /*
                     * write out the current connections
                     */
                    if (!this._gameDealt)
                        this._netManager.Write();
                }
            }

            this._netManager.Update(); // call the update on the netManager

            // update the hud
            if (this._user != null) {
                // set the currently focused card for the hud
                if (this._user.CurrentlyFocusedCard != null && this._user.CurrentlyFocusedCard.CanShowValue)
                    this._hud.FocusedCard = this._user.CurrentlyFocusedCard;
                else
                    this._hud.FocusedCard = null;

                // set the selected cards
                this._hud.SetSelectedCards(this._user.CurrentlySelectedCards);
            }

            // if, as a result of connecting to a game, we need to add players, then do so
            if (this._mustAddPlayers) {
                Console.WriteLine("\t must add players in CardGameScene.update()");
                Console.WriteLine("\t number of players to add = " + this._numPlayersToAdd);
                Console.WriteLine("\t player controlled is player number = " + this._playerControlled);
                for (int i = 0; i < this._numPlayersToAdd; i++) {
                    if (i == this._playerControlled) {
                        this.AddPlayer(true);
                        this._netManager.AddBlankConnection(); // add a blank connection for this player
                    } else
                        this.AddPlayer(false);
                    if (i == 0) {
                        Player p = this.GetPlayer(0);
                        if (p != null) {
                            lock (p) { // customise the player
                                p.HairType = (PlayerHairType)this._player0HairType;
                                p.HairColor = (PlayerColorChoice)this._player0HairColour;
                                p.SkinColor = (PlayerColorChoice)this._player0SkinColour;
                                p.Name = this._player0Name;
                            }
                        }
                    }
                }
                //send a message back saying we're listening
                this._netManager.RegisterWithPlayer(this._netManager.Connections[this._returnNCCall]); // register the connection with the player
                this._netManager.NumConnectionToRegister = this._numPlayersToAdd;
                this._netManager.Connections[this._returnNCCall].SendPortOpenCall();
                this._mustAddPlayers = false;
            }

            this.DecidePlayerMessages();

            this._hud.Update(totalTime, deltaTime); // update the hud

            return base.Update(totalTime, deltaTime); // update all the objects
        }

        /// <summary>
        /// Decide which messages to show up on the bottom hud
        /// </summary>
        private void DecidePlayerMessages() {
            // first set the first message to who you are
            if (this._user != null)
                this._hud.BottomMessage = SMOCGGame.Settings.HUDMessages[this._user.PlayerNumber];
            if (!this._gameDealt) {
                // if there's more players, then show up the "press deal" message
                if (this._players.Count > 1 && this._netManager.GameStarter)
                    this._hud.BottomMessage2 = SMOCGGame.Settings.HUDMessages[(int)HUDMessages.Press_deal_cards];
                else
                    this._hud.BottomMessage2 = "";
            } else { // game has been dealt
                if (!this._gameStarted) { // if the game hasn't started yet
                    if (!this._user.ReadyToBegin) {// if the user isn't ready to begin
                        this._hud.BottomMessage = SMOCGGame.Settings.HUDMessages[(int)HUDMessages.Press_ready_to_begin];

                        // if the user hasn't selected any cards - tell him that he can swap the two cards
                        if (this._user.CurrentlySelectedCards.Count == 0)
                            this._hud.BottomMessage2 = SMOCGGame.Settings.HUDMessages[(int)HUDMessages.Can_swap_faceup_hand_cards];
                        else // otherwise tell him how to swap the cards
                            this._hud.BottomMessage2 = SMOCGGame.Settings.HUDMessages[(int)HUDMessages.Select_cards_to_switch_position];
                    } else {// say how many he's waiting on
                        this._hud.BottomMessage = SMOCGGame.Settings.HUDMessages[22 + this._numPlayersLeftToGetReady];

                        // twll the player that he can swap two cards
                        if (this._user.CurrentlySelectedCards.Count == 0)
                            this._hud.BottomMessage2 = SMOCGGame.Settings.HUDMessages[(int)HUDMessages.Select_cards_to_switch_position];
                        else // tell the user that pressing the select same button will select similar cards
                            this._hud.BottomMessage2 = SMOCGGame.Settings.HUDMessages[(int)HUDMessages.Press_select_same_cards];
                    }
                } else { // the game has started
                    if (this._gameFinished) {
                        this._hud.BottomMessage2 = SMOCGGame.Settings.HUDMessages[(int)HUDMessages.Press_reset_game]; // reset the game
                    } else {
                        if (this._user.IsMyTurn) {// tell the user that it's his turn
                            this._hud.BottomMessage = SMOCGGame.Settings.HUDMessages[(int)HUDMessages.Your_go];
                            if (this._deck.PickupPile.Count == 0 && this._user.CurrentlySelectedCards.Count == 0) {// if there's no cards in the pickup pile
                                if (this._user.GameState == PlayerInGameState.HandCards) // play a hand card
                                    this._hud.BottomMessage2 = SMOCGGame.Settings.HUDMessages[(int)HUDMessages.Select_hand_card];
                                else if (this._user.GameState == PlayerInGameState.FaceUpCards) // play a faceup card
                                    this._hud.BottomMessage2 = SMOCGGame.Settings.HUDMessages[(int)HUDMessages.Select_faceup_card];
                                else if (this._user.GameState == PlayerInGameState.FaceDownCards) // play a facedown card
                                    this._hud.BottomMessage2 = SMOCGGame.Settings.HUDMessages[(int)HUDMessages.Select_facedown_card];
                            } else if (this._deck.PickupPile.Count != 0 && this._user.CurrentlySelectedCards.Count == 0)
                                this._hud.BottomMessage2 = SMOCGGame.Settings.HUDMessages[(int)HUDMessages.Can_pickup_anyway]; // can pick it up
                            else
                                this._hud.BottomMessage2 = SMOCGGame.Settings.HUDMessages[(int)HUDMessages.Click_pickup_pile_to_play]; // click pile to play
                        } else {// tell the player who's turn it is
                            if(this.GetPlayer(this._currPlayer) != null)
                                this._hud.BottomMessage = SMOCGGame.Settings.HUDMessages[9 + this.GetPlayer(this._currPlayer).LogNumber];
                            if (this._user.GameState == PlayerInGameState.Out)
                                this._hud.BottomMessage2 = "";
                            else
                                this._hud.BottomMessage2 = SMOCGGame.Settings.HUDMessages[(int)HUDMessages.Select_multiple_cards]; // can select multiple cards
                        }
                    }
                }
            }
        }

        /// <summary>
        /// Render all the objects, including any focused/selected cards, and font's detailing what's happening
        /// </summary>
        public override void Render() {

            base.Render(); // render all the objects
            this._deck.Render(); // render the deck

            if (this._gameStarted)
                this._turnArrow.Render();

            if(this._tableFocus.Focused && this._gameStarted)
                this._tableFocus.Render(); // render the table focus

            // write out the computer's ip
            if (this._gameip != "") {
                Font.Begin();
                int width = Font.GetWidth(FontStyle.Small, this._gameip);
                Font.Draw(FontStyle.Small, SMOCGGame.Graphics.GraphicsDevice.Viewport.Width - width - 120, 10, this._gameip, Color.White);
                Font.End();
            }

            if (_overlay != null)
                _overlay.Render(); //render the hud
        }
    }
}
