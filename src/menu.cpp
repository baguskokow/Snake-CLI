/* #########################################
 *	
 *	File: menu.cpp
 *
 *	Author : Bagus Koko Wibawanto
 *
 *	Version : 1.0
 *
 * ########################################
 *
 * */

#include <iostream>
#include <ctype.h>
#include <string.h>
#include "../include/snake.hpp"

bool Game::GameOver() {
	curs_set(FALSE);
	noecho();
	std::string listMenu[2] = {" Play Again ", " Return to Menu "};
	box(GameOverWindow, 0, 0);
	bool exit = false;
	keypad(GameOverWindow, TRUE);
	int highlight = 0;
	int yMenuWindow[3] = {8, 10};
	int xMenuWindow[3] = {20, 18};

	while(exit != true) {
		for(int i = 0; i < 2; i++){
			mvwprintw(GameOverWindow, yMenuWindow[i], xMenuWindow[i], listMenu[i].c_str());
		}

		for(int i = 0; i < 2; i++) {
			if(i == highlight) {
				wattron(GameOverWindow, A_REVERSE);
				mvwprintw(GameOverWindow, yMenuWindow[i], xMenuWindow[i], listMenu[i].c_str());
				wattroff(GameOverWindow, A_REVERSE);
			}
		}
		
		int choice = wgetch(GameOverWindow);
		
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
					point = 0;
					bodyLength = 4;
					startPosition();
					render();
					break;
				} else if(highlight == 1) {
					exit = true;
				}
			default:
				break;
		}

	}
}

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
				werase(Score);
				wrefresh(Score);
				break;
			default:
				break;
		}
	
		box(GameOverPopUp, 0, 0);
	}
	GameOver();	
}
