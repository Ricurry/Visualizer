#ifndef VAO_CLASS_H
#define VAO_CLASS_H

#include <cstdio>
#include "../glad/glad.h"
#include "../GLFW/glfw3.h"
#include <math.h>


#include "../VBO/VBO.h"


class VAO
{
    public:

    VAO();

    GLuint ID;

    void LinkVBO(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);

    void Bind();
    void Unbind();
    void Delete();
};

#endif