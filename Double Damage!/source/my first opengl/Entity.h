#pragma once
#include "Sprite.h"

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
#include "TextLabel.h"
#include "Utils.h"
#include "CubeMap.h"
#include "dependencies\FMOD\fmod.hpp"

class Entity
{
public:
	Entity();
	Entity(int _x, int _y);
	~Entity();

public:
	int m_x;
	int m_y;
	Sprite m_Sprite;
	int ID;
};

