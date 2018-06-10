#pragma once
#include "Entity.h"
#include <cmath>
class UFO :
	public Entity
{
public:
	UFO();
	UFO(Camera * _Camera, GLuint _Shader);
	~UFO();
	void Update(glm::vec3);
	void Render();
	void setpos(glm::vec2);
private:
	float speed = 0.02f;
	Model * UFOModel;
	float m_y = -0.1f;
};