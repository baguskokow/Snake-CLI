/* #########################################
 *	
 *	File: main.cpp
 *
 *	Author : Bagus Koko Wibawanto
 *
 * ########################################
 *
 * */

#include <iostream>
#include "../include/snake.hpp"

#define HEIGHT 20
#define WIDTH 50
#define WINDOWVERTICALPOSITION 0
#define WINDOWHORIZONTALPOSITION 0

int main() {
	initscr();
	const char scoreTitle[] = "[ Score ]";
	Game* Map = new Game(HEIGHT, WIDTH, WINDOWVERTICALPOSITION, WINDOWHORIZONTALPOSITION, scoreTitle);

	// Exception Handling
	try {
		if(Map->getRowTerminalSize() < 20 || Map->getColumnTerminalSize() < 50) {
			throw "Small Terminal";
		}

		Map->Menu();
		//Map->showSuccessPopUp();
		//Map->showConfirmPopUp();
		//Map->render();
//		Map->GameOver();
	//	Map->ShowPopUpGameOver();
	}

	catch(const char* error) {
		Map->~Game();
		std::cout << "Error : " << error << "\nThis game can't run on small terminal. Please resize your terminal to play the game!\n";	
	}

	delete Map;

	return 0;
}
