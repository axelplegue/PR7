#pragma once
#include "Personaje.h"
#include <iostream>
#include "Player.h"
using namespace std;

class Enemigo : public Personaje
{

	public:
	Enemigo(int pHp, int pAttack, string pName, int pPosX, int pPosY, bool pIsAlive);
	Enemigo();

};