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
	label.push_back(TempLabel);

	_Player = new Player(MyCamera, AmbientShader);
	MySkybox = new CubeMap(MyCamera, SkyboxShader, "Space/bkg1_top.png", "Space/bkg1_bot.png", "Space/bkg1_right.png", "Space/bkg1_left.png", "Space/bkg1_front.png", "Space/bkg1_back.png");

}

void MainMenu::Render()
{
	MyCamera->Update();
	glFrontFace(GL_CCW);

	//Background
	MySkybox->Render();
	_Player->Render();
	for (auto It = label->begin(); It != label->end(); ++It)
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

void MainMenu::Init()
{
}
