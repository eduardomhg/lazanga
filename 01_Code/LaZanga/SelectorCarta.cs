using TomShane.Neoforce.Controls;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using System;

namespace LaZanga
{
    /// <summary>
    /// Control que muestra una carta y permite al usuario seleccionar cuál quiere tirar.
    /// </summary>
    class SelectorCarta : Control
    {
        public enum Orientación
        {
            Abajo, 
            Derecha, 
            Arriba, 
            Izquierda
        }

        private Carta carta;

        private Orientación orientación;

        public SelectorCarta(Manager manager, Orientación orientación)
            : base(manager)
        {
            carta = null;
            this.orientación = orientación;
        }

        protected override void DrawControl(Renderer renderer, Rectangle rect, GameTime gameTime)
        {
            if (carta != null)
            {
                Texture2D texturaCarta = Texturas.SeleccionarCarta((Carta)carta);

                Rectangle rectCarta = new Rectangle();
                float ángulo = 0f;
                switch (orientación)
                {
                    case Orientación.Abajo:
                        rectCarta = rect;
                        ángulo = 0f;
                        break;
                    case Orientación.Izquierda:
                        rectCarta = new Rectangle(Width, 0, Height, Width);
                        ángulo = (float)Math.PI / 2;                        
                        break;
                    case Orientación.Derecha:
                        rectCarta = new Rectangle(0, Height, Height, Width);
                        ángulo = (float)-Math.PI / 2;
                        break;
                    case Orientación.Arriba:
                        rectCarta = new Rectangle(Width, Height, Width, Height);
                        ángulo = (float)Math.PI;   
                        break;
                }
                renderer.SpriteBatch.Draw(texturaCarta, rectCarta, null, Color.White, ángulo, new Vector2(0, 0), SpriteEffects.None, 0);
            }
        }

        public void AsignarCarta(Carta carta)
        {
            this.carta = carta;
        }

        public Carta ExtraerCarta()
        {
            return carta;
        }

    }
}
