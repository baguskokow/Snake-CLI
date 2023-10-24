#include <unistd.h>
#include <string.h>
#include "ncurses/ncurses.h"

class Snake {
	private: 
		// Member Property to  Windows Size
		int Height;
		int Width;

		// Member Property to Windows Coordinat
		int PositionVertical;
		int PositionHorizontal;

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

	public:
		
		Snake(int, int, int, int, const char*, const char*); //{
			//this->Window.Height = height;
			//this->Window.Width = width;

			//this->Start.PositionCoordinat.Vertical = verticalPosition;
			//this->Start.PositionCoordinat.Horizontal = horizontalPosition;

			//this->NameTitle = gameTitle;
			//this->ScoreTitle = scoreTitle;

			//// Map Window Inisialization
			//this->Screen.Map = newwin(Window.Height, Window.Width, Start.PositionCoordinat.Vertical, Start.PositionCoordinat.Horizontal);

			//// Score Window Inisialization
			//this->Screen.Score = newwin(Window.Height / 4, Window.Width / 3, Start.PositionCoordinat.Vertical + 7.5, Start.PositionCoordinat.Horizontal + Window.Width + 5); 
			//// Ex : (20 / 4, 50 / 3, 0 + 7.5, 0 + 50 + 5)
			//// 20 = Height
			//// 50 = Width
			//// 0 = Position Vertical
			//// 0 Position Horizontal
			//// 50 Position Horizontal after Width and + 5 for space

			//this->TitleLength.Name = strlen(gameTitle);
			//this->TitleLength.Score = strlen(scoreTitle);

			//this->Start.Name = (Window.Width - TitleLength.Name) / 2;
			//this->Start.Score = ((Window.Width / 3) - TitleLength.Score) / 2; // Ex : ((50 / 3) - 9) / 2)
		//}

		//char characters() {
		//	char Food[1] = {'+'};
		//	return Food;
		//}

		// Random Start Position
		//struct Random {
			int RandomVertical(); //{
			//	std::srand(time(0));
			//	int verticalLength = 18;
			//	int randomVertical;

			//	int x = std::rand() % verticalLength;
			//	if(x < 2) {
			//		randomVertical = x + 1;
			//	} else {
			//		randomVertical = x;
			//	}
			//	
			//	return randomVertical;
		//	}

			int RandomHorizontal(); //{
			//	std::srand(time(0));
			//	int horizontalLength = 48;
			//	int randomHorizontal;

			//	int y = std::rand() % horizontalLength;
			//	
			//	if(y < 2) {
			//		randomHorizontal = y + 1;
			//	} else {
			//		randomHorizontal = y;
			//	}
			//	
			//	return randomHorizontal;
		//	}
		//};

		struct Python {
			std::string right() {
				std::string rightSnake = "++0";
				return rightSnake;
			}

			std::string left() {
				std::string leftSnake = "0++";
				return leftSnake;
			}
			
		};


		void ularAtas(WINDOW *updateWindow, int vertical, int horizontal, char *karakter, int sisa) {
			char updateCharacter = *karakter;
			char hide[] = "   ";
			
			for(int i = 0; i < sisa; i++) {
				for(int j = 0; j < 4; j++) {
					mvwprintw(updateWindow, vertical + j, horizontal, "%c", karakter[j]);
				}

				wrefresh(updateWindow);
				sleep(1);

				for(int k = 0; k < 4; k++) {
					mvwprintw(updateWindow, vertical + k, horizontal, "%c", hide[k]);
				}
			
				vertical += 1;
			}
		}

		const char* food() {
			const char* makan = "+";
			return makan;
		}

		const char* hideFood() {
			const char* hide = " ";
			return hide;
		}

		void render() {
			Random Characters;
		    box(Screen.Map, 0, 0);
		    box(Screen.Score, 0, 0);
		    curs_set(FALSE); 
			int verticalPosition = Characters.vertical();
			int horizontalPosition = Characters.horizontal();
			
			// Dont touch line
			int verticalRemaining = 17 - verticalPosition;
			int horizontalRemaining = 47 - horizontalPosition;
			char test[] = "++0";
			
			//Just a Demo "Dont Touch Line"
			while(true) {
				mvwprintw(Screen.Map, 0, Start.Name, NameTitle);
				mvwprintw(Screen.Score, 0, Start.Score, ScoreTitle);
				mvwprintw(Screen.Map, Characters.vertical(), Characters.horizontal(), food());
				//ularAtas(Screen.Map, Characters.vertical(), Characters.horizontal(), test, verticalRemaining);
				wrefresh(Screen.Map);
				mvwprintw(Screen.Map, Characters.vertical(), Characters.horizontal(), hideFood());
				wrefresh(Screen.Score);
				sleep(1);
			}
		}

		~Snake(){
			endwin();
		}
};
