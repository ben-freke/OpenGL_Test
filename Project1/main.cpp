#include <GL\glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>



int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Group 16 OpenGL Experiment", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	
	glewExperimental = true;
	
	if (glewInit() != GLEW_OK){
		glfwTerminate();
		fprintf(stderr, "GLEW Failed to initalise");
		return -1;
	}

	GLuint vaoid = 6;
	glGenVertexArrays(1, &vaoid);
	glBindVertexArray(vaoid);
	//Tells OpenGL that we are going to be using the vaoid array

	static const GLfloat verts[] = {
		//X, Y, Z
		-0.8f, -0.8f, 0.0f,
		0.8f, -0.8f, 0.0f,
		0.0f, 0.8f, 0.0f

	};
	//This is an array of vertificies
	//Contains the array for the coordinates for the triange
		
	GLuint vboid;
	glGenBuffers(1, &vboid);
	glBindBuffer(GL_ARRAY_BUFFER, vboid);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);





	/* Loop until the user closes the window */
	

	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vboid);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glDisableVertexAttribArray(0);
		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}