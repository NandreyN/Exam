#pragma once
#include "Character.h"
class Wizard :
	public Character
{
public:
	Wizard(Sex, Race, unsigned int, unsigned int);
	void heal(Character&, int);
	void heal(Wizard&, int);
private:
	unsigned const int _maxMana;
	unsigned int _mana;
	bool isEnoughMana(int) const;
};

std::ofstream operator<<(std::ofstream&, Wizard&);
