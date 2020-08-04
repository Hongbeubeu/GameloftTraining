// TrainingFramework.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../Utilities/utilities.h" // if you use STL, please include this line AFTER all other include
#include "Shaders.h"
#include "Globals.h"
#include <conio.h>
#include "Model.h"
#include "Texture.h"
#include "Object.h"
#include "Camera.h"
#include "ResourceManager.h"
Object woman1;
Camera *camera;

int Init ( ESContext *esContext )
{
	glClearColor ( 1.0f, 1.0f, 1.0f, 1.0f );
	
	//triangle data (heap)
	
	Model *model = new Model(); 
	model ->LoadModel("../Resources/Models/woman1.nfg");
	woman1.AddModel(model);
	Texture *texture = new Texture();
	texture->LoadTexture("../Resources/Textures/Woman1.tga");
	woman1.AddTexture(texture);

	camera = new Camera();
	ResourceManager::GetInstance()->LoadResource();
	return woman1.InitModel("../Resources/Shaders/TriangleShaderVS.vs", "../Resources/Shaders/TriangleShaderFS.fs");
}

void Draw ( ESContext *esContext )
{
	woman1.Draw();
	eglSwapBuffers ( esContext->eglDisplay, esContext->eglSurface );
}

void Update ( ESContext *esContext, float deltaTime )
{
	camera->Update(deltaTime); 
	woman1.Update(camera->GetViewMatrix(), camera->GetProjectionMatrix());
}

void Key ( ESContext *esContext, unsigned char key, bool bIsPressed)
{
	camera->CheckKeyPress(key, bIsPressed);
}

void CleanUp()
{
	//glDeleteBuffers(1, &vboId);
}

int _tmain(int argc, _TCHAR* argv[])
{
	ESContext esContext;

    esInitContext ( &esContext );

	esCreateWindow ( &esContext, "Hello Triangle", Globals::screenWidth, Globals::screenHeight, ES_WINDOW_RGB | ES_WINDOW_DEPTH);

	if ( Init ( &esContext ) != 0 )
		return 0;

	

	esRegisterDrawFunc ( &esContext, Draw );
	esRegisterUpdateFunc ( &esContext, Update );
	esRegisterKeyFunc ( &esContext, Key);

	esMainLoop ( &esContext );

	//releasing OpenGL resources
	CleanUp();

	//identifying memory leaks
	MemoryDump();
	printf("Press any key...\n");
	_getch();

	return 0;
}

