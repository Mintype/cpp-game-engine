#include "mesh.h"

// Non-indexed mesh constructor
Mesh::Mesh(const float* vertices, unsigned int vertexCount)
    : VAO(0), VBO(0), EBO(0), TexCoordVBO(0), vertexCount(vertexCount), indexCount(0), isIndexed(false) {
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // Bind VAO
    glBindVertexArray(VAO);

    // Bind and fill VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertexCount * 3 * sizeof(float), vertices, GL_STATIC_DRAW);

    // Set vertex attribute pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Unbind VBO and VAO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

// Indexed mesh constructor (positions only)
Mesh::Mesh(const float* vertices, unsigned int vertexCount, const unsigned int* indices, unsigned int indexCount)
    : VAO(0), VBO(0), EBO(0), TexCoordVBO(0), vertexCount(vertexCount), indexCount(indexCount), isIndexed(true) {
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    // Bind VAO
    glBindVertexArray(VAO);

    // Bind and fill VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertexCount * 3 * sizeof(float), vertices, GL_STATIC_DRAW);

    // Bind and fill EBO (Element Buffer Object / Index Buffer)
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(unsigned int), indices, GL_STATIC_DRAW);

    // Set vertex attribute pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Unbind VBO (but keep EBO bound to VAO)
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

// Indexed mesh constructor (positions + texture coordinates)
Mesh::Mesh(const float* vertices, unsigned int vertexCount, const float* texCoords, const unsigned int* indices, unsigned int indexCount)
    : VAO(0), VBO(0), EBO(0), TexCoordVBO(0), vertexCount(vertexCount), indexCount(indexCount), isIndexed(true) {
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &TexCoordVBO);
    glGenBuffers(1, &EBO);

    // Bind VAO
    glBindVertexArray(VAO);

    // Bind and fill VBO (positions)
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertexCount * 3 * sizeof(float), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Bind and fill TexCoord VBO (texture coordinates)
    glBindBuffer(GL_ARRAY_BUFFER, TexCoordVBO);
    glBufferData(GL_ARRAY_BUFFER, vertexCount * 2 * sizeof(float), texCoords, GL_STATIC_DRAW);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);

    // Bind and fill EBO (Element Buffer Object / Index Buffer)
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(unsigned int), indices, GL_STATIC_DRAW);

    // Unbind VBO (but keep EBO bound to VAO)
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

Mesh::~Mesh() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    if (EBO != 0) {
        glDeleteBuffers(1, &EBO);
    }
    if (TexCoordVBO != 0) {
        glDeleteBuffers(1, &TexCoordVBO);
    }
}

void Mesh::bind() const {
    glBindVertexArray(VAO);
}

void Mesh::draw() const {
    if (isIndexed) {
        // Draw using indices
        glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
    } else {
        // Draw without indices
        glDrawArrays(GL_TRIANGLES, 0, vertexCount);
    }
}
