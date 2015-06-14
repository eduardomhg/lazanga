#region Dependancies
using System;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using SMOCG.Cameras;
#endregion

namespace SMOCG {
    /// <summary>
    /// A Stool inherits from <see cref="GameObject">GameObject</see> and represents a player's seat around a table
    /// </summary>
    public class Stool : GameObject {
        private float _angle = 0.0f; // temp rotation angle
        private float _angleToTable = 0.0f; // the angle to the center of the table - used to rotate the players

        private static Model _model;
        private static bool _modelLoaded = false;

        /// <summary>
        /// Get and set the angle of the stool to the center of the table (in terms of z position only) - used to rotate the players so they face the center
        /// </summary>
        public float Angle {
            get { return _angleToTable; }
            set { _angleToTable = value; }
        }

        /// <summary>
        /// Constructor. Create a stool with a position, rotation and scale
        /// </summary>
        /// <param name="game">A reference to the main game object</param>
        /// <param name="camera">The camera viewing the stool</param>
        /// <param name="pos">Where to position the stool</param>
        /// <param name="rotation">The rotation of the stool - used to correctly orient when importing the model</param>
        /// <param name="scale">The scale of the model</param>
        /// <param name="name">The name of the model to load</param>
        public Stool(SMOCGGame game, BasicCamera camera, Vector3 pos, Vector3 rotation, Vector3 scale, string name)
            : base(game, pos, rotation, scale) // call the constructor for GameObject
        {
            // use the same model for the stool
            if (!_modelLoaded) {
                _model = game.ContentManager.Load<Model>(name); // load in the model
                _modelLoaded = true;
            }
            this.Shape.Model = _model;

            this.Camera = camera; // hold the camera reference

            this.Shape.UsePerPixelLighting = true; // turn on per pixel lighting for this model
            this.Shape.Ambient = Color.Black; // set the ambient color to black
            this.Shape.Diffuse = Color.DarkSlateGray; // set the diffuse color for the shape
            this.Shape.SpecularPower = 50.0f; // set the specular color for the shape
        }

        /// <summary>
        /// Update the model's world position
        /// </summary>
        /// <param name="deltaTime">The time since the last call to update()</param>
        public override void Update(TimeSpan deltaTime) {
            this._angle += 1.0f * (float)deltaTime.TotalSeconds; // increase the angle, so the model rotates
            //set the shape's world matrix
            this.Shape.View = this.Camera.View;
            this.Shape.Proj = this.Camera.Projection;
            this.Shape.World = Matrix.CreateScale(this.Scale) *
                                Matrix.CreateRotationX(this.Rotation.X) *
                                Matrix.CreateTranslation(this.Position); /*
                                Matrix.CreateRotationY(this._angle);*/
        }
    }
}
