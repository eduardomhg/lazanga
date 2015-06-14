#region Dependancies
using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using SMOCG.GUI;
#endregion

namespace SMOCG {
    /// <summary>
    /// The MainMenuScreen inherits from SplashScreen and presents the user with a number
    /// of gui buttons to determine what to do
    /// </summary>
    public class MainMenuScreen : SplashScreen {

        private GUIButton _startLanGame; // start a lan game button
        private GUIButton _joinLanGame; // join a lan game button
        private GUIButton _customisePlayer; // customise the player
        private Vector2 _startLanGamePos = new Vector2(0, 220);
        private Vector2 _joinLanGamePos = new Vector2(0, 330);
        private Vector2 _customisePlayerPos = new Vector2(0, 439);

        private GameState _nextState = GameState.None;

        /// <summary>
        /// Create the splashscreen and set up the buttons
        /// </summary>
        /// <param name="game">A reference to the main game object</param>
        /// <param name="textureName">The texture to load in as a background</param>
        public MainMenuScreen(SMOCGGame game, string textureName)
            : base(game, textureName) 
        {
            // create the start lan game button
            this._startLanGame = new GUIButton(game, 
                                                "StartLanGame", 
                                                this._startLanGamePos, 
                                                GUI_widgit_type.GUI_WIDGIT_RECT_BUTTON,
                                                409, 
                                                89, 
                                                SMOCGGame.Settings.GUITexturePath + SMOCGGame.Settings.GUIButtonStartLanGame, 
                                                3);
            // create the join lan game button
            this._joinLanGame = new GUIButton(game,
                                                "JoinLanGame",
                                                this._joinLanGamePos,
                                                GUI_widgit_type.GUI_WIDGIT_RECT_BUTTON,
                                                380,
                                                91,
                                                SMOCGGame.Settings.GUITexturePath + SMOCGGame.Settings.GUIButtonJoinLanGame,
                                                3);
            // create the customise player button
            this._customisePlayer = new GUIButton(game,
                                                    "CustomisePlayer",
                                                    this._customisePlayerPos,
                                                    GUI_widgit_type.GUI_WIDGIT_RECT_BUTTON,
                                                    404,
                                                    89,
                                                    SMOCGGame.Settings.GUITexturePath + SMOCGGame.Settings.GUIButtonCustomisePlayer,
                                                    3);

            // what to do when the user presses one of the buttons
            this._startLanGame.MouseUp += new GUIItem.OnMouseUpHandler(OnStartGamePressed);
            this._joinLanGame.MouseUp += new GUIItem.OnMouseUpHandler(OnJoinGamePressed);
            this._customisePlayer.MouseUp += new GUIItem.OnMouseUpHandler(OnCustomisePlayerPressed);
        }

        /// <summary>
        /// Gets called when the start lan game is pressed
        /// </summary>
        private void OnStartGamePressed() {
            this.Game.StartLANGame = true;
            this._nextState = GameState.Play;
        }

        /// <summary>
        /// Gets called when the join lan game is pressed
        /// </summary>
        private void OnJoinGamePressed() {
            this._nextState = GameState.Play;
        }

        /// <summary>
        /// Gets called when the customise player is pressed
        /// </summary>
        private void OnCustomisePlayerPressed() {
            this._nextState = GameState.CustomisePlayer;
        }

        /// <summary>
        /// Update the buttons
        /// </summary>
        /// <param name="totalTime">The total time since the simulation started</param>
        /// <param name="deltaTime">The time since the last call to Update()</param>
        /// <returns>The next GameState to move to, or GameState.None if no change is necessary</returns>
        public override GameState Update(TimeSpan totalTime, TimeSpan deltaTime) {
            //update the buttons
            if (this._startLanGame.Enabled)
                this._startLanGame.ProcessInput(this.Game.Mouse.State, deltaTime);

            if (this._joinLanGame.Enabled)
                this._joinLanGame.ProcessInput(this.Game.Mouse.State, deltaTime);

            if (this._customisePlayer.Enabled)
                this._customisePlayer.ProcessInput(this.Game.Mouse.State, deltaTime);

            if (this._nextState != GameState.None)
                return this._nextState;
            else
                return base.Update(totalTime, deltaTime);
        }

        /// <summary>
        /// Render the buttons
        /// </summary>
        public override void Render() {
            base.Render();
            this._startLanGame.Render();
            this._joinLanGame.Render();
            this._customisePlayer.Render();
        }
    }
}
