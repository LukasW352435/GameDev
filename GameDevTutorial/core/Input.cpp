#include "Input.h"

bool Input::keyPressedData[GLFW_KEY_LAST] {false};
bool Input::moseButtonPressedData[GLFW_MOUSE_BUTTON_LAST] = { false };
float Input::mouseX = 0;
float Input::mouseY = 0;
float Input::mouseScrollX = 0;
float Input::mouseScrollY = 0;


Input::Input(GLFWwindow* window) {
	glfwSetKeyCallback(window, Input::keyCallback);
	glfwSetCursorPosCallback(window, Input::cursorPositionCallback);
	glfwSetMouseButtonCallback(window, Input::mouseButtonCallback);
	glfwSetScrollCallback(window, Input::mouseScrallCallback);
}

bool Input::isKeyDown(int key){
	return keyPressedData[key];
}

bool Input::isMouseButtonDown(int mouseButton) {
	return moseButtonPressedData[mouseButton];
}

void Input::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	keyPressedData[key] = action == GLFW_PRESS;
}

void Input::cursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {
	mouseX = (float)xpos;
	mouseY = (float)ypos;
}

void Input::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods){
	moseButtonPressedData[button] = action == GLFW_PRESS;
}

void Input::mouseScrallCallback(GLFWwindow* window, double xoffset, double yoffset){
	mouseScrollX = (float)xoffset;
	mouseScrollY = (float)yoffset;
}
