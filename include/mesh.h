#ifndef MESH_H
#define MESH_H

#include <glad/glad.h>
#include <vector>

class Mesh {
public:
    unsigned int VAO, VBO;

    Mesh(const float* vertices, unsigned int vertexCount);
    ~Mesh();

    void bind() const;
    void draw() const;
    
private:
    unsigned int vertexCount;
};

#endif
