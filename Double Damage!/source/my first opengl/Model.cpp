#include "Model.h"

Model::Model()
{

}

Model::Model(Camera * _Camera, GLuint _Program)
{

	SetProgram(_Program);
	glUseProgram(_Program);
	m_pCamera = _Camera;


	GLfloat verticesPyramid[] = {
		// Positions // Colors // Tex Coords
		-1.0f, 0.0f, -1.0f,		1.0f, 1.0f, 0.0f,	0.0f, 1.0f, // 0
		 1.0f, 0.0f, -1.0f,		1.0f, 0.0f, 0.0f,	1.0f, 1.0f, // 1
		 1.0f, 0.0f, 1.0f,		0.0f, 1.0f, 0.0f,	1.0f, 0.0f, // 2
		-1.0f, 0.0f, 1.0f,		0.0f, 0.0f, 1.0f,	0.0f, 0.0f, // 3
		 0.0f, 1.0f, 0.0f,		0.0f, 1.0f, 1.0f,	0.5f, 0.0f // 4 Top Point
	};

	GLuint indicesPyramid[] = {
		0, 4, 3,	// Side 1
		3, 4, 2,	// Side 2
		2, 4, 1,	// Side 3
		1, 4, 0,	// Side 4

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

	
	m_MVPMatrix = ((m_pCamera->GetProjectionMatrix()) * (m_pCamera->GetViewMatrix()) * (m_ModelMatrix));
	GLint MVPLoc = glGetUniformLocation(m_Program, "MVP");
	glUniformMatrix4fv(MVPLoc, 1, GL_FALSE, glm::value_ptr(m_MVPMatrix));

}


Model::~Model()
{
}

void Model::Render()
{
	m_MVPMatrix = ((m_pCamera->GetProjectionMatrix()) * (m_pCamera->GetViewMatrix()) * (m_ModelMatrix));
	GLint MVPLoc = glGetUniformLocation(m_Program, "MVP");
	glUniformMatrix4fv(MVPLoc, 1, GL_FALSE, glm::value_ptr(m_MVPMatrix));
	glUseProgram(m_Program);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glActiveTexture(GL_TEXTURE0);
	glUniform1i(glGetUniformLocation(m_Program, "SpriteTex"), 0);
	glBindVertexArray(vao);			// Bind VAO
	glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);			// Unbind VAO
}

void Model::SetProgram(GLuint _Program)
{
	m_Program = _Program;
}
