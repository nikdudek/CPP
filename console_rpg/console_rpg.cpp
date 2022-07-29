#include <iostream>
#include "MainWindow.h"

int main()
{
    MainWindow mainWindow;

    while (mainWindow.getIsOpen())
    {
        //Print something
        mainWindow.printInstructions();

        //Get Player's input
        mainWindow.getPlayerInput();

        //Process Player's input
        mainWindow.processPlayerInput();
    }

    return 0;
}
