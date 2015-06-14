using TomShane.Neoforce.Controls;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using System;

namespace LaZanga
{
    /// <summary>
    /// Control gráfico que muestra una mesa de Zanga y la evolución de una partida.    
    /// </summary>
    class MonitorMesa : Control
    {
        /// <summary>
        /// Posibles orientaciones de una carta en pantalla.
        /// </summary>
        private enum Orientación
        {
            Abajo, 
            Derecha, 
            Arriba, 
            Izquierda
        }            

        /// <summary>
        /// Objeto Mesa del que el control saca la información para mostrar visualmente.
        /// </summary>
        private Mesa mesa;

        private readonly Size TamañoCartaVert;
        private readonly Size TamañoCartaHoriz;
        private readonly Size TamañoBazaVert;
        private readonly Size TamañoBazaHoriz;

        private Rectangle RectCartaJugador1;
        private Rectangle RectCartaJugador2;
        private Rectangle RectCartaJugador3;
        private Rectangle RectCartaJugador4;

        private Rectangle RectZangaAbajoIzquierda;
        private Rectangle RectZangaArribaDerecha;

        private Rectangle RectPiedrasCentro;
        private Rectangle RectPiedrasAbajoDerecha;
        private Rectangle RectPiedrasArribaIzquierda;

        private Rectangle[] RectBazasAbajo;
        private Rectangle[] RectBazasIzquierda;

        private SpriteFont font;

        public MonitorMesa(Manager manager, Size tamañoCartaVert)
            : base(manager)
        {
            mesa = new Mesa();
            TamañoCartaVert = tamañoCartaVert;
            TamañoCartaHoriz = new Size(TamañoCartaVert.Height, TamañoCartaVert.Width);
            TamañoBazaVert = new Size(TamañoCartaVert.Width * 111 / 100, TamañoCartaVert.Height);
            TamañoBazaHoriz = new Size(TamañoBazaVert.Height, TamañoBazaVert.Width);
            //mesa.TirarCarta(new Carta(Valor.As, Palo.Bastos));

            RectBazasAbajo = new Rectangle[8];
            RectBazasIzquierda = new Rectangle[8];
            font = this.Manager.Game.Content.Load<SpriteFont>("Courier New");
        }

        public void CalcularDistancias()
        {
            // Calculamos los rectángulos de las cartas jugadas.
            int distanciaDesdeElCentro = this.Width * 10 / 100;
            Point centro = this.ClientRect.Center;
            Point esqSupIzqCartaJugador1 = new Point(centro.X - TamañoCartaVert.Width / 2, centro.Y + distanciaDesdeElCentro);
            RectCartaJugador1 = new Rectangle(esqSupIzqCartaJugador1.X, esqSupIzqCartaJugador1.Y, TamañoCartaVert.Width, TamañoCartaVert.Height);
            Point esqSupIzqCartaJugador2 = new Point(centro.X + distanciaDesdeElCentro, centro.Y - TamañoCartaVert.Height / 2);
            RectCartaJugador2 = new Rectangle(esqSupIzqCartaJugador2.X, esqSupIzqCartaJugador2.Y, TamañoCartaVert.Width, TamañoCartaVert.Height);
            Point esqSupIzqCartaJugador3 = new Point(centro.X - TamañoCartaVert.Width / 2, centro.Y - distanciaDesdeElCentro - TamañoCartaVert.Height);
            RectCartaJugador3 = new Rectangle(esqSupIzqCartaJugador3.X, esqSupIzqCartaJugador3.Y, TamañoCartaVert.Width, TamañoCartaVert.Height);
            Point esqSupIzqCartaJugador4 = new Point(centro.X - distanciaDesdeElCentro - TamañoCartaVert.Width, centro.Y - TamañoCartaVert.Height / 2);
            RectCartaJugador4 = new Rectangle(esqSupIzqCartaJugador4.X, esqSupIzqCartaJugador4.Y, TamañoCartaVert.Width, TamañoCartaVert.Height);

            // Calculamos los rectángulos de las zangas.
            int distanciaDesdeLateral = this.Width * 6 / 100;
            Point esqSupIzqZanga1 = new Point(distanciaDesdeLateral, this.Height - distanciaDesdeLateral - TamañoBazaVert.Height);
            RectZangaAbajoIzquierda = new Rectangle(esqSupIzqZanga1.X, esqSupIzqZanga1.Y, TamañoBazaVert.Width, TamañoBazaVert.Height);
            Point esqSupIzqZanga2 = new Point(this.Width - distanciaDesdeLateral - TamañoBazaVert.Width, distanciaDesdeLateral);
            RectZangaArribaDerecha = new Rectangle(esqSupIzqZanga2.X, esqSupIzqZanga2.Y, TamañoBazaVert.Width, TamañoBazaVert.Height);

            // Calculamos los rectángulos de las piedras.
            Size tamañoTotalPiedras = new Size(8 * 6 + 7 * 6, 4 * 6 + 3 * 6);
            RectPiedrasCentro = new Rectangle((this.Width - tamañoTotalPiedras.Width) / 2, (this.Height - tamañoTotalPiedras.Height) / 2, tamañoTotalPiedras.Width,
                                              tamañoTotalPiedras.Height);
            Point esqSupIzqPiedrasAbajoDerecha = new Point(RectZangaArribaDerecha.Right - tamañoTotalPiedras.Width, RectZangaAbajoIzquierda.Bottom - tamañoTotalPiedras.Height);
            RectPiedrasAbajoDerecha = new Rectangle(esqSupIzqPiedrasAbajoDerecha.X, esqSupIzqPiedrasAbajoDerecha.Y, tamañoTotalPiedras.Width, tamañoTotalPiedras.Height);
            Point esqSupIzqPiedrasArribaIzquierda = new Point(RectZangaAbajoIzquierda.Left, RectZangaArribaDerecha.Top);
            RectPiedrasArribaIzquierda = new Rectangle(esqSupIzqPiedrasArribaIzquierda.X, esqSupIzqPiedrasArribaIzquierda.Y, tamañoTotalPiedras.Width, tamañoTotalPiedras.Height);

            // Calculamos los rectángulos de las bazas de abajo.
            int espacioEntreBazas = TamañoBazaHoriz.Height * 20 / 100;
            Rectangle rectBaseHorizAbajo = new Rectangle((this.Width - TamañoBazaHoriz.Width) / 2, this.Height - TamañoBazaHoriz.Height, TamañoBazaHoriz.Width, TamañoBazaHoriz.Height);
            Rectangle rectBaseVertAbajo = new Rectangle((this.Width - TamañoBazaVert.Width) / 2, 
                                                         this.Height - espacioEntreBazas - TamañoBazaVert.Height, TamañoBazaVert.Width, TamañoBazaVert.Height);
            for (int i = 0; i < 4; i++)
            {             
                RectBazasAbajo[2 * i] = new Rectangle(rectBaseHorizAbajo.X, rectBaseHorizAbajo.Y - espacioEntreBazas * 2 * i,
                                                      rectBaseHorizAbajo.Width, rectBaseHorizAbajo.Height);
                RectBazasAbajo[2 * i + 1] = new Rectangle(rectBaseVertAbajo.X, rectBaseVertAbajo.Y - espacioEntreBazas * 2 * i,
                                                          rectBaseVertAbajo.Width, rectBaseVertAbajo.Height);
            }


            // Calculamos los rectángulos de las bazas de la izquierda.
            Rectangle rectBaseVertIzquierda = new Rectangle(0, (this.Height - TamañoBazaVert.Height) / 2, TamañoBazaVert.Width, TamañoBazaVert.Height);
            Rectangle rectBaseHorizIzquierda = new Rectangle(espacioEntreBazas, (this.Height - TamañoBazaHoriz.Height) / 2, TamañoBazaHoriz.Width, TamañoBazaHoriz.Height);
            for (int i = 0; i < 4; i++)
            {
                RectBazasIzquierda[2 * i] = new Rectangle(rectBaseVertIzquierda.X + espacioEntreBazas * 2 * i, rectBaseVertIzquierda.Y,
                                                          rectBaseVertIzquierda.Width, rectBaseVertIzquierda.Height);
                RectBazasIzquierda[2 * i + 1] = new Rectangle(rectBaseHorizIzquierda.X + espacioEntreBazas * 2 * i, rectBaseHorizIzquierda.Y,
                                                              rectBaseHorizIzquierda.Width, rectBaseHorizIzquierda.Height);
            }            
        }


        protected override void DrawControl(Renderer renderer, Rectangle rect, GameTime gameTime)
        {
            renderer.Draw(Texturas.Tapete, this.ClientRect, Color.White);

            DibujarCarta(renderer, mesa.Cartas[0], RectCartaJugador1.Location, Orientación.Abajo);
            DibujarCarta(renderer, mesa.Cartas[0], RectCartaJugador2.Location, Orientación.Abajo);
            DibujarCarta(renderer, mesa.Cartas[0], RectCartaJugador3.Location, Orientación.Abajo);
            DibujarCarta(renderer, mesa.Cartas[0], RectCartaJugador4.Location, Orientación.Abajo);

            DibujarBaza(renderer, RectZangaAbajoIzquierda.Location, Orientación.Abajo);
            DibujarBaza(renderer, RectZangaArribaDerecha.Location, Orientación.Abajo);

            DibujarPiedras(renderer, 32, 6, 6, RectPiedrasCentro.Center);
            DibujarPiedras(renderer, 32, 6, 6, RectPiedrasAbajoDerecha.Center);
            DibujarPiedras(renderer, 32, 6, 6, RectPiedrasArribaIzquierda.Center);                       


            for (int i = 0; i < RectBazasAbajo.Length; i++)
            {
                DibujarBaza(renderer, RectBazasAbajo[i].Location, ((i % 2)) == 0 ? Orientación.Izquierda : Orientación.Abajo);
                DibujarBaza(renderer, RectBazasIzquierda[i].Location, ((i % 2)) == 0 ? Orientación.Abajo : Orientación.Izquierda);
            }

            Vector2 tamañoNumAbajo = font.MeasureString("8");
            Point esqSupIzqNumAbajo = new Point(RectBazasAbajo[0].Left - 10 - (int)tamañoNumAbajo.X, RectBazasAbajo[0].Center.Y - (int)(tamañoNumAbajo.Y/2));
            renderer.SpriteBatch.DrawString(font, "8", new Vector2(esqSupIzqNumAbajo.X, esqSupIzqNumAbajo.Y), Color.White, 0.0f, new Vector2(), 1.0f, SpriteEffects.None, 1.0f);

            Vector2 tamañoNumIzquierda = font.MeasureString("8");
            Point esqSupIzqNumIzquierda = new Point(RectBazasIzquierda[0].Center.X - (int)(tamañoNumAbajo.X / 2), RectBazasIzquierda[0].Bottom + 10);
            renderer.SpriteBatch.DrawString(font, "8", new Vector2(esqSupIzqNumIzquierda.X, esqSupIzqNumIzquierda.Y), Color.White, 0.0f, new Vector2(), 1.0f, SpriteEffects.None, 1.0f);
        }

        private void DibujarPiedras(Renderer renderer, int numPiedras, int ladoPiedra, int espacioEntrePiedras, Point centro)
        {
            Point[] coordOrdenAparición = new Point[32]{ new Point(1, 3),
                                                         new Point(1, 4),
                                                         new Point(2, 3),
                                                         new Point(2, 4),
                                                         new Point(1, 2),
                                                         new Point(2, 2),
                                                         new Point(1, 5),
                                                         new Point(2, 5),
                                                         new Point(0, 3),
                                                         new Point(0, 4),
                                                         new Point(3, 3),
                                                         new Point(3, 4),
                                                         new Point(0, 2),
                                                         new Point(0, 5),
                                                         new Point(3, 2),
                                                         new Point(3, 5),
                                                         new Point(1, 1),
                                                         new Point(2, 1),
                                                         new Point(1, 6),
                                                         new Point(2, 6),
                                                         new Point(0, 1),
                                                         new Point(0, 6),
                                                         new Point(3, 1),
                                                         new Point(3, 6),
                                                         new Point(1, 0),
                                                         new Point(2, 0),
                                                         new Point(1, 7),
                                                         new Point(2, 7),
                                                         new Point(0, 0),
                                                         new Point(0, 7),
                                                         new Point(3, 0),
                                                         new Point(3, 7)};

            Size tamañoTotal = new Size(8 * ladoPiedra + 7 * espacioEntrePiedras, 4 * ladoPiedra + 3 * espacioEntrePiedras);
            Point esqSuperiorIzquierda = new Point(centro.X - tamañoTotal.Width / 2, centro.Y - tamañoTotal.Height / 2);
            Rectangle rectTotalPiedras = new Rectangle(esqSuperiorIzquierda.X, esqSuperiorIzquierda.Y, tamañoTotal.Width, tamañoTotal.Height);

            for (int i = 0; i < numPiedras; i++)
            {
                Point esqSupIzqPiedra = new Point(esqSuperiorIzquierda.X + coordOrdenAparición[i].Y * (ladoPiedra + espacioEntrePiedras),
                                                  esqSuperiorIzquierda.Y + coordOrdenAparición[i].X * (ladoPiedra + espacioEntrePiedras));
                Rectangle rectPiedra = new Rectangle(esqSupIzqPiedra.X, esqSupIzqPiedra.Y, ladoPiedra, ladoPiedra);
                renderer.Draw(Texturas.Piedra, rectPiedra, Color.White);
            }

            int anchuraTexto = (int)font.MeasureString(numPiedras.ToString()).X;
            Point esqSupIzqTexto = new Point(rectTotalPiedras.Center.X - anchuraTexto / 2, rectTotalPiedras.Bottom + 5);
            renderer.SpriteBatch.DrawString(font, numPiedras.ToString(), new Vector2(esqSupIzqTexto.X, esqSupIzqTexto.Y), Color.White, 0.0f, new Vector2(), 1.0f, SpriteEffects.None, 1.0f);
        }

        private void DibujarCarta(Renderer renderer, Carta carta, Point esqSupIzq, Orientación orientación)
        {
            if (carta != null)
            {
                Rectangle rectCarta = new Rectangle();
                float ángulo = 0f;
                switch (orientación)
                {
                    case Orientación.Abajo:
                        rectCarta = new Rectangle(0, 0, TamañoCartaVert.Width, TamañoCartaVert.Height);
                        ángulo = 0f;
                        break;
                    case Orientación.Izquierda:
                        rectCarta = new Rectangle(TamañoCartaHoriz.Width, 0, TamañoCartaHoriz.Height, TamañoCartaHoriz.Width);
                        ángulo = (float)Math.PI / 2;                        
                        break;
                    case Orientación.Derecha:
                        rectCarta = new Rectangle(0, TamañoCartaHoriz.Height, TamañoCartaHoriz.Height, TamañoCartaHoriz.Width);
                        ángulo = (float)-Math.PI / 2;
                        break;
                    case Orientación.Arriba:
                        rectCarta = new Rectangle(TamañoCartaHoriz.Height, TamañoCartaHoriz.Width, TamañoCartaVert.Width, TamañoCartaVert.Height);
                        ángulo = (float)Math.PI;   
                        break;
                }
                rectCarta.Offset(esqSupIzq);
                renderer.SpriteBatch.Draw(Texturas.SeleccionarCarta(carta), rectCarta, null, Color.White, ángulo, new Vector2(0, 0), SpriteEffects.None, 0);
            }
        }

        private void DibujarTrasera(Renderer renderer, Point esqSupIzq, Orientación orientación)
        {
            Rectangle rectCarta = new Rectangle();
            float ángulo = 0f;
            switch (orientación)
            {
                case Orientación.Abajo:
                    rectCarta = new Rectangle(0, 0, TamañoCartaVert.Width, TamañoCartaVert.Height);
                    ángulo = 0f;
                    break;
                case Orientación.Izquierda:
                    rectCarta = new Rectangle(TamañoCartaHoriz.Width, 0, TamañoCartaHoriz.Height, TamañoCartaHoriz.Width);
                    ángulo = (float)Math.PI / 2;
                    break;
                case Orientación.Derecha:
                    rectCarta = new Rectangle(0, TamañoCartaHoriz.Height, TamañoCartaHoriz.Height, TamañoCartaHoriz.Width);
                    ángulo = (float)-Math.PI / 2;
                    break;
                case Orientación.Arriba:
                    rectCarta = new Rectangle(TamañoCartaHoriz.Height, TamañoCartaHoriz.Width, TamañoCartaVert.Width, TamañoCartaVert.Height);
                    ángulo = (float)Math.PI;
                    break;
            }
            rectCarta.Offset(esqSupIzq);
            renderer.SpriteBatch.Draw(Texturas.Trasera, rectCarta, null, Color.White, ángulo, new Vector2(0, 0), SpriteEffects.None, 0);
        }

        private void DibujarBaza(Renderer renderer, Point esqSupIzq, Orientación orientación)
        {
            Rectangle rectBaza = new Rectangle();
            float ángulo = 0f;
            switch (orientación)
            {
                case Orientación.Abajo:
                    rectBaza = new Rectangle(0, 0, TamañoBazaVert.Width, TamañoBazaVert.Height);
                    ángulo = 0f;
                    break;
                case Orientación.Izquierda:
                    rectBaza = new Rectangle(TamañoBazaHoriz.Width, 0, TamañoBazaHoriz.Height, TamañoBazaHoriz.Width);
                    ángulo = (float)Math.PI / 2;
                    break;
                case Orientación.Derecha:
                    rectBaza = new Rectangle(0, TamañoBazaHoriz.Height, TamañoBazaHoriz.Height, TamañoBazaHoriz.Width);
                    ángulo = (float)-Math.PI / 2;
                    break;
                case Orientación.Arriba:
                    rectBaza = new Rectangle(TamañoBazaHoriz.Height, TamañoBazaHoriz.Width, TamañoBazaVert.Width, TamañoBazaVert.Height);
                    ángulo = (float)Math.PI;
                    break;
            }
            rectBaza.Offset(esqSupIzq);
            renderer.SpriteBatch.Draw(Texturas.Baza, rectBaza, null, Color.White, ángulo, new Vector2(0, 0), SpriteEffects.None, 0);
        }


    }
}
