#include "Mesh.h"
#include "Shader.h"

Mesh::Mesh() {
	m_shader = nullptr;
	m_vertexBuffer = 0;
}

Mesh::~Mesh() {

}

void Mesh::Create(Shader* _shader) {
	m_shader = _shader;
	// define triangle vertex data
	m_vertexData = { -0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f };
	// creates a new buffer object and assigns unique ID to m_vertexBuffer for reference.
	glGenBuffers(1, &m_vertexBuffer); 
	// binds buffer object (using id) to the GL_ARRAY_BUFFER target.
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	// Allocate memory and copy the vertex data into the GL_ARRAY_BUFFER target.
	// The data will be used for rendering and will not change frequently (GL_STATIC_DRAW).
	glBufferData(GL_ARRAY_BUFFER, m_vertexData.size() * sizeof(float), m_vertexData.data(), GL_STATIC_DRAW);
}

void Mesh::Cleanup() {
	glDeleteBuffers(1, &m_vertexBuffer);
}

void Mesh::Render() {
	glUseProgram(m_shader->GetProgramID()); // Use our shader

	glEnableVertexAttribArray(m_shader->GetAttrVertices()); // vertext position data will be used in the rendering process
	glVertexAttribPointer(m_shader->GetAttrVertices(), 
		3, // size 
		GL_FLOAT, // type 
		GL_FALSE, // normalized 
		0, // stride
		(void*)0); // array buffer offset

	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices = 1 triangle
	glDisableVertexAttribArray(m_shader->GetAttrVertices());
}
