#include <cstdlib>
#include <time.h>
#include <Windows.h>
#include <vector>
#include "GameManager.h"
#include "Animal.h"
#include <string>

GameManager::GameManager(AnimalManager& animalManager)
	: animalManager(animalManager)
{
	srand(time(NULL));
}

void GameManager::RandomFill()
{
	for (int i = 0, id = 1; i < animalManager.fields.size(); i++)
	{
		if (rand() % 2 == 1)
		{
			animalManager.AddAnimal(i, *(new Animal));
		}
		else
		{
			animalManager.RemoveAnimal(i);
		}
	}
}

void GameManager::DoCycle()
{
	std::vector<bool> toChange;
	toChange.resize(animalManager.fields.size());
	for (int i = 0; i < toChange.size(); i++)
	{
		toChange[i] = false;
	}
	for (int i = 0; i < toChange.size(); i++)
	{
		int num = animalManager.GetNumberOfNeighbours(i);
		if ((animalManager.fields[i] == nullptr && num == 3) ||
			(animalManager.fields[i] != nullptr && num != 3 && num != 2))
		{
			toChange[i] = true;
		}
	}
	for (int i = 0; i < toChange.size(); i++)
	{
		if (toChange[i])
		{
			if (animalManager.fields[i] == nullptr)
			{
				animalManager.AddAnimal(i, *(new Animal));
			}
			else
			{
				animalManager.RemoveAnimal(i);
			}
		}
	}
}

void GameManager::Start()
{
	RandomFill();
	while (true)
	{
		system("cls");
		Print();
		DoCycle();
		Sleep(15);
	}
}

void GameManager::Print()
{
	std::string output = "";
	for (int i = 0; i < animalManager.width + 2; i++)
	{
		output += '-';
	}
	output += '\n';
	for (int i = 0; i < animalManager.width * animalManager.height; i++)
	{
		if (i % animalManager.width == 0)
		{
			output += '|';
		}
		if (animalManager.fields[i] != nullptr)
		{
			output += '#';
		}
		else
		{
			output += ' ';
		}
		if (i % animalManager.width == animalManager.width - 1)
		{
			output += "|\n";
		}
	}
	for (int i = 0; i < animalManager.width + 2; i++)
	{
		output += '-';
	}
	printf("%s", output.c_str());
}
