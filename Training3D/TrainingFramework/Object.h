#pragma once
#include "Model.h"
#include "Texture.h"
class Object
{
public:
	Object();
	~Object();
	void AddModel(Model * model);
	void AddTexture(Texture *texture);
	GLuint InitModel(char *pathVs, char *pathFs);
	void Draw();
	void Update(Matrix viewMatrix, Matrix projectionMatrix);
private:
	Model *m_model;
	Texture *m_texture;
	Shaders m_myShaders;
	Matrix m_WVP_matrix, m_worldMatrix;
};

