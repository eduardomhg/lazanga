using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using TomShane.Neoforce.Controls;
using System;

namespace LaZanga
{
    /// <summary>
    /// Clase principal del juego.
    /// </summary>
    public class JuegoZanga : Game
    {
        /// <summary>
        /// Gestiona y configura los gráficos.
        /// </summary>
        private GraphicsDeviceManager graphics;

        /// <summary>
        /// Gestiona la lógica y el dibujo de los componentes de GUI.
        /// </summary>
        private Manager manager;

        /// <summary>
        /// Pantalla que se muestra en cada instante.
        /// </summary>
        private Pantalla pantallaActual;

        /// <summary>
        /// Constructor de la clase.
        /// </summary>
        public JuegoZanga()
        {
            graphics = new GraphicsDeviceManager(this);
            Content.RootDirectory = @"Content\CartasClásicas";
            graphics.PreferredBackBufferWidth = 1024;
            graphics.PreferredBackBufferHeight = 768;
            graphics.ApplyChanges();

            IsMouseVisible = true;
            IsFixedTimeStep = false;
            Window.Title = "La Zanga";
            

            // Create an instance of manager using Default skin. We set the fourth parameter to true,
            // so the instance of manager is registered as an XNA game component and methods
            // like Initialize(), Update() and Draw() are called automatically in the game loop.
            // If you set this parameter to false, you have to call Manager.Initialize(), 
            // Manager.Update() and Manager.Draw() manually in their respective overriden methods
            // of the game class.
            // If you use two-parameter constructor, Default skin is used and manager is registered.
            manager = new Manager(this, graphics, "Default", true);

            // Setting up the shared skins directory
            manager.SkinDirectory = @"..\..\..\Skins\";
            
        }

        /// <summary>
        /// Allows the game to perform any initialization it needs to before starting to run.
        /// This is where it can query for any required services and load any non-graphic
        /// related content.  Calling base.Initialize will enumerate through any components
        /// and initialize them as well.
        /// </summary>
        protected override void Initialize()
        {
            base.Initialize();

            pantallaActual = new PantallaInicial(manager, graphics, ComenzarNuevoJuego, Salir);    
            pantallaActual.Inicializar();
        }
           

        /// <summary>
        /// LoadContent will be called once per game and is the place to load
        /// all of your content.
        /// </summary>
        protected override void LoadContent()
        {
            Texturas.Tapete = Content.Load<Texture2D>("Tapete");
            Texturas.Trasera = Content.Load<Texture2D>("Trasera");
            Texturas.Baza = Content.Load<Texture2D>("Baza");
            Texturas.Piedra = Content.Load<Texture2D>("Piedra");

            foreach (Valor valor in Enum.GetValues(typeof(Valor)))
            {
                foreach (Palo palo in Enum.GetValues(typeof(Palo)))
                {
                    string fichero = valor.ToString() + palo.ToString();
                    Texturas.AsignarCarta(Content.Load<Texture2D>(fichero), new Carta(valor, palo));
                }
            }
        }

        /// <summary>
        /// Allows the game to run logic such as updating the world,
        /// checking for collisions, gathering input, and playing audio.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Update(GameTime gameTime)
        {

            pantallaActual.Actualizar(gameTime);

            base.Update(gameTime);
        }

        /// <summary>
        /// Esta función se llama cuando el juego se dibuja.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Draw(GameTime gameTime)
        {
            GraphicsDevice.Clear(Color.Black);

            // TODO: Add your drawing code here

            base.Draw(gameTime);
        }

        protected void ComenzarNuevoJuego(object sender, MouseEventArgs e)
        {
            pantallaActual.Finalizar();
            pantallaActual = new PantallaJuego(manager, graphics, Salir);
            pantallaActual.Inicializar();
        }

        protected void Salir(object sender, MouseEventArgs e)
        {
            Exit();
        }
    }
}
