#pragma once
#include "BaseAnimal.h"
#include <vector>

class AnimalManager
{
public:
	int width;
	int height;
	std::vector<BaseAnimal*> fields;

	AnimalManager(int w, int h);
	~AnimalManager();

	int GetNumberOfNeighbours(int index);
	void AddAnimal(int index, BaseAnimal& baseAnimal);
	void RemoveAnimal(int index);
};

