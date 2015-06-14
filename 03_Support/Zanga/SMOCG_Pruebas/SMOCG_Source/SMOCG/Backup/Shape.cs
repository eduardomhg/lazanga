#region Dependancies
using System;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
#endregion

namespace SMOCG {
    /// <summary>
    /// A Shape represents a renderable 3d mesh and is typically contained in a <see cref="GameObject">GameObject</see>
    /// </summary>
    public class Shape {
        private Model _model = null; // the actual model being drawn

        private Matrix _world; // the world matrix that this shape uses to render
        private Matrix _view; // the view matrix for this shape
        private Matrix _proj; // the projection matrix for this shape

        private bool _worldIsSet = false; // has the world matrix been set?
        private bool _viewIsSet = false; // has the view matrix been set?
        private bool _projIsSet = false; // has the projection matrix been set?

        private Texture2D _texture = null; // the texture used by this shape, if any
        private bool _hasTexture = false; // has this shape a texture? false by default

        private Vector3 _ambient = Color.DarkSlateGray.ToVector3(); // the ambient color of this shape
        private Vector3 _diffuse = Color.White.ToVector3(); // the diffuse color of this shape
        private Vector3 _specular = Color.White.ToVector3(); // the specular color of this shape
        private float _specularPower = 10.0f; // the specular power of this shape

        private bool _usePerPixelLighting = false; // use per pixel lighting for this shape?
        private float _alpha = 1.0f; // set the alpha value

        #region Get Set Properties
        /// <summary>
        /// Set the shape's model
        /// </summary>
        public Model Model {
            get { return _model; }
            set { _model = value; }
        }

        /// <summary>
        /// The world matrix that this shape uses to render
        /// </summary>
        public Matrix World {
            get { return _world; }
            set { _world = value; _worldIsSet = true; }
        }

        /// <summary>
        /// Set the view matrix for this shape
        /// </summary>
        public Matrix View {
            set { _view = value; _viewIsSet = true; }
        }

        /// <summary>
        /// set the projection matrix for this shape
        /// </summary>
        public Matrix Proj {
            set { _proj = value; _projIsSet = true; }
        }

        /// <summary>
        /// Set the texture that this shape uses
        /// </summary>
        public Texture2D Texture {
            get { return _texture; }
            set { _texture = value; _hasTexture = true;  }
        }

        /// <summary>
        /// Set whether the shape has a texture or not. Default is false
        /// </summary>
        public bool HasTexture {
            get { return _hasTexture; }
            set { _hasTexture = value; }
        }

        /// <summary>
        /// Set the ambient color for this shape. default is dark grey
        /// </summary>
        public Color Ambient {
            get { return new Color(_ambient); }
            set { _ambient = value.ToVector3(); }
        }

        /// <summary>
        /// Set the diffuse color for this shape. default is white
        /// </summary>
        public Color Diffuse {
            get { return new Color(_diffuse); }
            set { _diffuse = value.ToVector3(); }
        }

        /// <summary>
        /// Set the specular color for this shape. default is white
        /// </summary>
        public Color Specular {
            get { return new Color(_specular); }
            set { _specular = value.ToVector3(); }
        }

        /// <summary>
        /// Set the specular power for this shape. default is 10.0f
        /// </summary>
        public float SpecularPower {
            set { _specularPower = value; }
        }

        /// <summary>
        /// Set whether to use per-pixel lighting or not. default is false
        /// </summary>
        public bool UsePerPixelLighting {
            set { _usePerPixelLighting = value; }
        }

        /// <summary>
        /// Set the alpha value for the shape. default is 1.0f
        /// </summary>
        public float Alpha {
            set { _alpha = value; }
        }
        #endregion

        /// <summary>
        /// renders the shape based on it's settings
        /// </summary>
        public void Render() {
            // do nothing if none of the matrices have been set
            if (this._worldIsSet && this._viewIsSet && this._projIsSet && this._model != null) {

                // turn on alpha blending if the alpha is less than 1.0f
                if (this._alpha < 1.0f)
                    SMOCGGame.Graphics.GraphicsDevice.RenderState.AlphaBlendEnable = true;

                foreach (ModelMesh mesh in this._model.Meshes) {
                    foreach (BasicEffect be in mesh.Effects) {
                        be.EnableDefaultLighting();                             // enable default lighting
                        be.PreferPerPixelLighting = this._usePerPixelLighting;  // use per pixel lighting if the shape wants it
                        be.Projection = this._proj;                             // set the effects projection matrix
                        be.View = this._view;                                   // set the effects view matrix
                        be.World = this._world;                                 // set the effects world matrix
                        be.AmbientLightColor = this._ambient;                   // set the effects ambient color
                        be.DiffuseColor = this._diffuse;                        // set the effects diffuse color
                        be.SpecularColor = this._specular;                      // set the effects specular color
                        be.SpecularPower = this._specularPower;                 // set the effects specular power
                        be.Alpha = this._alpha;                                 // set the effects alpha
                        if (this._hasTexture) {                                 // if there's a texture to be put on the shape
                            be.Texture = this._texture;                         // set the effects texture
                            be.TextureEnabled = true;                           // enable it
                        }
                    }
                    mesh.Draw(); // draw the mesh
                }

                // turn off alpha blending again
                if (this._alpha < 1.0f)
                    SMOCGGame.Graphics.GraphicsDevice.RenderState.AlphaBlendEnable = false;
            }
        }
    }
}
