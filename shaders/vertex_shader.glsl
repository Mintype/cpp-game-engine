#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

// Output texture coordinates to fragment shader
out vec2 TexCoord;

// Transformation matrices
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    
    // Pass the texture coordinates to the fragment shader
    TexCoord = aTexCoord;
}
