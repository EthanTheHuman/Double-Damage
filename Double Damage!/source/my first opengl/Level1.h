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
#include <cmath>
#include <time.h>

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

// Namespace
using namespace std;

class Level1 :
	public Scene
{
public:
	Level1();
	~Level1();
	void Init();
	void Deconstruct();
	void Render();
	void Update();
	void MoveCharacter(unsigned char KeyState[255]);
	void MenuUpdate();
	void MovePlayerOne(glm::vec3 _NewPosition);

private:
	// List of objects
	Camera * MyCamera;
	Model * MyPyramid;
	Sprite * KarateGuy1;
	Sprite * KarateGuy2;
	CubeMap * MySkybox;
	ShaderLoader shaderloader;
	Player * _Player;
	std::vector<UFO*> UFOS;
	UFO * TempUFO;
	TextLabel * g_Score;
	int score = 0;

	// List of Shaders
	GLuint SpriteShader;
	GLuint ModelBasicShader;
	GLuint AmbientShader;
	GLuint TextShader;
	GLuint SkyboxShader;

	//menu stuff
	std::vector<TextLabel*> pauseMenu;
	TextLabel * TempLabel;
	int selection = 0;
	bool Gameover = false;
	Type UiType = SEEK;
};

