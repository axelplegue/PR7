#include <iostream>
#include "Enemigo.h"
#include "Player.h"
#include <string>
#include <stdlib.h>
#include "colors.h"
#include <windows.h>
using namespace std;

Enemigo::Enemigo(int pHp, int pAttack, string pName, int pPosX, int pPosY, bool pIsAlive) : Personaje(pHp, pAttack, pName, pPosX, pPosY, pIsAlive) {

}
Enemigo::Enemigo() {

}
