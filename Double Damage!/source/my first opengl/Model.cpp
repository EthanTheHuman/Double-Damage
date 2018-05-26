#include "Model.h"

Model::Model()
{

}

Model::Model(char * _filename, Camera * _Camera, GLuint _Program)
{

	SetProgram(_Program);
	glUseProgram(_Program);
	m_Camera = _Camera;


	GLfloat verticesPyramid[] = {
		// Positions // Colors // Tex Coords
		-1.0f, 0.0f, -1.0f,		1.0f, 1.0f, 0.0f,	0.0f, 1.0f, // 0	// Base
		 1.0f, 0.0f, -1.0f,		1.0f, 0.0f, 0.0f,	1.0f, 1.0f, // 1
		 1.0f, 0.0f,  1.0f,		1.0f, 0.0f, 0.0f,	1.0f, 1.0f, // 2
		-1.0f, 0.0f,  1.0f,		0.0f, 0.0f, 1.0f,	0.0f, 0.0f,	// 3
		-1.0f, 0.0f, -1.0f,		1.0f, 1.0f, 0.0f,	0.0f, 1.0f,	// 4	// Side 1
		-1.0f, 0.0f,  1.0f,		0.0f, 0.0f, 1.0f,	1.0f, 1.0f,	// 5
		-1.0f, 0.0f,  1.0f,		0.0f, 0.0f, 1.0f,	0.0f, 1.0f,	// 6	// Side 2
		 1.0f, 0.0f,  1.0f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,	// 7
		 1.0f, 0.0f,  1.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,	// 8	// Side 3
		 1.0f, 0.0f, -1.0f,		1.0f, 0.0f, 0.0f,	1.0f, 1.0f,	// 9
		 1.0f, 0.0f, -1.0f,		1.0f, 0.0f, 0.0f,	0.0f, 1.0f,	// 10	// Side 4
		-1.0f, 0.0f, -1.0f,		1.0f, 1.0f, 0.0f,	1.0f, 1.0f,	// 11

		 0.0f, 1.0f, 0.0f,		0.0f, 1.0f, 1.0f,	0.5f, 0.0f,	// 12	// Top Point
	};

	GLuint indicesPyramid[] = {
		4, 12, 5,	// Side 1
		6, 12, 7,	// Side 2
		8, 12, 9,	// Side 3
		10, 12, 11,	// Side 4

		3, 2, 1,	// Bottom Triangle 1
		3, 1, 0		// Bottom Triangle 2
	};

	// Vertex Array Object
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// Vertex Buffer Object
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData
	(
		GL_ARRAY_BUFFER,
		sizeof(verticesPyramid),
		verticesPyramid,
		GL_STATIC_DRAW
	);

	// Vertex Array Object Again
	glVertexAttribPointer
	(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		8 * sizeof(GLfloat),
		(GLvoid*)0
	);

	glEnableVertexAttribArray(0);

	glVertexAttribPointer
	(
		1,
		3,
		GL_FLOAT,
		GL_FALSE,
		8 * sizeof(GLfloat),
		(GLvoid*)(3 * sizeof(GLfloat))
	);

	glEnableVertexAttribArray(1);

	glVertexAttribPointer
	(
		2,
		2,
		GL_FLOAT,
		GL_FALSE,
		8 * sizeof(GLfloat),
		(GLvoid*)(6 * sizeof(GLfloat))
	);

	glEnableVertexAttribArray(2);

	// Element array buffer
	glGenBuffers(1, &ebo);	// Add "GLuint ebo" to global variables
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

	glBufferData
	(
		GL_ELEMENT_ARRAY_BUFFER,
		sizeof(indicesPyramid),
		indicesPyramid,
		GL_STATIC_DRAW
	);

	//------------------------------------------------------------------------------------------------------------------------------------------
	glGenTextures(1, &TempTexture);
	glBindTexture(GL_TEXTURE_2D, TempTexture);

	// Loading texture
	unsigned char* image = SOIL_load_image
	(
		_filename,			// File path/name
		&width,				// Output for image width
		&height,			// Output for number of channels
		0,					// Number of channels
		SOIL_LOAD_RGBA		// Load RGB values only
	);

	glTexImage2D
	(
		GL_TEXTURE_2D,		// Type of texture
		0,					// Mipmap level, 0 for base
		GL_RGBA,				// Number of color components in texture
		width,				// Width of texture
		height,				// Height of texture
		0,					// Must be 0
		GL_RGBA,				// Format for the pixel data
		GL_UNSIGNED_BYTE,	// Data type of the pixel data
		image				// Pointer to image data in memory
	);

	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	GLfloat bordercolor[] = { 1.0f, 0.0f,0.0f,0.0f };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, bordercolor);

	glBindTexture(GL_TEXTURE_2D, 0);

	m_Texture = TempTexture;

	RefreshMVP();
	//------------------------------------------------------------------------------------------------------------------------------------------
}


Model::~Model()
{
}

void Model::Render()
{
	glUseProgram(m_Program);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	RefreshMVP();
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_Texture);
	glUniform1i(glGetUniformLocation(m_Program, "SpriteTex"), 0);
	glBindVertexArray(vao);			// Bind VAO
	glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
	//	glBindVertexArray(0);			// Unbind VAO
}

void Model::RefreshMVP()
{
	m_MVPMatrix = glm::mat4();
	//Projection * view * model
	m_MVPMatrix = ((m_Camera->GetProjectionMatrix()) * (m_Camera->GetViewMatrix()) * (m_ModelMatrix));
	//m_MVPMatrix = glm::mat4();
	GLint MVPLoc = glGetUniformLocation(m_Program, "MVP");
	glUniformMatrix4fv(MVPLoc, 1, GL_FALSE, glm::value_ptr(m_MVPMatrix));
}

void Model::RefreshModelMatrix()
{
	m_ModelMatrix = m_TranslationMatrix * m_RotationMatrix * m_ScaleMatrix;
}

void Model::SetTranslation(glm::vec3 _Translation)
{
	m_TranslationMatrix = glm::translate(glm::mat4(), _Translation);
	RefreshModelMatrix();
	RefreshMVP();
}

void Model::SetRotation(glm::vec3 _Rotation)
{
	m_RotationMatrix = glm::rotate(glm::mat4(), glm::radians(_Rotation.x), glm::vec3(1, 0, 0));
	m_RotationMatrix = glm::rotate(glm::mat4(), glm::radians(_Rotation.y), glm::vec3(0, 1, 0));
	m_RotationMatrix = glm::rotate(glm::mat4(), glm::radians(_Rotation.z), glm::vec3(0, 0, 1));
	RefreshModelMatrix();
	RefreshMVP();
}

void Model::SetScale(glm::vec3 _Scale)
{
	// Scaling while retaining aspect ratio
	m_ScaleMatrix = glm::scale(glm::mat4(), _Scale);
	RefreshModelMatrix();
	RefreshMVP();
}

void Model::SetProgram(GLuint _Program)
{
	m_Program = _Program;
}
