#region Dependancies
using System;
using System.Collections.Generic;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
#endregion

namespace SMOCG.Cameras {
    /// <summary>
    /// the BasicCamera provides a way of viewing objects at (0, 0, 0) without the
    /// need to pan or tilt. can be typically used for viewing menu screens etc
    /// </summary>
    public class BasicCamera {
        private Matrix _projection; // the camera's projection matrix
        private Matrix _view; // the camera's view matrix
        private Vector3 _cameraPos; // the camera's position

        private float _fov; // the camera's field of view
        private float _aspectRatio; // the camera's aspect ratio
        private float _nearPlane; // the camera's near plane
        private float _farPlane; // the camera's far plane

        private bool _mustCalculate = true; // whether to recalculate the view matrix or not

        #region Properties
        /// <summary>
        /// get the projection matrix
        /// </summary>
        public Matrix Projection {
            get {  return _projection;  }
            set { _projection = value; }
        }

        /// <summary>
        /// get the view matrix
        /// </summary>
        public Matrix View {
            get {
                CalculateViewMatrix();
                return _view; 
            }
            set { _view = value; }
        }

        /// <summary>
        /// get and set the camera's position
        /// </summary>
        public Vector3 CameraPosition {
            get {  return _cameraPos; }
            set {
                _cameraPos = value;
                _mustCalculate = true;
            }
        }
        /// <summary>
        /// Get and set the camera's field of view
        /// </summary>
        public float FOV {
            get { return _fov; }
            set { 
                _fov = value;
                CreateProjMatrix();
            }
        }

        /// <summary>
        /// Get and set the camera's aspect ratio
        /// </summary>
        public float AspectRatio {
            get { return _aspectRatio; }
            set {
                _aspectRatio = value;
                CreateProjMatrix();
            }
        }

        /// <summary>
        /// Get and set the camera's near plane
        /// </summary>
        public float NearPlane {
            get { return _nearPlane; }
            set {
                _nearPlane = value;
                CreateProjMatrix();
            }
        }

        /// <summary>
        /// Get and set the camera's far plane
        /// </summary>
        public float FarPlane {
            get { return _farPlane; }
            set {
                _farPlane = value;
                CreateProjMatrix();
            }
        }

        /// <summary>
        /// Get and set the must calculate bool - whether to recalculate the view matrix or not
        /// </summary>
        public bool MustCalculate {
            get { return _mustCalculate; }
            set { _mustCalculate = value; }
        }
        #endregion

        /// <summary>
        /// Constructor - hold the different values given, and create a projection matrix based on it
        /// </summary>
        /// <param name="pos">The position of the camera</param>
        /// <param name="fov">The field of view of the camera</param>
        /// <param name="aspectRatio">The aspect ratio of the camera</param>
        /// <param name="nearPlane">The near plane of the camera</param>
        /// <param name="farPlane">The far plane of the camera</param>
        public BasicCamera(Vector3 pos, float fov, float aspectRatio, float nearPlane, float farPlane) {
            this._cameraPos = pos; // set the camera's position and create the view matrix

            this._fov = fov;
            this._aspectRatio = aspectRatio;
            this._nearPlane = nearPlane;
            this._farPlane = farPlane;
            CreateProjMatrix(); // create the projection matrix
        }

        /// <summary>
        /// Create the projection matrix
        /// </summary>
        private void CreateProjMatrix() {
            this._projection = Matrix.CreatePerspectiveFieldOfView(this._fov, this._aspectRatio, this._nearPlane, this._farPlane);
        }

        /// <summary>
        /// Calculate the view matrix
        /// </summary>
        protected virtual void CalculateViewMatrix() {
            if (this._mustCalculate) {
                this._view = Matrix.CreateLookAt(_cameraPos, Vector3.Zero, Vector3.Up);
                this._mustCalculate = false;
            }
        }
    }
}
