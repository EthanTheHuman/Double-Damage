#pragma once
#include <vector>
#include "Jason.h"
#include "Councellor.h"
#include "Tree.h"
#include "Ketchup.h"
#include "EmptyEntity.h"
#include "Camera.h"
#include "Scene.h"
#include "TextLabel.h"

class GameScene :
	public Scene
{
public:
	GameScene();
	~GameScene();
	void Init();
	void Update();

	void w();
	void s();
	void a();
	void d();
	Camera MyCamera;

private:
	std::vector<std::vector<Entity*>> GameBoard;
	std::vector<std::vector<Entity*>> BloodBoard;
	Coords m_JasonLocation = { 0,0 };
	Sprite Background;
};

