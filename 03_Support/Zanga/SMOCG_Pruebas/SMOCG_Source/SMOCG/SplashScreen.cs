#region Dependancies
using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
#endregion

namespace SMOCG {
    /// <summary>
    /// Spashscreen will show up a full screen, and will close when the user hits Enter (or whatever the control is in Settings)
    /// or a timeout occurs
    /// </summary>
    public class SplashScreen : Scene {
        //the name of the texture we're gonna be showing
        private string _textureName;

        //the texture2d
        private Texture2D _texture;

        //will the screen timeout?
        private double _timeOut;

        //end time of the screen
        private double _endTime = -1.0;

        //where are we going next
        private GameState _nextState = GameState.None;

        //get the input helper from SMOCGGame
        private InputHelper _input;

        //a rectangle corresponding to the viewport
        private Rectangle _rect = new Rectangle(0, 0, 0, 0);

        /// <summary>
        /// Default constructor - sets the texture name, and calls the Constuctor of scene
        /// </summary>
        /// <param name="game">A reference to the main game object</param>
        /// <param name="textureName">the texture to load in</param>
        public SplashScreen(SMOCGGame game, string textureName) : base(game) {
            setTexture(textureName); 
            this._input = game.InputHelper;
        }

        /// <summary>
        /// Constructor with a texture to load, a timeout assigned, and the nextstate to transition to
        /// </summary>
        /// <param name="game">A reference to the main game object</param>
        /// <param name="textureName">the texture to load in</param>
        /// <param name="timeout">time in seconds to display</param>
        /// <param name="nextState">the next state to transition to</param>
        public SplashScreen(SMOCGGame game, string textureName, double secsTimeout, GameState nextState) : base(game) {
            setTexture(textureName);
            this._timeOut = secsTimeout;
            this._nextState = nextState;
            this._input = game.InputHelper;
        }

        /// <summary>
        /// sets the texture to load in
        /// </summary>
        /// <param name="textureName">the texture name to load in</param>
        private void setTexture(string textureName) {
            this._textureName = textureName;
            //load in the texture
            this._texture = this.Game.ContentManager.Load<Texture2D>(SMOCGGame.Settings.SplashScreenTexturePath + this._textureName);
        }

        /// <summary>
        /// Checks for ActionKey (Default is Enter) or a timeout, then moves to the next state if there is one
        /// </summary>
        /// <param name="deltaTime">the time since the last call to update</param>
        /// <returns>the next state to transition to</returns>
        public override GameState Update(TimeSpan totalTime, TimeSpan deltaTime) {
            if (this._endTime < 0)
                this._endTime = totalTime.TotalSeconds + this._timeOut;

            //if there's a next state to transition to, then wait for timeout or ActionKey
            if (this._nextState != GameState.None &&
                ((this._timeOut != 0 && totalTime.TotalSeconds > this._endTime) ||
                  this._input.ActionPressed)) {
                this._endTime = totalTime.TotalSeconds - 0.01;
                return this._nextState;
            } else
                return base.Update(totalTime, deltaTime);
        }

        /// <summary>
        /// renders the full screen texture
        /// </summary>
        public override void Render() {
            GraphicsDevice device = SMOCGGame.Graphics.GraphicsDevice; // get the graphics device

            this.SpriteBatch.Begin(SpriteBlendMode.None);

            device.RenderState.DepthBufferEnable = false; // turn off depth buffer writing

            //make sure the rectangle is the same size as the viewport
            if (device.Viewport.Width != this._rect.Width || device.Viewport.Height != this._rect.Height) {
                this._rect.Width = device.Viewport.Width;
                this._rect.Height = device.Viewport.Height;
            }

            //this.SpriteBatch.Draw(this._texture, Vector2.Zero, null, Color.White); // draw the splash screen
            this.SpriteBatch.Draw(this._texture, this._rect, Color.White); // draw the screen

            device.RenderState.DepthBufferEnable = true; // turn depth buffering back on

            this.SpriteBatch.End();

            base.Render();
        }
    }
}
