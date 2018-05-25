#include "MenuScene.h"

MenuScene::MenuScene()
{
	
}


MenuScene::~MenuScene()
{
}

void MenuScene::Init()
{
	// Creating program
	ShaderLoader shaderloader;
	MyProgram = shaderloader.CreateProgram("Shadar.vs", "Shadar.fs");
	Camera MyCamera;
	Background = Sprite("Sprites/Title.png", MyCamera, MyProgram);
	Sound::GetInstance()->Musicchannel->stop();
	Sound::GetInstance()->audioMgr->playSound(Sound::GetInstance()->menuTheme , 0, false, &Sound::GetInstance()->Musicchannel);


}

void MenuScene::w()
{
	GameManager::GetInstance()->SwitchScene(1);
}

void MenuScene::s()
{
	exit(0);
}

void MenuScene::Update()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 0.0, 0.0, 1.0); // clear red

	glUseProgram(MyProgram);
	Background.render();
}
