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
	virtual void w();
	virtual void s();
	virtual void a();
	virtual void d();

	Camera MyCamera;
	GLuint MyProgram;
};

