#include "game.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include <learnopengl/camera.h>

App::App(){}

int App::Init()
{
    if(!glfwInit()) return -1;
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    mWindow = glfwCreateWindow(mWindowWidth, mWindowHeight, "Minecraft clone",NULL, NULL);

    if(!mWindow) return -1;

    glfwMakeContextCurrent(mWindow);
    
    if(!gladLoadGLLoader((GLADloadproc)(glfwGetProcAddress)))
        return -1;
    
    glfwGetFramebufferSize(mWindow, &mWindowWidth, &mWindowHeight);

    glViewport(0,0,mWindowWidth,mWindowHeight);

    return 0;
}

int App::Run()
{
    Camera camera;
    while(!glfwWindowShouldClose(mWindow))
    {
        glfwSwapBuffers(mWindow);
    }
    return 0;
}

App::~App()
{
    glfwDestroyWindow(mWindow);
    glfwTerminate();
}

