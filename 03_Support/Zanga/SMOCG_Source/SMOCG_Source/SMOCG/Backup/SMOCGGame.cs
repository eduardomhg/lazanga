#region Using Statements
using System;
using System.Collections.Generic;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Audio;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Storage;
using SMOCG.Cameras;
using SMOCG.Settings;
using SMOCG.GUI;
#endregion

namespace SMOCG {
    public class SMOCGGame : Microsoft.Xna.Framework.Game {
        //the preferred size of the game window
        private int _preferredWindowWidth = 1024;
        private int _preferredWindowHeight = 768;
        //private int _preferredWindowWidth = 640;
        //private int _preferredWindowHeight = 480;

        // static variables
        private static GraphicsDeviceManager _graphics; //the graphics device manager
        private static SMOCGSettings _settings = new SMOCGSettings(); //the game settings from settings.xml
        //private ContentManager _contentManager; //the content manager will load all the various content etc
        private GameState _gameState = GameState.Started; //the current gamestate
        private BasicCamera _camera; //a basic camera to look through
        private InputHelper _input; //the input helper object - used to simplify keyboard interactions etc
        private KeyboardState _keyState; //the keyboard state
        private bool _inTextInput; // are we currently typing in a text input widgit - suppress keyboard commands if so

        private Scene _currentScene = null; // what's currently showing
        private SMOCGMouse _mouse; //a graphic representation of the mouse

        //the name of the settings xml file
        private string _settingsFileName = "settings.xml";

        //private GUITextInput _nameInput;
        //private GUIButton _skinColorButton;
        //private GUIButton _hairTypeButton;
        //private GUIButton _hairColorButton;
        //private GUIButton _faceTextureButton;
        //private GUIButton _savePlayerButton;
        private bool _startGame = false; // which button did the user press on the main menu

        #region GetSetProperties

        /// <summary>
        /// get the graphics device
        /// </summary>
        public static GraphicsDeviceManager Graphics {
            get { return _graphics; }
        }

        /// <summary>
        /// get the game settings
        /// </summary>
        public static SMOCGSettings Settings {
            get { return _settings; }
        }

        /// <summary>
        /// get the content manager
        /// </summary>
        public ContentManager ContentManager {
            get { return Content; }// _contentManager; }
        }

        /// <summary>
        /// get the gamestate
        /// </summary>
        public GameState GameState {
            get { return _gameState;  }
        }

        /// <summary>
        /// get the basic camera
        /// </summary>
        public BasicCamera Camera {
            get {  return _camera; }
        }

        /// <summary>
        /// get the input helper
        /// </summary>
        public InputHelper InputHelper {
            get { return _input; }
        }

        /// <summary>
        /// get the keyboard state
        /// </summary>
        public KeyboardState KeyState {
            get { return _keyState; }
        }

        /// <summary>
        /// Get the game mouse
        /// </summary>
        public SMOCGMouse Mouse {
            get { return this._mouse; }
        }

        /// <summary>
        /// get and set whether we're currently typing in a text input widgit - if so suppress keyboard commands
        /// </summary>
        public bool InTextInput {
            get { return _inTextInput; }
            set { _inTextInput = value; }
        }

        /// <summary>
        /// Get the controlling camera - i.e. the camera of the user's player
        /// </summary>
        public BasicCamera ControllingCamera {
            get {
                if (this._currentScene != null)
                    return this._currentScene.ControllingCamera;
                else
                    return _camera;
            }
        }

        /// <summary>
        /// Did the user press start lan game?
        /// </summary>
        public bool StartLANGame {
            get { return this._startGame; }
            set { this._startGame = value; }
        }

        #endregion

        public SMOCGGame() {
            _graphics = new GraphicsDeviceManager(this);
            _graphics.PreferredBackBufferHeight = _preferredWindowHeight;
            _graphics.PreferredBackBufferWidth = _preferredWindowWidth;

            Content.RootDirectory = "Content";

            this._mouse = new SMOCGMouse(this);
            Components.Add(this._mouse);
        }

        protected override void Initialize() {
            //Uncomment this line to force a save of the default settings file - if after changing SMOCGSettings.cs for example
            //NOTE in VS this will go in DEBUG or RELEASE - need to copy up to main project
            //_settings.Save(_settingsFileName);
            _settings.Load(_settingsFileName);

            //setup the input helper
            this._input = new InputHelper();

            //set the window title
            Window.Title = _settings.WindowTitle;

            //create the mouse
            //this._mouse = new SMOCGMouse(this);

            //some settings for our basic camera
            float fov = (float)MathHelper.PiOver4;
            float aspect = (float)_preferredWindowWidth / (float)_preferredWindowHeight;
            float near = 1.0f;
            float far = 1000.0f;

            //create the basic camera
            this._camera = new BasicCamera(new Vector3(0.0f, 100.0f, 500.0f), fov, aspect, near, far);

            base.Initialize();
        }

        protected override void BeginRun() {
            //start it off
            ChangeState(GameState.SplashScreen); // load in the splash screen

            base.BeginRun();
        }

        //protected override void LoadGraphicsContent(bool loadAllContent) {
        protected override void LoadContent() {
            //this function is entered every time the screen resolution changes, so be careful of initializing stuff
           // if (loadAllContent) {
                //this._contentManager = new ContentManager(Services);
                Font.Init(this); // initialize the font object

                //this._mouse.LoadGraphics(); // load the graphics that the mouse uses

                //this._nameInput = new GUITextInput("nameInput", new Vector2(20, 50), GUI_widgit_type.GUI_WIDGIT_TEXT_INPUT, 194, 24, _settings.GUITexturePath + _settings.GUITextInputTexture, 2);
                //this._skinColorButton = new GUIButton("skinColorButton", new Vector2(200, 100), GUI_widgit_type.GUI_WIDGIT_RECT_BUTTON, 20, 20, _settings.GUITexturePath + _settings.GUIButtonTexture, 3);
                //this._hairTypeButton = new GUIButton("hairTypeButton", new Vector2(200, 130), GUI_widgit_type.GUI_WIDGIT_RECT_BUTTON, 20, 20, _settings.GUITexturePath + _settings.GUIButtonTexture, 3);
                //this._hairColorButton = new GUIButton("hairColorButton", new Vector2(200, 160), GUI_widgit_type.GUI_WIDGIT_RECT_BUTTON, 20, 20, _settings.GUITexturePath + _settings.GUIButtonTexture, 3);
                //this._faceTextureButton = new GUIButton("faceTextureButton", new Vector2(200, 190), GUI_widgit_type.GUI_WIDGIT_RECT_BUTTON, 20, 20, _settings.GUITexturePath + _settings.GUIButtonTexture, 3);
                //this._savePlayerButton = new GUIButton("savePlayerButton", new Vector2(200, 220), GUI_widgit_type.GUI_WIDGIT_RECT_BUTTON, 20, 20, _settings.GUITexturePath + _settings.GUIButtonTexture, 3);

                //this._nameInput.Contents = this._player.Name;
          //  }
        }

        //protected override void UnloadGraphicsContent(bool unloadAllContent) {
        protected override void UnloadContent()
        {
            //if (unloadAllContent) {
                //_contentManager.Unload();
                //_contentManager = null;

                Font.Dispose(); // clean up the font object
           // }
        }

        //int skin;
        //int hairType;
        //int hairColor;
        //int faceTexture;

        protected override void Update(GameTime gameTime) {
            //the time since the last update
            TimeSpan deltaTime = gameTime.ElapsedGameTime;
            TimeSpan totalTime = gameTime.TotalGameTime;

            _keyState = Keyboard.GetState(); // get the current keyboard state
            _input.Update(this, ref _keyState); // update the input helper
            //_mouse.Update(gameTime); // update the mouse

            #region GUI Player changes

            //skin = this._player.SkinColor;
            //hairType = this._player.HairType;
            //hairColor = this._player.HairColor;
            //faceTexture = this._player.FaceTexture;

            //this._nameInput.ProcessInput(_mouse.State, deltaTime);

            //GUIItem.GUIEvent butEvent = this._skinColorButton.ProcessInput(_mouse.State, deltaTime);
            //if (butEvent._eventType == GUI_event_type.GUI_EVENT_MOUSE_UP) {
            //    skin++;
            //    skin %= _settings.PlayerColors.Length;
            //    _player.SkinColor = skin;
            //}
            //butEvent = this._hairTypeButton.ProcessInput(_mouse.State, deltaTime);
            //if (butEvent._eventType == GUI_event_type.GUI_EVENT_MOUSE_UP) {
            //    hairType++;
            //    hairType %= _settings.HairModels.Length;
            //    _player.HairType = hairType;
            //}
            //butEvent = this._hairColorButton.ProcessInput(_mouse.State, deltaTime);
            //if (butEvent._eventType == GUI_event_type.GUI_EVENT_MOUSE_UP) {
            //    hairColor++;
            //    hairColor %= _settings.PlayerColors.Length;
            //    _player.HairColor = hairColor;
            //}
            //butEvent = this._faceTextureButton.ProcessInput(_mouse.State, deltaTime);
            //if (butEvent._eventType == GUI_event_type.GUI_EVENT_MOUSE_UP) {
            //    faceTexture++;
            //    faceTexture %= _settings.FaceTextures.Length;
            //    _player.FaceTexture = faceTexture;
            //}
            //butEvent = this._savePlayerButton.ProcessInput(_mouse.State, deltaTime);
            //if (butEvent._eventType == GUI_event_type.GUI_EVENT_MOUSE_UP) {
            //    _player.Name = this._nameInput.Contents;
            //    _player.Save("playerSave.xml");
            //    Console.WriteLine("Player saved!");
            //}

            #endregion

            GameState next = GameState.None; // where we're going next

            // Allows the game to exit
            if (_input.QuitPressed)
                this.Exit();

            //if we aren't typing in a text input widgit, allow keyboard commands
            //if (!this._inTextInput) {

            //    //toggle fullscreen if we haven't done so already
            //    //if (_input.FullscreenPressed)
            //    //{
            //    //    ToggleFullScreen();
            //    //}

            //    //save the settings.xml file if asked
            //    //if (_input.SaveSettingsPressed)
            //    //    _settings.Save(_settingsFileName);

            //    ////load the settings file if asked
            //    //if (_input.LoadSettingsPressed) {
            //    //    _settings.Load(_settingsFileName);
            //    //    _input.SetupKeys(); // make sure the right keys are set in the input helper
            //    //}
            //}

            //update the screen
            if(_currentScene != null)
                next = _currentScene.Update(totalTime, deltaTime);

            if (next != GameState.None)
                ChangeState(next);

            base.Update(gameTime);
        }

        /// <summary>
        /// change state - switch between screens, i.e. from splash screen to options etc.
        /// </summary>
        /// <param name="nextState">the state to change to</param>
        private void ChangeState(GameState nextState) {
            if (nextState == GameState.SplashScreen) 
            {
                if (this._currentScene != null) // if there's something there, shut it down
                    this._currentScene.Shutdown();

                this._currentScene = new SplashScreen(this, _settings.GameSplashTextureName, 0.0, GameState.MainMenuScreen); // create a new splash screen
                this._gameState = GameState.SplashScreen; // assign the game state
            }
            else if (nextState == GameState.MainMenuScreen) 
            {
                if (this._currentScene != null)
                    this._currentScene.Shutdown();

                this._currentScene = new MainMenuScreen(this, _settings.GameMainMenuTextureName); // create a new main menu
                this._gameState = GameState.MainMenuScreen; // assign the game state
            } 
            else if (nextState == GameState.CustomisePlayer) 
            {
                if (this._currentScene != null)
                    this._currentScene.Shutdown();

                this._currentScene = new CustomisePlayerScene(this); // create a new customise player
                this._gameState = GameState.CustomisePlayer;
            }
            else if (nextState == GameState.Play) {
                if (this._currentScene != null) // if there's something there, shut it down
                    this._currentScene.Shutdown();

                this._currentScene = new CardGameScene(this, 0, 0, this._startGame); // create a new card game
                this._currentScene.Init(); // init the card game
                this._gameState = GameState.Play; // assign the game state
            } else {
                //shouldn't get here
                Console.Error.WriteLine("Error! Unrecognized next state - " + nextState);
            }
        }

        /// <summary>
        /// toggles fullscreen mode
        /// </summary>
        private void ToggleFullScreen() {
            PresentationParameters presentation = _graphics.GraphicsDevice.PresentationParameters;
            if (presentation.IsFullScreen) {
                //going windowed
                _graphics.PreferredBackBufferHeight = _preferredWindowHeight;
                _graphics.PreferredBackBufferWidth = _preferredWindowWidth;

                _camera.AspectRatio = (float)_preferredWindowWidth / (float)_preferredWindowHeight;
            } else {
                //going fullscreen, use desktop resolution to minimize display mode changes
                //this also has the nice effect of working around some displays that lie about 
                //supporting 1280x720
                GraphicsAdapter adapter = _graphics.GraphicsDevice.CreationParameters.Adapter;
                _graphics.PreferredBackBufferWidth = adapter.CurrentDisplayMode.Width;
                _graphics.PreferredBackBufferHeight = adapter.CurrentDisplayMode.Height;

                _camera.AspectRatio = (float)_graphics.PreferredBackBufferWidth / _graphics.PreferredBackBufferHeight;
            }
            _graphics.ToggleFullScreen();
        }

        protected override void Draw(GameTime gameTime) {
            _graphics.GraphicsDevice.Clear(Color.CornflowerBlue);

            _graphics.GraphicsDevice.RenderState.DepthBufferEnable = true;

            //render the current scene
            if(_currentScene != null)
                _currentScene.Render();

            base.Draw(gameTime);

            #region GUI and Font draw commands

            //_nameInput.Render();

            //_skinColorButton.Render();
            //_hairColorButton.Render();
            //_hairTypeButton.Render();
            //_faceTextureButton.Render();
            //_savePlayerButton.Render();

            //Font.Begin();
            //Font.Draw(FontStyle.Small, 20, 30, "player name", Color.White);
            //Font.Draw(FontStyle.Small, 20, 100, "skin color", Color.White);
            //Font.Draw(FontStyle.Small, 20, 130, "hair type", Color.White);
            //Font.Draw(FontStyle.Small, 20, 160, "hair color", Color.White);
            //Font.Draw(FontStyle.Small, 20, 190, "face texture", Color.White);
            //Font.Draw(FontStyle.Small, 20, 220, "save player", Color.White);
            //Font.End();

            #endregion

            // draw the mouse last
            //_mouse.Render();
        }
    }
}
