#include <glad/glad.h>
#include <iostream>
#include "window.h"
#include "shader.h"
#include "cube.h"

int main() {
    try {
        // Create window
        Window window(800, 600, "Cube");

        // Load shaders
        Shader shader("./shaders/vertex_shader.glsl", "./shaders/fragment_shader.glsl");

        // Create cube and transform
        Cube cube;

        // Apply initial transform to the cube
        cube.transform.setPosition(glm::vec3(0.0f, 0.0f, -2.0f));
        cube.transform.setScale(glm::vec3(1.0f, 1.0f, 1.0f));

        // Create projection matrix (perspective view)
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

        // Render loop
        while (!window.shouldClose()) {
            // Clear screen
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            // Enable depth testing for 3D rendering
            glEnable(GL_DEPTH_TEST);

            // Enable wireframe mode to outline triangles
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

            // Rotate cube each frame
            cube.transform.rotate(glm::vec3(1.0f, 1.0f, 0.0f), 0.1f);

            // Draw cube with its transform
            shader.use();
            shader.setMat4("model", cube.transform.getModelMatrix());
            shader.setMat4("projection", projection);
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
