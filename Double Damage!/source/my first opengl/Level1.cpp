#include "Level1.h"

// Namespace
using namespace std;

Level1::Level1()
{
}


Level1::~Level1()
{
}

void Level1::Init()
{
	MyCamera = new Camera({0,2,-3}, {0,0,0}, {0,1,0});
	ShaderLoader shaderloader;

	SpriteShader = shaderloader.CreateProgram("Shaders/Sprite.vs", "Shaders/Sprite.fs");
	ModelBasicShader = shaderloader.CreateProgram("Shaders/ModelBasic.vs", "Shaders/ModelBasic.fs");
	TextShader = shaderloader.CreateProgram("Shaders/Text.vs", "Shaders/Text.fs");
	SkyboxShader = shaderloader.CreateProgram("Shaders/Cubemap.vs", "Shaders/Cubemap.fs");

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CW);
	label = new TextLabel("Sample Text",
		"Fonts/arial.ttf", glm::vec2(100.0f, 100.0f), TextShader);
	label->SetScale(1.0f);
	label->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));

	KarateGuy1 = new Sprite("Sprites/KarateGuy1.png", MyCamera, SpriteShader);
	KarateGuy1->SetTranslation({ -1.5,0,0 });
	KarateGuy1->SetScale({ 0.5,0.5,0 });
	KarateGuy2 = new Sprite("Sprites/KarateGuy2.png", MyCamera, SpriteShader);

	KarateGuy2->SetTranslation({ -1.6,0,0.001 });
	KarateGuy2->SetScale({ -0.5f , 0.5f , 0.5f });

	PlayerChar = new Player(MyCamera, ModelBasicShader);

	MySkybox = new CubeMap(MyCamera, SkyboxShader, "top.jpg", "bottom.jpg", "left.jpg", "right.jpg", "front.jpg", "back.jpg");
	//---------------------------------------------------------------
}

void Level1::Render()
{
	//Render 3D objects
	PlayerChar->render();

	//Double-Render transparent objects
	KarateGuy2->render();
	KarateGuy1->render();
	KarateGuy2->render();

	//Background
	MySkybox->Render();

	label->Render();
}

void Level1::Update()
{
}
