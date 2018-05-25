#pragma once
#include <iostream>
#include "ShaderLoader.h"
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include "Dependencies\soil\SOIL.h"
#include "Dependencies\glm\glm.hpp"
#include "Dependencies\glm\gtc\matrix_transform.hpp"
#include "Dependencies\glm\gtc\type_ptr.hpp"
#include "Camera.h"

class Model
{
public:
	Model();
	Model(Camera * _Camera, GLuint _Program);
	~Model();
	void Render();
	void SetProgram(GLuint _Program);

private:
	GLuint m_Program;
	Camera * m_pCamera;

	//Matrices
	glm::mat4 m_TranslationMatrix = glm::mat4();
	glm::mat4 m_RotationMatrix = glm::mat4();
	glm::mat4 m_ScaleMatrix = glm::mat4();
	glm::mat4 m_ModelMatrix = glm::mat4();
	glm::mat4 m_MVPMatrix = glm::mat4();

	//Other Stuff
	GLuint vbo;
	GLuint vao;
	GLuint ebo;
	GLuint TempTexture;
};

