<p align="center">
  <img width="180" height="180" src="minirt_logo.png">
</p>

# miniRT
## Grade: 125
miniRT project is about creating a simple raytracer to produce a realistic render.  
implement such raytracer required us to learn linear algebra and calculus to understand how to perform calculation in 3D space properly and learning to 
the usage of matrices to transform the point in different spaces like World Space, Object Space, Tangent Space and the process of implementing cartesian coordinates system and converting a point in it to different coordinate systems and the usage of vectors to apply
 transformations and the process to solve implict and parametric equations and the process of differentiation.  
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
* Gamma Correction: Ability to control the gamma in the shader
* HDR: Ability to represent colors in high dynamic range then converted to LDR with ACES approximation
* Supersampling: The ability to represent colors in the scene more accuratly by shooting multiple rays for each pixel
# How to use:
First compile the project by running make then run the miniRT executable with an scene provided as argument.
# Scenes
Scenes are defined with .rt extension which contains all the objects to render including their properties, the following is the objects which can be added in the scene and their properties:
## Ambient Light
| ID | Intensity | Color |
| --- | --- | --- |
| A | Float | RGB |
## Camera
| ID | Position | Normal Vector | FOV |
| --- | --- | --- | --- |
| C | Vec3 | Vec3 | Int |
## Point Light
| ID | Position | Intensity | Color |
| --- | --- | --- | --- |
| L | Vec3 | Int | RGB |
## Plane
| ID | Position | Normal Vector | Color |
| --- | --- | --- | --- |
| pl | Vec3 | Vec3 | RGB |
## Sphere
| ID | Position | Radius | Color |
| --- | --- | --- | --- |
| sp | Vec3 | Float | RGB |
## Cylinder
| ID | Position | Normal Vector | Diameter | Height | Color |
| --- | --- | --- | --- | --- | --- |
| cy | Vec3 | Vec3 | Float | Float | RGB |
## Hyperboloid of one sheet
| ID | Position | Scale | Normal Vector | Coefficients | Color |
| --- | --- | --- | --- | --- | --- |
| hy | Vec3 | Vec3 | Vec3 | Vec3 | RGB |
## Misc
All primitvies has miscellaneous properties which can be provided after the required properities which are the following:
| ID | Datatype | Info |
| --- | --- | --- |
| color: | String | Color map to apply |
| bump: | String | Bump map to apply |
| reflect: | Float | Applies reflect with provided intensity |
| phong: | Vec3 | Control the phong shader properties |
# Resources:
* MLX42: https://github.com/codam-coding-college/MLX42
* OpenGL Programming: http://www.opengl-redbook.com/
* The Ray Tracer Challenege: https://pragprog.com/titles/jbtracer/the-ray-tracer-challenge/
* Learn OpenGL: https://learnopengl.com/
* opengl-tutorial: https://www.opengl-tutorial.org/
* Scratchapixel: https://www.scratchapixel.com/
* ACES Filmic Tone Mapping Curve: https://knarkowicz.wordpress.com/2016/01/06/aces-filmic-tone-mapping-curve/
* Writing a Raytracer in Rust Part 3: https://bheisler.github.io/post/writing-raytracer-in-rust-part-3/
* Supersampling: https://en.wikipedia.org/wiki/Supersampling
* Cartesian Coordinate System: https://en.wikipedia.org/wiki/Cartesian_coordinate_system
* Spherical Coordinate System: https://en.wikipedia.org/wiki/Spherical_coordinate_system
* Cylindrical Coordinate System: https://en.wikipedia.org/wiki/Cylindrical_coordinate_system
* 3D Textures: https://3dtextures.me/
* Wolfenstein 3D Texture Library https://www.areyep.com/RIPandMCS-TextureLibrary.html
* Freepik: https://www.freepik.com/
* Planets Texture Maps: https://www.solarsystemscope.com/
* NormalMap Online: https://cpetry.github.io/NormalMap-Online/
# Testing Tools:
* Jupyter: https://jupyter.org/
* Numpy: https://numpy.org/
* ImageIO: https://pypi.org/project/imageio/
* Seaborn: https://seaborn.pydata.org/
* SymPy: https://www.sympy.org/en/index.html
