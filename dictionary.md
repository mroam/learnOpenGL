What is “CMake”?
--------
* “CMake is an extensible, open-source system that manages the build process in an operating system and in a compiler-independent manner. Unlike many cross-platform systems, CMake is designed to be used in conjunction with the native build environment.” Is part of Glitter openGL starter and can make xcode project for us. (also windows visual studio, and linux.) Source: http://cmake.org/overview/


What is “FreeGlut”?
--------
* [FreeGlut](http://freeglut.sourceforge.net)


What is “glad”?
--------
* [glad](http://github.com/Dav1dde/glad) Another way of loading openGL functions. See [glew vs glad](http://www.reddit.com/r/opengl/comments/3m28x1/glew_vs_glad/) debate on reddit. Also see http://www.opengl.org/wiki/OpenGL_Loading_Library for comparisons of glew, gl3w, glLoadGen, glad, glsdk, glbinding, libepoxy, GLee


What is “gl3w”?
--------
* [gl3w](https://github.com/skaslev/gl3w) “it's really lightweight, and only includes the bits of OpenGL that I need (core profile stuff). I don't know about GLAD, but I stopped using GLEW because it doesn't support core profile contexts.” --[reddit comment](https://www.reddit.com/r/opengl/comments/3m28x1/glew_vs_glad/cvbal5a) by [tombsar](http://www.reddit.com/user/tombsar).


What is “glew”?
--------
* “GLEW provides a way of accessing GL functionality higher than 1.1 on certain systems.  You can write this yourself, but GLEW certainly makes it easier (and less error-prone).  You almost certainly need this (but there are other libraries available with the same functionality too).” —mhagain http://www.gamedev.net/topic/656534-glfwglutglu-whats-the-best/

* “GLEW (GL extension wrangler library) - will give you access to all the OpenGL functions you need…” (for openGL 3+) —blubberbert http://www.gamedev.net/topic/656534-glfwglutglu-whats-the-best/

* [glew](http://glew.sourceforge.net)



What is “glfw”?
--------
* “a library that creates the context for you (i.e. opens a window for you to draw in, handles input for you, etc.)… (compared to SDL) … SDL offers a little more extra functionality like networking/sound/image loading, GLFW is just context creation and input handling, youll have to load textures yourself or use another library for that (like SOIL)’ —http://www.gamedev.net/topic/656534-glfwglutglu-whats-the-best/

* [glfw](http://www.glfw.org/)


What is “GLM”?
--------
* [glm](http://glm.g-truc.net/)

* GLM “OpenGL Mathematics: GLM ...The deprecated/removed features of OpenGL include all the matrix management and manipulation functions that are relied upon by the vast majority of older OpenGL programs. It is possible to recreate your own matrix and math libraries from scratch – and there are a range of books which provide good exemplars for this. However, in this class we will use a third part math library that has been developed for use with OpenGL – GLM. One of the notable features of GLM is that the core functions and types have been based closely on GLSL – so familiarity with GLM should help with GLSL and vice versa. You can download the GLM files from http://glm.g-truc.net/ . GLM is a header only library – so you only need to add the GLM folder to your include path – there are no lib files and there is no dll to worry about...” Source: Daniel Livingstone, “[OpenGL With GLM](http://www.scribd.com/doc/71980668/OpenGL-With-GLM#scribd)”


What is “GLU”?
--------
* “GLU is a software library bolted on top of OpenGL to provide some additional functionality or to simplify some parts of OpenGL.  Much of what's in it related to functionality that's been deprecated in GL3.x+ core contexts, so you can probably be better off forgetting it even existed.” —mhagain http://www.gamedev.net/topic/656534-glfwglutglu-whats-the-best/

 
What is “GLUT”?
----------
* An outdated library? “GLUT mostly provides a quick and dirty way of getting a window open, creating a GL context for it, and handling some basic input and other events.  Much tutorial material you'll find will use it, so it’s good to know it.  Again, it’s all code that you can write yourself (using a library just means that you don't have to, so you can focus on learning OpenGL rather than OS code).” —mhagain http://www.gamedev.net/topic/656534-glfwglutglu-whats-the-best/


What is “homebrew”?
--------
* Automated software installer/updater for mac that can supposedly download latest versions of open source programs and reconcile their dependencies (glew, x11, freeglut, etc.) Mike is hesitant about installing it: it fiddles with privileges and can [change versions of utilities that system uses](http://discussions.apple.com/thread/4337315?start=0&tstart=0).

* [homebrew](http://brew.sh)

* [install on mac](http://stackoverflow.com/questions/20381128/how-to-install-homebrew-on-mac-osx)


What is “Macports”?
--------
* Automated software installer/updater that can supposedly download latest versions of open source programs and reconcile their dependencies (glew, x11, freeglut, etc.) Mike is hesitant about installing it: it fiddles with privileges and can [change versions of utilities that system uses](http://discussions.apple.com/thread/4337315?start=0&tstart=0).

* [macports](http://www.macports.org/)


What is “SDL”?
--------
* Like GLFW, [sdl](http://www.libsdl.org) is a cross-platform library for audio and keyboard and mouse and openGL “that creates the context for you (i.e. opens a window for you to draw in, handles input for you, etc.)...SDL offers a little more extra functionality (than GLFW) like networking/sound/image loading. GLFW is just context creation and input handling, you’ll have to load textures yourself or use another library for that (like SOIL)” —http://www.gamedev.net/topic/656534-glfwglutglu-whats-the-best/ Some people on stack overflow say “forget SDL for modern openGL” while others argue back saying use “SDL2 lets you specify the version of the OpenGL context.”


What is “webGL”?
----------
* It is a (“plugin-free 3D for the web, implemented right in the browser. Major browser vendors Apple (Safari), Google (Chrome), Mozilla (Firefox), and Opera (Opera) are members of the WebGL Working Group.”) (What are limitations of webGL, and its foundation “openGL ES” for mobile devices?)
