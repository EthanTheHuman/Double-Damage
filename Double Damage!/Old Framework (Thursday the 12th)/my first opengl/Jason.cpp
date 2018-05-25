#include "Jason.h"



Jason::Jason()
{
}

Jason::Jason(int _x, int _y, Camera _camera, GLuint _program)
{
	m_Sprite = Sprite("Sprites/Jason/Down.png", _camera, _program);
	m_Sprite.SetScale({ 0.2f, 0.2f, 1.0f });
	ID = 1;
	UpSprite = Sprite("Sprites/Jason/Up.png", _camera, _program);
	UpSprite.SetScale({ 0.2f, 0.2f, 1.0f });
	DownSprite = Sprite("Sprites/Jason/Down.png", _camera, _program);
	DownSprite.SetScale({ 0.2f, 0.2f, 1.0f });
	LeftSprite = Sprite("Sprites/Jason/Left.png", _camera, _program);
	LeftSprite.SetScale({ 0.2f, 0.2f, 1.0f });
	RightSprite = Sprite("Sprites/Jason/Right.png", _camera, _program);
	RightSprite.SetScale({ 0.2f, 0.2f, 1.0f });
}


Jason::~Jason()
{
}

void Jason::up()
{
	m_Sprite = UpSprite;
}

void Jason::down()
{
	m_Sprite = DownSprite;
}

void Jason::left()
{
	m_Sprite = LeftSprite;
}

void Jason::right()
{
	m_Sprite = RightSprite;
}
