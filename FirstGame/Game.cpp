#include "Game.h"

//Private functions
void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	//Window
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	//this->videoMode.getDesktopMode; << Get the desktop resolution

	this->window = new sf::RenderWindow(this->videoMode, "CPP Game", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(164);
}

void Game::initEnemies()
{
	this->enemy.setPosition(10.f, 10.f);
	this->enemy.setSize(sf::Vector2f(100.f, 100.f));
	this->enemy.setScale(0.5f, 0.5f);
	this->enemy.setFillColor(sf::Color::Cyan);
	this->enemy.setOutlineColor(sf::Color::Green);
	this->enemy.setOutlineThickness(1.f);
}

//Constructors / Destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initEnemies();
}

Game::~Game()
{
	delete this->window;
}

//Accessors
const bool Game::getWindowIsOpen() const
{
	return this->window->isOpen();
}

//Functions
void Game::pollEvents()
{
	//Event polling
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{

		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
		default:
			break;
		}
	}
}

void Game::update()
{
	this->pollEvents();
}

void Game::render()
{
	/*
		@return void
		
		- clear old frame
		- render objects
		- display frame in window

		Renders the game objects.
	*/

	//Clear window
//	this->window->clear(sf::Color(0, 0, 255, 255)); << clear and set a Default color
	this->window->clear();

	//Draw game objects
	this->window->draw(this->enemy);

	this->window->display();
}
