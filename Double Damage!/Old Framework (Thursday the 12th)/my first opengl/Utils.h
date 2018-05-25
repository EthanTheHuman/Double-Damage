#pragma once
#include <iostream>
#include "ShaderLoader.h"
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include "Dependencies\soil\SOIL.h"
#include "Dependencies\glm\glm.hpp"
#include "Dependencies\glm\gtc\matrix_transform.hpp"
#include "Dependencies\glm\gtc\type_ptr.hpp"

namespace Utility {
	const int SRCWIDTH = 800;
	const int SRCHEIGHT = 600;
};

struct PositionStruct
{
	float x;
	float y;
	float z;
};

struct ColorStruct
{
	float r;
	float g;
	float b;
};

struct TexCoordStruct
{
	float x;
	float y;
};

class Utils
{
public:
	Utils();
	~Utils();
	PositionStruct CreatePositionStruct();
	void CreateTexCoordStruct();
	void CreateVertexFormatStruct();
	void CreateIndexFormatStruct();
	void SetQuadVertices();
	void SetResolution();
};

