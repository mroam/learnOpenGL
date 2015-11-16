# learnOpenGL
========

Questions
--------
* Maybe we should look into "[WebGL](http://www.khronos.org/webgl/)" for portability? (Limitations?)

* Should we use Eclipse or Xcode? Don’t we have to set up separate Eclipse copies for Java and C++?

* Java or C++? Swift?

* What physics system? Our own? There must be ones that play nice with opengl...

* Will [glew](http://glew.sourceforge.net), [glfw](http://www.glfw.org/), [glm](http://glm.g-truc.net/), [FreeGlut](http://freeglut.sourceforge.net) hurt my mac? (I already distrust [homebrew](http://brew.sh)[install](http://stackoverflow.com/questions/20381128/how-to-install-homebrew-on-mac-osx), [macports](http://www.macports.org/), etc for [potentially changing versions of utilities that system uses](http://discussions.apple.com/thread/4337315?start=0&tstart=0).)

* If GLUT is deprecated on mac osX 10.9+, what should/could we use instead? [FreeGlut](http://freeglut.sourceforge.net)? [Glew](http://glew.sourceforge.net) and/or [glfw](http://www.glfw.org/)? Somebody on stackoverflow says that what apple wants us to do is use cocoa.  ["installing-freeglut-on-os-x-mavericks"](http://stackoverflow.com/questions/19648087/installing-freeglut-on-os-x-mavericks) points out that despite deprecations, Glut still works fine and “glutInitDisplayMode(GLUT_3_2_CORE_PROFILE);” will get openGL 4.1+ context on mac osX 10.9 and 10.10. But many tutorials rely upon [Glew](http://glew.sourceforge.net) or [FreeGlut](http://freeglut.sourceforge.net).

* Can we make cross-platform standalone apps that include glew or glut or x11/xQuartz and whatever else we need so that users don't have to download things we depend upon?? (“linking” and/or/versus “installing”??)

Helpful Links
------------
* http://openglbook.com for *openGL 4* (see preface for hardware and software requirements (book uses [Glew](http://glew.sourceforge.net) and [FreeGlut](http://freeglut.sourceforge.net) (“get version 2.6.0 or higher in order to be able to create an OpenGL 4.0 context”), and explanation that old “glBegin, glEnd, glVertex3f, and glColor3f ... are not present in the OpenGL 4.0 Core Profile. Forget ... ’immediate mode’ OpenGL ... since it is never coming back.”)

* http://github.com/opengl-tutorials/ogl (originally at http://www.opengl-tutorial.org/) shows “modern” opengl (version 3.3 and up, which mac 10.9 runs, according to the “[Capabilities](http://developer.apple.com/opengl/capabilities/index.html)” page of [Apple’s OpenGL Info](http://developer.apple.com/library/mac/documentation/GraphicsImaging/Conceptual/OpenGL-MacProgGuide/opengl_intro/opengl_intro.html). Note: as of 2015 oct 28, their first 12 tutorials on github “work on mac” (and seem to need glew, glfw, and glm libraries/frameworks)

* [Durian opengl tutorial](http://duriansoftware.com/joe/An-intro-to-modern-OpenGL.-Table-of-Contents.html) with good explanations of pipeline and line-by-line explanation of code (oops, I typed “line-by-lie”) but seems to be using opengl 2 rather than the 3 or 4 that we’re able to do now.
 
* See github's “[MarkDown Basics](http://help.github.com/articles/markdown-basics/)”.

* [Glut Howto](http://web.eecs.umich.edu/~sugih/courses/eecs487/glut-howto/) <- provided us with a [sample.c](http://web.eecs.umich.edu/%7Esugih/courses/eecs487/glut-howto/sample.c) that worked on mac osX 10.10 in xcode 7! (Uses GLUT code deprecated since osX 10.9.) The tutorial showed us how to “Add” the OpenGL.framework and GLUT.framework to our project: by going to the project’s “Build Phases” tab, open the "Link Binary With Libraries" list, and click the ‘+’ sign at the bottom left corner of the list and choosing “OpenGL.framework” and “GLUT.framework” from the list.

* http://en.wikipedia.org/wiki/OpenGL

* http://www.opengl.org

* Stack overflow: how to [Use Xcode 7 with git](http://stackoverflow.com/questions/5383609/using-git-with-an-existing-xcode-project/32498035) and [Add xcode project to github](http://stackoverflow.com/questions/12698482/add-xcode-project-to-github-repo) 
 


Potential Projects
-----------------
* Lunar lander in 3D 
* Skydive simulator


To Do
---------
* Find out whether there are tutorials that don’t use glew, glfw, glm, [FreeGlut](http://freeglut.sourceforge.net)

* OR look into installing glew, glfw, glm, [FreeGlut](http://freeglut.sourceforge.net) for openlgl-tutorials (someone at a [gamedev thread](http://www.gamedev.net/topic/561579-is-glew-necessary-to-use-shaders-solved-not-necessary/) says “Just as a little aside, GLEW is now incredibly easy on the Mac. Download, run Make, put in /usr/local/lib and /usr/local/include respectively.” and follow-up note reminds users of GLEW to call glewInit( ) early in startup (“If you try to use any function before glewInit(), the program fails.”) ([stackoverflow “building glew for mac”](http://stackoverflow.com/questions/12229714/building-glew-for-mac-osx) includes suggestion, “go... to http://glew.sourceforge.net and downloading the ZIP file right onto your Mac. Then go into the Finder and type in glew.h to see the file, control click it, get info, and copy the path to the file. Then go into your respective program file (e.g., commons.h) that contains the #include <GL/glew.h> dependency, and change it to: #include <path/to/file/that/you/just/copied/glew.h>   Then, try to compile your program again, and this time you should not get any GLEW errors.” Better yet(?), see [stackoverflow thread "how-to-link-glew-in-xcode"](http://stackoverflow.com/questions/17600917/how-to-link-glew-in-xcode) which shows how to make xcode recognize glew headers, and see ["im-having-trouble-linking-the-glew-library-to-my-xcode-project"](http://stackoverflow.com/questions/3072293/im-having-trouble-linking-the-glew-library-to-my-xcode-project) for more info.

* Look into installing freeglut (seems to [require installing x11 first](http://sourceforge.net/p/freeglut/bugs/215/) ) Hey, somebody says that xQuartz ([replacement of X11 for mac](http://support.apple.com/en-us/HT201341)) comes with freeglut, so just install xQuartz [latest releases](http://xquartz.macosforge.org/trac/wiki/Releases) and you’ll get a pretty up-to-date freeglut. (We’re trying this.) See follow-up warnings and tweaks about [freeglut on mac](http://stackoverflow.com/questions/9149133/is-it-possible-to-build-freeglut-on-mac-os-x).

Did
----------
* (√) The harrygla xcode project folder is happy with github
* (√) Installed xquartz 2.7.8 ([xquartz latest releases](http://xquartz.macosforge.org/trac/wiki/Releases) as of nov 2015, “works with el capitan (osX 10.11)” supposedly.


More Info
----------
* GLM “OpenGL Mathematics: GLM ...The deprecated/removed features of OpenGL include all the matrix management and manipulation functions that are relied upon by the vast majority of older OpenGL programs. It is possible to recreate your own matrix and math libraries from scratch – and there are a range of books which provide good exemplars for this. However, in this class we will use a third part math library that has been developed for use with OpenGL – GLM.One of the notable features of GLM is that the core functions and types have been based closely on GLSL – so familiarity with GLM should help with GLSL and vice versa. You can download the GLM files from http://glm.g-truc.net/ . GLM is a header only library – so you only need to add the GLM folder to your include path – there are no lib files and there is no dll to worry about..." Daniel Livingstone, "[OpenGL With GLM](http://www.scribd.com/doc/71980668/OpenGL-With-GLM#scribd)"
* 
