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
* But the shaders aren't incorporated yet. Can drag them onto /Sources/OurDumbFolder/Sources/ in Xcode's left (navigator) column (make sure you're in folder view). I'm using "[x]Copy items if needed" and I'm trying "Add-to-targets:[x]ALL_BUILD, [x]OurDumbFolder, and [x]ZERO_CHECK"
* Also, in the upper left part of the Xcode project window (to the right of the Build and Stop buttons), must change the target from "ALL_BUILD>My Mac" to "OurDumbFolder>My Mac".

I had trouble getting shaders to work: the fix seemed to involve re-copying them into OurDumbFolder/Sources in finder, and onto /Sources/OurDumbFolder/Sources/ in Xcode's left (navigator) column (make sure you're in folder view), AND into the copy files build phase (dragging from xcode's navigator left panel).

# NOTE: this project might not like moving to differently named folder!?!?

Here are further steps to try within Xcode:
Figured out how to tell xcode to put the files (such as shaders) into the build destination:
( -Make sure we're in standard editor and leftmost column ("navigator") is visible.
-In navigator, click outermost upper project name ("OurDumbFolder").
-Just above the name, choose folder icon ("Project navigator") for view.
-In central main view area, upper left has icon: use it to show a sub sidebar "PROJECT and TARGETS List"
 xcdoc://?url=developer.apple.com/library/etc/redirect/xcode/devtools/1157/recipes/xcode_help-project_editor/Articles/CreatingaCopyFilesBuildPhase.html
-Now can follow the help file re "Copying Files While Building a Product"…
 -Choose a target in that tiny left sidebar of main central window (we're currently on 'OurDumbFolder' target)
 -Choose the "Build Phases" tab along the top
 -If there is not a "Copy Files" build phase (rule?) then add one with the "+" toward the top left "new copy Files phase",
 -can drag files onto the list of who gets copied
 -Specify Destination "Products Directory")