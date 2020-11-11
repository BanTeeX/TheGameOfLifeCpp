#include "AnimalManager.h"

AnimalManager::AnimalManager(int w, int h)
	: width(w)
	, height(h)
{
	fields.resize(w * h);
	for (int i = 0; i < fields.size(); i++)
	{
		fields[i] = nullptr;
	}
}

AnimalManager::~AnimalManager()
{
	for (int i = 0; i < fields.size(); i++)
	{
		delete fields[i];
	}
}

int AnimalManager::GetNumberOfNeighbours(int index)
{
	int x = index % width;
	int y = index / width;
	int count = 0;
	for (int i = x + width - 1; i < x + width + 2; i++)
	{
		for (int j = y + height - 1; j < y + height + 2; j++)
		{
			if (fields[(j % height) * width + (i % width)] != nullptr)
			{
				count++;
			}
		}
	}
	if (fields[index] != nullptr)
	{
		return --count;
	}
	else
	{
		return count;
	}
}

void AnimalManager::AddAnimal(int index, BaseAnimal& baseAnimal)
{
	fields[index] = &baseAnimal;
}

void AnimalManager::RemoveAnimal(int index)
{
	delete fields[index];
	fields[index] = nullptr;
}
