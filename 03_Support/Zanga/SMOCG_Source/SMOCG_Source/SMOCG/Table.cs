#region Dependancies
using System;
using System.Collections.Generic;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using SMOCG.Cameras;
#endregion

namespace SMOCG {
    /// <summary>
    /// A Table inherits from <see cref="GameObject">GameObject</see> and represents the in-game gaming table
    /// </summary>
    public class Table : GameObject {
        private float _angle = 0.0f; // temp angle used for rotating the table

        private static int _MAX_NUM_STOOLS = SMOCGGame.Settings.MaxPlayers; // the maximum number of stools around the table

        private List<Stool> _stools = new List<Stool>(_MAX_NUM_STOOLS); // some stools to be placed around the table (max 5)
        private int _numStools = 0; // the number of stools to place around the table
        private float _stoolDist = 12.5f; // the distance out from the center of the table

        #region GetSet Parameters

        /// <summary>
        /// Get and set the camera for the table and stools
        /// </summary>
        public override BasicCamera Camera {
            get { return base.Camera; }
            set { 
                base.Camera = value;
                foreach (Stool s in this._stools)
                    s.Camera = value; // set the stools camera
            }
        }

        #endregion

        /// <summary>
        /// Constructor. Creates a table with a position, rotation, texture, and scale
        /// </summary>
        /// <param name="game">A reference to the main game object</param>
        /// <param name="camera">The camera viewing the table</param>
        /// <param name="pos">The position of the table</param>
        /// <param name="rotation">The rotation of the table - used to correctly orient when importing the model</param>
        /// <param name="scale">The scale of the table</param>
        /// <param name="name">The name of the model to load in</param>
        /// <param name="texture">The texture used by the table</param>
        /// <param name="numStools">The number of stools to have around the table</param>
        public Table(SMOCGGame game, BasicCamera camera, Vector3 pos, Vector3 rotation, Vector3 scale, string name, string texture, int numStools)
            : base(game, pos, rotation, scale, name, texture) 
        {
            this.Camera = camera; // hold the camera reference

            this.Shape.Diffuse = Color.BurlyWood; // assign the table's diffuse color
            this.Shape.Ambient = Color.Sienna; // assign the table's ambient color
            this.Shape.Specular = Color.Tan; // assign the table's specular color
            this.Shape.UsePerPixelLighting = true; // prefer per-pixel lighting

            this._numStools = numStools; // set the number of stools around the table
            MathHelper.Clamp(this._numStools, 0, _MAX_NUM_STOOLS);// confine if if necessary

            for (int i = 0; i < numStools; i++) {
                //create the stools
                this._stools.Add(new Stool(this.Game,                                           // pass the reference to the main game object
                                            this.Camera,                                         // the camera viewing the stool
                                            Vector3.Zero,                                       // position
                                            new Vector3(MathHelper.PiOver2, 0.0f, 0.0f),    // rotation - used to correctly orient the model after loading
                                            this.Scale,                                     // scale
                                            SMOCGGame.Settings.ModelLoadPath + "stool"));    // model load path
            }

            ArrangeStools();
        }

        /// <summary>
        /// Arrange the stools in a circle around the table
        /// </summary>
        private void ArrangeStools() {
            //create the stools
            for (int i = 0; i < this._numStools; i++) {
                float angle = -(MathHelper.TwoPi / this._numStools) * i; // spread the stools around the table in circle
                //the stool's position based on it's number
                Vector3 stoolPos = new Vector3(((float)Math.Sin(angle) * (this._stoolDist * this.Scale.X)),
                                                -3.0f * this.Scale.Y,
                                                ((float)Math.Cos(angle) * (this._stoolDist * this.Scale.Z)));

                this._stools[i].Position = stoolPos;
                this._stools[i].Angle = angle; // store the chair's angle around the table
                this._stools[i].Shape.Diffuse = SMOCGGame.Settings.PlayerColors[i];
            }
        }

        /// <summary>
        /// create a new stool
        /// </summary>
        public void AddStool() {
            //create the stools
            lock(this._stools)
                this._stools.Add(new Stool(this.Game,                        // pass the reference to the main game object
                                            this.Camera,                                    // the camera viewing the stool
                                            Vector3.Zero,                                   // position
                                            new Vector3(MathHelper.PiOver2, 0.0f, 0.0f),    // rotation - used to correctly orient the model after loading
                                            this.Scale,                                     // scale
                                            SMOCGGame.Settings.ModelLoadPath + "stool"));    // model load path
            this._numStools++;
            ArrangeStools(); // arrange the stools again
        }

        /// <summary>
        /// Remove a stool from around the table
        /// </summary>
        /// <param name="i">the stool to remove</param>
        public void RemoveStool(int i) {
            lock (this._stools) {
                if(this._stools.Count > i)
                    this._stools.RemoveAt(i); // remove the stool
            }
            this._numStools--;
            this.ArrangeStools(); // arrange the stools again
        }

        /// <summary>
        /// Get a chair position for sitting down in
        /// </summary>
        /// <param name="i">the chair position to return</param>
        /// <returns>The chair position, or Vector3.Zero if no stool exists</returns>
        public Vector3 GetChairPosition(int i) {
            if (i >= this._stools.Count)
                return Vector3.Zero;
            else
                return this._stools[i].Position + new Vector3(0.0f, 10.0f, 0.0f) * this.Scale;
        }

        /// <summary>
        /// Get a chairs angle around the table (z position) so the player can be rotated to face the center
        /// </summary>
        /// <param name="i">The chair angle to return</param>
        /// <returns>The chair angle, or 0.0f if no stool exists</returns>
        public Vector3 GetChairAngle(int i) {
            if (i >= this._stools.Count)
                return Vector3.Zero;
            else
                return new Vector3(0.0f, this._stools[i].Angle, 0.0f);
        }

        /// <summary>
        /// Update the model's matrices, and calls updates on any stools the table has
        /// </summary>
        /// <param name="deltaTime">The time since the last call to Update()</param>
        public override void Update(TimeSpan deltaTime) {
            this._angle += 1.0f * (float)deltaTime.TotalSeconds;

            this.Shape.View = this.Camera.View;
            this.Shape.Proj = this.Camera.Projection;
            this.Shape.World = Matrix.CreateScale(this.Scale) *
                                Matrix.CreateRotationX(this.Rotation.X) *
                                Matrix.CreateTranslation(this.Position);

            //update the stools
            lock(this._stools)
                for (int i = 0; i < this._numStools; i++)
                    this._stools[i].Update(deltaTime);
        }

        /// <summary>
        /// Draw the table and it's stools
        /// </summary>
        public override void Render() {
            this.Shape.Render();

            //draw the stools
            lock(this._stools)
                foreach(Stool s in this._stools)
                    s.Render();
        }
    }
}
