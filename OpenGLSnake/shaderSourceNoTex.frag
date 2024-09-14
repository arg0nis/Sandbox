#version 460 core

in vec2 TexCoord;

out vec4 FragColor;

uniform vec3 color;
uniform sampler2D ourTexture;

void main() {
	//FragColor = vec4(color, 1.f);
	FragColor = texture(ourTexture, TexCoord);
}