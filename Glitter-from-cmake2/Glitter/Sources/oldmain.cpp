//
//  oldmain.cpp
//  Glitter
//
//  Created by student on 3/8/16.
//
//

#include <stdio.h>


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
 // (see also http://open.gl/drawing for a slightly different version.)
 
 GLuint VBO;
 glGenBuffers(1, &VBO);
 
 glBindBuffer(GL_ARRAY_BUFFER, VBO);
 
 glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
 
 -----
 // this is simple vertext shader
 // if we wanted to include this here (rather than remote file) we could say
 // const GLchar* vertextSource = "   blah blah blah \n"
 version 330 core
 layout (location = 0) in vec3 position;
 
 void main() {
 gl_Position = vec4(position.x, position.y, position.z, 1.0);
 }
 */



int oldmain(int argc, char * argv[]) {
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
    glfwMakeContextCurrent(mWindow);  // <== has to be before "glGenBuffers( )
    gladLoadGL();
    fprintf(stderr, "OpenGL %s\n", glGetString(GL_VERSION));
    
    
    // Create a Vertex Buffer Object and copy the vertex data to it
    /*     our vertices, duh... */
    // from http://learnopengl.com/book/offline%20learnopengl.pdf  page 37-38
    
    GLfloat vertices[] = {  /* note: the z's are 0.0, */
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };
    
    
    GLuint VBO;
    glGenBuffers(1, &VBO);
    // Beware: crashes when glGenBuffers( ) is before "glfwMakeContextCurrent( )"
    
    
    //// Now we'll try to load some shaders from external files
    // source stackoverflow.com/questions...
    std::ifstream vertfn("vertextshader_mh1.vert");
    std::stringstream ourVertexShaderBuffer;
    ourVertexShaderBuffer << vertfn.rdbuf( );
    // conversion from string to GLchar *   is from
    //  http://stackoverflow.com/questions/34836454/neither-vertex-shader-nor-fragment-shader-are-compiling-after-loading-from-a-fil
    // char * vertShaderSource = ourVertexShaderBuffer.c_str( );//const_cast<const GLchar*>(ourVertexShaderBuffer.str( ));
    std::string vertShaderSourceStr = ourVertexShaderBuffer.str( );
    const char * vertShaderSourceChars = vertShaderSourceStr.c_str( );  // "const" was important!!
    
    GLuint ourVertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(ourVertexShader, 1, &vertShaderSourceChars, NULL);
    glCompileShader(ourVertexShader);
    
    GLint ourShaderCompilationStatus;
    GLchar infoLog[512];
    glGetShaderiv(ourVertexShader, GL_COMPILE_STATUS, &ourShaderCompilationStatus);
    std::cout << "Vertex shader compilation status: " << (ourShaderCompilationStatus == GL_TRUE) << "\n";
    if (ourShaderCompilationStatus != GL_TRUE) {
        glGetShaderInfoLog(ourVertexShader, 512, NULL, infoLog);
        std::cout << "ERROR--Vertex Shader Compilation Failed.\n" << infoLog << std::endl;
    }
    
    std::ifstream fragfn("fragshader_mh1.vert");
    std::stringstream ourFragmentShaderBuffer;
    ourFragmentShaderBuffer << fragfn.rdbuf( );
    
    std::string fragShaderSourceStr = ourFragmentShaderBuffer.str( );
    const char * fragShaderSourceChars = fragShaderSourceStr.c_str( );  // "const" was important!!
    
    GLuint ourFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(ourFragmentShader, 1, &fragShaderSourceChars, NULL);
    glCompileShader(ourFragmentShader);
    
    glGetShaderiv(ourFragmentShader, GL_COMPILE_STATUS, &ourShaderCompilationStatus);
    std::cout << "Fragment shader compilation status: " << ourShaderCompilationStatus << "\n";
    if (ourShaderCompilationStatus != GL_TRUE) {
        glGetShaderInfoLog(ourFragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR--Fragment Shader Compilation Failed.\n" << infoLog << std::endl;
    }
    
    
    // Link the vertex and fragment shader into a shader program
    GLuint ourShaderProgram = glCreateProgram( );
    glAttachShader(ourShaderProgram, ourVertexShader);  // learnopengl.com's order vert then frag
    glAttachShader(ourShaderProgram, ourFragmentShader);
    glBindFragDataLocation(ourShaderProgram, 0, "outColor");
    glLinkProgram(ourShaderProgram);
    
    // check for errors:
    GLint ourShadersLinkStatus;
    glGetProgramiv(ourShaderProgram, GL_LINK_STATUS, &ourShadersLinkStatus);
    if (!ourShadersLinkStatus) {
        glGetProgramInfoLog(ourShaderProgram, 512, NULL, infoLog);
        std::cout << "DANG!--Linking of Shaders failed.\n" << infoLog << std::endl;
    }
    
    
    
    glUseProgram(ourShaderProgram);
    // now that the shader objects are linked, we can delete them (says learnopengl.com)
    // don't forget...
    glDeleteShader(ourVertexShader);
    glDeleteShader(ourFragmentShader);
    
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    // Specify the layout of the vertex data
    // note: instead of hard-wiring the first 0 for both method calls, could use:
    //     // GLint posAttrib = glGetAttribLocation(ourShaderProgram, "position");
    glVertexAttribPointer(
                          /* which vertex attribute: */ 0,
                          /* number of inputs: */ 3,
                          /* type of data: */ GL_FLOAT,
                          /* normalize: */ GL_FALSE,
                          /* stride: */ 3 * sizeof(GLfloat),
                          /* offset: */ (GLvoid*)0
                          );
    /* here's the opengl.com version of specifying layout of vertex data, which is different */
    // GLint posAttrib = glGetAttribLocation(ourShaderProgram, "position");
    // glVertexAttribPointer(posAttrib, /* number of inputs: */ 2, GL_FLOAT, /* normalize: */ GL_FALSE, /* stride: */0, /* offset: */ 0);
    
    
    // Create Vertex Array Object
    GLuint ourVao;
    glGenVertexArrays(1, &ourVao);
    
    
    glEnableVertexAttribArray( /* vertex attribute location: */ 0);
    // BEWARE: there is a method ending with ArrayAttrib instead of AttribArray!
    // glEnableVertexArrayAttrib(/*vaobj:*/ ourVao, /* vertex attribute location: */ 0);
    /* vertex attributes are disabled by default, so this looks important. See http://learnopengl.com/#!Getting-started/Hello-Triangle */
    /* hey glEnableVertexArrayAttrib( ) has two versions, one expecting just (GLuint index) while the other is expecting (GLuint vaobj, GLuint index) */
    
    
    
    
    
    // Rendering Loop
    while (glfwWindowShouldClose(mWindow) == false) {
        if (glfwGetKey(mWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(mWindow, true);
        
        // Background Fill Color
        glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        //  glDrawPixels
        // Draw a triangle using our 3 vertices
        
        /*  ... This compiles but nothing shows on the screen:
         Perhaps the shader versions are bad??
         Perhaps the vertices are out of bounds??
         Perhaps the shaders aren't talking to each other? (they're from different tutorials)
         Howzabout we find a sample program that doesn't use GLEW, instead using GLFW like us.
         ( http://open.gl/drawing has listing that uses GLEW so not exactly the same as us.
         Perhaps tutorial http://learnopengl.com/book/offline%20learnopengl.pdf has non-glew
         listing to compare to?
         */
        /* to do some drawing, we use Bind(ourVao) and then (un)Bind it with Bind(0) */
        glBindVertexArray(ourVao);
        glDrawArrays(GL_TRIANGLES, /* starting at which vertex: */ 0, /* howManyVertices: */ 3);
        glBindVertexArray(/* unbinding so as not to mess it up */0);
        
        // Flip Buffers and Draw
        glfwSwapBuffers(mWindow);
        glfwPollEvents();
    }   glfwTerminate();
    return EXIT_SUCCESS;
}
