#include "Mesh.h"
#include "Shader.h"
#include "OBJ_Loader.h"		//Include object loader

vector<Mesh> Mesh::Lights;
/*
* ASSIGNMENT 2
* RICHARD PEROCHO
* STUDENT ID: 991454906
*/
Mesh::Mesh()
{
	m_shader = nullptr;
	m_textureDiffuse = {};
	m_textureSpecular = {};
	m_vertexBuffer = 0;
	m_position = { 0, 0, 0 };
	m_rotation = { 0, 0, 0 };
	m_scale = { 1, 1, 1 };
	m_world = glm::mat4();
}

Mesh::~Mesh()
{
}

void Mesh::Cleanup()
{
	glDeleteBuffers(1, &m_vertexBuffer);
	m_textureDiffuse.Cleanup();
	m_textureSpecular.Cleanup();
}

string Mesh::Concat(string _s1, int _index, string _s2)
{
	string index = to_string(_index);
	return (_s1 + index + _s2);
}

void Mesh::Create(Shader* _shader, string _file)
{
	m_shader = _shader;

	objl::Loader Loader;	//Initialize Loader
	M_ASSERT(Loader.LoadFile(_file) == true, "Failed to load mesh.");	//Load .obj file

	for (unsigned int i = 0; i < Loader.LoadedMeshes.size(); i++)
	{
		objl::Mesh curMesh = Loader.LoadedMeshes[i];
		for (unsigned int j = 0; j < curMesh.Vertices.size(); j++)
		{
			m_vertexData.push_back(curMesh.Vertices[j].Position.X);
			m_vertexData.push_back(curMesh.Vertices[j].Position.Y);
			m_vertexData.push_back(curMesh.Vertices[j].Position.Z);
			m_vertexData.push_back(curMesh.Vertices[j].Normal.X);
			m_vertexData.push_back(curMesh.Vertices[j].Normal.Y);
			m_vertexData.push_back(curMesh.Vertices[j].Normal.Z);
			m_vertexData.push_back(curMesh.Vertices[j].TextureCoordinate.X);
			m_vertexData.push_back(curMesh.Vertices[j].TextureCoordinate.Y);
		}
	}


	// load diffuse texture from mtl file (if exists)
	string diffuseMapPath = Loader.LoadedMaterials[0].map_Kd;
	m_textureDiffuse = Texture();
	m_textureDiffuse.LoadTexture(diffuseMapPath);

	// load specular texture from mtl file (if exists)
	string specularMapPath = Loader.LoadedMaterials[0].map_Ks;
	m_textureSpecular = Texture();
	m_textureSpecular.LoadTexture(specularMapPath);

	glGenBuffers(1, &m_vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, m_vertexData.size() * sizeof(float), m_vertexData.data(), GL_STATIC_DRAW);

}

void Mesh::BindAttributes()
{
	// Binding buffer
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);

	// 1st attribute buffer : vertices
	glEnableVertexAttribArray(m_shader->GetAttrVertices());
	glVertexAttribPointer(m_shader->GetAttrVertices(), // The attribute we want to configure
		3,					// size
		GL_FLOAT,			// type
		GL_FALSE,			// normalized?
		8 * sizeof(float),	// stride (7 floats rep. xyzrgba per vertex definition)
		(void*)0);			// array buffer offset

	// 2nd attribute buffer : normals
	glEnableVertexAttribArray(m_shader->GetAttrNormals());
	glVertexAttribPointer(m_shader->GetAttrNormals(),
		3,								// size (3 components of colour value) RGB
		GL_FLOAT,						// type 
		GL_FALSE,						// normalized?
		8 * sizeof(float),				// stride (8 floats rep. per vertex definition)
		(void*)(3 * sizeof(float)));	// array buffer offset (after 3 float values is where the colour value begins)

	// 3rd attribute buffer : WVP
	glEnableVertexAttribArray(m_shader->GetAttrTexCoords());
	glVertexAttribPointer(m_shader->GetAttrTexCoords(),			//attribute we want to configure
		2,														//size
		GL_FLOAT,												//type
		GL_FALSE,												//normalized?
		8 * sizeof(float),										//stride (8 per vertex definition)
		(void*)(6 * sizeof(float)));							//array buffer offset


	//bind texture
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_textureDiffuse.GetTexture());
	glUniform1i(m_shader->GetSampler1(), 0);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, m_textureSpecular.GetTexture());
	glUniform1i(m_shader->GetSampler2(), 1);
}

void Mesh::CalculateTransform()
{
	m_world = glm::translate(glm::mat4(1.0f), m_position);
	m_world = glm::rotate(m_world, m_rotation.x, glm::vec3(1, 0, 0));
	m_world = glm::scale(m_world, m_scale);
}

void Mesh::SetShaderVariables(glm::mat4 _pv)
{
	m_shader->SetMat4("World", m_world);
	m_shader->SetMat4("WVP", _pv * m_world);
	m_shader->SetVec3("CameraPosition", m_cameraPosition);

	//light
	for (unsigned int i = 0; i < Lights.size(); i++)
	{
		m_shader->SetFloat(Concat("light[", i, "].constant").c_str(), 1.0f);
		m_shader->SetFloat(Concat("light[", i, "].linear").c_str(), 0.09f);
		m_shader->SetFloat(Concat("light[", i, "].quadratic").c_str(), 0.032f);

		m_shader->SetVec3(Concat("light[", i, "].ambientColor").c_str(), { 0.1f, 0.1f, 0.1f });	//light
		m_shader->SetVec3(Concat("light[", i, "].diffuseColor").c_str(), Lights[i].GetColor());	//colour
		m_shader->SetVec3(Concat("light[", i, "].specularColor").c_str(), { 1.0f, 1.0f, 1.0f });

		m_shader->SetVec3(Concat("light[", i, "].position").c_str(), Lights[i].GetPosition());	//light position
		m_shader->SetVec3(Concat("light[", i, "].direction").c_str(), glm::normalize(glm::vec3({ i * 0.1f, 0.0f, i * 0.1f }) - Lights[i].GetPosition()));
		m_shader->SetFloat(Concat("light[", i, "].coneAngle").c_str(), glm::radians(5.0f));
		m_shader->SetFloat(Concat("light[", i, "].falloff").c_str(), 100);
	}


	//material
	m_shader->SetFloat("material.specularStrength", 8);
	m_shader->SetTextureSampler("material.diffuseTexture", GL_TEXTURE0, 0, m_textureDiffuse.GetTexture());
	m_shader->SetTextureSampler("material.specularTexture", GL_TEXTURE1, 1, m_textureSpecular.GetTexture());
}

//void Mesh::Render(glm::mat4 _wvp)
void Mesh::Render(glm::mat4 _pv)
{
	glUseProgram(m_shader->GetProgramID()); // Use shader

	m_rotation.x += 0.003f;
	CalculateTransform();
	SetShaderVariables(_pv);
	BindAttributes();

	glDrawArrays(GL_TRIANGLES, 0, m_vertexData.size());

	glDisableVertexAttribArray(m_shader->GetAttrNormals());
	glDisableVertexAttribArray(m_shader->GetAttrVertices());
	glDisableVertexAttribArray(m_shader->GetAttrTexCoords());
}