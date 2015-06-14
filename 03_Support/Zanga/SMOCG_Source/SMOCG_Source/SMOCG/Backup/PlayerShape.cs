#region Dependancies
using System;
using System.Collections.Generic;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using SMOCG.Cameras;
using SMOCG.Settings;
#endregion

namespace SMOCG {
    /// <summary>
    /// A PlayerShape represents the in-game view of a user. it holds a customisable model and seperate hands, which can be moved
    /// </summary>
    public class PlayerShape {
        private float _angle = 0.0f; // temp angle for rotation

        private SMOCGGame _game; // a reference to the main game object
        private Player _player; // a reference to the player that created the shape

        private GameObject _head; // a GameObject representing the head
        private GameObject _leftHand; // a GameObject representing the left hand
        private GameObject _rightHand; // a GameObject representing the right hand
        private GameObject _hair; // a GameObject representing the hair
        private bool _hasHair = true; // has the PlayerShape any hair to begin with (could be bald)

        private Vector3 _leftHandPosLower; // the position of the left hand when the player has no cards to hold
        private Vector3 _leftHandPosRaised; // the position of the left hand when the player has cards to hold

        private static Model _headModel; // the model for all the player's heads
        private static Model _handsModel; // the model for all the player's hands

        private static Model[] _allHairModels = new Model[SMOCGGame.Settings.HairModels.Length]; // an array of hair Models that all PlayerShapes can use
        private static Texture2D[] _allFaceTextures = new Texture2D[SMOCGGame.Settings.FaceTextures.Length]; // an array of face textures that all PlayerShapes can use
        private static bool _allModelsAndTexturesLoaded = false; // have all the models and face textures been loaded in?

        private int _hairType = 0; // the hair type used for this model
        private int _hairColor = 0; // the hair color used for this model
        private int _faceTexture = 0; // the face texture used for this model
        private int _skinColor = 0; // the skin color used for this model

        private bool _hairTypeChanged = false; // set a bool to determine when to change the hair type

        #region Get and set Customisables

        /// <summary>
        /// Get and Set the hair model used by the player. use the PlayerHairType enum for ease of use
        /// </summary>
        public int HairType {
            get { return _hairType; }
            set {
                if (value > _allHairModels.Length - 1) _hairType = _allHairModels.Length - 1;
                else _hairType = value;

                _hairTypeChanged = true;
            }
        }

        /// <summary>
        /// Get and set the hair color used by the player. use the PlayerColorChoice enum for ease of use
        /// </summary>
        public int HairColor { 
            get { return _hairColor; }
            set {
                if (value > SMOCGGame.Settings.PlayerColors.Length - 1) _hairColor = SMOCGGame.Settings.PlayerColors.Length - 1;
                else _hairColor = value;

                this._hair.Shape.Diffuse = this._hair.Shape.Specular = SMOCGGame.Settings.PlayerColors[this._hairColor]; // assign the hair color
            }
        }

        /// <summary>
        /// Get and set the face texture used by the player. use the PlayerFaceTextures enum for ease of use
        /// </summary>
        public int FaceTexture { 
            get { return _faceTexture; }
            set {
                if (value > _allFaceTextures.Length) _faceTexture = _allFaceTextures.Length - 1;
                else _faceTexture = value;

                this._head.Shape.Texture = _allFaceTextures[this._faceTexture]; // assign the face texture
            }
        }

        /// <summary>
        /// Get and set the skin color used by the player. use the PlayerColorChoice enum for ease of use
        /// </summary>
        public int SkinColor {
            get { return _skinColor; }
            set {
                if (value > SMOCGGame.Settings.PlayerColors.Length - 1) _skinColor = SMOCGGame.Settings.PlayerColors.Length - 1;
                else _skinColor = value;

                this._head.Shape.Diffuse = this._head.Shape.Specular = 
                    this._leftHand.Shape.Diffuse = this._leftHand.Shape.Specular = 
                    this._rightHand.Shape.Diffuse = this._rightHand.Shape.Specular = SMOCGGame.Settings.PlayerColors[this._skinColor]; // assign the skin color
            }
        }

        /// <summary>
        /// Get and set the player's shape's position
        /// </summary>
        public Vector3 Position {
            get { return this._head.Position; }
            set { 
                this._head.Position = value;
                this._hair.Position = value;
                SetHandPos();
            }
        }

        /// <summary>
        /// Get the left hand position
        /// </summary>
        public Vector3 LeftHandPosition {
            get { return this._leftHand.Position; }
        }

        /// <summary>
        /// Get and set the player's shape's rotation
        /// </summary>
        public Vector3 Rotation {
            get { return this._head.Rotation; }
            set {
                this._head.Rotation = value;
                this._hair.Rotation = value;
                this._leftHand.Rotation = value;
                this._rightHand.Rotation = value;
                SetHandPos();
            }
        }

        /// <summary>
        /// Get and set the player's shape's scale
        /// </summary>
        public Vector3 Scale {
            get { return this._head.Scale; }
            set {
                this._head.Scale = value;
                this._hair.Scale = value;
                this._leftHand.Scale = value;
                this._rightHand.Scale = value;
                SetHandPos();
            }
        }

        /// <summary>
        /// Set the camera for the player shape - the player may be being viewed through another's eyes
        /// </summary>
        public BasicCamera Camera {
            set { this._head.Camera = value; }
        }

        #endregion

        /// <summary>
        /// Creates a PlayerShape with a Camera for viewing, a position, a scale, a path to the head model, a path to the hair model,
        /// a path to the hands model, and a path to the face texture
        /// </summary>
        /// <param name="game">A reference to the main game object</param>
        /// <param name="player">A reference to the player that created the shape</param>
        /// <param name="camera">a <see cref="BasicCamera">BasicCamera</see> used to view the player</param>
        /// <param name="pos">Where the PlayerShape is positioned</param>
        /// <param name="rot">The rotation of the PlayerShape</param>
        /// <param name="scale">The scale of the PlayerShape</param>
        /// <param name="hairType">Which hair model to use</param>
        /// <param name="hairColor">The color of the hair</param>
        /// <param name="faceTexture">The texture to use on the face</param>
        /// <param name="skinColor">The color of the skin</param>
        public PlayerShape(SMOCGGame game, Player player, BasicCamera camera, Vector3 pos, Vector3 rot, Vector3 scale, int hairType, int hairColor, int faceTexture, int skinColor){
            this._game = game;
            this._player = player;

            if (!_allModelsAndTexturesLoaded) LoadAllModelsAndTextures(); // load in the hair models and face textures if needed

            this._head = new GameObject(game, pos, rot, scale); // set up the head game object
            this._hair = new GameObject(game, pos, rot, scale); // set up the hair game object
            this._leftHand = new GameObject(game, pos + new Vector3(-20.0f, -60.0f, 0.0f), rot, scale); // set up the left hand game object
            this._rightHand = new GameObject(game, pos + new Vector3(20.0f, -60.0f, 0.0f), rot, scale); // set up the right hand game object

            GetEyePos();

            //record the player choices
            this.HairType = hairType;
            this.HairColor = hairColor;
            this.FaceTexture = faceTexture;
            this.SkinColor = skinColor;

            this._head.Shape.Model = _headModel; // assign the head model
            this._head.Shape.Texture = _allFaceTextures[this._faceTexture]; // assign the head texture

            this._leftHand.Shape.Model = this._rightHand.Shape.Model = _handsModel; // assign the hands model
            if (this._hasHair) this._hair.Shape.Model = _allHairModels[this._hairType]; // assign the hair model if the player has one

            //assign the camera - don't need to do this for the other shapes, as they'll use the same camera
            this._head.Camera = camera;
            //turn on per pixel lighting for each of the objects
            this._head.Shape.UsePerPixelLighting = 
                this._hair.Shape.UsePerPixelLighting = 
                this._leftHand.Shape.UsePerPixelLighting = 
                this._rightHand.Shape.UsePerPixelLighting = true;
            this._head.Shape.Diffuse = 
                this._leftHand.Shape.Diffuse = 
                this._rightHand.Shape.Diffuse = SMOCGGame.Settings.PlayerColors[this._skinColor]; // the color for the hands
            this._hair.Shape.Diffuse = SMOCGGame.Settings.PlayerColors[this._hairColor]; // the color for the hair
            this._head.Shape.Specular = 
                this._leftHand.Shape.Specular = 
                this._rightHand.Shape.Specular = this._head.Shape.Diffuse;// the specular color for the skin
            this._hair.Shape.Specular = this._hair.Shape.Diffuse; // set the specular color for the hair
            this._head.Shape.SpecularPower = 
                this._hair.Shape.SpecularPower = 
                this._leftHand.Shape.SpecularPower = 
                this._rightHand.Shape.SpecularPower = 100.0f; // the specular power
        }

        /// <summary>
        /// Load in all the hair models and face textures, so they can be used immediately
        /// </summary>
        private void LoadAllModelsAndTextures(){
            _headModel = this._game.ContentManager.Load<Model>(SMOCGGame.Settings.ModelLoadPath + "face"); // load in the head model
            _handsModel = this._game.ContentManager.Load<Model>(SMOCGGame.Settings.ModelLoadPath + "hand"); // load in the hand model

            //load in all the hair models
            for (int i = 0; i < SMOCGGame.Settings.HairModels.Length; i++) {
                if (SMOCGGame.Settings.HairModels[i] != "") { // if it's not blank
                    _allHairModels[i] = this._game.ContentManager.Load<Model>(SMOCGGame.Settings.ModelLoadPath + SMOCGGame.Settings.HairModels[i]);
                }
            }
            //load in all the face textures
            for (int i = 0; i < SMOCGGame.Settings.FaceTextures.Length; i++) {
                _allFaceTextures[i] = this._game.ContentManager.Load<Texture2D>(SMOCGGame.Settings.PlayerTexturePath + SMOCGGame.Settings.FaceTextures[i]);
            }
            _allModelsAndTexturesLoaded = true; //set the bool
        }

        /// <summary>
        /// Get the player's eye position for the camera
        /// </summary>
        /// <returns>A Vector3 of the player's eye position</returns>
        public Vector3 GetEyePos(){
            return this._head.Position + new Vector3(0.0f, 1.0f, 0.0f) * this._head.Scale;
        }

        /// <summary>
        /// Set the hand position for the model
        /// </summary>
        private void SetHandPos() {
            // need to make sure the left and right hand position is right
            this._leftHandPosLower = Vector3.Transform(new Vector3(-2.0f, -6.0f, 0.0f), Matrix.CreateRotationY(this._leftHand.Rotation.Y));
            this._leftHandPosRaised = Vector3.Transform(new Vector3(-0.5f, -4.0f, -2.5f), Matrix.CreateRotationY(this._leftHand.Rotation.Y));
            Vector3 right = Vector3.Transform(new Vector3(2.0f, -6.0f, 0.0f), Matrix.CreateRotationY(this._rightHand.Rotation.Y));
            this._rightHand.Position = this._head.Position + right * this._rightHand.Scale;
        }

        /// <summary>
        /// Lower the player's left hand - he doesn't have any cards to hold
        /// </summary>
        public void LowerLeftHand() {
            this._leftHand.Position = this._head.Position + this._leftHandPosLower * this._leftHand.Scale;
        }

        /// <summary>
        /// Raise the player's left hand - he has to hold some cards
        /// </summary>
        public void RaiseLeftHand() {
            this._leftHand.Position = this._head.Position + this._leftHandPosRaised * this._leftHand.Scale;
        }

        /// <summary>
        /// Update the different GameObjects that make up the PlayerShape
        /// </summary>
        /// <param name="deltaTime">The time since the last call to Update()</param>
        public void Update(TimeSpan deltaTime) {
            this._angle += 2.0f * (float)deltaTime.TotalSeconds; // increate the rotate angle
            this._head.Shape.View = this._leftHand.Shape.View = this._rightHand.Shape.View = this._head.Camera.View; // set up the view matrix for each model
            this._head.Shape.Proj = this._leftHand.Shape.Proj = this._rightHand.Shape.Proj = this._head.Camera.Projection; // set up the proj matrix for each model
            //set up the world matrix for the head model
            this._head.Shape.World = Matrix.CreateScale(this._head.Scale) *
                                     Matrix.CreateRotationX(this._head.Rotation.X) * 
                                     Matrix.CreateRotationY(this._head.Rotation.Y) * 
                                     Matrix.CreateRotationZ(this._head.Rotation.Z) * 
                                     Matrix.CreateTranslation(this._head.Position); /*
                                     Matrix.CreateRotationY(this._angle);*/
            //set up the world matrix for the left hand
            this._leftHand.Shape.World = Matrix.CreateScale(this._leftHand.Scale) *
                                        Matrix.CreateRotationX(this._leftHand.Rotation.X) *
                                        Matrix.CreateRotationY(this._leftHand.Rotation.Y) *
                                        Matrix.CreateRotationZ(this._leftHand.Rotation.Z) * 
                                        Matrix.CreateTranslation(this._leftHand.Position); /*
                                        Matrix.CreateRotationY(this._angle);*/
            //set up the world matrix for the right hand
            this._rightHand.Shape.World = Matrix.CreateScale(this._rightHand.Scale) *
                                        Matrix.CreateRotationX(this._rightHand.Rotation.X) *
                                        Matrix.CreateRotationY(this._rightHand.Rotation.Y) *
                                        Matrix.CreateRotationZ(this._rightHand.Rotation.Z) * 
                                        Matrix.CreateTranslation(this._rightHand.Position); /*
                                        Matrix.CreateRotationY(this._angle);*/

            // the reason this bool is here, is because sometimes it's possible to assign the hair's model and have it draw, before
            // the update has been called, meaning that the new hair is very briefly draw in the wrong place, resulting in a flicker
            if (this._hairTypeChanged) {
                this._hair.Shape.Model = _allHairModels[this._hairType]; // set the model

                //see if we should render the hair etc
                if ((PlayerHairType)this._hairType == PlayerHairType.Bald) this._hasHair = false;
                else this._hasHair = true;

                this._hairTypeChanged = false; // reset the bool
            }

            //only do the hair if the model has any
            if (this._hasHair) {
                this._hair.Shape.View = this._head.Camera.View;
                this._hair.Shape.Proj = this._head.Camera.Projection;
                //set up the world matrix for the hair
                this._hair.Shape.World = Matrix.CreateScale(this._hair.Scale) *
                                        Matrix.CreateRotationX(this._hair.Rotation.X) *
                                        Matrix.CreateRotationY(this._hair.Rotation.Y) *
                                        Matrix.CreateRotationZ(this._hair.Rotation.Z) * 
                                        Matrix.CreateTranslation(this._hair.Position); /*
                                        Matrix.CreateRotationY(this._angle);*/
            }
        }

        /// <summary>
        /// Render all the models that make up the PlayerShape
        /// </summary>
        public void Render() {
            SMOCGGame.Graphics.GraphicsDevice.RenderState.DepthBufferEnable = true;
            //SMOCGGame.Graphics.GraphicsDevice.RenderState.CullMode = CullMode.None;
            if (!this._player.UserControlled) {
                this._head.Render();
                if (this._hasHair) this._hair.Render();
            }
            this._leftHand.Render();
            this._rightHand.Render();
            //SMOCGGame.Graphics.GraphicsDevice.RenderState.CullMode = CullMode.CullCounterClockwiseFace;
        }
    }
}
