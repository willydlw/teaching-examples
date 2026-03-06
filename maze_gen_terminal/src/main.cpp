#include "../include/utility.h"

int main()
{
    clearScreen();
    int choice = getMenuChoice();
    std::cout << "Menu choice: " << choice << "\n";
    return 0;
}