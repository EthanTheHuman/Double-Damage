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
	Model(char * _filename, Camera * _Camera, GLuint _Program);
	~Model();

	//Simple
	void Render();

	//Refresh Matrices
	void RefreshMVP();
	void RefreshModelMatrix();

	//Translation
	void SetTranslation(glm::vec3 _Translation);

	//Rotation
	void SetRotation(glm::vec3 _Rotation);

	//Scale
	void SetScale(glm::vec3 _Scale);
	
	void SetProgram(GLuint _Program);

private:

	//Texture
	GLuint m_Texture;
	int width = 200;
	int height = 200;

	//Matrices
	glm::mat4 m_TranslationMatrix = glm::mat4();
	glm::mat4 m_RotationMatrix = glm::mat4();
	glm::mat4 m_ScaleMatrix = glm::mat4();
	glm::mat4 m_ModelMatrix = glm::mat4();
	glm::mat4 m_MVPMatrix = glm::mat4();

	//Camera
	Camera * m_Camera;

	//Other Stuff
	GLuint vbo;
	GLuint vao;
	GLuint ebo;
	GLuint m_Program;
	GLuint TempTexture;
	ShaderLoader shaderloader;
};

