#pragma once
class Essence
{
public:
	enum State
	{
		normal,
		sick,
		ill,
		spoiled,
		paralized,
		dead
	};
	enum Race
	{
		human,
		dwarf,
		elf,
		ork,
		dragon
	};
	enum Sex
	{
		male,
		female
	};
	static std::string getStringRace(Race);
	static std::string getStringSex(Sex);
};

inline std::string Essence::getStringRace(Race race)
{
	switch (race)
	{
	case human:return "human";
	case dwarf: return "dwarf";
	case elf: return "elf";
	case ork: return "ork";
	case dragon: return "dargon";
	default: return "";
	}
}

inline std::string Essence::getStringSex(Sex sex)
{
	switch(sex)
	{
	case male: return "male";
	case female: return "female";
	default: return "";
	}
}