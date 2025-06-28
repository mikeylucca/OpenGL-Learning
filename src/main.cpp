#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

// global variable for wize of window
const GLuint WIDHT = 800, HEIGHT = 600;

// key handler function
void	key_handler(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
		std::cout << "ESCAPE key pressed" << std::endl;
	}
}

int main(void)
{
	GLFWwindow* window;
	
	// Initialize GLFW
	if (!glfwInit())
	{
		std::cout << "GLFW failed to init" << std::endl;
		return -1;
	}

	// Set OpenGL version (3.3 core profile)
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(WIDHT, HEIGHT, "Test window", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_handler);

	// Initialize GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
		return -1;
	}

	// Successfully loaded OpenGL
	std::cout << "Loaded OpenGL " << GLVersion.major << "." << GLVersion.minor << std::endl;

	glViewport(0, 0, WIDHT, HEIGHT);

	//running loop
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents(); // listener for events

		//render starts here

		
		//clear color buffer
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}