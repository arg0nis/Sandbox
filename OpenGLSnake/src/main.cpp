#include "../include/BackEnd.h"
#include "../include/Input.h"
#include "../include/Renderer.h"

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
}