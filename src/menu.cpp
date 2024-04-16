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
	std::string listMenu[3] = {" Play ", " Best Score ", " Quit "};
	box(MenuWindow, 0, 0);
	wrefresh(MenuWindow);
	keypad(MenuWindow, TRUE);
	bool exit = false;
	int highlight = 0;
	int yMenuWindow[3] = {7, 9, 11};
	int xMenuWindow[3] = {22, 19, 22};


	while(exit != true) {
		for(int i = 0; i < 3; i++){
			mvwprintw(MenuWindow, yMenuWindow[i], xMenuWindow[i], listMenu[i].c_str());
		}

		for(int i = 0; i < 3; i++) {
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
				if(highlight == 2) {
					highlight = 2;
					break;
				}
				highlight++;
				break;
			case 10: // Enter
				if(highlight == 0) {
					render();
				} else if(highlight == 1) {
					ShowBestScore();
				} else if(highlight == 2) {
					exit = true;
				}
			default:
				break;
		}
		box(MenuWindow, 0, 0);
	}
}

