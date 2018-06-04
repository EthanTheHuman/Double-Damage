#pragma once
#include "Sprite.h"

class Entity
{
public:
	Entity();
	Entity(int _x, int _y);
	~Entity();

public:
	int m_x;
	int m_y;
	Sprite m_Sprite;
	int ID;
};

