<p align="center">
  <img width="180" height="180" src="minirt_logo.png">
</p>

# miniRT
## Grade: N/A
miniRT project is about creating a simple raytracer to produce a realistic render.  
Implementing such raytracer required us to learn linear algebra and calculus to understand how to perform calculation in 3D space properly and learn 
the usage of matrices to transform the point in different spaces like World Space, Object Space, Tangent Space and the usage of vectors to apply
 transformations and how to solve implict and parametric equations and the process of differentiation.  
Our raytracer supports wide ranges of features:  
* Primitives: Support of multiple primitives with full control of their transformations and their properties.
* Light Managment: The managment of multiple point lights from specific position, intensity and color.
* Shadows: The support of hard shadows by checking if an object is covering a light source.
* Scene Management: Support for providing a file with information of the scene to render.
* Phong shading: The simulation of light reflection and the distribution of light with phong shading model based on the normal vector.
* UV Mapping: An accurate support for texture mapping on primitives.
* Bump Mapping: The support for perturbing the normal vectors of a surface to simulate the look of uneven surface.
* Reflection: The support of reflective surface with recursive ray intersections.
* Field of view (FOV): Implementation of fov to control the focal length of the camera.
# Resources:
* OpenGL Programming: http://www.opengl-redbook.com/
* The Ray Tracer Challenege: https://pragprog.com/titles/jbtracer/the-ray-tracer-challenge/
* Learn OpenGL: https://learnopengl.com/
* opengl-tutorial: https://www.opengl-tutorial.org/
* Scratchapixel: https://www.scratchapixel.com/
