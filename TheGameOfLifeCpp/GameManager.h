#pragma once
#include "AnimalManager.h"

class GameManager
{
public:
	AnimalManager& animalManager;

	GameManager(AnimalManager& animalManager);

	void RandomFill();
	void DoCycle();
	void Start();
	void Print();
};

