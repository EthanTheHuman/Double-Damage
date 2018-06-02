#include "Scene.h"
#include "Sound.h"



Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::Update()
{
}

void Scene::Init()
{
}

//Updated Move Function
void Scene::MoveCharacter(unsigned char KeyState[255])
{
	if (KeyState[(unsigned char)'w'] == INPUT_HOLD) { }
	if (KeyState[(unsigned char)'s'] == INPUT_HOLD) { }
	if (KeyState[(unsigned char)'a'] == INPUT_HOLD) { }
	if (KeyState[(unsigned char)'d'] == INPUT_HOLD) { }
}
