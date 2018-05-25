#include "GameManager.h"

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
	pScenes[CurrentScene]->Update();
}

Scene* GameManager::CurrentSceneClass()
{
	return pScenes[CurrentScene];
}

GameManager::GameManager()
{
	MenuScene* newMenuScene = new MenuScene();
	pScenes.push_back(newMenuScene);
	GameScene* newGameScene = new GameScene();
	pScenes.push_back(newGameScene);
	GameOverScene* newGameOverScene = new GameOverScene();
	pScenes.push_back(newGameOverScene);
}


GameManager::~GameManager()
{
}
