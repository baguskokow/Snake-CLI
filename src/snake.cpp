#include <iostream>
#include <functional>
#include <vector>
#include "../include/snake.hpp"

Game::Game(int height, int width, int windowVerticalPosition, int windowHorizontalPosition, const char* gameTitle, const char* scoreTitle) {
	this->Height = height;
	this->Width = width;

	this->WindowVerticalPosition = windowVerticalPosition;
	this->WindowHorizontalPosition = windowHorizontalPosition;

	this->NameTitle = gameTitle;
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

	this->LengthName = strlen(gameTitle);
	this->LengthScore = strlen(scoreTitle);

	this->PositionName = (Width - LengthName) / 2;
	this->PositionScore = ((Width / 3) - LengthScore) / 2; // Ex : ((50 / 3) - 9) / 2)
}

void Game::UpdateScore(WINDOW* Score, int point) {
	std::string pointString = std::to_string(point);
	mvwprintw(Score, 2, 7.5, pointString.c_str());
}

void Game::render() {
	keypad(stdscr, TRUE);
    box(Score, 0, 0);
    curs_set(FALSE); 
	int pointNow = this->point;
	bool gameOver = false;

	startPosition();

	while(!gameOver) {
		int choice = getch();

		switch(choice) {
			case KEY_UP:
				mvUp();
				break;
			case KEY_DOWN:
				mvDown();
				break;
			case KEY_LEFT:
				mvLeft();
				break;
			case KEY_RIGHT:
				mvRight();
				break;
			case 'q':
				gameOver = true;
				break;
			default:
				break;
		}

		UpdatePosition();

		mvwprintw(Map, 0, PositionName, NameTitle);
		mvwprintw(Score, 0, PositionScore, ScoreTitle);

		//Update Score
		UpdateScore(Score, pointNow);
		pointNow += 1;

		werase(Map);
		box(Map, 0, 0);

		showCharacter(Map);
		wrefresh(Map);
		wrefresh(Score);
	}
}

Game::~Game() {
	endwin();
}
