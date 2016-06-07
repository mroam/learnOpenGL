# How to create a working openGL Xcode project from scratch...

# In Finder: Build a folder (e.g. XYZ) that contains the following:
* our "CMakeLists.txt" (can be copied from our "learnopengl-for-cmake" project)
* a folder called "Build"
* a folder called "OurDumbFolder" (call it whatever you want, but not XYZ) which contains subfolders "Headers", "Sources" and "Vendor"
* Make sure to change the file path in the CMakeLists.txt from "learn" to "OurDumbFolder" (there should be 12 changes, including line 2 of CMakeLists.txt, (though _maybe_ line 2 could have a different name? Not sure.))
* OurDumbFolder/Headers should contain "glitter.hpp" (copy from "learnopengl-for-cmake/learn/Headers")
* OurDumbFolder/Sources should contain our "main.cpp" (can copy from "learnopengl-for-cmake/learn/Sources" and also bring any shaders we want, too).

* OurDumbFolder/Vendor should contain "glad" and "glfw", each of which can be copied from "learnopengl-for-cmake/learn/Vendor"). Note: MUST remove any (invisible) .git and .gitignore files to be able to push this project to github!! Can use bbedit or terminal to check if there are pesky .git and .gitignore files.)

# Open and use "CMake" app to make our new Xcode project. Here's how: 
* tell CMake that source code comes from XYZ (it'll find subfolders)
* tell CMake to build the binaries into XYZ/Build
* press "(Configure)" button at bottom. You'll be prompted to build Xcode (or whateve r you might want to build instead). I choose "(x)Use default native compilers" in that prompt.
* You'll get a big red list: make sure GLFW_INSTALL [x] is turned on.
* then press CMake's "(Generate)" button.
* Don't be alarmed that there will be additional "OurDumbFolder" folders created in the Build folder. This is supposed to happen.

# Voila, that should do it, you'll have an Xcode project that should work, hiding as XYZ/OurDumbFolder/Build/OurDumbFolder.xcodeproj  
* Might have to do one thing: in the upper left part of the Xcode project window (to the right of the Build and Stop buttons), change the target from "ALL_BUILD>My Mac" to "OurDumbFolder>My Mac".

DARN: I'm getting error messages that vertex shader and fragment shader are "corrupt"--I think there is another step that has to be done inside Xcode, to install the shaders into the project.

# NOTE: this project might not like moving to differently named folder!?!?
