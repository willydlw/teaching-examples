#include "utility.h"
#include <limits>

void clearScreen(void)
{
    #ifdef _WIN32
        system("cls");
    #else 
        system("clear");
    #endif
}


void displayMenu(void)
{
    std::string menu = R"(
Maze Generation Menu
    1. Choice 1 
    2. Choice 2 
    3. Quit

Enter choice: )";
    std::cout << menu;

}
int getMenuChoice(void)
{
    bool notValid = true;
    int choice = 0;
    while(notValid)
    {
        displayMenu();
        choice = readIntFromKeyboard();
        if(choice >= MENU_MIN && choice <= MENU_MAX){
            notValid = false;
        }
        else{
            std::cout << "\nNumber " << choice << " is not a recognized menu option.\n";
            std::cout << "Press enter key to continue ...";
            std::getchar();
            clearScreen();
        }
    }
         
    return choice;
}


int readIntFromKeyboard()
{
    int number = 0;
    while(!(std::cin >> number)){
        std::cout << "Invalid input. Please enter a number: ";
        std::cin.clear();       // clear error flag 

        // discard the input buffer up to the next newline character
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // remove any remaining characters from the input buffer 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   
    return number;
}

