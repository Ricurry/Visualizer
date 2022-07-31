#include "VAO.h"

VAO::VAO() 
{
    glGenVertexArrays(1, &ID);
}

// Binds the VAO.
void VAO::Bind() 
{
    // Make the VAO the current Vertex Array Object by binding it
	glBindVertexArray(ID);
}

// Links the VAO to the VBO.
void VAO::LinkVBO(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
{
    // Configure the Vertex Attribute so that OpenGL knows how to read the VBO
    VBO.Bind();
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
    glEnableVertexAttribArray(layout);
    VBO.Unbind();
}

// Unbinds the VAO.
void VAO::Unbind() 
{
    // Unbinds the VAO by binding it to 0.
	glBindVertexArray(0);
}

void VAO::Delete() 
{
    glDeleteBuffers(1, &ID);
}