#include "../include/utils.h"

#include "../include/shader.h"




Shader::Shader(const std::string& vertPath, const std::string& fragPath) {
	vertCode = utils::readTextFromFile(vertPath);
	fragCode = utils::readTextFromFile(fragPath);

	const char* vertSrc(vertCode.c_str());
	const char* fragSrc(fragCode.c_str());
	
	unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertex, 1, &vertSrc, NULL);
	glShaderSource(fragment, 1, &fragSrc, NULL);

	glCompileShader(vertex);
	if(checkForErrors(vertex, "VERTEX"))
		utils::log_info("Compiled vertex shader");
	glCompileShader(fragment);
	if(checkForErrors(vertex, "FRAGMENT"))
		utils::log_info("Compiled vertex shader");

	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);
	checkForErrors(ID, "PROGRAM");

	glDeleteShader(vertex);
	glDeleteShader(fragment);

}

void Shader::CleanUp() {
	std::string cleanUpMessage = "Deleting shader program with ID " + std::to_string(ID);
	utils::log_info(cleanUpMessage.c_str());
	glDeleteProgram(ID);
}

void Shader::use() const {
	glUseProgram(ID);
	//utils::log_info(vertCode.c_str());
	//utils::log_info(fragCode.c_str());
}

int Shader::checkForErrors(const unsigned int shader, const std::string type) {
	int success;
	char infoLog[512];
	if (type != "PROGRAM") {
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::string errorMessage = "Shader compilation error of type: " + type;
			utils::log_error(errorMessage.c_str());
			std::cout << "- LOG: " << infoLog << "\n";
		}
	}
	else {
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shader, 512, NULL, infoLog);
			utils::log_error("Shader program compilation failed");
			std::cout << "- LOG: " << infoLog << "\n";
		}
	}
	return success;
}
void Shader::setBool(const std::string& uniformName, const bool& value) {
	glUniform1i(glGetUniformLocation(ID, uniformName.c_str()), value);
};
void Shader::setInt(const std::string& uniformName, const int& value) {
	glUniform1i(glGetUniformLocation(ID, uniformName.c_str()), value);
};
void Shader::setMat4(const std::string& uniformName, const glm::mat4& value) {
	glUniformMatrix4fv(glGetUniformLocation(ID, uniformName.c_str()), 1, GL_FALSE, &value[0][0]);
};
void Shader::setVec3(const std::string& uniformName, const glm::vec3& value) {
	glUniform3fv(glGetUniformLocation(ID, uniformName.c_str()), 1, &value[0]);
};