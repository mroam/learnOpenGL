# learnOpenGL
========

Installing openGL
--------
* On Mac, openGL and GLUT (deprecated) are installed already (see “[Capabilities](http://developer.apple.com/opengl/capabilities/index.html)” page of [Apple’s OpenGL Info](http://developer.apple.com/library/mac/documentation/GraphicsImaging/Conceptual/OpenGL-MacProgGuide/opengl_intro/opengl_intro.html)

* Many tutorials use [glew](http://glew.sourceforge.net), [glfw](http://www.glfw.org/), and [glm](http://glm.g-truc.net/). Used by http://github.com/opengl-tutorials/ogl. Someone at a [gamedev thread](http://www.gamedev.net/topic/561579-is-glew-necessary-to-use-shaders-solved-not-necessary/) says “Just as a little aside, GLEW is now incredibly easy on the Mac. Download, run Make, put in /usr/local/lib and /usr/local/include respectively.” and follow-up note reminds users of GLEW to call glewInit( ) early in startup (“If you try to use any function before glewInit(), the program fails.”) ([stackoverflow “building glew for mac”](http://stackoverflow.com/questions/12229714/building-glew-for-mac-osx) includes suggestion, “go... to http://glew.sourceforge.net and downloading the ZIP file right onto your Mac. Then go into the Finder and type in glew.h to see the file, control click it, get info, and copy the path to the file. Then go into your respective program file (e.g., commons.h) that contains the #include <GL/glew.h> dependency, and change it to: #include <path/to/file/that/you/just/copied/glew.h>  Then, try to compile your program again, and this time you should not get any GLEW errors.” Better yet(?), see [stackoverflow thread "how-to-link-glew-in-xcode"](http://stackoverflow.com/questions/17600917/how-to-link-glew-in-xcode) which shows how to make xcode recognize glew headers, and see ["im-having-trouble-linking-the-glew-library-to-my-xcode-project"](http://stackoverflow.com/questions/3072293/im-having-trouble-linking-the-glew-library-to-my-xcode-project) for more info.

* Instead of [glew](http://glew.sourceforge.net), some tutorials use [FreeGlut](http://freeglut.sourceforge.net) (Might [require installing x11 first](http://sourceforge.net/p/freeglut/bugs/215/) ) Hey, somebody says that xQuartz ([replacement of X11 for mac](http://support.apple.com/en-us/HT201341)) comes with freeglut, so just install xQuartz [latest releases](http://xquartz.macosforge.org/trac/wiki/Releases) and you’ll get a pretty up-to-date freeglut. (We’re trying this.) See follow-up warnings and tweaks about [build freeglut on mac](http://stackoverflow.com/questions/9149133/is-it-possible-to-build-freeglut-on-mac-os-x).

* There are automated software installer/updaters that could supposedly reconcile dependencies among glew, x11, freeglut, etc. Such updaters include [homebrew](http://brew.sh)[install](http://stackoverflow.com/questions/20381128/how-to-install-homebrew-on-mac-osx), and [macports](http://www.macports.org/), etc but I’m hesitant: they can [change versions of utilities that system uses](http://discussions.apple.com/thread/4337315?start=0&tstart=0).

* Re GLUT deprecated on mac osX 10.9+. Somebody on stackoverflow says that what apple wants us to do instead of  is use cocoa.  ["installing-freeglut-on-os-x-mavericks"](http://stackoverflow.com/questions/19648087/installing-freeglut-on-os-x-mavericks) points out that despite deprecations, Glut still works fine and “glutInitDisplayMode(GLUT\_3\_2\_CORE_PROFILE);” will get openGL 4.1+ context on mac osX 10.9 and 10.10. 


Using openGL from Xcode
--------
* [Glut Howto](http://web.eecs.umich.edu/~sugih/courses/eecs487/glut-howto/) <- provided us with a [sample.c](http://web.eecs.umich.edu/%7Esugih/courses/eecs487/glut-howto/sample.c) that worked on mac osX 10.10 in xcode 7! (Uses GLUT code deprecated since osX 10.9.) The tutorial showed us how to “Add” the OpenGL.framework and GLUT.framework to our project: by going to the project’s “Build Phases” tab, open the "Link Binary With Libraries" list, and click the ‘+’ sign at the bottom left corner of the list and choosing “OpenGL.framework” and “GLUT.framework” from the list.

* Stack overflow: how to [Use Xcode 7 with git](http://stackoverflow.com/questions/5383609/using-git-with-an-existing-xcode-project/32498035) and [Add xcode project to github](http://stackoverflow.com/questions/12698482/add-xcode-project-to-github-repo) 

openGL references
--------
* http://en.wikipedia.org/wiki/OpenGL

* http://www.opengl.org


Did
----------
* (√) Installed xquartz 2.7.8 (from [xquartz latest releases](http://xquartz.macosforge.org/trac/wiki/Releases) as of nov 2015, “works with el capitan (osX 10.11)” supposedly. Provides use with recent “freeglut” supposedly.

To do
---------
* [ ]Test xquartz 2.7.8
* [ ]Test 
