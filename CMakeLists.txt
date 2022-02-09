# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("GameDev")

# Include sub-projects.
#include_directories ("lib/glad")
add_subdirectory("lib/glad")
add_subdirectory ("lib/glfw")
add_subdirectory("lib/glm")
add_subdirectory ("GameDevTutorial")
