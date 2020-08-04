#include "stdafx.h"
#include "Model.h"

Model::Model()
{
}

Model::~Model()
{
}

void Model::LoadModel(char *path)
{
	FILE *f = fopen(path, "r");
	fscanf(f, "NrVertices: %d\n", &m_nrVertices);
	m_verticesData = new Vertex[m_nrVertices];
	int temp;
	
	for (int i = 0; i < m_nrVertices; i++)
	{
		fscanf(f, "%d. pos:[%f, %f, %f];", &temp, &m_verticesData[i].pos.x, &m_verticesData[i].pos.y, &m_verticesData[i].pos.z);
		fscanf(f, " norm:[%f, %f, %f];", &m_verticesData[i].normal.x, &m_verticesData[i].normal.y, &m_verticesData[i].normal.z);
		fscanf(f, " binorm:[%f, %f, %f];", &m_verticesData[i].binormal.x, &m_verticesData[i].binormal.y, &m_verticesData[i].binormal.z);
		fscanf(f, " tgt:[%f, %f, %f];", &m_verticesData[i].tangent.x, &m_verticesData[i].tangent.y, &m_verticesData[i].tangent.z);
		fscanf(f, " uv:[%f, %f];\n", &m_verticesData[i].uv.x, &m_verticesData[i].uv.y);
	}
	fscanf(f, "NrIndices: %d", &m_nrIndices);
	m_indices = new GLuint[m_nrIndices];
	int j = -1;
	
	for (int i = 0; i < m_nrIndices / 3; i++)
	{
		GLuint indice;
		fscanf(f, "%d.", &temp);
		fscanf(f, "%d,", &m_indices[++j]);
		fscanf(f, "%d,", &m_indices[++j]);
		fscanf(f, "%d,", &m_indices[++j]);
	}
	fclose(f);
	//buffer object
	glGenBuffers(1, &m_vboId);
	glBindBuffer(GL_ARRAY_BUFFER, m_vboId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*m_nrVertices, m_verticesData, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &m_iboId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_iboId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*m_nrIndices, m_indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

Vertex * Model::GetVerticesData()
{
	return this->m_verticesData;
}

GLuint * Model::GetIndices()
{
	return this->m_indices;
}
GLuint Model::GetNrVertices()
{
	return this->m_nrVertices;
}
GLuint Model::GetNrIndices()
{
	return this->m_nrIndices;
}

GLuint Model::GetVboId()
{
	return this->m_vboId;
}
GLuint Model::GetIboId()
{
	return this->m_iboId;
}
