#include "glfw.h"

GLTab::GLTab(int height, int width) 
{
	ID = glfwCreateWindow(height, width, "OpenGL", NULL, NULL);

	if (ID == NULL) 

	{
		printf("OpenGL: Window Failed!");
	}

}