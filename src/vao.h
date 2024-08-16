#pragma once

#include <glad/glad.h>

class VAO
{
public:
    unsigned int mId;

    VAO();
    ~VAO();

    void PushData(GLuint index, GLint size, GLenum type, GLboolean	normalized, GLsizei	stride, const GLvoid *pointer);

    void Bind();
};
