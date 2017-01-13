#include "Wizard.h"

Wizard::Wizard(Sex s, Race r, unsigned int hp, unsigned int mn) :_maxMana(mn), Character(s, r, hp)
{
	this->_mana = mn;
}

void Wizard::heal(Character& target, int h)
{
	if (!isEnoughMana(h))
		return;
	target.setHealth(target.getCurrentHealth() + h);
	this->_mana -= h * 2;
}

void Wizard::heal(Wizard& target, int h)
{
	if (!isEnoughMana(h))
		return;
	target.setHealth(target.getCurrentHealth() + h);
	this->_mana -= h * 2;
}

bool Wizard::isEnoughMana(int needToHealHP) const
{
	if (this->_mana * 2 >= needToHealHP)
		return true;
	return false;
}