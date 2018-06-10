#pragma once
#include "Entity.h"

class Player :
	public Entity
{
public:
	Player();
	Player(Camera * _Camera, GLuint _Shader);
	~Player();
	void vertical(bool _direction);
	void horizontal(bool _direction);
	void Update();
	void Render();
	void SetRotation(glm::vec3 _rotation);
private:
	float speed = 0.05f;
	Model * PlayerModel;
	int i_Rotation;
};

