#include "ShaderProgram.h"
#include "Shader.h"

ShaderProgram::ShaderProgram(const char* vertexShaderFile, const char* fragmentShaderFile)
{
	shaderVariableLocations = std::map<std::string, GLint>();
	if (!compileAndLink(vertexShaderFile, fragmentShaderFile)) {
		throw "Failed to create Shader!";
	}
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(programId);
}

void ShaderProgram::bind() const
{
	glUseProgram(programId);
}

void ShaderProgram::unbind() const
{
	glUseProgram(0);
}

GLuint ShaderProgram::getVariableLocation(const std::string varName)
{
	auto it = shaderVariableLocations.find(varName);
	if (it != shaderVariableLocations.end()) {
		return it->second;
	}
	throw "Shader variable <" + varName + "> not found!";
}

void ShaderProgram::uploadVec4(GLint varLocation, const glm::vec4& vec4) const
{
	glUniform4f(varLocation, vec4.x, vec4.y, vec4.z, vec4.w);
}

void ShaderProgram::uploadVec3(GLint varLocation, const glm::vec3& vec3) const
{
	glUniform3f(varLocation, vec3.x, vec3.y, vec3.z);
}

void ShaderProgram::uploadVec2(GLint varLocation, const glm::vec2& vec2) const
{
	glUniform2f(varLocation, vec2.x, vec2.y);
}

void ShaderProgram::uploadIVec4(GLint varLocation, const glm::ivec4& vec4) const
{
	glUniform4i(varLocation, vec4.x, vec4.y, vec4.z, vec4.w);
}

void ShaderProgram::uploadIVec3(GLint varLocation, const glm::ivec3& vec3) const
{
	glUniform3i(varLocation, vec3.x, vec3.y, vec3.z);
}

void ShaderProgram::uploadIVec2(GLint varLocation, const glm::ivec2& vec2) const
{
	glUniform2i(varLocation, vec2.x, vec2.y);
}

void ShaderProgram::uploadFloat(GLint varLocation, float value) const
{
	glUniform1f(varLocation, value);
}

void ShaderProgram::uploadInt(GLint varLocation, int value) const
{
	glUniform1i(varLocation, value);
}

void ShaderProgram::uploadIntArray(GLint varLocation, int length, const int* array) const
{
	glUniform1iv(varLocation, length, array);
}

void ShaderProgram::uploadUInt(GLint varLocation, unsigned int value) const
{
	glUniform1ui(varLocation, value);
}

void ShaderProgram::uploadBool(GLint varLocation, bool value) const
{
	glUniform1i(varLocation, value ? 1 : 0);
}

void ShaderProgram::uploadMat4(GLint varLocation, const glm::mat4& mat4) const
{
	glUniformMatrix4fv(varLocation, 1, GL_FALSE, glm::value_ptr(mat4));
}

void ShaderProgram::uploadMat3(GLint varLocation, const glm::mat3& mat3) const
{
	glUniformMatrix3fv(varLocation, 1, GL_FALSE, glm::value_ptr(mat3));
}

bool ShaderProgram::compileAndLink(const char* vertexShaderFile, const char* fragmentShaderFile)
{
	programId = glCreateProgram();

	Shader vertexShader(vertexShaderFile, GL_VERTEX_SHADER);
	if (!vertexShader.compile()) {
		return false;
	}
	Shader fragmentShader(fragmentShaderFile, GL_FRAGMENT_SHADER);
	if (!fragmentShader.compile()) {
		return false;
	}

	glAttachShader(programId, vertexShader.shaderId);
	glAttachShader(programId, fragmentShader.shaderId);

	glLinkProgram(programId);

	GLint isLinked = GL_FALSE;
	glGetProgramiv(programId, GL_LINK_STATUS, &isLinked);
	if (isLinked == GL_FALSE) {
		GLint maxLength = 0;
		glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &maxLength);
		std::vector<GLchar> infoLog(maxLength);
		glGetProgramInfoLog(programId, maxLength, &maxLength, &infoLog[0]);
		return false;
	}

	glDetachShader(programId, vertexShader.shaderId);
	glDetachShader(programId, fragmentShader.shaderId);

	int numUniforms;
	glGetProgramiv(programId, GL_ACTIVE_UNIFORMS, &numUniforms);
	int maxCharLength;
	glGetProgramiv(programId, GL_ACTIVE_UNIFORM_MAX_LENGTH, &maxCharLength);
	if (numUniforms > 0 && maxCharLength > 0) {
		char* buffer = new char[maxCharLength];
		memset(buffer, 0, maxCharLength);
		for (int i = 0; i < numUniforms; i++)
		{
			int length;
			int size;
			GLenum dataType;
			glGetActiveUniform(programId, i, maxCharLength, &length, &size, &dataType, buffer);
			GLint varLocation = glGetUniformLocation(programId, buffer);
			shaderVariableLocations.emplace(std::string(buffer, length), varLocation);
		}
		delete[] buffer;
	}

	return true;
}
