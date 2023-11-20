#ifndef STANDARD_INCLUDES_H
#define STANDARD_INCLUDES_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include <GL/glew.h> // Include GLEW
#include <GLFW/glfw3.h> // Inlcude GLFW
#include <glm/glm.hpp> // Include GLM
#include <glm/gtc/matrix_transform.hpp> // View / projection
#include <glm/gtc/random.hpp>

#include "Resolution.h"
#include "Singleton.h"

// Windows specific
#ifdef _WIN32
#include <Windows.h>
#define M_ASSERT(_cond, _msg) \
	if (!(_cond)) { OutputDebugStringA(_msg); std::abort(); glfwTerminate(); }
#endif // !_WIN32

using namespace std;

#endif // !STANDARD_INCLUDES_H
