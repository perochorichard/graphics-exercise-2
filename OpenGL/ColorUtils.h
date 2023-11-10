#ifndef COLOR_UTILS_H
#define COLOR_UTILS_H

#include "StandardIncludes.h"

class ColorUtils
{
public:
	static glm::vec3 RGBtoYUV(glm::vec3 rgb);
	static glm::vec3 YUVtoRGB(glm::vec3 yuv);
};

#endif // !COLOR_UTILS_H

