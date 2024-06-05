/* #########################################
 *	
 *	File: shop.cpp
 *
 *	Author : Bagus Koko Wibawanto
 *
 * ########################################
 *
 * */

#include <iostream>
#include <fstream>
#include "../include/snake.hpp"

void Game::showCoin() {
	werase(CoinMap);
	box(CoinMap, 0, 0);
	noecho();

	readDataMoney();
	mvwprintw(CoinMap, 1, 4, "[ $      ");
	mvwprintw(CoinMap, 1, 9, moneyString.c_str());
	mvwprintw(CoinMap, 1, 13, " ]");

	wrefresh(CoinMap);
}

// Reward 
void Game::rewardMoney() {
	if(point < 10) {
		money += 0;
	} else if(point < 20) {
		money += 1;
	} else if(point < 30) {
		money += 2;
	} else if(point < 40) {
		money += 3;
	} else {
		money += 4;
	}
}

bool Game::Pay(std::string skinName) {
	int Qi = 35;
	int Ate = 115;
	int TheG = 75;
	bool success;

	if(skinName == "Qi") {
		if(money <= Qi) {
			success = false;
		} else {
			money - 35;
			success = true;
		}
	} else if(skinName == "Ate") {
		if(money <= Ate) {
			success = false;
		} else {
			money - 115;
			success = true;
		}
	} else if(skinName == "The G") {
		if(money <= TheG) {
			success = false;
		} else {
			money - 75;
			success = true;
		}
	}
	return success;
}
