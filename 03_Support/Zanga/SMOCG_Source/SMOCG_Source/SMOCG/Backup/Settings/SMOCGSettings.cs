#region Dependancies
using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Graphics;
using System.IO;
using System.Xml.Serialization;
#endregion

namespace SMOCG.Settings {
    /// <summary>
    /// holds the settings for SMOCG, including game settings, keyboard settings
    /// and methods for loading and saving to and from an xml file
    /// </summary>
    public class SMOCGSettings {

        #region GameSettings

        /// <summary>
        /// the title of the game
        /// </summary>
        public string WindowTitle = "Super Multiplayer Online Card Game";

        /// <summary>
        /// The max number of player that can sit at one table
        /// </summary>
        public int MaxPlayers = 5;

        #endregion

        #region Load Paths

        /// <summary>
        /// where the player saves his data
        /// </summary>
        public string PlayerSave = "playerSave.xml";

        /// <summary>
        /// where to load the splashscreen textures from
        /// </summary>
        public string SplashScreenTexturePath = @"Textures\SplashScreens\";

        /// <summary>
        /// where to load the animated textures from
        /// </summary>
        public string AnimatedTexturePath = @"Textures\AnimatedTextures\";

        /// <summary>
        /// where to load the GUI textures from
        /// </summary>
        public string GUITexturePath = @"Textures\GUI\";

        /// <summary>
        /// Where to load the HUD textures from
        /// </summary>
        public string HUDTexturePath = @"Textures\HUD\";

        /// <summary>
        /// where to load the font textures from
        /// </summary>
        public string FontTexturePath = @"Textures\Fonts\";

        /// <summary>
        /// where to load the player textures from
        /// </summary>
        public string PlayerTexturePath = @"Textures\Player\";

        /// <summary>
        /// where to load the model textures from
        /// </summary>
        public string ModelTexturePath = @"Textures\Models\";

        /// <summary>
        /// Where to load the card textures from
        /// </summary>
        public string CardTexturePath = @"Textures\Cards\";

        /// <summary>
        /// the game's path to the model folder
        /// </summary>
        public string ModelLoadPath = @"Models\";

        #endregion

        #region TextureNames

        /// <summary>
        /// the game's opening splash screen texture
        /// </summary>
        public string GameSplashTextureName = "splashScreen";

        /// <summary>
        /// The game's main menu splash screen texture
        /// </summary>
        public string GameMainMenuTextureName = "mainMenuScreen";

        /// <summary>
        /// The in-game hud base texture
        /// </summary>
        public string HUDBase = "base_hud";

        /// <summary>
        /// The in-game hud's base bg
        /// </summary>
        public string HUDBaseBg = "base_hud_bg";

        /// <summary>
        /// The in-game hud log texture
        /// </summary>
        public string HUDLog = "log_hud";

        /// <summary>
        /// The play indicator bg
        /// </summary>
        public string HUDPlayIndicator = "playIndicator";

        /// <summary>
        /// The customise player hud bg
        /// </summary>
        public string HUDCustomisePlayerBg = "customiseBg";

        /// <summary>
        /// The background texture for the join game box
        /// </summary>
        public string ConnectBoxBg = "joinGameBg";

        /// <summary>
        /// the GUI text input's bg texture
        /// </summary>
        public string GUITextInputTexture = "textBoxBg";

        /// <summary>
        /// The GUI bg texture for the ip text input
        /// </summary>
        public string GUITextInputIPTexture = "ipTextBoxBg";

        /// <summary>
        /// The GUI bg texture for the chat box
        /// </summary>
        public string GUITextInputChatTexture = "chatTextBoxBg";

        /// <summary>
        /// the GUI text input's flashing cursor texture
        /// </summary>
        public string GUITextCursorTexture = "flashingTextCursor";

        /// <summary>
        /// The GUI button for starting a lan game
        /// </summary>
        public string GUIButtonStartLanGame = "startLanGame";

        /// <summary>
        /// The GUI button for joining a lan game
        /// </summary>
        public string GUIButtonJoinLanGame = "joinLanGame";

        /// <summary>
        /// The GUI button for connecting to an ip
        /// </summary>
        public string GUIButtonConnectGame = "connect_button";

        /// <summary>
        /// The GUI button for arranging the cards
        /// </summary>
        public string GUIButtonArrangeCards = "arrangeCards_button";

        /// <summary>
        /// The GUI button for dealing the cards
        /// </summary>
        public string GUIButtonDeal = "deal_button";

        /// <summary>
        /// The GUI button for picking the cards up
        /// </summary>
        public string GUIButtonPickup = "pickup_button";

        /// <summary>
        /// The GUI button for the ready to begin command
        /// </summary>
        public string GUIButtonReadyToBegin = "ready_button";

        /// <summary>
        /// The GUI button for resetting the game
        /// </summary>
        public string GUIButtonResetGame = "resetGame_button";

        /// <summary>
        /// The GUI button for selecting the same cards
        /// </summary>
        public string GUIButtonSelectSameCards = "selectSame_button";

        /// <summary>
        /// The GUI button for customising the player
        /// </summary>
        public string GUIButtonCustomisePlayer = "customisePlayer";

        /// <summary>
        /// The GUI button left arrow
        /// </summary>
        public string GUIButtonLeftArrow = "left_arrow_button";

        /// <summary>
        /// The GUI button right arrow
        /// </summary>
        public string GUIButtonRightArrow = "right_arrow_button";

        /// <summary>
        /// The GUI button save player
        /// </summary>
        public string GUIButtonSavePlayer = "save_button";

        /// <summary>
        /// The GUI button exit
        /// </summary>
        public string GUIButtonExit = "exit_button";

        #endregion

        #region MouseTextureNames

        /// <summary>
        /// the default texture for the mouse - equivilent to a pointer
        /// </summary>
        public string MousePointerTextureName = "mousePointer";

        /// <summary>
        /// the texture of the mouse when it's pressed
        /// </summary>
        public string MouseClickTextureName = "mousePointerRed";

        #endregion

        #region Fonts

        /// <summary>
        /// The game's font, large size
        /// </summary>
        public string FontLarge = "lettersLarge";

        /// <summary>
        /// the game's font, small size
        /// </summary>
        public string FontSmall = "lettersSmall";

        /// <summary>
        /// The game's font, smallest size
        /// </summary>
        public string FontSmallest = "lettersSmallest";

        #endregion

        #region PlayerShape Settings

        /// <summary>
        /// The different hair models used by the PlayerShape - see also in Enums.cs
        /// </summary>
        public string[] HairModels = new string[]{
            "",
            "hair_spikes"
        };

        /// <summary>
        /// The different face textures used by the PlayerShape - see also in Enums.cs
        /// </summary>
        public string[] FaceTextures = new string[]{
            "smileyFace"
        };

        /// <summary>
        /// The different colors that the player can choose to color his skin, hair etc - see also in Enum.cs
        /// </summary>
        public Color[] PlayerColors = new Color[]{
            Color.White,
            new Color(new Vector3(0.2f)), // black - but not so black that we can't see any detail under it
            Color.Red,
            Color.Purple,
            Color.Blue,
            Color.Green,
            Color.Yellow,
            Color.Orange,
            new Color(new Vector3(1.0f, 0.67f, 0.2f)), // caucassian color
            Color.Sienna
        };

        #endregion

        #region HUDMessages

        /// <summary>
        /// All of the messages that can appear in the HUD message part in the bottom of the screen
        /// </summary>
        public string[] HUDMessages = new string[]{
            "you are player 1",
            "you are player 2",
            "you are player 3",
            "you are player 4",
            "you are player 5",
            "select a card from your hand",
            "select a card from your face-up cards",
            "select a card from your face-down cards",
            "multiple cards of the same value can be selected",
            "click the pickup pile to play card",
            "it is player 1s go",
            "it is player 2s go",
            "it is player 3s go",
            "it is player 4s go",
            "it is player 5s go",
            "it is your go",
            "you can pickup even if you have a valid card",
            "you can swap your face-up and hand cards",
            "click ready to begin - b - to start the game",
            "click deal - d - to deal the cards",
            "click reset game - r - to play a new game",
            "click select same cards - c - to select similar cards",
            "select two cards to switch their position",
            "ready to begin - waiting on 1 other",
            "ready to begin - waiting on 2 others",
            "ready to begin - waiting on 3 others",
            "ready to begin - waiting on 4 others"
        };

        /// <summary>
        /// All of the messages that can appear in the log in the top left of the screen
        /// </summary>
        public string[] LogMessages = new string[]{
            "joined the game",
            "is ready to begin",
            "played the ",
            "played ",
            "just picked up",
            "cleared the pickup pile with a ten",
            "cleared the pickup pile with 4 ",
            "has gotten rid of all his cards",
            "has left the game",
            "is the loser - pwned"
        };

        #endregion

        // the keymap settings
        #region KeyboardSettings

        public Keys ActionKey = Keys.Enter;
        public Keys FullscreenKey = Keys.F;
        public Keys QuitKey = Keys.Escape;
        public Keys SaveSettingsKey = Keys.S;
        public Keys LoadSettingsKey = Keys.L;

        public Keys DealCardsKey = Keys.D;
        public Keys ReadyToBegin = Keys.B;
        public Keys SelectSameCardsKey = Keys.C;
        public Keys PickupKey = Keys.P;
        public Keys ArrangeCardsKey = Keys.A;
        public Keys ResetGameKey = Keys.R;

        #endregion

        // load and save the settings
        #region Save and Load

        //the saveSettingsData struct
        [Serializable]
        public struct SaveSettingsData {
            public string _wndTitle;
            public Keys _action;
            public Keys _fullScreen;
            public Keys _quit;
            public Keys _saveSettings;
            public Keys _loadSettings;
            public Keys _selectSameKeys;

            /// <summary>
            /// fill in the object's data so it can be written to xml
            /// </summary>
            /// <param name="settings">a reference to the setting object</param>
            public void FillData(SMOCGSettings settings) {
                //fill out this object's data with the settings passed in
                this._wndTitle = settings.WindowTitle;
                this._action = settings.ActionKey;
                this._fullScreen = settings.FullscreenKey;
                this._quit = settings.QuitKey;
                this._saveSettings = settings.SaveSettingsKey;
                this._loadSettings = settings.LoadSettingsKey;
                this._selectSameKeys = settings.SelectSameCardsKey;
            }

            /// <summary>
            /// use the data in this object to fill out the relevant parameters
            /// in the settings object
            /// </summary>
            /// <param name="settings">a reference to the settings object</param>
            public void UseData(SMOCGSettings settings) {
                //fill out the settings with the data in this object
                settings.WindowTitle = this._wndTitle;
                settings.ActionKey = this._action;
                settings.FullscreenKey = this._fullScreen;
                settings.QuitKey = this._quit;
                settings.SaveSettingsKey = this._saveSettings;
                settings.LoadSettingsKey = this._loadSettings;
                settings.SelectSameCardsKey = this._selectSameKeys;
            }

            /// <summary>
            /// write out the contents of the struct to the console - testing only
            /// </summary>
            public void Write() {
                Console.WriteLine("------------------------");
                Console.WriteLine("window title = " + this._wndTitle);
                Console.WriteLine("action key = " + this._action);
                Console.WriteLine("fullscreen = " + this._fullScreen);
                Console.WriteLine("quit = " + this._quit);
                Console.WriteLine("save settings = " + this._saveSettings);
                Console.WriteLine("load settings = " + this._loadSettings);
                Console.WriteLine("select same cards = " + this._selectSameKeys);
                Console.WriteLine("------------------------");
            }
        }

        /// <summary>
        /// saves the settings to a file
        /// </summary>
        /// <param name="filename">the filename to save to</param>
        public void Save(string filename) {
            // Create the data to save
            SaveSettingsData data = new SaveSettingsData();
            data.FillData(this); // fill the data

            //sometimes there's problems when rewriting the file and it doesn't write properly,
            //meaning the subsequent Load() doesn't work and you get an IO error
            //so just delete it if it's already there
            if (File.Exists(filename))
                File.Delete(filename); // delete the file if it exists

            //open a stream to the filename
            Stream stream = File.Open(filename, FileMode.OpenOrCreate, FileAccess.Write);

            //create an xml serializer and stream the data to the file
            XmlSerializer serializer = new XmlSerializer(typeof(SaveSettingsData));
            serializer.Serialize(stream, data);
            stream.Close();
        }

        ///<summary>
        ///loads settings from a file
        ///</summary>
        ///<param name="filename">the filename to load from</param>
        public void Load(string filename) {
            // Check to see if the save exists
            if (!File.Exists(filename))
                // Notify the user there is no save           
                return;

            //open the file, and stream it to the relevant type
            Stream stream = File.OpenRead(filename);
            XmlSerializer serializer = new XmlSerializer(typeof(SaveSettingsData));
            //try to read in the settings - if the settings are fubared, then deserialize
            //won't work and will throw an InvalidOperationException
            try {
                SaveSettingsData data = (SaveSettingsData)serializer.Deserialize(stream);
                //use the data
                data.UseData(this);
            } catch (InvalidOperationException) {
                //bury it, just use the default settings
                Console.WriteLine("Using default settings, as settings.xml is nobbled");
            }

            //close the stream
            stream.Close();
        }
        #endregion
    }
}
