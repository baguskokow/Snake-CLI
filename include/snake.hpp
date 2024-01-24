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
		const char* NameTitle;
		const char* ScoreTitle;
		
		// Member Property to Create Windows
		WINDOW *Map;
		WINDOW *Score;

		// Member Property to Get Length Windows Name
		size_t LengthName;
		size_t LengthScore;

		// Member Property to Windows Name Position
		int PositionName;
		int PositionScore;

		// Default Point
		int point = 0;

		// Size of Window Map
		int xMax;
		int yMax;

		// Characters
		char Food= '*'; // Food Character
		char SnakeHead = '@'; // Snake Head
		char SnakeBody = '+'; // Snake Body

		// Default Body Length
		int bodyLength = 4; 

		// Default Position xHead & yHead
		int xHead = 5; // Position of X Head
		int yHead = 4; // Position of Y Head
		
		// Size xBody & yBody Array
		int xBody[1000]; // Length of X body array
		int yBody[1000]; // Length of Y body array

		// Direction
		int xDirection;
		int yDirection;


	public:	
		Game(int, int, int, int, const char*, const char*);
		void UpdateScore(WINDOW*, int);
		void startPosition();
		void UpdatePosition();
		void showCharacter(WINDOW*);
		void mvUp();
		void mvDown();
		void mvRight();
		void mvLeft();
		void render();
		~Game();
};

#endif
