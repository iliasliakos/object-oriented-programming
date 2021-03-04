#include <cstring>
#include <iostream>

#include "spell.hpp"

using namespace std;
//////////////////////////////////////////////////////////////////////////////////////
//      ΚΛΑΣΣΗ FIRESPELL
// κληρονομεί την spell
//////////////////////////////////////////////////////////////////////////////////////
class firespell : public spell
{
private:
	int decrease_of_enemy_defence;	// το ποσό μείωσης της άμυνας του αντιπάλου

public:

	// constructor
	firespell(const char *nam, const int c = 20, const int lvl = 0, const int mind = 10, const int maxd = 35, const int mgc = 15) : spell(nam, c, lvl, mind, maxd, mgc), decrease_of_enemy_defence(10)
	{

		cout << "Ragnarok  illuminated human.The " << getname() << "  spell is yours" << endl;
	}

	// destructor
	~firespell()
	{
		cout << "Ragnarok obliviated man .Took back the knowledge of " << getname() << endl;
	}
	
	
	void print()
	{

		cout << " firespell with name " << getname() << " price " << getcost() << " level " << getlevel() << " magic power needed " << getmagic() << " damage range " << getmindam() << "-" << getmaxdam() << " decrease the enemy's defence by " << decrease_of_enemy_defence << endl;
	}
};