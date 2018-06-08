#pragma once
// Dependencies
#include <iostream>
#include "ShaderLoader.h"
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include "Dependencies\soil\SOIL.h"
#include "Dependencies\glm\glm.hpp"
#include "Dependencies\glm\gtc\matrix_transform.hpp"
#include "Dependencies\glm\gtc\type_ptr.hpp"
#include "Sprite.h"
#include "Model.h"

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

