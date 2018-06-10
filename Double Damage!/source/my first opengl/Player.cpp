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
}

void Player::vertical(bool _direction)
{
	if (_direction)
	{
		m_z += speed;
	}
	else if (!_direction)
	{
		m_z -= speed;
	}
}

void Player::horizontal(bool _direction)
{
	if (!_direction)
	{
		m_x += speed;
	}
	else if (_direction)
	{
		m_x -= speed;
	}
}

void Player::Update()
{
}

void Player::Render()
{
	PlayerModel->SetTranslation({ m_x, m_y, m_z });
	PlayerModel->Render();
}

void Player::SetRotation(glm::vec3 _rotation)
{
	PlayerModel->SetRotation(_rotation);
}
