namespace LaZanga
{
    /// <summary>
    /// Clase est�tica que contiene el m�todo Main().
    /// </summary>
    static class Programa
    {
        /// <summary>
        /// Punto de entrada de la aplicaci�n.
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

