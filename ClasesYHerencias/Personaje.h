#pragma once
#include <iostream>
using namespace std;

class Personaje
{
private:
	int hp;
	int attack;
	string name;
	int posX;
	int posY;
	bool isAlive;

public:

	//getters

	int getHp();
	int getAttack();
	string getName();		
	int getPosX();
	int getPosY();
	bool getIsAlive();


	//setters
		
	void setHp(int hp);
	void setAttack(int attack);
	void setName(string name);
	void setPosX(int posX);
	void setPosY(int posY);
	void setIsAlive(bool isAlive);


	Personaje(int pHp, int pAttack, string pName, int pPosX, int pPosY, bool pIsAlive);
	Personaje();
};
