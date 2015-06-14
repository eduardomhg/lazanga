namespace LaZanga
{
    /// <summary>
    /// Clase estática que contiene el método Main().
    /// </summary>
    static class Programa
    {
        /// <summary>
        /// Punto de entrada de la aplicación.
        /// </summary>
        static void Main(string[] args)
        {            
            using (JuegoZanga juego = new JuegoZanga())
            {
                juego.Run();
            }
        }
    }
}

