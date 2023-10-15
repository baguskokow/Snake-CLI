#include <unistd.h>
#include "../ncurses/ncurses.h"

class Screen {
	private: 
		int Height;
		int Width;
		int VerticalPosition;
		int HorizontalPosition;
		const char* NameScreen;
		//int LengthNameScreen;

	public:
		Screen(int height, int width, int verticalPosition, int horizontalPosition, const char* nameScreen) {
			Screen::Height = height;
			Screen::Width = width;
			Screen::VerticalPosition = verticalPosition;
			Screen::HorizontalPosition = horizontalPosition;
			Screen::NameScreen = nameScreen;
			//Screen::LengthNameScreen = nameScreen.size();
		}

		void render() {
			initscr();
			WINDOW *window = newwin(Height, Width, VerticalPosition, HorizontalPosition);
		    box(window, 0, 0);
		    curs_set(FALSE);
    
		    while(true) {
				mvwprintw(window, 0, 19, NameScreen);
				wrefresh(window);

		    //    for(int i = 2; i < 49; i++) {
			//		mvwprintw(window, 2, i - 1, "++++0");
			//		//mvwprintw(MainWindow, 2, i, "++++0");
			//		//mvwprintw(ScoreWindow, 2.5, 9.5, "0"); 
			//		wrefresh(window);
			//		//wrefresh(ScoreWindow);
			//		sleep(1);
			//	}
			}
			endwin();
		}
};


class Position {
	public:
		 
};




