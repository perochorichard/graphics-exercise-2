#include "Camera.h"

Camera::Camera() {
	m_projection = { };
	m_view = { };
}

Camera::Camera(Resolution _screenResolution) {

	// projection matrix (45 deg FoV, 4:3 aspect ratio, display range: 0.1 unit <-> 100 units
	m_projection = glm::perspective(glm::radians(45.0f),
		(float)_screenResolution.m_width /
		(float)_screenResolution.m_height, // aspect ratio
		0.1f,
		100.0f);

	m_view = glm::lookAt(
		glm::vec3(0, 0, 30),
		glm::vec3(0, 0, 0),
		glm::vec3(0, 1, 0)
	);
}

Camera::~Camera() {

}