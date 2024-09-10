#pragma once
#include "utils.h"

namespace BackEnd {
	void Init();
	void Update();
	void CleanUp();

	int GetWindowWidth();
	int GetWindowHeight();

	bool WindowShouldClose();

	GLFWwindow* GetWindowPointer();
}
