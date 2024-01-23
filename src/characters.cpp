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
