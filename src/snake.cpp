/* #########################################
 *	
 *	File: snake.cpp
 *
 *	Author : Bagus Koko Wibawanto
 *
 *	Version : 1.0
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
	this->Map = newwin(Height, Width, WindowVerticalPosition, WindowHorizontalPosition);

	// Score Window Inisialization
	this->Score = newwin(Height / 4, Width / 3, WindowVerticalPosition + 7.5, WindowHorizontalPosition + Width + 5); 
	// Ex : (20 / 4, 50 / 3, 0 + 7.5, 0 + 50 + 5)
	// 20 = Height
	// 50 = Width
	// 0 = Window Position Vertical
	// 0 = Window Position Horizontal
	// 50 Position Horizontal after Width and + 5 for space
	
	// Game Over Pop Up Window
	this->GameOverPopUp = newwin(10, 20, 4, 5);

	// Menu Window
	this->MenuWindow = newwin(20, 50, 0, 0);

	// Get Terminal Size
	getmaxyx(stdscr, rowTerminal, columnTerminal);

	// Title Score Window
	this->LengthScore = strlen(scoreTitle);

	this->PositionScore = ((Width / 3) - LengthScore) / 2; // Ex : ((50 / 3) - 9) / 2)
}

int Game::getRowTerminalSize() {
	return rowTerminal; 		
}

int Game::getColumnTerminalSize() {
	return columnTerminal; 		
}

// Conditional When Game Over
bool Game::GameOver() {
	//saveData();
	bool exit = false;
	werase(Map);
	box(Map, 0, 0);	
	noecho();
    curs_set(FALSE); 
	
	mvwprintw(Map, 9, 20, "GAME OVER");
	mvwprintw(Map, 18, 2, "Play Again (p)");
	mvwprintw(Map, 18, 30, "Return to Menu (q)");
	this->xHead = 5;
	this->yHead = 4;
	this->point = 0;
	this->bodyLength = 4;

	refresh();
	wrefresh(Map);
	wrefresh(Score);
	wgetch(Map);
	return exit;
}

bool Game::render() {
	curs_set(FALSE);
	noecho();
	werase(Map);
	keypad(Map, TRUE);
	nodelay(Map, TRUE);
	startPosition();
	int gameOver = false;

	while(gameOver != true) {
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
		}
		

		werase(Map);
		
		SpawnFood();
		
		UpdateScore(Score, point);
		UpdatePosition();
		
		showCharacter(Map);

		for(int i = 1; i < bodyLength; i++) {
			if(xHead == xBody[i] && yHead == yBody[i]) {
				gameOver = true;
			}
		}
		
		directionControl();
		
		usleep(120000); // miliseconds
		wrefresh(Map);
		wrefresh(Score);
	}
	
	return true;
}

// Looping Game
bool Game::Play() {
	bool exit = false;
	while(exit != true) {
		if(render() == true) {
			if(GameOver() == true) {
				GameOver();
				exit = true;
			}
		}
	}
	return exit;
}

Game::~Game() {
	endwin();
}
