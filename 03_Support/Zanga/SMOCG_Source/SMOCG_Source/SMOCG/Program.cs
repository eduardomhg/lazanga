using System;

namespace SMOCG {
    static class Program {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        static void Main(string[] args) {
            using (SMOCGGame game = new SMOCGGame()) {
                game.Run();
            }
        }
    }
}

