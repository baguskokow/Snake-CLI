#include <iostream>
#include "../include/snake.hpp"

// Update Score when snake eat the food
void Game::UpdateScore(WINDOW* Score, int pointNow) {
	if(this->xRandom == xHead && this->yRandom == yHead) {
		++pointNow; //Update Point
		this->point = pointNow; 
		this->yRandom = 0;
		this->xRandom = 0;
		this->bodyLength += 1; //Update Body Length
	}
	
	std::string pointString = std::to_string(point);
	mvwprintw(Score, 2, 7.5, pointString.c_str());
	wrefresh(Score);
}
