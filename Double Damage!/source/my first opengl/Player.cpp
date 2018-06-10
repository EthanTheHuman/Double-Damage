#include "Player.h"



Player::Player()
{
}

Player::Player(Camera * _Camera, GLuint _Shader)
{
	PlayerModel = new Model("Models/h2f2obj/f.obj", _Camera, _Shader);
	PlayerModel->SetScale({ 0.2f, 0.2f, 0.2f });
}

Player::~Player()
{
	delete PlayerModel;
}

void Player::vertical(bool _direction)
{
	if (_direction)
	{
		z += speed;
	}
	else if (!_direction)
	{
		z -= speed;
	}
}

void Player::horizontal(bool _direction)
{
	if (!_direction)
	{
		x += speed;
	}
	else if (_direction)
	{
		x -= speed;
	}
}

void Player::Update()
{
}

void Player::Render()
{
	PlayerModel->SetTranslation({ x, y, z });
	PlayerModel->Render();
}

void Player::SetRotation(glm::vec3 _rotation)
{
	PlayerModel->SetRotation(_rotation);
}
