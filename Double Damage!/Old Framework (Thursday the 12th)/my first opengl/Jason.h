#pragma once
#include "Entity.h"
class Jason :
	public Entity
{
public:
	Jason();
	Jason(int _x, int _y, Camera _camera, GLuint _program);
	~Jason();

	void up();
	void down();
	void left();
	void right();

	Sprite UpSprite;
	Sprite DownSprite;
	Sprite LeftSprite;
	Sprite RightSprite;
};

