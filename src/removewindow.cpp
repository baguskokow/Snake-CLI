/* #########################################
 *	
 *	File: removewindow.cpp
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
	werase(HighestScoreWindow);
	wrefresh(HighestScoreWindow);
	box(HighestScoreWindow, 0, 0);
}

void Game::removeShopWindow() {
	werase(ShopWindow);
	box(ShopWindow, 0, 0);
	wrefresh(ShopWindow);
}

void Game::removeMenuWindow() {
	werase(MenuWindow);
	box(MenuWindow, 0, 0);
	wrefresh(MenuWindow);
}
