#include "Mesh.h"
#include "Shader.h"
#include "ColorUtils.h"

Mesh::Mesh() {
	m_shader = nullptr;
	m_texture = { };
	m_texture2 = { };
	m_vertexBuffer = 0;
	m_indexBuffer = 0;
	m_position = { 0, 0, 0 };
	m_rotation = { 0, 0, 0 };
}

Mesh::~Mesh() {

}

void Mesh::Cleanup() {
	glDeleteBuffers(1, &m_vertexBuffer);
	glDeleteBuffers(1, &m_indexBuffer);
	m_texture.Cleanup();
	m_texture2.Cleanup();
}

void Mesh::Create(Shader* _shader) {
	m_shader = _shader;
	
	m_texture = Texture();
	m_texture.LoadTexture("../Assets/Textures/Wood.jpg");
	m_texture2 = Texture();
	m_texture2.LoadTexture("../Assets/Textures/Emoji.jpg");

	/*
	1. get user inputted slider values for yuv scaling
	2. convert rgb to yuv 
	3. apply scaling to yuv 
	4. convert back to rgb
	5. apply to vertex data
	*/

	// 1. get user inputted slider values for yuv scaling

	glm::mat4x3 rgb = {
		{1.0f, 0.0f, 0.0f},
		{0.0f, 1.0f, 0.0f},
		{0.0f, 0.0f, 1.0f},
		{1.0f, 1.0f, 1.0f}
	};
	for (int i = 0; i < rgb.length(); i++) {
		// 2. convert rgb to yuv
		rgb[i] = ColorUtils::RGBtoYUV(rgb[i]);
		// 3. apply scaling to yuv 
		// 4. convert back to rgb
	}
	// 5. apply to vertex data
	m_vertexData = {
		/*   position   */     /*                     RGBA color                         */   /* texture coords */
		50.0f, 50.0f, 0.0f,    rgb[0][0], rgb[0][1], rgb[0][2],    1.0f, 1.0f, // top-right
		50.0f, -50.0f, 0.0f,   rgb[1][0], rgb[1][1], rgb[1][2],    1.0f, 0.0f, // bottom-right
		-50.0f, -50.0f, 0.0f,  rgb[2][0], rgb[2][1], rgb[2][2],    0.0f, 0.0f, // bottom-left
		-50.0f, 50.0f, 0.0f,   rgb[3][0], rgb[3][1], rgb[3][2],    0.0f, 1.0f  //top-left
	};
	
	glGenBuffers(1, &m_vertexBuffer); 
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, m_vertexData.size() * sizeof(float), m_vertexData.data(), GL_STATIC_DRAW);

	m_indexData = {
		2, 0, 3, 2, 1, 0
	};

	glGenBuffers(1, &m_indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indexData.size() * sizeof(GLubyte), m_indexData.data(), GL_STATIC_DRAW);
}

void Mesh::Render(glm::mat4 _wvp) {
	glUseProgram(m_shader->GetProgramID()); // Use our shader

	// 1st attribute buffer : vertices
	glEnableVertexAttribArray(m_shader->GetAttrVertices()); // vertext position data will be used in the rendering process
	glVertexAttribPointer(m_shader->GetAttrVertices(), 
		3,                 // size 
		GL_FLOAT,          // type 
		GL_FALSE,          // normalized 
		8 * sizeof(float), // stride (8 floats per vertex definition)
		(void*)0);         // array buffer offset

	// 2nd attribute buffer : colors
	glEnableVertexAttribArray(m_shader->GetAttrColors());
	glVertexAttribPointer(m_shader->GetAttrColors(),
		3,                 // size (3 vertices per primitive)
		GL_FLOAT,          // type
		GL_FALSE,          // normalized
		8 * sizeof(float), // stride
		(void*)(3 * sizeof(float))); // array buffer offset

	// 3rd attribute buffer : texCoords
	glEnableVertexAttribArray(m_shader->GetAttrTexCoords());
	glVertexAttribPointer(m_shader->GetAttrTexCoords(),
		2,                 // size
		GL_FLOAT,          // type
		GL_FALSE,          // normalized
		8 * sizeof(float), // stride (8 floats per vertex definition)
		(void*)(6 * sizeof(float))); // array buffer offset

	// 4th attribute : WVP
	m_rotation.y += 0.0f;
	glm::mat4 transform = glm::rotate(_wvp, m_rotation.y, glm::vec3(0, 1, 0));
	glUniformMatrix4fv(m_shader->GetAttrWVP(), 1, GL_FALSE, &transform[0][0]);

	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer); // bind the vertex buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBuffer); // bind the index buffer
	
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_texture.GetTexture()); // bind wood texture explicitly to texture unit 1
	glUniform1i(m_shader->GetSampler1(), 0);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, m_texture2.GetTexture()); // bind emoji texture explicitly to texture unit 2
	glUniform1i(m_shader->GetSampler2(), 1);
	
	glDrawElements(GL_TRIANGLES, m_indexData.size(), GL_UNSIGNED_BYTE, (void*)0);
	glDisableVertexAttribArray(m_shader->GetAttrColors());
	glDisableVertexAttribArray(m_shader->GetAttrVertices());
	glDisableVertexAttribArray(m_shader->GetAttrTexCoords());
}
