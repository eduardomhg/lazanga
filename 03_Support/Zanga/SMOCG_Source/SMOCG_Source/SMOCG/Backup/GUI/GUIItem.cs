#region Dependancies
using System;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Graphics;
#endregion

namespace SMOCG.GUI {
    /// <summary>
    /// The GUIItem class represents an object that can interact with the mouse and fire off events when needed
    /// </summary>
    public abstract class GUIItem {
        /// <summary>
        /// A struct GUIEvent - comprimises of info including; the creator of the event, the widgit type, and the event type
        /// </summary>
        public struct GUIEvent {
            public GUIItem _creator; // the creator of the event
            public GUI_widgit_type _widgitType; // the type of widgit that created the event
            public GUI_event_type _eventType; // the event type

            /// <summary>
            /// Default constructor
            /// </summary>
            /// <param name="creator">The GUIItem that created the type</param>
            /// <param name="widgitType">The type of widgit that the GUIItem is</param>
            /// <param name="eventType">What type of event is being generated</param>
            public GUIEvent(GUIItem creator, GUI_widgit_type widgitType, GUI_event_type eventType){
                this._creator = creator;
                this._widgitType = widgitType;
                this._eventType = eventType;
            }
        }

        private SMOCGGame _game; // a reference to the main game object

        private bool _enabled; // is the gui item enabled?
        private bool _visible; // is the gui item visible?
        private bool _clicked; // has the gui item been clicked?
        private bool _focused; // has the gui item been focused?

        private string _name; // the name of the gui item
        private GUIItem _parent; // who owns the gui item

        private Vector2 _position; // the position of the top left hand corner of the gui item
        private Vector2 _center; // the center of the gui item
        private Vector2 _clickedPos; // where the mouse was clicked on the widgit
        private Rectangle _bounds; // the rectangular bounds of the gui item
        protected Rectangle _drawRect; // the drawing rect of the gui item

        protected Texture2D _texture; // the GUI texture
        private int _numTextureStates; // the number of texture states (default, mouseOver) etc that the texture has

        protected static SpriteBatch _batch = null; // a sprite batch used to draw all the gui items

        protected GUIEvent _event; // the event for this control
        protected GUI_event_type _currEventType; // current event type for this widgit
        private GUI_widgit_type _widgitType; // the type of the widgit

        protected static Color _disabledColor = new Color((byte)173, (byte)216, (byte)230, (byte)128);



        public delegate void OnMouseUpHandler();
        private OnMouseUpHandler _mouseUp = null;

        public delegate void OnEnterPressedHandler();
        private OnEnterPressedHandler _enterPressed = null;

        #region Get and Set Properties

        /// <summary>
        /// Get and set the OnMouseUpHandler
        /// </summary>
        public OnMouseUpHandler MouseUp {
            get { return _mouseUp; }
            set { _mouseUp = value; }
        }

        /// <summary>
        /// Get and set the OnEnterPressedHandler
        /// </summary>
        public OnEnterPressedHandler OnEnterPressed {
            get { return this._enterPressed; }
            set { this._enterPressed = value; }
        }

        /// <summary>
        /// Get the reference to the main game object
        /// </summary>
        public SMOCGGame Game {
            get { return _game; }
        }

        /// <summary>
        /// Is the GUI item enabled
        /// </summary>
        public bool Enabled {
            get { return _enabled; }
            set { _enabled = value; }
        }

        /// <summary>
        /// Is the GUI item visible
        /// </summary>
        public bool Visible {
            get { return _visible; }
            set { _visible = value; }
        }

        /// <summary>
        /// Has the GUI item been clicked
        /// </summary>
        public bool Clicked {
            get { return _clicked; }
            set { _clicked = value; }
        }

        /// <summary>
        /// Has the GUI item been focused
        /// </summary>
        public bool Focused {
            get { return _focused; }
            set { _focused = value; }
        }

        /// <summary>
        /// The name of the GUI item
        /// </summary>
        public string Name {
            get { return _name; }
            set { _name = value; }
        }

        /// <summary>
        /// Set the parent of the GUI item
        /// </summary>
        /// <param name="parent">The parent of the GUI item</param>
        public void SetParent(ref GUIItem parent) {
            this._parent = parent;
        }

        /// <summary>
        /// The position of the top left hand corner of the GUI item
        /// </summary>
        public Vector2 Position{
            get { return _position; }
            set { _position = value; }
        }

        /// <summary>
        /// The clicked position - i.e. where the mouse clicked it
        /// </summary>
        public Vector2 ClickedPosition {
            get { return _clickedPos; }
            set { _clickedPos = value; }
        }

        /// <summary>
        /// The number of texture states (default, mouseOver, etc) that the GUI item has
        /// </summary>
        public int NumTextureStates {
            get { return _numTextureStates; }
        }

        /// <summary>
        /// Get the type of the GUI item
        /// </summary>
        public GUI_widgit_type WidgitType {
            get { return _widgitType; }
        }

        #endregion

        /// <summary>
        /// Default constructor, sets the defaults to null
        /// </summary>
        public GUIItem(SMOCGGame game) {
            this._game = game;

            _enabled = false;
            _visible = false;
            _clicked = false;
            _focused = false;

            _parent = null;
            _name = "NewGUIItem";

            _position = _center = new Vector2(0);
            _widgitType = GUI_widgit_type.GUI_WIDGIT_NONE;
            _bounds = new Rectangle(0, 0, 0, 0);

            _texture = null;
            _numTextureStates = 0;

            //create the sprite batch if necessary
            InitSpriteBatch();
        }

        /// <summary>
        /// Constructor that sets up the gui item properly
        /// </summary>
        /// <param name="game">A reference to the main game object</param>
        /// <param name="name">The name of the gui item</param>
        /// <param name="position">Where the gui item is positioned on the screen (by it's top left hand corner)</param>
        /// <param name="widgitType">The type of the widgit</param>
        /// <param name="width">The width of the gui item</param>
        /// <param name="height">The height of the gui item</param>
        /// <param name="textureName">The name of the gui item's texture</param>
        /// <param name="numStates">how many gui states (default, mouseOver, mouseDown) there are in the texture</param>
        public GUIItem(SMOCGGame game, string name, Vector2 position, GUI_widgit_type widgitType, int width, int height, string textureName, int numStates) {
            this._game = game;

            _enabled = true; // gui item is enabled
            _visible = true; // gui item is visible
            _clicked = false; // gui item hasn't been clicked
            _focused = false; // gui item hasn't been focused

            _parent = null; // no parent yet
            _name = name; // gui item's name

            _position = position; // where it's positioned
            _center = new Vector2((position.X + width / 2), (position.Y + height / 2));
            _widgitType = widgitType; // the type of the widgit
            _bounds = new Rectangle((int)_position.X, (int)_position.Y, width, height); // set up the bounds of the gui item

            _numTextureStates = numStates; // the number of texture states in the texture
            LoadTexture(textureName); // load in the texture

            //create the sprite batch if necessary
            InitSpriteBatch();
        }

        /// <summary>
        /// Is the mouse over the GUI item?
        /// </summary>
        /// <param name="mousex">The X position of the mouse</param>
        /// <param name="mousey">The Y position of the mouse</param>
        /// <returns>Whether the mouse is currently over the gui item or not</returns>
        protected bool IsMouseOver(int mousex, int mousey) {
            //if the widgit is circular, do a length test between the mouse position and the center of the circle
            if (_widgitType == GUI_widgit_type.GUI_WIDGIT_CIRCLE_BUTTON)
                //the center of the circle is the position (top left hand corner) plus half the width and height
                return (new Vector2(mousex - (_position.X + _bounds.Width / 2), mousey - (_position.Y + _bounds.Height / 2)).Length() < _bounds.Width / 2);
            else // just do a rectangular bounds check
                return (mousex > _bounds.Left) && (mousex < _bounds.Right) && (mousey > _bounds.Top) && (mousey < _bounds.Bottom);
        }

        /// <summary>
        /// Load the texture associated with the GUI item
        /// </summary>
        /// <param name="texturePath">the path to the texture</param>
        private void LoadTexture(string texturePath) {
            _texture = this._game.ContentManager.Load<Texture2D>(texturePath);
            _drawRect = new Rectangle(0, 0, _texture.Width / this._numTextureStates, this._bounds.Height); // create the draw rect
        }

        /// <summary>
        /// Init the sprite batch if necessary
        /// </summary>
        protected void InitSpriteBatch() {
            if (_batch == null)
                _batch = new SpriteBatch(SMOCGGame.Graphics.GraphicsDevice);
        }

        /// <summary>
        /// Clear up the sprite batch and set it to null
        /// </summary>
        protected void Dispose() {
            if (_batch != null) {
                _batch.Dispose();
                _batch = null;
            }
        }

        /// <summary>
        /// Get the Width of the GUI item
        /// </summary>
        /// <returns>the width of the GUI item</returns>
        public int Width() {
            return _bounds.Width;
        }

        /// <summary>
        /// Get the Height of the GUI item
        /// </summary>
        /// <returns>The height of the GUI item</returns>
        public int Height() {
            return _bounds.Height;
        }

        /// <summary>
        /// Process the input of the mouse. Base class method is abstract, so classes inheriting from this have to fill this out
        /// </summary>
        /// <param name="mState">The mouse state</param>
        /// <param name="deltaTime">The time since the last call to ProcessInput</param>
        /// <returns>A GuiEvent that marks what happened</returns>
        public virtual GUIEvent ProcessInput(MouseState mState, TimeSpan deltaTime) {
            if (this._widgitType != GUI_widgit_type.GUI_WIDGIT_BACKGROUND) { // the background widgit doesn't need to update
                if (this.Visible && this.Enabled) { // if we're visible and enabled
                    //the mouse is over the button
                    if (this.IsMouseOver(mState.X, mState.Y)) {
                        //the mouse button is currently pressed down as well
                        if (mState.LeftButton == ButtonState.Pressed) {
                            if (this._currEventType == GUI_event_type.GUI_EVENT_NONE) // mouse has been pressed from outside the button
                                this._currEventType = GUI_event_type.GUI_EVENT_NONE; // so just ignore it
                            else {
                                this._currEventType = GUI_event_type.GUI_EVENT_MOUSE_DOWN; // this is a mouse down, i.e. the button is currently being pressed
                                OnMouseDown(); // call onMouseDown
                            }
                        } else { // the buttons isn't being pressed
                            if (this._currEventType == GUI_event_type.GUI_EVENT_MOUSE_DOWN) { // if the previous event was a mouse down
                                this._currEventType = GUI_event_type.GUI_EVENT_MOUSE_UP; // then this is a mouse up, i.e. the button has just been clicked
                                this._clickedPos = new Vector2(mState.X, mState.Y); // store the clicked position
                                OnMouseUp(); // call onMouseUp
                            } else {// the button hasn't previously been pressed
                                this._currEventType = GUI_event_type.GUI_EVENT_MOUSE_OVER; // just a mouse over
                                OnMouseOver(); // call onMouseOver
                            }
                        }
                    } else { // the mouse isn't over the button anymore
                        if (mState.LeftButton == ButtonState.Pressed) {
                            this._currEventType = GUI_event_type.GUI_EVENT_NONE;
                            this._focused = false;
                        } else if (this._currEventType == GUI_event_type.GUI_EVENT_MOUSE_OVER) { // if the previous event was a mouse over
                            this._currEventType = GUI_event_type.GUI_EVENT_MOUSE_OUT; // then this is a mouse out, i.e. the mouse has entered, then exited the button bounds
                            OnMouseOut(); // call onMouseOut();
                        } else
                            this._currEventType = GUI_event_type.GUI_EVENT_NONE; // the mouse isn't near the button
                    }

                    if (this._event._eventType != this._currEventType) this._event._eventType = this._currEventType; // change the event type if necessary
                } else {
                    this.Focused = false; // we're not visible, or enabled, so we're not focused
                    this._currEventType = GUI_event_type.GUI_EVENT_NONE;
                }
            }

            return this._event;
        }

        /// <summary>
        /// Method to call when the mouse is over the GUI item. base class does nothing
        /// </summary>
        public virtual void OnMouseOver() { }

        /// <summary>
        /// Method to call when the mouse was over the GUI item and no longer is. base class does nothing
        /// </summary>
        public virtual void OnMouseOut() { }

        /// <summary>
        /// Method to call when the mouse is over the GUI item and is clicked. base class does nothing
        /// </summary>
        public virtual void OnMouseDown() { }

        /// <summary>
        /// Method to call when the mouse was clicked on the GUI item and subsequently released. base class does nothing
        /// </summary>
        public virtual void OnMouseUp() { Console.WriteLine("ON MOUSE UP"); if (MouseUp != null) MouseUp(); }

        /// <summary>
        /// Render the GUI item. base class does nothing
        /// </summary>
        public virtual void Render() { }
    }
}
