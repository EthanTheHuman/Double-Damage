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

void UFO::Update()
{
}

void UFO::Render()
{
	UFOModel->SetTranslation({ x, y, z });
	UFOModel->Render();
}
