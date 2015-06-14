using Microsoft.Xna.Framework;
using TomShane.Neoforce.Controls;

namespace LaZanga
{
    /// <summary>
    /// Representa una pantalla del juego.
    /// </summary>
    abstract class Pantalla
    {

        /// <summary>
        /// Manager que gestiona los controles GUI.
        /// </summary>
        private Manager manager;

        /// <summary>
        /// Propiedad para acceder al manager desde clases derivadas.
        /// </summary>
        protected Manager Manager
        {
            get
            {
                return manager;
            }
        }

        /// <summary>
        /// Constructor de la clase.
        /// </summary>
        /// <param name="manager">Manager que gestiona los controles GUI.</param>
        public Pantalla(Manager manager)
        {
            this.manager = manager;
        }

        /// <summary>
        /// Inicializa la pantalla.
        /// </summary>
        public virtual void Inicializar()
        {
        }

        /// <summary>
        /// Actualiza el estado de la pantalla
        /// </summary>
        public virtual void Actualizar(GameTime gameTime)
        {
        }

        /// <summary>
        /// Finaliza la pantalla.
        /// </summary>
        public virtual void Finalizar()
        {
        }
    }
}

