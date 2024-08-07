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
        int skinCollectionCount = sizeof(skinCollection) / sizeof(skinCollection[0]);
        std::vector<std::string> ensureSkinCollectionHaveValue {"False", "False", "False", "False"};
        std::string listMenu[4] = {"!Qi", "!Ziro", "!Ate", "!The G"};
        box(SkinMenuWindow, 0, 0);
        bool exit = false;
        keypad(SkinMenuWindow, TRUE);
        int yMenuWindow[5] = {4, 6, 8, 10, 12};
        int xMenuWindow[5] = {7, 7, 7, 7, 7};
        SkinPreview();
        wrefresh(SkinMenuWindow);
        readDataCollectionSkin();

        while(exit != true) {
                // Read collection skin
                readDataCollectionSkin();

                // Print skin collection by collection skin data
                for(int i = 0; i < skinCollectionCount; i++){
                        if(skinCollection[i] == "Qi" || skinCollection[i] == "Ziro" || skinCollection[i] == "Ate" || skinCollection[i] == "The G") {
                                mvwprintw(SkinMenuWindow, yMenuWindow[i], xMenuWindow[i], skinCollection[i].c_str());
                        } else {
                                wrefresh(SkinMenuWindow);
                                mvwprintw(SkinMenuWindow, yMenuWindow[i], xMenuWindow[i], listMenu[i].c_str());
                        }
                }

                mvwprintw(SkinMenuWindow, 0, 1, "[ q ]");
                mvwprintw(SkinMenuWindow, 18, 15, "Press Space To Select");

               for(int i = 0; i < 4; i++) {
                       if(i == highlightSkinMenu) {
                               wattron(SkinMenuWindow, A_REVERSE);
                               if(skinCollection[i] == "Qi" || skinCollection[i] == "Ziro" || skinCollection[i] == "Ate" || skinCollection[i] == "The G") {
                                       mvwprintw(SkinMenuWindow, yMenuWindow[i], xMenuWindow[i], skinCollection[i].c_str());
                               } else {
                                       mvwprintw(SkinMenuWindow, yMenuWindow[i], xMenuWindow[i], listMenu[i].c_str());
                               }
                               wattroff(SkinMenuWindow, A_REVERSE);
                       }
               }
                
                // Read current selected skin that will use when playing game
                readDataSkin();

                // Show Detail Selected Skin
               if(skinSelected == highlightSkinMenu) {
                       for(int i = 0; i < skinCollectionCount; i++) {
                               if(skinCollection[i] == "Qi" || skinCollection[i] == "Ziro" || skinCollection[i] == "Ate" || skinCollection[i] == "The G") {
                                       ensureSkinCollectionHaveValue.at(i) = "True";
                                       
                               } else {
                                       ensureSkinCollectionHaveValue.at(i) = "False";
                               }
                       }
                       if(ensureSkinCollectionHaveValue.at(skinSelected) == "True") {
                               mvwprintw(ShadowMap, 0, 2, "[ Selected ]");
                               wrefresh(ShadowMap);
                       }
               } else {
                       werase(ShadowMap);
                       wrefresh(ShadowMap);
               }

                // Show Preview
                SkinPreview();

                int choice = wgetch(SkinMenuWindow);

                switch(choice) {
                        case KEY_UP:
                                if(highlightSkinMenu == 0) {
                                        highlightSkinMenu = 0;
                                        break;
                                }
                                highlightSkinMenu--;
                                break;
                        case KEY_DOWN:
                                if(highlightSkinMenu == skinCollectionCount - 1) {
                                        highlightSkinMenu = skinCollectionCount - 1;
                                        break;
                                }
                                highlightSkinMenu++;
                                break;
                        case ' ':
                                skinSelected = highlightSkinMenu;
                                saveDataSkin();
                                break;
                        case 'q':
                                werase(SkinMenuWindow);
                                refresh();
                                exit = true;
                        default:
                                break;
                }
        }
        
        // At below, change head snake that use when playing game
        if(skinSelected == 0) {
                SnakeHead = 'Q';
        } else if (skinSelected == 1) {
                SnakeHead = '0';
        } else if (skinSelected == 2) {
                SnakeHead = '@';
        } else if (skinSelected == 3) {
                SnakeHead = 'G';
        }

        return 0;
}

bool Game::SkinPreview() {
        werase(SkinPreviewWindow);
        box(SkinPreviewWindow, 0, 0);
        if(highlightSkinMenu == 0) {
                mvwprintw(SkinPreviewWindow, 2, 6, "Q+++");
        } else if(highlightSkinMenu == 1) {
                mvwprintw(SkinPreviewWindow, 2, 6, "0+++");
        } else if(highlightSkinMenu == 2) {
                mvwprintw(SkinPreviewWindow, 2, 6, "@+++");
        } else if(highlightSkinMenu == 3) {
                mvwprintw(SkinPreviewWindow, 2, 6, "G+++");
        } 

        wrefresh(SkinPreviewWindow);

        return 0;
}
