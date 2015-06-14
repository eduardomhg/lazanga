#region Dependancies
using System;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Graphics;
#endregion

namespace SMOCG.GUI {
    /// <summary>
    /// The GUIButton class inherits from <see cref="GUIItem">GUIItem</see> and 
    /// allows the user to click on a button
    /// </summary>
    class GUIButton : GUIItem {

        //private GUI_event_type _currEventType; // the current gui event for this button

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
        public GUIButton(SMOCGGame game, string name, Vector2 position, GUI_widgit_type widgitType, int width, int height, string textureName, int numStates)
            :
            base(game, name, position, widgitType, width, height, textureName, numStates) 
        {
            this._event = new GUIEvent(this, this.WidgitType, GUI_event_type.GUI_EVENT_NONE); // set up a basic GUIEvent
        }

        /// <summary>
        /// Draw the GUIButton - only drawing the part of the texture that's relevant
        /// </summary>
        public override void Render() {
            if (this.Visible) { // only draw if we're visible
                //create the batch if necessary
                if (_batch == null)
                    this.InitSpriteBatch();

                _batch.Begin();

                // if the current event type is a mouse over or a mouse down and we have enough states in the texture, then use those
                if ((this._currEventType == GUI_event_type.GUI_EVENT_MOUSE_OVER && this.NumTextureStates > 1) ||
                    (this._currEventType == GUI_event_type.GUI_EVENT_MOUSE_DOWN && this.NumTextureStates > 2)) {
                    _drawRect.X = (int)this._currEventType * this.Width();
                } //otherwise, if the current event type is a mouse down, and we only have the default and mouse over states in the texture, then use the mouseover state
                else if (this._currEventType == GUI_event_type.GUI_EVENT_MOUSE_DOWN && this.NumTextureStates == 2) {
                    _drawRect.X = this.Width();
                } //just draw the default state all the time
                else
                    _drawRect.X = 0;

                //draw the part of the texture we want
                if (this.Enabled)
                    _batch.Draw(this._texture, this.Position, this._drawRect, Color.White);
                else
                    _batch.Draw(this._texture, this.Position, this._drawRect, _disabledColor);
                _batch.End();
            }
        }
    }
}
