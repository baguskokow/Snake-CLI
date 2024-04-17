/* #########################################
 *	
 *	File: snake.hpp
 *
 *	Author : Bagus Koko Wibawanto
 *
 * ########################################
 *
 * */

#include <unistd.h>
#include <string.h>
#include <vector>
#include "ncurses/ncurses.h"

#ifndef __SNAKE
#define __SNAKE

class Game {
	private: 
		// Member Property to  Windows Size
		int Height;
		int Width;

		// Member Property to Windows Coordinat
		int WindowVerticalPosition;
		int WindowHorizontalPosition;

		// Member Property to Windows Name
		const char* ScoreTitle;
		
		// Member Property to Create Windows
		WINDOW *Map;
		WINDOW *Score;
		WINDOW *GameOverPopUp;
		WINDOW *MenuWindow;
		WINDOW *BestScoreWindow;
		WINDOW *GameOverWindow;
		WINDOW *ConfirmWindow;
		WINDOW *SuccessWindow;

		// Member Property to Get Length Windows Name
		size_t LengthName;
		size_t LengthScore;

		// Member Property to Windows Name Position
		int PositionName;
		int PositionScore;

		// Default Point
		int point = 0;
		std::string lastPoint = std::to_string(point);
		int highestScore;
		std::string highScoreString;

		// Size of Window Map
		int xMax;
		int yMax;

		// Size Current Terminal
		int rowTerminal;
		int columnTerminal;

		// Characters
		char Food= '*'; // Food Character
		char SnakeHead = '@'; // Snake Head
		char SnakeBody = '+'; // Snake Body

		// Default Body Length
		int bodyLength = 4; 

		// Default Position xHead & yHead
		int xHead; // Position of X Head
		int yHead; // Position of Y Head
					
		//Random Food Position
		int yRandom;
		int xRandom;
		
		// Size xBody & yBody Array
		int xBody[1000]; // Length of X body array
		int yBody[1000]; // Length of Y body array

		// Default Direction
		int xDirection = 1;
		int yDirection = 0;
		
		// Continue Keypad
		bool isContinue;


	public:	
		Game(int, int, int, int, const char*);
		void UpdateScore(WINDOW*, int);
		bool render();
		bool GameOver();
		void ShowPopUpGameOver();
		bool Play();
		void Menu();
		void startPosition();
		void UpdatePosition();
		int xHeadRandom();
		int yHeadRandom();
		void showCharacter(WINDOW*);
		void controlSnakeHead();
		void generateFood(WINDOW*, int, int);
		int xFoodRandom();
		int yFoodRandom();
		void SpawnFood();
		void mvUp();
		void mvDown();
		void mvRight();
		void mvLeft();
		void directionControl();
		int getRowTerminalSize();
		int getColumnTerminalSize();
		void saveData();
		void readData();
		void resetData();
		void ShowBestScore();
		void removeScoreWindow();
		void removeConfirmWindow();
		void removeSuccessWindow();
		void resetSnake();
		void showConfirmPopUp();
		bool showSuccessPopUp();
		~Game();
};

#endif
