#pragma once
#include "Object.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();
	void Init();
	void AddObject();
	void Update();
	void Draw();
private:
	GLuint m_numberObject;
	Object **m_objects;
};
