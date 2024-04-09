#include "GameController.h"
#include "WindowController.h"
#include "ToolWindow.h"
#include "Fonts.h"
#include <random>

/*
* ASSIGNMENT 2
* RICHARD PEROCHO
* STUDENT ID: 991454906
*/
GameController::GameController() {
	m_shaderColor = { };
	m_shaderDiffuse = { };
	m_shaderFont = { };
	m_camera = { };
	m_teapot = { };
	m_texturedSphere = { };
	m_meshBoxes.clear();
}

void GameController::Initialize() {
	GLFWwindow* window = WindowController::GetInstance().GetWindow(); // Call this first as it creates the window required by GLFW
	M_ASSERT(glewInit() == GLEW_OK, "Failed to Initialize GLEW."); // initialize GLEW
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE); // Ensure we can capture the escape key
	glClearColor(0.1f, 0.1f, 0.1f, 0.0f); // grey background
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	srand((unsigned int)time(0));

	// create default perspective camera
	m_camera = Camera(WindowController::GetInstance().GetResolution());
}

void GameController::RunGame() {
	PrimitiveDrawTest::ToolWindow^ window = gcnew PrimitiveDrawTest::ToolWindow();
	window->Show();

	// create and compule GLSL programs from the shaders
	m_shaderColor = Shader();
	m_shaderColor.LoadShaders("Color.vertexshader", "Color.fragmentshader");
	m_shaderDiffuse = Shader();
	m_shaderDiffuse.LoadShaders("Diffuse.vertexshader", "Diffuse.fragmentshader");
	m_shaderFont = Shader();
	m_shaderFont.LoadShaders("Font.vertexshader", "Font.fragmentshader");

	Mesh light = Mesh();
	light.Create(&m_shaderColor, "../Assets/Models/sphere.obj");
	light.SetPosition({ 0.0f, 0.5f, 0.5f });
	light.SetScale({ 0.01f,0.01f,0.01f });
	light.SetColor({ 1.0f, 1.0f,1.0f });
	Mesh::Lights.push_back(light);

	Mesh teapot = Mesh();
	teapot.Create(&m_shaderDiffuse, "../Assets/Models/teapot.obj");
	teapot.SetCameraPosition(m_camera.GetPosition());
	teapot.SetPosition({ 0.0f, 0.0f, 0.0f });
	teapot.SetScale({ 0.02f, 0.02f, 0.02f });
	m_teapot = teapot;

	Mesh texturedSphere = Mesh();
	texturedSphere.Create(&m_shaderDiffuse, "../Assets/Models/texturedSphere.obj");
	texturedSphere.SetCameraPosition(m_camera.GetPosition());
	texturedSphere.SetPosition({ 0.0f, 0.0f, 0.0f });
	texturedSphere.SetScale({ 0.02f, 0.02f, 0.02f });
	m_texturedSphere = texturedSphere;

	Fonts f = Fonts();
	f.Create(&m_shaderFont, "arial.ttf", 100);

	// FPS INITIALIZE
	double prevTime = glfwGetTime();
	int frameCount = 0;
	int fps = 0;

	// MOUSE INITIALIZE
	double mouseX;
	double mouseY;
	bool wasMousePressed = false;

	// SCREEN CENTER
	glm::vec2 screenCenter = glm::vec2(WindowController::GetInstance().GetResolution().m_width / 2.0f, WindowController::GetInstance().GetResolution().m_height / 2.0f);

	// RANDOM NUM GENERATOR INITIALIZE
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(-200, 200);

	do {
		System::Windows::Forms::Application::DoEvents();

		GLint loc = glGetUniformLocation(m_shaderDiffuse.GetProgramID(), "specularStrengthValue");
		glUniform1i(loc, (int)PrimitiveDrawTest::ToolWindow::specularStrengthValue);
		loc = glGetUniformLocation(m_shaderDiffuse.GetProgramID(), "specularColorRValue");
		glUniform1i(loc, (int)PrimitiveDrawTest::ToolWindow::specularColorRValue);
		loc = glGetUniformLocation(m_shaderDiffuse.GetProgramID(), "specularColorGValue");
		glUniform1i(loc, (int)PrimitiveDrawTest::ToolWindow::specularColorGValue);
		loc = glGetUniformLocation(m_shaderDiffuse.GetProgramID(), "specularColorBValue");
		glUniform1i(loc, (int)PrimitiveDrawTest::ToolWindow::specularColorBValue);
		loc = glGetUniformLocation(m_shaderDiffuse.GetProgramID(), "moveLightValue");
		glUniform1i(loc, (bool)PrimitiveDrawTest::ToolWindow::moveLightValue);
		loc = glGetUniformLocation(m_shaderDiffuse.GetProgramID(), "colorByPositionValue");
		glUniform1i(loc, (bool)PrimitiveDrawTest::ToolWindow::colorByPositionValue);
		loc = glGetUniformLocation(m_shaderDiffuse.GetProgramID(), "moveCubesToSphereValue");
		glUniform1i(loc, (bool)PrimitiveDrawTest::ToolWindow::moveCubesToSphereValue);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear the screen

		// FPS TRACKER
		double currTime = glfwGetTime();
		frameCount++;
		if (currTime - prevTime >= 1.0f) {
			fps = frameCount;
			frameCount = 0;
			prevTime = currTime;
		}
		f.RenderText("FPS: " + to_string(fps), 10, 100, 0.5f, { 1.0f, 1.0f, 0.0f });

		// MOUSE TRACKER
		glfwGetCursorPos(WindowController::GetInstance().GetWindow(), &mouseX, &mouseY);
		f.RenderText("Mouse Pos: " + to_string(mouseX) + "   " + to_string(mouseY), 10, 150, 0.5f, { 1.0f, 1.0f, 0.0f });

#pragma region Move Light
		if (PrimitiveDrawTest::ToolWindow::moveLightValue) {
			// mouse click event handling
			glm::vec3 lightVelocity = glm::vec3();
			if (glfwGetMouseButton(WindowController::GetInstance().GetWindow(), GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
				glm::vec2 dir = glm::vec2(
					mouseX < screenCenter.x ? -1 : 1,
					mouseY < screenCenter.y ? 1 : -1
				);
				dir = glm::normalize(dir);
				float speedMultiplier = 0.00005f;
				float speed = speedMultiplier * glm::length(glm::vec2(
					mouseX - screenCenter.x,
					mouseY - screenCenter.y
				));
				lightVelocity = glm::vec3(dir * speed, 0.0f);
			}

			// render
			for (unsigned int count = 0; count < Mesh::Lights.size(); count++) {
				Mesh::Lights[count].Render(m_camera.GetProjection() * m_camera.GetView());
				Mesh::Lights[count].SetPosition(
					Mesh::Lights[count].GetPosition() + lightVelocity
				);

				// RESET LIGHT POSITION
				if (PrimitiveDrawTest::ToolWindow::resetLightPositionValue) {
					Mesh::Lights[count].SetPosition({ 0.0f, 0.5f, 0.5f });
					PrimitiveDrawTest::ToolWindow::resetLightPositionValue = false;
				}
			}
			m_teapot.Render(m_camera.GetProjection() * m_camera.GetView());
		} 
#pragma endregion

#pragma region Color By Position
		else if (PrimitiveDrawTest::ToolWindow::colorByPositionValue) {

			// mouse click event handling
			glm::vec3 teapotVelocity = glm::vec3();
			if (glfwGetMouseButton(WindowController::GetInstance().GetWindow(), GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
				glm::vec2 dir = glm::vec2(
					mouseX < screenCenter.x ? -1 : 1,
					mouseY < screenCenter.y ? 1 : -1
				);
				dir = glm::normalize(dir);
				float speedMultiplier = 0.00005f;
				float speed = speedMultiplier * glm::length(glm::vec2(
					mouseX - screenCenter.x,
					mouseY - screenCenter.y
				));
				teapotVelocity = glm::vec3(dir * speed, 0.0f);
			}

			// render
			m_teapot.Render(m_camera.GetProjection() * m_camera.GetView());
			m_teapot.SetPosition(m_teapot.GetPosition() + teapotVelocity);

			// RESET TEAPOT POSITION
			if (PrimitiveDrawTest::ToolWindow::resetTeapotPositionValue) {
				m_teapot.SetPosition({ 0, 0, 0 });
				PrimitiveDrawTest::ToolWindow::resetTeapotPositionValue = false;
			}
		}
#pragma endregion

#pragma region Move Cubes To Sphere
		else if (PrimitiveDrawTest::ToolWindow::moveCubesToSphereValue) {
			// mouse click
			int mouseState = glfwGetMouseButton(WindowController::GetInstance().GetWindow(), GLFW_MOUSE_BUTTON_LEFT);
			if (mouseState == GLFW_PRESS && !wasMousePressed) {
				// create box at random position
				Mesh box = Mesh();
				box.Create(&m_shaderDiffuse, "../Assets/Models/Cube.obj");
				box.SetCameraPosition(m_camera.GetPosition());
				box.SetPosition({ distrib(gen)/100.0, distrib(gen)/100.0, 0 });
				box.SetScale({ 0.02,0.02,0.02 });
				m_meshBoxes.push_back(box);

				wasMousePressed = true; // prevent click on multiple frames
			}
			else if (mouseState == GLFW_RELEASE) {
				wasMousePressed = false;
			}
			// render
			for (unsigned int count = 0; count < Mesh::Lights.size(); count++) {
				Mesh::Lights[count].Render(m_camera.GetProjection() * m_camera.GetView());
			}
			m_texturedSphere.Render(m_camera.GetProjection() * m_camera.GetView());
			for (unsigned int count = 0; count < m_meshBoxes.size(); count++) {
				m_meshBoxes[count].Render(m_camera.GetProjection()* m_camera.GetView());
				
				// move box toward sphere
				glm::vec3 dir = m_texturedSphere.GetPosition() - m_meshBoxes[count].GetPosition();
				dir = glm::normalize(dir);
				float speed = 0.005f;
				glm::vec3 velocity = dir * speed;
				m_meshBoxes[count].SetPosition(
					m_meshBoxes[count].GetPosition() + velocity
				);

				// destroy box if within sphere radius
				float distance = glm::distance(m_texturedSphere.GetPosition(), m_meshBoxes[count].GetPosition());
				if (distance <= 0.02f /*sphere scale*/) {
					m_meshBoxes.erase(m_meshBoxes.begin() + count);
				}

			}
			f.RenderText("Cubes: " + to_string(m_meshBoxes.size()), 10, 230, 0.5f, {1.0f, 1.0f, 0.0f});
		}
#pragma endregion


		glfwSwapBuffers(WindowController::GetInstance().GetWindow()); // swap back and front buffers
		glfwPollEvents();

	} while (glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS && 
		glfwWindowShouldClose(WindowController::GetInstance().GetWindow()) == 0);

	for (int count = 0; count < Mesh::Lights.size(); count++) {
		Mesh::Lights[count].Cleanup();
	}
	for (unsigned int count = 0; count < m_meshBoxes.size(); count++) {
		m_meshBoxes[count].Cleanup();
	}
	m_teapot.Cleanup();
	m_texturedSphere.Cleanup();
	m_shaderFont.Cleanup();
	m_shaderDiffuse.Cleanup();
	m_shaderColor.Cleanup();
}
