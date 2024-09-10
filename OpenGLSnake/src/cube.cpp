#include "../include/utils.h"
#include "../include/cube.h"
#include "../include/shader.h"
#include "../include/colors.h"

const GLfloat Cube::vertices[] = {
	-.5f, -.5f, -.5f,
	.5f, -.5f, -.5f,
	-.5f, .5f, -.5f,
	.5f, .5f, -.5f,

	-.5f, -.5f, .5f,
	.5f, -.5f, .5f,
	-.5f, .5f, .5f,
	.5f, .5f, .5f,
};

const unsigned int Cube::indices[] = {
	0, 1, 2,  2, 3, 1,	// Front face
	4, 5, 6,  6, 7, 4,	// Back face
	2, 3, 6,  6, 7, 3,	// Top face
	0, 1, 4,  4, 5, 1,	// Bottom face
	0, 2, 6,  6, 4, 0,	// Left face
	1, 3, 7,  7, 5, 1	// Right face
};

Cube::Cube(const glm::vec3& position, const glm::vec3& size) : position{ position }, size{size} {
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	updateTransform();
};

void Cube::updateTransform() {
	modelMat = glm::translate(glm::mat4(1.f), position);
	modelMat = glm::scale(modelMat, size);
}

void Cube::render(Shader& shader) const {
	shader.use();
	shader.setMat4("model", modelMat);
	//shader.setVec3("color", BLUE);

	//utils::log_info("Rendering cube");

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Cube::CleanUp() {
	utils::log_info("Destroying cube");
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void Cube::setPosition(const glm::vec3& newPos) {
	position = newPos;
	updateTransform();
}
void Cube::setSize(const glm::vec3& newSize) {
	size = newSize;
	updateTransform();
}

glm::vec3 Cube::getPosition() const {
	return this->position;
}