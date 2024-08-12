#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>

#include <learnopengl/camera.h>
#include "window.h"

class App
{
public:

    App();

    ~App();
    
    void Init(int width, int height, const char *name);

    int Run();

private:
    Window mWindow;
    void InputHandler();

};


