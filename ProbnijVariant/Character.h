#pragma once
#include <ostream>
#include  "Essence.h";

typedef Essence::Sex Sex;
typedef Essence::State State;
typedef Essence::Race Race;

class Character : public Essence
{
public:
	explicit Character(Sex, Race,unsigned int);
	explicit Character();

	Race getRace() const;
	Sex getSex() const;
	unsigned int getMaxHealth() const;
	unsigned int getCurrentHealth() const;
	unsigned int getXP() const;
	State getState() const;
	unsigned char getAge() const;

	void setHealth(unsigned int);
	void incXP(int);
	void setState(State);
	void canSpeak(bool);
	void canMove(bool);
	void incAge();

	bool canSpeak() const;
	bool canMove() const;

	bool operator<(const Character&) const;
	bool operator>(const Character&) const;
	bool operator==(const Character&) const ;
	bool operator!=(const Character&) const;

	bool static compareByXP(const Character&, const Character&); 
private:
	unsigned const int _maxValue;
	const Race _race;
	const Sex _sex;
	unsigned int _currentValue;
	unsigned int _xpGained;
	const int _id;
	State _state;
	unsigned char _age;
	bool _canSpeak;
	bool _canMove;

	 unsigned char getHealtPercentage() const ;
	
	void checkHealth();
	void changeState(State) ;
	void changeOtherSets(State) ;
};

std::ostream& operator<<(std::ostream&, const Character&);
