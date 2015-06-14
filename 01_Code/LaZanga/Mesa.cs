using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace LaZanga
{
    class Mesa
    {
        #region Types

        private class Baraja
        {
            private const int NúmeroCartas = 40;

            private List<Carta> cartas;

            private Random generadorAleatorio;

            public Carta this[int index]
            {
                get
                {
                    return cartas[index];
                }
            }

            public Baraja()
            {
                cartas = new List<Carta>(NúmeroCartas);

                foreach (Palo palo in Enum.GetValues(typeof(Palo)))
                {
                    foreach (Valor valor in Enum.GetValues(typeof(Valor)))
                    {
                        cartas.Add(new Carta(valor, palo));
                    }
                }

                generadorAleatorio = new Random(DateTime.Now.Millisecond);
            }

            public void Barajar()
            {
                int cartasPorBarajar = cartas.Count;
                int indiceAleatorio = 0;

                while (cartasPorBarajar > 1)
                {
                    cartasPorBarajar--;                         // n is now the last pertinent index
                    indiceAleatorio = generadorAleatorio.Next(cartasPorBarajar + 1);  // 0 <= k <= n.
                    Carta temp = cartas[indiceAleatorio];
                    cartas[indiceAleatorio] = cartas[cartasPorBarajar];
                    cartas[cartasPorBarajar] = temp;
                }                
            }
        }

        public enum Jugador
        {
            Jugador1, 
            Jugador2,
            Jugador3,
            Jugador4
        }

        #endregion

        #region Constants

        private const int NúmJugadores = 4;

        private const int NúmParejas = NúmJugadores / 2;

        private const int NúmCartasMesa = 4;

        private const int MaxCartasBaza = 4;

        private const int MaxBazasPorPareja = 8;

        private const int NúmTotalPiedras = 32;

        #endregion

        #region Fields

        private Baraja baraja;

        private Carta[] cartasMesa;

        private List<Carta[]>[] bazas;

        private Carta[,] cartasJugadores;

        private int[] piedras;

        private bool sePidióCinco;

        private bool alguienTieneEstuche;

        private bool alguienSeFueSolo;

        private bool sePidióTodas;

        #endregion

        #region Properties

        public Carta[] Cartas
        {
            get
            {
                return cartasMesa;
            }
        }

        public List<Carta[]>[] Bazas
        {
            get
            {
                return bazas;
            }
        }

        public int[] Piedras
        {
            get
            {
                return piedras;
            }
        }

        #endregion

        #region Methods

        public Mesa()
        {
            baraja = new Baraja();           

            cartasMesa = new Carta[NúmCartasMesa];
            for (int i = 0; i < cartasMesa.Length; i++)
            {
                cartasMesa[i] = null;
            }

            bazas = new List<Carta[]>(MaxCartasBaza)[NúmParejas];
            for (int i = 0; i < bazas.GetLength(0); i++)
            {
                for (int j = 0; j < bazas.GetLength(1); j++)
                {
                    bazas[i, j] = null;
                }
            }

            piedras = new int[2];
            piedras[0] = NúmTotalPiedras / 2;
            piedras[1] = NúmTotalPiedras / 2;
        }

        public void TirarCarta(Jugador jugador, Carta carta)
        {
            cartasMesa[(int)jugador] = carta;
        }

        #endregion
    }
}
