#include <iostream>
#include <algorithm>
#include "../include/snake.hpp"

// Inisialization Start Position
void Game::startPosition() {
	for(int i = 0; i < bodyLength; ++i) {
		xBody[i] = xHead - i - 1;
		yBody[i] = yHead;
	}
}

// Update Position Snake
void Game::UpdatePosition() {
	for(int i = bodyLength - 1; i > 0; --i) {
		xBody[i] = xBody[i - 1];
		yBody[i] = yBody[i - 1];
	}

	xBody[0] = xHead;
	yBody[0] = yHead;
}

// Show Character at Map Window
void Game::showCharacter(WINDOW* Map) {
	mvwaddch(Map, yHead, xHead, SnakeHead);

	for(int i = 1; i < bodyLength; i++) {
		mvwaddch(Map, yBody[i], xBody[i], SnakeBody);
	}
}

void Game::generateFood(WINDOW* Map) {
	std::srand(time(0));

	int xMax = 50 - 2;
	int yMax = 20 - 2;

	if(xRandom == 0 && xRandom == 0) {
		int xRandom = std::rand() % xMax;
		int yRandom = std::rand() % yMax;
	}

	if(yRandom < 1 || xRandom < 1) {
		mvwaddch(Map, yRandom + 1, xRandom + 1, Food);
	} else if(yRandom > 19 || xRandom > 49) {
		mvwaddch(Map, yRandom - 1, xRandom - 1, Food);
	} else {
		mvwaddch(Map, yRandom, xRandom, Food);
	}

}
