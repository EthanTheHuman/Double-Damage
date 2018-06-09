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

private:
	float speed = 0.05f;
	Model * PlayerModel;
	Sprite * PlayerSprite;
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
	int i_Rotation;
};

