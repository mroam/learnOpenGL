# learnOpenGL
========

Questions
--------
* Should we use Eclipse or Xcode?
* Java or C++? Swift?
* What physics system? Our own? There must be ones that play nice with opengl...
* Will glew, glfw, glm hurt my mac? I already distrust homebrew, macports, etc for [potentially changing versions of utilities that system uses](http://discussions.apple.com/thread/4337315?start=0&tstart=0)


Helpful Links
------------
* http://github.com/opengl-tutorials/ogl (originally at http://www.opengl-tutorial.org/) shows “modern” opengl (version 3.3 and up, which mac 10.9 runs, according to the “[Capabilities](http://developer.apple.com/opengl/capabilities/index.html)” page of [Apple’s OpenGL Info](http://developer.apple.com/library/mac/documentation/GraphicsImaging/Conceptual/OpenGL-MacProgGuide/opengl_intro/opengl_intro.html). Note: as of 2015 oct 28, their first 12 tutorials on github “work on mac” (and seem to need glew, glfw, and glm libraries/frameworks)

* [Durian opengl tutorial](http://duriansoftware.com/joe/An-intro-to-modern-OpenGL.-Table-of-Contents.html) with good explanations of pipeline and line-by-line explanation of code (oops, I typed “line-by-lie”) but seems to be using opengl 2 rather than the 3 or 4 that we’re able to do now.
 
* See github's “[MarkDown Basics](http://help.github.com/articles/markdown-basics/)”.

* [Glut Howto](http://web.eecs.umich.edu/~sugih/courses/eecs487/glut-howto/) <- provided us with a [sample.c](http://web.eecs.umich.edu/%7Esugih/courses/eecs487/glut-howto/sample.c) that worked on mac osX 10.10 in xcode 7! (Uses code deprecated since osX 10.9.) The tutorial showed us how to “Add” the OpenGL.framework and GLUT.framework to our project: by going to the project’s “Build Phases” tab, open the "Link Binary With Libraries" list, and click the ‘+’ sign at the bottom left corner of the list and choosing “OpenGL.framework” and “GLUT.framework” from the list.

* http://en.wikipedia.org/wiki/OpenGL

* http://www.opengl.org

* Stack overflow: how to [Use Xcode 7 with git](http://stackoverflow.com/questions/5383609/using-git-with-an-existing-xcode-project/32498035) and [Add xcode project to github](http://stackoverflow.com/questions/12698482/add-xcode-project-to-github-repo) 
 


Potential Projects
-----------------
* Lunar lander in 3D 
* Skydive simulator


To Do
---------
* check whether the harrygla xcode project folder is happy with github
* find out whether there are tutorials that don’t use glew, glfw, glm 
* OR look into installing glew, glfw, glm for openlgl-tutorials (someone at a [gamedev thread](http://www.gamedev.net/topic/561579-is-glew-necessary-to-use-shaders-solved-not-necessary/) says “Just as a little aside, GLEW is now incredibly easy on the Mac. Download, run Make, put in /usr/local/lib and /usr/local/include respectively.” and follow-up note reminds users of GLEW to call glewInit( ) early in startup (“If you try to use any function before glewInit(), the program fails.”) (A [stackoverflow thread](http://stackoverflow.com/questions/12229714/building-glew-for-mac-osx) includes suggestion, “recommend going to http://glew.sourceforge.net and downloading the ZIP file right onto your Mac. Then go into the Finder and type in glew.h to see the file, control click it, get info, and copy the path to the file. Then go into your respective program file (e.g., commons.h) that contains the #include <GL/glew.h> dependency, and change it to: #include <path/to/file/that/you/just/copied/glew.h>   Then, try to compile your program again, and this time you should not get any GLEW errors.” Better yet(?), see [stackoverflow thread "how-to-link-glew-in-xcode"](http://stackoverflow.com/questions/17600917/how-to-link-glew-in-xcode) which shows how to make xcode recognize glew headers, and see ["im-having-trouble-linking-the-glew-library-to-my-xcode-project"](http://stackoverflow.com/questions/3072293/im-having-trouble-linking-the-glew-library-to-my-xcode-project) for more info.

