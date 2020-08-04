#pragma once
#include "../Utilities/utilities.h" // if you use STL, please include this line AFTER all other include
#include "Globals.h"
#include "Shaders.h"

const INT32 MOVE_FORWARD = 1 << 0;
const INT32 MOVE_BACKWARD = 1 << 1;
const INT32 MOVE_LEFT = 1 << 2;
const INT32 MOVE_RIGHT = 1 << 3;
const INT32 ROTATION_UP = 1 << 4;
const INT32 ROTATION_DOWN = 1 << 5;
const INT32 ROTATION_LEFT = 1 << 6;
const INT32 ROTATION_RIGHT = 1 << 7;

class Camera
{
public:
	Camera();
	~Camera();
	void CalculateViewMatrix();
	void CalculateWorldMatrix();
	void MoveForward(float deltaTime);
	void MoveBackward(float deltaTime);
	void MoveLeft(float deltaTime);
	void MoveRight(float deltaTime);
	void RotateUp(float deltaTime);
	void RotateDown(float deltaTime);
	void RotateLeft(float deltaTime);
	void RotateRight(float deltaTime);
	void Update(float deltaTime);

	void UpdateCamera(Vector3 deltaMove);

	void CheckKeyPress(unsigned char key, bool isPressed);
	Matrix RotationMatrixAroundY(float angle);
	Matrix GetViewMatrix();
	Matrix GetWorldMatrix();
	Matrix GetProjectionMatrix();
private:
	Vector3 m_position, m_target, m_up;
	Vector3 xaxis, yaxis, zaxis;
	Matrix m_viewMatrix, m_worldMatrix, m_projectionMatrix;
	INT32 m_direction = 0;
};

