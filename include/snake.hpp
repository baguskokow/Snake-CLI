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
#include <ncurses.h>

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
		WINDOW *HighestScoreWindow;
		WINDOW *GameOverWindow;
		WINDOW *ConfirmWindow;
		WINDOW *SuccessWindow;
		WINDOW *SkinPreviewWindow;
		WINDOW *ShadowMap;
		WINDOW *CoinMap;
		WINDOW *ShopWindow;
		WINDOW *SkinMenuWindow;
		WINDOW *QiSkinWindow;
		WINDOW *ZiroSkinWindow;
		WINDOW *AteSkinWindow;
		WINDOW *TheGSkinWindow;
		WINDOW *YuSkinWindow;
		WINDOW *NotificationPopUpWindow;

		// Member Property to Get Length Windows Name
		size_t LengthName;
		size_t LengthScore;

		// Member Property to Windows Name Position
		int PositionName;
		int PositionScore;

		// Default Point
		int point = 0;
		int highestScore;
		std::string highScoreString = std::to_string(highestScore);

		// Size of Window Map
		int xMax;
		int yMax;

		// Size Current Terminal
		int rowTerminal;
		int columnTerminal;

		// Characters
		char Food = '*'; // Food Character
		char SnakeHead; // Snake Head
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
		std::vector<int> xBody;
		std::vector<int> yBody;

		// Default Direction
		int xDirection = 1;
		int yDirection = 0;
		
		// Continue Keypad
		bool playAgain;

		// Skin Selected
		int skinSelected;

		// Highlight Menu (Global Variable)
		int highlightSkinMenu = 0;

		// Money
		int money = 0;
		std::string moneyString = std::to_string(money);
		
		// Index Skin
		std::vector<std::string> skinIndex = {"Qi", "Ziro", "Ate", "The G"};

		// Skin Collection
		std::string skinCollection[4];

		// Skin Want To Buy It
		int skinWantToBuy = 0;

		// Define homeDir & workDir
		const char* homeDir;
		std::string workDir;

	public:	
		Game(int, int, int, int, const char*);
		void UpdateScore(WINDOW*, int);
		bool render();
		bool GameOver();
		bool EnsurePlayAgainOrNot(bool);
		bool ShowPopUpGameOver();
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
		void speed();
		int getRowTerminalSize();
		int getColumnTerminalSize();
		void saveData();
		void readData();
		void resetData();
		void ShowHighestScore();
		void removeMenuWindow();
		void removeScoreWindow();
		void removeConfirmWindow();
		void removeSuccessWindow();
		void removeHighScoreWindow();
		void removeShopWindow();
		void resetSnake();
		void showConfirmPopUp(std::string, std::string);
		bool showSuccessPopUp();
		bool chooseSkin();
		bool SkinPreview();
		void saveDataSkin();
		void readDataSkin();
		void showCoin();
		int rewardMoney();
		void saveDataMoney();
		void readDataMoney();
		void readDataCollectionSkin();
		void saveDataCollectionSkin(std::string);
		bool buySkin();
		bool QiSkin();
		bool ZiroSkin();
		bool AteSkin();
		bool TheGSkin();
		bool ConfirmSkin();
		bool Pay(std::string);
		bool PayProcess(int, int);
		bool NotificationPopUp(std::string);
		~Game();
};

#endif
