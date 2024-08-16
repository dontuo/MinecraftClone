#include "app.h"


static std::vector<float> verticies =
{
    -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
    -0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
     0.5f,0.5f, 0.0f, 0.5f, -0.5f,
};

App::App(){}

void App::Init(int width, int height,const char *name)
{
    mWindow.Init(width, height, name);
}

int App::Run()
{
    Shader shader("shaders/block.vert","shaders/block.frag");
    
    VAO vao;
    VBO vbo;

    vbo.PushData(GL_ARRAY_BUFFER, sizeof(float) * verticies.size(), verticies.data(), GL_STATIC_DRAW);
    
    vao.PushData(0,3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
    vao.PushData(1,2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) (3 * sizeof(float)));
        
    while(!glfwWindowShouldClose(mWindow.mWindow))
    {
        vao.Bind();
        InputHandler();
        mWindow.Clear(0.2,0.5,0.7,1.0);
        

        shader.use();
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

