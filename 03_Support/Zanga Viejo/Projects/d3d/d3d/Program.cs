using System;
using System.Collections.Generic;
using System.Windows.Forms;
using Microsoft.DirectX;
using Microsoft.DirectX.Direct3D;
using DeviceTutorial;

namespace d3d
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            CreateDevice frm = new CreateDevice();
            if (!frm.InitializeGraphics()) // Initialize Direct3D
            {
                MessageBox.Show(
                    "Could not initialize Direct3D.  This tutorial will exit.");
                return;
            }
            frm.Show();

            // While the form is still valid, render and process messages
            while (frm.Created)
            {
                frm.Render();
                Application.DoEvents();
            }
        }
    }
}