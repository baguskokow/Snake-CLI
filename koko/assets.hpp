#include <unistd.h>
#include <string.h>
#include "../ncurses/ncurses.h"

class Snake {
	private: 
		// Member Property to  Windows Size
		struct Size {
			int Height;
			int Width;
		};

		// Member Property to Windows Coordinat
		struct Coordinat {
			int Vertical;
			int Horizontal;
		};

		// Member Property to Windows Name
		const char* NameTitle;
		const char* ScoreTitle;
		
		// Member Property to Create Windows
		struct Window {
			WINDOW *Map;
			WINDOW *Score;
		};

		// Member Property to Get Length Windows Name
		struct Length {
			size_t Name;
			size_t Score;
		};

		// Member Property to Windows Name Position
		struct Position {
			int Name;
			int Score;

			Coordinat PositionCoordinat;
		};

	public:
		// Define Struct
		Length TitleLength;
		Position Start;
		Window Screen;
		Size Window;                                                                                                                                                                                    
		
		Snake(int height, int width, int verticalPosition, int horizontalPosition, const char* gameTitle, const char* scoreTitle) {
			Window.Height = height;
			Window.Width = width;

			Start.PositionCoordinat.Vertical = verticalPosition;
			Start.PositionCoordinat.Horizontal = horizontalPosition;

			Snake::NameTitle = gameTitle;
			Snake::ScoreTitle = scoreTitle;

			// Map Window Inisialization
			Screen.Map = newwin(Window.Height, Window.Width, Start.PositionCoordinat.Vertical, Start.PositionCoordinat.Horizontal);

			// Score Window Inisialization
			Screen.Score = newwin(Window.Height / 4, Window.Width / 3, Start.PositionCoordinat.Vertical + 7.5, Start.PositionCoordinat.Horizontal + Window.Width + 5); 
			// Ex : (20 / 4, 50 / 3, 0 + 7.5, 0 + 50 + 5)
			// 20 = Height
			// 50 = Width
			// 0 = Position Vertical
			// 0 Position Horizontal
			// 50 Position Horizontal after Width and + 5 for space

			TitleLength.Name = strlen(gameTitle);
			TitleLength.Score = strlen(scoreTitle);

			Start.Name = (Window.Width - TitleLength.Name) / 2;
			Start.Score = ((Window.Width / 3) - TitleLength.Score) / 2; // Ex : ((50 / 3) - 9) / 2)
		}

		void render() {
		    box(Screen.Map, 0, 0);
		    box(Screen.Score, 0, 0);
		    curs_set(FALSE); 
			while(true) {
				mvwprintw(Screen.Map, 0, Start.Name, NameTitle);
				mvwprintw(Screen.Score, 0, Start.Score, ScoreTitle);
				wrefresh(Screen.Map);
				wrefresh(Screen.Score);
				sleep(1);
			}
		}

		~Snake(){
			endwin();
		}
};
