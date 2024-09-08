#pragma once
#include "utils.h"

namespace BackEnd {
	void Init();
	void Update();

	int GetWindowWidth();
	int GetWindowHeight();

	bool WindowShouldClose();

	GLFWwindow* GetWindowPointer();
}
