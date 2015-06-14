#region Dependancies
using System;
using System.Collections.Generic;
using System.Text;
using System.Net;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using SMOCG.GUI;
#endregion

namespace SMOCG {
    /// <summary>
    /// An enum to help deal with the connection status
    /// </summary>
    public enum ConnectionStatus {
        Idle,
        Connecting,
        Error_bad_ip,
        Error_no_response
    };
    /// <summary>
    /// The JoinGamePopup class controls the popup that the player gets when he joins a game.
    /// it lets him enter an ip
    /// </summary>
    public class JoinGamePopup : Scene {
        private CardGameScene _cGame; // a reference of the CardGameScene
        private GUIBackground _bg; // the background for the popup

        // the four ip entry boxes
        private GUITextInput[] _ips = new GUITextInput[4];

        private GUIButton _connect; // the connect button
        private string _status = "status"; // the status header
        private string[] _statusResponses = new string[4]{
            "idle",
            "connecting",
            "enter a proper ip address",
            "error - no response"
        };

        private Vector2 _bgPos = new Vector2(327.0f, 302.0f);
        private Vector2[] _ipsPos = new Vector2[4]{
                                                    new Vector2(405.0f, 352.0f),
                                                    new Vector2(461.0f, 352.0f),
                                                    new Vector2(517.0f, 352.0f),
                                                    new Vector2(573.0f, 352.0f)
        };
        private Vector2 _connectPos = new Vector2(459.0f, 382.0f); // the position for the connect button
        // center the status phrase
        private Vector2 _statusPos = new Vector2(512.0f - (Font.GetWidth(FontStyle.Small, "status") / 2.0f), 435.0f);
        private int[] _statusResponseX = new int[4];

        // we start off idle
        private ConnectionStatus _currStatus = ConnectionStatus.Idle;

        /// <summary>
        /// Create the popup and various GUI elements
        /// </summary>
        /// <param name="cGame">A reference to the card game scene object</param>
        /// <param name="game">A reference to the main game object</param>
        public JoinGamePopup(CardGameScene cGame, SMOCGGame game)
            : base(game) 
        {
            this._cGame = cGame; // keep a reference to the card game scene

            // fill out the status response x positions
            for(int i = 0; i<4; i++)
                this._statusResponseX[i] = 512 - (Font.GetWidth(FontStyle.Small, this._statusResponses[i]) / 2);


            string iptex = SMOCGGame.Settings.GUITexturePath + SMOCGGame.Settings.GUITextInputIPTexture; // hold the texture path
            this._bg = new GUIBackground(game, "bg", this._bgPos, GUI_widgit_type.GUI_WIDGIT_BACKGROUND, 371, 197, SMOCGGame.Settings.GUITexturePath + SMOCGGame.Settings.ConnectBoxBg, 1);
            for(int i=0; i<4; i++)
                this._ips[i] = new GUITextInput(game, "ip" + i, this._ipsPos[i], GUI_widgit_type.GUI_WIDGIT_TEXT_INPUT, 46, 24, iptex, 2, 3);
            this._connect = new GUIButton(game, "connect", this._connectPos, GUI_widgit_type.GUI_WIDGIT_RECT_BUTTON, 105, 42, SMOCGGame.Settings.GUITexturePath + SMOCGGame.Settings.GUIButtonConnectGame, 3);

            this._connect.MouseUp += new GUIItem.OnMouseUpHandler(OnConnectPressed);
        }

        /// <summary>
        /// Called when OnConnectIs pressed
        /// </summary>
        private void OnConnectPressed() {
            string ip = "";
            for (int i = 0; i < 4; i++) {
                if (this._ips[i].Contents == "")
                    ip += "0";
                else
                    ip += this._ips[i].Contents;

                // add the dots
                if (i < 3)
                    ip += ".";
            }
            bool validAddress = true;
            try {
                IPAddress toIp = IPAddress.Parse(ip);
            }
            catch (System.FormatException) {
                validAddress = false;
                this._currStatus = ConnectionStatus.Error_bad_ip; // bad ip entered
                Console.WriteLine("Bad entry, enter a proper number");
            }
            if (validAddress) {
                Console.WriteLine("Valid address! - trying it");
                this._currStatus = ConnectionStatus.Connecting;
                this._connect.Enabled = false;
                bool success = this._cGame.TryToJoinGame(ip);
                if (!success) {
                    this._currStatus = ConnectionStatus.Error_no_response;
                    this._connect.Enabled = true;
                } else
                    this.Shutdown();
            }
            Console.WriteLine("final ip = " + ip);
        }

        /// <summary>
        /// Update all the elements
        /// </summary>
        /// <param name="totalTime">The total simulation time</param>
        /// <param name="deltaTime">The time since the last call to Update()</param>
        /// <returns>The next gamestate, or GameState.None if no change is necessary</returns>
        public override GameState Update(TimeSpan totalTime, TimeSpan deltaTime) {
            bool inTextInput = false;
            for (int i = 0; i < 4; i++) {
                this._ips[i].ProcessInput(this.Game.Mouse.State, deltaTime);
                if (this._ips[i].Focused) inTextInput = true;
            }
            this.Game.InTextInput = inTextInput; // make sure we stay in text input

            this._connect.ProcessInput(this.Game.Mouse.State, deltaTime); // update the connect button

            return base.Update(totalTime, deltaTime);
        }

        /// <summary>
        /// Render all the elements
        /// </summary>
        public override void Render() {
            base.Render();

            this._bg.Render();
            for (int i = 0; i < 4; i++)
                this._ips[i].Render();

            this._connect.Render();

            Font.Begin();
            Font.Draw(FontStyle.Small, (int)this._statusPos.X, (int)this._statusPos.Y, this._status, Color.White); // draw the status header
            Font.Draw(FontStyle.Small, this._statusResponseX[(int)this._currStatus], 459, this._statusResponses[(int)this._currStatus], Color.White); // draw the status response
            Font.End();
        }
    }
}
