#include "GameDevTutorial.h"

int main()
{
	if (!glfwInit()) {
		std::cout << "Failed to initialize GLFW!" << std::endl;
		return EXIT_FAILURE;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//int count;
	//GLFWmonitor** monitors = glfwGetMonitors(&count);
	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* mode = glfwGetVideoMode(monitor);
	const char* monitorName = glfwGetMonitorName(monitor);

	int windowWidth = 1280;
	int windowHeight = 720;
	int windowXPos;
	int windowYPos;
	const char* windowTitle = "My Title";
	GLFWwindow* window = glfwCreateWindow(
		windowWidth,
		windowHeight,
		windowTitle,
		nullptr,
		nullptr
	);

	if (window == nullptr) {
		std::cout << "Failed to create GLFW window!" << std::endl;
		glfwTerminate();
		return EXIT_FAILURE;
	}

	glfwGetWindowPos(window, &windowXPos, &windowYPos);

	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize Glad!" << std::endl;
		return EXIT_FAILURE;
	}
	glViewport(0, 0, windowWidth, windowHeight);

	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	// Setup Platform/Renderer backends
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	const char* glsl_version = "#version 130";
	ImGui_ImplOpenGL3_Init(glsl_version);

	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	bool close = false;
	bool fullscreen = false;
	int backupWindowWidth = windowWidth;
	int backupWindowHeight = windowHeight;
	bool openInfo = true;
	bool openKeyMapping = false;
	while (!glfwWindowShouldClose(window) && !close)
	{
		glfwPollEvents();

		// Start the Dear ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		int state = glfwGetKey(window, GLFW_KEY_I);
		if (state == GLFW_PRESS) {
			openInfo = true;
		}

		if(openInfo) {
			ImGui::Begin("Window Info", &openInfo);
			ImGui::Text("Monitor name: %s", monitorName);
			ImGui::Text("Monitor resulution: (Width/Height) %dx%d" ,mode->width ,mode->height);
			glfwGetWindowSize(window, &windowWidth, &windowHeight);
			ImGui::Text("Current window resulution: (Width/Height) %dx%d", windowWidth, windowHeight);
			if (ImGui::Button("Fullscreen")) {
				if (fullscreen) {
					glfwSetWindowMonitor(window, nullptr, windowXPos, windowYPos, backupWindowWidth, backupWindowHeight, 0);
					fullscreen = false;
				}
				else {
					glfwGetWindowSize(window, &backupWindowWidth, &backupWindowHeight);
					glfwGetWindowPos(window, &windowXPos, &windowYPos);
					glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, 0);
					fullscreen = true;
				}
			}
			if (ImGui::Button("Open key mapping")) {
				openKeyMapping = true;
			}
			if (ImGui::Button("Close main window")) {
				close = true;
			}
			ImGui::End();
		}

		if (openKeyMapping) {
			ImGui::Begin("Key mapping", &openKeyMapping);
			ImGui::Text("I\t=>\topen info window");
			ImGui::End();
		}

		// Rendering
		ImGui::Render();
		int display_w, display_h;
		glfwGetFramebufferSize(window, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);
	}
	glfwTerminate();
	return 0;
}
