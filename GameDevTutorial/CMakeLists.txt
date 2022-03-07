# CMakeList.txt : CMake project for GameDevTutorial, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(../lib/glfw/)
include_directories(../lib/glad/include)
include_directories(../lib/imgui)
include_directories(../lib/imgui/backends)
include_directories(../lib/glm)

# Add source to this project's executable.
add_executable (GameDevTutorial 
	"GameDevTutorial.cpp" "GameDevTutorial.h"
	"../lib/imgui/backends/imgui_impl_glfw.cpp" "../lib/imgui/backends/imgui_impl_opengl3.cpp"
	"../lib/imgui/imgui_draw.cpp" "../lib/imgui/imgui_tables.cpp" "../lib/imgui/imgui_widgets.cpp"
	"../lib/imgui/imgui.cpp" 
	"../lib/imgui/imgui_demo.cpp"
	"core/Window.cpp" "core/Window.h" 
	"core/Input.h" "core/Input.cpp" 
	"renderer/Shader.cpp" "renderer/Shader.h" 
	"renderer/ShaderProgram.h" "renderer/ShaderProgram.cpp")

target_link_libraries(GameDevTutorial glfw)
target_link_libraries(GameDevTutorial glad)
target_link_libraries(GameDevTutorial glm)

