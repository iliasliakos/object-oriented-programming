#include <cstring>
#include <iostream>

#include "monster.hpp"

using namespace std;

//////////////////////////////////////////////////////////////////////////////////////
//      ΚΛΑΣΣΗ DRAGON
// κληρονομεί την MONSTER
//////////////////////////////////////////////////////////////////////////////////////
class dragon : public monster
{
public:

	// constructor
	dragon(const char *nam, const int mind, const int maxd, const int def, const int av) : monster(nam, mind, maxd, def, av)
	{

		cout << "\nA dragon has landed nearby!\n 			GHHHRHOAAOR!" << endl;
		cout << "	... Applying dragon effect of bigger damage ..." << endl;
	}

	// destructor
	~dragon()
	{

		cout << "A Dragon will be destructed with name : " << endl;
		cout << "			Sweet dreams little chic!!\n" << endl;
	}

	void level_up(const int c)
	{
		if (c >= 0)
		{

			increase_maxdamage(c * 4);
			increase_mindamage(c * 3);
			increase_defence(c * 2);
			increase_avoid(c);
			monster :: level_up(c);
		}

		else
			cout << "wrong level up input" << endl;
	}

	void print()
	{
		cout << "Dragon Monster" << endl;
		monster::print();
	}

	void print_all()
	{

		cout << "Dragon ";
		monster ::print_all();
	}
};