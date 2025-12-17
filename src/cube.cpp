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

// Texture coordinates for each vertex (u, v) from 0.0 to 1.0
// Each face has its own set of vertices with full 0-1 texture coverage
const float Cube::texCoords[] = {
    // Back face
    0.0f, 0.0f,
    1.0f, 0.0f,
    1.0f, 1.0f,
    0.0f, 1.0f,
    
    // Front face
    0.0f, 0.0f,
    1.0f, 0.0f,
    1.0f, 1.0f,
    0.0f, 1.0f,
    
    // Left face
    0.0f, 0.0f,
    1.0f, 0.0f,
    1.0f, 1.0f,
    0.0f, 1.0f,
    
    // Right face
    0.0f, 0.0f,
    1.0f, 0.0f,
    1.0f, 1.0f,
    0.0f, 1.0f,
    
    // Bottom face
    0.0f, 0.0f,
    1.0f, 0.0f,
    1.0f, 1.0f,
    0.0f, 1.0f,
    
    // Top face
    0.0f, 0.0f,
    1.0f, 0.0f,
    1.0f, 1.0f,
    0.0f, 1.0f,
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
Cube::Cube() : mesh(vertices, vertexCount, texCoords, indices, indexCount), transform() {
    // Mesh constructor handles all GPU setup including texture coordinates
    // Load texture - this assumes you have a texture file named "container.png" or similar
    // in the working directory or a textures folder
    texture = new Texture("./textures/grass_block.png");
}

// Destructor - clean up texture
Cube::~Cube() {
    if (texture) {
        delete texture;
        texture = nullptr;
    }
}
