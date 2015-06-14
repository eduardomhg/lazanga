using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework.Graphics;

namespace LaZanga
{
    static class Texturas
    {
        private static Texture2D tapete;

        private static Texture2D trasera;

        private static Texture2D baza;

        private static Texture2D[] cartas;

        private static Texture2D piedra;

        public static Texture2D Tapete
        {
            get
            {
                return tapete;
            }
            set
            {
                tapete = value;
            }
        }

        public static Texture2D Trasera
        {
            get
            {
                return trasera;
            }
            set
            {
                trasera = value;
            }
        }

        public static Texture2D Baza
        {
            get
            {
                return baza;
            }
            set
            {
                baza = value;
            }
        }

        public static Texture2D Piedra
        {
            get
            {
                return piedra;
            }
            set
            {
                piedra = value;
            }
        }

        static Texturas()
        {
            tapete = null;
            trasera = null;
            baza = null;
            piedra = null;
            cartas = new Texture2D[40];
            for (int i = 0; i < cartas.Length; i++)
            {
                cartas[i] = null;
            }
        }

        public static void AsignarCarta(Texture2D textura, Carta carta)
        {
            int índice = (int)carta.Palo * 10 + (int)carta.Valor;

            cartas[índice] = textura;
        }

        public static Texture2D SeleccionarCarta(Carta carta)
        {
            int índice = (int)carta.Palo * 10 + (int)carta.Valor;

            return cartas[índice];
        }
    }
}
