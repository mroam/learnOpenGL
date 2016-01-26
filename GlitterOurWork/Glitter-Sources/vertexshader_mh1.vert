version 150 core
// vertex shader!! Is 330 a good version number??
// from http://open.gl/drawing

layout (location = 0) in vec3 position;
void main() {
    gl_Position = vec4(position.x /*  *100 */, position.y /*  *100 */, 0.0, 1.0);
}