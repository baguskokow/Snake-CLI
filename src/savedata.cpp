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
int Game::readData() {
	std::ifstream bestScore("savedata/score.txt");
	std::string highScore;

	if(bestScore.is_open()) {
		getline(bestScore, highScore);
		bestScore.close();
	} else {
		highScore = '0';
	}
	
	return highestScore = std::stoi(highScore);
}
