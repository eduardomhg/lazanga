
namespace LaZanga
{
    /// <summary>
    /// Valores de la baraja española (no incluye las cartas 8, 9 y comodín).
    /// </summary>
    enum Valor
    {
        As,
        Dos,
        Tres,
        Cuatro,
        Cinco,
        Seis,
        Siete,
        Sota,
        Caballo,
        Rey
    }

    /// <summary>
    /// Palos de la baraja española.
    /// </summary>
    enum Palo
    {
        Bastos,
        Copas,
        Espadas,
        Oros
    }

    /// <summary>
    /// Representa una carta de la baraja española. No incluye las cartas 8, 9 y comodín.
    /// </summary>
    class Carta
    {
        /// <summary>
        /// Valor de la carta.
        /// </summary>
        private Valor valor;

        /// <summary>
        /// Palo de la carta.
        /// </summary>
        private Palo palo;

        /// <summary>
        /// Valor de la carta.
        /// </summary>
        public Valor Valor
        {
            get;
            set;
        }

        /// <summary>
        /// Palo de la carta.
        /// </summary>
        public Palo Palo
        {
            get;
            set;
        }

        /// <summary>
        /// Constructor de la clase.
        /// </summary>
        /// <param name="valor">El valor de la carta.</param>
        /// <param name="palo">El palo de la carta.</param>
        public Carta(Valor valor, Palo palo)
        {
            this.valor = valor;
            this.palo = palo;
        }
    }
}
