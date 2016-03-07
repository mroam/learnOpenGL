#include <iostream>
#include <glad/glad.h>  // mjr added

// This is source code from learnopengl.com which I've spliced into a copy of my glitter
// xcode project and then I've spent hours trying to make it compile on mac xcode.
// The big problem seems to be its use of glew for call backs or window.


/* following is header suggestion from 
 http://stackoverflow.com/questions/12229714/building-glew-for-mac-osx
 aswer by Brett Hale
 */
#if defined (__APPLE__)
#include <OpenGL/gl3.h>
#else
#include <GL/gl3.h>   /* assert OpenGL 3.2 core profile available. */
#endif

#define GLFW_INCLUDE_GL3    /* don't drag in legacy GL headers. */
#define GLFW_NO_GLU       /* don't drag in the old GLU lib - unless you must. */

/* Brett Hale had <GL/glfw.h> which isn't found on Mike's xcode. Either install it or ... */
#include <GLFW/glfw3.h>    /* simple and easy to use. omit legacy GL. */


/* First header from learnopengl.com with Mike's attempts...
// GLEW
#define GLEW_STATIC
#include <OpenGL/GL.h>    //   mjr adding this
//#include <glad/glad.h>    // mjr tried this to replace learnopengl.com's #include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>   // mjr can't blank this
*/






// Function prototypes
// void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode); <== mjr is blanking

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

// Shaders
const GLchar* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 position;\n"
"void main()\n"
"{\n"
"gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
"}\0";

const GLchar* fragmentShaderSource = "#version 330 core\n"
"out vec4 color;\n"
"void main()\n"
"{\n"
"color = vec4(1.0f, 0.5f, 0.7f, 1.0f);\n"
"}\n\0"; /* was vec4(1.0f, 0.5f, 0.2f, 1.0f); */


// The MAIN function, from here we start the application and run the game loop
int main()
{
    // Init GLFW
    glfwInit();
    // Set all the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // mjr added
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    
    // Create a GLFWwindow object that we can use for GLFW's functions
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
    
    // mjr added the following, copied from the original glitter project from github.
    // Check for Valid Context
    if (window == nullptr) {
        fprintf(stderr, "Failed to Create OpenGL Context");
        return EXIT_FAILURE;
    }
    glfwMakeContextCurrent(window);
    gladLoadGL();  // mjr added  ***** THIS MADE IT WORK (along with include glad/glad.h above
    fprintf(stderr, "OpenGL %s\n", glGetString(GL_VERSION));  // mjr added
    
    // gladLoadGL( );  // <=== mjr added this from glitter sample
    // Set the required callback functions
    // glfwSetKeyCallback(window, key_callback);   // necessary??  mjr can't blank it
    
    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
    //glewExperimental = GL_FALSE;   // <== is this necessary??  mjr is falsing it
    // Initialize GLEW to setup the OpenGL Function pointers
    //glewInit();   // <== is this necessary??  mjr is blanking it
    
    // Define the viewport dimensions
    // glViewport(0, 0, WIDTH, HEIGHT);   <== mjr is blanking
    
    
    // Build and compile our shader program
    // Vertex shader
    
    // mjr: the glCreateShader( ) is getting EXC_BAD_ACCESS (code=1) which may be indicative
    // of releasing from memory an object that isn't mine to release. Somebody online with this
    // problem realized that they hadn't set up the openGL context prior to calling glCreateShader
    // but I already have context setup above, I think.
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // Check for compile time errors
    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // Fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // Check for compile time errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // Link shaders
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // Check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    
    
    // Set up vertex data (and buffer(s)) and attribute pointers
    GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f, // Left
        0.5f, -0.5f, 0.0f, // Right
        0.0f,  0.5f, 0.0f  // Top
    };
    GLuint VBO, VAO;
    glGenVertexArrays(1, &VAO);   // mjr tried glGenVertexArraysAPPLE(1, &VAO);
    glGenBuffers(1, &VBO);
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray(VAO);   // mjr tried glBindVertexArrayAPPLE(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind
    
    glBindVertexArray(0); // mjr tried glBindVertexArrayAPPLE(0);
    // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)
    
    // Game loop
    while (!glfwWindowShouldClose(window))
    {
        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();
        
        // Render
        // Clear the colorbuffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        // Draw our first triangle
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);   // mjr tried glBindVertexArrayAPPLE(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);   // mjr tried glBindVertexArrayAPPLE(0);
        
        // Swap the screen buffers
        glfwSwapBuffers(window);
    }
    // Properly de-allocate all resources once they've outlived their purpose
    glDeleteVertexArrays(1, &VAO);    // glDeleteVertexArraysAPPLE(1, &VAO);
    glDeleteBuffers(1, &VBO);
    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();
    return 0;
}

// mjr is blanking this
// Is called whenever a key is pressed/released via GLFW
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, GL_TRUE);
//}