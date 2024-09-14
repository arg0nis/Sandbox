#pragma once
#include <stb_image.h>
#include "utils.h"

class Texture {
public:
	Texture() = default;
	Texture(const char* path) {
		data = stbi_load(path, &width, &height, &nrChannels, 0);

		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else {
			utils::log_error("Failed to load texture");
		}


		stbi_image_free(data);
	}

	unsigned int id() const {
		return texture;
	}

private:
	int width, height, nrChannels;
	unsigned char* data;

	unsigned int texture;


};


