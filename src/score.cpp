#include <iostream>
#include "../include/snake.hpp"

void Game::UpdateScore(WINDOW* Score, int point) {
	if(xHead == xRandom && yHead == yRandom) {
		point += 1;
		std::string pointString = std::to_string(point);
		mvwprintw(Score, 2, 7.5, pointString.c_str());
		yRandom = 0;
		xRandom = 0;
	} else {
		std::string pointString = std::to_string(point);
		mvwprintw(Score, 2, 7.5, pointString.c_str());
	}
}
