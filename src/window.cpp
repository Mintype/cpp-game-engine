#include "window.h"
#include <iostream>

Window::Window(int width, int height, const char* title)
    : width(width), height(height), window(nullptr) {
    if (!initGLFW()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync
    
    try {
        initGLAD();
    } catch (...) {
        glfwTerminate();
        throw;
    }

    glViewport(0, 0, width, height);
}

Window::~Window() {
    if (window) {
        glfwDestroyWindow(window);
    }
    glfwTerminate();
}

bool Window::initGLFW() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return false;
    }
    return true;
}

void Window::initGLAD() {
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD\n";
        throw std::runtime_error("GLAD initialization failed");
    }
}

bool Window::isOpen() const {
    return window != nullptr;
}

void Window::pollEvents() {
    glfwPollEvents();
}

void Window::swapBuffers() {
    glfwSwapBuffers(window);
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(window);
}

void Window::setShouldClose(bool value) {
    glfwSetWindowShouldClose(window, value);
}

GLFWwindow* Window::getGLFWWindow() const {
    return window;
}
