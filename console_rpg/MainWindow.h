#pragma once

class MainWindow
{
private:
	// Private variables
	bool isOpen;
	int playerInput;

	//Private functions
	void initVariables();

public:
	//Constructor / Destructor
	MainWindow();
	virtual ~MainWindow();

	//Getters / Setters
	bool getIsOpen();

	//Public functions
	void closeGame();
	void printInstructions();
	void getPlayerInput();
	void processPlayerInput();

};