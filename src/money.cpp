/* #########################################
 *	
 *	File: menu.cpp
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
	refresh();
	readDataMoney();
	werase(CoinMap);
	box(CoinMap, 0, 0);
	noecho();

	mvwprintw(CoinMap, 1, 4, "[ $      ");
	mvwprintw(CoinMap, 1, 9, moneyString.c_str());
	mvwprintw(CoinMap, 1, 13, " ]");

	refresh();
	wrefresh(CoinMap);
}

// Reward 
int Game::rewardMoney() {
	int reward;
	if(point < 10) {
		reward = 0;
	} else if(point < 20) {
		reward = 1;
	} else if(point < 30) {
		reward = 2;
	} else if(point < 40) {
		reward = 3;
	} else if(point < 50) {
		reward = 4;
	} else if(point < 60) {
		reward = 5;
	} else if(point < 70) {
		reward = 6;
	} else if(point < 80) {
		reward = 7;
	} else if(point < 90) {
		reward = 8;
	} else if(point < 100) {
		reward = 9;
	} else {
		reward = 10;
	}
	return reward;
}

// Payment Process
bool Game::PayProcess(int moneyCurrent, int cost) {
	bool success;
	int resultMoney;

	if (moneyCurrent <= cost) {
		success = false;
	} else {
		resultMoney = moneyCurrent - cost;
		this->money = resultMoney;
		success = true;
	}
	return success;
}

bool Game::Pay(std::string skinName) {
	int cost;
	if(skinName == "Qi") {
		cost = 35;
	} else if(skinName == "Ate") {
		cost = 115;
	} else if(skinName == "The G") {
		cost = 75;
	} else {
		cost = 0;
	}
	bool success;

	if(PayProcess(this->money, cost) == true) {
		success = true;
		saveDataCollectionSkin(skinName);
	} else {
		success = false;
	}

	return success;
}
