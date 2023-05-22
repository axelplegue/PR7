#pragma once
#include "Personaje.h"
#include <iostream>
using namespace std;

class Player : public Personaje
{

	public:
	Player(int pHp, int pAttack, string pName, int pPosX, int pPosY, bool pIsAlive);
};
