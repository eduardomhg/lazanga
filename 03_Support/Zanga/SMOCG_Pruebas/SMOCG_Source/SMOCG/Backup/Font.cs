#region Dependancies
using System;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
#endregion

namespace SMOCG {
    /// <summary>
    /// Loads in a font sheet as a texture, and pulls digits off it to draw
    /// </summary>
    public static class Font {

        /// <summary>
        /// a sprite batch to draw our fonts
        /// </summary>
        private static SpriteBatch _batch;

        private static Texture2D[] _textures = new Texture2D[3];

        /// <summary>
        /// has the Font class been setup
        /// </summary>
        public static bool _isSetup = false;

        /// <summary>
        /// have the textures been loaded?
        /// </summary>
        private static bool _texturesLoaded = false;

        /// <summary>
        /// has the Font class been setup
        /// </summary>
        public static bool IsSetup {
            get { return _isSetup; }
        }

        /// <summary>
        /// a struct to help with the organisation of font information
        /// </summary>
        private struct FontInfo {
            public string Filename; // the name of the texture to load in
            public string Characters; // what characters are in the texture
            public int CharSpacing; // how much space is between each char
            public int RenderSpacing; // how much space to put between each char when rendering
            public int CharHeight; // the character's height
            public int CharWidth; // the character's width
            public int TextureNum; // what number of texture to use

            public FontInfo(string filename, string chars, int charSpacing, int renderSpacing, int charHeight, int charWidth, int textureNum) {
                this.Filename = filename;
                this.Characters = chars;
                this.CharSpacing = charSpacing;
                this.RenderSpacing = renderSpacing;
                this.CharHeight = charHeight;
                this.CharWidth = charWidth;
                this.TextureNum = textureNum;
            }
        }

        /// <summary>
        /// setup all the font's used in the game
        /// </summary>
        private static FontInfo[] _fontInfo = new FontInfo[]{
                new FontInfo(SMOCGGame.Settings.FontTexturePath + SMOCGGame.Settings.FontLarge, "abcdefghijklmnopqrstuvwxyz0123456789-_", 36, 21, 36, 36, 0),
                new FontInfo(SMOCGGame.Settings.FontTexturePath + SMOCGGame.Settings.FontSmall, "abcdefghijklmnopqrstuvwxyz0123456789-_.", 18, 11, 18, 18, 1),
                new FontInfo(SMOCGGame.Settings.FontTexturePath + SMOCGGame.Settings.FontSmallest, "abcdefghijklmnopqrstuvwxyz0123456789-_", 12, 8, 17, 10, 2)
            };

        /// <summary>
        /// create the sprite batch used to draw the fonts, and load in the textures if necessary
        /// </summary>
        public static void Init(SMOCGGame game){
            if(_batch == null)
                _batch = new SpriteBatch(SMOCGGame.Graphics.GraphicsDevice);

            //load in the textures if needed
            if (!_texturesLoaded) {
                for (int i = 0; i < _fontInfo.Length; i++) {
                    _textures[i] = game.ContentManager.Load<Texture2D>(_fontInfo[i].Filename);
                }
                _texturesLoaded = true;
            }
            _isSetup = true;
        }

        /// <summary>
        /// Dispose of the Font's SpriteBatch
        /// </summary>
        public static void Dispose(){
            if(_batch != null){
                _batch.Dispose();
                _batch = null;
            }
            _isSetup = false;
        }

        /// <summary>
        /// setup the Font to begin drawing
        /// </summary>
        public static void Begin(){
            _batch.Begin(SpriteBlendMode.AlphaBlend, SpriteSortMode.Texture, SaveStateMode.None);
        }

        /// <summary>
        /// make the call to finish drawing
        /// </summary>
        public static void End() {
            _batch.End();
        }

        /// <summary>
        /// Draws a string using a particular font style
        /// </summary>
        /// <param name="fontStyle">the font style to use</param>
        /// <param name="x">Where to start drawing the string (x)</param>
        /// <param name="y">Where to start drawing the string (y)</param>
        /// <param name="text">What text to draw</param>
        /// <param name="color">What color to draw it</param>
        public static void Draw(FontStyle fontStyle, int x, int y, string text, Color color) {
            FontInfo fInfo = _fontInfo[(int)fontStyle]; // grab our font info

            Vector2 textPos = new Vector2(x, y); // where the characters position is
            Rectangle drawRect = new Rectangle(0, 0, fInfo.CharWidth, fInfo.CharHeight); // the draw rect to draw the part of the texture

            text = text.ToLower(); // put the string to all lower case

            //Console.WriteLine(text + " = text being asked to draw - in Font.Draw()");

            for (int i = 0; i < text.Length; i++) {
                //don't do anything if it's a space character
                if (text[i] != ' ') {
                    //if it's a narrow char, bring it closer to the previous one
                    if (text[i] == 'i' || text[i] == '1' || (fontStyle == FontStyle.Small && text[i] == '.') ) textPos.X -= 1;

                    //get the character position
                    int charPos = fInfo.Characters.IndexOf(text[i]);

                    //move the drawRect
                    drawRect.X = charPos * fInfo.CharSpacing;

                    //draw the correct characters in the correct position
                    _batch.Draw(_textures[fInfo.TextureNum], textPos, drawRect, color);
                }
                //move to the position of the next char
                //if it's I or 1, then bring it in closer
                textPos.X += (text[i] == 'i' || text[i] == '1' || (fontStyle == FontStyle.Small && text[i] == '.')) ? fInfo.RenderSpacing / 1.5f : fInfo.RenderSpacing;
            }
        }

        /// <summary>
        /// Gets a rough width of the text in a specific font style
        /// </summary>
        /// <param name="fontStyle">the font style that the text will be using</param>
        /// <param name="text">the text to write</param>
        /// <returns>the rough width of the text</returns>
        public static int GetWidth(FontStyle fontStyle, string text) {
            FontInfo fInfo = _fontInfo[(int)fontStyle]; // get the font info
            int ret = 0;

            //go through the string and add up how much rendering space it takes
            for (int i = 0; i < text.Length; i++)
                ret += (text[i] == 'i' || text[i] == 'I' || text[i] == '1' || (fontStyle == FontStyle.Small && text[i] == '.')) ? (int)(fInfo.RenderSpacing / 1.5f) : fInfo.RenderSpacing;

            return ret;
        }
    }
}
