#include <iostream>
#include  "Wizard.h"
using namespace std;

int main()
{
	Character c(Character::Sex::female, Character::Race::dragon,1050); 
	cout << c << endl;
	return 0;
}