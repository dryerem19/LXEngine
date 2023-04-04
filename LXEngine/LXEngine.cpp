// LXEngine.cpp: определяет точку входа для приложения.
//

#include "LXEngine.h"

#include "Application.h"

int main()
{
	LX::Application& app = LX::Application::getInstance();
	app.setFrameRateLimit(60);
	if (!app.init()) {
		return -1;
	}

	app.run();
	return 0;
}
