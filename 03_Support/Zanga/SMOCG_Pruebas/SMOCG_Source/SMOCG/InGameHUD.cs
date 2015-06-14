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
    /// The different buttons availabe in the hud
    /// </summary>
    public enum HUDButtons {
        Deal,
        Pickup,
        Reset,
        //Arrange,
        Ready,
        SelectSame
    }

    /// <summary>
    /// The InGameHUD displays all information, buttons, and the game log for the player
    /// to view and interact with
    /// </summary>
    public class InGameHUD : Scene {

        private CardGameScene _cardGame; // a reference to the card game scene
        private Deck _deck; // a reference to the deck of cards

        // the gui buttons and their positions
        private GUIButton _dealButton;
        private GUIButton _pickupButton;
        private GUIButton _resetButton;
        //private GUIButton _arrangeButton;
        private GUIButton _readyButton;
        private GUIButton _selectSameButton;
        private GUITextInput _chatBox; // the chat box

        private Vector2 _dealButtonPos = new Vector2(0.0f, 413.0f);//(0.0f, 369.0f);
        private Vector2 _pickupButtonPos = new Vector2(0.0f, 457.0f);//(0.0f, 413.0f);
        private Vector2 _resetButtonPos = new Vector2(0.0f, 501.0f);//(0.0f, 457.0f);
        //private Vector2 _arrangeButtonPos = new Vector2(0.0f, 501.0f);
        private Vector2 _readyButtonPos = new Vector2(0.0f, 543.0f);
        private Vector2 _selectSameButtonPos = new Vector2(0.0f, 589.0f);
        private Vector2 _chatBoxPos = new Vector2(24.0f, 149.0f);

        private Texture2D _baseHUD; // the texture for the base hud
        private Texture2D _baseHUDbg; // the base hud's bg
        private Texture2D _logHUD; // the log hud
        private Texture2D _playIndicator; // the player Indicator
        private Vector2 _baseHudPos = new Vector2(0.0f, 621.0f); // where the base hud is positioned
        private Vector2 _baseHudBgPos = new Vector2(0.0f, 638.0f); // where the base hud bg is positioned
        private Vector2 _logHudPos = new Vector2(0.0f); // where the log hud is positioned
        private Vector2 _playIndicatorPos = new Vector2(915.0f, 0.0f); // where to position the play indicator
        private Rectangle _playIndicatorDrawRect = new Rectangle(0, 0, 109, 104); // which part of the texture to draw

        private Vector2 _playerControlledPos = new Vector2(934.0f, 49.0f);
        private Vector2 _currPlayerPlayingPos = new Vector2(972.0f, 12.0f);

        private string _bottomMessage1 = ""; // the first bottom message in the lower hud
        private string _bottomMessage2 = ""; // the second bottom message in the lower hud

        private const int _MAX_MESSAGES = 8;
        private List<string> _logMessages = new List<string>(_MAX_MESSAGES); // the log messages
        private List<Color> _logColors = new List<Color>(_MAX_MESSAGES); // the color of the log messages

        private Card _focusedCard; // which card is currently focused
        private Card[] _selectedCards = new Card[4]; // which card is currently selected

        private Rectangle _focusDrawRect; // the focused card draw rectangle
        private Rectangle[] _selectedDrawRect = new Rectangle[4]; // the 4 selected cards draw rectangle
        private Rectangle[] _lastCardsDrawRect = new Rectangle[4]; // the last 4 cards to be placed on the pickup pile
        private Rectangle _drawSourceRect; // which part of the card texture to draw
        private Color _focusCardAlpha = new Color(new Vector4(1.0f, 1.0f, 1.0f, 0.8f)); // what alpha to draw the focus card with

        //variables for the focused / selected card drawing
        private int _cardDrawWidth = 50;
        private int _cardDrawHeight = 100;
        private int _cardDrawSpace = 20;


        #region GetSet Parameters

        /// <summary>
        /// Set the reference to the deck of cards
        /// </summary>
        public Deck Deck {
            set { this._deck = value; }
        }

        /// <summary>
        /// Set which card is displayed in the focused area
        /// </summary>
        public Card FocusedCard {
            set { this._focusedCard = value; }
        }

        /// <summary>
        /// Set the selected cards
        /// </summary>
        /// <param name="cards">A list of selected cards</param>
        public void SetSelectedCards(List<Card> cards) {
            for (int i = 0; i < this._selectedCards.Length; i++) {
                if (cards.Count > i)
                    this._selectedCards[i] = cards[i];
                else
                    this._selectedCards[i] = null;
            }
        }

        /// <summary>
        /// Set the draw source rect
        /// </summary>
        public Rectangle DrawSourceRect {
            set { this._drawSourceRect = value; }
        }

        /// <summary>
        /// Set the first bottom message
        /// </summary>
        public string BottomMessage {
            set { this._bottomMessage1 = value; }
        }

        /// <summary>
        /// Set the second bottom message
        /// </summary>
        public string BottomMessage2 {
            set { this._bottomMessage2 = value; }
        }

        #endregion

        /// <summary>
        /// Create the textures etc. necessary
        /// </summary>
        /// <param name="game">A reference to the main game object</param>
        /// <param name="cgame">A reference to the CardGameScene that created it</param>
        public InGameHUD(SMOCGGame game, CardGameScene cgame)
            : base(game) {

            this._cardGame = cgame; // hold the reference to the CardGameScene

            this._baseHUD = game.ContentManager.Load<Texture2D>(SMOCGGame.Settings.HUDTexturePath + SMOCGGame.Settings.HUDBase);
            this._baseHUDbg = game.ContentManager.Load<Texture2D>(SMOCGGame.Settings.HUDTexturePath + SMOCGGame.Settings.HUDBaseBg);
            this._logHUD = game.ContentManager.Load<Texture2D>(SMOCGGame.Settings.HUDTexturePath + SMOCGGame.Settings.HUDLog);
            this._playIndicator = game.ContentManager.Load<Texture2D>(SMOCGGame.Settings.HUDTexturePath + SMOCGGame.Settings.HUDPlayIndicator);

            // create the draw rectangle for the currently focused card
            int viewportHeight = SMOCGGame.Graphics.GraphicsDevice.Viewport.Height;
            int viewportWidth = SMOCGGame.Graphics.GraphicsDevice.Viewport.Width;

            this._focusDrawRect = new Rectangle(this._cardDrawSpace, viewportHeight - this._cardDrawHeight - this._cardDrawSpace, this._cardDrawWidth, this._cardDrawHeight);
            for (int i = 0; i < 4; i++) {// create the four selected cards draw rectangle
                this._selectedDrawRect[i] = new Rectangle((this._cardDrawWidth + this._cardDrawSpace * 2) + ((this._cardDrawWidth + 1) * i),
                                                            viewportHeight - this._cardDrawHeight - this._cardDrawSpace,
                                                            this._cardDrawWidth,
                                                            this._cardDrawHeight);
                this._lastCardsDrawRect[i] = new Rectangle(viewportWidth - 223 + ((this._cardDrawWidth + 1) * i),
                                                        viewportHeight - this._cardDrawHeight - this._cardDrawSpace,
                                                        this._cardDrawWidth,
                                                        this._cardDrawHeight);
            }

            // the buttons
            this._dealButton = new GUIButton(game, "DealButton", this._dealButtonPos, GUI_widgit_type.GUI_WIDGIT_RECT_BUTTON, 108, 48, SMOCGGame.Settings.GUITexturePath + SMOCGGame.Settings.GUIButtonDeal, 3);
            this._pickupButton = new GUIButton(game, "PickupButton", this._pickupButtonPos, GUI_widgit_type.GUI_WIDGIT_RECT_BUTTON, 125, 48, SMOCGGame.Settings.GUITexturePath + SMOCGGame.Settings.GUIButtonPickup, 3);
            this._resetButton = new GUIButton(game, "ResetButton", this._resetButtonPos, GUI_widgit_type.GUI_WIDGIT_RECT_BUTTON, 174, 48, SMOCGGame.Settings.GUITexturePath + SMOCGGame.Settings.GUIButtonResetGame, 3);
            //this._arrangeButton = new GUIButton(game, "ArrangeButton", this._arrangeButtonPos, GUI_widgit_type.GUI_WIDGIT_RECT_BUTTON, 208, 48, SMOCGGame.Settings.GUITexturePath + SMOCGGame.Settings.GUIButtonArrangeCards, 3);
            this._readyButton = new GUIButton(game, "ReadyButton", this._readyButtonPos, GUI_widgit_type.GUI_WIDGIT_RECT_BUTTON, 213, 48, SMOCGGame.Settings.GUITexturePath + SMOCGGame.Settings.GUIButtonReadyToBegin, 3);
            this._selectSameButton = new GUIButton(game, "SelectSameButton", this._selectSameButtonPos, GUI_widgit_type.GUI_WIDGIT_RECT_BUTTON, 249, 48, SMOCGGame.Settings.GUITexturePath + SMOCGGame.Settings.GUIButtonSelectSameCards, 3);

            this._chatBox = new GUITextInput(game, "ChatBox", this._chatBoxPos, GUI_widgit_type.GUI_WIDGIT_TEXT_INPUT, 366, 24, SMOCGGame.Settings.GUITexturePath + SMOCGGame.Settings.GUITextInputChatTexture, 2, 32);

            // disable them initially
            this._dealButton.Enabled = this._pickupButton.Enabled =
                this._resetButton.Enabled = /*this._arrangeButton.Enabled =*/
                this._readyButton.Enabled = this._selectSameButton.Enabled = false;

            // set what happens when the user clicks on them
            this._dealButton.MouseUp += new GUIItem.OnMouseUpHandler(this._cardGame.Deal);
            this._pickupButton.MouseUp += new GUIItem.OnMouseUpHandler(this._cardGame.Pickup);
            this._resetButton.MouseUp += new GUIItem.OnMouseUpHandler(this.ResetActions);
            this._readyButton.MouseUp += new GUIItem.OnMouseUpHandler(this._cardGame.PlayerIsReady);
            this._selectSameButton.MouseUp += new GUIItem.OnMouseUpHandler(this.SelectSameActions);

            this._chatBox.OnEnterPressed += new GUIItem.OnEnterPressedHandler(this.TextBoxEnterActions); // what happens then the user hits enter while in the text box
        }

        /// <summary>
        /// Add a message to the log
        /// </summary>
        /// <param name="playerNumber">The player logging the message</param>
        /// <param name="message">The message to add</param>
        /// <param name="messageColor">The color of the message</param>
        public void AddLogMessage(int playerNumber, string message, PlayerColorChoice messageColor) {
            lock (this._logMessages) {
                if (this._logMessages.Count >= _MAX_MESSAGES) {
                    this._logMessages.RemoveAt(0);
                    this._logColors.RemoveAt(0);
                }
                this._logMessages.Add("Player " + playerNumber + " " + message);
                this._logColors.Add(SMOCGGame.Settings.PlayerColors[(int)messageColor]); // add the color
            }
        }

        /// <summary>
        /// Add a message to the log
        /// </summary>
        /// <param name="message">The message to add</param>
        /// <param name="messageColor">The color of the message</param>
        public void AddLogMessage(string message, PlayerColorChoice messageColor) {
            lock (this._logMessages) {
                if (this._logMessages.Count >= _MAX_MESSAGES) {
                    this._logMessages.RemoveAt(0);
                    this._logColors.RemoveAt(0);
                }
                this._logMessages.Add(message);
                this._logColors.Add(SMOCGGame.Settings.PlayerColors[(int)messageColor]); // add the color
            }
        }

        /// <summary>
        /// Enable, or disable a button on the hud
        /// </summary>
        /// <param name="but">The button to disable</param>
        /// <param name="activate">Whether to activate it or not</param>
        public void ButtonActivation(HUDButtons but, bool activate){
            switch (but) {
                case HUDButtons.Deal:
                    this._dealButton.Enabled = activate;
                    break;
                case HUDButtons.Pickup:
                    this._pickupButton.Enabled = activate;
                    break;
                case HUDButtons.Reset:
                    this._resetButton.Enabled = activate;
                    break;
                //case HUDButtons.Arrange:
                //    this._arrangeButton.Enabled = activate;
                //    break;
                case HUDButtons.Ready:
                    this._readyButton.Enabled = activate;
                    break;
                case HUDButtons.SelectSame:
                    this._selectSameButton.Enabled = activate;
                    break;
                default:
                    break;
            }
        }

        /// <summary>
        /// Deal with the input from the buttons etc.
        /// </summary>
        /// <param name="totalTime">The total time since the program was started</param>
        /// <param name="deltaTime">The time since the last call to Update()</param>
        /// <returns>The next GameState, or GameState.None if staying as is</returns>
        public override GameState Update(TimeSpan totalTime, TimeSpan deltaTime) {

            // the deal cards button
            if (this._dealButton.Enabled)
                this._dealButton.ProcessInput(this.Game.Mouse.State, deltaTime);

            // the pickup cards button
            if (this._pickupButton.Enabled)
                this._pickupButton.ProcessInput(this.Game.Mouse.State, deltaTime);

            // the reset game button
            if (this._resetButton.Enabled) 
                this._resetButton.ProcessInput(this.Game.Mouse.State, deltaTime);

            //// the arrange cards button
            //if (this._arrangeButton.Enabled)
            //    this._arrangeButton.ProcessInput(this.Game.Mouse.State, deltaTime);

            // the ready to begin button
            if (this._readyButton.Enabled)
                this._readyButton.ProcessInput(this.Game.Mouse.State, deltaTime);

            // the select same cards button
            if (this._selectSameButton.Enabled)
                this._selectSameButton.ProcessInput(this.Game.Mouse.State, deltaTime);

            if (this._chatBox.Enabled)
                this._chatBox.ProcessInput(this.Game.Mouse.State, deltaTime);

            if (this._overlay != null)
                this._overlay.Update(totalTime, deltaTime);

            return base.Update(totalTime, deltaTime);
        }

        /// <summary>
        /// What to do when the select same card button has been pressed
        /// </summary>
        private void SelectSameActions() {
            this._cardGame.SelectSameWithMouse = true;
            this._cardGame.SelectSameCards();
        }

        /// <summary>
        /// What to do when the reset button has been pressed
        /// </summary>
        private void ResetActions() {
            this._cardGame.Reset(true);
        }

        /// <summary>
        /// What to do when the enter key is pressed in the text box
        /// </summary>
        private void TextBoxEnterActions() {
            Console.WriteLine("This text box is filled with the text - " + this._chatBox.Contents);
            lock (this._logMessages) {
                Player p = this._cardGame.GetPlayer(this._cardGame.PlayerControlled);
                Console.WriteLine("Player controlled is " + p.PlayerNumber + ", this cardGame.playercontrolled = " + this._cardGame.PlayerControlled);
                int num = 0;
                PlayerColorChoice color = PlayerColorChoice.White;
                if (p != null) {
                    Console.WriteLine("Player number " + p.PlayerNumber + " has a log number of " + p.LogNumber);
                    num = p.LogNumber;
                    color = p.SkinColor;
                }
                string log = "Player " + num + " - " + this._chatBox.Contents.ToString();
                this.AddLogMessage(log, color); // add the chat box content to the log
                if(p != null) p.NetConnection.SendChatMessage(log); // send the message over the network
            }
            this._chatBox.Empty(); // empty the chat box
        }

        /// <summary>
        /// Draw the hud
        /// </summary>
        public override void Render() {
            this.SpriteBatch.Begin();

            // draw the log hud
            this.SpriteBatch.Draw(this._logHUD, this._logHudPos, Color.White);

            // draw the base hud bg
            this.SpriteBatch.Draw(this._baseHUDbg, this._baseHudBgPos, Color.White); 

            // draw the play indicator
            if (this._cardGame.GameStarted)
                this._playIndicatorDrawRect.X = 109;
            else
                this._playIndicatorDrawRect.X = 0;
            this.SpriteBatch.Draw(this._playIndicator, this._playIndicatorPos, this._playIndicatorDrawRect, Color.White);

            // show the focused card if there is one
            if (this._focusedCard != null)
                this.SpriteBatch.Draw(this._focusedCard.Shape.Texture, this._focusDrawRect, this._drawSourceRect, this._focusCardAlpha);

            // if the player is currently selecting cards, then show them beside the focused card
            for (int i = 0; i < this._selectedCards.Length; i++)
                if (this._selectedCards[i] != null)
                    this.SpriteBatch.Draw(this._selectedCards[i].Shape.Texture, this._selectedDrawRect[i], this._drawSourceRect, Color.White);

            lock (this._deck.PickupPile) {
                // draw the last four cards in the deck
                if (this._deck != null) {
                    int numCards = this._deck.PickupPile.Count; // hold how many cards are in the pickup pile
                    if (numCards > 0) {
                        for (int i = 0; i < 4; i++) {
                            if (numCards > i) { // if the card is there
                                Color alpha = new Color((byte)255, (byte)255, (byte)255, (byte)(255 - (50 * i)));
                                Texture2D texture = this._deck.PickupPile[i].Shape.Texture; //get it's texture, and draw it
                                this.SpriteBatch.Draw(texture, this._lastCardsDrawRect[3 - i], this._drawSourceRect, alpha);
                            }
                        }
                    }
                }
            }

            // draw the base hud itself
            this.SpriteBatch.Draw(this._baseHUD, this._baseHudPos, Color.White);

            this.SpriteBatch.End();

            // draw the log messages
            Font.Begin();
            int n = 0;
            lock (this._logMessages) {
                foreach (string s in this._logMessages) {
                    Font.Draw(FontStyle.Smallest, 20, 13 + (15 * n), s, this._logColors[n]);
                    n++;
                }
            }

            //draw the two bottom messages
            Font.Draw(FontStyle.Smallest, 340, 711, this._bottomMessage1, Color.White);
            Font.Draw(FontStyle.Smallest, 340, 728, this._bottomMessage2, Color.White);

            if (this._cardGame.Players.Count > 0) {
                //draw the player controlled and current player player numbers
                Font.Draw(FontStyle.Small, (int)this._playerControlledPos.X, (int)this._playerControlledPos.Y, "" + (this._cardGame.PlayerControlled + 1), Color.White);
                Font.Draw(FontStyle.Large, (int)this._currPlayerPlayingPos.X, (int)this._currPlayerPlayingPos.Y, "" + (this._cardGame.CurrentPlayerPlaying + 1), Color.White);
            }
            Font.End();

            // draw the buttons
            this._dealButton.Render();
            this._pickupButton.Render();
            this._resetButton.Render();
            //this._arrangeButton.Render();
            this._readyButton.Render();
            this._selectSameButton.Render();

            this._chatBox.Render();

            if (this._overlay != null)
                this._overlay.Render();
        }
    }
}
