#version 330 core
// Fragment Shader!! Is version 330 a good version??
// from learnopengl.com/#!Getting-started/Shaders
// (see also http://open.gl/drawing for a slightly different version.)

#define M_PI 3.1415926535897932384626433832795

// in vec4 vertexColor; // The input variable from the vertext shader (same name & same type)
in vec4 vertexLoc;
out vec4 color;
//attribute gl_Vertex vertex;
void main()
{
    float distanceFromOrigin = sqrt((vertexLoc.x * vertexLoc.x) + (vertexLoc.y * vertexLoc.y) + (vertexLoc.z * vertexLoc.z));
    //color = vec4(vertexLoc.xyz, 1.0f - distanceFromOrigin / sqrt(2));
    //color.a = 0.1f;
    //color = vec4(dist, dist, vertexLoc.z, 1.0f); //This works and made a weird blue stained glass thing with an orb of light
    //color = vertexColor;   // this worked!
    //color = vec4(1.0f, 0.5f, gl_FragCoord.z, 1.0f); // this didn't work
    //color = vec4(0.0f, 0.5f, 0.2f, 1.0f); // this works! vec4(1.0f, 0.5f, 0.2f, 1.0f); is orangish
    // color = vertexColor;    // fancier version for shaders lesson 2
    // outColor = vec4(1.0, 1.0, 1.0, 1.0);
    
    float H /* hue */ = atan(vertexLoc.y, vertexLoc.x) * 180.0 / M_PI;
    
//    float S /* saturation */ = vertexLoc.y;
//    float L /* lightness */ = vertexLoc.z;
    float S /* saturation */ = distanceFromOrigin * 50.0;
    float L /* lightness */ = 100;

    
    /* working from http://www.rapidtables.com/convert/color/hsv-to-rgb.htm
     to convert HSB (HSL? HSV?) to RGB ... */
    float C = (1.0 - abs(2.0 * L - 1.0)) * S;
    float X = C * (1.0 - abs(mod(H/60.0, 2) - 1.0));
    float m = L - C/2.0;
    vec3 RGBPrime;
    if(H <= 0 && H < 60){
        RGBPrime = vec3(C, X, 0);
    }else if(H <= 60 && H < 120){
        RGBPrime = vec3(X, C, 0);
    }else if(H <= 120 && H < 180){
        RGBPrime = vec3(0, C, X);
    }else if(H <= 180 && H < 240){
        RGBPrime = vec3(0, X, C);
    }else if(H <= 240 && H < 300){
        RGBPrime = vec3(X, 0, C);
    }else if(H <= 300 && H < 360){
        RGBPrime = vec3(C, 0, X);
    }
    color = vec4(RGBPrime.x + m, RGBPrime.y + m, RGBPrime.z + m, 1.0f);
//    float angle = atan(vertexLoc.y, vertexLoc.x) * 180.0 / M_PI;
//    float scaledAngle = angle * 4.25;
//    float r = max(max(min(510 - scaledAngle, 255), 0), max(510 - min(scaledAngle - 1020, 255), 0));
//    float g = max(min(510 - abs(scaledAngle - 510), 255),0);
//    float b = max(min(510 - abs(scaledAngle - 1020), 255), 0);
//    color = vec4(r, g, b, 1.0);
    
//    float r = max(0, min(255, abs(768 - scaledAngle) - 256));
//    float g = max(0, min(255, 512 - abs(1024 - scaledAngle)));
//    float b = max(0, min(255, 512 - abs(512 - scaledAngle)));
//    color = vec4(r, g, b, 1.0);
}
