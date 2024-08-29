#include "app.h"
#include "GLFW/glfw3.h"
#include "glm/ext/matrix_transform.hpp"
#include "glm/fwd.hpp"
#include <iostream>


static std::vector<float> cube_vertices = {
        -1.f, -1.f, -1.f, //front
         1.f, -1.f, -1.f,
         1.f,  1.f, -1.f,
         1.f,  1.f, -1.f,
        -1.f,  1.f, -1.f,
        -1.f, -1.f, -1.f,

        -1.f, -1.f,  1.f,
         1.f, -1.f,  1.f,
         1.f,  1.f,  1.f,
         1.f,  1.f,  1.f,
        -1.f,  1.f,  1.f,
        -1.f, -1.f,  1.f,

        -1.f,  1.f,  1.f,
        -1.f,  1.f, -1.f,
        -1.f, -1.f, -1.f,
        -1.f, -1.f, -1.f,
        -1.f, -1.f,  1.f,
        -1.f,  1.f,  1.f,

         1.f,  1.f,  1.f,
         1.f,  1.f, -1.f,
         1.f, -1.f, -1.f,
         1.f, -1.f, -1.f,
         1.f, -1.f,  1.f,
         1.f,  1.f,  1.f,

        -1.f, -1.f, -1.f,
         1.f, -1.f, -1.f,
         1.f, -1.f,  1.f,
         1.f, -1.f,  1.f,
        -1.f, -1.f,  1.f,
        -1.f, -1.f, -1.f,

        -1.f,  1.f, -1.f,
         1.f,  1.f, -1.f,
         1.f,  1.f,  1.f,
         1.f,  1.f,  1.f,
        -1.f,  1.f,  1.f,
        -1.f,  1.f, -1.f,
};

static std::vector<float> verticies =
{
        // positions          // texture coords
         0.5f,  0.f, -0.5f,   1.0f, 1.0f, // top right
         -0.5f, 0.f, 0.5f,   0.0f, 1.0f, // bottom right
         0.5f, 0.f, 0.5f,   0.0f, 1.0f, // bottom right
         
         -0.5f,  0.f, 0.5f,   1.0f, 1.0f, // top right
         0.5f, 0.f, -0.5f,   0.0f, 1.0f, // bottom right
         -0.5f, 0.f, -0.5f,   0.0f, 1.0f, // bottom right
                    
         -0.5f,  1.f, -0.5f,   1.0f, 1.0f, // top right
         0.5f, 0.f, -0.5f,   0.0f, 1.0f, // bottom right
         -0.5f, 0.f, -0.5f,   0.0f, 1.0f, // bottom right

        -0.5f,  1.f, -0.5f,   1.0f, 1.0f, // top right
         0.5f, 0.f, -0.5f,   0.0f, 1.0f, // bottom right
         -0.5f, 0.f, -0.5f,   0.0f, 1.0f, // bottom right
};

static std::vector<float> uvs =
{
    0.0f, 0.0f,
    1.0f, 0.0f,
    1.0f, 1.0f,
    1.0f, 1.0f,
    0.0f, 1.0f,
    0.0f, 0.0f,

    0.0f, 0.0f,
    1.0f, 0.0f,
    1.0f, 1.0f,
    1.0f, 1.0f,
    0.0f, 1.0f,
    0.0f, 0.0f,

    1.0f, 0.0f,
    1.0f, 1.0f,
    0.0f, 1.0f,
    0.0f, 1.0f,
    0.0f, 0.0f,
    1.0f, 0.0f,

    1.0f, 0.0f,
    1.0f, 1.0f,
    0.0f, 1.0f,
    0.0f, 1.0f,
    0.0f, 0.0f,
    1.0f, 0.0f,

    0.0f, 1.0f,
    1.0f, 1.0f,
    1.0f, 0.0f,
    1.0f, 0.0f,
    0.0f, 0.0f,
    0.0f, 1.0f,

    0.0f, 1.0f,
    1.0f, 1.0f,
    1.0f, 0.0f,
    1.0f, 0.0f,
    0.0f, 0.0f,
    0.0f, 1.0f, 
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
    VBO vboVerticies;
    VBO vboUV;
    

    vboVerticies.PushData(GL_ARRAY_BUFFER, sizeof(float) * cube_vertices.size(), cube_vertices.data(), GL_STATIC_DRAW);
    
    vao.PushData(0,3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);

    vboUV.PushData(GL_ARRAY_BUFFER, sizeof(float) * uvs.size(), uvs.data(), GL_STATIC_DRAW);

    vao.PushData(1,2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *) (0));
        
    while(!glfwWindowShouldClose(mWindow.mWindow))
    {
        vao.Bind();
        InputHandler();
        mWindow.Clear(0.2,0.5,0.7,1.0);
        glm::mat4 model         = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        glm::mat4 view          = glm::mat4(1.0f);
        glm::mat4 projection    = glm::mat4(1.0f);

        model = glm::mat4(1.0f);

        model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(1.0f,0.0f,0.0f));
        view = glm::translate(view, glm::vec3(-.5f,-2.0f, -5.f));
        projection = glm::perspective(glm::radians(90.0f), (float)800/(float)600, 0.1f, 100.0f);       
        //transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(1.0f,1.0f,1.0f));
        //transform = glm::scale(transform, glm::vec3(glfwGetTime(),1.0f,1.0f));
        
        shader.use();
        shader.setMat4("model", model);
        shader.setMat4("proj", projection);
        shader.setMat4("view", view);

        glDrawArrays(GL_TRIANGLES, 0,3 * 12);

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

