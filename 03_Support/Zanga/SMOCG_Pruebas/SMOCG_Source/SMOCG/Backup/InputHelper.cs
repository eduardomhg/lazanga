#region Dependancies
using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework;
using SMOCG.Settings;
#endregion

namespace SMOCG {
    /// <summary>
    /// InputHelper makes it easier to detect if a key has been pressed, as well
    /// as getting rid of problems for multiple calls to a function if the key remains
    /// pressed
    /// </summary>
    public class InputHelper {
        private KeyboardState _keyState; // the keyboard state
        private Game _game; // the game object
        private SMOCGSettings _settings; // the game's settings object

        //the different keys used in the game
        private Keys _actionKey;
        private Keys _fullScreenKey;
        private Keys _quitKey;
        private Keys _saveSettingsKey;
        private Keys _loadSettingsKey;

        private Keys _dealCardsKey;
        private Keys _selectSameCardsKey;
        private Keys _pickupKey;
        private Keys _arrangeCardsKey;
        private Keys _resetGameKey;
        private Keys _readyToBeginKey;

        private Keys _enterKey;
        private Keys _spaceKey;
        private Keys _backspaceKey;
        private Keys _deleteKey;
        private Keys _dashKey;
        private Keys _leftShiftKey;
        private Keys _rightShiftKey;
        private Keys _rightKey;
        private Keys _leftKey;

        //keys used for typing
        private char[] _typingKeys = new char[38];
        private bool[] _typingKeysBool = new bool[38];

        //was the key released
        private bool _actionWasReleased;
        private bool _fullScreenWasReleased;
        private bool _quitWasReleased;
        private bool _saveSettingWasReleased;
        private bool _loadSettingsWasReleased;

        private bool _dealCardsWasReleased;
        private bool _selectSameCardsWasReleased;
        private bool _pickupKeyWasReleased;
        private bool _arrangeCardsKeyWasReleased;
        private bool _resetGameKeyWasReleased;
        private bool _readyToBeginWasReleased;

        private bool _enterWasReleased;
        private bool _spaceWasReleased;
        private bool _backspaceWasReleased;
        private bool _deleteWasReleased;
        private bool _dashWasReleased;
        private bool _leftShiftWasReleased;
        private bool _rightShiftWasReleased;
        private bool _rightWasReleased;
        private bool _leftWasReleased;

        ///<summary>
        ///default constructor - assigns the different keys
        ///</summary>
        public InputHelper() {
            SetupKeys();
        }

        /// <summary>
        /// Setup the keys from the settings object. This is called whenever settings are changed or reloaded
        /// </summary>
        public void SetupKeys(){
            _settings = SMOCGGame.Settings;

            //assign the keys from the passed settings object
            _actionKey = _settings.ActionKey;
            _fullScreenKey = _settings.FullscreenKey;
            _quitKey = _settings.QuitKey;
            _saveSettingsKey = _settings.SaveSettingsKey;
            _loadSettingsKey = _settings.LoadSettingsKey;

            _dealCardsKey = _settings.DealCardsKey;
            _selectSameCardsKey = _settings.SelectSameCardsKey;
            _pickupKey = _settings.PickupKey;
            _arrangeCardsKey = _settings.ArrangeCardsKey;
            _resetGameKey = _settings.ResetGameKey;
            _readyToBeginKey = _settings.ReadyToBegin;

            _enterKey = Keys.Enter;
            _spaceKey = Keys.Space;
            _backspaceKey = Keys.Back;
            _deleteKey = Keys.Delete;
            _dashKey = Keys.OemMinus;
            _leftShiftKey = Keys.LeftShift;
            _rightShiftKey = Keys.RightShift;
            _rightKey = Keys.Right;
            _leftKey = Keys.Left;

            // the characters we're allowed to type
            string temp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_";
            //fill the two arrays - one with characters, the other with whether the specific keys is up or down
            for (int i = 0; i < _typingKeys.Length; i++) {
                _typingKeys[i] = (char)temp[i];
                _typingKeysBool[i] = false;
            }
        }

        #region Check key presses functions
        /// <summary>
        /// check to see if the action key has been pressed
        /// </summary>
        public bool ActionPressed {
            get {
                return CheckPressed(_keyState.IsKeyDown(_actionKey), ref _actionWasReleased);
            }
        }
        ///<summary>
        /// check to see if the fullscreen key has been pressed
        ///</summary>
        public bool FullscreenPressed {
            get {
                return CheckPressed(_keyState.IsKeyDown(_fullScreenKey), ref _fullScreenWasReleased);
            }
        }

        ///<summary>
        /// check to see if the quit key has been pressed
        ///</summary>
        public bool QuitPressed {
            get {
                return CheckPressed(_keyState.IsKeyDown(_quitKey), ref _quitWasReleased);
            }
        }

        ///<summary>
        /// check to see if the save settings button has been pressed
        ///</summary>
        public bool SaveSettingsPressed {
            get {
                return CheckPressed(_keyState.IsKeyDown(_saveSettingsKey), ref _saveSettingWasReleased);
            }
        }

        ///<summary>
        /// check to see if the load settings button has been pressed
        ///</summary>
        public bool LoadSettingsPressed {
            get {
                return CheckPressed(_keyState.IsKeyDown(_loadSettingsKey), ref _loadSettingsWasReleased);
            }
        }

        ///<summary>
        /// check to see if the select same cards button has been pressed
        ///</summary>
        public bool DealCardsPressed {
            get {
                return CheckPressed(_keyState.IsKeyDown(_dealCardsKey), ref _dealCardsWasReleased);
            }
        }

        ///<summary>
        /// check to see if the select same cards button has been pressed
        ///</summary>
        public bool SelectSameCardsPressed {
            get {
                return CheckPressed(_keyState.IsKeyDown(_selectSameCardsKey), ref _selectSameCardsWasReleased);
            }
        }

        ///<summary>
        /// check to see if the pickup cards button has been pressed
        ///</summary>
        public bool PickUpPressed {
            get {
                return CheckPressed(_keyState.IsKeyDown(_pickupKey), ref _pickupKeyWasReleased);
            }
        }

        ///<summary>
        /// check to see if the network listen button has been pressed
        ///</summary>
        public bool ArrangeKeysPressed {
            get {
                return CheckPressed(_keyState.IsKeyDown(_arrangeCardsKey), ref _arrangeCardsKeyWasReleased);
            }
        }

        ///<summary>
        /// check to see if the network listen button has been pressed
        ///</summary>
        public bool ResetGamePressed {
            get {
                return CheckPressed(_keyState.IsKeyDown(_resetGameKey), ref _resetGameKeyWasReleased);
            }
        }

        ///<summary>
        /// check to see if the network listen button has been pressed
        ///</summary>
        public bool ReadyToBeginPressed {
            get {
                return CheckPressed(_keyState.IsKeyDown(_readyToBeginKey), ref _readyToBeginWasReleased);
            }
        }

        ///<summary>
        /// check to see if the enter key has been pressed
        ///</summary>
        public bool EnterPressed {
            get {
                return CheckPressed(_keyState.IsKeyDown(_enterKey), ref _enterWasReleased);
            }
        }

        ///<summary>
        /// check to see if the space key has been pressed
        ///</summary>
        public bool SpacePressed {
            get {
                return CheckPressed(_keyState.IsKeyDown(_spaceKey), ref _spaceWasReleased);
            }
        }

        ///<summary>
        /// check to see if the backspace key has been pressed
        ///</summary>
        public bool BackspacePressed {
            get {
                return CheckPressed(_keyState.IsKeyDown(_backspaceKey), ref _backspaceWasReleased);
            }
        }

        ///<summary>
        /// check to see if the delete key has been pressed
        ///</summary>
        public bool DeletePressed {
            get {
                return CheckPressed(_keyState.IsKeyDown(_deleteKey), ref _deleteWasReleased);
            }
        }

        ///<summary>
        /// check to see if the dash key has been pressed
        ///</summary>
        public bool DashPressed {
            get {
                return CheckPressed(_keyState.IsKeyDown(_dashKey), ref _dashWasReleased);
            }
        }

        ///<summary>
        /// check to see if the left shift key has been pressed
        ///</summary>
        public bool LeftShiftPressed {
            get {
                return CheckPressed(_keyState.IsKeyDown(_leftShiftKey), ref _leftShiftWasReleased);
            }
        }

        ///<summary>
        /// check to see if the dash key has been pressed
        ///</summary>
        public bool RightShiftPressed {
            get {
                return CheckPressed(_keyState.IsKeyDown(_rightShiftKey), ref _rightShiftWasReleased);
            }
        }

        ///<summary>
        /// check to see if the right arrow key has been pressed
        ///</summary>
        public bool RightPressed {
            get {
                return CheckPressed(_keyState.IsKeyDown(_rightKey), ref _rightWasReleased);
            }
        }

        ///<summary>
        /// check to see if the left arrow key has been pressed
        ///</summary>
        public bool LeftPressed {
            get {
                return CheckPressed(_keyState.IsKeyDown(_leftKey), ref _leftWasReleased);
            }
        }
        #endregion

        /// <summary>
        /// Checks to see if a typing key has been pressed - usually called by a GUITextInput object
        /// </summary>
        /// <param name="key">The key to check</param>
        /// <param name="retKey">The returned key (otherwise testing for '1' would return 'D1'</param>
        /// <returns>whether the specific key has been pressed</returns>
        public bool TypingKeyPressed(char key, out char retKey) {
            int pos = -1;
            //search for the key in the array of allowed keys
            for (int i = 0; i < _typingKeys.Length; i++) {
                if (key == _typingKeys[i]) {
                    pos = i;
                    break;
                }
            }

            //we've found a match
            if (pos != -1) {
                //if the key pressed (and the previous state it;s been released - to stop multiple presses)
                if (CheckPressed(_keyState.IsKeyDown((Keys)_typingKeys[pos]), ref _typingKeysBool[pos])) {
                    retKey = _typingKeys[pos]; // set the returnKey
                    return true;
                }
            }

            retKey = '.'; // default return key - this doesn't matter, as it'll never get printed
            return false;
        }

        ///<summary>
        ///check to see if a key button has been pressed
        /// only works if the game is the active application
        ///</summary>
        ///<param name="pressed">is the key currently down</param>
        ///<param name="controlWasReleased">has is previously been released (stop repeated calls from holding the key down)</param>
        private bool CheckPressed(bool pressed, ref bool controlWasReleased){
            bool returnValue = controlWasReleased && pressed;

            if (_game.IsActive) {
                //if the key was pressed, then reset the "released" indicators
                if (returnValue)
                    controlWasReleased = false;
            } else return false; // game is not the active application

            return returnValue;
        }

        ///<summary>
        ///updates the states - should be called once per frame if it's to work properly
        ///</summary>
        ///<param name="game">hold a copy of the game object</param>
        ///<param name="keyState">hold a reference to the current keyboard state</param>
        public void Update(Game game, ref KeyboardState keyState) {
            this._keyState = keyState; // hold the keystate
            this._game = game; // hold a reference to the game object

            //check which buttons have been released, so we can detect presses
            if (_keyState.IsKeyUp(_actionKey)) _actionWasReleased = true;
            if (_keyState.IsKeyUp(_fullScreenKey)) _fullScreenWasReleased = true;
            if (_keyState.IsKeyUp(_quitKey)) _quitWasReleased = true;
            if (_keyState.IsKeyUp(_saveSettingsKey)) _saveSettingWasReleased = true;
            if (_keyState.IsKeyUp(_loadSettingsKey)) _loadSettingsWasReleased = true;

            if (_keyState.IsKeyUp(_dealCardsKey)) _dealCardsWasReleased = true;
            if (_keyState.IsKeyUp(_selectSameCardsKey)) _selectSameCardsWasReleased = true;
            if (_keyState.IsKeyUp(_pickupKey)) _pickupKeyWasReleased = true;
            if (_keyState.IsKeyUp(_arrangeCardsKey)) _arrangeCardsKeyWasReleased = true;
            if (_keyState.IsKeyUp(_resetGameKey)) _resetGameKeyWasReleased = true;
            if (_keyState.IsKeyUp(_readyToBeginKey)) _readyToBeginWasReleased = true;

            if (_keyState.IsKeyUp(_enterKey)) _enterWasReleased = true;
            if (_keyState.IsKeyUp(_spaceKey)) _spaceWasReleased = true;
            if (_keyState.IsKeyUp(_backspaceKey)) _backspaceWasReleased = true;
            if (_keyState.IsKeyUp(_deleteKey)) _deleteWasReleased = true;
            if (_keyState.IsKeyUp(_dashKey)) _dashWasReleased = true;
            if (_keyState.IsKeyUp(_leftShiftKey)) _leftShiftWasReleased = true;
            if (_keyState.IsKeyUp(_rightShiftKey)) _rightShiftWasReleased = true;
            if (_keyState.IsKeyUp(_rightKey)) _rightWasReleased = true;
            if (_keyState.IsKeyUp(_leftKey)) _leftWasReleased = true;

            for(int i=0; i<_typingKeys.Length; i++)
                if(_keyState.IsKeyUp((Keys)_typingKeys[i])) _typingKeysBool[i] = true;
        }
    }
}
