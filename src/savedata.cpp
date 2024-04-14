/* #########################################
 *	
 *	File: savedata.cpp
 *
 *	Author : Bagus Koko Wibawanto
 *
 *	Version : 1.0
 *
 * ########################################
 *
 * */

#include <iostream>
#include <fstream>
#include "../include/snake.hpp"

// Save Score
void Game::saveData() {
	//std::string homeDirectory = getenv("HOME");
	std::ofstream bestScore;

	bestScore.open("savedata/score.txt", std::ios::out);

	bestScore << point;
	bestScore.close();
}

// Read
void Game::readData() {
	std::ifstream bestScore("savedata/score.txt");

	if(bestScore.is_open()) {
		getline(bestScore, highScoreString);
		bestScore.close();
	} else {
		highScoreString = '0';
	}
	
	highestScore = std::stoi(highScoreString);
}
