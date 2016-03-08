# How to create a working openGL Xcode project from scratch...

# In Finder: Build a folder (e.g. XYZ) that contains the following:
* our "CMakeLists.txt" (included in this project)
* a folder called "Build"
* a folder called "learn" which contains subfolders "Headers", "Sources" and "Vendor"
* learn/Headers should contain "glitter.hpp"
* learn/Sources should contain our "main.cpp"
* learn/Vendor should contain "glad" and "glfw", each of which contains stuff copied from here. (had to remove their .git and .gitignore files to be able to push this project to github!!)

# Using "CMake", make a new Xcode project, 
* tell it source code comes from XYZ (it'll find subfolders)
* tell it to build the binaries into XYZ/Build
* press "(Configure)" button at bottom
* make sure GLFW_INSTALL [x] is turned on.
* then press "(Generate")"

# Voila, that should do it, you'll have an Xcode project that should work. 
* Might have to do one thing: in the upper left part of the window (to the right of the Build and Stop buttons), change the target from "ALL_BUILD>My Mac" to "learn>My Mac"."

# NOTE: this project might not like moving to differently named folder!! To move it, rebuild from scratch in a new place.
