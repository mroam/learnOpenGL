#version 330 core
// Fragment Shader!! Is version 330 a good version??
// from learnopengl.com/#!Getting-started/Shaders
// (see also http://open.gl/drawing for a slightly different version.)

// in vec4 vertexColor; // The input variable from the vertext shader (same name & same type)
in vec4 vertexLoc;
out vec4 color;
//attribute gl_Vertex vertex;
void main()
{
    float dist = 1.0f - sqrt(vertexLoc.x * vertexLoc.x + vertexLoc.y * vertexLoc.y);
    color = vec4(dist, dist, vertexLoc.z, vertexLoc.z);
    color.a = 0.1f;
    //color = vec4(dist, dist, vertexLoc.z, 1.0f); //This works and made a weird blue stained glass thing with an orb of light
    //color = vertexColor;   // this worked!
    //color = vec4(1.0f, 0.5f, gl_FragCoord.z, 1.0f); // this didn't work
    //color = vec4(0.0f, 0.5f, 0.2f, 1.0f); // this works! vec4(1.0f, 0.5f, 0.2f, 1.0f); is orangish
    // color = vertexColor;    // fancier version for shaders lesson 2
    // outColor = vec4(1.0, 1.0, 1.0, 1.0);
}
