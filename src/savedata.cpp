/* #########################################
 *	
 *	File: savedata.cpp
 *
 *	Author : Bagus Koko Wibawanto
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
	std::ofstream highScore;

	highScore.open("savedata/score.txt", std::ios::out);

	highScore << point;
	highScore.close();
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

// Reset Data
void Game::resetData() {
	this->highestScore = 0;
	std::ofstream highScore;

	highScore.open("savedata/score.txt", std::ios::out);

	highScore << highestScore;
	highScore.close();
}
