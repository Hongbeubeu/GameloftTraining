#include "stdafx.h"
#include "Object.h"

Object::Object()
{
	Matrix rotateX, rotateY, rotateZ, rotationMatrix;
	rotateX.SetRotationX(0.0f);
	rotateZ.SetRotationY(0.0f);
	rotateY.SetRotationZ(0.0f);
	rotationMatrix = rotateZ * rotateX * rotateY;
	Matrix translationMatrix, scaleMatrix, viewMatrix, projectionMatrix;
	scaleMatrix.SetScale(0.5f);
	translationMatrix.SetTranslation(0.0f, 0.0f, 0.0f);

	m_worldMatrix = scaleMatrix * rotationMatrix * translationMatrix;

	viewMatrix.SetIdentity();
	projectionMatrix.SetIdentity();

	m_WVP_matrix = m_worldMatrix * viewMatrix * projectionMatrix;
}

Object::~Object()
{
}

void Object::AddModel(Model *model)
{
	this->m_model = model;
}

void Object::AddTexture(Texture *texture)
{
	this->m_texture = texture;
}

GLuint Object::InitModel(char *pathVs,char *pathFs)
{
	return m_myShaders.Init(pathVs, pathFs);
}

void Object::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glActiveTexture(GL_TEXTURE);
	glBindTexture(GL_TEXTURE_2D, this->m_texture->GetTextureId());
	int iTextureLoc = glGetUniformLocation(m_myShaders.program, "u_texture");
	glUniform1i(iTextureLoc, 0);

	glUseProgram(m_myShaders.program);
	glBindTexture(GL_TEXTURE_2D, this->m_texture->GetTextureId());
	glBindBuffer(GL_ARRAY_BUFFER, this->m_model->GetVboId());

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_model->GetIboId());
	if (m_myShaders.positionAttribute != -1)
	{
		glEnableVertexAttribArray(m_myShaders.positionAttribute);
		glVertexAttribPointer(m_myShaders.positionAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

		glEnableVertexAttribArray(m_myShaders.iTexcoordLoc);
		glVertexAttribPointer(m_myShaders.iTexcoordLoc, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (char *)0 + sizeof(Vector3) * 4);
	}

	if (m_myShaders.matrixId != -1)
	{
		glEnableVertexAttribArray(m_myShaders.matrixId);
		glUniformMatrix4fv(m_myShaders.matrixId, 1, GL_FALSE, (GLfloat *)&m_WVP_matrix.m);
	}

	glDrawElements(GL_TRIANGLES, this->m_model->GetNrIndices(), GL_UNSIGNED_INT, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Object::Update(Matrix viewMatrix, Matrix projectionMatrix)
{
	this->m_WVP_matrix = m_worldMatrix*viewMatrix*projectionMatrix;
}