#include "vao.h"


VAO::VAO()
{
    glGenVertexArrays(1, &mId);
}

void VAO::PushData(GLuint index, GLint size, GLenum type, GLboolean	normalized, GLsizei	stride, const GLvoid *pointer)
{
    Bind();
    glVertexAttribPointer(index,size, type, normalized, stride, pointer);
}

void VAO::Bind()
{
    glBindVertexArray(mId);
}

VAO::~VAO()
{
    glDeleteVertexArrays(1, &mId);
}
