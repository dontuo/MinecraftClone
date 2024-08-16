#pragma once

#include <glad/glad.h>

class VBO
{
public:
    unsigned int mId;

    VBO();
    ~VBO();

    void PushData(int target, int size, void *data, GLenum usage);

    void Bind(int target);
};
