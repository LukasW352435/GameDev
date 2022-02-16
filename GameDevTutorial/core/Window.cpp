#include "Window.h"

Window::Window(int width, int height, const char* title) {
	monitor = glfwGetPrimaryMonitor();
	mode = glfwGetVideoMode(monitor);
	monitorName = glfwGetMonitorName(monitor);
	window = glfwCreateWindow(
		width,
		height,
		title,
		nullptr,
		nullptr
	);
	if (window == nullptr) {
		std::cout << "Failed to create GLFW window!" << std::endl;
		glfwTerminate();
	}
	this->width = width;
	this->height = height;
	backupWidth = width;
	backupHeight = height;

	glfwGetWindowPos(window, &posX, &posY);
}

Window::~Window() {
	glfwTerminate();
}

void Window::toggleFullscreen() {
	if (fullscreen) {
		glfwSetWindowMonitor(window, nullptr, posX, posY, backupWidth, backupHeight, 0);
		fullscreen = false;
	}
	else {
		glfwGetWindowSize(window, &backupWidth, &backupHeight);
		glfwGetWindowPos(window, &posX, &posY);
		glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, 0);
		fullscreen = true;
	}
}