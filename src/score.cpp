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
void Game::ShowHighestScore() {
	removeMenuWindow();
	refresh();
	curs_set(FALSE);
	noecho();
	box(HighestScoreWindow, 0, 0);
	wrefresh(HighestScoreWindow);
	keypad(HighestScoreWindow, TRUE);
	readData();
	bool exit = false;

	while(exit != true) {
		mvwprintw(HighestScoreWindow, 0, 0, "[ q ]");
		mvwprintw(HighestScoreWindow, 0, 6, "[ r ]");
		mvwprintw(HighestScoreWindow, 2, 7, "High Score");
		mvwprintw(HighestScoreWindow, 4, 11, highScoreString.c_str());
		refresh();

		int choice = wgetch(HighestScoreWindow);

		switch(choice) {
			case 'q':
				exit = true;
				break;
			case 'r':
				showConfirmPopUp("Are you sure to reset the high score?", "resetData");
				break;
			default:
				break;
		}
	
		box(HighestScoreWindow, 0, 0);
	}
}
