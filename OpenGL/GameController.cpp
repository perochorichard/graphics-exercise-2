#include "GameController.h"
#include "WindowController.h"
#include "ToolWindow.h"

GameController::GameController() {
	m_shaderColor = { };
	m_shaderDiffuse = { };
	m_camera = { };
	m_meshBox = { };
	m_meshLight = { };
}

void GameController::Initialize() {
	GLFWwindow* window = WindowController::GetInstance().GetWindow(); // Call this first as it creates the window required by GLFW
	M_ASSERT(glewInit() == GLEW_OK, "Failed to Initialize GLEW."); // initialize GLEW
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE); // Ensure we can capture the escape key
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // black background
	glEnable(GL_DEPTH_TEST);

	// create default perspective camera
	m_camera = Camera(WindowController::GetInstance().GetResolution());
}

void GameController::RunGame() {
	//PrimitiveDrawTest::ToolWindow^ window = gcnew PrimitiveDrawTest::ToolWindow();
	//window->Show();

	m_shaderColor = Shader();
	m_shaderColor.LoadShaders("Color.vertexshader", "Color.fragmentshader");
	m_shaderDiffuse = Shader();
	m_shaderDiffuse.LoadShaders("Diffuse.vertexshader", "Diffuse.fragmentshader");

	m_meshLight = Mesh();
	m_meshLight.Create(&m_shaderColor);
	m_meshLight.SetPosition({ 1, -0.5f, 0.0f });
	m_meshLight.SetScale({ 0.1f, 0.1f, 0.1f });

	m_meshBox = Mesh();
	m_meshBox.Create(&m_shaderDiffuse);
	m_meshBox.SetLightColor({ 0.5f, 0.9f, 0.5f });
	m_meshBox.SetLightPosition(m_meshLight.GetPosition());
	m_meshBox.SetCameraPosition(m_camera.GetPosition());

	GLFWwindow* win = WindowController::GetInstance().GetWindow();
	do {
		//System::Windows::Forms::Application::DoEvents(); // handle C++/CLI form events

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear the screen
		m_meshBox.Render(m_camera.GetProjection() * m_camera.GetView());
		m_meshLight.Render(m_camera.GetProjection() * m_camera.GetView());
		glfwSwapBuffers(win); // swap back and front buffers
		glfwPollEvents();
	} while (glfwGetKey(win, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(win) == 0);

	m_meshLight.Cleanup();
	m_meshBox.Cleanup();
	m_shaderDiffuse.Cleanup();
	m_shaderColor.Cleanup();
}
