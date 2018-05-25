#pragma once
#include "Entity.h"
class Councellor :
	public Entity
{
public:
	Councellor();
	Councellor::Councellor(int _x, int _y, Camera _camera, GLuint _program);
	~Councellor();
};

