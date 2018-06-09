#pragma once
#include "Entity.h"
class UFO :
	public Entity
{
public:
	UFO();
	UFO(Camera * _Camera, GLuint _Shader);
	~UFO();
	void Update();
	void Render();
private:
	float speed = 0.05f;
	Model * UFOModel;
	float x = 0.0f;
	float y = -0.1f;
	float z = 0.0f;
};

