#pragma once

class PlayerCharacter
{
private:
	//Player attributes
	int strength;
	int agility;
	int willpower;
	int intelligence;
	int endurance;
	int speed;
	int personality;
	int luck;

public:
	//Constructor / Destructor
	PlayerCharacter();
	virtual ~PlayerCharacter();

	//Setters for attributes
	void increaseStrength(int value);
	void increaseAgility(int value);
	void increaseWillpower(int value);
	void increaseIntelligence(int value);
	void increaseEndurance(int value);
	void increaseSpeed(int value);
	void increasePersonality(int value);
	void increaseLuck(int value);

	void decreaseStrength(int value);
	void decreaseAgility(int value);
	void decreaseWillpower(int value);
	void decreaseIntelligence(int value);
	void decreaseEndurance(int value);
	void decreaseSpeed(int value);
	void decreasePersonality(int value);
	void decreaseLuck(int value);

	//Public functions
	void initVariables();
};

