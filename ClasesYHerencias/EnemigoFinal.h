#pragma once
#include "Enemigo.h"
#include "Personaje.h"
#include <iostream>
using namespace std;

class EnemigoFinal : public Personaje
{
private:
	int ataqueEspecialFuego=50;
	int ataqueEspecialHielo=40;

public:
	//getter:
	int getAtaqueEspecialFuego();
	int getAtaqueEspecialHielo();


	//setter:
	void setAtaqueEspecialFuego(int pAtaqueEspecialFuego);
	void setAtaqueEspecialHielo(int pAtaqueEspecialHielo);


	//constructor:

	EnemigoFinal(int pHp, int pAttack, string pName, int pPosX, int pPosY, bool pIsAlive, int pAtaqueEspecialFuego, int pAtaqueEspecialHielo);
};

