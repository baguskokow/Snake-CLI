#include <iostream>
#include <functional>
#include <vector>
#include "../include/snake.hpp"

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
	saveData();
	werase(Map);
	mvwprintw(Map, 9, 20, "GAME OVER");
	box(Map, 0, 0);	
	wrefresh(Map);
	refresh();
	int choice = getch();
	this->xHead = 5;
	this->yHead = 4;
	this->point = 0;
	this->bodyLength = 4;
	keypad(stdscr, TRUE);
	
	bool end = false;

	switch(choice) {
		case 'q':
			end = true;
			break;
		case ' ':
			end = false;
			break;
		default:
			end = false;
	}
	return end;
}

// Render Game
bool Game::render() {
	keypad(stdscr, TRUE);
    box(Score, 0, 0);
    curs_set(FALSE); 
	bool gameOver = false;
	noecho();

	startPosition();
	
	while(!gameOver) {

		int choice = getch();

		switch(choice) {
			case KEY_UP:
				if(yDirection != 1) {
					mvUp();
					break;
				} else {
					continue;
				}
			case KEY_DOWN:
				if(yDirection != -1) {
					mvDown();
					break;
				} else {
					continue;
				}
			case KEY_LEFT:
				if(xDirection != 1) {
					mvLeft();
					break;
				} else {
					continue;
				}
			case KEY_RIGHT:
				if(xDirection != -1) {
					mvRight();
					break;
				} else {
					continue;
				}
			case 'q':
				gameOver = true;
				break;
			case ' ':
				break;
			default:
				continue;
		}

		UpdatePosition();

		mvwprintw(Score, 0, PositionScore, ScoreTitle);

		werase(Map);
		box(Map, 0, 0);

		showCharacter(Map);
		UpdateScore(Score, point);
		if(yRandom == 0 && xRandom == 0) {
			yRandom = yFoodRandom();
			xRandom = xFoodRandom();
			generateFood(Map, yRandom, xRandom);
		} else {
			generateFood(Map, yRandom, xRandom);
		}

		for(int i = 1; i < bodyLength; i++) {
			if(xHead == xBody[i] && yHead == yBody[i]) {
				gameOver = true;
			}
		}
		
		wrefresh(Map);
		wrefresh(Score);
	}
	return gameOver;
}

// Looping Game
void Game::Play() {
	bool exit = false;
	while(exit != true) {
		if(render() == true) {
			if(GameOver() == false) {
				exit = false;
			} else {
				exit = true;
			}
		} else {
			render();
		}
	}
}

Game::~Game() {
	endwin();
}
