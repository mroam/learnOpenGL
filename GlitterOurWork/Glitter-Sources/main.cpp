// Local Headers
#include "glitter.hpp"

// System Headers
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Standard Headers
#include <cstdio>
#include <cstdlib>

#include <iostream>  // enables cout
#include <fstream>    // so we can read external shader text files
#include <sstream>    // so we can read external shader as string

/* 
 // from http://learnopengl.com/book/offline%20learnopengl.pdf  page 37-38
 
 GLfloat vertices[] = {
 -0.5f, -0.5f, 0.0f,
 0.5f, -0.5f, 0.0f,
 0.0f, 0.5f, 0.0f
};
 
 GLuint VBO;
 glGenBuffers(1, &VBO);
 
 glBindBuffer(GL_ARRAY_BUFFER, VBO);
 
 glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
 
 -----
 // this is simple vertext shader
 version 330 core
 layout (location = 0) in vec3 position;
 
 void main() {
     gl_Position = vec4(position.x, position.y, position.z, 1.0);
 }
 */



int main(int argc, char * argv[]) {
    std::cout << "Glitter is";
    fprintf(stdout, " starting...\n");
    // Load GLFW and Create a Window
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // project was hardwired with "4" and "0" but imac z-ppp1-j (early 2009)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // has nvidia geforce 9400 with opengl 3.3

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    auto mWindow = glfwCreateWindow(mWidth, mHeight, "OpenGL", nullptr, nullptr);

    // Check for Valid Context
    if (mWindow == nullptr) {
        fprintf(stderr, "Failed to Create OpenGL Context");
        return EXIT_FAILURE;
    }

    // Create Context and Load OpenGL Functions
    glfwMakeContextCurrent(mWindow);
    gladLoadGL();
    fprintf(stderr, "OpenGL %s\n", glGetString(GL_VERSION));
    
    
    
    //// Now we'll try to load some shaders from external files
    // source stackoverflow.com/questions...
    std::ifstream vertfn("vertextshader_mh1.vert");
    std::stringstream ourVertexShaderBuffer;
    ourVertexShaderBuffer << vertfn.rdbuf( );
    // conversion from string to GLchar *   is from
    //        http://stackoverflow.com/questions/34836454/neither-vertex-shader-nor-fragment-shader-are-compiling-after-loading-from-a-fil
    // char * vertShaderSource = ourVertexShaderBuffer.c_str( );//const_cast<const GLchar*>(ourVertexShaderBuffer.str( ));
    std::string vertShaderSourceStr = ourVertexShaderBuffer.str( );
    const char * vertShaderSourceChars = vertShaderSourceStr.c_str( );  // "const" was important!!
    
    GLuint ourVertexShader = glCreateShader(GL_VERTEX_SHADER);
    
    glShaderSource(ourVertexShader, 1, &vertShaderSourceChars, NULL);
    glCompileShader(ourVertexShader);
    // we stopped here, presently copying from "Vertex Shader" sections of
    // tutorial http://learnopengl.com/book/offline%20learnopengl.pdf
    // and   https://open.gl/drawing
    
    
    
    

    // Rendering Loop
    while (glfwWindowShouldClose(mWindow) == false) {
        if (glfwGetKey(mWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(mWindow, true);

        // Background Fill Color
        glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        // ?? glDrawPixels

        // Flip Buffers and Draw
        glfwSwapBuffers(mWindow);
        glfwPollEvents();
    }   glfwTerminate();
    return EXIT_SUCCESS;
}
