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
#include "Utils.h"
#include "dependencies\FMOD\fmod.hpp"

// Namespace
using namespace std;

// Functions
void init();
void render(void);
void update();
void Inputs(unsigned char key, int x, int y);
Camera MyCamera;
Model * MyPyramid;

enum InputState
{
	INPUT_FIRST_RELEASE,	// First frame of Up state
	INPUT_RELEASED,			// Default State (Up)
	INPUT_FIRST_PRESS,		// First frame of Down state
	INPUT_HOLD,				// Key is held Down
};

	// Global

// Main function
int main(int argc, char **argv)
{
	// OpenGL Window Creation
	glutInit(&argc, argv);
	glutSetOption(GLUT_MULTISAMPLE, 8);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(500, 300);
	glutInitWindowSize(SRCWIDTH, SRCHEIGHT);
	glutCreateWindow("Thursday The Twelfth");
	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(Inputs);
	glEnable(GL_MULTISAMPLE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(1.0, 1.0, 0.0, 1.0); //clear red

	// Initialisation
	glewInit();
	init();

	// Functions

	// register callbacks
	glutDisplayFunc(render);
	glutIdleFunc(update);
	glutMainLoop();

	return(0);
}

// Initialise Function
void init()
{
	//GameManager::GetInstance()->SwitchScene(0);
	ShaderLoader shaderloader;
	GLuint MyProgram = shaderloader.CreateProgram("Shaders/Sprite.vs", "Shaders/Sprite.fs");
	MyPyramid = new Model(& MyCamera, MyProgram);
	//---------------------------------------------------------------
}

// Render Function
void render(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 0.0, 0.0, 1.0); // clear red
	//GameManager::GetInstance()->render();
	MyCamera.Update();
	MyPyramid->Render();

	glutSwapBuffers();
}

// Update Function
void update()
{
	glutPostRedisplay();
}

void Inputs(unsigned char key, int x, int y)
{
	unsigned char KeyState[255];
	KeyState[key] = INPUT_HOLD;
	if (KeyState[(unsigned char)'w'] == INPUT_HOLD)
	{
		GameManager::GetInstance()->CurrentSceneClass()->w();
	}
	else if (KeyState[(unsigned char)'s'] == INPUT_HOLD)
	{
		GameManager::GetInstance()->CurrentSceneClass()->s();
	}
	else if (KeyState[(unsigned char)'a'] == INPUT_HOLD)
	{
		GameManager::GetInstance()->CurrentSceneClass()->a();
	}
	else if (KeyState[(unsigned char)'d'] == INPUT_HOLD)
	{
		GameManager::GetInstance()->CurrentSceneClass()->d();
	}
}