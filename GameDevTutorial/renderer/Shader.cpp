#include "Shader.h"

Shader::Shader(const char* filename, GLenum shaderType) : filename(filename), shaderType(shaderType) {
	shaderId = UINT32_MAX;
}

Shader::~Shader() {
	glDeleteShader(shaderId);
}

bool Shader::compile() {
	std::string shaderCode = parse();
	shaderId = glCreateShader(shaderType);
	const GLchar* shaderCodeCStr = shaderCode.c_str();
	glShaderSource(shaderId, 1, &shaderCodeCStr, 0);
	glCompileShader(shaderId);

	GLint compiledStatus = 0;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &compiledStatus);
	if (compiledStatus == GL_FALSE) {
		GLint maxLength = 0;
		glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &maxLength);
		std::vector<GLchar> infoLog(maxLength);
		glGetShaderInfoLog(shaderId, maxLength, &maxLength, &infoLog[0]);
		glDeleteShader(shaderId);
		std::cout << "Failed compile: " << infoLog.data() << std::endl;
		return false;
	}
	return true;
}

std::string Shader::parse() {
	std::string result;
	std::ifstream in(filename, std::ios::in | std::ios::binary);
	if (in) {
		in.seekg(0, std::ios::end);
		result.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&result[0], result.size());
		in.close();
	}
	else {
		std::cout << "Failed open file: " << filename << std::endl;
		std::cout << std::filesystem::current_path() << std::endl;
	}
	return result;
}