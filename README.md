# learnOpenGL
========
Harry and Mike are trying to learn openGL by installing it, reading tutorials, running code, and revising code. (“OpenGL” does 3D graphics: it is a cross-platform multi-language code library API for controlling computer graphics chips to draw pictures of 3d objects.) Here is what we’ve found so far including links to installers, tutorials, versions, references, etc...


Potential Projects
-----------------
* [Lunar lander](http://www.nasa.gov/multimedia/imagegallery/image_gallery_2104.html) in 3D, as interactive game. (Could it display in red-blue 3d glasses, or virtual reality goggles?)

* [Skydive](http://www.uspa.org) simulator, interactive game. (Virtual reality?)



References 
--------
* Learning [to install opengl and related tools](http://github.com/mroam/learnOpenGL/blob/master/install-opengl.md).

* See our [dictionary](http://github.com/mroam/learnOpenGL/blob/master/dictionary.md) re “What is..” glew, glut, webgl, glm, glfw, etc...

* http://www.opengl.org

* http://en.wikipedia.org/wiki/OpenGL

* [openGL api](http://docs.gl)

* [learnopengl.com](http://learnopengl.com) has nice [pdf version of their tutorial website](http://learnopengl.com/#!Offline-book), using glfw, glew, and cmake, on windows visual studio. (Please donate to them if you find them helpful.)

* See github’s “[MarkDown Basics](http://help.github.com/articles/markdown-basics/)”.

* [McNopper’s sample programs](http://github.com/McNopper), including shading language.

* [Loading file into string](http://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring)

Tutorials
--------
* “[Glitter](http://github.com/Polytonic/Glitter)” is github repo which includes the necessary libraries and instructions for getting started with the [learnopengl.com](http://learnopengl.com) and [open.gl](http://open.gl) tutorials! (Requires only one “dependency”: [cmake](http://www.cmake.org/download/).) ... This is our work in progress but doesn't it need shaders?

* [modern OpenGL with shaders (youtube 3 hour video)](http://youtu.be/6-9XFm7XAT8) from SIGGRAPH!

* http://openglbook.com for *openGL 4* (see preface for hardware and software requirements: book uses [Glew](http://glew.sourceforge.net) and [FreeGlut](http://freeglut.sourceforge.net) (note: “get freeglut version 2.6.0 or higher in order to be able to create an OpenGL 4.0 context”), and explanation that old “glBegin, glEnd, glVertex3f, and glColor3f ... are not present in the OpenGL 4.0 Core Profile. Forget ... ‘immediate mode’ OpenGL ... since it is never coming back.”)

* Highly recommended [open.gl tutorial for openGL 4](http://open.gl) with minimal use of other libraries. (requires SFML, [glfw](http://www.glfw.org/) or SDL for creating the context and handling input; [Glew](http://glew.sourceforge.net) to use newer OpenGL functions; [SOIL](http://www.lonesock.net/soil.html) (or [SOIL2](http://bitbucket.org/SpartanJ/soil2)?) for textures; [glm](http://glm.g-truc.net/) for vectors and matrices.

* [learnopengl.com](http://learnopengl.com) for opengl 3.3+ has nice [pdf version of their tutorial website](http://learnopengl.com/#!Offline-book), using glfw, glew, and cmake on windows visual studio. (Please donate to them if you find them helpful.) They explain that openGL 3.3 and up through 4.5 are all “modern” in terms of using shaders and avoiding old deprecated “immediate” mode.

* http://github.com/opengl-tutorials/ogl (originally at http://www.opengl-tutorial.org/) shows “modern” opengl (version 3.3 and up, which mac 10.9 runs, according to the “[Capabilities](http://developer.apple.com/opengl/capabilities/index.html)” page of [Apple’s OpenGL Info](http://developer.apple.com/library/mac/documentation/GraphicsImaging/Conceptual/OpenGL-MacProgGuide/opengl_intro/opengl_intro.html). Note: as of 2015 oct 28, the first 12 tutorials of http://github.com/opengl-tutorials/ogl “work on mac” (and seem to need [Glew](http://glew.sourceforge.net), [glfw](http://www.glfw.org/), and [glm](http://glm.g-truc.net/) libraries/frameworks).

* [Durian opengl tutorial](http://duriansoftware.com/joe/An-intro-to-modern-OpenGL.-Table-of-Contents.html) with good explanations of pipeline and line-by-line explanation of code (oops, I typed “line-by-lie”) but seems to be using old opengl 2 rather than the 3 or 4 that we’re able to do now.
 
* [Glut Howto](http://web.eecs.umich.edu/~sugih/courses/eecs487/glut-howto/) <- provided us with a [sample.c](http://web.eecs.umich.edu/%7Esugih/courses/eecs487/glut-howto/sample.c) that worked on mac osX 10.10 in xcode 7! (Uses GLUT code deprecated since osX 10.9.) 

* (more are listed and described at http://www.opengl.org/wiki/Getting_Started#Tutorials_and_How_To_Guides )


To Do
--------
* Continue trying to use the mere source from learnopengl.com, which uses glew and glfw, and won't compile on mac xcode. (see glitter2) We have used http://learnopengl.com to add shaders and objects to our Glitter work in progress, and it compiles but nothing appears on our grey screen. ("Vertex shader compilation status: 1 (ok); Fragment shader compilation status: 1 (ok); DANG!--Linking of Shaders failed. ERROR: Compiled vertex shader was corrupt. ERROR: Compiled fragment shader was corrupt.")

* Is there any hope (or need?) of finding tutorials that don’t use or [glfw](http://www.glfw.org/ and http://learnopengl.com), [Glew](http://glew.sourceforge.net), or [glm](http://glm.g-truc.net/), or [FreeGlut](http://freeglut.sourceforge.net), etc.?

* Figure out the file size bug [Here's a link to something!](http://superuser.com/questions/382120/mac-os-x-not-reporting-directory-sizes-correctly)


Questions
--------
* Can we make cross-platform standalone apps that include everything they need? (glew, glut, x11/xQuartz, or whatever else so that users don’t have to download things we depend upon?? (Isn’t this about “static linking” and/or/versus “installing”??)

* For portability, maybe we should look into “[WebGL](http://www.khronos.org/webgl/)”? (“plugin-free 3D for the web, implemented right in the browser. Major browser vendors Apple (Safari), Google (Chrome), Mozilla (Firefox), and Opera (Opera) are members of the WebGL Working Group.”—http://www.khronos.org/webgl/) (What are limitations of webGL, and its foundation “openGL ES” for mobile devices?) 

* Should we use Eclipse or (mac-only) Xcode? If we use Eclipse, don’t we have to set up separate Eclipse copies for Java and C++?

* Java? C++? (mac only?) Swift? Python?

* What physics systems play nice with opengl? Do we want to build our own? (Note: the “[learnopengl.com](http://learnopengl.com)” website’s author answers a question about picking an onscreen object by saying “(see) [http://www.opengl-tutorial.org...](http://www.opengl-tutorial.org/miscellaneous/clicking-on-objects/picking-with-a-physics-library/) the open source physics library [BulletPhysics](http://bulletphysics.org/) (an amazing library) is used for collision detection in the project.”

* Since openGL just draws pictures (“render”) and does not keep track of where our 3d objects are, how best should we keep track of what objects we’re using and where they are and how they are moving? Perhaps through a physics engine? (see note above.) (“OpenGL is a rendering library. What OpenGL does not do is retain information about an “object.” All OpenGL sees is a ball of triangles and a bag of state with which to render them. It does not remember that you drew a line in one location and a sphere in another.” —http://www.opengl.org/wiki/Getting_Started )


Done
----------
* (√) make our xcode glitter project's main.cpp ALMOST match the glfw demo from http://learnopengl.com

* (√) copied “[Glitter](http://github.com/Polytonic/Glitter)” tutorial and used cmake to make Glitter have an xcode project which compiled and ran (after a few changes, see its readme).

* (√) Installed “[cmake](http://www.cmake.org/download/)” on our main machine so that the “[Glitter](http://github.com/Polytonic/Glitter)” tutorial can build xcode projects for us.
 
* (√) Installed xquartz 2.7.8 on our main machine. ([xquartz latest releases](http://xquartz.macosforge.org/trac/wiki/Releases) as of nov 2015, “works with el capitan (osX 10.11)” supposedly.)

* (√) The harrygla xcode project folder is happy with github.

