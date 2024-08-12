#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class App
{
public:

    App();
    ~App();
    
    int Init(int width, int height,const char *name);

    int Run();

private:
    GLFWwindow *mWindow;
    void InputHandler();

    static void GLFW_FramebufferSizeCallback(GLFWwindow *window, int width, int height);
};


