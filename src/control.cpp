/* #########################################
 *	
 *	File: control.cpp
 *
 *	Author : Bagus Koko Wibawanto
 *
 * ########################################
 *
 * */

#include <iostream>
#include "../include/snake.hpp"

// Up 
void Game::mvUp() {
	yDirection = -1;
	xDirection = 0;
}

// Down
void Game::mvDown(){
	yDirection = 1;
	xDirection = 0;
}

// Left
void Game::mvLeft() {
	xDirection = -1;
	yDirection = 0;
}

// Right
void Game::mvRight() {
	xDirection = 1;
	yDirection = 0;
}

// Direction Control
void Game::directionControl() {
	if(yDirection == -1 && xDirection == 0) {
		yHead--;
	} else if(yDirection == 1 && xDirection == 0) {
		yHead++;
	} else if(yDirection == 0 && xDirection == 1) {
		xHead++;
	} else if (yDirection == 0 && xDirection == -1) {
		xHead--;
	}
}
