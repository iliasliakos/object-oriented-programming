#ifndef WARRIOR_H
#define WARRIOR_H

#include <cstring>
#include <iostream>
#include <vector> 

#include "hero.hpp"
#include "item.hpp"


using namespace std;




//////////////////////////////////////////////////////////////////////////////////////
//      ΚΛΑΣΣΗ WARRIOR
// κληρονομεί την hero
//////////////////////////////////////////////////////////////////////////////////////
class warrior : public hero
{
public:
    // constructor
    warrior(const char *nam, int mp, int s, int d, int a) : hero(nam, mp, s, d, a)
    {

        // εκτύπωση σχετικού μηνύματος
        cout << " Here comes a Warrior " << endl;
        cout << "       Pride and dignity!!!!!!" << endl;
    }

    void levelup(const int up)
    {
        
        
        increase_strength(up*5);
        increase_dexterity(up*2);
        increase_agility(up*4);
        set_health(100);
        hero :: level_up(up);
    }

    // destructor
    ~warrior(){

     }
};

#endif