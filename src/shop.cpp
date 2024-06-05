/* #########################################
 *	
 *	File: skin.cpp
 *
 *	Author : Bagus Koko Wibawanto
 *
 * ########################################
 *
 * */

#include <iostream>
#include <fstream>
#include "../include/snake.hpp"
#include <clocale>

bool Game::buySkin() {
        curs_set(FALSE);
        noecho();
        std::string listMenu[4] = {" Buy ", " Buy ", " Buy ", " Buy "};
        box(ShopWindow, 0, 0);
        bool exit = false;
        keypad(ShopWindow, TRUE);
        int highlight = 0;
        int yMenuWindow[4] = {8, 8, 16, 16};
        int xMenuWindow[4] = {11, 33, 11, 33};
        wrefresh(ShopWindow);
        readDataCollectionSkin();

        while(exit != true) {
                for(int i = 0; i < 4; i++){
                        if(skinCollection[i] == "Qi" || skinCollection[i] == "Ziro" || skinCollection[i] == "Ate"  || skinCollection[i] == "The G") {
                                mvwprintw(ShopWindow, yMenuWindow[i], xMenuWindow[i], " Owned ");
                        } else {
                                mvwprintw(ShopWindow, yMenuWindow[i], xMenuWindow[i], listMenu[i].c_str());
                        }
                }
                mvwprintw(ShopWindow, 0, 1, "[ q ]");

                for(int i = 0; i < 4; i++) {
                        if(i == highlight) {
                                wattron(ShopWindow, A_REVERSE);
                                if(skinCollection[i] == "Qi" || skinCollection[i] == "Ziro" || skinCollection[i] == "Ate"  || skinCollection[i] == "The G") {
                                        mvwprintw(ShopWindow, yMenuWindow[i], xMenuWindow[i], " Owned ");
                                } else {
                                        mvwprintw(ShopWindow, yMenuWindow[i], xMenuWindow[i], listMenu[i].c_str());
                                }
                                wattroff(ShopWindow, A_REVERSE);
                        }
                }
                showCoin();        
                QiSkin();
                ZiroSkin();
                AteSkin();
                TheGSkin();
                
                int choice = wgetch(ShopWindow);

                switch(choice) {
                        case KEY_UP:
                                if(highlight == 0) {
                                        highlight = 0;
                                        break;
                                } else if(highlight == 1) {
                                        highlight == 1;
                                        break;
                                }
                                highlight -= 2;
                                break;
                        case KEY_DOWN:
                                if(highlight == 2) {
                                        highlight = 2;
                                        break;
                                } else if(highlight == 3) {
                                        highlight == 3;
                                        break;
                                }
                                highlight += 2;
                                break;
                        case KEY_RIGHT:
                                if(highlight == 3) {
                                        highlight = 3;
                                        break;
                                }
                                highlight++;
                                break;
                        case KEY_LEFT:
                                if(highlight == 0) {
                                        highlight = 0;
                                        break;
                                }
                                highlight--;
                                break;
                        case ' ':
                                skinWantToBuy = highlight;
                                showConfirmPopUp("Are you sure you want to buy it?", "buySkin");
                                break;
                        case 'q':
                                exit = true;
                        default:
                                break;
                }
                
        }
        
        return 0;
}

bool Game::QiSkin() {
  werase(QiSkinWindow);
  box(QiSkinWindow, 0, 0);
  mvwprintw(QiSkinWindow, 0, 1, "{ Qi }");
  mvwprintw(QiSkinWindow, 2, 6, "Q+++");
  mvwprintw(QiSkinWindow, 4, 4, "[ $ 35 ]");
  wrefresh(QiSkinWindow);
  
  return 0;
}

bool Game::ZiroSkin() {
  werase(ZiroSkinWindow);
  box(ZiroSkinWindow, 0, 0);
  mvwprintw(ZiroSkinWindow, 0, 1, "{ Ziro }");
  mvwprintw(ZiroSkinWindow, 2, 6, "0+++");
  mvwprintw(ZiroSkinWindow, 4, 4, "[ $ 0 ]");
  wrefresh(ZiroSkinWindow);
  
  return 0;
}

bool Game::AteSkin() {
  werase(AteSkinWindow);
  box(AteSkinWindow, 0, 0);
  mvwprintw(AteSkinWindow, 0, 1, "{ Ate }");
  mvwprintw(AteSkinWindow, 2, 6, "@+++");
  mvwprintw(AteSkinWindow, 4, 4, "[ $ 115 ]");
  wrefresh(AteSkinWindow);
  
  return 0;
}

bool Game::TheGSkin() {
  werase(TheGSkinWindow);
  box(TheGSkinWindow, 0, 0);
  mvwprintw(TheGSkinWindow, 0, 1, "{ The G }");
  mvwprintw(TheGSkinWindow, 2, 6, "G+++");
  mvwprintw(TheGSkinWindow, 4, 4, "[ $ 75 ]");
  wrefresh(TheGSkinWindow);
  
  return 0;
}
