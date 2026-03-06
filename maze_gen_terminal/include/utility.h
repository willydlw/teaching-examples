#pragma once \

#include <iostream>

#define MENU_MIN 1
#define MENU_MAX 3

#define NOT_IMPLEMENTED \
    std::cerr << "NOT IMPLEMENTED: Function " << __func__ \
            << " in file " << __FILE__ << "\n";

#define TODO(msg) \
    std::cerr << "[TODO] File " << __FILE__ \
            << ", Line: " << __LINE__ << " - " #msg << "\n";

void clearScreen();
void displayMenu();
int getMenuChoice();
int readIntFromKeyboard();
