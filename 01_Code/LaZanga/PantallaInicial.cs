using Microsoft.Xna.Framework;
using TomShane.Neoforce.Controls;

namespace LaZanga
{
    /// <summary>
    /// Pantalla inicial del juego. Esta pantalla se muestra cuando el usuario ejecuta la aplicación y
    /// le permite elegir entre los diferentes modos de juego.
    /// </summary>
    class PantallaInicial : Pantalla
    {
        #region Constants

        /// <summary>
        /// Altura de los botones, en porcentaje respecto a la altura de la ventana.
        /// </summary>
        private const int AlturaBotónPct = 20;

        /// <summary>
        /// Anchura de los botones, en porcentaje respecto a la anchura de la ventana.
        /// </summary>
        private const int AnchuraBotónPct = 20;

        /// <summary>
        /// Espacio vertical entre los botones, en porcentaje respecto a la altura de la ventana.
        /// </summary>
        private const int EspacioEntreBotonesPct = 5;

        /// <summary>
        /// Texto que se muestra dentro del botón de Nuevo Juego.
        /// </summary>
        private const string TextoNuevoJuego = "Nueva Partida";

        /// <summary>
        /// Texto que se muestra dentro del botón de Salir.
        /// </summary>
        private const string TextoSalir = "Salir";

        #endregion

        #region Fields

        /// <summary>
        /// Botón de Nuevo Juego. Este botón permite al usuario iniciar una nueva
        /// partida.
        /// </summary>
        private Button botónNuevoJuego;

        /// <summary>
        /// Botón de Salir. Este botón permite al usuario salir de la aplicación.
        /// </summary>
        private Button botónSalir;

        #endregion

        /// <summary>
        /// Constructor de la pantalla.
        /// </summary>
        /// <param name="manager">Manager que gestiona el GUI.</param>
        /// <param name="graphics">GraphicsDeviceManager que gestiona los gráficos.</param>
        /// <param name="handlerNuevoJuego">Función que se ejecuta cuando se presiona el botón Nuevo Juego.</param>
        /// <param name="handlerSalir">Función que se ejecuta cuando se presiona el botón Salir.</param>
        public PantallaInicial(Manager manager, GraphicsDeviceManager graphics, 
                               MouseEventHandler handlerNuevoJuego, 
                               MouseEventHandler handlerSalir) 
            : base(manager)
        {
            // Calculamos tamaño de la pantalla (ventana de windows).
            int AlturaPantalla = graphics.PreferredBackBufferHeight;
            int AnchuraPantalla = graphics.PreferredBackBufferWidth;

            // Calculamos el tamaño y el espaciado de los botones.
            int AlturaBotón = AlturaPantalla * AlturaBotónPct / 100;
            int AnchuraBotón = AnchuraPantalla * AnchuraBotónPct / 100;
            int EspacioEntreBotones = AlturaPantalla * EspacioEntreBotonesPct / 100;

            // Creamos el botón de Nuevo Juego.
            botónNuevoJuego = new Button(manager);
            botónNuevoJuego.Width = AnchuraBotón;
            botónNuevoJuego.Height = AlturaBotón;
            botónNuevoJuego.Left = (AnchuraPantalla / 2) - (AnchuraBotón / 2);
            botónNuevoJuego.Top = (AlturaPantalla / 2) - AlturaBotón - (EspacioEntreBotones / 2);
            botónNuevoJuego.Text = TextoNuevoJuego;
            botónNuevoJuego.MousePress += new MouseEventHandler(handlerNuevoJuego);

            // Creamos el botón de Salir.
            botónSalir = new Button(manager);
            botónSalir.Width = AnchuraBotón;
            botónSalir.Height = AlturaBotón;
            botónSalir.Left = (AnchuraPantalla / 2) - (AnchuraBotón / 2);
            botónSalir.Top = (AlturaPantalla / 2) + (EspacioEntreBotones / 2);
            botónSalir.Text = TextoSalir;
            botónSalir.MousePress += new MouseEventHandler(handlerSalir);
        }

        /// <summary>
        /// Inicializa la pantalla. 
        /// </summary>
        public override void Inicializar()
        {
            // Añadimos los botones al manager.
            Manager.Add(botónNuevoJuego);
            Manager.Add(botónSalir);
        }

        /// <summary>
        /// Finaliza la pantalla. 
        /// </summary>
        public override void Finalizar()
        {
            // Quitamos los botones del manager.            
            Manager.Remove(botónNuevoJuego);
            Manager.Remove(botónSalir);
        }
    }
}
