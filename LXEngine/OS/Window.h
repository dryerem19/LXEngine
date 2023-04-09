#pragma once
#include "../log.h"

class Window
{
private:
	GLFWwindow* _pWindow;
	std::string _title;
	unsigned int _width;
	unsigned int _height;
public:
	Window(const std::string& title, unsigned int width, unsigned int height);
	Window() = default;
	~Window();
	bool Initialize();
	bool ShouldClose();
	void Update();

	void SetTitle(const std::string& title);
	void SetSize(unsigned int width, unsigned int height);
};