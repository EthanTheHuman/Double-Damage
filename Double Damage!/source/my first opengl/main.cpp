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
GameManager Manager;

TextLabel * label;

CubeMap * MySkybox;

unsigned char KeyState[255]; // Global

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

	//Updated Keyboard Functions
	glutKeyboardFunc(Keyboard_Down);
	glutKeyboardUpFunc(Keyboard_Up);

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
		"Fonts/arial.ttf", glm::vec2(100.0f, 100.0f), TextShader);
	label->SetScale(1.0f);
	label->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));

	KarateGuy1 = new Sprite("Sprites/KarateGuy1.png", MyCamera, SpriteShader);
	KarateGuy1->SetTranslation({ -1.5,0,0 });
	KarateGuy1->SetScale({ 0.5,0.5,0 });
	KarateGuy2 = new Sprite("Sprites/KarateGuy2.png", MyCamera, SpriteShader);

	KarateGuy2->SetTranslation({ -1.6,0,0.001 });
	KarateGuy2->SetScale({ -0.5f , 0.5f , 0.5f });

	MyPyramid = new Model("Models/Wraith Raider Starship/Wraith Raider Starship.obj", MyCamera, ModelBasicShader);
	MyPyramid->SetScale({ 0.005f, 0.005f, 0.005f });

	MySkybox = new CubeMap(MyCamera, SkyboxShader, "top.jpg", "bottom.jpg", "left.jpg", "right.jpg", "front.jpg", "back.jpg");
	//---------------------------------------------------------------
}

// Render Function
void render(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 0.0, 0.0, 1.0); // clear red
	//GameManager::GetInstance()->render();
	MyCamera->Update();
	glFrontFace(GL_CCW);

	//Background
	MySkybox->Render();

	//Render 3D objects
	MyPyramid->Render();

	//Double-Render transparent objects
	//KarateGuy2->render();
	//KarateGuy1->render();
	//KarateGuy2->render();

	label->Render();
	glutSwapBuffers();
}

// Update Function
void update()
{
	glutPostRedisplay();
	//Updated Move Function
	Manager.GetInstance()->CurrentSceneClass()->MoveCharacter(KeyState);
}

//Updated Keyboard Functions
void Keyboard_Down(unsigned char key, int x, int y) { KeyState[key] = INPUT_HOLD; }
void Keyboard_Up(unsigned char key, int x, int y) { KeyState[key] = INPUT_RELEASED; }