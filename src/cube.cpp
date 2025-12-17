#include "cube.h"

// 8 unique vertices for a cube (no duplicates!)
// Each vertex is shared by 3 faces
const float Cube::vertices[] = {
    // Position        (x,     y,     z)
    -0.5f, -0.5f, -0.5f,  // 0: back-bottom-left
     0.5f, -0.5f, -0.5f,  // 1: back-bottom-right
     0.5f,  0.5f, -0.5f,  // 2: back-top-right
    -0.5f,  0.5f, -0.5f,  // 3: back-top-left
    -0.5f, -0.5f,  0.5f,  // 4: front-bottom-left
     0.5f, -0.5f,  0.5f,  // 5: front-bottom-right
     0.5f,  0.5f,  0.5f,  // 6: front-top-right
    -0.5f,  0.5f,  0.5f,  // 7: front-top-left
};

const unsigned int Cube::vertexCount = 8;

// 36 indices define 12 triangles (6 faces with 2 triangles each)
// Each index references one of the 8 unique vertices
const unsigned int Cube::indices[] = {
    // Back face (Z-)
    0, 1, 2,
    0, 2, 3,
    
    // Front face (Z+)
    4, 6, 5,
    4, 7, 6,
    
    // Left face (X-)
    0, 3, 7,
    0, 7, 4,
    
    // Right face (X+)
    1, 5, 6,
    1, 6, 2,
    
    // Bottom face (Y-)
    0, 5, 1,
    0, 4, 5,
    
    // Top face (Y+)
    3, 6, 7,
    3, 2, 6,
};

const unsigned int Cube::indexCount = 36;

// Constructor - initializes the cube mesh with indexed vertices and the transform
Cube::Cube() : mesh(vertices, vertexCount, indices, indexCount), transform() {
    // Mesh constructor handles all GPU setup
}
