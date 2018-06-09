#include "Level1.h"



Level1::Level1()
{
}


Level1::~Level1()
{
}

void Level1::Init()
{
	MyCamera = new Camera(glm::vec3(5,0,-3), glm::vec3(0,0,0), glm::vec3(0,1,0));
	SpriteShader = shaderloader.CreateProgram("Shaders/Sprite.vs", "Shaders/Sprite.fs");
	ModelBasicShader = shaderloader.CreateProgram("Shaders/ModelBasic.vs", "Shaders/ModelBasic.fs");
	AmbientShader = shaderloader.CreateProgram("Shaders/Ambient.vs", "Shaders/Ambient.fs");
	TextShader = shaderloader.CreateProgram("Shaders/Text.vs", "Shaders/Text.fs");
	SkyboxShader = shaderloader.CreateProgram("Shaders/Cubemap.vs", "Shaders/Cubemap.fs");

	label = new TextLabel("Play", "fonts/arial.ttf", glm::vec2(100, 100));
	label->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));

	_Player = new Player(MyCamera, AmbientShader);
	_UFO1 = new UFO(MyCamera, AmbientShader);

	MySkybox = new CubeMap(MyCamera, SkyboxShader, "Citadel/top.jpg", "Citadel/bottom.jpg", "Citadel/left.jpg", "Citadel/right.jpg", "Citadel/front.jpg", "Citadel/back.jpg");
}

void Level1::Render()
{
	MyCamera->Update();
	glFrontFace(GL_CCW);

	//Background
	MySkybox->Render();

	//Render 3D objects
	_Player->Render();
	_UFO1->Render();

	label->Render();
}

void Level1::Update()
{
	_Player->Update();
	_UFO1->Update();
}

void Level1::MoveCharacter(unsigned char KeyState[255])
{
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

	//Rotation

	//All 4
	if ((KeyState[(unsigned char)'w'] == INPUT_HOLD) && (KeyState[(unsigned char)'s'] == INPUT_HOLD) && (KeyState[(unsigned char)'a'] == INPUT_HOLD) && (KeyState[(unsigned char)'d'] == INPUT_HOLD))
	{
		//No rotation
	}

	//Trios
	else if ((KeyState[(unsigned char)'w'] == INPUT_HOLD) && (KeyState[(unsigned char)'s'] == INPUT_HOLD) && (KeyState[(unsigned char)'a'] == INPUT_HOLD))
	{
		//No rotation
	}
	else if ((KeyState[(unsigned char)'s'] == INPUT_HOLD) && (KeyState[(unsigned char)'a'] == INPUT_HOLD) && (KeyState[(unsigned char)'d'] == INPUT_HOLD))
	{
		//No rotation
	}
	else if ((KeyState[(unsigned char)'w'] == INPUT_HOLD) && (KeyState[(unsigned char)'a'] == INPUT_HOLD) && (KeyState[(unsigned char)'d'] == INPUT_HOLD))
	{
		//No rotation
	}
	else if ((KeyState[(unsigned char)'w'] == INPUT_HOLD) && (KeyState[(unsigned char)'s'] == INPUT_HOLD) && (KeyState[(unsigned char)'d'] == INPUT_HOLD))
	{
		//No rotation
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
