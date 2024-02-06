#include <iostream>
#include "../include/snake.hpp"

// Up 
void Game::mvUp() {
	yHead--;

	yDirection = -1;
	xDirection = 0;

	if(yHead < 1) {
		yHead = 18;
	}
}

// Down
void Game::mvDown(){
	yHead++;

	yDirection = 1;
	xDirection = 0;

	if(yHead > 18) {
		yHead = 1;
	}
}

// Left
void Game::mvLeft() {
	xHead--;

	xDirection = -1;
	yDirection = 0;

	if(xHead < 1) {
		xHead = 48;
	}
}

// Right
void Game::mvRight() {
	xHead++;

	xDirection = 1;
	yDirection = 0;

	if(xHead > 48) {
		xHead = 1;
	}
}

void Game::getUserInput() {
	keypad(Map, TRUE);
	int choice = wgetch(Map);

	switch(choice) {
		case KEY_UP:
			if(yDirection != 1) {
				mvUp();
			}
			break;
		case KEY_DOWN:
			if(yDirection != -1) {
				mvDown();
			}
			break;
		case KEY_LEFT:
			if(xDirection != 1) {
				mvLeft();
			}
			break;
		case KEY_RIGHT:
			if(xDirection != -1) {
				mvRight();
			}
			break;
		default:
			break;
	}

}
