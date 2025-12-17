#include "cube.h"

// 24 vertices for a cube - 4 vertices per face with unique texture coordinates
// This way each face can have proper 0-1 texture coordinates
const float Cube::vertices[] = {
    // Back face (Z = -0.5)
    -0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
    -0.5f,  0.5f, -0.5f,
    
    // Front face (Z = 0.5)
    -0.5f, -0.5f,  0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    
    // Left face (X = -0.5)
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
    
    // Right face (X = 0.5)
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f, -0.5f,
    
    // Bottom face (Y = -0.5)
    -0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,
    
    // Top face (Y = 0.5)
    -0.5f,  0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
};

const unsigned int Cube::vertexCount = 24;

// Texture coordinates for each vertex (u, v)
// The texture is a 4x3 grid: each cell is 0.25 wide (1/4) and 0.333 tall (1/3)
// Grid layout:
//   nothing-top-nothing-nothing     (row 0, y: 0.0-0.333)
//   side-side-side-side            (row 1, y: 0.333-0.667)
//   nothing-bottom-nothing-nothing  (row 2, y: 0.667-1.0)
const float Cube::texCoords[] = {
    // Back face - uses side texture (column 0, row 1)
    0.0f, 0.667f,
    0.25f, 0.667f,
    0.25f, 0.333f,
    0.0f, 0.333f,
    
    // Front face - uses side texture (column 1, row 1)
    0.25f, 0.667f,
    0.5f, 0.667f,
    0.5f, 0.333f,
    0.25f, 0.333f,
    
    // Left face - uses side texture (column 2, row 1)
    0.5f, 0.667f,
    0.75f, 0.667f,
    0.75f, 0.333f,
    0.5f, 0.333f,
    
    // Right face - uses side texture (column 3, row 1)
    0.75f, 0.667f,
    1.0f, 0.667f,
    1.0f, 0.333f,
    0.75f, 0.333f,
    
    // Bottom face - uses bottom texture (column 1, row 2)
    0.25f, 0.667f,
    0.5f, 0.667f,
    0.5f, 1.0f,
    0.25f, 1.0f,
    
    // Top face - uses top texture (column 1, row 0)
    0.25f, 0.0f,
    0.5f, 0.0f,
    0.5f, 0.333f,
    0.25f, 0.333f,
};

// 36 indices define 12 triangles (6 faces with 2 triangles each)
// Now indices reference the 24 unique vertices (4 per face)
const unsigned int Cube::indices[] = {
    // Back face (0-3)
    0, 1, 2,
    0, 2, 3,
    
    // Front face (4-7)
    4, 6, 5,
    4, 7, 6,
    
    // Left face (8-11)
    8, 9, 10,
    8, 10, 11,
    
    // Right face (12-15)
    12, 14, 13,
    12, 15, 14,
    
    // Bottom face (16-19)
    16, 18, 17,
    16, 19, 18,
    
    // Top face (20-23)
    20, 21, 22,
    20, 22, 23,
};

const unsigned int Cube::indexCount = 36;

// Constructor - initializes the cube mesh with indexed vertices, texture coordinates, and the transform
Cube::Cube(const char* texturePath) : mesh(vertices, vertexCount, texCoords, indices, indexCount), transform() {
    // Mesh constructor handles all GPU setup including texture coordinates
    // Load texture from the provided path
    texture = new Texture(texturePath);
}

// Destructor - clean up texture
Cube::~Cube() {
    if (texture) {
        delete texture;
        texture = nullptr;
    }
}
