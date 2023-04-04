#pragma once
#include "log.h"

namespace LX
{
	class Application
	{
	private:
		GLFWwindow* _pWindow;
		int _frameCount;
		std::chrono::time_point<std::chrono::high_resolution_clock> _lastTime;
	public:
		Application();
		~Application();
		bool init();
		void run();
	private:
		void update(double deltaTime);
	};
}