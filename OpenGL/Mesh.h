#ifndef MESH_H
#define MESH_H

#include "StandardIncludes.h"
#include "Texture.h"

class Shader;

class Mesh
{
public:
	Mesh();
	virtual ~Mesh();

	// Methods
	void Create(Shader* _shader);
	void Cleanup();
	void Render(glm::mat4 _wvp);

private:
	Shader* m_shader;
	Texture m_texture;
	Texture m_texture2;
	GLuint m_vertexBuffer; // GPU buffer
	GLuint m_indexBuffer; // GPU buffer
	std::vector<GLfloat> m_vertexData; // store vertex data in RAM
	std::vector<GLubyte> m_indexData; // store index data in RAM
	glm::vec3 m_position;
	glm::vec3 m_rotation;
};

#endif // !MESH_H


