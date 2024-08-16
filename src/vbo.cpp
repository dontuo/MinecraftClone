#include "vbo.h"


VBO::VBO()
{
    glGenBuffers(1, &mId);
}

void VBO::PushData(int target, int size, void *data, GLenum usage)
{
    Bind(target);
    glBufferData(target,size,data,usage);
}

void VBO::Bind(int target)
{
    glBindBuffer(target,mId);
}

VBO::~VBO()
{
    glDeleteBuffers(1, &mId);
}
