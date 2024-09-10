#pragma once

#include "utils.h"
#include "shader.h"

class Floor {
public:
	Floor() = default;
	Floor(glm::vec3 size) {

		modelMat = glm::translate(glm::mat4(1.f), glm::vec3(.0f, -2.0f, .0f));
		modelMat = glm::scale(modelMat, size);
		modelMat = glm::rotate(modelMat, glm::radians(90.f), glm::vec3(1.0f, .0f, .0f));

		glCreateBuffers(1, &VBO);
		glCreateBuffers(1, &EBO);
		glCreateVertexArrays(1, &VAO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		glEnableVertexAttribArray(0);

		glBindVertexArray(0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void Draw(Shader &shader) {
		shader.use();
		shader.setMat4("model", modelMat);
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}

	void CleanUp() {
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
	}

private:

	float vertices[12]{
		-.5f, .5f, .0f,		// Top left
		.5f, .5f, .0f,		// Top right
		-.5f, -.5f, .0f,	// Bottom left	
		.5f, -.5f, .0f		// Bottom right
	};


	unsigned int indices[6] {
		0, 2, 3,
		0, 1, 3
	};

	unsigned int VBO, EBO, VAO;
	glm::mat4 modelMat;

};
