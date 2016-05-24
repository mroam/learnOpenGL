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
    float distanceFromOrigin = sqrt((vertexLoc.x * vertexLoc.x) + (vertexLoc.y * vertexLoc.y) + (vertexLoc.z * vertexLoc.z));
    color = vec4(vertexLoc.xyz, 1.0f - distanceFromOrigin / sqrt(2));
    //color.a = 0.1f;
    //color = vec4(dist, dist, vertexLoc.z, 1.0f); //This works and made a weird blue stained glass thing with an orb of light
    //color = vertexColor;   // this worked!
    //color = vec4(1.0f, 0.5f, gl_FragCoord.z, 1.0f); // this didn't work
    //color = vec4(0.0f, 0.5f, 0.2f, 1.0f); // this works! vec4(1.0f, 0.5f, 0.2f, 1.0f); is orangish
    // color = vertexColor;    // fancier version for shaders lesson 2
    // outColor = vec4(1.0, 1.0, 1.0, 1.0);
    //atan(vertexLoc.y, vertexLoc.x) * 180 / PI;
    float C = (1 - abs(2 * L - 1)) * S;
    float X = C * (1 - abs(mod(H/60, 2) - 1))
    float m = L - C/2;
    if(H <= 0 && H < 60){
        
    }else if(h <= 60 && H < 120){
        
    }else if(h <= 120 && H < 180){
        
    }else if(h <= 180 && H < 240){
        
    }else if(h <= 240 && H < 300){
        
    }else if(h <= 300 && H < 360){
        
    }
}
