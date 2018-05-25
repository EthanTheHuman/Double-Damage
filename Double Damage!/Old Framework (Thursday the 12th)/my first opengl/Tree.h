#pragma once
#include "Entity.h"
class Tree :
	public Entity
{
public:
	Tree();
	Tree(int _x, int _y, Camera _camera, GLuint _program);
	~Tree();
};

