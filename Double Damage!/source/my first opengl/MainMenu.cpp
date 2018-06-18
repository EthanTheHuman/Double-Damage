#include "MainMenu.h"

MainMenu::MainMenu()
{
}

void MainMenu::Init()
{
	MyCamera = new Camera(glm::vec3(0, 0, -3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	SpriteShader = shaderloader.CreateProgram("Shaders/Sprite.vs", "Shaders/Sprite.fs");
	UISpriteShader = shaderloader.CreateProgram("Shaders/UISprite.vs", "Shaders/UISprite.fs");
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

	TempLabel = new TextLabel("Host", "fonts/arial.ttf", glm::vec2(100, 50));
	TempLabel->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
	coopMenu.push_back(TempLabel);

	TempLabel = new TextLabel("Join", "fonts/arial.ttf", glm::vec2(300, 50));
	TempLabel->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
	coopMenu.push_back(TempLabel);

	TempLabel = new TextLabel("Back", "fonts/arial.ttf", glm::vec2(600, 50));
	TempLabel->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
	coopMenu.push_back(TempLabel);

	//-------------------------------------------------------------------------------------------------------------

	TempLabel = new TextLabel("Back", "fonts/arial.ttf", glm::vec2(50, 550));
	TempLabel->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
	hostMenu.push_back(TempLabel);

	TempLabel = new TextLabel("Player Name", "fonts/arial.ttf", glm::vec2(50, 500));
	TempLabel->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
	hostMenu.push_back(TempLabel);

	TempLabel = new TextLabel("Player Name", "fonts/arial.ttf", glm::vec2(50, 450));
	TempLabel->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
	hostMenu.push_back(TempLabel);

	TempLabel = new TextLabel("Player Name", "fonts/arial.ttf", glm::vec2(50, 400));
	TempLabel->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
	hostMenu.push_back(TempLabel);

	TempLabel = new TextLabel("Player Name", "fonts/arial.ttf", glm::vec2(50, 350));
	TempLabel->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
	hostMenu.push_back(TempLabel);

	//-------------------------------------------------------------------------------------------------------------

	TempLabel = new TextLabel("Back", "fonts/arial.ttf", glm::vec2(50, 550));
	TempLabel->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
	joinMenu.push_back(TempLabel);

	TempLabel = new TextLabel("Empty Slot", "fonts/arial.ttf", glm::vec2(50, 500));
	TempLabel->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
	joinMenu.push_back(TempLabel);

	TempLabel = new TextLabel("Empty Slot", "fonts/arial.ttf", glm::vec2(50, 450));
	TempLabel->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
	joinMenu.push_back(TempLabel);

	TempLabel = new TextLabel("Empty Slot", "fonts/arial.ttf", glm::vec2(50, 400));
	TempLabel->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
	joinMenu.push_back(TempLabel);

	TempLabel = new TextLabel("Empty Slot", "fonts/arial.ttf", glm::vec2(50, 350));
	TempLabel->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
	joinMenu.push_back(TempLabel);

	TempLabel = new TextLabel("Empty Slot", "fonts/arial.ttf", glm::vec2(50, 300));
	TempLabel->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
	joinMenu.push_back(TempLabel);

	TempLabel = new TextLabel("Empty Slot", "fonts/arial.ttf", glm::vec2(50, 250));
	TempLabel->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
	joinMenu.push_back(TempLabel);

	TempLabel = new TextLabel("Empty Slot", "fonts/arial.ttf", glm::vec2(50, 200));
	TempLabel->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
	joinMenu.push_back(TempLabel);

	TempLabel = new TextLabel("Empty Slot", "fonts/arial.ttf", glm::vec2(50, 150));
	TempLabel->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
	joinMenu.push_back(TempLabel);

	TempLabel = new TextLabel("Empty Slot", "fonts/arial.ttf", glm::vec2(50, 100));
	TempLabel->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
	joinMenu.push_back(TempLabel);

	TempLabel = new TextLabel("Empty Slot", "fonts/arial.ttf", glm::vec2(50, 50));
	TempLabel->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
	joinMenu.push_back(TempLabel);

	//-------------------------------------------------------------------------------------------------------------

	Title = new UISprite("Textures/Cubemap/Title.png", MyCamera, UISpriteShader);
	Title->SetScale({ 0.3, 0.3, 0.3 });
	Title->SetTranslation({ 0, 0.5, 0 });

	Controls = new UISprite("Textures/Controls.png", MyCamera, UISpriteShader);
	Controls->SetScale({ 1, 1, 1 });
	Controls->SetTranslation({ 0, 0, 0 });

	_Player = new Player(MyCamera, AmbientShader);
	MySkybox = new CubeMap(MyCamera, SkyboxShader, "Space/bkg1_top.png", "Space/bkg1_bot.png", "Space/bkg1_right.png", "Space/bkg1_left.png", "Space/bkg1_front.png", "Space/bkg1_back.png");
	MenuUpdate();
}

void MainMenu::Deconstruct()
{
	delete MyCamera;
	for (int i = 0; i < mainMenu.size(); i++) {
		delete mainMenu[i];
	}
	mainMenu.clear();
	for (int i = 0; i < playMenu.size(); i++) {
		delete playMenu[i];
	}
	playMenu.clear();
	for (int i = 0; i < coopMenu.size(); i++) {
		delete coopMenu[i];
	}
	coopMenu.clear();
	delete _Player;
	delete MySkybox;
	nextScene = NOTHING;
	menu = MAIN;
	selection = 0;
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
		Title->render();
	}
	else if (menu == PLAY) {
		for (int i = 0; i < playMenu.size(); i++) {
			playMenu[i]->Render();
		}
	}
	else if (menu == COOP) {
		for (int i = 0; i < coopMenu.size(); i++) {
			coopMenu[i]->Render();
		}
	}
	else if (menu == CONTROL) {
		Controls->render();
	}
	else if (menu == HOST) {
		for (int i = 0; i < hostMenu.size(); i++) {
			hostMenu[i]->Render();
		}
	}
	else if (menu == JOIN) {
		for (int i = 0; i < joinMenu.size(); i++) {
			joinMenu[i]->Render();
		}
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
	if (KeyState[(unsigned char)' '] == INPUT_FIRST_PRESS)
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
				exit(0);
			}
		}
		else if (menu == PLAY) {
			if (selection == 0) {
				//play in singleplayer
				nextScene = NEXT;
			}
			else if (selection == 1) {
				//play in multiplayer
				menu = COOP;
				selection = 0;
				MenuUpdate();
			}
			else if (selection == 2) {
				menu = MAIN;
				selection = 0;
				MenuUpdate();
			}
		}
		else if (menu == COOP) {
			if (selection == 0) {
				//Host
				menu = HOST;
				Networkmode = 1;
			}
			else if (selection == 1) {
				//Join
				menu = JOIN;
				selection = 0;
				Networkmode = 2;
			}
			else if (selection == 2) {
				menu = PLAY;
				selection = 1;
				MenuUpdate();
			}
		}
		else if (menu == HOST)
		{
			if (selection == 0) {
				menu = PLAY;
				Networkmode = 0;
				MenuUpdate();
			}
		}
		else if (menu == JOIN)
		{
			if (selection == 0) {
				menu = PLAY;
				Networkmode = 0;
				MenuUpdate();
			}
		}
	}
	if (KeyState[(unsigned char)'\x1b'] == INPUT_FIRST_PRESS)
	{
		if (menu == CONTROL)
		{
			menu = MAIN;
			MenuUpdate();
		}
	}
	if (KeyState[(unsigned char)'w'] == INPUT_FIRST_PRESS)
	{
		if (menu == HOST) {
			if (selection == 0) {
				selection = 4;
				MenuUpdate();
			}
			else {
				selection--;
				MenuUpdate();
			}
		}
	}
		else if (menu == JOIN)
		{
			if (selection == 0) {
				selection = 10;
				MenuUpdate();
			}
			else {
				selection--;
				MenuUpdate();
			}
	}
	if (KeyState[(unsigned char)'s'] == INPUT_FIRST_PRESS)
	{
		if (menu == HOST) {
			if (selection == 4) {
				selection = 0;
				MenuUpdate();
			}
			else {
				selection++;
				MenuUpdate();
			}
		}
	}
	else if (menu == JOIN)
	{
		if (selection == 10) {
			selection = 0;
			MenuUpdate();
		}
		else {
			selection++;
			MenuUpdate();
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
	else if (menu == COOP) {
		for (int i = 0; i < coopMenu.size(); i++) {
			coopMenu[i]->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
		}
		coopMenu[selection]->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	}
	else if (menu == HOST) {
		for (int i = 0; i < hostMenu.size(); i++) {
			hostMenu[i]->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
		}
		hostMenu[selection]->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	}
	else if (menu == JOIN) {
		for (int i = 0; i < joinMenu.size(); i++) {
			joinMenu[i]->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
		}
		joinMenu[selection]->SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
	}
}