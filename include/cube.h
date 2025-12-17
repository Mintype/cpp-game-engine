#ifndef CUBE_H
#define CUBE_H

#include "mesh.h"
#include "transform.h"

class Cube {
public:
    Mesh mesh;
    Transform transform;

    Cube();

private:
    // 8 unique vertices for a unit cube (no duplicates)
    static const float vertices[];
    static const unsigned int vertexCount;
    
    // 36 indices to define 12 triangles (6 faces * 2 triangles per face)
    static const unsigned int indices[];
    static const unsigned int indexCount;
};

#endif
