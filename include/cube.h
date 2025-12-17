#ifndef CUBE_H
#define CUBE_H

#include "mesh.h"
#include "transform.h"
#include "texture.h"

class Cube {
public:
    Mesh mesh;
    Transform transform;
    Texture* texture;

    Cube();
    ~Cube();

private:
    // 24 vertices for a cube - 4 vertices per face for unique texture coordinates
    static const float vertices[];
    static const unsigned int vertexCount;
    
    // Texture coordinates for each vertex (u, v)
    static const float texCoords[];
    
    // 36 indices to define 12 triangles (6 faces * 2 triangles per face)
    static const unsigned int indices[];
    static const unsigned int indexCount;
};

#endif
