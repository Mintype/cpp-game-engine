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

        // Create cube
        Cube cube;

        // Render loop
        while (!window.shouldClose()) {
            // Clear screen
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            // Enable depth testing for 3D rendering
            glEnable(GL_DEPTH_TEST);

            // Draw cube
            shader.use();
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
