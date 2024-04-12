/* #########################################
 *	
 *	File: characters.cpp
 *
 *	Author : Bagus Koko Wibawanto
 *
 *	Version : 1.0
 *
 * ########################################
 *
 * */

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

void Game::controlSnakeHead() {
	if(xHead > 48) {
		xHead = 1;
	} else if(xHead < 1) {
		xHead = 48;
	} else if(yHead > 18) {
		yHead = 1;
	} else if(yHead < 1) {
		yHead = 18;
	}
}

int Game::xFoodRandom() {
	std::srand(time(0));
	int xMax = 50 - 2;

	int xRandom = std::rand() % xMax;
	
	if(xRandom < 1) {
		return xRandom + 1;
	} else if(xRandom > 49) {
		return xRandom - 1;
	} else {
		return xRandom;
	}
}

int Game::yFoodRandom() {
	std::srand(time(0));
	int yMax = 20 - 2;
	
	int yRandom = std::rand() % yMax;
	
	if(yRandom < 1) {
		return yRandom + 1;
	} else if(yRandom > 19) {
		return yRandom - 1;
	} else {
		return yRandom;
	}
}

void Game::generateFood(WINDOW* Map, int yFood, int xFood) {
	mvwaddch(Map, yFood, xFood, Food);
}

void Game::SpawnFood() {
	if(yRandom == 0 && xRandom == 0) {
		yRandom = yFoodRandom();
		xRandom = xFoodRandom();
		generateFood(Map, yRandom, xRandom);
	} else {
		// Ensure the food location is not same as the snake character
		for(int i = bodyLength; i > 0; --i) {
			while(yRandom == yBody[i] && xRandom == xBody[i]) {
				if(yRandom == yBody[i]) {
					yRandom = yFoodRandom();
				} else if(xRandom == xBody[i]){
					xRandom = xFoodRandom();
				}
			}
		}
		generateFood(Map, yRandom, xRandom);
	}
}
