#include "app.h"
#include <learnopengl/shader.h>


static float verticies[] =
{
    -0.5f, 0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
     0.5f,0.5f, 0.0f,
};

App::App(){}

void App::Init(int width, int height,const char *name)
{
    mWindow.Init(width, height, name);
}

int App::Run()
{
    uint VAO;
    uint VBO;
    
    Shader("shaders/vertex.vert","shaders/fragment.frag");
        
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);

    glBindVertexArray(VAO);

    glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    
    glEnableVertexAttribArray(0);

    while(!glfwWindowShouldClose(mWindow.mWindow))
    {
        InputHandler();
        mWindow.Clear(0.2,0.5,0.7,1.0);
        
        glDrawArrays(GL_TRIANGLES, 0,3);

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

