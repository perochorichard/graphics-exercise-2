#ifndef MESH_H
#define MESH_H

#include "StandardIncludes.h"
class Shader;

class Mesh
{
public:
	Mesh();
	virtual ~Mesh();

	// Methods
	void Create(Shader* _shader);
	void Cleanup();
	void Render();

private:
	Shader* m_shader;
	GLuint m_vertexBuffer;
	std::vector<GLfloat> m_vertexData;
};

#endif // !MESH_H


