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

bool Game::chooseSkin() {
        curs_set(FALSE);
        noecho();
        std::string listMenu[4] = {" Vi ", " Ziro ", " Ate ", " The G "};
        box(Map, 0, 0);
        bool exit = false;
        keypad(Map, TRUE);
        //int highlight = 0;
        int yMenuWindow[4] = {6, 8, 10, 12};
        int xMenuWindow[4] = {7, 7, 7, 7};
        int selectedSkin = 1; // start index from 0
        vSkin();
        wrefresh(Map);
        wrefresh(MapN);

        while(exit != true) {
                for(int i = 0; i < 4; i++){
                        mvwprintw(Map, yMenuWindow[i], xMenuWindow[i], listMenu[i].c_str());
                }
                mvwprintw(Map, 18, 15, "Press Space To Select");

                for(int i = 0; i < 4; i++) {
                        if(i == highlight) {
                                wattron(Map, A_REVERSE);
                                mvwprintw(Map, yMenuWindow[i], xMenuWindow[i], listMenu[i].c_str());
                                wattroff(Map, A_REVERSE);
                        }
                }
        
                // Show Detail Selected Skin
                if(selectedSkin == highlight) {
                        mvwprintw(MapN, 10, 25, "[ Selected ]");
                        wrefresh(MapN);
                } else {
                        werase(MapN);
                        wrefresh(MapN);
                }

                
                // Show Preview
                vSkin();


                int choice = wgetch(Map);

                switch(choice) {
                        case KEY_UP:
                                if(highlight == 0) {
                                        highlight = 0;
                                        break;
                                }
                                highlight--;
                                break;
                        case KEY_DOWN:
                                if(highlight == 3) {
                                        highlight = 3;
                                        break;
                                }
                                highlight++;
                                break;
                        case ' ':
                                selectedSkin = highlight;
                                
                        default:
                                break;
                }
                
        }
        return 0;
}

bool Game::vSkin() {
        werase(SkinPreviewWindow);
        box(SkinPreviewWindow, 0, 0);
        if(highlight == 0) {
                mvwprintw(SkinPreviewWindow, 2, 6, "V+++");
        } else if(highlight == 1) {
                mvwprintw(SkinPreviewWindow, 2, 6, "0+++");
        } else if(highlight == 2) {
                mvwprintw(SkinPreviewWindow, 2, 6, "@+++");
        } else {
                mvwprintw(SkinPreviewWindow, 2, 6, "G+++");
        }
        wrefresh(SkinPreviewWindow);

        return 0;
}
