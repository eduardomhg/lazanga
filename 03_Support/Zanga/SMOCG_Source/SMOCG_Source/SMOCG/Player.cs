//#define SHOW_DEBUG_LINES

#region Dependancies
using System;
using System.Timers;
using System.Collections.Generic;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using SMOCG.GUI;
using SMOCG.Cameras;
using System.IO;
using System.Xml.Serialization;
#endregion

namespace SMOCG {
    /// <summary>
    /// A Player holds all the information necessary to create, and show a player, represented by a PlayerShape
    /// </summary>
    public class Player : GameObject {
        private bool _TRACE = false;

        private SMOCGGame _smocgGame;
        private CardGameScene _game; // a reference to the card game scene object
        private Table _table; // a reference to the table object
        private GameObject _tableFocus; // a reference to the table focus object
        private bool _overTableFocus = false; // is the player over the table focus

        private NetConnection _netConn = null; // a reference to the net connection object for this player

        private static int _currentNumPlayers = 0; // the current amount of players
        private static int _maxSelectedCards = 4; // the maximum amount of selected cards allowed

        private PlayerShape _shape; // the player's model
        private string _name; // the player's name
        private FreeCamera _freeCamera; // the player's camera

        private MouseState _prevMouseState; // a hold on the previous mouse state

        private int _playerNum; // the number of the player
        private int _logNum; // the number to use when writing to the log
        private bool _userControlled = false; // is this player user controlled? (as opposed to controlled by someone over the net)
        private bool _isMyTurn = false; // is it the player's turn?
        private bool _justPickedUp = false; // has the player just picked up?
        private bool _forcedPickup = false; // did the player force pickup?
        private bool _justCancelledPile = false; // has the player just cancelled the pickup pile?
        private bool _endTurnSent = false; // has the end turn message been sent?
        private int _canPlayCardNumber; // the number of the first card the player can play legally

        private bool _readyToBegin = false; // is the player ready to begin playing?

        private List<Card> _hand = new List<Card>(52); // a list that will hold the cards that the player will play with
        private List<Card> _currentlySelectedCards = new List<Card>(_maxSelectedCards); // an array of currently selected cards - the player is only allowed to select a maximum of 4
        private Card _currentlyFocusedCard = null; // the currently focused card
        private int _numCardsInHand = 0; // how many cards is the player currently holding in his hand
        private int _numFaceupCards = 0; // how many cards the player has face up
        private int _numFaceDownCards = 0; // how many cards the player has face down

        private PlayerInGameState _currState = PlayerInGameState.None; // the players game state

        /*-------------------------------------------------------------------------------*/
#if SHOW_DEBUG_LINES
        // Vertex array that stores exactly which triangle was picked.
        VertexPositionColor[] pickedTriangle =
        {
            new VertexPositionColor(Vector3.Zero, Color.Magenta),
            new VertexPositionColor(Vector3.Zero, Color.Magenta),
            new VertexPositionColor(Vector3.Zero, Color.Magenta),
        };

        // Effect and vertex declaration for drawing the picked triangle.
        BasicEffect lineEffect;
        VertexDeclaration lineVertexDeclaration;

        DebugLine _debugLine;
#endif
        /*-------------------------------------------------------------------------------*/

        #region Get and set Customisables

        /// <summary>
        /// Get and set the table reference for the player
        /// </summary>
        public Table Table {
            get { return _table; }
            set { _table = value; }
        }

        /// <summary>
        /// Set the table focus - the model to be used to determine when the player has focused on the table
        /// </summary>
        public GameObject TableFocus {
            set { _tableFocus = value; }
        }

        /// <summary>
        /// Get and set the name of the player
        /// </summary>
        public string Name {
            get { return _name; }
            set { _name = value; }
        }

        /// <summary>
        /// Get the player's camera - note, this is returning a BasicCamera, not a FreeCamera
        /// </summary>
        public override BasicCamera Camera
        {
            get { return (BasicCamera)_freeCamera; }
            //get { return (BasicCamera)SMOCGGame.Camera; }
        }

        public FreeCamera FreeCamera
        {
            get { return _freeCamera; }
            //get { return (BasicCamera)SMOCGGame.Camera; }
        }

        /// <summary>
        /// Get and set the hair model used by the player. use the PlayerHairType enum for ease of use
        /// </summary>
        public PlayerHairType HairType {
            get { return (PlayerHairType)_shape.HairType; }
            set { _shape.HairType = (int)value; }
        }

        /// <summary>
        /// Get and set the hair color used by the player. use the PlayerColorChoice enum for ease of use
        /// </summary>
        public PlayerColorChoice HairColor {
            get { return (PlayerColorChoice)_shape.HairColor; }
            set { _shape.HairColor = (int)value; }
        }

        /// <summary>
        /// Get and set the face texture used by the player. use the PlayerFaceTextures enum for ease of use
        /// </summary>
        public PlayerFaceTextures FaceTexture {
            get { return (PlayerFaceTextures)_shape.FaceTexture; }
            set { _shape.FaceTexture = (int)value; }
        }

        /// <summary>
        /// Get and set the skin color used by the player. use the PlayerColorChoice enum for ease of use
        /// </summary>
        public PlayerColorChoice SkinColor {
            get { return (PlayerColorChoice)_shape.SkinColor; }
            set { _shape.SkinColor = (int)value; }
        }

        /// <summary>
        /// Get the player's number
        /// </summary>
        public int PlayerNumber {
            get { return _playerNum; }
            set { 
                _playerNum = value;
                this._logNum = value + 1;
            }
        }

        /// <summary>
        /// Get and set the player's log number - the number used when writing his actions to the log
        /// </summary>
        public int LogNumber {
            get { return this._logNum; }
            set { this._logNum = value; }
        }

        /// <summary>
        /// Get and set the player static number
        /// </summary>
        public static int StatPlayerNumber {
            get { return _currentNumPlayers; }
            set { _currentNumPlayers = value; }
        }

        /// <summary>
        /// Get and set whether the player is user controlled as opposed to being controlled by someone over the net. The default is false
        /// </summary>
        public bool UserControlled {
            get { return _userControlled; }
            set { _userControlled = value; }
        }

        /// <summary>
        /// Get and set whether it's the player's turn not not
        /// </summary>
        public bool IsMyTurn {
            get { return _isMyTurn; }
            set { _isMyTurn = value; }
        }

        /// <summary>
        /// Get and set whether the player has just picked up
        /// </summary>
        public bool JustPickedUp {
            get { return this._justPickedUp; }
            set { this._justPickedUp = value; }
        }

        /// <summary>
        /// Get and set whether the player forced picked up
        /// </summary>
        public bool ForcePickedUp {
            get { return this._forcedPickup; }
            set { this._forcedPickup = value; }
        }

        /// <summary>
        /// Get and set whether the player has just cancelled the pickup pile
        /// </summary>
        public bool JustCancelledPile {
            get { return this._justCancelledPile; }
            set { this._justCancelledPile = value; }
        }

        /// <summary>
        /// Get and set whether the player has sent his end turn message
        /// </summary>
        public bool EndTurnSent {
            get { return this._endTurnSent; }
            set { this._endTurnSent = value; }
        }

        /// <summary>
        /// Get and set the player's position
        /// </summary>
        public override Vector3 Position {
            get { return this._shape.Position; }
            set { this._shape.Position = value; }
        }

        /// <summary>
        /// Get and set the player's rotation
        /// </summary>
        public override Vector3 Rotation {
            get { return this._shape.Rotation; }
            set { this._shape.Rotation = value; }
        }

        /// <summary>
        /// Get and set the player's scale
        /// </summary>
        public override Vector3 Scale {
            get { return this._shape.Scale; }
            set { this._shape.Scale = value; }
        }

        /// <summary>
        /// Get and set the player's in game state - this determines which cards he's allowed to play
        /// </summary>
        public PlayerInGameState GameState {
            get { return this._currState; }
            set { 
                this._currState = value;

                if (this._currState == PlayerInGameState.HandCards) // if we're playing from our hand 
                    foreach (Card card in this._hand) // go through each card, and if it's a faceup card then set that it can't move
                        if (card.CardType == CardType.FaceUpCard) card.CanMove = false;
            }
        }

        /// <summary>
        /// Get the player's cards
        /// </summary>
        public List<Card> Cards {
            get { return this._hand; }
        }

        /// <summary>
        /// Get the currently focused card
        /// </summary>
        public Card CurrentlyFocusedCard {
            get { return this._currentlyFocusedCard; }
        }

        /// <summary>
        /// Get the currently selected cards
        /// </summary>
        public List<Card> CurrentlySelectedCards {
            get { return this._currentlySelectedCards; }
        }

        /// <summary>
        /// Get the number of hand cards in the player's hand
        /// </summary>
        public int NumberOfCardsInHand {
            get {
                int i = 0;
                foreach (Card card in this._hand)
                    if (card.CardType == CardType.InHandCard)
                        i++;
                return i;
            }
        }

        /// <summary>
        /// Get and set if the player is ready to begin playing the game
        /// </summary>
        public bool ReadyToBegin {
            get { return this._readyToBegin; }
            set { 
                this._readyToBegin = value;
                if (this._readyToBegin)
                    this._currState = PlayerInGameState.HandCards;
            }
        }

        /// <summary>
        /// Get the player's netConnection object
        /// </summary>
        public NetConnection NetConnection {
            get { return this._netConn; }
        }

        #endregion

        /// <summary>
        /// constructor. creates a new player at position pos with default settings
        /// </summary>
        /// <param name="game">A reference to the main game object</param>
        /// <param name="cardGame">A reference to the CardGameScene object</param>
        public Player(SMOCGGame game, CardGameScene cardGame) : base(game) {
            this._smocgGame = game;
            this._game = cardGame; // hold the game reference
            this._name = "no_name"; // set a default name
            this._playerNum = _currentNumPlayers++; // give the player a number, and incretement the other players
            this._logNum = this._playerNum + 1;

            InitCamera(); // initiate the player camera

            _shape = new PlayerShape(game,                  // pass the reference to the main game object
                                    this,                   // a reference to this
                                    this.Camera,           // camera to view the shape with
                                    Vector3.Zero,           // position of the PlayerShape
                                    Vector3.Zero,           // the rotation of the PlayerShape
                                    Vector3.One,            // the scale of the player shape
                                    0,                      // the hair model to use
                                    0,                      // the hair color to use
                                    0,                      // the face texture to use
                                    0);                     // the skin color to use

            /*---------------------------------------------------------------------------------*/
#if SHOW_DEBUG_LINES
            //create the effect and vertex declaration for drawing the
            //picked triangle.
            lineEffect = new BasicEffect(SMOCGGame.Graphics.GraphicsDevice, null);
            lineEffect.VertexColorEnabled = true;

            lineVertexDeclaration = new VertexDeclaration(SMOCGGame.Graphics.GraphicsDevice,
                                                VertexPositionColor.VertexElements);

            _debugLine = new DebugLine(SMOCGGame.Graphics.GraphicsDevice);
#endif
            /*---------------------------------------------------------------------------------*/
        }

        /// <summary>
        /// Create a player with a specific position, hair model, hair color, face texture, and skin color
        /// </summary>
        /// <param name="game">A reference to the main game object</param>
        /// <param name="cardGame">A reference to the card game scene object</param>
        /// <param name="pos">The position of the player</param>
        /// <param name="rot">The rotation of the player</param>
        /// <param name="scale">The scale of the player</param>
        /// <param name="name">The name of the player</param>
        /// <param name="hairModel">What hair model to use</param>
        /// <param name="hairColor">What hair color to use</param>
        /// <param name="faceTexture">What face texture to use</param>
        /// <param name="skinColor">What skin color to use</param>
        public Player(SMOCGGame game, CardGameScene cardGame, Vector3 pos, Vector3 rot, Vector3 scale, string name, int hairModel, int hairColor, int faceTexture, int skinColor) : base(game) {
            this._smocgGame = game;
            this._game = cardGame;
            this._name = name;
            this._playerNum = _currentNumPlayers++; // give the player a number, and incretement the other players
            this._logNum = this._playerNum + 1;

            InitCamera(); //initiate the player camera

            _shape = new PlayerShape(game,                  // pass the reference to the main game object
                                    this,                   // a reference to this
                                    this.Camera,            // camera to view the shape with
                                    pos,                    // position of the PlayerShape
                                    rot,                    // the rotation of the playerShape
                                    scale,                  // the scale of the player shape
                                    hairModel,              // the hair model to use
                                    hairColor,              // the hair color to use
                                    faceTexture,            // the face texture to use
                                    skinColor);             // the skin color to use
        }

        /// <summary>
        /// initiate the player camera
        /// </summary>
        private void InitCamera() {
            this._freeCamera = new FreeCamera(Vector3.Zero,
                                        Vector3.Forward,
                                        MathHelper.ToRadians(80.0f),
                                        4.0f / 3.0f,
                                        1.0f,//0.001f,  // don't set this too close as the ray picking won't work properly
                                        300.0f); // create the camera for the player

            this._prevMouseState = Mouse.GetState(); // get the current mouse
        }

        /// <summary>
        /// Set up the player's camera so it's in the right place and looking in the right direction
        /// </summary>
        public void SetupCamera() {
            if (this._userControlled) { // if the user is controlling this player
                SetCameraPos(); // set the camera position
                this._freeCamera.Target = new Vector3(0.0f, this.Position.Y, 0.0f); // set the target
            } else
                this._shape.Camera = this.Game.ControllingCamera; // get the controlling camera
        }

        /// <summary>
        /// Set the player camera position
        /// </summary>
        public void SetCameraPos() {
            if (this._userControlled) {
                this._freeCamera.CameraPosition = this._shape.GetEyePos(); // move the camera into position
                this._freeCamera.HorizontalRotation = -this.Rotation.Y - MathHelper.PiOver2; // set the horizontal rotation value so its in the right direction
            } else
                this._shape.Camera = this.Game.ControllingCamera;
        }

        /// <summary>
        /// Called when it's the player's turn
        /// </summary>
        public void OnMyTurn() {
            this._isMyTurn = true;
            this._endTurnSent = false;

            Console.WriteLine("It's my turn - Player " + this.PlayerNumber);

            if (this.UserControlled) {
                if (this._currState == PlayerInGameState.HandCards || this._currState == PlayerInGameState.FaceUpCards) {

                    CardType type = CardType.InDeckCard;
                    if (this._currState == PlayerInGameState.HandCards)
                        type = CardType.InHandCard;
                    else
                        type = CardType.FaceUpCard;

                    if (this._TRACE) Console.WriteLine("--------------------------------------------------------------------");
                    if (this._TRACE) Console.WriteLine("Player " + this._playerNum + "'s current state = " + this._currState);
                    this._canPlayCardNumber = PlayHelper.AnyValidCards(this, this.GetCardsOfType(type), this._game.Deck);

                    if (this._canPlayCardNumber == -1) {
                        if (this._TRACE) Console.WriteLine("***** NO VALID CARDS *****");
                        this._justPickedUp = true;

                        // if the player is playing from his face up cards, then let him pick some up
                        if (this._currState == PlayerInGameState.FaceUpCards) {
                            List<Card> faceup = this.GetCardsOfType(CardType.FaceUpCard); // get the faceup cards
                            if (faceup.Count > 0) {
                                Card smallest = this.GetSmallestCard(faceup); // get the smallest cad
                                this._currentlySelectedCards.Add(smallest); // add it to the selected list

                                foreach (Card c in faceup)
                                    if (c.CardDescription != smallest.CardDescription && c.CardValue == smallest.CardValue)
                                        this._currentlySelectedCards.Add(c); // add any cards that are the same value

                                this._game.PlaceCardsInPickupPile(this); // place the card in the pickup pile
                            } else
                                if (this._TRACE) Console.WriteLine("no cards in faceup pile to pickup");
                        }

                        this._game.Pickup(this); // pick up
                        if (this._TRACE) Console.WriteLine("***** PLAYER " + this._playerNum + " JUST PICKED UP *****");
                        if (this._TRACE) Console.WriteLine("Player " + this._playerNum + " has " + this._numCardsInHand + " in his hand, " +
                              this._numFaceupCards + " faceup cards, " + this._numFaceDownCards + " face down cards");
                        this._game.EndTurn(this); // end the player's turn
                    } else
                        if (this._TRACE) Console.WriteLine("can play card number " + this._canPlayCardNumber);
                }
            }

        }

        /// <summary>
        /// Keep a reference to the NetConnection object for this player
        /// </summary>
        /// <param name="conn">The NetConnection object</param>
        public void FNRegisterNetConnection(NetConnection conn){
            Console.WriteLine("=============");
            Console.WriteLine("Player " + this._playerNum + " has registered connection " + conn.ConnectionNumber);
            this._netConn = conn;
            if (this._netConn == null)
                Console.WriteLine("NetConnection was null");
            else
                Console.WriteLine("Netconnection wasn't null");
            Console.WriteLine("=============");
        }

        /// <summary>
        /// Get a card in the player's hand by the original number
        /// </summary>
        /// <param name="n">The original number of the card to find</param>
        /// <returns>The card whose original number matches that passed in</returns>
        public Card GetCardByOriginalNumber(int n) {
            Card toReturn = null;
            foreach (Card card in this._hand)
                if (card.OriginalCardNum == n) {
                    toReturn = card;
                    break;
                }
            return toReturn;
        }

        /// <summary>
        /// Get the cards of a particular type that the player has
        /// </summary>
        /// <returns>An list holding all the cards that the player has of a particular type</returns>
        public List<Card> GetCardsOfType(CardType type) {
            List<Card> cards = new List<Card>();
            foreach (Card card in this._hand)
                if (card.CardType == type)
                    cards.Add(card);
            return cards;
        }

        /// <summary>
        /// Returns the smallest card in a particular list
        /// </summary>
        /// <param name="cards">The list to check against</param>
        /// <returns>The smallest card in the list</returns>
        public Card GetSmallestCard(List<Card> cards) {
            Card smallest = cards[0];
            foreach (Card c in cards)
                if (c.CardValue < smallest.CardValue)
                    smallest = c;
            return smallest;
        }

        /// <summary>
        /// Returns a bool on whether the player has the card in his hand (including faceup / facedown cards) or not
        /// </summary>
        /// <param name="card">The card to check</param>
        /// <returns>Whether the player has the card in his hand</returns>
        public bool HasCard(Card card) {
            return this._hand.Contains(card);
        }

        /// <summary>
        /// Clear any cards that the player has
        /// </summary>
        public void ClearAllCards() {
            this._hand.Clear();
            this._numCardsInHand = 0;
        }

        /// <summary>
        /// Clear a particular card from the selected list
        /// </summary>
        /// <param name="c">the card to be cleared</param>
        public void ClearSelectedCard(Card c) {
            if (this._currentlySelectedCards.Contains(c)) { // if it's on the selected card list
                this._currentlySelectedCards.Remove(c); // remove it from the selected list
                c.Selected = false;
            }

            if (this._currentlySelectedCards.Count == 0)
                this._game.HUD.ButtonActivation(HUDButtons.SelectSame, false);
        }

        /// <summary>
        /// This function clears all the currently selected cards
        /// </summary>
        public void ClearAllSelectedCards() {
            Console.WriteLine("Clearing all selected cards");
            this._currentlySelectedCards.Clear(); // clear the selected card list

            foreach (Card card in this._hand)
                card.Selected = false;

            this._game.HUD.ButtonActivation(HUDButtons.SelectSame, false);
        }

        /// <summary>
        /// Remove a particular card from a player's hand (including his faceup/facedown cards)
        /// </summary>
        /// <param name="card">The card to remove</param>
        public void RemoveCardFromHand(Card card) {
            this._hand.Remove(card);
            //manage the number of card types
            if (card.CardType == CardType.InHandCard)
                this._numCardsInHand--;
            else if (card.CardType == CardType.FaceUpCard)
                this._numFaceupCards--;
            else if (card.CardType == CardType.FaceDownCard)
                this._numFaceDownCards--;

            if(this._TRACE) Console.WriteLine("checking do i need to change state from " + this._currState + ", has he just picked up - " + this._justPickedUp);

            //set the player's state based on what he's playing from
            if (this._numCardsInHand == 0 && this._numFaceupCards > 0 && !this._justPickedUp)
                this._currState = PlayerInGameState.FaceUpCards;
            else if (this._numCardsInHand == 0 && this._numFaceupCards == 0 && this._numFaceDownCards > 0 && !this._justPickedUp)
                this._currState = PlayerInGameState.FaceDownCards;
            else if (this._numCardsInHand == 0 && this._numFaceupCards == 0 && this._numFaceDownCards == 0 && !this._justPickedUp) {
                this._currState = PlayerInGameState.Out;
                this._game.PlayerOut(this); // remove the player from the game
            } 
            
            if (this._currState == PlayerInGameState.FaceUpCards) { // if we're playing from our faceup cards
                foreach (Card c in this._hand)
                    if (c.CardType == CardType.FaceUpCard) c.CanMove = true;
            }

            if(this._numCardsInHand > 0) this.ArrangeCardsInHand(); // arrange the cards remaining
        }

        /// <summary>
        /// Give the player some cards
        /// </summary>
        /// <param name="cards">The cards you wish the player to have</param>
        /// <param name="dealCards">Are the cards from the deal, or as a result of picking up (signify's pre game status)</param>
        public void GiveCards(Card[] cards, bool dealCards) {
            List<Card> cardList = new List<Card>(cards);
            GiveCards(cardList, dealCards); // call the other function
        }

        /// <summary>
        /// Give the player some cards
        /// </summary>
        /// <param name="cards">The card you wish the player to have</param>
        /// <param name="dealCards">Are the cards from the deal, or as a result of picking up</param>
        public void GiveCards(List<Card> cards, bool dealCards) {
            if (dealCards) this._currState = PlayerInGameState.PreGame; // set the pre game state
            else this._currState = PlayerInGameState.HandCards; // playing from cards in his hand

            this._shape.RaiseLeftHand(); // raise the player's left hand

            Console.WriteLine("+++++");
            Console.WriteLine("Player " + this._playerNum + " received the following cards: ");

            foreach (Card card in cards) { // go through the array
                this._hand.Add(card); // add it to the players hand
                if (this._userControlled) card.WithUser = true; // set that the card is with the user if the player is user controlled
                if (card.CardType == CardType.InHandCard) { // if the player is to hold these cards, then incret _numCardsInHand
                    this._numCardsInHand++;
                    card.CanMove = true;
                    card.CanShowValue = true;
                }
                Console.WriteLine("\t" + card.CardDescription + " = " + card.CardType);
            }

            Console.WriteLine("+++++");

            ArrangeCards(); // arrange all the cards
        }

        /// <summary>
        /// This function arranges all the player's cards
        /// </summary>
        public void ArrangeCards() {
            this._hand.Sort(); // sort the hand

            float rad = MathHelper.ToRadians(5.0f); // slight angle difference so the faceup/facedown cards sit beside each other
            float facedown = rad, faceup = rad;

            this._numFaceDownCards = this._numFaceupCards = 0;

            foreach (Card card in this._hand) { // go through the players cards
                float dist = 85.0f; // distance from the center of the table to the faceup/facedown cards
                float addAngle = MathHelper.ToRadians(12.0f); // additional angle to push the cards to the right a bit

                if (card.CardType == CardType.FaceDownCard) // face down cards to be placed on the table in front of the player
                {
                    float angle = (this.Rotation.Y - facedown) + addAngle;
                    card.Position = card.StartingPosition = new Vector3((float)Math.Sin(angle) * dist + this._table.Position.X,
                                                            this._table.Position.Y + 2.0f,
                                                            (float)Math.Cos(angle) * dist + this._table.Position.Z);
                    card.QRotation = Quaternion.CreateFromYawPitchRoll(angle, MathHelper.PiOver2, 0.0f);
                    card.CanMove = false;
                    facedown -= rad;
                    this._numFaceDownCards++;
                } else if (card.CardType == CardType.FaceUpCard) // face up cards to be placed on the table in front of the player
                {
                    float angle = (this.Rotation.Y - faceup) + addAngle;
                    dist -= 5.0f;
                    card.Position = card.StartingPosition = new Vector3((float)Math.Sin(angle) * dist + this._table.Position.X,
                                                            this._table.Position.Y + 3.0f,
                                                            (float)Math.Cos(angle) * dist + this._table.Position.Z);
                    card.QRotation = Quaternion.CreateFromYawPitchRoll(angle, -MathHelper.PiOver2, 0.0f);
                    faceup -= rad;
                    this._numFaceupCards++;
                }
            }
            ArrangeCardsInHand(); // arrange any cards in the players hand
        }

        /// <summary>
        /// Arrange any cards in the players hand so that their fanned out
        /// </summary>
        private void ArrangeCardsInHand() {
            if (this._hand.Count > 0) {

                this._shape.RaiseLeftHand(); // make sure the left hand is raised

                float angle;
                int cardsToUse; // how many cards to use to determine the angle of the cards with each other
                if (this._numCardsInHand < 26)
                    cardsToUse = 26; // half the deck of cards
                else
                    cardsToUse = 52; // the full deck of cards
                angle = MathHelper.Pi / cardsToUse; // the angle each card takes up if cardsToUser were arranged in 180 degrees

                float dist = 13.0f; // a dist to move the cards in a circle
                Vector3 handPos = this._shape.LeftHandPosition; // the left hand position
                int i = (cardsToUse / 2) - (this._numCardsInHand / 2); // keep the cards centered (based on holding a full 52 card deck, which number do you start from
                if(this._TRACE) Console.WriteLine(i + " angle incretement in arrangecards, " + this._numCardsInHand + " = num cards in hand");
                // so the cards you hold are centered)
                foreach (Card card in this._hand) {
                    if (card.CardType == CardType.InHandCard) { // if the player is holding the card
                        Vector3 pos = new Vector3((float)Math.Sin(angle * i - MathHelper.PiOver2) * dist, // slight fanning position
                                                   (float)Math.Cos(angle * i - MathHelper.PiOver2) * dist,
                                                    -8.0f + 0.35f * i);
                        card.Position = card.StartingPosition = handPos + 
                                                                Vector3.Transform(pos, Matrix.CreateRotationY(this.Rotation.Y)); // move the card to the hand, and rotate the fan
                                                                                                                                // based on the player's rotation around the table
                        card.QRotation = Quaternion.CreateFromYawPitchRoll(this.Rotation.Y,
                                                                            MathHelper.ToRadians(-10.0f),
                                                                            (-angle * i + MathHelper.PiOver2)); // the rotation of the card
                        i++;
                    }
                }
            }
        }

        /// <summary>
        /// This function swaps two cards - their CardType and position
        /// </summary>
        /// <param name="card">The first card to swap</param>
        /// <param name="card_2">The second card to swap</param>
        private void SwapCards(Card card, Card card_2) {    
            //swap the cards places
            int n = card.Place;
            card.Place = card_2.Place;
            card_2.Place = n;

            if (card.CardType != card_2.CardType) { // swap card types if needed
                int ct = (int)card.CardType;
                card.CardType = card_2.CardType;
                card_2.CardType = (CardType)ct;
            }

            //log the message if it's pre-game
            if(this._currState == PlayerInGameState.PreGame)
                this._game.HUD.AddLogMessage(this._logNum, "swapped a " + card.CardValue + " with a " + card_2.CardValue, this.SkinColor);

            ArrangeCards(); // arrange the cards
        }

        /// <summary>
        /// This function swaps two cards by their original card number
        /// </summary>
        /// <param name="c1">The original card number of the first card to swap</param>
        /// <param name="c2">The original card number of the second card to swap</param>
        public void SwapCards(int c1, int c2) {
            Card card1 = null, card2 = null;
            //get the two cards to be swapped
            foreach (Card card in this._hand) {
                if (card.OriginalCardNum == c1)
                    card1 = card;
                else if (card.OriginalCardNum == c2)
                    card2 = card;
            }
            Console.WriteLine("Player " + this._playerNum + " swapped the " + card1.CardDescription + " with the " + card2.CardDescription);
            this.SwapCards(card1, card2); // call the other swap card function
        }

        /// <summary>
        /// Pick the best card to play (AI only)
        /// </summary>
        private void PickBestCard() {
            if (this._currState == PlayerInGameState.HandCards){
                List<Card> cards = this.GetCardsOfType(CardType.InHandCard);
                this._currentlySelectedCards.Add(cards[this._canPlayCardNumber]);
            } else if (this._currState == PlayerInGameState.FaceUpCards) {
                List<Card> cards = this.GetCardsOfType(CardType.FaceUpCard);
                this._currentlySelectedCards.Add(cards[this._canPlayCardNumber]);
            } else if (this._currState == PlayerInGameState.FaceDownCards) {
                List<Card> cards = this.GetCardsOfType(CardType.FaceDownCard);
                this._currentlySelectedCards.Add(cards[0]);
            }
        }

        /// <summary>
        /// Select cards of the same value automatically
        /// </summary>
        public void SelectSameCards() {
            if (this._currentlySelectedCards.Count == 0)
                return;

            // find what type of cards we're looking for
            CardType type = CardType.InDeckCard;
            if (this._currState == PlayerInGameState.HandCards || this._currState == PlayerInGameState.PreGame)
                type = CardType.InHandCard;
            else if (this._currState == PlayerInGameState.FaceUpCards)
                type = CardType.FaceUpCard;

            List<Card> cards = this.GetCardsOfType(type); // get a list of the cards
            foreach (Card c in cards) {
                // if the value is the same and the card isn't already selected
                if (c.CardValue == this._currentlySelectedCards[0].CardValue && !c.Selected) {
                    c.Selected = true;
                    this._currentlySelectedCards.Add(c);
                }
            }
        }

        /// <summary>
        /// This function gets called every time the player selects a card
        /// </summary>
        private void OnSelectCard() {
            // the player has just received his cards and is in a pre game state
            if (this._currState == PlayerInGameState.PreGame ||
                (this._currState == PlayerInGameState.HandCards && !this._isMyTurn) ||
                (this._currState == PlayerInGameState.FaceUpCards && !this._isMyTurn)) {
                // if he's selected two cards
                if (this._currentlySelectedCards.Count > 1) {
                    SwapCards(this._currentlySelectedCards[0], this._currentlySelectedCards[1]);
                    string swapped = this._currentlySelectedCards[0].OriginalCardNum + " " + this._currentlySelectedCards[1].OriginalCardNum;
                    ClearAllSelectedCards(); // clear the selected list
                    this._netConn.SendSwapCards(swapped); // send a message that two cards were swapped
                }
            }
        }

        /// <summary>
        /// The player has picked up the cards, even though he didn't have to
        /// </summary>
        public void ForcePickup() {
            this._justPickedUp = true;
            this._forcedPickup = true;
            this._game.Pickup(this); // pick it up
            this._game.EndTurn(this);
        }

        /// <summary>
        /// Reset the player
        /// </summary>
        public void Reset() {
            this._currentlyFocusedCard = null;
            this._currentlySelectedCards.Clear();
            this._currState = PlayerInGameState.None;
            this._forcedPickup = false;
            this._hand.Clear();
            this._isMyTurn = false;
            this._justCancelledPile = false;
            this._justPickedUp = false;
            this._numCardsInHand = 0;
            this._numFaceDownCards = 0;
            this._numFaceupCards = 0;
            this._readyToBegin = false;
        }

        /// <summary>
        /// Runs a per-triangle picking algorithm over models in the scene,
        /// storing which triangle is currently under the cursor.
        /// </summary>
        private void UpdateFocus() {
            // Look up a collision ray based on the current cursor position. See the
            // Picking Sample documentation for a detailed explanation of this.
            Ray cursorRay = CollisionHelper.GetPickRay(this._smocgGame, this.FreeCamera, this._prevMouseState.X, this._prevMouseState.Y);
#if SHOW_DEBUG_LINES
            _debugLine.SetPoints(cursorRay);
#endif

            // Keep track of the closest object we have seen so far, so we can
            // choose the closest one if there are several models under the cursor.
            float closestIntersection = float.MaxValue;

            bool cardFocused = false; // no card has been focused

            // Loop over all our models.
            lock (this._game.Deck.Cards) { // lock the cards
                foreach (Card card in this._game.Deck.Cards) {
#if SHOW_DEBUG_LINES
                    Vector3 vertex1, vertex2, vertex3;
#endif

                    // Perform the ray to model intersection test.
#if SHOW_DEBUG_LINES
                    float? intersection = CollisionHelper.RayIntersectsModel(cursorRay, card.Shape.Model, card.Shape.World,
                                                         out vertex1, out vertex2,
                                                         out vertex3);
#else
                    float? intersection = CollisionHelper.RayIntersectsModel(cursorRay, card.Shape.Model, card.Shape.World);
#endif

                    // Do we have a per-triangle intersection with this model?
                    if (intersection != null) {
                        // If so, is it closer than any other model we might have
                        // previously intersected?
                        if (intersection < closestIntersection && PlayHelper.CanFocusCard(this, card)) {
                            // Store information about this model.
                            closestIntersection = intersection.Value;

                            if (card != _currentlyFocusedCard) {
                                if (_currentlyFocusedCard != null) _currentlyFocusedCard.Focused = false;
                                _currentlyFocusedCard = card;
                                _currentlyFocusedCard.Focused = true;
                            }

                            cardFocused = true;

#if SHOW_DEBUG_LINES
                            // Store vertex positions so we can display the picked triangle.
                            pickedTriangle[0].Position = vertex1;
                            pickedTriangle[1].Position = vertex2;
                            pickedTriangle[2].Position = vertex3;
#endif
                        }
                    }
                }
            }
            if (!cardFocused) {
                if (_currentlyFocusedCard != null) _currentlyFocusedCard.Focused = false;
                _currentlyFocusedCard = null;
            }

            /* ---------------------------------------------------------
             * check against the table focus object
             * ---------------------------------------------------------*/
            if (this._tableFocus != null && (this._currState != PlayerInGameState.PreGame ||
                                             this._currState != PlayerInGameState.None ||
                                             this._currState != PlayerInGameState.Out)) {
                float? intersection = CollisionHelper.RayIntersectsModel(cursorRay, this._tableFocus.Shape.Model, this._tableFocus.Shape.World);
                if (intersection != null && !this._overTableFocus) { // if we're over the focus, and we haven't been before
                    this._tableFocus.Shape.Diffuse = Color.Gold;
                    this._overTableFocus = this._tableFocus.Focused = true;
                } else if (intersection == null && this._overTableFocus) { // if we're not over the focus, and we just were
                    this._tableFocus.Shape.Diffuse = Color.White;
                    this._overTableFocus = this._tableFocus.Focused = false;
                }
            }
        }

        #region DrawPickedTriangle function
        /// <summary>
        /// Helper for drawing the outline of the triangle currently under the cursor.
        /// </summary>
#if SHOW_DEBUG_LINES
        private void DrawPickedTriangle()
        {
            if (this._currentlyFocusedCard != null)
            {
                GraphicsDevice device = SMOCGGame.Graphics.GraphicsDevice;
                RenderState renderState = device.RenderState;

                // Set line drawing renderstates. We disable backface culling
                // and turn off the depth buffer because we want to be able to
                // see the picked triangle outline regardless of which way it is
                // facing, and even if there is other geometry in front of it.
                renderState.FillMode = FillMode.WireFrame;
                renderState.CullMode = CullMode.None;
                renderState.DepthBufferEnable = false;

                // Activate the line drawing BasicEffect.
                lineEffect.Projection = this.Camera.Projection;
                lineEffect.View = this.Camera.View;

                lineEffect.Begin();
                lineEffect.CurrentTechnique.Passes[0].Begin();

                // Draw the triangle.
                device.VertexDeclaration = lineVertexDeclaration;

                device.DrawUserPrimitives(PrimitiveType.TriangleList,
                                          pickedTriangle, 0, 1);

                lineEffect.CurrentTechnique.Passes[0].End();
                lineEffect.End();

                // Reset renderstates to their default values.
                renderState.FillMode = FillMode.Solid;
                renderState.CullMode = CullMode.CullCounterClockwiseFace;
                renderState.DepthBufferEnable = true;
            }
        }
#endif
        #endregion

        //bool _doAi = false;
        //double _time = 1.0f;
        //double _currTimePassed = 0.0f;

        /// <summary>
        /// Update the Player and call Update() on it's PlayerShape
        /// </summary>
        /// <param name="deltaTime">The time since the last call to Update()</param>
        public override void Update(TimeSpan deltaTime) {
            if (this._userControlled) {
                UpdateInput(deltaTime);
            }

            /* AI and timer -----------------------------------------------*/

            //if (!this._userControlled && this._isMyTurn && !_doAi) {
            //    this._currTimePassed += deltaTime.TotalSeconds;
            //    if (this._currTimePassed > this._time)
            //        this._doAi = true;
            //}
            //if (!this._userControlled && this._doAi && this._currState != PlayerInGameState.Out && !this._justPickedUp) {
            //    PickBestCard(); // pick the best card
            //    // if the player is playing from the face down cards, then he picks one, so check to see if it's valid,
            //    // otherwise he'll have to pick up. with the other states (faceup and hand cards) it will already have
            //    // been checked if he has a valid card, in the OnMyTurn() function
            //    if (this._currState == PlayerInGameState.FaceDownCards) {
            //        // he can play the card
            //        if (PlayHelper.CanPlaceCard(this, this._currentlySelectedCards[0], this._game.Deck)) {
            //            this._game.PlaceCardsInPickupPile(this); // place the cards in the pickup pile
            //            this._game.EndTurn(this); // end the player's turn
            //        } 
            //        else 
            //        { // he has to pickup
            //            this._justPickedUp = true;
            //            this._game.PlaceCardsInPickupPile(this); // place the card in the pickup pile
            //            this._game.Pickup(this); // pick it up
            //            this._game.EndTurn(this);
            //        }
            //    } else {
            //        this._game.PlaceCardsInPickupPile(this); // place the cards in the pickup pile
            //        this._game.EndTurn(this); // end the player's turn
            //    }

            //    this._currTimePassed = 0.0f;
            //    this._doAi = false;
            //}

            /*------------------------------------------------------------*/

            if (this._numCardsInHand > 0) // if the player has cards
                _shape.RaiseLeftHand(); // raise his hand
            else
                _shape.LowerLeftHand();

            if (_shape != null)
                _shape.Update(deltaTime);
        }

        /// <summary>
        /// Update the input from the mouse, if the player is user controlled
        /// </summary>
        /// <param name="deltaTime">The time since the last call to UpdateInput</param>
        private void UpdateInput(TimeSpan deltaTime) {
            float camSpeed = 0.2f; // the speed of the camera

            MouseState mstate = Mouse.GetState(); // get the mouse state

            if (mstate.RightButton == ButtonState.Pressed) { // if the right button is pressed

                //move the camera
                float mxc = mstate.X - this._prevMouseState.X;
                float myc = mstate.Y - this._prevMouseState.Y;

                this._freeCamera.PanVertically(-myc * camSpeed * (float)deltaTime.TotalSeconds);
                this._freeCamera.PanHorizontally(mxc * camSpeed * (float)deltaTime.TotalSeconds);

            } // else if the left button has just been released
            else if (mstate.LeftButton == ButtonState.Released && this._prevMouseState.LeftButton == ButtonState.Pressed) {
                // if we're currently focusing on a card, and we can select it
                if (this._currentlyFocusedCard != null && PlayHelper.CanSelectCard(this, this._currentlyFocusedCard)) {
                    if (this._currentlyFocusedCard.Selected) { // if we're selecting a card that's already selected
                        ClearSelectedCard(this._currentlyFocusedCard); // remove the card from the selected card list
                    } else {
                        if (this._currentlySelectedCards.Count < _maxSelectedCards) { // if we haven't selected the maximum yet
                            this._currentlyFocusedCard.Selected = true;
                            this._currentlySelectedCards.Add(this._currentlyFocusedCard);

                            this._game.HUD.ButtonActivation(HUDButtons.SelectSame, true); // activate the select same button
                        }
                    }
                    OnSelectCard();
                } else {
                    // check to see that we're not clicking the select same cards button
                    if (!this._game.SelectSameWithMouse) {
                        // if we have some cards selected, and we're clicking on the table focus, and it's our turn
                        if (this._tableFocus.Focused && this._currentlySelectedCards.Count > 0 && this._isMyTurn) {
                            if (PlayHelper.CanPlaceCard(this, this._currentlySelectedCards[0], this._game.Deck)) {
                                this._game.PlaceCardsInPickupPile(this); // place the cards in the pickup pile
                                this._game.EndTurn(this); // end the player's turn
                            } else {
                                if (this._currState == PlayerInGameState.FaceDownCards) {
                                    this._justPickedUp = true;
                                    this._game.PlaceCardsInPickupPile(this); // place the card in the pickup pile
                                    this._game.Pickup(this); // pick it up
                                    this._game.EndTurn(this);
                                }
                                if (this._TRACE) Console.WriteLine("Can't play that card");
                            }
                        } else
                            ClearAllSelectedCards(); // deselect all the cards currently selected
                    } else
                        this._game.SelectSameWithMouse = false;
                }

            } else
                UpdateFocus(); // update the focus of the mouse

            this._prevMouseState = mstate; // record the previous mouse state
        }

        /// <summary>
        /// Render the player's PlayerShape
        /// </summary>
        public override void Render() {
            if (_shape != null)
                _shape.Render();

#if SHOW_DEBUG_LINES
            DrawPickedTriangle();
            _debugLine.Draw(this._freeCamera);
#endif
        }

        // load and save the settings
        #region Save and Load

        //the saveSettingsData struct
        [Serializable]
        public struct PlayerSaveData {
            public string _name;
            public int _hairType;
            public int _hairColor;
            public int _skinColor;
            public int _faceTexture;

            /// <summary>
            /// write out the contents of the struct to the console - testing only
            /// </summary>
            public void Write() {
                Console.WriteLine("------------------------");
                Console.WriteLine("player name = " + this._name);
                Console.WriteLine("player hair type = " + this._hairType);
                Console.WriteLine("player hair color = " + this._hairColor);
                Console.WriteLine("player skin color = " + this._skinColor);
                Console.WriteLine("player face texture = " + this._faceTexture);
                Console.WriteLine("------------------------");
            }
        }

        /// <summary>
        /// saves the settings to a file
        /// </summary>
        /// <param name="filename">the filename to save to</param>
        public void Save(string filename) {
            // Create the data to save
            PlayerSaveData data = new PlayerSaveData();
            //fill out the data
            data._name = this.Name;
            data._hairType = (int)this.HairType;
            data._hairColor = (int)this.HairColor;
            data._skinColor = (int)this.SkinColor;
            data._faceTexture = (int)this.FaceTexture;

            //sometimes there's problems when rewriting the file and it doesn't write properly,
            //meaning the subsequent Load() doesn't work and you get an IO error
            //so just delete it if it's already there
            if (File.Exists(filename))
                File.Delete(filename); // delete the file if it exists

            //open a stream to the filename
            Stream stream = File.Open(filename, FileMode.OpenOrCreate, FileAccess.Write);

            //create an xml serializer and stream the data to the file
            XmlSerializer serializer = new XmlSerializer(typeof(PlayerSaveData));
            serializer.Serialize(stream, data);
            stream.Close();
        }

        ///<summary>
        ///loads settings from a file
        ///</summary>
        ///<param name="filename">the filename to load from</param>
        public void Load(string filename) {
            Console.WriteLine("Loading player from file " + filename);
            // Check to see if the save exists
            if (!File.Exists(filename))
                // Notify the user there is no save           
                return;

            //open the file, and stream it to the relevant type
            Stream stream = File.OpenRead(filename);
            XmlSerializer serializer = new XmlSerializer(typeof(PlayerSaveData));
            //try to read in the settings - if the settings are fubared, then deserialize
            //won't work and will throw an InvalidOperationException
            try {
                PlayerSaveData data = (PlayerSaveData)serializer.Deserialize(stream);
                //data.Write(); // write the data to the console
                //use the data
                this.Name = data._name;
                this.HairType = (PlayerHairType)data._hairType;
                this.HairColor = (PlayerColorChoice)data._hairColor;
                this.SkinColor = (PlayerColorChoice)data._skinColor;
                this.FaceTexture = (PlayerFaceTextures)data._faceTexture;
            }
            catch (InvalidOperationException) {
                //bury it, just use the default settings
                Console.WriteLine("XML file is nobbed, so using default player settings");
            }

            //close the stream
            stream.Close();
        }
        #endregion
    }
}
