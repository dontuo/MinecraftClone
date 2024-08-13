#include "window.h"

Window::Window(){}

void Window::Init(int width, int height, const char *name)
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

    glEnable(GL_DEPTH_BUFFER_BIT);

    glViewport(0,0,width,height);

    glfwSetFramebufferSizeCallback(mWindow, GLFW_FramebufferSizeCallback);   

}

void Window::GLFW_FramebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0,0,width,height);
}

void Window::Update()
{
    glfwPollEvents();
    glfwSwapBuffers(mWindow);
}

void Window::Clear(float r, float g, float b, float a)
{
    glClearColor(r,g,b,a);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
