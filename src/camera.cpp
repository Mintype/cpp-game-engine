#include "camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <algorithm>

Camera::Camera(glm::vec3 position, glm::vec3 front, glm::vec3 up)
    : position(position), front(front), up(up), worldUp(up),
      pitch(0.0f), yaw(-90.0f), speed(5.0f), sensitivity(0.1f) {
    
    right = glm::normalize(glm::cross(front, worldUp));
    up = glm::normalize(glm::cross(right, front));
}

// getViewMatrix() - Create and return the view matrix
glm::mat4 Camera::getViewMatrix() const {
    // Parameters:
    // - position: Camera location in world space
    // - position + front: Target point to look at
    // - up: Which direction is "up"
    return glm::lookAt(position, position + front, up);
}

// moveForward() - Move camera forward along its facing direction
void Camera::moveForward(float distance) {
    position += front * distance;
}

// moveRight() - Move camera right relative to its orientation
void Camera::moveRight(float distance) {
    position += right * distance;
}

// moveUp() - Move camera up in world space
void Camera::moveUp(float distance) {
    position += worldUp * distance;
}

// rotate() - Rotate camera by pitch and yaw
void Camera::rotate(float pitchDelta, float yawDelta) {
    pitch += pitchDelta * sensitivity;
    yaw += yawDelta * sensitivity;

    // Clamp pitch to prevent camera flip
    pitch = std::clamp(pitch, -89.0f, 89.0f);

    updateVectors();
}

// updateVectors() - Recalculate direction vectors based on pitch/yaw
void Camera::updateVectors() {
    // Convert angles to radians
    // GLM trigonometric functions expect radians, not degrees
    float pitchRad = glm::radians(pitch);
    float yawRad = glm::radians(yaw);

    // Calculate new front vector from pitch and yaw

    // Pitch: Rotation around X axis (up/down look)
    //   - positive = look up
    //   - negative = look down
    //
    // Yaw: Rotation around Y axis (left/right look)
    //   - positive = look right
    //   - negative = look left
    glm::vec3 newFront;
    newFront.x = cos(pitchRad) * cos(yawRad);
    newFront.y = sin(pitchRad);
    newFront.z = cos(pitchRad) * sin(yawRad);
    front = glm::normalize(newFront);
    
    right = glm::normalize(glm::cross(front, worldUp));
    up = glm::normalize(glm::cross(right, front));
}
