#include "Character.h"
#include <iostream>

static int _totalCount;

Character::Character(Sex sex, Race race, unsigned int maxHealth) :_maxValue(maxHealth), _sex(sex), _race(race), _id(_totalCount++)
{
	this->_age = 11;
	this->_canMove = true;
	this->_canSpeak = true;
	this->_xpGained = 0;
	this->_currentValue = this->_maxValue;
	this->_state = State::normal;
}

Character::Character() :_maxValue(1000), _sex(female), _race(elf), _id(_totalCount++)
{}

Race Character::getRace() const
{
	return this->_race;
}

Sex Character::getSex() const
{
	return this->_sex;
}

unsigned Character::getMaxHealth() const
{
	return this->_maxValue;
}

unsigned Character::getCurrentHealth() const
{
	return this->_currentValue;
}

unsigned Character::getXP() const
{
	return this->_xpGained;
}

State Character::getState() const
{
	return this->_state;
}

unsigned char Character::getAge() const
{
	return this->_age;
}

void Character::setHealth(unsigned int health)
{
	if (health <= this->_maxValue)
		this->_currentValue = health;
	else
		std::cout << "Health exceeds limit" << std::endl;
}

void Character::incXP(int xp)
{
	this->_xpGained += xp;
}

void Character::setState(State state)
{
	this->_state = state;
}

void Character::canSpeak(bool value)
{
	this->_canSpeak = value;
}

void Character::canMove(bool value)
{
	this->_canMove = value;
}

void Character::incAge()
{
	if (this->_age < UCHAR_MAX)
		this->_age++;
}

bool Character::canSpeak() const
{
	return this->_canSpeak;
}

bool Character::canMove() const
{
	return this->_canMove;
}

bool Character::operator<(const Character& another) const
{
	return Character::compareByXP(*this, another);
}

bool Character::operator>(const Character& another) const
{
	return !this->operator<(another);
}

bool Character::compareByXP(const Character& c1, const Character& c2)
{
	return (c1._xpGained < c2._xpGained) ? true : false;
}

unsigned char Character::getHealtPercentage() const
{
	return (_currentValue / _maxValue) * 100;
}

void Character::checkHealth()
{
	if (this->getHealtPercentage() == 0)
	{
		this->_state = State::dead;
		return;
	}

	if (this->getHealtPercentage() < 10)
		this->changeState(State::sick);
	else
		this->changeState(State::normal);
}

void Character::changeState(State to)
{
	if (this->_state != State::dead)
		this->_state = to;
}

void Character::changeOtherSets(State s)
{
	switch (s)
	{
	paralized: _canMove = false;
		break;
	dead:
		_canMove = false;
		_canSpeak = false;
		break;
	default: break;
	}
}

std::ostream& operator<<(std::ostream& o, const Character& person)
{
	o << Essence::getStringRace(person.getRace()).c_str() << " " << Essence::getStringSex(person.getSex()).c_str() << " HP: " << person.getCurrentHealth()
		<< "/" << person.getMaxHealth() << "XP: "<< person.getXP() << std::endl;
	return o;
}