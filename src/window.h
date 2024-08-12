#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>


class Window
{
public:
    Window();
   
    void Init(int width, int height, const char *name);
    GLFWwindow *mWindow;
    
    void Update();
    void Clear(float r, float g, float b, float a);

    static void GLFW_FramebufferSizeCallback(GLFWwindow *window, int width, int height);
};
