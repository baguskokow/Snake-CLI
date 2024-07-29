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
#include <stdlib.h>
#include "../include/snake.hpp"

// Save Score
void Game::saveData() {
	std::ofstream highScore;
	std::string command = "touch " + workDir + "score.txt";

	highScore.open(workDir + "score.txt", std::ios::out);

	if(highScore.is_open()) {
		highScore << point;
	} else {
		system(command.c_str());
	}

	highScore.close();
}

// Read
void Game::readData() {
	std::ifstream bestScore(workDir + "score.txt");
	std::string command = "touch " + workDir + "score.txt";
	std::string secondCommand = "echo 0 > " + workDir + "score.txt";

	if(bestScore.is_open()) {
		getline(bestScore, highScoreString);
		bestScore.close();
	} else {
		highScoreString = '0';
		system(command.c_str());
		system(secondCommand.c_str());
	}
	
	highestScore = std::stoi(highScoreString);
}

// Reset Data
void Game::resetData() {
	this->highestScore = 0;
	std::ofstream highScore;
	std::string command = "touch " + workDir + "score.txt";

	highScore.open(workDir + "score.txt", std::ios::out);
	if(highScore.is_open()) {
		highScore << highestScore;
	} else {
		system(command.c_str());
	}

	highScore.close();
}

// Save Skin
void Game::saveDataSkin() {
	std::ofstream skin;
	std::string command = "touch " + workDir + "skin.txt";
	std::string secondCommand = "echo 1 > " + workDir + "skin.txt";

	skin.open(workDir + "skin.txt", std::ios::out);
	if(skin.is_open()) {
		skin << skinSelected;
	} else {
		system(command.c_str());
		system(secondCommand.c_str());
	}

	skin.close();
}

// Read Skin
void Game::readDataSkin() {
	std::ifstream skin(workDir + "skin.txt");
	std::string command = "touch " + workDir + "skin.txt";
	std::string secondCommand = "echo 1 > " + workDir + "skin.txt";
	std::string skinSelectedString;

	if(skin.is_open()) {
		getline(skin, skinSelectedString);
	} else {
		system(command.c_str());
		system(secondCommand.c_str());
		skinSelectedString = '1';
	}
	
	skin.close();
	
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

	Money.open(workDir + "money.txt", std::ios::out);

	Money << this->money;
	Money.close();
}

// Read Data Money
void Game::readDataMoney() {
	std::ifstream Money(workDir + "money.txt");

	if(Money.is_open()) {
		getline(Money, moneyString);
		Money.close();
	} else {
		moneyString = '0';
	}
	
	this->money = std::stoi(moneyString);
}

// Read Collection Skin
void Game::readDataCollectionSkin() {
	std::string lineString;
	int lineCount = 0;
	std::string command = "touch " + workDir + "collection-skin.txt";
	std::string secondCommand = "echo Ziro > " + workDir + "collection-skin.txt";

	std::ifstream Collection(workDir + "collection-skin.txt");
	std::vector<std::string> skinCollectionTemporary;

	if(Collection.is_open()) {
		while(std::getline(Collection, lineString)) {
			skinCollectionTemporary.push_back(lineString);
			lineCount++;
		}
	} else {
		system(command.c_str());
		system(secondCommand.c_str());
		skinCollectionTemporary.push_back(lineString);
		lineCount++;
	}

	Collection.close();

	// Set value as sequentialy at every index skinCollection array, referenced by skinIndex array
	for(int i = 0; i < lineCount; i++) {
		for(int j = 0; j < skinIndex.size(); j++) {
			if(skinIndex.at(j) == skinCollectionTemporary.at(i)) {
				this->skinCollection[j] = skinIndex.at(j);
				break;
			}
		}
	}
}

// Save data collection skin after buy a skin at shop
void Game::saveDataCollectionSkin(std::string skinWantToBuy) {
	std::ofstream Collection;
	std::string command = "touch " + workDir + "collection-skin.txt";
	std::string secondCommand = "echo Ziro > " + workDir + "collection-skin.txt";

	Collection.open(workDir + "collection-skin.txt", std::ios::app);

	if(Collection.is_open()) {
		Collection << skinWantToBuy;
		Collection << "\n";
	} else {
		system(command.c_str());
		system(secondCommand.c_str());
	}

	Collection.close();
}
