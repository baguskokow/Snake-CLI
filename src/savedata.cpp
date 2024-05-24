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

// Save Skin
void Game::saveDataSkin() {
	std::ofstream skin;

	skin.open("savedata/skin.txt", std::ios::out);

	skin << skinSelected;
	skin.close();
}

// Read Skin
void Game::readDataSkin() {
	std::ifstream skin("savedata/skin.txt");
	std::string skinSelectedString;

	if(skin.is_open()) {
		getline(skin, skinSelectedString);
		skin.close();
	} else {
		skinSelectedString = '2';
	}
	
	skinSelected = std::stoi(skinSelectedString);

	// Apply Skin When Start the Game
  if(skinSelected == 0) {
          SnakeHead = 'Q';
  } else if (skinSelected == 1) {
          SnakeHead = '0';
  } else if (skinSelected == 2) {
          SnakeHead = '@';
  } else if (skinSelected == 3) {
          SnakeHead = 'G';
  } else {
          SnakeHead = 'U';
  }
}

// Save Data Money
void Game::saveDataMoney() {
	std::ofstream Money;

	Money.open("savedata/money.txt", std::ios::out);

	Money << money;
	Money.close();
}

// Read
void Game::readDataMoney() {
	std::ifstream Money("savedata/money.txt");

	if(Money.is_open()) {
		getline(Money, moneyString);
		Money.close();
	} else {
		moneyString = '0';
	}
	
	money = std::stoi(moneyString);
}
