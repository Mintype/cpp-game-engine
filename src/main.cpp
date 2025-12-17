#include <glad/glad.h>
#include <iostream>
#include "window.h"
#include "shader.h"
#include "mesh.h"

int main() {
    try {
        // Create window
        Window window(800, 600, "Triangle");

        // Load shaders
        Shader shader("./shaders/vertex_shader.glsl", "./shaders/fragment_shader.glsl");

        // Vertex data
        float vertices[] = {
             0.0f,  0.5f, 0.0f,  // top
            -0.2f, -0.2f, 0.0f,  // bottom left
             0.5f, -0.5f, 0.0f   // bottom right
        };

        // Create mesh
        Mesh triangle(vertices, 3);

        // Render loop
        while (!window.shouldClose()) {
            // Clear screen
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            // Draw triangle
            shader.use();
            triangle.bind();
            triangle.draw();

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
