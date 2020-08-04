#pragma once
#include "Model.h"
#include "Texture.h"

#define RESOURCE_MANAGER_FILE_PATH "../Resources/RM.txt"

class ResourceManager
{
protected:
	ResourceManager();
	~ResourceManager();

public:
	static ResourceManager * GetInstance()
	{
		if (ms_pInstance == NULL)
			ms_pInstance = new ResourceManager;
		return ms_pInstance;
	}

	static void DestroyInstance()
	{
		if (ms_pInstance)
		{
			delete ms_pInstance;
			ms_pInstance = NULL;
		}
	}
	void LoadResource();
	void AddModel(Model *model);
	void AddTexture(Texture *texture);
private:
	static ResourceManager * ms_pInstance;
	GLuint m_numberModel, m_numberTexture, m_id;
	Model **m_model;
	Texture **m_texture;
};
