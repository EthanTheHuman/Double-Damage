#pragma once
#include "Camera.h"
#include "Sprite.h"

class Scene
{
public:
	Scene();
	~Scene();
	virtual void Update();
	virtual void Init();
	virtual void Render();
	virtual void MoveCharacter(unsigned char KeyState[255]);

	Camera MyCamera;
	GLuint MyProgram;
};

