#region Dependancies
using System;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Graphics;
#endregion

namespace SMOCG.GUI {
    public class GUIBackground : GUIItem {
        /// <summary>
        /// Default constructor - calls the GUIItem constructor
        /// </summary>
        /// <param name="game">A reference to the main game object</param>
        /// <param name="name">the name of the widgit</param>
        /// <param name="position">the position of the top left hand corner of the widgit</param>
        /// <param name="widgitType">The type of the widgit</param>
        /// <param name="width">the width of the widgit</param>
        /// <param name="height">the height of the widgit</param>
        /// <param name="textureName">the texture to load in</param>
        /// <param name="numStates">the number of states (default, mouseover, mousedown, etc) in the texture</param>
        public GUIBackground(SMOCGGame game, string name, Vector2 position, GUI_widgit_type widgitType, int width, int height, string textureName, int numStates)
            :
            base(game, name, position, widgitType, width, height, textureName, numStates) 
        {
            this._event = new GUIEvent(this, this.WidgitType, GUI_event_type.GUI_EVENT_NONE); // set up a basic GUIEvent
        }

        /// <summary>
        /// Draw the GUIBackground
        /// </summary>
        public override void Render() {
            if (this.Visible) { // only draw if we're visible
                //create the batch if necessary
                if (_batch == null)
                    this.InitSpriteBatch();

                _batch.Begin();
                _batch.Draw(this._texture, this.Position, Color.White);
                _batch.End();
            }
        }
    }
}
