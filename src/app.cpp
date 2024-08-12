#include "app.h"

#include <iostream>
#include <stdexcept>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <learnopengl/camera.h>

App::App(){}

void App::GLFW_FramebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0,0,width,height);
}


int App::Init(int width, int height,const char *name)
{
    if(!glfwInit())
        throw std::runtime_error("failed to create window =/ Not lucky today =/");
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    mWindow = glfwCreateWindow(width, height, name,NULL, NULL);

    if(!mWindow)
        throw std::runtime_error("failed to create window =/ Not lucky today =/");

    glfwMakeContextCurrent(mWindow);
    
    if(!gladLoadGLLoader((GLADloadproc)(glfwGetProcAddress)))
        throw std::runtime_error("failed to load opengl =/ Not lucky today =/");
    
    glfwGetFramebufferSize(mWindow, &width, &height);


    glViewport(0,0,width,height);

    glfwSetFramebufferSizeCallback(mWindow, GLFW_FramebufferSizeCallback);
    return 0;
    
}

int App::Run()
{
    while(!glfwWindowShouldClose(mWindow))
    {
        InputHandler();        
        glClearColor(0.2,0.5,0.7, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);    
        

        glfwSwapBuffers(mWindow);
        glfwPollEvents();
    }
    return 0;
}

App::~App()
{
    glfwDestroyWindow(mWindow);
    glfwTerminate();
}

void App::InputHandler()
{
    if(glfwGetKey(mWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(mWindow, true);
}

