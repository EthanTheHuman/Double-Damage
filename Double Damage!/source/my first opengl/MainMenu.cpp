#include "MainMenu.h"


TextLabel * TempLabel;
MainMenu::MainMenu()
{
	MyCamera = new Camera(glm::vec3(0, 0, -3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	SpriteShader = shaderloader.CreateProgram("Shaders/Sprite.vs", "Shaders/Sprite.fs");
	ModelBasicShader = shaderloader.CreateProgram("Shaders/ModelBasic.vs", "Shaders/ModelBasic.fs");
	AmbientShader = shaderloader.CreateProgram("Shaders/Ambient.vs", "Shaders/Ambient.fs");
	TextShader = shaderloader.CreateProgram("Shaders/Text.vs", "Shaders/Text.fs");
	SkyboxShader = shaderloader.CreateProgram("Shaders/Cubemap.vs", "Shaders/Cubemap.fs");

	TempLabel = new TextLabel("Play", "fonts/arial.ttf", glm::vec2(100, 50));
	TempLabel->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
	mainMenu.push_back(TempLabel);

	TempLabel = new TextLabel("Controls", "fonts/arial.ttf", glm::vec2(300, 50));
	TempLabel->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
	mainMenu.push_back(TempLabel);

	TempLabel = new TextLabel("Exit", "fonts/arial.ttf", glm::vec2(600, 50));
	TempLabel->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
	mainMenu.push_back(TempLabel);

	TempLabel = new TextLabel("Solo", "fonts/arial.ttf", glm::vec2(100, 50));
	TempLabel->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
	playMenu.push_back(TempLabel);

	TempLabel = new TextLabel("Co op", "fonts/arial.ttf", glm::vec2(300, 50));
	TempLabel->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
	playMenu.push_back(TempLabel);

	TempLabel = new TextLabel("Back", "fonts/arial.ttf", glm::vec2(600, 50));
	TempLabel->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
	playMenu.push_back(TempLabel);

	_Player = new Player(MyCamera, AmbientShader);
	MySkybox = new CubeMap(MyCamera, SkyboxShader, "Space/bkg1_top.png", "Space/bkg1_bot.png", "Space/bkg1_right.png", "Space/bkg1_left.png", "Space/bkg1_front.png", "Space/bkg1_back.png");
	MenuUpdate();
}

void MainMenu::Render()
{
	MyCamera->Update();
	glFrontFace(GL_CCW);

	//Background
	MySkybox->Render();
	_Player->Render();
	if (menu == MAIN) {
		for (int i = 0; i < mainMenu.size(); i++) {
			mainMenu[i]->Render();
		}
	}
	else if (menu == PLAY) {
		for (int i = 0; i < playMenu.size(); i++) {
			playMenu[i]->Render();
		}
	}
	else if (menu == CONTROL) {

	}
}


void MainMenu::Update()
{
	float currentTime = glutGet(GLUT_ELAPSED_TIME);
	currentTime = currentTime * 0.00005f;

	GLfloat radius = 5.0f;
	GLfloat camX = sin(currentTime) * radius;
	GLfloat camZ = cos(currentTime) * radius;
	MyCamera->SetCameraPosition({ camX, 2.5, camZ });
}

MainMenu::~MainMenu()
{
}

void MainMenu::MoveCharacter(unsigned char KeyState[255]) {
	if (KeyState[(unsigned char)'a'] == INPUT_FIRST_PRESS)
	{
		if (menu != CONTROL) {
			if (selection == 0) {
				selection = 2;
				MenuUpdate();
			}
			else {
				selection--;
				MenuUpdate();
			}
		}
	}
	if (KeyState[(unsigned char)'d'] == INPUT_FIRST_PRESS)
	{
		if (menu != CONTROL) {
			if (selection == 2) {
				selection = 0;
				MenuUpdate();
			}
			else {
				selection++;
				MenuUpdate();
			}
		}
	}
	if (KeyState[(unsigned char)'e'] == INPUT_FIRST_PRESS)
	{
		if (menu == MAIN) {
			if (selection == 0) {
				menu = PLAY;
				MenuUpdate();
			}
			else if (selection == 1) {
				menu = CONTROL;
				MenuUpdate();
			}
			else if (selection == 2) {
				//exit
			}
		}
		else if (menu == PLAY) {
			if (selection == 0) {
				//play in singleplayer
				nextScene = true;
			}
			if (selection == 1) {
				//play in miltiplayer
			}
			if (selection == 2) {
				menu = MAIN;
				selection = 0;
				MenuUpdate();
			}
		}
	}
}

void MainMenu::MenuUpdate() {
	if (menu == MAIN) {
		for (int i = 0; i < mainMenu.size(); i++) {
			mainMenu[i]->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
		}
		mainMenu[selection]->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	}
	else if (menu == PLAY) {
		for (int i = 0; i < playMenu.size(); i++) {
			playMenu[i]->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
		}
		playMenu[selection]->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	}
}