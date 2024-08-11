#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class App
{
public:

    App();
    ~App();
    
    int Init();

    int Run();
private:
    int mWindowWidth = 800;
    int mWindowHeight = 800;
    GLFWwindow *mWindow;
};
