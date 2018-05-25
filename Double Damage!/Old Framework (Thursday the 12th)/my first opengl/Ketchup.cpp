#include "Ketchup.h"



Ketchup::Ketchup()
{
}

Ketchup::Ketchup(int _x, int _y, Camera _camera, GLuint _program)
{
	m_Sprite = Sprite("Sprites/Ketchup.png", _camera, _program);
	m_Sprite.SetScale({ 0.2f, 0.2f, 1.0f });
	ID = 2;
}

Ketchup::~Ketchup()
{
}
