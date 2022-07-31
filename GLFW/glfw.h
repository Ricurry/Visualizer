#include <cstdio>
#include "../glad/glad.h"
#include "glfw3.h"
#include <math.h>


#ifndef GLFW_CLASS_H
#define GLFW_CLASS_H

class GLTab 
{
public:
	GLTab(int height, int width);
	GLFWwindow * ID;
};

#endif