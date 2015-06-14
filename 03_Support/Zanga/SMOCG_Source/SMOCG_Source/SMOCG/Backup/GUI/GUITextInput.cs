#region Dependancies
using System;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Graphics;
#endregion

namespace SMOCG.GUI {
    class GUITextInput : GUIItem {
        private AnimatedTexture _cursor; // The cursor that will show where the mouse is
        private Vector2 _cursorPos; // the position of the cursor
        private int _cursorContentPos; // the position of the cursor in the content string
        private StringBuilder _contents; // the contents of the text input
        private int _maxLength = 16; // the maximum num of chars allowed in the input

        private InputHelper _input; // a reference to SMOCGGame's input helper object

        /// <summary>
        /// get the contents of the text input
        /// </summary>
        public string Contents {
            get { return _contents.ToString(); }
            set {
                _contents.Remove(0, _contents.Length); // clear the contents
                if(value.Length > this._maxLength) _contents.Insert(0, value.Substring(0, this._maxLength)); // if it's a large string, only accept the first 16 chars
                else _contents.Insert(0, value); // otherwise, just put the lot in
            }
        }

        /*----------------------------------------------------------------------------------------------------------------------------
         * PRIVATE FUNCTIONS
         * ---------------------------------------------------------------------------------------------------------------------------*/

        /// <summary>
        /// Poll the keyboard to see if any keys are currently being pressed. if they're typeable keys, then allow them to be entered
        /// </summary>
        private void PollKeyboard() {
            KeyboardState state = Keyboard.GetState(); // get the keyboard state
            Keys[] currentKeys = state.GetPressedKeys(); // get the currently pressed keys

            //if something is  being pressed
            if (currentKeys.Length > 0) {
                // if the key is ENTER, the call the callback function
                if (currentKeys[0] == Keys.Enter && _input.EnterPressed) {
                    if (this.OnEnterPressed != null) {
                        this.OnEnterPressed();
                        return;
                    }
                }
                //if the current key is BACKSPACE, and there's something in the _contents StringBuilder, then delete it one letter at a time
                if (currentKeys[0] == Keys.Back && _input.BackspacePressed && _contents.Length > 0)
                    RemoveFromContents(_cursorContentPos - 1, true);
                else if (currentKeys[0] == Keys.Delete && _input.DeletePressed && _contents.Length > 0 && _cursorContentPos < _contents.Length)
                    RemoveFromContents(_cursorContentPos, false);
                else if (currentKeys[0] == Keys.Right && _input.RightPressed)
                    MoveCursorRight();
                else if (currentKeys[0] == Keys.Left && _input.LeftPressed)
                    MoveCursorLeft();
                //we haven't reached our maximum amount of characters
                else if (_contents.Length < _maxLength) {
                    char keyToWrite; // what key we're going to write
                    //if the first key down is one of the shift keys, and the second is the '-' key, then add an underscore to the _contents
                    if (currentKeys.Length > 1 && (currentKeys[0] == Keys.LeftShift || currentKeys[0] == Keys.RightShift) &&
                        currentKeys[1] == Keys.OemMinus && _input.DashPressed)
                        AddToContents('_');
                    // if the first key down is the '-' key, then add a dash to the _contents
                    else if (currentKeys[0] == Keys.OemMinus && _input.DashPressed)
                        AddToContents('-');
                    // else if the first key down is the SPACE key, then add a space
                    else if (currentKeys[0] == Keys.Space && _input.SpacePressed)
                        AddToContents(' ');
                    // else, key the first key down with what we're allowed to type - if something shows up, then add it
                    else if (_input.TypingKeyPressed((char)currentKeys[0], out keyToWrite))
                        AddToContents(keyToWrite);
                }
                this._currEventType = GUI_event_type.GUI_EVENT_KEY_DOWN; // a key is currently being pressed
            }
        }

        /*----------------------------------------------------------------------------------------------------------------------------*/

        /// <summary>
        /// Move the cursor left only if it isn't at the start already
        /// </summary>
        private void MoveCursorLeft() {
            if (_cursorContentPos > 0) _cursorContentPos--;
        }

        /*----------------------------------------------------------------------------------------------------------------------------*/

        /// <summary>
        /// move the cursor right if it hasn't reached the end of _contents contents
        /// </summary>
        private void MoveCursorRight() {
            if (_cursorContentPos < _contents.Length) _cursorContentPos++;
        }

        /*----------------------------------------------------------------------------------------------------------------------------*/

        /// <summary>
        /// Add to the _contents StringBuilder
        /// </summary>
        /// <param name="c">The char to be added</param>
        private void AddToContents(char c) {
            _contents.Insert(_cursorContentPos, c);
            if (_cursorContentPos < _maxLength) _cursorContentPos++;
        }

        /*----------------------------------------------------------------------------------------------------------------------------*/

        /// <summary>
        /// Remove from the _contents StringBuilder
        /// </summary>
        /// <param name="where">Where to remove</param>
        /// <param name="moveCursor">Whether to move the cursor left or not (difference between BACKSPACE and DELETE)</param>
        private void RemoveFromContents(int where, bool moveCursor) {
            if (where > -1) {
                _contents.Remove(where, 1);
                if (moveCursor) MoveCursorLeft();
            }
        }

        /*----------------------------------------------------------------------------------------------------------------------
         * PUBLIC FUNCTIONS
         * ---------------------------------------------------------------------------------------------------------------------*/

        /// <summary>
        /// Constructor - create the widgit, and the animated cursor. also creates a string builder to hold the contents of the input box
        /// </summary>
        /// <param name="game">A reference to the main game object</param>
        /// <param name="name">The name of the widgit</param>
        /// <param name="position">the position of the top left hand corner of the widgit</param>
        /// <param name="widgitType">the type of widgit <see cref="GUI_widgit_type">GUI_widgit_type</see></param>
        /// <param name="width">the width of the widgit</param>
        /// <param name="height">the height of the widgit</param>
        /// <param name="textureName">the name of the texture to display</param>
        /// <param name="numStates">the number of states in the texture</param>
        /// <param name="maxChars">The maximum number of chars allowed in the text input</param>
        public GUITextInput(SMOCGGame game, string name, Vector2 position, GUI_widgit_type widgitType, int width, int height, string textureName, int numStates, int maxChars)
            : base(game, name, position, widgitType, width, height, textureName, numStates) 
        {
            this._input = game.InputHelper; // grab the main game object's input helper
            this._event = new GUIEvent(this, this.WidgitType, GUI_event_type.GUI_EVENT_NONE); // set up a basic GUIEvent

            this._cursorPos = new Vector2(position.X + 4, position.Y + 4 ); // set up the position of the cursor
            this._cursor = new AnimatedTexture(game, new Vector2(0), 0.0f, 1.0f, 1.0f); // set up the animated cursor
            this._cursor.Load(SMOCGGame.Settings.AnimatedTexturePath + SMOCGGame.Settings.GUITextCursorTexture, 2, 2); // load in the flashing cursor image

            this._maxLength = maxChars; // set the maximum amount of chars

            this._contents = new StringBuilder(_maxLength, _maxLength); // create a string builder for easy concat etc.
        }

        /*----------------------------------------------------------------------------------------------------------------------------*/

        /// <summary>
        /// Process the mouse input - only become active if the user clicks on the widgit, otherwise do nothing
        /// </summary>
        /// <param name="mState">the current mouse state</param>
        /// <param name="deltaTime">the last time since ProcessInput was called</param>
        /// <returns>a <see cref="GUIEvent">GUIEvent</see> that specifies the GUITextInput's current state</returns>
        public override GUIEvent ProcessInput(MouseState mState, TimeSpan deltaTime) {
            this._event = base.ProcessInput(mState, deltaTime); // get the base to process first

            if (this.Visible && this.Enabled) { // if we're visible and enabled
                // if we're currently focused on the text input widgit, poll the keyboard to get any text entry
                if (this.Focused) {
                    this.Game.InTextInput = true; // tell the game object that we're in a text input widgit
                    this._cursor.UpdateFrame(deltaTime); // update the cursor animation
                    PollKeyboard();
                } else
                    this.Game.InTextInput = false;

                // move the cursor to the end of the text if there is any
                this._cursorPos.X = this.Position.X + 4;
                if (_contents.Length > 0) this._cursorPos.X += Font.GetWidth(FontStyle.Small, _contents.ToString().Substring(0, _cursorContentPos));

            } else {
                this.Focused = false;
                this.Game.InTextInput = false;
            }

            return this._event;
        }

        /*----------------------------------------------------------------------------------------------------------------------------*/

        /// <summary>
        /// The widgit has been clicked, find out where and if we need to move the cursor pos
        /// </summary>
        public override void OnMouseUp() {
            this.Focused = true; // focus the control

            int localX = (int)this.ClickedPosition.X - ((int)Position.X + 4); // get the local x coord of where we clicked

            //get the width of the contents of the _contents stringBuilder
            int textWidth = 0;
            if (_contents.Length > 0) textWidth += Font.GetWidth(FontStyle.Small, _contents.ToString());

            // if the local x is greater than the width of the contents (i.e. we've clicked after the text
            //then set the cursor pos to be the after the last char
            if (localX > textWidth) _cursorContentPos = _contents.Length;
            else {
                float percent = (float)localX / (float)textWidth; // find out the percentage in the string length where we've clicked
                _cursorContentPos = (int)(_contents.Length * percent); // set the cursor there (e.g. in a 6 length string, (int)(string.Length * percent) = 3 - i.e. 3 char's in)
            }
            if (_cursorContentPos < 0) _cursorContentPos = 0;
            if (_cursorContentPos > _maxLength) _cursorContentPos = _maxLength;
        }

        /*----------------------------------------------------------------------------------------------------------------------------*/

        /// <summary>
        /// Empty the contents of the text input box
        /// </summary>
        public void Empty() {
            lock (this._contents)
                this._contents.Remove(0, this._contents.Length);
            this._cursorContentPos = 0;
        }

        /*----------------------------------------------------------------------------------------------------------------------------*/

        /// <summary>
        /// Draw the GUITextInput widgit, starting with the background, any contents, and the blinking cursor object
        /// </summary>
        public override void Render() {
            if (this.Visible) { // only draw if we're visible
                //create the batch if necessary
                if (_batch == null)
                    this.InitSpriteBatch();

                //the background
                _batch.Begin();
                {
                    //if we're focused, swap in the mouseover texture to let the user know
                    if (this.Focused)
                        _drawRect.X = this.Width();
                    else
                        _drawRect.X = 0;

                    //draw the part of the texture we want
                    if (this.Enabled)
                        _batch.Draw(this._texture, this.Position, this._drawRect, Color.White);
                    else
                        _batch.Draw(this._texture, this.Position, this._drawRect, _disabledColor);
                }
                _batch.End();

                //write the contents of the text input if there is any
                if (this._contents.Length != 0) {
                    Font.Begin();
                    Font.Draw(FontStyle.Small, (int)this.Position.X + 3, (int)this.Position.Y + 3, _contents.ToString(), Color.White);
                    Font.End();
                }

                //if we're focused, then draw the flashing cursor
                if(this.Focused){
                    _batch.Begin();
                    this._cursor.DrawFrame(_batch, this._cursorPos); // draw the flashing cursor if we're focused
                    _batch.End();
                }
            }
        }

        /*----------------------------------------------------------------------------------------------------------------------------*/
    }
}
