#include "WindowController.h"
/*
* ASSIGNMENT 2
* RICHARD PEROCHO
* STUDENT ID: 991454906
*/
WindowController::WindowController() {
	m_window = nullptr;
}

WindowController::~WindowController() {
	if (m_window != nullptr) {
		glfwTerminate();
		m_window = nullptr;
	}
}

void WindowController::NewWindow() {
	M_ASSERT(glfwInit(), "Failed to initialize GLFW."); // initialize GLFW

	// Open a window and create its OpenGL context
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // 3 in 3.1
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1); // 1 in 3.1
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	M_ASSERT((m_window = glfwCreateWindow(mode->width, mode->height, "Assignment 2", NULL, NULL)) != nullptr, "Failed to open GLFW window.");
	glfwMakeContextCurrent(m_window);
}

Resolution WindowController::GetResolution() {
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	return Resolution(mode->width, mode->height);
}