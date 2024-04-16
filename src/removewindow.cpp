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

void Game::removeScoreWindow() {
	werase(Score);
	wrefresh(Score);
}
