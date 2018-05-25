#pragma once
#include "Scene.h"
#include "GameManager.h"
#include "dependencies\FMOD\fmod.hpp"
#include "Sound.h"

class GameOverScene :
	public Scene
{
public:
	GameOverScene();
	~GameOverScene();
	void Init();
	void w();
	void s();
	void Update();
private:
	Sprite Background;
};

