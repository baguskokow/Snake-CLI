/* #########################################
 *	
 *	File: gameover.cpp
 *
 *	Author : Bagus Koko Wibawanto
 *
 * ########################################
 *
 * */

#include <iostream>
#include "../include/snake.hpp"

// Game Over Menu
bool Game::GameOver() {
        curs_set(FALSE);
        noecho();
        std::string listMenu[2] = {" Play Again ", " Return to Menu "};
        box(GameOverWindow, 0, 0);
        bool exit = false;
        keypad(GameOverWindow, TRUE);
        int highlight = 0;
        int yMenuWindow[2] = {8, 10};
        int xMenuWindow[2] = {20, 18};

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
                                        this->playAgain = true;
                                        exit = true;
                                        break;
                                } else if(highlight == 1) {
                                        this->playAgain = false;
                                        exit = true;
                                        break;
                                }
                        default:
                                break;
                }
        }
        return playAgain;
}

bool Game::EnsurePlayAgainOrNot(bool playAgain) {
        bool result;
        if(playAgain == true) {
               // gameOverTemporary = true;
               result = true;
        } else {
                //gameOverTemporary = false;
               result = false;
        }
        return result;
}
