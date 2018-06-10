#include "GameManager.h"
#include "Level1.h"
#include "MainMenu.h"

GameManager* GameManager::m_Manager;

GameManager * GameManager::GetInstance()
{
	if (!m_Manager)
	{
		m_Manager = new GameManager();
	}
	return m_Manager;
}

void GameManager::DestroyInstance()
{
	if (m_Manager)
	{
		delete m_Manager;
	}
	m_Manager = nullptr;
}

void GameManager::SwitchScene(int _Placement)
{
	CurrentScene = _Placement;
	pScenes[CurrentScene]->Init();
}

void GameManager::render()
{
	pScenes[CurrentScene]->Render();
}

void GameManager::update()
{
	if (pScenes[CurrentScene]->b_pauseMenu == false) {
		pScenes[CurrentScene]->Update();
	}
	if (pScenes[CurrentScene]->nextScene == true) {
		delete pScenes[CurrentScene];
		CurrentScene++;
		pScenes[CurrentScene]->Init();
	}
}

Scene* GameManager::CurrentSceneClass()
{
	return pScenes[CurrentScene];
}

GameManager::GameManager()
{
	MainMenu* newMainMenu = new MainMenu();
	newMainMenu->Init();
	pScenes.push_back(newMainMenu);
	Level1* newMenuScene = new Level1();
	pScenes.push_back(newMenuScene);
}


GameManager::~GameManager()
{
}
