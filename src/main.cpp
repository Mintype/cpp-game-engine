#include <glad/glad.h>
#include <iostream>
#include "window.h"
#include "shader.h"
#include "cube.h"
#include "camera.h"

int main() {
    try {
        // Create window
        Window window(800, 600, "Cube");

        // Load shaders
        Shader shader("./shaders/vertex_shader.glsl", "./shaders/fragment_shader.glsl");

        // Create camera
        Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

        // Create cube and transform
        Cube cube("./textures/grass_block.png");

        // Apply initial transform to the cube
        cube.transform.setPosition(glm::vec3(0.0f, 0.0f, -5.0f));
        cube.transform.setScale(glm::vec3(1.0f, 1.0f, 1.0f));
        // cube.transform.setRotation(glm::vec3(45.0f, 45.0f, 0.0f));

        // Create projection matrix (perspective view)
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

        // Render loop
        while (!window.shouldClose()) {
            // Clear screen
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            // Enable depth testing for 3D rendering
            glEnable(GL_DEPTH_TEST);

            // Disable wireframe mode to see the texture (comment out to see wireframe)
            // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

            // Simple camera controls
            if (window.isKeyPressed(GLFW_KEY_W)) camera.moveForward(0.05f);
            if (window.isKeyPressed(GLFW_KEY_S)) camera.moveForward(-0.05f);
            if (window.isKeyPressed(GLFW_KEY_A)) camera.moveRight(-0.05f);
            if (window.isKeyPressed(GLFW_KEY_D)) camera.moveRight(0.05f);
            if (window.isKeyPressed(GLFW_KEY_SPACE)) camera.moveUp(0.05f);
            if (window.isKeyPressed(GLFW_KEY_LEFT_CONTROL)) camera.moveUp(-0.05f);

            // Rotate cube each frame
            cube.transform.rotate(glm::vec3(1.0f, 1.0f, 0.0f), 0.001f);

            // Draw cube with its transform
            shader.use();
            shader.setMat4("model", cube.transform.getModelMatrix());
            shader.setMat4("view", camera.getViewMatrix());
            shader.setMat4("projection", projection);
            
            // Bind the texture before drawing
            if (cube.texture) {
                cube.texture->setTextureUnit(0);  // Use texture unit 0
                shader.setInt("texture1", 0);      // Tell shader to sample from texture unit 0
            }
            
            cube.mesh.bind();
            cube.mesh.draw();

            // Swap buffers and poll events
            window.swapBuffers();
            window.pollEvents();
        }

        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return -1;
    }
}
