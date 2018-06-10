#pragma once
#include "Camera.h"
#include "Sprite.h"

enum SceneTransition {
	NOTHING,
	PREVIOUS,
	NEXT,
	TOMAIN
};

class Scene
{
public:
	Scene();
	~Scene();
	virtual void Update();
	virtual void Init();
	virtual void Deconstruct();
	virtual void Render();
	virtual void MoveCharacter(unsigned char KeyState[255]);

	Camera MyCamera;
	GLuint MyProgram;
	SceneTransition nextScene = NOTHING;
	bool b_pauseMenu = false;
};

