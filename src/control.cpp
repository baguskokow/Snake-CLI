#include <iostream>
#include "../include/snake.hpp"

// Up 
void Game::mvUp() {
	yHead--;
	if(yHead < 1) {
		yHead = 18;
	}
}

// Down
void Game::mvDown(){
	yHead++;
	if(yHead > 18) {
		yHead = 1;
	}
}

// Left
void Game::mvLeft() {
	xHead--;
	if(xHead < 1) {
		xHead = 48;
	}
}

// Right
void Game::mvRight() {
	xHead++;
	if(xHead > 48) {
		xHead = 1;
	}
}
