/* #########################################
 *	
 *	File: snake.cpp
 *
 *	Author : Bagus Koko Wibawanto
 *
 * ########################################
 *
 * */

#include <iostream>
#include <functional>
#include <vector>
#include "../include/snake.hpp"
#include <unistd.h>

Game::Game(int height, int width, int windowVerticalPosition, int windowHorizontalPosition, const char* scoreTitle) {
	this->Height = height;
	this->Width = width;

	this->WindowVerticalPosition = windowVerticalPosition;
	this->WindowHorizontalPosition = windowHorizontalPosition;

	this->ScoreTitle = scoreTitle;

	// Map Window Inisialization
	this->Map = newwin(Height, Width, WindowVerticalPosition + 2, WindowHorizontalPosition);

	// Score Window Inisialization
	this->Score = newwin(Height / 4, Width / 3, WindowVerticalPosition + 7.5, WindowHorizontalPosition + Width + 5); 
	// Ex : (20 / 4, 50 / 3, 0 + 7.5, 0 + 50 + 5)
	// 20 = Height
	// 50 = Width
	// 0 = Window Position Vertical
	// 0 = Window Position Horizontal
	// 50 Position Horizontal after Width and + 5 for space
	
	// Game Over Pop Up Window
	this->GameOverPopUp = newwin(9, 25, 6, 12);

	// Menu Window
	this->MenuWindow = newwin(20, 50, 2, 0);
	
	// Game Over Window
	this->GameOverWindow = newwin(20, 50, 2, 0);
	
	// High Score Window
	this->BestScoreWindow = newwin(8, 25, 6, 12);

	// Confirm Reset High Score
	this->ConfirmWindow = newwin(10, 41, 5, 5.5);
	
	// Success Pop Up Window
	this->SuccessWindow = newwin(7, 25, 6, 12);
	
	// Skin Preview Window
	this->SkinPreviewWindow = newwin(5, 16, 7, 25);

	// Shop Window
	this->ShopWindow = newwin(20, 50, 2, 0);

	// Skins Window
	this->QiSkinWindow = newwin(5, 16, 4, 5);
	this->ZiroSkinWindow = newwin(5, 16, 4, 28);
	this->AteSkinWindow = newwin(5, 16, 12, 5);
	this->TheGSkinWindow = newwin(5, 16, 12, 28);

	// Shadow Map
	this->ShadowMap = newwin(2, 16, 12, 25);

	// Coin Map
	this->CoinMap = newwin(2, 19, 0, 31);
	
	// Notification Pop Up Window
	this->NotificationPopUpWindow = newwin(9, 25, 6, 12);

	// Get Size
	getmaxyx(stdscr, rowTerminal, columnTerminal);

	// Title Score Window
	this->LengthScore = strlen(scoreTitle);

	this->PositionScore = ((Width / 3) - LengthScore) / 2; // Ex : ((50 / 3) - 9) / 2)
	
	// X & Y Snake Head
	this->xHead = xHeadRandom();
	this->yHead = yHeadRandom();
	readDataMoney();
}

// Get Row Size of Terminal
int Game::getRowTerminalSize() {
	return rowTerminal; 		
}

// Get Column Size of Terminal
int Game::getColumnTerminalSize() {
	return columnTerminal; 		
}

// Render the Game
bool Game::render() {
	curs_set(FALSE);
	noecho();
	werase(Map);
	werase(Score);
	keypad(Map, TRUE);
	nodelay(Map, TRUE);
	startPosition();
	bool paused = false;
	bool gameOver = false;
	bool exit = false;
	readDataSkin(); // Read Skin Selected
	bool checkingStatus;

	while(exit != true) {
		box(Map, 0, 0);
		box(Score, 0, 0);
		mvwprintw(Score, 0, PositionScore, ScoreTitle);
		controlSnakeHead();
		
		int choice = wgetch(Map);
		
		switch(choice) {
			case KEY_UP:
				if(yDirection == 1) {
					continue;
				}
				mvUp();
				break;
			case KEY_DOWN:
				if(yDirection == -1) {
					continue;
				}
				mvDown();
				break;
			case KEY_RIGHT:
				if(xDirection == -1) {
					continue;
				}
				mvRight();
				break;
			case KEY_LEFT:
				if(xDirection == 1) {
					continue;
				}
				mvLeft();
				break;
			case ' ': // Pause Game
				if(paused == false) {
					paused = true;
					mvwprintw(Map, 10, 20, "PAUSED");
				} else {
					paused = false;
				}
		}
	
		// Paused Game
		if(paused != true) {
			UpdatePosition();
			werase(Map);
			showCharacter(Map);
			directionControl();
		}
		
		SpawnFood();
		
		UpdateScore(Score, point);
		
		usleep(120000); // miliseconds
		wrefresh(Map);
		wrefresh(Score);
		
		for(int i = 0; i < bodyLength; ++i) {
			if(xHead == xBody.at(i) && yHead == yBody.at(i)) {
				gameOver = true;
			}
		}

		if(gameOver == true) {
				werase(Map);
				box(Map, 0, 0);
				wrefresh(Map);
				ShowPopUpGameOver();

				resetSnake();

				readData();
				if(point > highestScore) {
					saveData();
				}
				
				rewardMoney();
				saveDataMoney();

				if(EnsurePlayAgainOrNot(GameOver()) == true){
						gameOver = false;
				} else {
						exit = true;
						gameOver = false;
				}
		}

	}
	return 0;
}

Game::~Game() {
	endwin();
}
