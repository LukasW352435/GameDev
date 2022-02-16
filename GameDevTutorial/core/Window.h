#pragma once
#include "../GameDevTutorial.h"

class Window {
public:
	GLFWwindow* window;
	GLFWmonitor* monitor;
	int width;
	int height;
	int posX;
	int posY;
	const GLFWvidmode* mode;
	const char* monitorName;
	Window(int width, int height, const char* title);
	~Window();
	void toggleFullscreen();
private:
	bool fullscreen = false;
	int backupWidth;
	int backupHeight;
};