#pragma once
#include "Entity.h"
#include "Model.h"

class Player :
	public Entity
{
public:
	Player();
	Player(Camera * _Camera, GLuint _Shader);
	~Player();
	void render();
private:
	Model * PlayerModel;
};

