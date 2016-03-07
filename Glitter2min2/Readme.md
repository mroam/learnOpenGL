# This started life as ...
# [Glitter](http://polytonic.github.io/Glitter/)
![Screenshot](http://i.imgur.com/MDo2rsy.jpg)


Mike & Harry Note:
* We used to cmake to build this project for Xcode, but the project was huge (780M), so this version strips out a lot of extra stuff for texture and physics and is only 8M. The only things we've kept are glad and glfw.
* cmake worked to build this project when we pointed it at the right starting project.
* The main.cpp file is from learnopengl.com, and may be using internally defined shaders instead of the separate file shaders that we've also included.
* After compiling in xcode, we had to tell xcode to run "Glitter>My Mac" in the choice at the top left of the window, to the right of buttons ">" and "[]"
* We had to hard-wire opengl version major/minor 3.3 instead of default 4.0. Our old favorite development imac only has opengl 3.3

To do:
[ ] Figure out whether moving to new machine allows opengl 4.0
[ ] Figure out whether changing the internal shaders makes a difference.
[ ] Figure out how to use the separate-file shaders. (Probably could copy from the "Glitter/OurWork" version of main.cpp)

