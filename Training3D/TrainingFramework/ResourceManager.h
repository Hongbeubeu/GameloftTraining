#pragma once
#include "Model.h"
#include "Texture.h"
#include <vector>

#define RESOURCE_MANAGER_FILE_PATH "../Resources/RM.txt"
#define RESOURCE_LENGTH 100

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
private:
	static ResourceManager * ms_pInstance;
	GLuint m_numberModel, m_numberTexture, m_id;
	vector<Model *> m_modelList;
	vector<Texture *> m_textureList;
};
