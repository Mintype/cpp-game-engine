#version 330 core

// Input texture coordinates from vertex shader
in vec2 TexCoord;

// Texture sampler uniform
uniform sampler2D texture1;

// Output color
out vec4 FragColor;

void main() {
    // Sample the texture at the given texture coordinates
    FragColor = texture(texture1, TexCoord);
}
