#pragma once
#include "log.h"

namespace LX
{
	class Application
	{
	private:
		GLFWwindow* _pWindow;
		int _fps;
		unsigned int _frameRateLimit;
		std::chrono::time_point<std::chrono::high_resolution_clock> _lastTime;
	public:
		static Application& getInstance();
		bool init();
		void run();
		void setFrameRateLimit(unsigned int frameRateLimit);

	private:
		Application();
		~Application();
		Application(const Application&) = delete;
		Application& operator=(const Application&) = delete;

		void update(double deltaTime);
	};
}