#ifndef PALADIN_H
#define PALADIN_H

#include <cstring>
#include <iostream>

#include "hero.hpp"


using namespace std;




//////////////////////////////////////////////////////////////////////////////////////
//      ΚΛΑΣΣΗ PALADIN
// κληρονομεί την hero
//////////////////////////////////////////////////////////////////////////////////////
class paladin : public hero
{
public:
    // constructor
    paladin(const char *nam, int mp, int s, int d, int a) : hero(nam, mp, s, d, a)
    {

        // εκτύπωση σχετικού μηνύματος
        cout << " Here comes a Paladin " << endl;
        cout << "       In your service my lord!!!!!!" << endl;
    }

    void levelup(const int up = 1)
    {
        
        increase_strength(up*5);
        increase_dexterity(up*4);
        increase_agility(up*2);
        set_health(100);
        hero :: level_up(up);
    }

    // destructor
    ~paladin(){

        // εκτυπωσή σχετικού μηνύματος
        cout << " A paladin to be destroyd " << endl;
    }
};
#endif