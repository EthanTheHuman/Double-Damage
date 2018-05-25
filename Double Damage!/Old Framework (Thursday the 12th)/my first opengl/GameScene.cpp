#include <iostream>
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include "Dependencies\soil\SOIL.h"
#include "Dependencies\glm\glm.hpp"
#include "Dependencies\glm\gtc\matrix_transform.hpp"
#include "Dependencies\glm\gtc\type_ptr.hpp"
#include <iterator>
#include <map>

#include "Camera.h"
#include "GameManager.h"
#include "GameScene.h"
#include "Sound.h"
#include "Sprite.h"
#include "Utils.h"
#include "ShaderLoader.h"

// Namespace
using namespace std;

// Initialise stuff
GLuint MyProgram;
int score = 0;

GameScene::GameScene()
{
	
}



GameScene::~GameScene()
{
}

void GameScene::Init()
{
	score = 0;

	// Creating program
	ShaderLoader shaderloader;
	MyProgram = shaderloader.CreateProgram("Shadar.vs", "Shadar.fs");
	Camera MyCamera;
	Sound::GetInstance()->Musicchannel->stop();
	Sound::GetInstance()->audioMgr->playSound(Sound::GetInstance()->bgmTheme, 0, false, &Sound::GetInstance()->Musicchannel);

	//Initialise an empty game board
	GameBoard.clear();
	Entity* TempEntity = new Entity;
	for (int i = 0; i < 10; i++)
	{
		std::vector<Entity*> TempVector;
		for (int j = 0; j < 10; j++)
		{
			TempEntity = new EmptyEntity;
			TempVector.push_back(TempEntity);
		}
		GameBoard.push_back(TempVector);
	}

	//Do the same for the blood board
	BloodBoard.clear();
	for (int i = 0; i < 10; i++)
	{
		std::vector<Entity*> TempVector;
		for (int j = 0; j < 10; j++)
		{
			TempEntity = new EmptyEntity;
			TempVector.push_back(TempEntity);
		}
		BloodBoard.push_back(TempVector);
	}

	//Pre-determined entities
	m_JasonLocation = { 4,1 };

	GameBoard[4][1] = new Jason(m_JasonLocation.x, m_JasonLocation.y, MyCamera, MyProgram);
	GameBoard[4][0] = new Councellor(4, 0, MyCamera, MyProgram);
	GameBoard[1][4] = new Councellor(1, 4, MyCamera, MyProgram);
	GameBoard[0][0] = new Councellor(0, 0, MyCamera, MyProgram);
	//GameBoard[4][2] = new Councellor(0, 0, MyCamera, MyProgram);
	GameBoard[1][0] = new Tree(1, 0, MyCamera, MyProgram);
	GameBoard[2][0] = new Tree(2, 0, MyCamera, MyProgram);
	GameBoard[3][0] = new Tree(3, 0, MyCamera, MyProgram);
	GameBoard[3][1] = new Tree(3, 1, MyCamera, MyProgram);
	GameBoard[3][2] = new Tree(3, 2, MyCamera, MyProgram);
	GameBoard[1][2] = new Tree(1, 2, MyCamera, MyProgram);
	GameBoard[0][2] = new Tree(0, 2, MyCamera, MyProgram);
	GameBoard[2][4] = new Tree(2, 4, MyCamera, MyProgram);
	GameBoard[3][4] = new Tree(3, 4, MyCamera, MyProgram);
	GameBoard[4][4] = new Tree(4, 4, MyCamera, MyProgram);


	Background = Sprite("Sprites/Ground.png", MyCamera, MyProgram);
}

void GameScene::Update()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 0.0, 0.0, 1.0); // clear red

	glUseProgram(MyProgram);

	Background.render();
	//GameBoard[2][2]->m_Sprite.SetTranslation({ 1, 1, 0 });
	//GameBoard[2][2]->m_Sprite.SetScale({ 5, 5, 0 });
	//GameBoard[2][2]->m_Sprite.SetRotation({ 0, 0, 90 });
	//GameBoard[2][2]->m_Sprite.render();

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (BloodBoard[i][j]->ID == 2)
			{
				BloodBoard[i][j]->m_Sprite.SetTranslation({ (-1.2 + (0.4*(i + 1))), (1.2 - (0.4*(j + 1))), 0 });
				BloodBoard[i][j]->m_Sprite.render();
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if ((GameBoard[i][j]->ID == 1) || (GameBoard[i][j]->ID == 2) || (GameBoard[i][j]->ID == 3))
			{
				GameBoard[i][j]->m_Sprite.SetTranslation({ (-1.2 + (0.4*(i+1))), (1.2 - (0.4*(j + 1))), 0 });
				GameBoard[i][j]->m_Sprite.render();
			}
		}
	}

	if (score == 3)
	{
		GameManager::GetInstance()->SwitchScene(2);
	}
}

void GameScene::w()
{
	if (m_JasonLocation.y > 0)
	{
		if (GameBoard[m_JasonLocation.x][m_JasonLocation.y - 1]->ID != 3)
		{
			GameBoard[m_JasonLocation.x][m_JasonLocation.y] = new EmptyEntity;
			m_JasonLocation.y--;
			if (GameBoard[m_JasonLocation.x][m_JasonLocation.y]->ID == 2)
			{
				Sound::GetInstance()->audioMgr->playSound(Sound::GetInstance()->fxSplat, 0, false, &Sound::GetInstance()->fxchannel);
				BloodBoard[m_JasonLocation.x][m_JasonLocation.y] = new Ketchup(m_JasonLocation.x, m_JasonLocation.y, MyCamera, MyProgram);
				score++;
			}
			Jason* TempJason = new Jason(m_JasonLocation.x, m_JasonLocation.y, MyCamera, MyProgram);
			TempJason->up();
			GameBoard[m_JasonLocation.x][m_JasonLocation.y] = TempJason;
		}
	}
}

void GameScene::s()
{
	if (m_JasonLocation.y < 4)
	{
		if (GameBoard[m_JasonLocation.x][m_JasonLocation.y + 1]->ID != 3)
		{
			GameBoard[m_JasonLocation.x][m_JasonLocation.y] = new EmptyEntity;
			m_JasonLocation.y++;
			if (GameBoard[m_JasonLocation.x][m_JasonLocation.y]->ID == 2)
			{
				Sound::GetInstance()->audioMgr->playSound(Sound::GetInstance()->fxSplat, 0, false, &Sound::GetInstance()->fxchannel);
				BloodBoard[m_JasonLocation.x][m_JasonLocation.y] = new Ketchup(m_JasonLocation.x, m_JasonLocation.y, MyCamera, MyProgram);
				score++;
			}
			Jason* TempJason = new Jason(m_JasonLocation.x, m_JasonLocation.y, MyCamera, MyProgram);
			TempJason->down();
			GameBoard[m_JasonLocation.x][m_JasonLocation.y] = TempJason;
		}
	}
}

void GameScene::a()
{
	if (m_JasonLocation.x > 0)
	{
		if (GameBoard[m_JasonLocation.x - 1][m_JasonLocation.y]->ID != 3)
		{
			GameBoard[m_JasonLocation.x][m_JasonLocation.y] = new EmptyEntity;
			m_JasonLocation.x--;
			if (GameBoard[m_JasonLocation.x][m_JasonLocation.y]->ID == 2)
			{
				Sound::GetInstance()->audioMgr->playSound(Sound::GetInstance()->fxSplat, 0, false, &Sound::GetInstance()->fxchannel);
				BloodBoard[m_JasonLocation.x][m_JasonLocation.y] = new Ketchup(m_JasonLocation.x, m_JasonLocation.y, MyCamera, MyProgram);
				score++;
			}
			Jason* TempJason = new Jason(m_JasonLocation.x, m_JasonLocation.y, MyCamera, MyProgram);
			TempJason->left();
			GameBoard[m_JasonLocation.x][m_JasonLocation.y] = TempJason;
		}
	}
}

void GameScene::d()
{

	if (m_JasonLocation.x < 4)
	{
		if (GameBoard[m_JasonLocation.x + 1][m_JasonLocation.y]->ID != 3)
		{
			GameBoard[m_JasonLocation.x][m_JasonLocation.y] = new EmptyEntity;
			m_JasonLocation.x++;
			if (GameBoard[m_JasonLocation.x][m_JasonLocation.y]->ID == 2)
			{
				Sound::GetInstance()->audioMgr->playSound(Sound::GetInstance()->fxSplat, 0, false, &Sound::GetInstance()->fxchannel);
				BloodBoard[m_JasonLocation.x][m_JasonLocation.y] = new Ketchup(m_JasonLocation.x, m_JasonLocation.y, MyCamera, MyProgram);
				score++;
			}
			Jason* TempJason = new Jason(m_JasonLocation.x, m_JasonLocation.y, MyCamera, MyProgram);
			TempJason->right();
			GameBoard[m_JasonLocation.x][m_JasonLocation.y] = TempJason;
		}
	}
}
