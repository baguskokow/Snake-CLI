/* #########################################
 *	
 *	File: characters.cpp
 *
 *	Author : Bagus Koko Wibawanto
 *
 * ########################################
 *
 * */

#include <iostream>
#include <algorithm>
#include "../include/snake.hpp"


// Random X position of Snake Head
int Game::xHeadRandom() {
	std::srand(time(0));
	int xMax = 50 - 10;

	int xRandom = std::rand() % xMax;
	
	if(xRandom < 5) {
		return xRandom + 1;
	} else if(xRandom > 42) {
		return xRandom - 5;
	} else {
		return xRandom;
	}
}

// Random Y position
int Game::yHeadRandom() {
	std::srand(time(0));
	int yMax = 20 - 10;
	
	int yRandom = std::rand() % yMax;
	
	if(yRandom < 5) {
		return yRandom + 1;
	} else if(yRandom > 12) {
		return yRandom - 4;
	} else {
		return yRandom;
	}
}

// Inisialization Start Position
void Game::startPosition() {
	xBody.resize(1000);
	yBody.resize(1000);
	
	for(int i = 0; i < bodyLength; ++i) {
		xBody.at(i) = xHead - i - 1;
		yBody.at(i) = yHead;
	}
}

// Update Position Snake
void Game::UpdatePosition() {
	for(int i = bodyLength - 1; i > 0; --i) {
		xBody.at(i) = xBody.at(i - 1);
		yBody.at(i) = yBody.at(i - 1);
	}

	xBody.at(0) = xHead;
	yBody.at(0) = yHead;
}

// Show Character at Map Window
void Game::showCharacter(WINDOW* Map) {
	mvwaddch(Map, yHead, xHead, SnakeHead);

	for(int i = 1; i < bodyLength; i++) {
		mvwaddch(Map, yBody.at(i), xBody.at(i), SnakeBody);
	}
}

// Reset Snake
void Game::resetSnake() {
	point = 0;
	bodyLength = 4;

	bool checkingCollison;

	// ensure there are no more collisions between the head and the body after the game over
	do {
		startPosition();
		xBody.clear();
		yBody.clear();
		xBody.resize(1000, 0);	
		yBody.resize(1000, 0);
		xHead = xHeadRandom(); 
		yHead = xHead - 1; 
			
		for(int i = 0; i < bodyLength; i++) {
			if(xHead != xBody.at(i) && yHead != yBody.at(i)) {
				checkingCollison = true;
			} else {
				checkingCollison = false;
			}
		}
	} while (checkingCollison = false);
}


// Control the Snake Head when it exits the map
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

// Random X position
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

// Random Y position
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

// Generate Food at Map
void Game::generateFood(WINDOW* Map, int yFood, int xFood) {
	mvwaddch(Map, yFood, xFood, Food);
}

// Spawn Food
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
