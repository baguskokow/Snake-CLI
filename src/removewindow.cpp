/* #########################################
 *	
 *	File: control.cpp
 *
 *	Author : Bagus Koko Wibawanto
 *
 * ########################################
 *
 * */

#include <iostream>
#include "../include/snake.hpp"

// Remove Score Window
void Game::removeScoreWindow() {
	werase(Score);
	wrefresh(Score);
}

// Remove Confirm Window
void Game::removeConfirmWindow() {
	werase(ConfirmWindow);
	wrefresh(ConfirmWindow);
}

// Remove Success Window
void Game::removeSuccessWindow() {
	werase(SuccessWindow);
	wrefresh(SuccessWindow);
	box(ConfirmWindow, 0, 0);
}

void Game::removeHighScoreWindow() {
	werase(BestScoreWindow);
	wrefresh(BestScoreWindow);
	box(BestScoreWindow, 0, 0);
}
