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
    /// a scene represents a part in the game to be rendered, effectively breaking it up.
    /// can be used as menu screens, splash screens, in-game etc.
    /// </summary>
    abstract public class Scene {
        /// <summary>
        /// another scene that will be drawn after this one, as in for overlays
        /// </summary>
        protected Scene _overlay;

        /// <summary>
        /// a sprite batch do draw the objects in the scene
        /// </summary>
        protected SpriteBatch _batch = null;

        private SMOCGGame _game; // a reference to the main game object

        //a list of all the GameObjects in the scene
        private List<GameObject> _sceneObjects;

        // is the scene paused?
        private bool _isPaused;

        #region Get Set Properties

        /// <summary>
        /// Get the reference to the main game object
        /// </summary>
        public SMOCGGame Game {
            get { return _game; }
        }

        /// <summary>
        /// Base class implementation of this just returns the main game object's camera
        /// </summary>
        public virtual BasicCamera ControllingCamera {
            get { return _game.Camera; }
        }

        /// <summary>
        /// get the spritebatch used by this scene
        /// </summary>
        public SpriteBatch SpriteBatch {
            get { return _batch; }
        }

        /// <summary>
        /// Pause or unpause the scene - this will pause all the objects in the scene
        /// </summary>
        public bool IsPaused {
            get { return _isPaused; }
            set { _isPaused = value; }
        }

        /// <summary>
        /// Get and set the scene overlay
        /// </summary>
        public Scene Overlay {
            get { return this._overlay; }
            set { this._overlay = value; }
        }
        #endregion

        /// <summary>
        /// default constructor - holds an instance of the game object, and uses it to set up the sprite batch
        /// </summary>
        /// <param name="game">A reference to the main game object</param>
        public Scene(SMOCGGame game) {
            this._game = game; // hold the reference to the main game object

            //create the sprite batch
            _batch = new SpriteBatch(SMOCGGame.Graphics.GraphicsDevice);

            //create the scene object list
            _sceneObjects = new List<GameObject>();
        }

        /// <summary>
        /// This function is available for anything that needs to be done that relies on the game object's
        /// settings being set properly, i.e. using the SMOCGGame's ControllingCamera function uses the 
        /// current scene to return the right camera, so anything that needs that camera would need to be
        /// constructed in this function
        /// </summary>
        public virtual void Init() {
        }

        /// <summary>
        /// Adds a GameObject to the list that scene holds
        /// </summary>
        /// <param name="obj">the GameObject to be held</param>
        public void AddObject(GameObject obj) {
            lock(this._sceneObjects)
                _sceneObjects.Add(obj);
        }

        /// <summary>
        /// Removes a GameObject from the list
        /// </summary>
        /// <param name="obj">The GameObject to remove</param>
        public void RemoveObject(GameObject obj) {
            lock(this._sceneObjects)
                _sceneObjects.Remove(obj);
        }

        /// <summary>
        /// Update calls the update method on all the scene's objects. it also calls any overlays
        /// and gets them to render themselves
        /// </summary>
        /// <param name="deltaTime">the change in time since the last call to update</param>
        /// <returns>the next GameState to transition to. default is None</returns>
        public virtual GameState Update(TimeSpan totalTime, TimeSpan deltaTime) {
            //update all the game objects
            lock (this._sceneObjects) {
                foreach (GameObject obj in _sceneObjects) {
                    if (_isPaused) obj.IsPaused = true;
                    obj.Update(deltaTime);
                }
            }
          
            return GameState.None;// (_overlay == null) ? GameState.None : _overlay.Update(totalTime, deltaTime);
        }

        /// <summary>
        /// Renders the scene, calls on all it's objects to render themselves, then calls
        /// any overlays
        /// </summary>
        public virtual void Render() {
            //draw any gameobjects
            lock (this._sceneObjects) {
                foreach (GameObject obj in _sceneObjects)
                    obj.Render();
            }

            //if (_overlay != null)
            //    _overlay.Render(); //render the overlay
        }

        /// <summary>
        /// tidies up the scene - calls Shutdown() on any overlays
        /// </summary>
        public virtual void Shutdown() {
            if (_overlay != null)
                _overlay.Shutdown(); // shutdown any overlays

            if (_batch != null) {
                _batch.Dispose(); // release any unmanaged resources
                _batch = null;
            }
        }

        /// <summary>
        /// CreateDevice is called when the device needs to be created, funnily enough
        /// </summary>
        public virtual void CreateDevice() {
            //recreate the sprite batch
            _batch = new SpriteBatch(SMOCGGame.Graphics.GraphicsDevice);
        }
    }
}
