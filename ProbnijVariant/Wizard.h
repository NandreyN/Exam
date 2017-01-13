#pragma once
#include "Character.h"
class Wizard :
	public Character
{
public:
	Wizard();
	void heal(Character&, int);
	void heal(Wizard&, int);
private:
	unsigned const int _maxMana;
	unsigned int _mana;
	bool isEnoughMana() const;
};

std::ofstream operator<<(std::ofstream&, Wizard&);
