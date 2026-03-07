#include "../include/utility.h"

int main()
{
    clearScreen();
    int choice = 0;
    while(choice != static_cast<int>(MenuItem::EXIT)){
        choice = getMenuChoice();
        std::cout << "Menu choice: " << choice << "\n";
        processMenuChoice(choice);
    }
    
    return 0;
}