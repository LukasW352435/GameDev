// GameDevTutorial.cpp : Defines the entry point for the application.
//

#include "GameDevTutorial.h"

using namespace std;

int main()
{
	if (!glfwInit()) {
		cout << "Failed to initialize GLFW!" << endl;
		return EXIT_FAILURE;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	const int windowWidth = 1280;
	const int windowHeight = 720;
	const char* windowTitle = "My Title";
	GLFWwindow* window = glfwCreateWindow(
		windowWidth,
		windowHeight,
		windowTitle,
		nullptr,
		nullptr
	);
	if (window == nullptr) {
		cout << "Failed to create GLFW window!" << endl;
		glfwTerminate();
		return EXIT_FAILURE;
	}
	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "Failed to initialize Glad!" << endl;
		return EXIT_FAILURE;
	}
	glViewport(0, 0, windowWidth, windowHeight);
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(250.f / 255.f, 119.f / 255.f, 110.f / 255.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}
