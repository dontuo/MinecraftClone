#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Game
{
public:

    Game();
    ~Game();
    
    int Init();

    int Run();
private:
    int mWindowWidth = 800;
    int mWindowHeight = 800;
    GLFWwindow *mWindow;
};
