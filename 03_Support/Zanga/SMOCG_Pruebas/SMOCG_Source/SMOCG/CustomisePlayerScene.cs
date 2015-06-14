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
    /// The CustomisePlayerScene inherits from scene and allows the user to customise
    /// his player
    /// </summary>
    public class CustomisePlayerScene : Scene {
        private GameState _nextState = GameState.None; // the next game state

        private Player _player; // the player model

        private GUIBackground _panel; //the gui elements
        private GUIButton _hairLeft;
        private GUIButton _hairRight;
        private GUIButton _hairColourLeft;
        private GUIButton _hairColourRight;
        private GUIButton _skinColourLeft;
        private GUIButton _skinColourRight;
        private GUIButton _save;
        private GUIButton _exit;
        private GUITextInput _nameInput;

        private Vector2 _panelPos = new Vector2(146, 224);                  // the gui element positions
        private Vector2 _hairLeftPos = new Vector2(342.0f, 255.0f);
        private Vector2 _hairRightPos = new Vector2(424.0f, 255.0f);
        private Vector2 _hairColourLeftPos = new Vector2(342.0f, 295.0f);
        private Vector2 _hairColourRightPos = new Vector2(424.0f, 295.0f);
        private Vector2 _skinColourLeftPos = new Vector2(342.0f, 335.0f);
        private Vector2 _skinColourRightPos = new Vector2(424.0f, 335.0f);
        private Vector2 _savePos = new Vector2(244.0f, 439.0f);
        private Vector2 _exitPos = new Vector2(322.0f, 439.0f);
        private Vector2 _nameInputPos = new Vector2(267.0f, 385.0f);

        private Vector2 _hairTextPos = new Vector2(179.0f, 269.0f);         // the text positions
        private Vector2 _hairColourTextPos = new Vector2(179.0f, 309.0f);
        private Vector2 _skinColourTextPos = new Vector2(177.0f, 348.0f);
        private Vector2 _nameTextPos = new Vector2(179.0f, 389.0f);
        private Vector2 _hairNumPos = new Vector2(392.0f, 269.0f);
        private Vector2 _hairColourNumPos = new Vector2(392.0f, 309.0f);
        private Vector2 _skinColourNumPos = new Vector2(392.0f, 348.0f);
        private int _statusY = 418;

        private Vector3 _playerRotation = new Vector3(0.0f); // the player rotation

        private int _tempHairType = 0; // our temporary values
        private int _tempHairColour = 0;
        private int _tempSkinColour = 0;

        private bool _savedStatus = true;
        private string _savedTrue = "saved";
        private string _savedFalse = "not saved";

        public CustomisePlayerScene(SMOCGGame game)
            : base(game) 
        {
            // create the gui elements
            this._panel = new GUIBackground(game, "panelBg", this._panelPos, GUI_widgit_type.GUI_WIDGIT_BACKGROUND, 350, 293, SMOCGGame.Settings.HUDTexturePath + SMOCGGame.Settings.HUDCustomisePlayerBg, 1);
            this._hairLeft = new GUIButton(game, "hairLeft", this._hairLeftPos, GUI_widgit_type.GUI_WIDGIT_RECT_BUTTON, 43, 43, SMOCGGame.Settings.GUITexturePath + SMOCGGame.Settings.GUIButtonLeftArrow, 3);
            this._hairRight = new GUIButton(game, "hairRight", this._hairRightPos, GUI_widgit_type.GUI_WIDGIT_RECT_BUTTON, 43, 43, SMOCGGame.Settings.GUITexturePath + SMOCGGame.Settings.GUIButtonRightArrow, 3);
            this._hairColourLeft = new GUIButton(game, "hairColourLeft", this._hairColourLeftPos, GUI_widgit_type.GUI_WIDGIT_RECT_BUTTON, 43, 43, SMOCGGame.Settings.GUITexturePath + SMOCGGame.Settings.GUIButtonLeftArrow, 3);
            this._hairColourRight = new GUIButton(game, "hairColourRight", this._hairColourRightPos, GUI_widgit_type.GUI_WIDGIT_RECT_BUTTON, 43, 43, SMOCGGame.Settings.GUITexturePath + SMOCGGame.Settings.GUIButtonRightArrow, 3);
            this._skinColourLeft = new GUIButton(game, "skinColourLeft", this._skinColourLeftPos, GUI_widgit_type.GUI_WIDGIT_RECT_BUTTON, 43, 43, SMOCGGame.Settings.GUITexturePath + SMOCGGame.Settings.GUIButtonLeftArrow, 3);
            this._skinColourRight = new GUIButton(game, "skinColourRight", this._skinColourRightPos, GUI_widgit_type.GUI_WIDGIT_RECT_BUTTON, 43, 43, SMOCGGame.Settings.GUITexturePath + SMOCGGame.Settings.GUIButtonRightArrow, 3);
            this._save = new GUIButton(game, "save", this._savePos, GUI_widgit_type.GUI_WIDGIT_RECT_BUTTON, 76, 48, SMOCGGame.Settings.GUITexturePath + SMOCGGame.Settings.GUIButtonSavePlayer, 3);
            this._exit = new GUIButton(game, "exit", this._exitPos, GUI_widgit_type.GUI_WIDGIT_RECT_BUTTON, 76, 48, SMOCGGame.Settings.GUITexturePath + SMOCGGame.Settings.GUIButtonExit, 3);
            this._nameInput = new GUITextInput(game, "nameInput", this._nameInputPos, GUI_widgit_type.GUI_WIDGIT_TEXT_INPUT, 194, 24, SMOCGGame.Settings.GUITexturePath + SMOCGGame.Settings.GUITextInputTexture, 2, 16);

            // assign their actions
            this._hairLeft.MouseUp += new GUIItem.OnMouseUpHandler(OnHairLeft);
            this._hairRight.MouseUp += new GUIItem.OnMouseUpHandler(OnHairRight);
            this._hairColourLeft.MouseUp += new GUIItem.OnMouseUpHandler(OnHairColourLeft);
            this._hairColourRight.MouseUp += new GUIItem.OnMouseUpHandler(OnHairColourRight);
            this._skinColourLeft.MouseUp += new GUIItem.OnMouseUpHandler(OnSkinColourLeft);
            this._skinColourRight.MouseUp += new GUIItem.OnMouseUpHandler(OnSkinColourRight);
            this._save.MouseUp += new GUIItem.OnMouseUpHandler(OnSave);
            this._exit.MouseUp += new GUIItem.OnMouseUpHandler(OnExit);

            // the player model
            this._player = new Player(game, null);
            this._player.Position = new Vector3(150.0f, 60.0f, 0.0f);
            this._player.Rotation = Vector3.Zero;
            this._player.Scale = new Vector3(20.0f);
            this._player.SetupCamera();
            this._player.Load(SMOCGGame.Settings.PlayerSave); // load the last file
            //this.AddObject(this._player);

            // adjust the temp values
            this._tempHairType = (int)this._player.HairType;
            this._tempHairColour = (int)this._player.HairColor;
            this._tempSkinColour = (int)this._player.SkinColor;
            this._nameInput.Contents = this._player.Name;
        }

        /// <summary>
        /// What happens when the hair left button is pressed
        /// </summary>
        private void OnHairLeft() {
            this._tempHairType--;
            if(this._tempHairType <= -1) this._tempHairType = SMOCGGame.Settings.HairModels.Length - 1;
            this._player.HairType = (PlayerHairType)this._tempHairType;
            this._savedStatus = false;
        }

        /// <summary>
        /// What happens when the hair right button is pressed
        /// </summary>
        private void OnHairRight() {
            this._tempHairType++;
            this._tempHairType %= SMOCGGame.Settings.HairModels.Length;
            this._player.HairType = (PlayerHairType)this._tempHairType;
            this._savedStatus = false;
        }

        /// <summary>
        /// what happens when the hair colour left button is pressed
        /// </summary>
        private void OnHairColourLeft() {
            this._tempHairColour--;
            if(this._tempHairColour <= -1) this._tempHairColour = SMOCGGame.Settings.PlayerColors.Length - 1;
            this._player.HairColor = (PlayerColorChoice)this._tempHairColour;
            this._savedStatus = false;
        }

        /// <summary>
        /// what happens when the hair colour right button is pressed
        /// </summary>
        private void OnHairColourRight() {
            this._tempHairColour++;
            this._tempHairColour %= SMOCGGame.Settings.PlayerColors.Length;
            this._player.HairColor = (PlayerColorChoice)this._tempHairColour;
            this._savedStatus = false;
        }

        /// <summary>
        /// what happens when the skin colour left button is pressed
        /// </summary>
        private void OnSkinColourLeft() {
            this._tempSkinColour--;
            if(this._tempSkinColour <= -1) this._tempSkinColour = SMOCGGame.Settings.PlayerColors.Length - 1;
            this._player.SkinColor = (PlayerColorChoice)this._tempSkinColour;
            this._savedStatus = false;
        }

        /// <summary>
        /// What happens when the skin colour right button is pressed
        /// </summary>
        private void OnSkinColourRight() {
            this._tempSkinColour++;
            this._tempSkinColour %= SMOCGGame.Settings.PlayerColors.Length;
            this._player.SkinColor = (PlayerColorChoice)this._tempSkinColour;
            this._savedStatus = false;
        }

        /// <summary>
        /// What happens when the save button is pressed
        /// </summary>
        private void OnSave() {
            this._player.HairType = (PlayerHairType)this._tempHairType;
            this._player.HairColor = (PlayerColorChoice)this._tempHairColour;
            this._player.SkinColor = (PlayerColorChoice)this._tempSkinColour;
            this._player.Name = this._nameInput.Contents.ToString();
            this._player.Save(SMOCGGame.Settings.PlayerSave);
            this._savedStatus = true;
        }

        /// <summary>
        /// What happens when the exit button is pressed
        /// </summary>
        private void OnExit() {
            this._nextState = GameState.MainMenuScreen;
        }

        /// <summary>
        /// update al the gui's and player etc
        /// </summary>
        /// <param name="totalTime">The total time passed since the start of the program</param>
        /// <param name="deltaTime">The time since the last call to deltatime</param>
        /// <returns>The next GameState, or GameState.None is no change is required</returns>
        public override GameState Update(TimeSpan totalTime, TimeSpan deltaTime) {
            this._playerRotation.Y += (float)(MathHelper.PiOver4 * deltaTime.TotalSeconds);
            this._player.Rotation = this._playerRotation;

            if (this._panel.Enabled)
                this._panel.ProcessInput(this.Game.Mouse.State, deltaTime);

            if (this._hairLeft.Enabled)
                this._hairLeft.ProcessInput(this.Game.Mouse.State, deltaTime);

            if (this._hairRight.Enabled)
                this._hairRight.ProcessInput(this.Game.Mouse.State, deltaTime);

            if (this._hairColourLeft.Enabled)
                this._hairColourLeft.ProcessInput(this.Game.Mouse.State, deltaTime);

            if (this._hairColourRight.Enabled)
                this._hairColourRight.ProcessInput(this.Game.Mouse.State, deltaTime);

            if (this._skinColourLeft.Enabled)
                this._skinColourLeft.ProcessInput(this.Game.Mouse.State, deltaTime);

            if (this._skinColourRight.Enabled)
                this._skinColourRight.ProcessInput(this.Game.Mouse.State, deltaTime);

            if (this._save.Enabled)
                this._save.ProcessInput(this.Game.Mouse.State, deltaTime);

            if (this._exit.Enabled)
                this._exit.ProcessInput(this.Game.Mouse.State, deltaTime);

            if (this._nameInput.Enabled)
                this._nameInput.ProcessInput(this.Game.Mouse.State, deltaTime);

            this._player.Update(deltaTime);

            if (this._nextState != GameState.None)
                return this._nextState;
            else
                return base.Update(totalTime, deltaTime);
        }

        /// <summary>
        /// Render everything
        /// </summary>
        public override void Render() {
            this._panel.Render();
            this._hairLeft.Render();
            this._hairRight.Render();
            this._hairColourLeft.Render();
            this._hairColourRight.Render();
            this._skinColourLeft.Render();
            this._skinColourRight.Render();
            this._save.Render();
            this._exit.Render();
            this._nameInput.Render();

            int statusX = 321 - Font.GetWidth(FontStyle.Smallest, this._savedStatus ? this._savedTrue : this._savedFalse) / 2;

            Font.Begin();
            // draw the labels
            Font.Draw(FontStyle.Small, (int)this._hairTextPos.X, (int)this._hairTextPos.Y, "hair", Color.White);
            Font.Draw(FontStyle.Small, (int)this._hairColourTextPos.X, (int)this._hairColourTextPos.Y, "hair colour", Color.White);
            Font.Draw(FontStyle.Small, (int)this._skinColourTextPos.X, (int)this._skinColourTextPos.Y, "skin colour", Color.White);
            Font.Draw(FontStyle.Small, (int)this._nameTextPos.X, (int)this._nameTextPos.Y, "name", Color.White);

            // draw the values
            Font.Draw(FontStyle.Small, (int)this._hairNumPos.X, (int)this._hairNumPos.Y, "" + this._tempHairType, Color.White);
            Font.Draw(FontStyle.Small, (int)this._hairColourNumPos.X, (int)this._hairColourNumPos.Y, "" + this._tempHairColour, Color.White);
            Font.Draw(FontStyle.Small, (int)this._skinColourNumPos.X, (int)this._skinColourNumPos.Y, "" + this._tempSkinColour, Color.White);

            Font.Draw(FontStyle.Smallest, statusX, this._statusY, this._savedStatus ? this._savedTrue : this._savedFalse, this._savedStatus ? Color.Green : Color.Red);

            Font.End();

            this._player.Render();

            base.Render();
        }

        /// <summary>
        /// Shut it down
        /// </summary>
        public override void Shutdown() {
            Player.StatPlayerNumber--;
            base.Shutdown();
        }
    }
}
