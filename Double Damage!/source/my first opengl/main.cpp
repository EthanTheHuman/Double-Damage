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

// Namespace
using namespace std;

// Functions
void init();
void render(void);
void update();
void Inputs(unsigned char key, int x, int y);
Camera * MyCamera;
Model * MyPyramid;
Sprite * KarateGuy1;
Sprite * KarateGuy2;
<<<<<<< HEAD
<<<<<<< HEAD
TextLabel * label;
=======
CubeMap * MySkybox;
>>>>>>> 95d07e56588cc16eca9800c67081300d4959e3f8
=======
CubeMap * MySkybox;
>>>>>>> 95d07e56588cc16eca9800c67081300d4959e3f8

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
	glutCreateWindow("Double Damage!");
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
	MyCamera = new Camera();
	ShaderLoader shaderloader;
	GLuint SpriteShader = shaderloader.CreateProgram("Shaders/Sprite.vs", "Shaders/Sprite.fs");
	GLuint ModelBasicShader = shaderloader.CreateProgram("Shaders/ModelBasic.vs", "Shaders/ModelBasic.fs");
	GLuint TextShader = shaderloader.CreateProgram("Shaders/Text.vs", "Shaders/Text.fs");
	GLuint SkyboxShader = shaderloader.CreateProgram("Shaders/Cubemap.vs", "Shaders/Cubemap.fs");
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CW);

	label = new TextLabel("Sample Text",
		"Fonts/arial.ttf", glm::vec2(100.0f, 100.0f));
	label->SetScale(1.0f);
	label->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));

	KarateGuy1 = new Sprite("Sprites/KarateGuy1.png", MyCamera, SpriteShader);
	KarateGuy1->SetTranslation({ -1.5,0,0 });
	KarateGuy1->SetScale({ 0.5,0.5,0 });
	KarateGuy2 = new Sprite("Sprites/KarateGuy2.png", MyCamera, SpriteShader);
	//KarateGuy2->SetTranslation({ 1.5,0,0 });
	KarateGuy2->SetTranslation({ -1.6,0,0.001 });
	KarateGuy2->SetScale({ -0.5, 0.5, 0.5 });
	MyPyramid = new Model("Models/Tank/Tank.obj", MyCamera, ModelBasicShader);
	MyPyramid->SetScale({ 0.5,0.5,0.5 });
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 95d07e56588cc16eca9800c67081300d4959e3f8
	MySkybox = new CubeMap(MyCamera, SkyboxShader, "top.jpg", "bottom.jpg", "left.jpg", "right.jpg", "front.jpg", "back.jpg");
	//---------------------------------------------------------------
>>>>>>> 95d07e56588cc16eca9800c67081300d4959e3f8
}

// Render Function
void render(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 0.0, 0.0, 1.0); // clear red
	//GameManager::GetInstance()->render();
	MyCamera->Update();
	glFrontFace(GL_CCW);
<<<<<<< HEAD
=======

	//Background
	MySkybox->Render();

<<<<<<< HEAD
>>>>>>> 95d07e56588cc16eca9800c67081300d4959e3f8
=======
	//Background
	MySkybox->Render();

>>>>>>> 95d07e56588cc16eca9800c67081300d4959e3f8
	//Render 3D objects
	MyPyramid->Render();

	//Double-Render transparent objects
	KarateGuy2->render();
	KarateGuy1->render();
	KarateGuy2->render();
	label->Render();
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