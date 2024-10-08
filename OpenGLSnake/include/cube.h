#pragma once

#include "utils.h"
#include "shader.h"
#include "Texture.h"

#include <glm/gtc/matrix_transform.hpp>


class Cube {
public:

	Texture texture;
	Cube(const glm::vec3& position, const glm::vec3& size, bool hasTexture);
	Cube() = default;

	void CleanUp();

	void render(Shader& shader)const;
	void setPosition(const glm::vec3& position);
	void setSize(const glm::vec3& size);
	glm::vec3 getPosition() const;
private:
	void updateTransform();

	bool hasTexture;


	glm::vec3 size;
	glm::vec3 position;
	glm::mat4 modelMat;

	unsigned int VBO, VAO, EBO;

	static const unsigned int indices[];
	static const GLfloat vertices[];
};
