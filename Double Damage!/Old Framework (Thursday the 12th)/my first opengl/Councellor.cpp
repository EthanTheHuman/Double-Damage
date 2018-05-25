#include "Councellor.h"



Councellor::Councellor()
{
}

Councellor::Councellor(int _x, int _y, Camera _camera, GLuint _program)
{
	m_Sprite = Sprite("Sprites/Child.png", _camera, _program);
	m_Sprite.SetScale({ 0.2f, 0.2f, 1.0f });
	ID = 2;
}


Councellor::~Councellor()
{
}
