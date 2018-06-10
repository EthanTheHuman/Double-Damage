#pragma once
#include "Scene.h"

// Dependencies
#include <iostream>
#include "ShaderLoader.h"
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
#include "Sound.h"
#include "Sprite.h"
#include "Model.h"
#include "TextLabel.h"
#include "Utils.h"
#include "CubeMap.h"
#include "Player.h"
#include "UFO.h"
#include "dependencies\FMOD\fmod.hpp"

enum Menus {
	MAIN,
	PLAY,
	CONTROL
};

class MainMenu :
	public Scene
{
public:
	MainMenu();
	~MainMenu();
	void Render();
	void Update();
	void MoveCharacter(unsigned char KeyState[255]);
	void MenuUpdate();

private:
	// List of objects
	Camera * MyCamera;
	std::vector<TextLabel*> mainMenu;
	std::vector<TextLabel*> playMenu;
	CubeMap * MySkybox;
	ShaderLoader shaderloader;
	Player * _Player;

	// List of Shaders
	GLuint SpriteShader;
	GLuint ModelBasicShader;
	GLuint AmbientShader;
	GLuint TextShader;
	GLuint SkyboxShader;

	//menu stuff
	int selection = 0;
	Menus menu = MAIN;
};
