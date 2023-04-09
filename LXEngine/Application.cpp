#include "pch.h"
#include "Application.h"

LX::Application::Application()
	: _lastTime(std::chrono::high_resolution_clock::now())
{
	_window.SetTitle("LXEngine");
	_window.SetSize(800, 600);
}

LX::Application& LX::Application::getInstance()
{
	static Application instance;
	return instance;
}

bool LX::Application::init()
{
	if (!_window.Initialize()) {
		return false;
	}

	return true;
}

void LX::Application::run()
{
	int frameCount = 0;
	double timeStep = 1.0 / _frameRateLimit;
	double accumulator = 0.0;
	double fpsTimer = 0.0;

	while (!_window.ShouldClose()) {
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

		_window.Update();

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