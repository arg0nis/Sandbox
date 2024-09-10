#pragma once
#include "utils.h"
#include "shader.h"

namespace Renderer {
	void Init();
	void Update();
	void Render();
	void CleanUp();

	float getDeltaTime(); 
	
	glm::vec3 GetCameraPosition();
}
