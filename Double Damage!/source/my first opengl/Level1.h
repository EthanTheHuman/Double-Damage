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
#include "dependencies\FMOD\fmod.hpp"
#include "Player.h"

class Level1 :
	public Scene
{
public:
	Level1();
	~Level1();
	void Init();
	void Render();
	void Update();
private:
	// List of Objects
	Camera * MyCamera;
	Player * PlayerChar;
	Sprite * KarateGuy1;
	Sprite * KarateGuy2;
	TextLabel * label;
	CubeMap * MySkybox;

	// List of Shaders
	GLuint SpriteShader;
	GLuint ModelBasicShader;
	GLuint TextShader;
	GLuint SkyboxShader;
};

