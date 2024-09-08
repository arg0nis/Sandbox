#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <format>


namespace utils {

	inline void log_info(const char* infoMessage) {
		std::cout << "INFO: " << infoMessage << std::endl;
	}
	inline void log_error(const char* errorMessage) {
		std::cerr << "ERROR: " << errorMessage << std::endl;
	}

	inline void setClearColor(const glm::vec3& color, const float alpha) {
		glClearColor(color.x, color.y, color.z, alpha);
	}

	inline std::string vec3ToString(const glm::vec3 vec) {
		return std::string("(" + std::format("{:.2f}", vec.x) + ", " + std::format("{:.2f}", vec.y) + ", " + std::format("{:.2f}", vec.x) + ")");
	};

	inline std::string readTextFromFile(const std::string& path){
		std::ifstream file(path);
		std::string str;
		std::string line;
		while (std::getline(file, line)) 
			str += line + "\n";
		return str;
	}


};

