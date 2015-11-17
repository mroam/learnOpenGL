# learnOpenGL
========
Harry and Mike are trying to learn openGL by installing it, reading tutorials, running code, and revising code.


Potential Projects
-----------------
* Lunar lander in 3D 
* Skydive simulator


Questions
--------
* Can we make cross-platform standalone demo apps that include everything they need? (glew, glut, x11/xQuartz, or whatever else so that users don’t have to download things we depend upon?? (Isn’t this about “linking” and/or/versus “installing”??) Maybe we should look into “[WebGL](http://www.khronos.org/webgl/)” for portability? (It is a “plugin-free 3D to the web, implemented right into the browser. Major browser vendors Apple (Safari), Google (Chrome), Mozilla (Firefox), and Opera (Opera) are members of the WebGL Working Group.”) (What are its limitations? And how much does it overlap with openGL for mobile devices?) 

* Should we use Eclipse or Xcode? If we use Eclipse, don’t we have to set up separate Eclipse copies for Java and C++?

* Java? C++? Swift? Python?

* What physics systems play nice with opengl? Do we want to build our own?


References and Tutorials 
--------
* See [how to install opengl](http://github.com/mroam/learnOpenGL/blob/master/install-opengl.md) page.

* See [our dictionary](http://github.com/mroam/learnOpenGL/blob/master/dictionary.md) re “What is..” glew, glut, webgl, glm, glfw, etc...

* http://www.opengl.org

* http://en.wikipedia.org/wiki/OpenGL

* http://openglbook.com for *openGL 4* (see preface for hardware and software requirements (book uses [Glew](http://glew.sourceforge.net) and [FreeGlut](http://freeglut.sourceforge.net) (“get freeglut version 2.6.0 or higher in order to be able to create an OpenGL 4.0 context”), and explanation that old “glBegin, glEnd, glVertex3f, and glColor3f ... are not present in the OpenGL 4.0 Core Profile. Forget ... ‘immediate mode’ OpenGL ... since it is never coming back.”)

* Highly recommended [open.gl tutorial for openGL 4](http://open.gl) with minimal use of other libraries.

* http://github.com/opengl-tutorials/ogl (originally at http://www.opengl-tutorial.org/) shows “modern” opengl (version 3.3 and up, which mac 10.9 runs, according to the “[Capabilities](http://developer.apple.com/opengl/capabilities/index.html)” page of [Apple’s OpenGL Info](http://developer.apple.com/library/mac/documentation/GraphicsImaging/Conceptual/OpenGL-MacProgGuide/opengl_intro/opengl_intro.html). Note: as of 2015 oct 28, their first 12 tutorials on github “work on mac” (and seem to need glew, glfw, and glm libraries/frameworks)

* [Durian opengl tutorial](http://duriansoftware.com/joe/An-intro-to-modern-OpenGL.-Table-of-Contents.html) with good explanations of pipeline and line-by-line explanation of code (oops, I typed “line-by-lie”) but seems to be using opengl 2 rather than the 3 or 4 that we’re able to do now.
 
* See github’s “[MarkDown Basics](http://help.github.com/articles/markdown-basics/)”.

* [Glut Howto](http://web.eecs.umich.edu/~sugih/courses/eecs487/glut-howto/) <- provided us with a [sample.c](http://web.eecs.umich.edu/%7Esugih/courses/eecs487/glut-howto/sample.c) that worked on mac osX 10.10 in xcode 7! (Uses GLUT code deprecated since osX 10.9.) 



To Do
---------
* Keep looking for tutorials that don’t use glew, glfw, glm, [FreeGlut](http://freeglut.sourceforge.net)


Did
----------
* (√) The harrygla xcode project folder is happy with github
* (√) Installed xquartz 2.7.8 ([xquartz latest releases](http://xquartz.macosforge.org/trac/wiki/Releases) as of nov 2015, “works with el capitan (osX 10.11)” supposedly.


More Info
----------
* GLM “OpenGL Mathematics: GLM ...The deprecated/removed features of OpenGL include all the matrix management and manipulation functions that are relied upon by the vast majority of older OpenGL programs. It is possible to recreate your own matrix and math libraries from scratch – and there are a range of books which provide good exemplars for this. However, in this class we will use a third part math library that has been developed for use with OpenGL – GLM.One of the notable features of GLM is that the core functions and types have been based closely on GLSL – so familiarity with GLM should help with GLSL and vice versa. You can download the GLM files from http://glm.g-truc.net/ . GLM is a header only library – so you only need to add the GLM folder to your include path – there are no lib files and there is no dll to worry about..." Daniel Livingstone, "[OpenGL With GLM](http://www.scribd.com/doc/71980668/OpenGL-With-GLM#scribd)"
* 
