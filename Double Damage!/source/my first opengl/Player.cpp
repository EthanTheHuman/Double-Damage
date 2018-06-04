#include "Player.h"



Player::Player()
{
}

Player::Player(Camera * _Camera, GLuint _Shader)
{
	PlayerModel = new Model("Models/h2f2/f.obj", _Camera, _Shader);
	PlayerModel->SetScale({ 0.2f, 0.2f, 0.2f });
}


Player::~Player()
{
}

void Player::render()
{
	PlayerModel->Render();
}
