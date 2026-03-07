#pragma once \

#include <iostream>


#define NOT_IMPLEMENTED \
    std::cerr << "NOT IMPLEMENTED: Function " << __func__ \
            << " in file " << __FILE__ << "\n";

#define TODO(msg) \
    std::cerr << "[TODO] File " << __FILE__ \
            << ", Line: " << __LINE__ << " - " #msg << "\n";


#define MENU_ITEM_MIN 1 
#define MENU_ITEM_MAX 6

enum class MenuItem : int
{
    DEFAULT = 0,
    SET_DIMENSIONS = 1,
    GENERATE_MAZE = 2,
    DISPLAY_MAZE = 3,
    SAVE_MAZE = 4,
    LOAD_MAZE = 5,
    EXIT = 6
};

void clearScreen();
void displayMenu();
int  getMenuChoice();
void processMenuChoice(int choice);
int  readIntFromKeyboard();


void pressEnterKeyToContinue();
