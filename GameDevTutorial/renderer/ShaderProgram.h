#pragma once
#include "../GameDevTutorial.h"

class ShaderProgram {
public:
	ShaderProgram(const char* vertexShaderFile, const char* fragmentShaderFile);
	~ShaderProgram();

	void bind() const;
	void unbind() const;

	GLuint getVariableLocation(const std::string varName);

	void uploadVec4(GLint varLocation, const glm::vec4& vec4) const;
	void uploadVec3(GLint varLocation, const glm::vec3& vec3) const;
	void uploadVec2(GLint varLocation, const glm::vec2& vec2) const;
	void uploadIVec4(GLint varLocation, const glm::ivec4& vec4) const;
	void uploadIVec3(GLint varLocation, const glm::ivec3& vec3) const;
	void uploadIVec2(GLint varLocation, const glm::ivec2& vec2) const;
	void uploadFloat(GLint varLocation, float value) const;
	void uploadInt(GLint varLocation, int value) const;
	void uploadIntArray(GLint varLocation, int length, const int* array) const;
	void uploadUInt(GLint varLocation, unsigned int value) const;
	void uploadBool(GLint varLocation, bool value) const;
	void uploadMat4(GLint varLocation, const glm::mat4& mat4) const;
	void uploadMat3(GLint varLocation, const glm::mat3& mat3) const;

private:
	GLuint programId;
	std::map<std::string, GLint> shaderVariableLocations;
	bool compileAndLink(const char* vertexShaderFile, const char* fragmentShaderFile);
};