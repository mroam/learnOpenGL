This uses the [sourcecode](http://www.learnopengl.com/code_viewer.php?code=getting-started/hellotriangle) from the [“Hello Triangle”](http://www.learnopengl.com/#!Getting-started/Hello-Triangle) tutorial 
from [learnopengl.com](http://www.learnopengl.com/) within an Xcode project that was built using the CMake files from the 
[“Glitter”](https://github.com/Polytonic/Glitter) project on github.
We had to customized the cource code a little because our project is using “glad” instead of “glew.” 
Our project also uses “glfw” and has removed the other libraries such as assimp and bullet from Glitter and its CMake file.
(With all the glitter extras, the Xcode project was 700 Mb. Without them it is 9M.)
We also removed the “.git” and “.gitignore” hidden files from the Glitter project so that we could synch it with our
own [“learnOpenGL”](“https://github.com/mroam/learnOpenGL/”) repository.

   We’ve customized the code to make the triangle rotate. Wahoo!