#include <iostream>
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
