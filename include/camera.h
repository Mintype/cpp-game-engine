#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
    // Constructor - Initialize camera with position and orientation
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 3.0f),
           glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f),
           glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f));

    // getViewMatrix() - Get the view matrix for rendering
    glm::mat4 getViewMatrix() const;

    // moveForward() - Move camera forward along its facing direction
    void moveForward(float distance);

    // moveRight() - Move camera right relative to its orientation
    void moveRight(float distance);

    // moveUp() - Move camera up in world space
    void moveUp(float distance);

    // rotate() - Rotate camera by pitch and yaw angles
    //   - pitchDelta: Rotation around right axis (up/down look)
    //   - yawDelta: Rotation around up axis (left/right look)
    void rotate(float pitchDelta, float yawDelta);

    // Getter methods - Access camera properties
    glm::vec3 getPosition() const { return position; }
    glm::vec3 getFront() const { return front; }
    glm::vec3 getRight() const { return right; }
    glm::vec3 getUp() const { return up; }

    // Setter methods - Modify camera properties
    void setPosition(glm::vec3 newPosition) { position = newPosition; }
    void setSpeed(float newSpeed) { speed = newSpeed; }
    void setSensitivity(float newSensitivity) { sensitivity = newSensitivity; }

private:
    // Camera position in world space
    glm::vec3 position;

    // Direction vectors
    glm::vec3 front;   // Direction camera is looking
    glm::vec3 right;   // Right vector (perpendicular to front and up)
    glm::vec3 up;      // Up vector (world up is usually Y axis)
    glm::vec3 worldUp; // Constant world up direction for recalculations

    // Rotation angles
    float pitch;       // Vertical rotation angle (up/down)
    float yaw;         // Horizontal rotation angle (left/right)

    // Movement and rotation speeds
    float speed;       // Movement speed multiplier
    float sensitivity; // Mouse/rotation sensitivity

    // updateVectors() - Recalculate direction vectors after rotation
    void updateVectors();
};

#endif
