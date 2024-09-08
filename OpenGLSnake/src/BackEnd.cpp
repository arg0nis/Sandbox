

#include "../include/utils.h"

#include "../include/BackEnd.h"
#include "../include/Renderer.h"

#include <deque>

#define VSYNC_DISABLED true

namespace BackEnd {

	GLFWwindow* _window;
	int _windowWidth = 0;
	int _windowHeight = 0;
	float _deltaTime;

	void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	void initGlad();
	void calculateFPS();

	void Init() {

		int width = 800;
		int height = 600;
		
		if (!glfwInit()) { 
			utils::log_error("Failed to initialize GLFW");
			exit(1);
		}
		else {
			utils::log_info("GLFW initialized successfully");

			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		}

		_windowWidth = width;
		_windowHeight = height;

		_window = glfwCreateWindow(width, height, "Trip", NULL, NULL);

		if (!_window) {
			utils::log_error("Window creation failed");
			glfwTerminate();
			exit(1);
		} else {
			utils::log_info("Window was created successfully");
			glfwMakeContextCurrent(_window);

			if (VSYNC_DISABLED) 
				glfwSwapInterval(0);

			glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

			glfwSetFramebufferSizeCallback(_window, framebuffer_size_callback);

			utils::log_info("Window callbacks were set successfully");
		}

		initGlad();
	}

	void Update() {
		glfwSwapBuffers(_window);
		_deltaTime = Renderer::getDeltaTime();
		//calculateFPS();
	}

	void initGlad() {
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			utils::log_error("Failed to initialize GLAD");
			glfwTerminate();
			exit(1);
		}
		else {
			utils::log_info("GLAD initialized successfully");
		}
	}

	bool WindowShouldClose(){
		return glfwWindowShouldClose(_window);
	}

	void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);

		_windowWidth = width;
		_windowHeight = height;
	}
	void calculateFPS() {
		float fps = 1.f / _deltaTime;
		std::string fpsMessage;

		static std::deque<float> frameTimes;
		static const int smoothingWindow = 100;

		if (_deltaTime > 0.0f) {
			frameTimes.push_back(_deltaTime);
			if (frameTimes.size() > smoothingWindow) 
				frameTimes.pop_front();

			float avgDeltaTime = 0.f;
			for (float dt : frameTimes) {
				avgDeltaTime += dt;
			}
			avgDeltaTime /= frameTimes.size();
			fps = 1.f / avgDeltaTime;
			fpsMessage = "FPS: " + std::to_string(static_cast<int>(fps));

		} else
			fpsMessage = "FPS: Inf";

		utils::log_info(fpsMessage.c_str());
	}

	int GetWindowWidth() {
		return _windowWidth;
	}

	int GetWindowHeight() {
		return _windowHeight;
	}



	GLFWwindow* GetWindowPointer() {
		return _window;
	}
}
