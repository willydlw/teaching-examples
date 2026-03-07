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
Maze Generator
    1. Set Dimensions
    2. Generate New Maze
    3. Display Maze 
    4. Save Maze 
    5. Load Maze
    6. Exit

Enter numeric option: )";
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
        if(choice >= MENU_ITEM_MIN && choice <= MENU_ITEM_MAX){
            notValid = false;
        }
        else{
            std::cout << "\nNumber " << choice << " is not a recognized menu option.\n";
            pressEnterKeyToContinue();
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

void pressEnterKeyToContinue()
{
    std::cout << "Press enter key to continue ...";
    std::getchar();
}


void processMenuChoice(int choice)
{
    switch(static_cast<MenuItem>(choice)){
        case MenuItem::SET_DIMENSIONS:
            TODO("Set Maze Dimensions");
        break;
        case MenuItem::GENERATE_MAZE:
            TODO("Generate Maze");
        break;
        case MenuItem::DISPLAY_MAZE:
            TODO("Display maze";)
        break;
        case MenuItem::SAVE_MAZE:
            TODO("Save maze");
        break;
        case MenuItem::LOAD_MAZE:
            TODO("Load maze");
        break;
        case MenuItem::EXIT:
            return;
        default:
            std::cerr << "\n[ERROR] func: " << __func__ << ", unknown choice: " << choice << "\n";
            pressEnterKeyToContinue();
    }
    pressEnterKeyToContinue();
    clearScreen();
}

