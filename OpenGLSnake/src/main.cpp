#include "../include/BackEnd.h"
#include "../include/Input.h"
#include "../include/Renderer.h"
#include "../include/shader.h"

int main() {
	BackEnd::Init();
	Input::Init();
	Renderer::Init();

	while (!BackEnd::WindowShouldClose()) {
		Input::Update();
		BackEnd::Update();
		Renderer::Update();
		Renderer::Render();
	}

	std::cout << "\n";
	Renderer::CleanUp();
	BackEnd::CleanUp();

	return 0;
}