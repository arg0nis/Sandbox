#pragma once

namespace Input {
	void Init();
	void Update(); 

	double GetMouseX();
	double GetMouseY();
	double GetMouseOffsetX();
	double GetMouseOffsetY();
	double GetScrollOffset();
	double GetMouseWheelValue();
	bool GetKeyPressed(int key);
}
