#pragma once
#include "../GameDevTutorial.h"

class Shader {
public:
	GLenum shaderType;
	const char* filename;
	GLuint shaderId;
	Shader(const char* filename, GLenum shaderType);
	~Shader();
	bool compile();
private:
	std::string parse();
};