#pragma once

#include "GameDevTutorial.h"
#include "core/Window.h"
#include "core/Input.h"
#include "renderer/ShaderProgram.h"

void errorCallback(int errorCode, const char* description) {
	std::cout << errorCode << ": " << description << std::endl;
}

struct Vertex {
	glm::vec3 position;
	glm::vec4 color;
};

void initTriangle(GLuint* vaoId) {
	Vertex dataTriangle[3] = {
		{glm::vec3(-0.5f, -0.5f,0.0f),glm::vec4(0.9f,0.8f,0.2f,1.0f)},
		{glm::vec3(0.0f, 0.5f,0.0f),glm::vec4(0.2f,0.9f,0.8f,1.0f)},
		{glm::vec3(0.5f, -0.5f,0.0f),glm::vec4(0.9f,0.2f,0.8f,1.0f)},
	};
	glCreateVertexArrays(1, vaoId);
	glBindVertexArray(*vaoId);

	GLuint bufferId;
	glGenBuffers(1, &bufferId);
	glBindBuffer(GL_ARRAY_BUFFER, bufferId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(dataTriangle), dataTriangle, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
	glEnableVertexAttribArray(1);
}

void initSquare(GLuint* vaoId) {
	Vertex dataTriangle[6] = {
		{glm::vec3(-0.5f, -0.5f,0.0f),glm::vec4(0.9f,0.8f,0.2f,1.0f)},
		{glm::vec3(-0.5f, 0.5f,0.0f),glm::vec4(0.2f,0.9f,0.8f,1.0f)},
		{glm::vec3(0.5f, 0.5f,0.0f),glm::vec4(0.2f,0.9f,0.8f,1.0f)},
		{glm::vec3(0.5f, 0.5f,0.0f),glm::vec4(0.2f,0.9f,0.8f,1.0f)},
		{glm::vec3(0.5f, -0.5f,0.0f),glm::vec4(0.9f,0.2f,0.8f,1.0f)},
		{glm::vec3(-0.5f, -0.5f,0.0f),glm::vec4(0.9f,0.8f,0.2f,1.0f)},
	};
	glCreateVertexArrays(1, vaoId);
	glBindVertexArray(*vaoId);

	GLuint bufferId;
	glGenBuffers(1, &bufferId);
	glBindBuffer(GL_ARRAY_BUFFER, bufferId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(dataTriangle), dataTriangle, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
	glEnableVertexAttribArray(1);
}

void initSquareWithElements(GLuint* vaoId) {
	Vertex dataTriangle[6] = {
		{glm::vec3(-0.5f, -0.5f,0.0f),glm::vec4(0.9f,0.8f,0.2f,1.0f)},
		{glm::vec3(-0.5f, 0.5f,0.0f),glm::vec4(0.2f,0.9f,0.8f,1.0f)},
		{glm::vec3(0.5f, 0.5f,0.0f),glm::vec4(0.2f,0.9f,0.8f,1.0f)},
		{glm::vec3(0.5f, -0.5f,0.0f),glm::vec4(0.9f,0.2f,0.8f,1.0f)},
	};
	glCreateVertexArrays(1, vaoId);
	glBindVertexArray(*vaoId);

	GLuint bufferId;
	glGenBuffers(1, &bufferId);
	glBindBuffer(GL_ARRAY_BUFFER, bufferId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(dataTriangle), dataTriangle, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
	glEnableVertexAttribArray(1);

	unsigned int indices[6] = {
		0, 1, 2, 2, 3, 0
	};

	GLuint eboId;
	glGenBuffers(1, &eboId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

void initStar(GLuint* vaoId) {
	Vertex dataTriangle[10] = {
		{glm::vec3(-0.4f,  0.125f, 0.0f), glm::vec4(0.4f, 0.521f, 0.960f, 1.0f)},
		{glm::vec3(-0.125f,  0.125f, 0.0f), glm::vec4(0.490f, 0.443f, 0.956f, 1.0f)},
		{glm::vec3(0.0f,    0.5f, 0.0f), glm::vec4(0.686f, 0.443f, 0.956f, 1.0f)},
		{glm::vec3(0.125f,  0.125f, 0.0f), glm::vec4(0.917f, 0.443f, 0.956f, 1.0f)},
		{glm::vec3(0.4f,  0.125f, 0.0f), glm::vec4(0.807f, 0.317f, 0.250f, 1.0f)},
		{glm::vec3(0.13f, -0.125f, 0.0f), glm::vec4(0.807f, 0.250f, 0.682f, 1.0f)},
		{glm::vec3(0.29f,   -0.6f, 0.0f), glm::vec4(0.956f, 0.631f, 0.443f, 1.0f)},
		{glm::vec3(0.0f,  -0.29f, 0.0f), glm::vec4(0.956f, 0.843f, 0.443f, 1.0f)},
		{glm::vec3(-0.29f,   -0.6f, 0.0f), glm::vec4(0.862f, 0.956f, 0.443f, 1.0f)},
		{glm::vec3(-0.13f, -0.125f, 0.0f), glm::vec4(0.584f, 0.956f, 0.443f, 1.0f)}
	};
	glCreateVertexArrays(1, vaoId);
	glBindVertexArray(*vaoId);

	GLuint bufferId;
	glGenBuffers(1, &bufferId);
	glBindBuffer(GL_ARRAY_BUFFER, bufferId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(dataTriangle), dataTriangle, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
	glEnableVertexAttribArray(1);

	unsigned int indices[24] = {
		0, 1, 9,   1, 2, 3,
		3, 4, 5,   5, 6, 7,
		7, 8, 9,   9, 5, 7,
		9, 1, 3,   9, 3, 5
	};

	GLuint eboId;
	glGenBuffers(1, &eboId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

void initSquareLines(GLuint* vaoId) {
	Vertex dataTriangle[4] = {
		{glm::vec3(-0.5f, -0.5f,0.0f),glm::vec4(0.9f,0.8f,0.2f,1.0f)},
		{glm::vec3(-0.5f, 0.5f,0.0f),glm::vec4(0.2f,0.9f,0.8f,1.0f)},
		{glm::vec3(0.5f, 0.5f,0.0f),glm::vec4(0.2f,0.9f,0.8f,1.0f)},
		{glm::vec3(0.5f, -0.5f,0.0f),glm::vec4(0.9f,0.2f,0.8f,1.0f)},
	};
	glCreateVertexArrays(1, vaoId);
	glBindVertexArray(*vaoId);

	GLuint bufferId;
	glGenBuffers(1, &bufferId);
	glBindBuffer(GL_ARRAY_BUFFER, bufferId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(dataTriangle), dataTriangle, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
	glEnableVertexAttribArray(1);

	unsigned int indices[8] = {
		0, 1, 1, 2, 2, 3, 3, 0
	};

	GLuint eboId;
	glGenBuffers(1, &eboId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

void initStarNamedBuffer(GLuint* vaoId) {
	Vertex dataTriangle[10] = {
		{glm::vec3(-0.4f,  0.125f, 0.0f), glm::vec4(0.4f, 0.521f, 0.960f, 1.0f)},
		{glm::vec3(-0.125f,  0.125f, 0.0f), glm::vec4(0.490f, 0.443f, 0.956f, 1.0f)},
		{glm::vec3(0.0f,    0.5f, 0.0f), glm::vec4(0.686f, 0.443f, 0.956f, 1.0f)},
		{glm::vec3(0.125f,  0.125f, 0.0f), glm::vec4(0.917f, 0.443f, 0.956f, 1.0f)},
		{glm::vec3(0.4f,  0.125f, 0.0f), glm::vec4(0.807f, 0.317f, 0.250f, 1.0f)},
		{glm::vec3(0.13f, -0.125f, 0.0f), glm::vec4(0.807f, 0.250f, 0.682f, 1.0f)},
		{glm::vec3(0.29f,   -0.6f, 0.0f), glm::vec4(0.956f, 0.631f, 0.443f, 1.0f)},
		{glm::vec3(0.0f,  -0.29f, 0.0f), glm::vec4(0.956f, 0.843f, 0.443f, 1.0f)},
		{glm::vec3(-0.29f,   -0.6f, 0.0f), glm::vec4(0.862f, 0.956f, 0.443f, 1.0f)},
		{glm::vec3(-0.13f, -0.125f, 0.0f), glm::vec4(0.584f, 0.956f, 0.443f, 1.0f)}
	};
	unsigned int indices[24] = {
		0, 1, 9,   1, 2, 3,
		3, 4, 5,   5, 6, 7,
		7, 8, 9,   9, 5, 7,
		9, 1, 3,   9, 3, 5
	};

	glCreateVertexArrays(1, vaoId);
	glBindVertexArray(*vaoId);

	// Set up and buffer element buffer
	GLuint eboId;
	glCreateBuffers(1, &eboId);
	glNamedBufferData(eboId, sizeof(indices), indices, GL_STATIC_DRAW);
	glVertexArrayElementBuffer(*vaoId, eboId);

	// Set up and buffer the vertex buffer
	GLuint vboId;
	GLuint vertexBindingPoint = 0;
	glCreateBuffers(1, &vboId);
	glNamedBufferData(vboId, sizeof(dataTriangle), dataTriangle, GL_STATIC_DRAW);
	glVertexArrayVertexBuffer(*vaoId, vertexBindingPoint, vboId, 0, sizeof(Vertex));

	// Set up and enabel attribute 1
	glVertexArrayAttribFormat(*vaoId, 0, 3, GL_FLOAT, GL_FALSE, offsetof(Vertex, position));
	glVertexArrayAttribBinding(*vaoId, 0, vertexBindingPoint);
	glEnableVertexArrayAttrib(*vaoId, 0);

	// Set up and enabel attribute 2
	glVertexArrayAttribFormat(*vaoId, 1, 4, GL_FLOAT, GL_FALSE, offsetof(Vertex, color));
	glVertexArrayAttribBinding(*vaoId, 1, vertexBindingPoint);
	glEnableVertexArrayAttrib(*vaoId, 1);
}

int main()
{
	glfwSetErrorCallback(errorCallback);
	if (!glfwInit()) {
		std::cout << "Failed to initialize GLFW!" << std::endl;
		return EXIT_FAILURE;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	Window w(1280, 720, "My Title");
	if (w.window == nullptr) {
		return EXIT_FAILURE;
	}
	Input input(w.window);

	glfwMakeContextCurrent(w.window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize Glad!" << std::endl;
		return EXIT_FAILURE;
	}
	glViewport(0, 0, w.width, w.height);

	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	// Setup Platform/Renderer backends
	ImGui_ImplGlfw_InitForOpenGL(w.window, true);
	const char* glsl_version = "#version 130";
	ImGui_ImplOpenGL3_Init(glsl_version);

	// Create buffers
	GLuint vaoId;

	//initTriangle(&vaoId);
	//initSquare(&vaoId);
	//initSquareWithElements(&vaoId);
	//initStar(&vaoId);
	//initSquareLines(&vaoId);
	initStarNamedBuffer(&vaoId);

	// Create shaders
	ShaderProgram shader("..\\..\\..\\..\\assets\\shaders\\vertex\\basic.glsl", "..\\..\\..\\..\\assets\\shaders\\fragment\\basic.glsl");
	shader.bind();

	// Main loop
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	bool openInfo = true;
	bool openKeyMapping = false;
	while (!glfwWindowShouldClose(w.window))
	{
		glfwPollEvents();

		// Start the Dear ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		if (input.isKeyDown(GLFW_KEY_I)) {
			openInfo = true;
		}
		if (input.isKeyDown(GLFW_KEY_K)) {
			openKeyMapping = true;
		}
		if (input.isKeyDown(GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose(w.window, GLFW_TRUE);
		}

		if (openInfo) {
			ImGui::Begin("Window Info", &openInfo);
			ImGui::Text("Monitor name: %s", w.monitorName);
			ImGui::Text("Monitor resulution: (Width/Height) %dx%d", w.mode->width, w.mode->height);
			int windowWidth, windowHeight;
			glfwGetWindowSize(w.window, &windowWidth, &windowHeight);
			ImGui::Text("Current window resulution: (Width/Height) %dx%d", windowWidth, windowHeight);
			if (ImGui::Button("Fullscreen")) {
				w.toggleFullscreen();
			}
			if (ImGui::Button("Open key mapping")) {
				openKeyMapping = true;
			}
			if (ImGui::Button("Close main window")) {
				glfwSetWindowShouldClose(w.window, GLFW_TRUE);
			}
			ImGui::End();
		}

		if (openKeyMapping) {
			ImGui::Begin("Key mapping", &openKeyMapping);
			ImGui::Text("I\t=>\topen info window");
			ImGui::Text("K\t=>\topen key mapping window");
			ImGui::End();
		}

		// Rendering
		ImGui::Render();
		int display_w, display_h;
		glfwGetFramebufferSize(w.window, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw User
		glBindVertexArray(vaoId);
		//glDrawArrays(GL_TRIANGLES, 0, 3); // Triangle
		//glDrawArrays(GL_TRIANGLES, 0, 6); // Square
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); // Square with Element buffer
		//glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, 0); // Star with Element buffer
		//glDrawElements(GL_LINES, 8, GL_UNSIGNED_INT,0); // Square with lines
		glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, 0); // Star with Named buffer

		// Draw ImGui
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(w.window);
	}
	return 0;
}
