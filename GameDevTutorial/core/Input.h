#pragma once
#include "../GameDevTutorial.h"

class Input {
public:
	Input(GLFWwindow* window);
	bool isKeyDown(int key);
	bool isMouseButtonDown(int mouseButton);

private:
	static bool keyPressedData[GLFW_KEY_LAST];
	static bool moseButtonPressedData[GLFW_MOUSE_BUTTON_LAST];
	static float mouseX;
	static float mouseY;
	static float mouseScrollX;
	static float mouseScrollY;

	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
	static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	static void mouseScrallCallback(GLFWwindow* window, double xoffset, double yoffset);
};