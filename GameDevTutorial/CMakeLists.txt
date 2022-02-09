# CMakeList.txt : CMake project for GameDevTutorial, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

include_directories(../lib/glfw/)
include_directories(../lib/glad/include)
include_directories(../lib/glm)

# Add source to this project's executable.
add_executable (GameDevTutorial "GameDevTutorial.cpp" "GameDevTutorial.h")

target_link_libraries(GameDevTutorial glfw)
target_link_libraries(GameDevTutorial glad)
target_link_libraries(GameDevTutorial glm)

