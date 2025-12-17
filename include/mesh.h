#ifndef MESH_H
#define MESH_H

#include <glad/glad.h>
#include <vector>

class Mesh {
public:
    unsigned int VAO, VBO, EBO, TexCoordVBO;

    // Constructor for non-indexed mesh
    Mesh(const float* vertices, unsigned int vertexCount);
    
    // Constructor for indexed mesh with positions only
    Mesh(const float* vertices, unsigned int vertexCount, const unsigned int* indices, unsigned int indexCount);
    
    // Constructor for indexed mesh with positions and texture coordinates
    Mesh(const float* vertices, unsigned int vertexCount, const float* texCoords, const unsigned int* indices, unsigned int indexCount);
    ~Mesh();

    void bind() const;
    void draw() const;
    
private:
    unsigned int vertexCount;
    unsigned int indexCount;
    bool isIndexed;
};

#endif
