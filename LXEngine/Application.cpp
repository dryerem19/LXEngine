#include "pch.h"
#include "Application.h"

LX::Application::Application()
	: _pWindow(nullptr), _lastTime(std::chrono::high_resolution_clock::now())
{
}

LX::Application::~Application()
{
	glfwTerminate();
}

LX::Application& LX::Application::getInstance()
{
	static Application instance;
	return instance;
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

	int frameCount = 0;
	double timeStep = 1.0 / _frameRateLimit;
	double accumulator = 0.0;
	double fpsTimer = 0.0;

	while (!glfwWindowShouldClose(_pWindow)) {
		glClear(GL_COLOR_BUFFER_BIT);

		auto currentTime = std::chrono::high_resolution_clock::now();
		double deltaTime = std::chrono::duration_cast<std::chrono::duration<double>>(currentTime - _lastTime).count();
		_lastTime = currentTime;
		accumulator += deltaTime;
		fpsTimer += deltaTime;

		if (timeStep > 0.0) {
			while (accumulator >= timeStep) {
				update(deltaTime);
				accumulator -= timeStep;
			}
		}
		else {
			update(deltaTime);
			accumulator = 0.0;
		}

		glfwPollEvents();
		glfwSwapBuffers(_pWindow);

		frameCount++;
		if (fpsTimer >= 1.0) {
			_fps = frameCount;
			frameCount = 0;
			fpsTimer -= 1.0;
		}
	}
}

void LX::Application::setFrameRateLimit(unsigned int frameRateLimit)
{
	_frameRateLimit = frameRateLimit;
}

void LX::Application::update(double deltaTime)
{
	LOG_INFO(_fps);
}
