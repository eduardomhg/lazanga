#region Dependancies
using System;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
#endregion

namespace SMOCG {
    /// <summary>
    /// the AnimatedTexture class allows the loading of a strip of images to be rendered one after the
    /// other, giving animation. how fast the animation runs can also be set
    /// </summary>
    class AnimatedTexture {
        private SMOCGGame _game; // a reference to the main game object

        private int _framecount; // how many frames are in the animation
        private Texture2D _texture; // the texture object itself
        private float _timePerFrame; // how much time is each frame shown for?
        private int _frame; // what frame we're currently on
        private float _totalElapsed; // total elapsed time - used to decide when to move to the next frame
        private bool _paused; // is the animation paused?

        public float _rotation, _scale, _depth; // rotation, scale, and depth
        public Vector2 _origin; // where the texture's origin is

        /// <summary>
        /// get and set what frame the animated texture is on
        /// </summary>
        public int Frame {
            get { return _frame; }
            set { _frame = value; }
        }

        /// <summary>
        /// Constructor - creates an animated texture at position origin
        /// </summary>
        /// <param name="game">A reference to the main game object</param>
        /// <param name="origin">the origin of the spirte. specify (0,0) for the upper left hand corner</param>
        /// <param name="rotation">the rotation of the animated texture</param>
        /// <param name="scale">the scale of the animated texture</param>
        /// <param name="depth">the depth of the animated texture</param>
        public AnimatedTexture(SMOCGGame game, Vector2 origin, float rotation, float scale, float depth) {
            this._game = game;
            this._origin = origin;
            this._rotation = rotation;
            this._scale = scale;
            this._depth = depth;
        }

        /// <summary>
        /// Loads the specified animated texture, and sets hows many frames are in the animation, as
        /// well as how fast the animation plays
        /// </summary>
        /// <param name="textureName">the name of the animated texture to load in</param>
        /// <param name="frameCount">how many frames are in the animation</param>
        /// <param name="framesPerSec">how fase to play the animation</param>
        public void Load(string textureName, int frameCount, int framesPerSec) {
            this._framecount = frameCount;
            _texture = this._game.ContentManager.Load<Texture2D>(textureName); // load the texture
            this._timePerFrame = 1.0f / framesPerSec; // figure out how much time per frame is needed
            this._frame = 0; // start at the beginning
            this._totalElapsed = 0; // total elapsed time
            this._paused = false; // play straight away
        }

        /// <summary>
        /// UpdateFrame takes into account the passed time since the last call, and decides if the
        /// next frame of the animation needs to be drawn
        /// </summary>
        /// <param name="deltaTime">the time since the last update</param>
        public void UpdateFrame(TimeSpan deltaTime) {
            if (this._paused) return; // don't update if we're paused

            this._totalElapsed += (float)deltaTime.TotalSeconds; // add on the passed time
            if (this._totalElapsed > this._timePerFrame) { // if we need to move onto the next frame of the animation
                this._frame++; // incretement
                //keep the frame between 0 and totalFrames-1
                this._frame = this._frame % this._framecount; //loop
                this._totalElapsed -= this._timePerFrame; // reset for next test
            }
        }

        /// <summary>
        /// Draws the animated texture at the specified screenPosition
        /// </summary>
        /// <param name="batch">a <see cref="SpriteBatch">SpriteBatch</see> object used to draw the animated texture</param>
        /// <param name="screenPos">where to draw the animated texture</param>
        public void DrawFrame(SpriteBatch batch, Vector2 screenPos) {
            DrawFrame(batch, this._frame, screenPos);
        }

        /// <summary>
        /// Draws a specified frame of the animated texture at the specified screen position
        /// </summary>
        /// <param name="batch">a <see cref="SpriteBatch">SpriteBatch</see> object used to draw the animated texture</param>
        /// <param name="fr">the frame to draw</param>
        /// <param name="screenPos">where to draw the animated texture</param>
        public void DrawFrame(SpriteBatch batch, int fr, Vector2 screenPos) {
            int frameWidth = _texture.Width / _framecount; // figure out how much of the width we need to draw
            Rectangle sourceRect = new Rectangle(frameWidth * fr, 0, frameWidth, this._texture.Height); // create a rectangle with the specified dimensions
                                                                                                        // so we draw the right frame

            // draw part of the full texture using sourceRect
            batch.Draw(this._texture, screenPos, sourceRect, Color.White, this._rotation, this._origin, this._scale, SpriteEffects.None, this._depth);
        }

        /// <summary>
        /// Is the animted texture paused
        /// </summary>
        public bool IsPaused {
            get { return this._paused; }
        }

        /// <summary>
        /// reset the animated texture back to the start
        /// </summary>
        public void Reset() {
            this._frame = 0;
            this._totalElapsed = 0.0f;
        }

        /// <summary>
        /// stop the animated texture and reset it
        /// </summary>
        public void Stop() {
            Pause();
            Reset();
        }

        /// <summary>
        /// play the animated texture
        /// </summary>
        public void Play() {
            this._paused = true;
        }

        /// <summary>
        /// pause the animated texture
        /// </summary>
        public void Pause() {
            this._paused = true;
        }
    }
}
