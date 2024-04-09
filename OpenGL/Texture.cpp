#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
/*
* ASSIGNMENT 2
* RICHARD PEROCHO
* STUDENT ID: 991454906
*/
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
    // process filename
    if (_fileName.empty()) {
        std::cout << "[TEXTURE] filename empty" << std::endl;
        return;
    }
    const size_t last_slash_idx = _fileName.find_last_of("\\");
    if (std::string::npos != last_slash_idx)
    {
        _fileName.erase(0, last_slash_idx + 1);
    }
    _fileName = "../Assets/Textures/" + _fileName;

    glGenTextures(1, &m_texture);
    glBindTexture(GL_TEXTURE_2D, m_texture);

    // Set texture wrapping/filtering options
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Load and generate the texture
    stbi_set_flip_vertically_on_load(true); // images have 0.0 on the top, and opengl expects it on the bottom, causing upside-down image. flip image to resolve.
    GLubyte* data = stbi_load(_fileName.c_str(), &m_width, &m_height, &m_channels, 0);

    if (data != nullptr) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        stbi_image_free(data);
        std::cout << "[TEXTURE] successfully loaded " << _fileName << std::endl;
    }
    else {
        // Handle the error - log the error message or throw an exception
        std::cerr << "[TEXTURE] failed to load " << _fileName << std::endl;
    }
}
