#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
public:
    Window(int width, int height, const char* title);
    ~Window();

    bool isOpen() const;
    void pollEvents();
    void swapBuffers();
    bool shouldClose() const;
    void setShouldClose(bool value);
    
    GLFWwindow* getGLFWWindow() const;
    
private:
    GLFWwindow* window;
    int width, height;
    
    bool initGLFW();
    void initGLAD();
};

#endif
