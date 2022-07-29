#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter()
{
	initVariables();
}

PlayerCharacter::~PlayerCharacter()
{

}

//Setters for attributes
void PlayerCharacter::increaseStrength(int value)
{
	this->strength += value;
}

void PlayerCharacter::increaseAgility(int value)
{
	this->agility += value;
}

void PlayerCharacter::increaseWillpower(int value)
{
	this->willpower += value;
}

void PlayerCharacter::increaseIntelligence(int value)
{
	this->intelligence += value;
}

void PlayerCharacter::increaseEndurance(int value)
{
	this->endurance += value;
}

void PlayerCharacter::increaseSpeed(int value)
{
	this->speed += value;
}

void PlayerCharacter::increasePersonality(int value)
{
	this->personality += value;
}

void PlayerCharacter::increaseLuck(int value)
{
	this->luck += value;
}


void PlayerCharacter::decreaseStrength(int value)
{
	this->strength -= value;
}

void PlayerCharacter::decreaseAgility(int value)
{
	this->agility -= value;
}

void PlayerCharacter::decreaseWillpower(int value)
{
	this->willpower -= value;
}

void PlayerCharacter::decreaseIntelligence(int value)
{
	this->intelligence -= value;
}

void PlayerCharacter::decreaseEndurance(int value)
{
	this->endurance -= value;
}

void PlayerCharacter::decreaseSpeed(int value)
{
	this->speed -= value;
}

void PlayerCharacter::decreasePersonality(int value)
{
	this->personality -= value;
}

void PlayerCharacter::decreaseLuck(int value)
{
	this->luck -= value;
}

void PlayerCharacter::initVariables()
{
	this->strength = 30;
	this->agility = 30;
	this->willpower = 30;
	this->intelligence = 30;
	this->endurance = 30;
	this->speed = 30;
	this->personality = 30;
	this->luck = 30;
}
