# learnOpenGL
========
Harry and Mike are trying to learn openGL by installing it, reading tutorials, running code, and revising code. (”OpenGL“ is a code library for controlling multi-platform computer graphics chips to draw pictures of 3d objects.)


Potential Projects
-----------------
* Lunar lander in 3D

* Skydive simulator



References 
--------
* Learning [to install opengl and related tools](http://github.com/mroam/learnOpenGL/blob/master/install-opengl.md).

* See our [dictionary](http://github.com/mroam/learnOpenGL/blob/master/dictionary.md) re “What is..” glew, glut, webgl, glm, glfw, etc...

* http://www.opengl.org

* http://en.wikipedia.org/wiki/OpenGL

* [openGL api](http://docs.gl)

* See github’s “[MarkDown Basics](http://help.github.com/articles/markdown-basics/)”.


Tutorials
--------
* “[Glitter](http://github.com/Polytonic/Glitter)” is github repo which includes the necessary libraries and instructions for getting started with the learnopengl.com and open.gl tutorials! (Claims to require only one “dependency”: [cmake](http://www.cmake.org/download/).)

* http://openglbook.com for *openGL 4* (see preface for hardware and software requirements: book uses [Glew](http://glew.sourceforge.net) and [FreeGlut](http://freeglut.sourceforge.net) (note: “get freeglut version 2.6.0 or higher in order to be able to create an OpenGL 4.0 context”), and explanation that old “glBegin, glEnd, glVertex3f, and glColor3f ... are not present in the OpenGL 4.0 Core Profile. Forget ... ‘immediate mode’ OpenGL ... since it is never coming back.”)

* Highly recommended [open.gl tutorial for openGL 4](http://open.gl) with minimal use of other libraries. (requires SFML, [glfw](http://www.glfw.org/) or SDL for creating the context and handling input; [Glew](http://glew.sourceforge.net) to use newer OpenGL functions; [SOIL](http://www.lonesock.net/soil.html) for textures; [glm](http://glm.g-truc.net/) for vectors and matrices.

* http://github.com/opengl-tutorials/ogl (originally at http://www.opengl-tutorial.org/) shows “modern” opengl (version 3.3 and up, which mac 10.9 runs, according to the “[Capabilities](http://developer.apple.com/opengl/capabilities/index.html)” page of [Apple’s OpenGL Info](http://developer.apple.com/library/mac/documentation/GraphicsImaging/Conceptual/OpenGL-MacProgGuide/opengl_intro/opengl_intro.html). Note: as of 2015 oct 28, the first 12 tutorials of http://github.com/opengl-tutorials/ogl “work on mac” (and seem to need [Glew](http://glew.sourceforge.net), [glfw](http://www.glfw.org/), and [glm](http://glm.g-truc.net/) libraries/frameworks)

* [Durian opengl tutorial](http://duriansoftware.com/joe/An-intro-to-modern-OpenGL.-Table-of-Contents.html) with good explanations of pipeline and line-by-line explanation of code (oops, I typed “line-by-lie”) but seems to be using old opengl 2 rather than the 3 or 4 that we’re able to do now.
 
* [Glut Howto](http://web.eecs.umich.edu/~sugih/courses/eecs487/glut-howto/) <- provided us with a [sample.c](http://web.eecs.umich.edu/%7Esugih/courses/eecs487/glut-howto/sample.c) that worked on mac osX 10.10 in xcode 7! (Uses GLUT code deprecated since osX 10.9.) 



To Do
--------
* Download “Glitter” tutorial and its dependency “cmake”. See tutorials, above.

* Is there in hope of finding tutorials that don’t use [Glew](http://glew.sourceforge.net), or [glfw](http://www.glfw.org/), [glm](http://glm.g-truc.net/), or [FreeGlut](http://freeglut.sourceforge.net), etc.?



Questions
--------
* Can we make cross-platform standalone apps that include everything they need? (glew, glut, x11/xQuartz, or whatever else so that users don’t have to download things we depend upon?? (Isn’t this about “linking” and/or/versus “installing”??) 
* For portability, maybe we should look into “[WebGL](http://www.khronos.org/webgl/)”? (“plugin-free 3D for the web, implemented right in the browser. Major browser vendors Apple (Safari), Google (Chrome), Mozilla (Firefox), and Opera (Opera) are members of the WebGL Working Group.”) (What are webGL limitations? And how much does it overlap with “openGL ES” for mobile devices?) 

* Should we use Eclipse or mac-only Xcode? If we use Eclipse, don’t we have to set up separate Eclipse copies for Java and C++?

* Java? C++? (mac only?) Swift? Python?

* What physics systems play nice with opengl? Do we want to build our own?

* Since openGL just draws pictures (“render”) and does not keep track of where our 3d objects are *, how best should we keep track of what objects we’re using and where they are and how they are moving? (* “OpenGL is a rendering library. What OpenGL does not do is retain information about an “object.” All OpenGL sees is a ball of triangles and a bag of state with which to render them. It does not remember that you drew a line in one location and a sphere in another.” —http://www.opengl.org/wiki/Getting_Started )


Done
----------
* (√) The harrygla xcode project folder is happy with github

* (√) Installed xquartz 2.7.8 ([xquartz latest releases](http://xquartz.macosforge.org/trac/wiki/Releases) as of nov 2015, “works with el capitan (osX 10.11)” supposedly.
