/* #########################################
 *	
 *	File: menu.cpp
 *
 *	Author : Bagus Koko Wibawanto
 *
 * ########################################
 *
 * */

#include <iostream>
#include <ctype.h>
#include <string.h>
#include "../include/snake.hpp"

// Main Menu
void Game::Menu() {
	refresh();
	curs_set(FALSE);
	noecho();
	std::string listMenu[5] = {" Play ", " Shop ", " High Score ", " Skin ", " Quit "};
	box(MenuWindow, 0, 0);
	wrefresh(MenuWindow);
	keypad(MenuWindow, TRUE);
	bool exit = false;
	int highlight = 0;
	int yMenuWindow[5] = {5, 7, 9, 11, 13};
	int xMenuWindow[5] = {22, 22, 19, 22, 22};

	while(exit != true) {
		showCoin();
		for(int i = 0; i < 5; i++){
			mvwprintw(MenuWindow, yMenuWindow[i], xMenuWindow[i], listMenu[i].c_str());
		}	

		for(int i = 0; i < 5; i++) {
			if(i == highlight) {
				wattron(MenuWindow, A_REVERSE);
				mvwprintw(MenuWindow, yMenuWindow[i], xMenuWindow[i], listMenu[i].c_str());
				wattroff(MenuWindow, A_REVERSE);
			}
		}
		
		int choice = wgetch(MenuWindow);
		
		switch(choice) {
			case KEY_UP:
				if(highlight == 0) {
					highlight = 0;
					break;
				}
				highlight--;
				break;
			case KEY_DOWN:
				if(highlight == 4) {
					highlight = 4;
					break;
				}
				highlight++;
				break;
			case 10: // Enter
				if(highlight == 0) {
					werase(MenuWindow);
					render();
				} else if(highlight == 1) {
					buySkin();
				} else if(highlight == 2) {
					ShowBestScore();
				} else if(highlight == 3) {
					chooseSkin();
				} else {
					exit = true;
				}
			default:
				break;
		}
		werase(MenuWindow);
		box(MenuWindow, 0, 0);
		refresh();
	}
}

