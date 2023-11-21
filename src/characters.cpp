#include <iostream>
#include <algorithm>
#include "../include/snake.hpp"

int Characters::RandomPositionVertical() {
	std::srand(time(0));
	int verticalLength = 18;
	int randomVertical;

	int x = std::rand() % verticalLength;
	if(x < 2) {
		randomVertical = x + 1;
	} else {
		randomVertical = x;
	}
	
	return randomVertical;
}

int Characters::RandomPositionHorizontal() {
	std::srand(time(0));
	int horizontalLength = 48;
	int randomHorizontal;

	int y = std::rand() % horizontalLength;
	
	if(y < 2) {
		randomHorizontal = y + 1;
	} else {
		randomHorizontal = y;
	}
	
	return randomHorizontal;
}

void Characters::getFood(WINDOW* Map) {
	mvwprintw(Map, Characters::RandomPositionVertical(), Characters::RandomPositionHorizontal(), this->Food);
}

int start() {
	int headPosition = 4;
//	std::srand(time(0));
	return std::rand() % headPosition;
}

// Fix : Top & Bottom Position are over the Map Window

void Characters::getSnake(WINDOW* Map) {
	int left = 0;
	int right = 1;
	int top = 3;
	int bottom = 4;

	if(start() == left) {
		std::reverse(this->Snake.begin(), this->Snake.end());
		std::string strSnake(this->Snake.begin(), this->Snake.end());
		mvwprintw(Map, Characters::RandomPositionVertical(), Characters::RandomPositionHorizontal(), strSnake.c_str());
	} else if(start() == right) {
		std::string strSnake(this->Snake.begin(), this->Snake.end());
		mvwprintw(Map, Characters::RandomPositionVertical(), Characters::RandomPositionHorizontal(), strSnake.c_str());
	} else if(start() == top){
		std::reverse(this->Snake.begin(), this->Snake.end());
		std::string strSnake(this->Snake.begin(), this->Snake.end());
		for(int i = 0; i < 4; i++) {
			mvwprintw(Map, Characters::RandomPositionVertical() + i, Characters::RandomPositionHorizontal(), "%c", this->Snake.at(i));
		}
		
	} else {
		std::string strSnake(this->Snake.begin(), this->Snake.end());
		for(int i = 0; i < 4; i++) {
			mvwprintw(Map, Characters::RandomPositionVertical() + i, Characters::RandomPositionHorizontal(), "%c", this->Snake.at(i));
		}

	}

}

// Fix remove Snake Characters !

void Characters::removeSnake(WINDOW* Map) {
	int left = 0;
	int right = 1;
	int top = 3;
	int bottom = 4;

	if(start() == left) {
		std::reverse(this->Snake.begin(), this->Snake.end());
		std::string strSnake(this->Snake.begin(), this->Snake.end());
		mvwprintw(Map, Characters::RandomPositionVertical(), Characters::RandomPositionHorizontal(), "    ");
	} else if(start() == right) {
		std::string strSnake(this->Snake.begin(), this->Snake.end());
		mvwprintw(Map, Characters::RandomPositionVertical(), Characters::RandomPositionHorizontal(), "    ");	
	} else if(start() == top) {
		for(int i = 0; i < 4; i++) {
			Snake.at(i) = ' ';
		}
		std::reverse(this->Snake.begin(), this->Snake.end());
		std::string strSnake(this->Snake.begin(), this->Snake.end());
		for(int i = 0; i < 4; i++) {
			mvwprintw(Map, Characters::RandomPositionVertical() + i, Characters::RandomPositionHorizontal(), "%c", this->Snake.at(i));
		}
		
	} else {
		for(int i = 0; i < 4; i++) {
			Snake.at(i) = ' ';
		}
		
		for(int i = 0; i < 4; i++) {
			mvwprintw(Map, Characters::RandomPositionVertical() + i, Characters::RandomPositionHorizontal(), "%c", this->Snake.at(i));
		}

	}

}
