#version 460 core

in vec2 TexCoord;

out vec4 FragColor;



uniform vec3 color;
uniform sampler2D ourTexture;
uniform bool hasTexture;

void main() {

	if(hasTexture) {
		FragColor = texture(ourTexture, TexCoord);
	} else {
		FragColor = vec4(color, 1.f);
	}
}