#include <cstring>
#include <iostream>

#include "spell.hpp"

using namespace std;
//////////////////////////////////////////////////////////////////////////////////////
//      ΚΛΑΣΣΗ LIGHTINGSPELL
// κληρονομεί την spell
//////////////////////////////////////////////////////////////////////////////////////
class lightingspell : public spell
{
private:
    int decrease_of_enemy_avoidance;    // το ποσό μείωσης της πιθανότητας αποφυγής του αντιπάλου
    int rounds; // για πόσους γύρους γίνεται η μείωση της πιθανότητας αποφυγής του αντιπάλου

public:

    // constructor
    lightingspell(const char *nam, const int c = 20, const int lvl = 0, const int mind = 10, const int maxd = 35, const int mgc = 15) : spell(nam, c, lvl, mind, maxd, mgc), decrease_of_enemy_avoidance(10), rounds(2)
    {

    }

    // destructor
    ~lightingspell() 
    { 
        
    }

    void print()
	{

		cout << " lightingpell with name " << getname() << " price " << getcost() << " level " << getlevel() << " magic power needed " << getmagic() << " damage range " << getmindam() << "-" << getmaxdam() << " decrease the enemy's chance to avoid a hit by " << decrease_of_enemy_avoidance << " for " << rounds << " rounds " << endl;
	}
};