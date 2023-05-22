#include <iostream>
#include "EnemigoFinal.h"
using namespace std;

int EnemigoFinal::getAtaqueEspecialFuego() {
	return ataqueEspecialFuego;
};
int EnemigoFinal::getAtaqueEspecialHielo() {
	return ataqueEspecialHielo;
};

void EnemigoFinal::setAtaqueEspecialFuego(int pAtaqueEspecialFuego) {
	ataqueEspecialFuego = pAtaqueEspecialFuego;
};
void EnemigoFinal::setAtaqueEspecialHielo(int pAtaqueEspecialHielo) {
	ataqueEspecialHielo = pAtaqueEspecialHielo;
};


EnemigoFinal::EnemigoFinal(int pHp, int pAttack, string pName, int pPosX, int pPosY, bool pIsAlive, int pAtaqueEspecialFuego, int pAtaqueEspecialHielo) : Personaje(pHp, pAttack, pName, pPosX, pPosY, pIsAlive) {

}