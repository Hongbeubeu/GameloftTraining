#pragma once
#include "../Utilities/utilities.h" // if you use STL, please include this line AFTER all other include
#include "Vertex.h"
#include "Shaders.h"
#include "Globals.h"
#include <conio.h>

using namespace std;

class Model
{
public:
	Model();
	~Model();
	void LoadModel(char *path);
	Vertex * GetVerticesData();
	GLuint * GetIndices();
	GLuint GetNrVertices();
	GLuint GetNrIndices();
	GLuint GetVboId();
	GLuint GetIboId();

private:
	GLuint m_vboId, m_iboId, m_nrVertices, m_nrIndices;
	Vertex *m_verticesData;
	GLuint *m_indices;
};

