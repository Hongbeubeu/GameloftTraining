#pragma once
#include "Shaders.h"
#include "Globals.h"
#include <conio.h>

class Texture
{
public:
	Texture();
	~Texture();
	void LoadTexture(char *path);
	GLuint GetTextureId();
private:
	int width, height, bpp;
	GLuint m_textureId;
};

