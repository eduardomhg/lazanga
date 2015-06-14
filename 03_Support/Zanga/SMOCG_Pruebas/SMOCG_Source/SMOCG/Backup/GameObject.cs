#region Dependancies
using System;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using SMOCG.Cameras;
#endregion

namespace SMOCG {
    /// <summary>
    /// a GameObject represents something in a scene that can have position, rotation etc, as well
    /// as a <see cref="Shape">Shape</see> to render
    /// </summary>
    public class GameObject {
        private SMOCGGame _game; // a reference to the main game object
        private Shape _shape; // the renderable shape of the object

        private BasicCamera _camera; // the camera used to view the game object

        private Vector3 _position = new Vector3(0.0f); // the position of the object
        private Vector3 _rotation = new Vector3(0.0f); // the rotation of the object
        private Vector3 _scale = new Vector3(1.0f); // the scale of the object

        private float _colRadius = 0.0f; // the collision radius of this object
        private bool _isPaused = false; // is the simulation paused for this object
        private bool _focused = false; // is the object focused

        #region Get Set Properties

        /// <summary>
        /// Get the reference to the main game object
        /// </summary>
        public SMOCGGame Game {
            get { return _game; }
        }

        /// <summary>
        /// Get the game object's shape
        /// </summary>
        public Shape Shape {
            get { return _shape; }
        }

        /// <summary>
        /// Get the game object's camera
        /// </summary>
        public virtual BasicCamera Camera{
            get{ return _camera;}
            set { _camera = value; }
        }

        /// <summary>
        /// the object's position
        /// </summary>
        public virtual Vector3 Position {
            get { return _position; }
            set { _position = value; }
        }

        /// <summary>
        /// The object's rotation
        /// </summary>
        public virtual Vector3 Rotation {
            get { return _rotation; }
            set { _rotation = value; }
        }

        /// <summary>
        /// The object's scale
        /// </summary>
        public virtual Vector3 Scale {
            get { return _scale; }
            set { _scale = value; }
        }

        /// <summary>
        /// The collision radius of the object
        /// </summary>
        public float CollisionRadius {
            get { return _colRadius; }
            set { _colRadius = value; }
        }

        /// <summary>
        /// If the object is paused or not. If it's paused, then no Update's will take place
        /// </summary>
        public bool IsPaused {
            get { return _isPaused; }
            set { _isPaused = value; }
        }

        /// <summary>
        /// Get and set whether the object is focused or not
        /// </summary>
        public bool Focused {
            get { return _focused; }
            set { _focused = value; }
        }

        #endregion

        #region Constructors

        /// <summary>
        /// Create a basic GameObject object
        /// </summary>
        /// <param name="game">A reference to the main game object</param>
        public GameObject(SMOCGGame game) {
            this._game = game;
        }

        /// <summary>
        /// Create a game object with a specified model
        /// </summary>
        /// <param name="game">A reference to the main game object</param>
        /// <param name="modelName">The name of the model to load in</param>
        public GameObject(SMOCGGame game, string modelName) {
            this._game = game; // hold the reference to the main game object
            this._shape = new Shape(); // create the shape
            this._shape.Model = game.ContentManager.Load<Model>(modelName); // load in the model
        }

        /// <summary>
        /// Create a game object with a specified model and texture
        /// </summary>
        /// <param name="game">A reference to the main game object</param>
        /// <param name="modelName">The name of the model to load in</param>
        /// <param name="textureName">The name of the texture to load in</param>
        public GameObject(SMOCGGame game, string modelName, string textureName) {
            this._game = game; // hold the reference to the main game object
            this._shape = new Shape(); // create the shape
            this._shape.Model = game.ContentManager.Load<Model>(modelName); // load in the model
            this._shape.Texture = game.ContentManager.Load<Texture2D>(textureName); // load in the texture
            this._shape.HasTexture = true; // tell the shape that it's using a texture
        }

        /// <summary>
        /// Create a game object with a center, position, rotation, scale, and a blank shape object
        /// </summary>
        /// <param name="game">A reference to the main game object</param>
        /// <param name="position">The position of the game object</param>
        /// <param name="rotation">The rotation of the game object</param>
        /// <param name="scale">The scale of the game object</param>
        public GameObject(SMOCGGame game, Vector3 position, Vector3 rotation, Vector3 scale) {
            this._game = game; // hold the reference to the main game object
            this._position = position;
            this._rotation = rotation;
            this._scale = scale;

            this._shape = new Shape();
        }

        /// <summary>
        /// Create a game object with a center, position, rotation, scale, and a specified model
        /// </summary>
        /// <param name="game">A reference to the main game object</param>
        /// <param name="position">The position of the game object</param>
        /// <param name="rotation">The rotation of the game object</param>
        /// <param name="scale">The scale of the game object</param>
        /// <param name="modelName">The name of the model to load in</param>
        public GameObject(SMOCGGame game, Vector3 position, Vector3 rotation, Vector3 scale, string modelName) {
            this._game = game; // hold the reference to the main game object
            this._position = position;
            this._rotation = rotation;
            this._scale = scale;

            this._shape = new Shape(); // create the shape
            this._shape.Model = game.ContentManager.Load<Model>(modelName); // load in the model
        }

        /// <summary>
        /// Create a game object with a center, position, rotation, scale, a specified model, and a texture
        /// </summary>
        /// <param name="game">A reference to the main game object</param>
        /// <param name="position">The position of the game object</param>
        /// <param name="rotation">The rotation of the game object</param>
        /// <param name="scale">The scale of the game object</param>
        /// <param name="modelName">The name of the model to load in</param>
        /// <param name="textureName">The name of the texture to load in</param>
        public GameObject(SMOCGGame game, Vector3 position, Vector3 rotation, Vector3 scale, string modelName, string textureName) {
            this._game = game; // hold the reference to the main game object
            this._position = position;
            this._rotation = rotation;
            this._scale = scale;

            this._shape = new Shape(); // create the shape
            this._shape.Model = game.ContentManager.Load<Model>(modelName); // load in the model
            this._shape.Texture = game.ContentManager.Load<Texture2D>(textureName); // load in the model's texture
            this._shape.HasTexture = true; // tell the shape that it has a texture
        }
        #endregion

        /// <summary>
        /// updates the GameObject
        /// </summary>
        /// <param name="deltaTime">the time since the last call to Update()</param>
        public virtual void Update(TimeSpan deltaTime) {
            if (this._shape != null) {
                if(this._camera == null)
                    this._camera = this._game.Camera;

                this._shape.View = _camera.View; // grab the view matrix from the camera
                this._shape.Proj = _camera.Projection; // grab the projection matrix from the camera

                // scale the shape, rotate it, then move it back to it's place
                this._shape.World = Matrix.CreateScale(this._scale) *
                                    Matrix.CreateRotationX(this._rotation.X) *
                                    Matrix.CreateRotationY(this._rotation.Y) *
                                    Matrix.CreateRotationZ(this._rotation.Z) *
                                    Matrix.CreateTranslation(this._position);
            }
        }

        /// <summary>
        /// If the GameObject has a shape associated with it, then draw it
        /// </summary>
        public virtual void Render() {
            //if this item has a shape, then draw it
            if (this._shape != null)
                this._shape.Render();
        }

        /// <summary>
        /// Do a simple collision check with another GameObject
        /// </summary>
        /// <param name="obj">the GameObject to check against</param>
        /// <returns>A bool of whether the two objects are in collision with each other</returns>
        public virtual bool Collide(GameObject obj) {
            //do a simple sphere sphere collision
            if ((this._position - obj.Position).Length() < this._colRadius + obj.CollisionRadius)
                return true;

            return false;
        }
    }
}
