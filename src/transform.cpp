#include "transform.h"
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

Transform::Transform()
    : position(0.0f), rotation(0.0f), scaleVec(1.0f),
      modelMatrix(glm::mat4(1.0f)) {
}

void Transform::setPosition(const glm::vec3& pos) {
    position = pos;
    updateModelMatrix();
}

void Transform::setRotation(const glm::vec3& rot) {
    rotation = rot;
    updateModelMatrix();
}

void Transform::setScale(const glm::vec3& scl) {
    scaleVec = scl;
    updateModelMatrix();
}

glm::vec3 Transform::getPosition() const {
    return position;
}

glm::vec3 Transform::getRotation() const {
    return rotation;
}

glm::vec3 Transform::getScale() const {
    return scaleVec;
}

void Transform::translate(const glm::vec3& offset) {
    position += offset;
    updateModelMatrix();
}

void Transform::rotate(const glm::vec3& axis, float angle) {
    // Convert axis-angle to Euler angles and add to rotation
    glm::quat q = glm::angleAxis(angle, glm::normalize(axis));
    glm::quat currentQuat = glm::quat(rotation);
    currentQuat = q * currentQuat;
    rotation = glm::eulerAngles(currentQuat);
    updateModelMatrix();
}

void Transform::scale(const glm::vec3& factor) {
    scaleVec *= factor;
    updateModelMatrix();
}

void Transform::updateModelMatrix() {
    modelMatrix = glm::mat4(1.0f);
    modelMatrix = glm::translate(modelMatrix, position);
    modelMatrix = glm::rotate(modelMatrix, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
    modelMatrix = glm::rotate(modelMatrix, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
    modelMatrix = glm::rotate(modelMatrix, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
    modelMatrix = glm::scale(modelMatrix, scaleVec);
}

glm::mat4 Transform::getModelMatrix() const {
    return modelMatrix;
}
