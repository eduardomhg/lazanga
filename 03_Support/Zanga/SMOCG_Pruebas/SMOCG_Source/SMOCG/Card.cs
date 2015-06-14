#region Dependancies
using System;
using System.Collections.Generic;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using SMOCG.Cameras;
#endregion

namespace SMOCG {
    /// <summary>
    /// A Card represents a playing card
    /// </summary>
    public class Card : GameObject, IComparable {
        static Model _cardShape; // the model that's shared with every Card
        static bool _shapeLoaded = false; // has it been loaded yet

        private Quaternion _quatRotation; // the cards have quaterion rotation because their more likely to undergo gimbal lock

        static int _cardNum = 0; // which texture to load in for the card
        private int _textureNum; // the texture loaded in
        private int _placeNum; // where in the deck this card is placed

        private Cards _cardDescription; // the actual description of the card, i.e. AceOfHearts
        private CardType _cardType; // what the card type is (faceup, facedown, in a players hand etc)
        private CardValue _cardValue; // what value the card holds, 2-Ace

        private Vector3 _startingPos; // the starting position for the card - used to reset it after selecting

        private bool _selected = false; // is the card selected
        private bool _withUser = false; // is the card in the user's hand (don't do the jump when focusing if it isn't)
        private bool _canMove = true; // can the card move when focused
        private bool _canShowValue = true; // can the card show it's value when focused

        #region GetSet Properties

        /// <summary>
        /// Get the cards description, i.e. AceOfHearts etc.
        /// </summary>
        public Cards CardDescription{
            get { return _cardDescription; }
        }

        /// <summary>
        /// Get and set the card's type - i.e. faceup, facedown etc
        /// </summary>
        public CardType CardType {
            get { return _cardType; }
            set { _cardType = value; }
        }

        /// <summary>
        /// Get the cards value - i.e. two, three, four, etc
        /// </summary>
        public CardValue CardValue {
            get { return _cardValue; }
        }

        /// <summary>
        /// Get and set the cards place
        /// </summary>
        public int Place {
            get { return _placeNum; }
            set { _placeNum = value; }
        }

        /// <summary>
        /// Get and set the quaternion rotation for the card
        /// </summary>
        public Quaternion QRotation {
            get { return _quatRotation; }
            set { _quatRotation = value; }
        }

        /// <summary>
        /// Get and set the starting position of the card
        /// </summary>
        public Vector3 StartingPosition {
            get { return _startingPos; }
            set { _startingPos = value; }
        }

        /// <summary>
        /// Get and set whether the card is selected or not
        /// </summary>
        public bool Selected {
            get { return _selected; }
            set { _selected = value; }
        }

        /// <summary>
        /// Get and set whether the card is in the user's hand or not
        /// </summary>
        public bool WithUser {
            get { return this._withUser; }
            set { this._withUser = value; }
        }

        /// <summary>
        /// Get and set whether the card can move when focused or not
        /// </summary>
        public bool CanMove {
            get { return this._canMove; }
            set { this._canMove = value; }
        }

        /// <summary>
        /// Get and set whether the card can show it's value when focused or selected
        /// </summary>
        public bool CanShowValue {
            get { return this._canShowValue; }
            set { this._canShowValue = value; }
        }

        /// <summary>
        /// Get the cards original number in the deck
        /// </summary>
        public int OriginalCardNum {
            get { return this._textureNum; }
        }

        #endregion

        /// <summary>
        /// Create a card with a center of rotation, a position, a rotation, and a scale
        /// </summary>
        /// <param name="game">A reference to the main game object</param>
        /// <param name="camera">The camera to view the cards with</param>
        /// <param name="pos">Where the card is placed</param>
        /// <param name="rotation">The rotation of the card</param>
        /// <param name="scale">The scale of the card</param>
        public Card(SMOCGGame game, BasicCamera camera, Vector3 pos, Vector3 rotation, Vector3 scale) :
            base(game, pos, rotation, scale) // call the base constructor
        {
            if (!_shapeLoaded) { // if the model hasn't been loaded, do so
                _cardShape = game.ContentManager.Load<Model>(SMOCGGame.Settings.ModelLoadPath + "card");
                _shapeLoaded = true;
            }
            this.Shape.Model = _cardShape; // set the card shape

            this._textureNum = this._placeNum = _cardNum; // hold the texture number and place number (place number can change)
            this.Shape.Texture = game.ContentManager.Load<Texture2D>(SMOCGGame.Settings.CardTexturePath + (Cards)_cardNum++); // load in the relevant texture

            this._cardDescription = (Cards)_textureNum; // set the card description
            this._cardValue = (CardValue)(_textureNum % 13); // set the value of the card
            this._cardType = CardType.InDeckCard; // all the cards initially start out in the deck

            //create the quaternion rotation
            this._quatRotation = Quaternion.CreateFromYawPitchRoll(this.Rotation.Y, this.Rotation.X, this.Rotation.Z);

            this.Camera = camera; // set up the camera
        }

        /// <summary>
        /// Create a card with a center of rotation, a position, a rotation, and a scale
        /// </summary>
        /// <param name="game">A reference to the main game object</param>
        /// <param name="camera">The camera to view the cards with</param>
        /// <param name="pos">Where the card is placed</param>
        /// <param name="rotation">The rotation of the card</param>
        /// <param name="scale">The scale of the card</param>
        public Card(SMOCGGame game, BasicCamera camera, Vector3 pos, Vector3 rotation, Vector3 scale, bool forScreen)
            :
            base(game, pos, rotation, scale) // call the base constructor
        {
            if (!_shapeLoaded) { // if the model hasn't been loaded, do so
                _cardShape = game.ContentManager.Load<Model>(SMOCGGame.Settings.ModelLoadPath + "card");
                _shapeLoaded = true;
            }
            this.Shape.Model = _cardShape; // set the card shape

            //create the quaternion rotation
            this._quatRotation = Quaternion.CreateFromYawPitchRoll(this.Rotation.Y, this.Rotation.X, this.Rotation.Z);

            this.Camera = camera; // set up the camera
        }

        /// <summary>
        /// Compare two cards to sort
        /// </summary>
        /// <param name="o">The card to compare with</param>
        public int CompareTo(object o) {
            return this._placeNum - ((Card)o).Place;
        }

        /// <summary>
        /// Update the card - move it into place
        /// </summary>
        /// <param name="deltaTime"></param>
        public override void Update(TimeSpan deltaTime) {

            this.Position = this.StartingPosition;

            if (this._selected) {
                this.Shape.Diffuse = Color.GreenYellow;
                if (this._withUser && this._canMove) this.Position += Vector3.Transform(new Vector3(0.0f, 1.0f, 0.0f), Matrix.CreateFromQuaternion(this._quatRotation));
            } else if (this.Focused) {
                this.Shape.Diffuse = Color.Gold;
                if(this._withUser && !this._selected && this._canMove) this.Position += Vector3.Transform(new Vector3(0.0f, 1.0f, 0.0f), Matrix.CreateFromQuaternion(this._quatRotation));
            } else {
                this.Shape.Diffuse = Color.White;
            }

            this.Shape.View = this.Camera.View; // set the view from the camera
            this.Shape.Proj = this.Camera.Projection; // set the projection matrix from the camera
            this.Shape.World = Matrix.CreateScale(this.Scale) *
                                Matrix.CreateFromQuaternion(_quatRotation) *
                                Matrix.CreateTranslation(this.Position); // set the world matrix
        }
    }
}
