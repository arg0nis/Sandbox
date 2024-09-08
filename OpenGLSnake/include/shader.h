#pragma once

#include "utils.h"

class Shader {
public:
	Shader(const std::string& vertPath, const std::string& fragPath);
	Shader() = default;
	~Shader();
	void use() const;
	void setBool(const std::string& uniformName, const bool& value);
	void setInt(const std::string& uniformName, const int& value);
	void setMat4(const std::string& uniformName, const glm::mat4& value);
	void setVec3(const std::string& uniformName, const glm::vec3& vec);
private:
	std::string vertCode, fragCode;
	int checkForErrors(const unsigned int shader, const std::string type);
	unsigned int ID;
};
