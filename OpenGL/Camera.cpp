#include "Camera.h"

Camera::Camera() {
	m_projection = { };
	m_view = { };
	m_position = { };
}

Camera::Camera(Resolution _screenResolution) {
	m_position = { 1, 1,1  };
	// projection matrix (45 deg FoV, 4:3 aspect ratio, display range: 0.1 unit <-> 100 units
	m_projection = glm::perspective(glm::radians(45.0f),
		(float)_screenResolution.m_width /
		(float)_screenResolution.m_height, // aspect ratio
		0.1f, // near clipping plane
		1000.0f); // far clipping plane
	//m_projection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, 0.0f, 100.0f);
	m_view = glm::lookAt(
		m_position, // camera position (world space)
		glm::vec3(0, 0, 0),  // loot at
		glm::vec3(0, 1, 0)   // direction of "up" (0, -1, 0) for upside-down
	);
}

Camera::~Camera() {

}