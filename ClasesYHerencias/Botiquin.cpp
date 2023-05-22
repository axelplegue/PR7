#include <iostream>

#include "Botiquin.h"
using namespace std;

int Botiquin::getPosX() {
	return posX;
};
int Botiquin::getPosY() {
	return posY;
};
void Botiquin::setPosX(int pPosX) {
	posX = pPosX;
};
void Botiquin::setPosY(int pPosY) {
	posY = pPosY;
};

Botiquin::Botiquin(int pPosX, int pPosY) {
	posX = pPosX;
	posY = pPosY;

};
Botiquin::Botiquin() {

};
