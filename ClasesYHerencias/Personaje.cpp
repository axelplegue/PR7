#include <iostream>
#include "Personaje.h"
using namespace std;

//getters
int Personaje::getHp() {
	return hp;
}
int Personaje::getAttack() {
	return attack;
}
string Personaje::getName() {
	return name;
}
int Personaje::getPosX() {
	return posX;
}
int Personaje::getPosY() {
	return posY;
}
bool Personaje::getIsAlive() {
	if (hp > 0) {
		return true;
	}
	else {
		return false;
	}
}

//setters
void Personaje::setHp(int pHp) {
	hp = pHp;
}
void Personaje::setAttack(int pAttack) {
	attack = pAttack;
}
void Personaje::setName(string pName) {
	name = pName;
}
void Personaje::setPosX(int pPosX) {
	posX = pPosX;
}
void Personaje::setPosY(int pPosY) {
	posY = pPosY;
}
void Personaje::setIsAlive(bool pIsAlive) {
	isAlive = pIsAlive;
}

Personaje::Personaje(int pHp, int pAttack, string pName, int pPosX, int pPosY, bool pIsAlive) {
	hp = pHp;
	attack = pAttack;
	name = pName;
	posX = pPosX;
	posY = pPosY;
	isAlive = pIsAlive;
}
Personaje::Personaje() {

}
