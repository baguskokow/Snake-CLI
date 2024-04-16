/* #########################################
 *	
 *	File: score.cpp
 *
 *	Author : Bagus Koko Wibawanto
 *
 * ########################################
 *
 * */

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

// Show Best Score
void Game::ShowBestScore() {
	refresh();
	curs_set(FALSE);
	noecho();
	box(BestScoreWindow, 0, 0);
	wrefresh(BestScoreWindow);
	keypad(BestScoreWindow, TRUE);
	readData();
	bool exit = false;

	while(exit != true) {
		mvwprintw(BestScoreWindow, 0, 0, "[ q ]");
		mvwprintw(BestScoreWindow, 2, 7, "Best Score");
		mvwprintw(BestScoreWindow, 4, 11, highScoreString.c_str());

		int choice = wgetch(BestScoreWindow);

		switch(choice) {
			case 'q':
				exit = true;
				break;
			default:
				break;
		}
	
		box(BestScoreWindow, 0, 0);
	}
}
