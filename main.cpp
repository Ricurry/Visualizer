// Default
#include <windows.h>
#include <cstdio>

#include <fstream>
#include <cstring>

//  GLAD
#include "glad/glad.h"
// GLFW3.
#include "GLFW/glfw3.h"

// Local..
// -Shader Class
#include "shaderClass/shader.h" 
#include "VBO/VBO.h"
#include "VAO/VAO.h"
#include "EBO/EBO.h"

// STB// Texture Loading.
#include "stb/stb_image.h"

// GLFW Window.

#include "GLFW/glfw.h"


// GLM (TEMP!) (MAY NEED LATER!)

#include "glm/glm/glm.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"
#include "glm/glm/gtc/type_ptr.hpp"

// Aquila Library.
//

#include "fft/fft.h"

// PerlinNoise2D(nOutputWidth, nOutputHeight, fNoiseSeed2D, nOctaveCount, fScalingBias, fPerlinNoise2D);



// Vertices coordinates
GLfloat vertices[] =
{ //               COORDINATES                  /     COLORS           //
	-0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f, // Lower left corner
	 0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f, // Lower right corner
	 0.0f,  0.5f * float(sqrt(3)) * 2 / 3, 0.0f,     1.0f, 0.6f,  0.32f, // Upper corner
	-0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f,     0.9f, 0.45f, 0.17f, // Inner left
	 0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f,     0.9f, 0.45f, 0.17f, // Inner right
	 0.0f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f  // Inner down
};

// Indices for vertices order
GLuint indices[] =
{
	0, 4, 5, // Lower left triangle
	4, 2, 3, // Lower right triangle
	5, 3, 1 // Upper triangle
};


int main ()
{
	// Initialize GLFW.
	glfwInit();

	// Tell GLFW which version we are using.
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);

	// Create A Window With GLFW.

	GLTab Window(800, 800);	

	// Introduce Window into.. Windows.
	glfwMakeContextCurrent(Window.ID);
	
	// Load Glad.
	gladLoadGL();

	// With glad, change the viewport to centor of the screen.
	glViewport(0,0, 800, 800);

	// Prepare Shader.
	// *NOTE* Shader class is typically used as an "overlay to the OpenGL window.", Thus, it is ok to declare it here.

	Shader shader0("shader/default.vert", "shader/default.frag");

	// Generate VAO.
	VAO VAO1;

	// Bind VAO.
	VAO1.Bind();

	// Generate VBO/
			// Vertices, Size of Vertices.
	VBO VBO1(vertices, sizeof(vertices));

	// Generate EBO.
			//Indices, sizeof(indices).
	EBO EBO1(indices, sizeof(indices));

	// Link VAO to VBO.
	VAO1.LinkVBO(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
	VAO1.LinkVBO(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));

	// Unbind VAO.
	VAO1.Unbind();

	// Unbind both EBO and VBO, (Both are binded on creation.).

	VBO1.Unbind();
	EBO1.Unbind();

	// Time Variable.

	GLfloat prevtime = glfwGetTime();

	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);

  ffm sp1;
  int i;
  Aquila::SpectrumType sp8 = sp1.FFT();

  GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

	while (!glfwWindowShouldClose(Window.ID))

    {    	
    	// Change the Color of the background to darkish blue.
    	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

	  	// Clean the back buffer and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    	// Activate the shader.
    	shader0.Activate();

    	GLfloat crntTime = glfwGetTime();

      for (i = 0; i < sp8[sizeof(sp8)]; i++]) 
      {
          glUniform1f(uniID, sp8[i]);
      }

    	// Bind the VBO so OpenGL knows to use it
      VAO1.Bind();
      // Draw the triangle using the GL_TRIANGLES primitive and draw it along with EBO, or indices.
      glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

      // Swap window with each new frame.
      glfwSwapBuffers(Window.ID); 
      // Poll each event each time the loop occurs
      glfwPollEvents(); 
    }
      // Delete VAO1, EBO1, and VBO1.
    VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	  // Terminate Shader.
	  shader0.Delete();
	  // Terminate Window.
	  glfwDestroyWindow(Window.ID);
    // Terminate GLFW.
    glfwTerminate();
}
