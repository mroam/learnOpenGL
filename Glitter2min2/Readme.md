# This started life as ... [Glitter](http://polytonic.github.io/Glitter/)


Mike & Harry Notes:
To do:

[ ] Figure out whether moving to new machine allows opengl 4.0

[ ] Figure out how to use the separate-file shaders. (Probably could copy from the "Glitter/OurWork" version of main.cpp)

[ ] Figure out how to build a working Xcode from scratch ( or at least figure out how to build a minimal Xcode opengl project from cmake).



# Done:

[√] Changing the internal shaders makes a difference.


# History:
* We used to cmake to build this project for Xcode, but the project was huge (780M), so this version strips out a lot of extra stuff for texture and physics and is only 8M. The only things we've kept are glad and glfw. There were invisible junk files that didn't go away until I made a duplicate folder and copied across sub-folders to it. I had to delete some ".gitignore" files from these folders before I was able to commit this to my github. I also deleted some ".git" files, not sure whether that was necessary.

* cmake worked to build this project when we pointed it at the right starting project.

* The main.cpp file is from learnopengl.com, and may be using internally defined shaders instead of the separate file shaders that we've also included.

* After compiling in xcode, we had to tell xcode to run "Glitter>My Mac" in the choice at the top left of the window, to the right of buttons ">" and "[]"

* We had to hard-wire opengl version major/minor 3.3 instead of default 4.0. Our old favorite development imac only has opengl 3.3


