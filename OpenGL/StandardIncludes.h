#ifndef STANDARD_INCLUDES_H
#define STANDARD_INCLUDES_H


// Include standard headers
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <map>

// Window specific includes and defines
#ifdef _WIN32
#include <Windows.h>
#define M_ASSERT(_cond, _msg) \
	if (!(_cond)) {OutputDebugStringA(_msg); std::abort(); glfwTerminate(); }
#endif

// Font includes
#include <ft2build.h>
#include FT_FREETYPE_H

// Open GL/Helper headers
#include <GL/glew.h>		//Include GLEW
#include <GLFW/glfw3.h>     //Include GLEW
#include <glm/glm.hpp>		//Include GLM

#include <glm/ext.hpp>		//OpenGL Experimental to_string
#include "Resolution.h"

#include "Singleton.h"

using namespace std;

#endif  // STANDARD_INCLUDES_H

