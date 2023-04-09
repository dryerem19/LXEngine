#include "../pch.h"
#include "Window.h"

Window::Window(const std::string& title, unsigned int width, unsigned int height)
	: _title(title), _width(width), _height(height)
{
}

Window::~Window()
{
	glfwTerminate();
}

bool Window::Initialize()
{
	if (!glfwInit()) {
		LOG_ERROR("Failed to initialize GLFW");
		return false;
	}

	_pWindow = glfwCreateWindow(_width, _height, _title.c_str(), nullptr, nullptr);
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

bool Window::ShouldClose()
{
	return glfwWindowShouldClose(_pWindow);
}

void Window::Update()
{
	glfwPollEvents();
	glfwSwapBuffers(_pWindow);
}

void Window::SetTitle(const std::string& title)
{
	if (_pWindow) {
		glfwSetWindowTitle(_pWindow, title.c_str());
	}

	_title = title;
}

void Window::SetSize(unsigned int width, unsigned int height)
{
	if (_pWindow) {
		glfwSetWindowSize(_pWindow, width, height);
	}

	_width  = width;
	_height = height;
}
