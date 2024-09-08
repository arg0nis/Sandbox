#include "../include/utils.h"
#include "../include/BackEnd.h"


#include "../include/keycodes.h"


namespace Input {

	
	bool _keyPressed[GLFW_KEY_LAST];
	double _mouseX;
	double _mouseY;
	double _mouseLastX;
	double _mouseLastY;
	double _mouseOffsetX;
	double _mouseOffsetY;
	double _scrollWheelYOffset;
	GLFWwindow* _window;

	void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

	void Init() {
		double x, y;

		_window = BackEnd::GetWindowPointer();
		glfwSetScrollCallback(_window, scroll_callback);
		glfwGetCursorPos(_window, &x, &y);

		_mouseX = x;
		_mouseY = y;
		_mouseLastX = 0;
		_mouseLastY = 0;
		_mouseOffsetX = _mouseX - _mouseLastX;
		_mouseOffsetY = _mouseY - _mouseLastY;
		
	}

	void Update() {
		double x, y;
		glfwPollEvents();
		_window = BackEnd::GetWindowPointer();
		glfwGetCursorPos(_window, &x, &y);

		if (_keyPressed[MY_KEY_ESCAPE]) {
			glfwSetWindowShouldClose(_window, true);
		}

		_mouseLastX = _mouseX;
		_mouseLastY = _mouseY;
		_mouseX = x;
		_mouseY = y;
		_mouseOffsetX = _mouseX - _mouseLastX;
		_mouseOffsetY = _mouseLastY - _mouseY;

		for (int i = 0; i < GLFW_KEY_LAST; i++) {
			if (glfwGetKey(_window, i) == GLFW_PRESS) {
				_keyPressed[i] = true;
			}
		}

	}

	double GetMouseX() {
		return _mouseX;
	};
	
	double GetMouseY() {
		return _mouseY;
	};

	double GetMouseOffsetX() {
		return _mouseOffsetX;
	};
	double GetMouseOffsetY() {
		return _mouseOffsetY;
	};
	double GetScrollOffset() {
		return _scrollWheelYOffset;
	}

	bool GetKeyPressed(int key) {
		return _keyPressed[key];
	}



	void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
		_scrollWheelYOffset = yoffset;
	}
}