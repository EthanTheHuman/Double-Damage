#include "GameOverScene.h"



GameOverScene::GameOverScene()
{
}


GameOverScene::~GameOverScene()
{
}

void GameOverScene::Init()
{
	// Creating program
	ShaderLoader shaderloader;
	MyProgram = shaderloader.CreateProgram("Shadar.vs", "Shadar.fs");
	Camera MyCamera;
	Background = Sprite("Sprites/GameOver.png", MyCamera, MyProgram);
	Sound::GetInstance()->Musicchannel->stop();

}

void GameOverScene::w()
{
	GameManager::GetInstance()->SwitchScene(0);
}

void GameOverScene::s()
{
	exit(0);
}

void GameOverScene::Update()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 0.0, 0.0, 1.0); // clear red

	glUseProgram(MyProgram);
	Background.render();
}