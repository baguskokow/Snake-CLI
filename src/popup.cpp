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
