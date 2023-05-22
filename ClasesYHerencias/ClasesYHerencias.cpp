#include <iostream>
#include "Enemigo.h"
#include "Player.h"
#include "Personaje.h"
#include "EnemigoFinal.h"
#include "colors.h"
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <wincon.h>
#include <cstdlib>
#include "colors.h"
#include <mmsystem.h>
#include <conio.h>
#include <string>
#include "Botiquin.h"

using namespace std;

int continuar=0;
string namePlayer="jose";
const int MAP_WIDTH = 50;
const int MAP_HEIGHT = 30;

// declaracion de objetos personajes enemigos:
Player player(100, 15, namePlayer, 0, 0, true);
EnemigoFinal enemigoFinal(100, 10, "MANOLO", 10, 0, true, 50, 40);

Enemigo* variosEnemigos(int numEnemigos) {
	Enemigo* arrayEnemigos = new Enemigo[numEnemigos];

	for (size_t i = 0; i < numEnemigos; i++)
	{
	
		arrayEnemigos[i] = Enemigo(100, 10, "Enemigo", 0, 0, true);

	}
	return arrayEnemigos;
}

Botiquin* variosBotiquines(int numBotiquines) {
	Botiquin* arrayBotiquines = new Botiquin[numBotiquines];

	for (size_t i = 0; i < numBotiquines; i++)
	{
		int posX = 1 + rand() % (50 - 1);
		int posY = 1 + rand() % (30 - 1);
		arrayBotiquines[i] = Botiquin(posX, posY);

	}
	return arrayBotiquines;
}

void titulo() {
	cout << LGREEN << "\t\t    ===========================================================================" << endl;
	cout << "\t\t    =				    El camino				      =" << endl;
	cout << "\t\t    =			          by axelplegue				      =" << endl;
	cout << "\t\t    ===========================================================================\n\n" << RESET<<endl;
}

void tituloBatallaFinal() {
	cout << LGREEN << "\t\t    ===========================================================================" << endl;
	cout << "\t\t    =				  BATALLA FINAL				      =" << endl;
	cout << "\t\t    =			          by axelplegue				      =" << endl;
	cout << "\t\t    ===========================================================================\n\n" << RESET << endl;
}

void tituloBatallaComun() {
	cout << LGREEN << "\t\t    ===========================================================================" << endl;
	cout << "\t\t    =				  BATALLA COMUN				      =" << endl;
	cout << "\t\t    =			          by axelplegue				      =" << endl;
	cout << "\t\t    ===========================================================================\n\n" << RESET << endl;
}

void explicacionJuego() {
	cout << "El siguiente juego se trata de un" << GREEN << " HEROE " <<RESET<< "que trata de llegar a su guarida.\n";
	cout << "Para jugar utiliza las teclas WASD.\n";
	cout << "Por el camino te encontraras con varios"<<RED<< " ENEMIGOS"<<RESET<<" que intentaran acabar con tu vida, pero estan ocultos.\n";
	cout << "Si tienes suerte, podras encontrarte con algun "<<GREEN <<"BOTIQUIN"<< RESET << " que te recuperara la vida.\n";
	cout << "Si quieres continuar con el juego, cualquier numero y luego enter:";
	cin >> continuar;
	Sleep(1500);
	system("CLS");
	titulo();
}

void BatallaEnemigoComun(Enemigo& enemigo, Player& player) {
	system("CLS");
	int ataque = 0;
	cout << "\n\n\n";
	cout << "Te has topado con un " << RED << "enemigo" << RESET << ", tendras que luchar contra el.\n";

	do
	{
		tituloBatallaComun();
		int enemyAttack = 1 + rand() % (15 - 1);
		int heroAttack = 1 + rand() % (30 - 5);
		cout << " \nEs tu turno para atacar al " << RED << "enemigo" << RESET << "\n";
		cout << "\nPulsa 0 y Enter para atacar\n";
		cin >> ataque;
		player.setAttack(heroAttack);
		enemigo.setHp(enemigo.getHp() - player.getAttack());

		if (enemigo.getHp() <= 0) {
			enemigo.setHp(0);
			cout << "\nEl " << RED << "enemigo" << RESET << " ha sido derrotado\n";
			enemigo.setIsAlive(false);
			Sleep(2000);
		}
		else if (enemigo.getHp() > 0) {

			enemigo.setAttack(enemyAttack);
			cout << "\nTras el ataque, la vida del " << RED << "enemigo" << RESET << " es de " << enemigo.getHp() << " puntos de vida\n";
			cout << "\nEl enemigo te va atacar de vuelta\n";
			player.setHp(player.getHp() - enemigo.getAttack());
			if (player.getHp() <= 0) {
				player.setHp(0);
				cout << "\nEl " << GREEN << "heroe" << RESET << " ha sido derrotado por el " << RED << "enemigo" << RESET << ".\n";
				Sleep(2000);

				player.setIsAlive(false);
			}
			else if (player.getHp() > 0) {
				cout << "\nLa vida del " << GREEN << "heroe" << RESET << " tras el ataque es de " << player.getHp() << "\n";
				Sleep(2000);
			}
		}

	} while (enemigo.getIsAlive() == true && player.getIsAlive() == true);

}

void checkIfHeroIsAliveFinal(Player& player, EnemigoFinal& enemigo) {
	if (player.getHp() <= 0) {
		player.setHp(0);
		player.setIsAlive(false);
		cout << "El heroe ha sido derrotado a manos de " <<enemigo.getName()<<".\n";
		Sleep(1500);
	}
	else {
		cout << "La vida del heroe tras el ataque de hielo de " << enemigo.getName() << " es de " << player.getHp() << ".\n";
		player.setIsAlive(true);
		Sleep(2000);
	}
}

void checkIfEnemyIsAliveFinal(Player& player, EnemigoFinal& enemigo) {
	if (enemigo.getHp() <= 0)
	{
		cout << "EL HEROE HA DERROTADO AL ENEMIGO FINAL " << enemigo.getName() << "\n";
		cout << player.getName() << " es el vencedor.\n";
		enemigo.setIsAlive(false);
		Sleep(1500);
	}
	else
	{
		cout << "La vida del enemigo tras el ataque es de " << enemigo.getHp() <<"\n";
		cout << "Pulsa 0 para continuar: ";
		cin >> continuar;
		Sleep(750);
	}
}

void batallaFinal(EnemigoFinal& enemigo, Player& player) {
	Sleep(1500);
	system("CLS");
	tituloBatallaFinal();
	cout << "\nHas llegado a la guarida pero te estaba esperando un " << RED << "enemigo" << RESET << " inesperado.\n";
	cout << "\nHas tenido suerte y te has encontrado un " <<GREEN << "botiquin" << RESET << " en la entrada de la guarida\n";
	cout << "\nVa a comenzar una gran batalla entre el heroe " << player.getName() << " y " << enemigo.getName() << ".\n";
	cout << "\nVas a poder atacar tu primero al " << RED << "enemigo" << RESET << " porque te lo has encontrado durmiendo en la entrada de tu guarida.\n";
	cout << "\nPulsa 0 para continuar\n";
	cin >> continuar;
	do
	{
		system("CLS");
		tituloBatallaFinal();
		//ataque enemigo
		int numRandom1 = rand() % 4 + 1;
		int numRandom2 = rand() % 4 + 1;
		int ataque = rand() % 2 + 1;
		if (ataque==1)
		{
			cout << "El ataque que va a realizar el " << RED << "enemigo" << RESET << " " << enemigo.getName() << " sera " << BLUE << " EL ATAQUE DE HIELO." << RESET << "\n";
			cout << "Ahora veremos si el ataque del " << RED << "enemigo" << RESET << " te alcanza...\n";
			cout << "Pulsa 0 para continuar:";
			cin >> continuar;
			cout << "\n";
			if (numRandom1 == numRandom2)
			{
				cout << "\nEl ataque del " << RED << "enemigo" << RESET << " te ha alcanzado, y este ha sido fuerte.\n";
				player.setHp(player.getHp() - enemigo.getAtaqueEspecialHielo());
				checkIfHeroIsAliveFinal(player, enemigo);		
				cout << "Pulsa 0 para continuar:";
				cin >> continuar;
				system("CLS");
				tituloBatallaFinal();
			}
			else {
				cout << "El " << RED << "enemigo" << RESET << " ha fallado el ataque de hielo y tendras la oportunidad de volver a atacar...\n";
				cout << "No te confies porque el " << RED << "enemigo" << RESET << " volvera a atacarte mas adelante...\n";
				cout << "Pulsa 0 para continuar:";
				cin >> continuar;
				system("CLS");
				tituloBatallaFinal();
			}
		}
		else if (ataque == 2) {
			cout << "El ataque que va a realizar el " << RED << "enemigo" << RESET << " " << enemigo.getName() << " sera " << RED << " EL ATAQUE DE FUEGO." << RESET << "\n";
			cout << "Ahora veremos si el ataque del " << RED << "enemigo" << RESET << " te alcanza...\n";
			cout << "Pulsa 0 para continuar:";
			cin >> continuar;
			cout << "\n";
			if (numRandom1 == numRandom2)
			{
				cout << "\nEl ataque del " << RED << "enemigo" << RESET << " te ha alcanzado, y este ha sido fuerte.\n";
				player.setHp(player.getHp() - enemigo.getAtaqueEspecialFuego());
				checkIfHeroIsAliveFinal(player,enemigo);
				cout << "Pulsa 0 para continuar:";
				cin >> continuar;
				system("CLS");
				tituloBatallaFinal();
			}
			else {
				cout << "El " << RED << "enemigo" << RESET << " ha fallado el ataque de fuego y tendras la oportunidad de volver a atacar...\n";
				cout << "No te confies porque el " << RED << "enemigo" << RESET << " volvera a atacarte mas adelante...\n";
				cout << "Pulsa 0 para continuar:";
				cin >> continuar;
				system("CLS");
				tituloBatallaFinal();
			}
		}
		//ataque heroe
		if (player.getIsAlive() == true) {
			cout << "Te toca atacar al " << RED << "enemigo" << RESET << " "<<enemigo.getName()<<"\n";
			cout << "Pulsa 0 para atacar al enemigo:";
			cin >> continuar;
			enemigo.setHp(enemigo.getHp() - player.getAttack());
			checkIfEnemyIsAliveFinal(player, enemigo);
		}

		
		
	} while (enemigo.getIsAlive() == true && player.getIsAlive() == true);
}

void imprimirMapa(char mapa[MAP_HEIGHT][MAP_WIDTH]) {
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			std::cout << mapa[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

bool checkIfHeroIsAlive(Player& player) {
	if (player.getHp()<=0)
	{
		player.setHp(0);
		player.setIsAlive(false);
		return false;
	}
	else
	{
		player.setIsAlive(true);
		return true;
	}
}

void randomPosicionesEnemigos() {
	int randPosFinal = 1 + rand() % (10 - 1);
	enemigoFinal.setPosX(randPosFinal);

	int randPosXFinalenemigo1 = 1 + rand() % (9 - 1);
	int randPosYFinalenemigo1 = 1 + rand() % (9 - 1);
	
	int randPosXFinalenemigo2 = 1 + rand() % (9 - 1);
	int randPosYFinalenemigo2 = 1 + rand() % (9 - 1);
	

	int randPosXFinalenemigo3 = 1 + rand() % (9 - 1);
	int randPosYFinalenemigo3 = 1 + rand() % (9 - 1);


	int randPosXFinalenemigo4 = 1 + rand() % (9 - 1);
	int randPosYFinalenemigo4 = 1 + rand() % (9 - 1);

	int randPosXFinalenemigo5 = 1 + rand() % (9 - 1);
	int randPosYFinalenemigo5 = 1 + rand() % (9 - 1);

	int randPosXFinalenemigo6 = 1 + rand() % (9 - 1);
	int randPosYFinalenemigo6 = 1 + rand() % (9 - 1);
}


int main() {
	int modos = 0;
	int numEnemigos = 0;
	//hacer randoms de posiciones para enemigos y player para compararlos y saber si estan ahi, mirar pruebateclas.
	randomPosicionesEnemigos();



	int opcion = 0;
	srand((unsigned)time(NULL));

	int numBotiquin = 0;
	titulo();
	explicacionJuego();
	cout << "En que modo de juego quieres jugar?\n";
	cout << "1. Modo facil.\n";
	cout << "2. Modo normal.\n";
	cout << "3. Modo dificil.\n";
	cin >> modos;
	Sleep(1500);
	system("CLS");
	Enemigo* enemigos = new Enemigo[50];
	Botiquin* botiquines = new Botiquin[50];
	if (modos==1)
	{
		enemigos = variosEnemigos(15);
		for (size_t i = 0; i <=14 ; i++)
		{
			int rand1 = 1 + rand() % (50 - 1);
			int rand2= 1 + rand() % (30 - 1);
			enemigos[i].setPosX(rand1);
			enemigos[i].setPosY(rand2);
		}
		botiquines = variosBotiquines(10);
	}
	else if (modos == 2)
	{
		enemigos = variosEnemigos(25);
		for (size_t i = 0; i <= 24; i++)
		{
			int rand1 = 1 + rand() % (50 - 1);
			int rand2 = 1 + rand() % (30 - 1);
			enemigos[i].setPosX(rand1);
			enemigos[i].setPosY(rand2);
			
		}
		botiquines = variosBotiquines(20);
	}
	else if (modos == 3)
	{
		enemigos = variosEnemigos(35);
		for (size_t i = 0; i <= 34; i++)
		{
			int rand1 = 1 + rand() % (50 - 1);
			int rand2 = 1 + rand() % (30 - 1);
			enemigos[i].setPosX(rand1);
			enemigos[i].setPosY(rand2);
			
		}
		botiquines = variosBotiquines(30);
	}
	else
	{
		cout << "No has introducido un modo de juego valido, se jugara en modo normal.\n";
		enemigos = variosEnemigos(25);
		for (size_t i = 0; i <= 24; i++)
		{
			int rand1 = 1 + rand() % (50 - 1);
			int rand2 = 1 + rand() % (30 - 1);
			enemigos[i].setPosX(rand1);
			enemigos[i].setPosY(rand2);
		}
		botiquines = variosBotiquines(20);
	}
	if (modos==1)
	{
		numEnemigos = 7;
		numBotiquin = 10;
	}
	if (modos == 2) {
		numEnemigos  =14;
		numBotiquin = 20;
	}
	if (modos == 3)
	{
		numEnemigos  =21;
		numBotiquin = 30;
	}
	else {
		numEnemigos  =14;
		numBotiquin = 20;
	}
		


	string namePlayer;
	cout << "Introduce el nombre del heroe:";
	cin >> namePlayer;

	int posInicialPersX = 1 + rand() % (10 - 1);
	player.setPosX(posInicialPersX);
	int posInicialPersY = 1 + rand() % (10 - 1);
	player.setPosX(posInicialPersY);

	char mapa[MAP_HEIGHT][MAP_WIDTH] = {};
	int valor = 15 + rand() % (15 - 1);
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			if (i == 0 || i == MAP_HEIGHT - 1 || j == 0 || j == MAP_WIDTH - 1) {
				mapa[i][j] = '#';  // Bordes del mapa
			}
			else {
				mapa[i][j] = '-';  // Relleno del mapa
			}
			if (j==16 || j==33)
			{
				mapa[i][j] = '#';
			}
			if (i==15)
			{
				mapa[i][j] = '#';
			}
			if(j==16 && i==12)
			{
				mapa[i][j] = '-';
			}
			if (j == 33 && i == 5)
			{
				mapa[i][j] = '-';
			}
			if (j == 47 && i == 15)
			{
				mapa[i][j] = '-';
			}
			if (j == 33 && i == 27)
			{
				mapa[i][j] = '-';
			}
			if (j == 16 && i == 18)
			{
				mapa[i][j] = '-';
			}

			
				
			
			
			
		}
	}

	mapa[valor][0] = '@';

	
	enemigoFinal.setPosX(0);
	enemigoFinal.setPosY(valor);

	titulo();
	//Bucle del juego.
	bool juegoTerminado = false;
	while (!juegoTerminado) {
		titulo();
		cout << "\n\n";
		
		// Imprimir el mapa
		imprimirMapa(mapa);

		// Obtener la entrada del usuario
		char tecla = _getch();

		// Borrar la posición anterior del jugador en el mapa
		mapa[player.getPosY()][player.getPosX()] = ' ';

		// Mover el jugador según la tecla presionada
		switch (tecla) {
		case 'w':
		case 'W':
			if (mapa[player.getPosY() - 1][player.getPosX()] != '#')
				player.setPosY(player.getPosY()-1);
			for (size_t i = 0; i < numEnemigos; i++)
			{
				if (player.getPosX() == enemigos[i].getPosX() && player.getPosY() == enemigos[i].getPosY())
				{
					BatallaEnemigoComun(enemigos[i], player);
					if (player.getHp() <= 0)
					{
						juegoTerminado = true;
					}
				}
				
			}
			for (size_t i = 0; i < numBotiquin; i++)
			{
				if (player.getPosX() == botiquines[i].getPosX() && player.getPosY() == botiquines[i].getPosY())
				{
					cout << "Te has encontrado un botiquin, tu vida se va a restablecer al maximo\n";
					player.setHp(100);
					cout << "Pulsa 0 para continuar:";
					cin >> continuar;

				}
			}
			if (player.getPosX() == enemigoFinal.getPosX() && player.getPosY() == enemigoFinal.getPosY())
			{
				batallaFinal(enemigoFinal,player); 
				if (player.getHp() <= 0)
				{
					juegoTerminado = true;
				}
				else if (enemigoFinal.getHp() <= 0)
				{
					juegoTerminado = true;
				}
			}
			break;
		case 'a':
		case 'A':
			if (mapa[player.getPosY()][player.getPosX() - 1] != '#')
				player.setPosX(player.getPosX()-1);
			for (size_t i = 0; i < numEnemigos; i++)
			{
				if (player.getPosX() == enemigos[i].getPosX() && player.getPosY() == enemigos[i].getPosY())
				{
					BatallaEnemigoComun(enemigos[i], player);
					if (player.getHp() <= 0)
					{
						juegoTerminado = true;
					}
				}
				
			}
			for (size_t i = 0; i < numBotiquin; i++)
			{
				if (player.getPosX() == botiquines[i].getPosX() && player.getPosY() == botiquines[i].getPosY())
				{
					cout << "Te has encontrado un botiquin, tu vida se va a restablecer al maximo\n";
					player.setHp(100);
					cout << "Pulsa 0 para continuar:";
					cin >> continuar;

				}
			}
			if (player.getPosX() == enemigoFinal.getPosX() && player.getPosY() == enemigoFinal.getPosY())
			{
				batallaFinal(enemigoFinal, player);
				if (player.getHp() <= 0)
				{
					juegoTerminado = true;
				}
				else if (enemigoFinal.getHp() <= 0)
				{
					juegoTerminado = true;
				}
			}
			break;
		case 's':
		case 'S':
			if (mapa[player.getPosY() + 1][player.getPosX()] != '#')
				player.setPosY(player.getPosY() + 1);
			for (size_t i = 0; i < numEnemigos; i++)
			{
				if (player.getPosX() == enemigos[i].getPosX() && player.getPosY() == enemigos[i].getPosY())
				{
					BatallaEnemigoComun(enemigos[i], player);
					if (player.getHp() <= 0)
					{
						juegoTerminado = true;
					}
				}
				
			}
			for (size_t i = 0; i < numBotiquin; i++)
			{
				if (player.getPosX() == botiquines[i].getPosX() && player.getPosY() == botiquines[i].getPosY())
				{
					cout << "Te has encontrado un botiquin, tu vida se va a restablecer al maximo\n";
					player.setHp(100);
					cout << "Pulsa 0 para continuar:";
					cin >> continuar;

				}
			}
			if (player.getPosX() == enemigoFinal.getPosX() && player.getPosY() == enemigoFinal.getPosY())
			{
				batallaFinal(enemigoFinal, player);
				if (player.getHp() <= 0)
				{
					juegoTerminado = true;
				}
				else if (enemigoFinal.getHp() <= 0)
				{
					juegoTerminado = true;
				}
			}
			break;
		case 'd':
		case 'D':
			if (mapa[player.getPosY()][player.getPosX() + 1] != '#')
				player.setPosX(player.getPosX() + 1);
			for (size_t i = 0; i < numEnemigos; i++)
			{
				if (player.getPosX() == enemigos[i].getPosX() && player.getPosY() == enemigos[i].getPosY())
				{
					BatallaEnemigoComun(enemigos[i], player);
					if (player.getHp() <= 0)
					{
						juegoTerminado = true;
					}
				}
				
			}
			for (size_t i = 0; i < numBotiquin; i++)
			{
				if (player.getPosX() == botiquines[i].getPosX() && player.getPosY() == botiquines[i].getPosY())
				{
					cout << "Te has encontrado un botiquin, tu vida se va a restablecer al maximo\n";
					player.setHp(100);
					cout << "Pulsa 0 para continuar:";
					cin >> continuar;

				}
			}
			if (player.getPosX() == enemigoFinal.getPosX() && player.getPosY() == enemigoFinal.getPosY())
			{
				batallaFinal(enemigoFinal, player);
				if (player.getHp() <= 0)
				{
					juegoTerminado = true;
				}
				else if (enemigoFinal.getHp() <= 0)
				{
					juegoTerminado = true;
				}
			}
			break;
		case 'q':
		case 'Q':
			juegoTerminado = true;
			break;
		}

		// Colocar al jugador en la nueva posición en el mapa
		mapa[player.getPosY()][player.getPosX()] = 'P';

		// Limpiar la consola
		system("cls");
	}
	if (player.getHp()<=0)
	{
		cout << "El heroe ha sido derrotado, has perdido.";
		Sleep(2500);

	}
	else if (enemigoFinal.getHp() <= 0) {
		cout <<GREEN<< "\nEl enemigo final ha sido derrotado, ERES EL GANADOR Y HAS LLEGADO A TU DESTINO"<<RESET <<"\n\n\n";
	}


	return 0;
}
