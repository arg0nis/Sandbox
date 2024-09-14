

#include "../include/utils.h"

#include "../include/Renderer.h"

#include "../include/camera.h"
#include "../include/Input.h"
#include "../include/keycodes.h"
#include "../include/BackEnd.h"
#include "../include/colors.h"
#include "../include/shader.h"
#include "../include/cube.h"
#include "../include/Floor.h"



namespace Renderer {
	Camera _camera;
	Shader _shader;
	Cube _cubes[3];
	Floor _floor;

	glm::vec3 _cameraPosition;
	float _deltaFrame;
	float _lastFrame;

	int _windowWidth;
	int _windowHeight;

	void calculateDeltaTime(); 
	void handleMouseMovement();
	void handleMouseScroll();
	void handleKeyboard();

	GLFWwindow* _window;

	void Init() {
		glm::vec3 cameraPos(.0f, .0f, 3.f);
		_camera = Camera(cameraPos);
		_shader = Shader("shaderSource.vert", "shaderSource.frag");
		_shader.use();
		_shader.setVec3("color", RED);
		_cameraPosition = cameraPos;
		_window = BackEnd::GetWindowPointer();
		utils::setClearColor(WHITE, 1.f);

		glEnable(GL_DEPTH_TEST);
		
		_cubes[0] = Cube(glm::vec3(.0f, .0f, .0f), glm::vec3(1.f, 1.f, 1.f), true);
		_cubes[1] = Cube(glm::vec3(3.0f, .0f, .0f), glm::vec3(1.f, 1.f, 1.f), true);
		_cubes[2] = Cube(glm::vec3(5.0f, .0f, .0f), glm::vec3(1.f, 1.f, 1.f), false);
		_floor = Floor(glm::vec3(10.f, 10.f, 10.f));
	}
	
	void Render() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glm::mat4 view = _camera.GetViewMatrix();
		glm::mat4 projection = glm::perspective(glm::radians(_camera.Zoom), (float)_windowWidth / _windowHeight, 1.f, 100.f );

		_shader.use();
		_shader.setMat4("view", view);
		_shader.setMat4("projection", projection);

		for (Cube cube : _cubes) {
			cube.render(_shader);
		}

		_floor.Draw(_shader);
	}

	void CleanUp() {
		for (Cube cube : _cubes) {
			cube.CleanUp();
		}
		_shader.CleanUp();
		_floor.CleanUp();
	}

	void Update() {
		calculateDeltaTime();
		handleMouseMovement();
		handleMouseScroll();
		handleKeyboard();
		_windowWidth = BackEnd::GetWindowWidth();
		_windowHeight = BackEnd::GetWindowHeight();
	}

	void calculateDeltaTime() {
		float currentTime = static_cast<float>(glfwGetTime());
		_deltaFrame = currentTime - _lastFrame;
		_lastFrame = currentTime;

	}
	void handleMouseMovement() {
		float xoffset = static_cast<float>(Input::GetMouseOffsetX());
		float yoffset = static_cast<float>(Input::GetMouseOffsetY());
		_camera.ProcessMouseMovement(xoffset, yoffset);
	};

	void handleMouseScroll() {
		if (Input::Scrolled()) {
			float scrollOffset = static_cast<float>(Input::GetScrollOffset());
			_camera.ProcessMouseScroll(scrollOffset);
		}
	};

	float getDeltaTime() {
		return _deltaFrame;
	}

	void handleKeyboard() {
		if (Input::GetKeyPressed(MY_KEY_W))
			_camera.ProcessKeyboard(FORWARD, _deltaFrame);
		if (Input::GetKeyPressed(MY_KEY_A))
			_camera.ProcessKeyboard(LEFT, _deltaFrame);
		if (Input::GetKeyPressed(MY_KEY_D))
			_camera.ProcessKeyboard(RIGHT, _deltaFrame);
		if (Input::GetKeyPressed(MY_KEY_S)) 
			_camera.ProcessKeyboard(BACKWARD, _deltaFrame);

		if (Input::GetKeyPressed(MY_KEY_E)) 
			_camera.ProcessKeyboard(UP, _deltaFrame);
		if (Input::GetKeyPressed(MY_KEY_Q)) 
			_camera.ProcessKeyboard(DOWN, _deltaFrame);
	}

	glm::vec3 GetCameraPosition() {
		return _cameraPosition;
	}

}