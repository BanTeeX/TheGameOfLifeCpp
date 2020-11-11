#include "AnimalManager.h"
#include "GameManager.h"

int main()
{
	AnimalManager animalManager(100, 25);
	GameManager gameManager(animalManager);
	gameManager.Start();
}
