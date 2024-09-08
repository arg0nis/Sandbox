#pragma once
#include "utils.h"

namespace Renderer {
	void Init();
	void Update();
	void Render();

	float getDeltaTime(); 
	
	glm::vec3 GetCameraPosition();
}
