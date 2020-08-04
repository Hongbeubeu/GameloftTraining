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
	printf("%d\n", m_numberModel);
	char *path = new char[50];
	for (int i = 0; i < m_numberModel; i++)
	{
		fscanf(f, "ID %d\n", &m_id);
		fscanf(f, "FILE %s\n", path);
		printf("%s\n", path);
	}

	fscanf(f, )
	delete(path);
	fclose(f);
	return;
}