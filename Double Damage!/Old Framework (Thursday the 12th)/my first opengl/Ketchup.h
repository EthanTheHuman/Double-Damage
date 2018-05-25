#pragma once
#include "Entity.h"
class Ketchup :
	public Entity
{
public:
	Ketchup();
	Ketchup(int _x, int _y, Camera _camera, GLuint _program);
	~Ketchup();
};

