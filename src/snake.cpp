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

Characters Food;

void Game::render() {
    box(Map, 0, 0);
    box(Score, 0, 0);
    curs_set(FALSE); 

	while(true) {
		mvwprintw(Map, 0, PositionName, NameTitle);
		mvwprintw(Score, 0, PositionScore, ScoreTitle);
		std::srand(time(0));
		
		//Food.getFood(Map);
		Food.getSnake(Map);

		//mvwprintw(Map, Food.RandomPositionVertical(), Food.RandomPositionHorizontal(), "+");
		wrefresh(Map);
		wrefresh(Score);
		sleep(1);
	}
}


Game::~Game() {
	endwin();
}
