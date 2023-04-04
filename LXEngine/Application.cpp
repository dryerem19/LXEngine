#include "pch.h"
#include "Application.h"

LX::Application::Application()
	: _pWindow(nullptr), _lastTime(std::chrono::high_resolution_clock::now()),
		_frameCount(0)
{
}

LX::Application::~Application()
{
	glfwTerminate();
}

bool LX::Application::init()
{
	if (!glfwInit()) {
		LOG_ERROR("Failed to initialize GLFW");
		return false;
	}

	_pWindow = glfwCreateWindow(800, 600, "LX Game Engine", nullptr, nullptr);
	if (!_pWindow) {
		LOG_ERROR("Failed to create GLFW window");
		return false;
	}
	glfwMakeContextCurrent(_pWindow);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		LOG_ERROR("Failed to initialize GLAD");
		glfwTerminate();
		return false;
	}

	return true;
}

void LX::Application::run()
{
	if (!_pWindow) {
		LOG_ERROR("The window has not been created, make sure that you have not forgotten to call init()");
		return;
	}

	while (!glfwWindowShouldClose(_pWindow)) {
		glClear(GL_COLOR_BUFFER_BIT);

		auto currentTime = std::chrono::high_resolution_clock::now();
		double deltaTime = std::chrono::duration_cast<std::chrono::duration<double>>(currentTime - _lastTime).count();
		if (deltaTime >= 1.0) {
			_frameCount = 0;
			_lastTime = currentTime;
		}

		update(deltaTime);

		glfwPollEvents();
		glfwSwapBuffers(_pWindow);
	}
}

void LX::Application::update(double deltaTime)
{
}
