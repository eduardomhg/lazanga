#region Dependancies
using System;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Graphics;
#endregion

namespace SMOCG {
    public class SMOCGMouse : DrawableGameComponent
    {
        private AnimatedTexture _defaultTexture; // the default mouse texture
        private AnimatedTexture _mouseDownTexture; // the texture for when the mouse is pressed
        private AnimatedTexture _currentTexture; // the current texture that we're using
        private MouseState _state; // the current mouse state
        private CurrMouseState _currState; // what state (pointer, pressed, none, etc the current mouse is in)
        private Vector2 _mousePos = new Vector2(); // the mouse's position
        private SpriteBatch _batch = null;
        private SMOCGGame _game = null;

        /// <summary>
        /// Get the x position of the mouse
        /// </summary>
        public int X {
            get { return (int)_mousePos.X; }
        }

        /// <summary>
        /// Get the Y position of the mouse
        /// </summary>
        public int Y {
            get { return (int)_mousePos.Y; }
        }

        /// <summary>
        /// Get the latest mouse state
        /// </summary>
        public MouseState State {
            get { return _state; }
        }

        /// <summary>
        /// Constructor - initialises the mouse state and animated texture
        /// </summary>
        /// <param name="game">the game object to get the graphics device from</param>
        public SMOCGMouse(SMOCGGame game)
            : base(game) 
        {
            _game = game;
            _state = Mouse.GetState();

            _currState = CurrMouseState.Pointer; // set the current state

            //_batch = new SpriteBatch(SMOCGGame.Graphics.GraphicsDevice); //use the graphics service to create the sprite batch
        }

        /// <summary>
        /// Load in the various graphics needed
        /// </summary>
        protected override void LoadContent()
        {
            //create the different animated textures
            _defaultTexture = new AnimatedTexture(_game, _mousePos, 0.0f, 1.0f, 1.0f);
            _mouseDownTexture = new AnimatedTexture(_game, _mousePos, 0.0f, 1.0f, 1.0f);

            _defaultTexture.Load(SMOCGGame.Settings.AnimatedTexturePath + SMOCGGame.Settings.MousePointerTextureName, 4, 16);
            _mouseDownTexture.Load(SMOCGGame.Settings.AnimatedTexturePath + SMOCGGame.Settings.MouseClickTextureName, 4, 16);
            GetTexture(); // make sure we're using the right texture

            _batch = new SpriteBatch(GraphicsDevice);

            base.LoadContent();
        }
        //public void LoadGraphics(){
        //    _defaultTexture.Load(SMOCGGame.Settings.AnimatedTexturePath + SMOCGGame.Settings.MousePointerTextureName, 4, 16);
        //    _mouseDownTexture.Load(SMOCGGame.Settings.AnimatedTexturePath + SMOCGGame.Settings.MouseClickTextureName, 4, 16);
        //}

        /// <summary>
        /// Update the mouse - get the new state and update any the current texture if it's animated
        /// </summary>
        /// <param name="deltaTime">the last time since update was called</param>
        public override void Update(GameTime gameTime)
        {
            TimeSpan deltaTime = gameTime.ElapsedGameTime;
            //public void Update(TimeSpan deltaTime) {
            _state = Mouse.GetState();
            _mousePos.X = _state.X; // hold the mouse's x pos
            _mousePos.Y = _state.Y; // hold the mouse's y pos

            //make sure the mouse is in the right state
            if (_state.LeftButton == ButtonState.Pressed)
                _currState = CurrMouseState.MouseDown;
            else
                _currState = CurrMouseState.Pointer;

            int currFrame = _currentTexture.Frame; // hold the current texture's frame
            GetTexture(); // get the right texture
            _currentTexture.Frame = currFrame; // make sure if the texture switched, that it plays smoothly

            _currentTexture.UpdateFrame(deltaTime); // update the animated texture

            base.Update(gameTime);
        }

        /// <summary>
        /// Check the current state of the mouse (Pointer, MouseDown, etc) and make sure we're using the right texture
        /// </summary>
        private void GetTexture() {
            //see which texture we should render - check to see if we're over anything, or the mouse is being clicked
            if (_currState == CurrMouseState.MouseDown)
            {
                _currentTexture = _mouseDownTexture;
            }
            else
                _currentTexture = _defaultTexture;
        }

        /// <summary>
        /// Draw the mouse
        /// </summary>
        //public void Render() {
        //    if (_batch != null) {
        //        _batch.Begin();
        //        _currentTexture.DrawFrame(_batch, _mousePos);
        //        _batch.End();
        //    }
        //}
        // Draw is pretty straightforward: we'll Begin the SpriteBatch, Draw the cursor,
        // and then End.
        public override void Draw(GameTime gameTime)
        {
            if (_batch != null)
            {
                _batch.Begin();
                _currentTexture.DrawFrame(_batch, _mousePos);
                _batch.End();
            }

            base.Draw(gameTime);
        }

        /// <summary>
        /// Dispose of the mouse's sprite batch
        /// </summary>
        //public void Dispose() {
        //    if (_batch != null) {
        //        _batch.Dispose();
        //        _batch = null;
        //    }
        //}
    }
}
