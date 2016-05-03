#version 330 core
// vertex shader!! Is 330 a good version number??
// from http://learnopengl.com/#!Getting-started/Shaders
// (see also http://open.gl/drawing for a slightly different version

layout (location = 0) in vec3 position; // The position variable has attribute position 0
out vec4 vertexLoc;
// out vec4 vertexColor; // Specify a color output to the fragment shader
// fancier, for shader2 lesson

void main() {
    gl_Position = vec4( position.x, position.y, position.z, 1.0);
    vertexLoc = vec4(position.x, position.y, position.z, 1.0f);
    // the following is fancier, for shader2 lesson
   // gl_Position = vec4(position, 1.0); // See how we directly give a vec3 to vec4's constructor
   // vertexColor = vec4( 0.5f, 0.0f, 0.0f, 1.0f); // Set the output variable to a dark-red color

    
    // our experiment with adjusting point locations, perhaps misled
    // because numbers come out of shaders in range -1 .. 1 and clip the rest
    // gl_Position = vec4(position.x /*  *100 */, position.y /*  *100 */, 0.0, 1.0);
}

