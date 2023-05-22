#pragma once
#include <iostream>

class Botiquin
{
private:
	int posX=0;
	int posY=0;

public:
	//getters
	int getPosX();
	int getPosY();

	//setters
	void setPosX(int pPosX);
	void setPosY(int pPosY);

	Botiquin(int pPosX, int pPosY);
	Botiquin();

};