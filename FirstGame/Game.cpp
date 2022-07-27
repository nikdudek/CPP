#include "Game.h"

//Private functions
void Game::initVariables()
{
	this->window = nullptr;

	//Game logic
	this->points = 0;
	this->enemySpawnTimerMax = 50.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 5;
}

void Game::initWindow()
{
	//Window
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	//this->videoMode.getDesktopMode; << Get the desktop resolution

	this->window = new sf::RenderWindow(this->videoMode, "CPP Game", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(60);
}

void Game::initEnemies()
{
	this->enemy.setPosition(10.f, 10.f);
	this->enemy.setSize(sf::Vector2f(100.f, 100.f));
	this->enemy.setScale(0.5f, 0.5f);
	this->enemy.setFillColor(sf::Color::Cyan);
//	this->enemy.setOutlineColor(sf::Color::Green);
//	this->enemy.setOutlineThickness(1.f);
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
void Game::spawnEnemy()
{
	/*
		@ return void

		Spawns enemies and sets their colors and positions.
		- Sets a random position.
		- Sets a random color.
		- Add enemy to the vector.
	*/

	this->enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
		0.f
	);

	this->enemy.setFillColor(sf::Color::Green);

	//Spawn the enemy
	this->enemies.push_back(this->enemy);
}

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

void Game::updateMousePositions()
{
	/*
		@ return void
	
		Updates the mouse positions:
		- Mouse position relative to window (Vector2i)	
	*/

	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateEnemies()
{
	/*
		@ return void

		Updates the enemy spawn timer and spawns enemies
		when the total amount of enemies is less than maximum.
		Moves the enemies downwards.
		Removes the enemies at the edge of the screen. //TODO
	*/

	//Updating the timer for enemy spawning
	if (this->enemies.size() < this->maxEnemies)
	{
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{
			//Spawn the enemy and reset the timer
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}
		else
			this->enemySpawnTimer += 1.f;
	}

	//Move and updating the enemies
//	for (auto& e : this->enemies)
	for (int i = 0; i < this->enemies.size(); i++)
	{
		bool deleted = false;
		this->enemies[i].move(0.f, 1.f);

		//Check if clicked upon
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (this->enemies[i].getGlobalBounds().contains(this->mousePosView));
			{
				deleted = true;

				//Gain points
				this->points += 10.f;
			}
		}

		//If the enemy is past the bottom of the screen
		if (this->enemies[i].getPosition().y > this->window->getSize().y)
		{
			deleted = true;
		}

		//Final delete
		if (deleted)
			this->enemies.erase(this->enemies.begin() + i);
	}
}

void Game::update()
{
	this->pollEvents();

	//Update mouse position
	//Relative to the screen
	//std::cout << "Mouse pos: " << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y << "\n";

	//Relative to the window
	std::cout << "Mouse pos: " << sf::Mouse::getPosition(*this->window).x << " " << sf::Mouse::getPosition(*this->window).y << "\n";


	this->updateMousePositions();

	this->updateEnemies();
}

void Game::renderEnemies()
{
	//Rendering all the enemies
	for (auto& e : this->enemies)
	{
		this->window->draw(e);
	}
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
	this->renderEnemies();

	this->window->display();
}
