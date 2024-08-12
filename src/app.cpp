#include "app.h"


App::App(){}

/*void App::GLFW_FramebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0,0,width,height);
}*/


void App::Init(int width, int height,const char *name)
{
    mWindow.Init(width, height, name);
    
}

int App::Run()
{
    while(!glfwWindowShouldClose(mWindow.mWindow))
    {
        InputHandler();
        mWindow.Clear(0.2,0.5,0.7,1.0);
        
        mWindow.Update();
    }
    return 0;
}

App::~App()
{
    glfwDestroyWindow(mWindow.mWindow);
    glfwTerminate();
}

void App::InputHandler()
{
    if(glfwGetKey(mWindow.mWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(mWindow.mWindow, true);
}

