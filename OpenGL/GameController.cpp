#include "GameController.h"
#include "WindowController.h"
#include "ToolWindow.h"

GameController::GameController() {
	m_shader = { };
	m_camera = { };
	m_mesh = { };
}

void GameController::Initialize() {
	GLFWwindow* window = WindowController::GetInstance().GetWindow(); // Call this first as it creates the window required by GLFW
	M_ASSERT(glewInit() == GLEW_OK, "Failed to Initialize GLEW."); // initialize GLEW
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE); // Ensure we can capture the escape key
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // black background

	// create default perspective camera
	m_camera = Camera(WindowController::GetInstance().GetResolution());
}

void GameController::RunGame() {
	//PrimitiveDrawTest::ToolWindow^ window = gcnew PrimitiveDrawTest::ToolWindow();
	//window->Show();

	m_shader = Shader();
	m_shader.LoadShaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");

	m_mesh = Mesh();
	m_mesh.Create(&m_shader);

	GLFWwindow* win = WindowController::GetInstance().GetWindow();
	do {
		//System::Windows::Forms::Application::DoEvents(); // handle C++/CLI form events

		glClear(GL_COLOR_BUFFER_BIT); // clear the screen
		m_mesh.Render(m_camera.GetProjection() * m_camera.GetView());
		glfwSwapBuffers(win); // swap back and front buffers
		glfwPollEvents();
	} while (glfwGetKey(win, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(win) == 0);

	m_mesh.Cleanup();
	m_shader.Cleanup();
}
