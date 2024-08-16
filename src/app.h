#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>

#include <learnopengl/camera.h>
#include <learnopengl/shader.h>
#include "window.h"
#include <vector>

#include "vbo.h"
#include "vao.h"

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


