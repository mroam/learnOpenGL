# learnOpenGL
========

Questions
--------
* Should we use Eclipse or Xcode?
* Java or C++? Swift?
* What physics system? Our own? There must be ones that play nice with opengl...


Helpful Links
------------
* http://github.com/opengl-tutorials/ogl (originally at http://www.opengl-tutorial.org/) shows “modern” opengl (version 3.3 and up, which mac 10.9 runs, according to the “[Capabilities](http://developer.apple.com/opengl/capabilities/index.html)” page of [Apple’s OpenGL Info](http://developer.apple.com/library/mac/documentation/GraphicsImaging/Conceptual/OpenGL-MacProgGuide/opengl_intro/opengl_intro.html). Note: as of 2015 oct 28, their first 12 tutorials on github “work on mac” (and seem to need glew, glfw, and glm libraries/frameworks)
 
* See github's “[MarkDown Basics](http://help.github.com/articles/markdown-basics/)”.

* [Glut Howto](http://web.eecs.umich.edu/~sugih/courses/eecs487/glut-howto/) <- provided us with a [sample.c](http://web.eecs.umich.edu/%7Esugih/courses/eecs487/glut-howto/sample.c) that worked on mac osX 10.10 in xcode 7! (Uses code deprecated since osX 10.9.) (The tutorial showed us how to “Add” the OpenGL.framework and GLUT.framework to our project: by going to the project’s “Build Phases” tab, open the "Link Binary With Libraries" list, and click the ‘+’ sign at the bottom left corner of the list and choosing “OpenGL.framework” and “GLUT.framework” from the list.)

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
