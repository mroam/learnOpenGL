#version 330 core
// Fragment Shader!! Is version 330 a good version??
// from learnopengl.com/#!Getting-started/Shaders
// (see also http://open.gl/drawing for a slightly different version.)

// in vec4 vertexColor; // The input variable from the vertext shader (same name & same type)

out vec4 color;

void main()
{
    color = vec4(1.0f, 0.7f, 0.5f, 1.0f); // orange-ish.
    // color = vertexColor;    // fancier version for shaders lesson 2
    // outColor = vec4(1.0, 1.0, 1.0, 1.0);
}


