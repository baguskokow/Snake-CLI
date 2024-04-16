/* #########################################
 *	
 *	File: popup.cpp
 *
 *	Author : Bagus Koko Wibawanto
 *
 * ########################################
 *
 * */

#include <iostream>
#include "../include/snake.hpp"

// Pop Up When Game Over
void Game::ShowPopUpGameOver() {
        curs_set(FALSE);
        box(GameOverPopUp, 0, 0);
        bool exit = false;
        keypad(GameOverPopUp, TRUE);

        while(exit != true) {
                mvwprintw(GameOverPopUp, 0, 0, "[ q ]");
                mvwprintw(GameOverPopUp, 4, 6, "[ GAME OVER ]");

                int choice = wgetch(GameOverPopUp);

                switch(choice) {
                        case 'q':
                                exit = true;
                                removeScoreWindow();
                                break;
                        default:
                                break;
                }

                box(GameOverPopUp, 0, 0);
        }
        GameOver();
}

// Show Confirm Pop Up
void Game::showConfirmPopUp() {
        box(ConfirmWindow, 0, 0);
        refresh();
        curs_set(FALSE);
        noecho();
        wrefresh(ConfirmWindow);
	    std::string listMenu[2] = {" Yes ", " No  "};
	    int highlight = 0;
	    int yMenuWindow[2] = {5, 6};
	    int xMenuWindow[2] = {18, 18};
        keypad(ConfirmWindow, TRUE);
        bool exit = false;
        
        while(exit != true) {
                mvwprintw(ConfirmWindow, 2, 2, "Are you sure to reset the high score?");

	            for(int i = 0; i < 2; i++){
	            	mvwprintw(ConfirmWindow, yMenuWindow[i], xMenuWindow[i], listMenu[i].c_str());
	            }

	            for(int i = 0; i < 2; i++) {
	            	if(i == highlight) {
	            		wattron(ConfirmWindow, A_REVERSE);
	            		mvwprintw(ConfirmWindow, yMenuWindow[i], xMenuWindow[i], listMenu[i].c_str());
	            		wattroff(ConfirmWindow, A_REVERSE);
	            	}
	            }

                int choice = wgetch(ConfirmWindow);

                switch(choice) {
                        case KEY_UP:
                                if(highlight == 0) {
                                        highlight = 0;
                                        break;
                                }
                                highlight--;
                                break;
                        case KEY_DOWN:
                                if(highlight == 1) {
                                        highlight = 1;
                                        break;
                                }
                                highlight++;
                                break;
                        case 10:
                                if(highlight == 0) {
                                        resetData();
                                        if(highestScore == 0) {
                                                showSuccessPopUp();
                                        }
                                } else if(highlight == 1) {
                                        exit = true;
                                        removeConfirmWindow();
                                }
                        default:
                                break;
                }

        }
}

// Show Success Pop Up
bool Game::showSuccessPopUp() {
        removeConfirmWindow();
        curs_set(FALSE);
        box(SuccessWindow, 0, 0);
        bool exit = false;
        keypad(SuccessWindow, TRUE);

        while(exit != true) {
                mvwprintw(SuccessWindow, 0, 0, "[ q ]");
                mvwprintw(SuccessWindow, 3.5, 9, "SUCCESS");

                int choice = wgetch(SuccessWindow);

                switch(choice) {
                        case 'q':
                                exit = true;
                                removeSuccessWindow();
                                break;
                        default:
                                break;
                }

                box(SuccessWindow, 0, 0);
        }
        return true;
}
