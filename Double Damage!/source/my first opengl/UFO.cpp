#include "UFO.h"



UFO::UFO()
{
}

UFO::UFO(Camera * _Camera, GLuint _Shader)
{
	UFOModel = new Model("Models/UFO/Low_poly_UFO.obj", _Camera, _Shader);
	UFOModel->SetScale({ 0.01f, 0.01f, 0.01f });
}


UFO::~UFO()
{
	delete UFOModel;
}


void UFO::Update(glm::vec3 C1)
{
	float distance = sqrt(pow(C1.x - m_x, 2) + pow(C1.z - m_z, 2));
	float directionX = (C1.x - m_x) / distance;
	float directionY = (C1.z - m_z) / distance;

	m_x += directionX * speed;
	m_z += directionY * speed;
}

void UFO::Render()
{
	UFOModel->SetTranslation({ m_x, m_y, m_z });
	UFOModel->Render();
}

void UFO::setpos(glm::vec2 pos)
{
	m_x = pos.x;
	m_z = pos.y;
}
