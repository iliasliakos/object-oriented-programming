#include <cstring>
#include <iostream>

#include "spell.hpp"

using namespace std;
//////////////////////////////////////////////////////////////////////////////////////
//      ΚΛΑΣΣΗ ICESPELL
// κληρονομεί την spell
//////////////////////////////////////////////////////////////////////////////////////
class icespell : public spell
{
private:
    int decrease_of_enemy_damage;   // το ποσό μείωσης της ζημιάς που προκαλεί ο αντίπαλος

public:

    // constructor
    icespell(const char *nam, const int c = 20, const int lvl = 0, const int mind = 10, const int maxd = 35, const int mgc = 15) : spell(nam, c, lvl, mind, maxd, mgc), decrease_of_enemy_damage(10)
    {

        cout << "Poseidon  have donated the power of " << getname() << endl;
    }

    // destructor
    ~icespell() { 

        cout << "Poseidon obliviated man .Took back the knowledge of " << getname() << endl; 
    }

    void print()
	{

		cout << " icespell with name " << getname() << " price " << getcost() << " level " << getlevel() << " magic power needed " << getmagic() << " damage range " << getmindam() << "-" << getmaxdam() << " decrease the enemy's damage by " << decrease_of_enemy_damage << endl;
	}
};