#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Transform {
public:
    Transform();

    // Setters
    void setPosition(const glm::vec3& pos);
    void setRotation(const glm::vec3& rot);
    void setScale(const glm::vec3& scl);

    // Getters
    glm::vec3 getPosition() const;
    glm::vec3 getRotation() const;
    glm::vec3 getScale() const;

    // Transformations
    void translate(const glm::vec3& offset);
    void rotate(const glm::vec3& axis, float angle);
    void scale(const glm::vec3& factor);

    // Matrix operations
    glm::mat4 getModelMatrix() const;

private:
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scaleVec;

    void updateModelMatrix();
    glm::mat4 modelMatrix;
};

#endif
