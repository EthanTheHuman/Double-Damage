#pragma once
#include "Scene.h"
#include "GameManager.h"
#include "dependencies\FMOD\fmod.hpp"
#include "Sound.h"

class MenuScene : public Scene
{
public:
	MenuScene();
	~MenuScene();
	void Init();
	void w();
	void s();
	void Update();
private:
	Sprite Background;
};

