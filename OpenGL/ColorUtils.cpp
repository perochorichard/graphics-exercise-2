#include "ColorUtils.h"

glm::vec3 ColorUtils::RGBtoYUV(glm::vec3 rgb) {
	glm::mat3 rgbToYuvMatrix = {
		{0.299, 0.587, 0.114},
		{-0.14713, -0.28886, 0.436},
		{0.615, -0.51499, -0.10001}
	};
	return rgbToYuvMatrix * rgb;
}