#include "GameManager.h"
#include "Level1.h"

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

Scene* GameManager::CurrentSceneClass()
{
	return pScenes[CurrentScene];
}

GameManager::GameManager()
{
	pScenes.push_back(new Level1);
}


GameManager::~GameManager()
{
}
