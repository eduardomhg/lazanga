using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using Microsoft.DirectX;
using Microsoft.DirectX.Direct3D;

namespace DeviceTutorial
{
    public partial class CreateDevice : Form
    {
        // Our global variables for this project
        Device device = null; // Our rendering device
        VertexBuffer vertexBuffer = null;

        public CreateDevice()
        {
            // Set the initial size of our form
            this.ClientSize = new System.Drawing.Size(400, 300);
            // And its caption
            this.Text = "D3D Tutorial 01: CreateDevice";
        }

        public bool InitializeGraphics()
        {
            try
            {
                // Now  setup our D3D stuff
                PresentParameters presentParams = new PresentParameters();
                presentParams.Windowed = true;
                presentParams.SwapEffect = SwapEffect.Discard;
                device = new Device(0, DeviceType.Hardware, this,
                        CreateFlags.SoftwareVertexProcessing, presentParams);
                return true;
            }
            catch (DirectXException)
            {
                return false;
            }
        }

        public void Render()
        {
            if (device == null)
                return;

            //Clear the backbuffer to a blue color 
            device.Clear(ClearFlags.Target, System.Drawing.Color.Blue, 1.0f, 0);
            //Begin the scene
            device.BeginScene();

            // New for Tutorial 2
            device.SetStreamSource(0, vertexBuffer, 0);
            device.VertexFormat = CustomVertex.TransformedColored.Format;
            device.DrawPrimitives(PrimitiveType.TriangleList, 0, 1);

            //End the scene
            device.EndScene();
            device.Present();
        }

        public void OnCreateDevice(object sender, EventArgs e)
        {
            Device dev = (Device)sender;

            // Now create the vertex buffer
            vertexBuffer = new VertexBuffer(
                typeof(CustomVertex.TransformedColored), 3, dev, 0,
                CustomVertex.TransformedColored.Format, Pool.Default);
            vertexBuffer.Created +=
                new System.EventHandler(this.OnCreateVertexBuffer);
            this.OnCreateVertexBuffer(vertexBuffer, null);
        }

        public void OnCreateVertexBuffer(object sender, EventArgs e)
        {
            VertexBuffer vb = (VertexBuffer)sender;
            GraphicsStream stm = vb.Lock(0, 0, 0);
            CustomVertex.TransformedColored[] verts =
                new CustomVertex.TransformedColored[3];
            verts[0].X = 150; verts[0].Y = 50; verts[0].Z = 0.5f; verts[0].Rhw = 1;
            verts[0].Color = System.Drawing.Color.Aqua.ToArgb();

            verts[1].X = 250; verts[1].Y = 250; verts[1].Z = 0.5f; verts[1].Rhw = 1;
            verts[1].Color = System.Drawing.Color.Brown.ToArgb();

            verts[2].X = 50; verts[2].Y = 250; verts[2].Z = 0.5f; verts[2].Rhw = 1;
            verts[2].Color = System.Drawing.Color.LightPink.ToArgb();

            stm.Write(verts);
            vb.Unlock();
        }
    }
}