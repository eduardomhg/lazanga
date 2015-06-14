#region Dependancies
using System;
using System.Collections.Generic;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Content;
using SMOCG.Cameras;
#endregion

namespace SMOCG
{
    /// <summary>
    /// The DebugLine class is there to draw a line on the screen so you can see where the rays are going
    /// </summary>
    public class DebugLine
    {
        // Vertex array that stores exactly which triangle was picked.
        VertexPositionColor[] _line =
        {
            new VertexPositionColor(Vector3.Zero, Color.Red),
            new VertexPositionColor(Vector3.Zero, Color.Red),
            new VertexPositionColor(Vector3.Zero, Color.Red),
        };

        // Effect and vertex declaration for drawing the picked triangle.
        BasicEffect _lineEffect;
        VertexDeclaration _lineVertexDeclaration;
        GraphicsDevice _gd;

        public DebugLine(GraphicsDevice gd)
        {
            _gd = gd;
            // create the effect and vertex declaration for drawing the
            // picked triangle.
            _lineEffect = new BasicEffect(gd, null);
            _lineEffect.VertexColorEnabled = true;

            _lineVertexDeclaration = new VertexDeclaration(gd, VertexPositionColor.VertexElements);
        }

        public void SetPoints(Vector3 p, Vector3 p2)
        {
            _line[0].Position = p;
            _line[1].Position = p2; // give it a bit of length
            _line[2].Position = p + Vector3.Up; // return to the point of origin
        }

        public void SetPoints(Ray drawRay)
        {
            _line[0].Position = drawRay.Position;
            _line[1].Position = drawRay.Position + ( drawRay.Direction * 50.0f ); // give it a bit of length
            _line[2].Position = drawRay.Position + Vector3.Up; // return to the point of origin
        }

        public void Draw(FreeCamera camera)
        {
            RenderState renderState = _gd.RenderState;

            // Set line drawing renderstates. We disable backface culling
            // and turn off the depth buffer because we want to be able to
            // see the picked triangle outline regardless of which way it is
            // facing, and even if there is other geometry in front of it.
            renderState.FillMode = FillMode.WireFrame;
            renderState.CullMode = CullMode.None;
            renderState.DepthBufferEnable = false;

            // Activate the line drawing BasicEffect.
            _lineEffect.Projection = camera.Projection;
            _lineEffect.View = camera.View;

            _lineEffect.Begin();
            _lineEffect.CurrentTechnique.Passes[0].Begin();

            // Draw the triangle.
            _gd.VertexDeclaration = _lineVertexDeclaration;

            _gd.DrawUserPrimitives(PrimitiveType.TriangleList,
                                      _line, 0, 1);

            _lineEffect.CurrentTechnique.Passes[0].End();
            _lineEffect.End();

            // Reset renderstates to their default values.
            renderState.FillMode = FillMode.Solid;
            renderState.CullMode = CullMode.CullCounterClockwiseFace;
            renderState.DepthBufferEnable = true;
        }
    }
}
