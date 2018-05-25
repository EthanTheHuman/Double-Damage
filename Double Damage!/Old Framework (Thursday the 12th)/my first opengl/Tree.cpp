#include "Tree.h"



Tree::Tree()
{
}

Tree::Tree(int _x, int _y, Camera _camera, GLuint _program)
{
	m_Sprite = Sprite("Sprites/Tree.png", _camera, _program);
	m_Sprite.SetScale({ 0.2f, 0.2f, 1.0f });
	ID = 3;
}


Tree::~Tree()
{
}
