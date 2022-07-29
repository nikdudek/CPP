#include <iostream>
#include "MainWindow.h"
#include "PlayerCharacter.h"

// Private functions
void MainWindow::initVariables()
{
	PlayerCharacter playerCharacter;
	this->isOpen = true;
	this->playerInput = 0;
}

//Constructor / Destructor
MainWindow::MainWindow()
{
	this->initVariables();
}

MainWindow::~MainWindow()
{

}

//Getters
bool MainWindow::getIsOpen()
{
	return this->isOpen;
}

//Public functions
void MainWindow::closeGame()
{
	this->isOpen = false;
}

void MainWindow::printInstructions()
{
	std::cout
		<< "INSTRUCTIONS:\n"
		<< "Type 0 - QUIT GAME\n"
		<< std::endl;
}

void MainWindow::getPlayerInput()
{
	int input;

	while (!(std::cin >> input)) {
		std::cout << "Enter a valid number and try again: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<int>::max(), '\n');
	}

	this->playerInput = input;
}

void MainWindow::processPlayerInput()
{
	switch (this->playerInput)
	{
	case 0: closeGame();

	default:
		break;
	}
}
