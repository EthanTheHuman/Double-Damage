#include "Level1.h"

Level1::Level1()
{
	srand((unsigned)time(NULL));
}

Level1::~Level1()
{
}

void Level1::Init()
{
	MyCamera = new Camera(glm::vec3(0,5,-7), glm::vec3(0,0,0), glm::vec3(0,1,0));
	SpriteShader = shaderloader.CreateProgram("Shaders/Sprite.vs", "Shaders/Sprite.fs");
	ModelBasicShader = shaderloader.CreateProgram("Shaders/ModelBasic.vs", "Shaders/ModelBasic.fs");
	AmbientShader = shaderloader.CreateProgram("Shaders/Ambient.vs", "Shaders/Ambient.fs");
	TextShader = shaderloader.CreateProgram("Shaders/Text.vs", "Shaders/Text.fs");
	SkyboxShader = shaderloader.CreateProgram("Shaders/Cubemap.vs", "Shaders/Cubemap.fs");

	g_Score = new TextLabel("Score: ", "fonts/arial.ttf", glm::vec2(600, 50));

	TempLabel = new TextLabel("Resume", "fonts/arial.ttf", glm::vec2(100, 100));
	TempLabel->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
	pauseMenu.push_back(TempLabel);

	TempLabel = new TextLabel("Back To Main Menu", "fonts/arial.ttf", glm::vec2(100, 200));
	TempLabel->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
	pauseMenu.push_back(TempLabel);

	_Player = new Player(MyCamera, AmbientShader);


	for (int i = 0; i < 10; i++) {
		TempUFO = new UFO(MyCamera, AmbientShader);
		TempUFO->setpos(glm::vec2(-5 + rand() % 10, -5 + rand() % 10));
		UFOS.push_back(TempUFO);
	}

	MySkybox = new CubeMap(MyCamera, SkyboxShader, "Citadel/top.jpg", "Citadel/bottom.jpg", "Citadel/left.jpg", "Citadel/right.jpg", "Citadel/front.jpg", "Citadel/back.jpg");
}

void Level1::Deconstruct()
{
	delete MyCamera;
	for (int i = 0; i < pauseMenu.size(); i++) {
		delete pauseMenu[i];
	}
	pauseMenu.clear();
	delete _Player;
	for (int i = 0; i < UFOS.size(); i++) {
		delete UFOS[i];
	}
	UFOS.clear();
	delete MySkybox;
	delete g_Score;
	nextScene = NOTHING;
	b_pauseMenu = false;
}

void Level1::Render()
{
	MyCamera->Update();
	glFrontFace(GL_CCW);

	//Background
	MySkybox->Render();

	//Render 3D objects
	_Player->Render();
	for (int i = 0; i < UFOS.size(); i++) {
		UFOS[i]->Render();
	}

	if (b_pauseMenu == true) {
		for (int i = 0; i < pauseMenu.size(); i++) {
			pauseMenu[i]->Render();
		}
	}
	else
	{
		g_Score->Render();
	}
}

void Level1::Update()
{
	_Player->Update();
	for (int i = 0; i < UFOS.size(); i++) {
		UFOS[i]->Update();
	}
	string TempString = "Score: " + ToString(score);
	g_Score->SetText(TempString);

	for (int i = 0; i < UFOS.size(); i++) {
		if (IsColliding(_Player->GetPos(), UFOS[i]->GetPos(), 1.0f, 1.0f)) {
			delete UFOS[i];
			UFOS.erase(UFOS.begin() + i);
			score++;
		}
	}
}

void Level1::MoveCharacter(unsigned char KeyState[255])
{
	if (b_pauseMenu == true) {
		if (KeyState[(unsigned char)'s'] == INPUT_FIRST_PRESS)
		{
			if (selection == 0) {
				selection = 1;
				MenuUpdate();
			}
			else {
				selection--;
				MenuUpdate();
			}
		}
		if (KeyState[(unsigned char)'w'] == INPUT_FIRST_PRESS)
		{
			if (selection == 1) {
				selection = 0;
				MenuUpdate();
			}
			else {
				selection++;
				MenuUpdate();
			}
		}
		if (KeyState[(unsigned char)' '] == INPUT_FIRST_PRESS)
		{
			if (selection == 0) {
				b_pauseMenu = false;
				MenuUpdate();
			}
			else if (selection == 1) {
				nextScene = TOMAIN;
			}
		}
	}
	else {
		//Movement itself
		if (KeyState[(unsigned char)'w'] == INPUT_HOLD)
		{
			_Player->vertical(true);
		}
		if (KeyState[(unsigned char)'s'] == INPUT_HOLD)
		{
			_Player->vertical(false);
		}
		if (KeyState[(unsigned char)'a'] == INPUT_HOLD)
		{
			_Player->horizontal(false);
		}
		if (KeyState[(unsigned char)'d'] == INPUT_HOLD)
		{
			_Player->horizontal(true);
		}
		if (KeyState[(unsigned char)'\x1b'] == INPUT_FIRST_PRESS)
		{
			b_pauseMenu = true;
			MenuUpdate();
		}



		//Rotation

		//All 4
		if ((KeyState[(unsigned char)'w'] == INPUT_HOLD) && (KeyState[(unsigned char)'s'] == INPUT_HOLD) && (KeyState[(unsigned char)'a'] == INPUT_HOLD) && (KeyState[(unsigned char)'d'] == INPUT_HOLD))
		{
			//No rotation
		}

		//Trios
		else if ((KeyState[(unsigned char)'w'] == INPUT_HOLD) && (KeyState[(unsigned char)'s'] == INPUT_HOLD) && (KeyState[(unsigned char)'a'] == INPUT_HOLD))
		{
			_Player->SetRotation({ 0,90,0 });
		}
		else if ((KeyState[(unsigned char)'s'] == INPUT_HOLD) && (KeyState[(unsigned char)'a'] == INPUT_HOLD) && (KeyState[(unsigned char)'d'] == INPUT_HOLD))
		{
			_Player->SetRotation({ 0,180,0 });
		}
		else if ((KeyState[(unsigned char)'w'] == INPUT_HOLD) && (KeyState[(unsigned char)'a'] == INPUT_HOLD) && (KeyState[(unsigned char)'d'] == INPUT_HOLD))
		{
			_Player->SetRotation({ 0,0,0 });
		}
		else if ((KeyState[(unsigned char)'w'] == INPUT_HOLD) && (KeyState[(unsigned char)'s'] == INPUT_HOLD) && (KeyState[(unsigned char)'d'] == INPUT_HOLD))
		{
			_Player->SetRotation({ 0,270,0 });
		}

		//Opposites
		else if ((KeyState[(unsigned char)'w'] == INPUT_HOLD) && (KeyState[(unsigned char)'s'] == INPUT_HOLD))
		{
			//No rotation
		}
		else if ((KeyState[(unsigned char)'a'] == INPUT_HOLD) && (KeyState[(unsigned char)'d'] == INPUT_HOLD))
		{
			//No rotation
		}

		//Diagonals
		else if ((KeyState[(unsigned char)'w'] == INPUT_HOLD) && (KeyState[(unsigned char)'a'] == INPUT_HOLD))
		{
			_Player->SetRotation({ 0,45,0 });
		}
		else if ((KeyState[(unsigned char)'s'] == INPUT_HOLD) && (KeyState[(unsigned char)'a'] == INPUT_HOLD))
		{
			_Player->SetRotation({ 0,135,0 });
		}
		else if ((KeyState[(unsigned char)'s'] == INPUT_HOLD) && (KeyState[(unsigned char)'d'] == INPUT_HOLD))
		{
			_Player->SetRotation({ 0,225,0 });
		}
		else if ((KeyState[(unsigned char)'w'] == INPUT_HOLD) && (KeyState[(unsigned char)'d'] == INPUT_HOLD))
		{
			_Player->SetRotation({ 0,315,0 });
		}

		//Straights
		else if (KeyState[(unsigned char)'w'] == INPUT_HOLD)
		{
			_Player->SetRotation({ 0,0,0 });
		}
		else if (KeyState[(unsigned char)'s'] == INPUT_HOLD)
		{
			_Player->SetRotation({ 0,180,0 });
		}
		else if (KeyState[(unsigned char)'a'] == INPUT_HOLD)
		{
			_Player->SetRotation({ 0,90,0 });
		}
		else if (KeyState[(unsigned char)'d'] == INPUT_HOLD)
		{
			_Player->SetRotation({ 0,270,0 });
		}
	}
}

void Level1::MenuUpdate() {
	for (int i = 0; i < pauseMenu.size(); i++) {
		pauseMenu[i]->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
	}
	pauseMenu[selection]->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
}