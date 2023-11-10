#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture::Texture() {
	m_width = 0;
	m_height = 0;
	m_channels = 0;
	m_texture = 0;
}

void Texture::Cleanup() {
	glDeleteTextures(1, &m_texture);
}

void Texture::LoadTexture(string _fileName) {
    glGenTextures(1, &m_texture);
    glBindTexture(GL_TEXTURE_2D, m_texture);

    // Set texture wrapping/filtering options
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Load and generate the texture
    GLubyte* data = stbi_load(_fileName.c_str(), &m_width, &m_height, &m_channels, 0);

    if (data != nullptr) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        stbi_image_free(data);
        std::cout << "texture loaded..." << std::endl;
    }
    else {
        // Handle the error - log the error message or throw an exception
        std::cerr << "Failed to load texture: " << _fileName << std::endl;
    }
}
