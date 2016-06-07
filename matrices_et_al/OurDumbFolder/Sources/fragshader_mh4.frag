#version 330 core
// Fragment Shader!! Is version 330 a good version??
// from learnopengl.com/#!Getting-started/Shaders
// (see also http://open.gl/drawing for a slightly different version.)

#define M_PI 3.1415926535897932384626433832795

// in vec4 vertexColor; // The input variable from the vertext shader (same name & same type)
in vec4 vertexLoc;
out vec4 color;



void main(){
    float distanceFromOrigin = sqrt((vertexLoc.x * vertexLoc.x) + (vertexLoc.y * vertexLoc.y) + (vertexLoc.z * vertexLoc.z));
    float angle = atan(vertexLoc.y, vertexLoc.x) * 180.0 / M_PI;
    if(angle < 0){angle = angle + 360.0;}
    float scaledAngle = angle * 4.25;
    float r = max(min(510 - min(abs(scaledAngle - 1530), scaledAngle), 255), 0)/256.0;
    float g = max(min(510 - abs(scaledAngle - 510), 255),0)/256.0;
    float b = max(min(510 - abs(scaledAngle - 1020), 255), 0)/256.0;
    
    /*if(r == 0) r = distanceFromOrigin/sqrt(3);
    if(g == 0) g = distanceFromOrigin/sqrt(3);
    if(b == 0) b = distanceFromOrigin/sqrt(3);*/
    
    float darkness = 1.0 - distanceFromOrigin / sqrt(3);
    r *= darkness;
    g *= darkness;
    b *= darkness;
    
    color = vec4(r, g, b, 1.0);
    
    //color = vec4(abs(1-mod(abs(vertexLoc.x * 10), 2)),abs(1.5-mod(abs(vertexLoc.y * 10), 3)), abs(2.5-mod(abs(vertexLoc.z * 10), 5)), 1.0);
}
