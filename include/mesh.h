#ifndef MESH_H
#define MESH_H

#include <glad/glad.h>
#include <vector>

class Mesh {
public:
    unsigned int VAO, VBO, EBO;

    // Constructor for non-indexed mesh
    Mesh(const float* vertices, unsigned int vertexCount);
    
    // Constructor for indexed mesh
    Mesh(const float* vertices, unsigned int vertexCount, const unsigned int* indices, unsigned int indexCount);
    ~Mesh();

    void bind() const;
    void draw() const;
    
private:
    unsigned int vertexCount;
    unsigned int indexCount;
    bool isIndexed;
};

#endif
