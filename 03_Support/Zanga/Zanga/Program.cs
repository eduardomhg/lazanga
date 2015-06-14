using System;

namespace Zanga
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        static void Main(string[] args)
        {
            using (JuegoZanga zanga = new JuegoZanga())
            {
                zanga.Run();
            }
        }
    }
}

