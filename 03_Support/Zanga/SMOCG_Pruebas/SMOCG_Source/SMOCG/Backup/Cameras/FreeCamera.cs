#region Dependancies
using System;
using System.Collections.Generic;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
#endregion

namespace SMOCG.Cameras {
    /// <summary>
    /// FreeCamera inherits from <see cref="BasicCamera">BasicCamera</see> and can be moved around and follow a target
    /// </summary>
    public class FreeCamera : BasicCamera {
        private float _verticalRot = 0.0f; // vertical rotation in radians
        private float _horizontalRot = 0.0f; // horizontal rotation in radians
        private Vector3 _target; // where the camera is aimed at
        private float _eyeDist = 0.0f; // the eye dist(to target)

        /// <summary>
        /// Change the vertical rotation on the FreeCamera. rotation is confined
        /// </summary>
        public float VerticalRotation {
            get { return this._verticalRot; }
            set {
                if (value != this._verticalRot) {
                    this._verticalRot = value;

                    float downlimit = -MathHelper.ToRadians(60.0f);
                    float uplimit = MathHelper.ToRadians(60.0f);

                    this._verticalRot = MathHelper.Clamp(this._verticalRot, downlimit, uplimit);
                }
            }
        }

        /// <summary>
        /// Change the horizontal rotation on the FreeCamera
        /// </summary>
        public float HorizontalRotation {
            get { return _horizontalRot; }
            set {
                if (value != this._horizontalRot)
                    this._horizontalRot = value;
            }
        }

        /// <summary>
        /// Get and set the target of the FreeCamera
        /// </summary>
        public Vector3 Target {
            get { return _target; }
            set { 
                _target = value;
                this._eyeDist = (this.CameraPosition - this._target).Length(); // hold the eye distance
                this.MustCalculate = true;
            }
        }

        /// <summary>
        /// Create a free camera with a position, target, field of view, aspect ratio, near plane, and far plane
        /// </summary>
        /// <param name="pos">Where the camera is placed</param>
        /// <param name="target">What the camera is looking at</param>
        /// <param name="fov">The field of view of the camera</param>
        /// <param name="aspect">The aspect ratio of the camera</param>
        /// <param name="near">The near plane of the camera</param>
        /// <param name="far">The far plane of the camera</param>
        public FreeCamera(Vector3 pos, Vector3 target, float fov, float aspect, float near, float far)
            : base(pos, fov, aspect, near, far) // call the base constructor
        {
            this._target = target;
        }

        /// <summary>
        /// Pan the camera vertically
        /// </summary>
        /// <param name="radians">How much (in radians) to pan it</param>
        public void PanVertically(float radians) {
            if (radians != 0.0f)
            {
                this.VerticalRotation += radians;
                this.MustCalculate = true;
            }
        }

        /// <summary>
        /// Pan the camera horizontally
        /// </summary>
        /// <param name="radians">How much (in radians) to pan it</param>
        public void PanHorizontally(float radians) {
            if (radians != 0.0f)
            {
                this.HorizontalRotation += radians;
                this.MustCalculate = true;
            }
        }

        /// <summary>
        /// Calculate the view matrix - overridden from the base method
        /// </summary>
        protected override void  CalculateViewMatrix(){
            if (this.MustCalculate == true) {
                float cs = (float)Math.Cos(_horizontalRot); // hold the cos of the xAngle
                float sn = (float)Math.Sin(_horizontalRot); // hold the sin of the xAngle
                float cs2 = (float)Math.Cos(_verticalRot); // hold the cos of the -yAngle
                float sn2 = (float)Math.Sin(_verticalRot); // hold the sin of the -yAngle

                this._target.X = (cs * cs2) * this._eyeDist + this.CameraPosition.X;
                this._target.Y = sn2 * this._eyeDist + this.CameraPosition.Y;
                this._target.Z = (sn * cs2) * this._eyeDist + this.CameraPosition.Z;

                // view matrix compilation
                this.View = Matrix.CreateLookAt(
                    this.CameraPosition,
                    this._target,
                    Vector3.Up
                    );

                // reset the bool
                this.MustCalculate = false;
            }
        }
    }
}
