#region Dependancies
using System;
using System.Collections.Generic;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Content;
using SMOCG.Cameras;
#endregion

namespace SMOCG {
    /// <summary>
    /// The static CollisionHelper class is there to help extract out methods for picking / selecting objects
    /// It's used by the Player class help with collision detection and picking with the cards
    /// </summary>
    public static class CollisionHelper {
        /// <summary>
        /// Generate a picking ray to we can select objects etc
        /// </summary>
        /// <param name="camera">A <see cref="BasicCamera">BasicCamera</see> to get the view and projection matricies from</param>
        /// <param name="mx">The mouse x position</param>
        /// <param name="my">The mouse y position</param>
        /// <returns>A ray obtained using the mouse position</returns>
        public static Ray GetPickRay(SMOCGGame game, FreeCamera camera, float mx, float my) {
            Vector3 nearsource = new Vector3((float)mx, (float)my, 0f);
            Vector3 farsource = new Vector3((float)mx, (float)my, 1f);

            Matrix world = Matrix.Identity;

            Vector3 nearPoint = game.GraphicsDevice.Viewport.Unproject(nearsource, camera.Projection, camera.View, world);
            
            Vector3 farPoint = game.GraphicsDevice.Viewport.Unproject(farsource, camera.Projection, camera.View, world);

            // Create a ray from the near clip plane to the far clip plane.
            Vector3 direction = farPoint - nearPoint;
            direction.Normalize();
            return new Ray(nearPoint, direction);
        }

        /// <summary>
        /// Checks whether a ray intersects a model. This method needs to access
        /// the model vertex data, so the model must have been built using the
        /// custom TrianglePickingProcessor provided.
        /// </summary>
        /// <param name="ray">The ray to check against the model</param>
        /// <param name="model">The model to check</param>
        /// <param name="modelTransform">The model's transform (world) matrix</param>
        /// <returns>The distance along the ray to the point of intersection, or null
        /// if there is no intersection</returns>
        public static float? RayIntersectsModel(Ray ray, Model model, Matrix modelTransform){
            Vector3 v1, v2, v3;
            return RayIntersectsModel(ray, model, modelTransform, out v1, out v2, out v3);
        }

        /// <summary>
        /// Checks whether a ray intersects a model. This method needs to access
        /// the model vertex data, so the model must have been built using the
        /// custom TrianglePickingProcessor provided.
        /// </summary>
        /// <param name="ray">The ray to check against the model</param>
        /// <param name="model">The model to check</param>
        /// <param name="modelTransform">The model's transform (world) matrix</param>
        /// <param name="vertex1">Vertex 1 of the selected triangle, if any</param>
        /// <param name="vertex2">Vertex 2 of the selected triangle, if any</param>
        /// <param name="vertex3">Vertex 3 of the selected triangle, if any</param>
        /// <returns>Returns the distance along the ray to the point of intersection, or null
        /// if there is no intersection.</returns>
        public static float? RayIntersectsModel(Ray ray, Model model, Matrix modelTransform,
                                         out Vector3 vertex1, out Vector3 vertex2,
                                         out Vector3 vertex3) {
            vertex1 = vertex2 = vertex3 = Vector3.Zero;

            // The input ray is in world space, but our model data is stored in object
            // space. We would normally have to transform all the model data by the
            // modelTransform matrix, moving it into world space before we test it
            // against the ray. That transform can be slow if there are a lot of
            // triangles in the model, however, so instead we do the opposite.
            // Transforming our ray by the inverse modelTransform moves it into object
            // space, where we can test it directly against our model data. Since there
            // is only one ray but typically many triangles, doing things this way
            // around can be much faster.

            Matrix inverseTransform = Matrix.Invert(modelTransform);

            ray.Position = Vector3.Transform(ray.Position, inverseTransform);
            ray.Direction = Vector3.TransformNormal(ray.Direction, inverseTransform);

            // Look up our custom collision data from the Tag property of the model.
            Dictionary<string, object> tagData = (Dictionary<string, object>)model.Tag;

            if (tagData == null) {
                throw new InvalidOperationException(
                    "Model.Tag is not set correctly. Make sure your model " +
                    "was built using the custom TrianglePickingProcessor.");
            }

            // Start off with a fast bounding sphere test.
            BoundingSphere boundingSphere = (BoundingSphere)tagData["BoundingSphere"];

            if (boundingSphere.Intersects(ray) == null)
            {
                // If the ray does not intersect the bounding sphere, we cannot
                // possibly have picked this model, so there is no need to even
                // bother looking at the individual triangle data.
                return null;
            }
            else
            {
                // The bounding sphere test passed, so we need to do a full
                // triangle picking test.

                // Keep track of the closest triangle we found so far,
                // so we can always return the closest one.
                float? closestIntersection = null;

                // Loop over the vertex data, 3 at a time (3 vertices = 1 triangle).
                Vector3[] vertices = (Vector3[])tagData["Vertices"];

                for (int i = 0; i < vertices.Length; i += 3) {
                    // Perform a ray to triangle intersection test.
                    float? intersection;

                    RayIntersectsTriangle(ref ray,
                                          ref vertices[i],
                                          ref vertices[i + 1],
                                          ref vertices[i + 2],
                                          out intersection);

                    // Does the ray intersect this triangle?
                    if (intersection != null) {
                        // If so, is it closer than any other previous triangle?
                        if ((closestIntersection == null) ||
                            (intersection < closestIntersection)) {
                            // Store the distance to this triangle.
                            closestIntersection = intersection;

                            // Transform the three vertex positions into world space,
                            // and store them into the output vertex parameters.
                            Vector3.Transform(ref vertices[i],
                                              ref modelTransform, out vertex1);

                            Vector3.Transform(ref vertices[i + 1],
                                              ref modelTransform, out vertex2);

                            Vector3.Transform(ref vertices[i + 2],
                                              ref modelTransform, out vertex3);
                        }
                    }
                }

                return closestIntersection;
            }
        }

        /// <summary>
        /// Checks whether a ray intersects a triangle. This uses the algorithm
        /// developed by Tomas Moller and Ben Trumbore, which was published in the
        /// Journal of Graphics Tools, volume 2, "Fast, Minimum Storage Ray-Triangle
        /// Intersection".
        /// 
        /// This method is implemented using the pass-by-reference versions of the
        /// XNA math functions. Using these overloads is generally not recommended,
        /// because they make the code less readable than the normal pass-by-value
        /// versions. This method can be called very frequently in a tight inner loop,
        /// however, so in this particular case the performance benefits from passing
        /// everything by reference outweigh the loss of readability.
        /// </summary>
        /// <param name="ray">The ray to check against the triangle</param>
        /// <param name="vertex1">Vertex 1 of the triangle to check against</param>
        /// <param name="vertex2">Vertex 2 of the triangle to check against</param>
        /// <param name="vertex3">Vertex 3 of the triangle to check against</param>
        /// <param name="result">The distance along the ray until the collision, if any</param>
        public static void RayIntersectsTriangle(ref Ray ray,
                                          ref Vector3 vertex1,
                                          ref Vector3 vertex2,
                                          ref Vector3 vertex3, out float? result) {
            // Compute vectors along two edges of the triangle.
            Vector3 edge1, edge2;

            Vector3.Subtract(ref vertex2, ref vertex1, out edge1);
            Vector3.Subtract(ref vertex3, ref vertex1, out edge2);

            // Compute the determinant.
            Vector3 directionCrossEdge2;
            Vector3.Cross(ref ray.Direction, ref edge2, out directionCrossEdge2);

            float determinant;
            Vector3.Dot(ref edge1, ref directionCrossEdge2, out determinant);

            // If the ray is parallel to the triangle plane, there is no collision.
            if (determinant > -float.Epsilon && determinant < float.Epsilon) {
                result = null;
                return;
            }

            float inverseDeterminant = 1.0f / determinant;

            // Calculate the U parameter of the intersection point.
            Vector3 distanceVector;
            Vector3.Subtract(ref ray.Position, ref vertex1, out distanceVector);

            float triangleU;
            Vector3.Dot(ref distanceVector, ref directionCrossEdge2, out triangleU);
            triangleU *= inverseDeterminant;

            // Make sure it is inside the triangle.
            if (triangleU < 0 || triangleU > 1) {
                result = null;
                return;
            }

            // Calculate the V parameter of the intersection point.
            Vector3 distanceCrossEdge1;
            Vector3.Cross(ref distanceVector, ref edge1, out distanceCrossEdge1);

            float triangleV;
            Vector3.Dot(ref ray.Direction, ref distanceCrossEdge1, out triangleV);
            triangleV *= inverseDeterminant;

            // Make sure it is inside the triangle.
            if (triangleV < 0 || triangleU + triangleV > 1) {
                result = null;
                return;
            }

            // Compute the distance along the ray to the triangle.
            float rayDistance;
            Vector3.Dot(ref edge2, ref distanceCrossEdge1, out rayDistance);
            rayDistance *= inverseDeterminant;

            // Is the triangle behind the ray origin?
            if (rayDistance < 0) {
                result = null;
                return;
            }

            result = rayDistance;
        }
    }
}
