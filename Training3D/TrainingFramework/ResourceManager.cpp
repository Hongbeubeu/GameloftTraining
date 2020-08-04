#include "stdafx.h"
#include "ResourceManager.h"

ResourceManager * ResourceManager::ms_pInstance = NULL;

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
}

void ResourceManager::LoadResource()
{
	FILE *f;
	f = fopen(RESOURCE_MANAGER_FILE_PATH, "r");
	fscanf(f, "#Models: %d\n", &m_numberModel);
	
	for (int i = 0; i < m_numberModel; i++)
	{
		char path[RESOURCE_LENGTH];
		fscanf(f, "ID %d\n", &m_id);
		fscanf(f, "FILE %s\n", path);
		
		Model *model = new Model();
		model->LoadModel(path);
		m_modelList.push_back(model);
	}
	fscanf(f, "\n#2D Textures: %d\n", &m_numberTexture);
	for (int i = 0; i < m_numberTexture; i++)
	{
		char path[RESOURCE_LENGTH];
		fscanf(f, "ID %d\n", &m_id);
		fscanf(f, "FILE %s\n", path);
		Texture *texture = new Texture();
		texture->LoadTexture(path);
		m_textureList.push_back(texture);
		char tilling[20];
		fscanf(f, "TILLING %s\n", tilling);
	}
	fclose(f);
	return;
}

