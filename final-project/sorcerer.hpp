#ifndef SORCERER_H
#define SORCERER_H

#include <cstring>
#include <iostream>

#include "hero.hpp"


using namespace std;




//////////////////////////////////////////////////////////////////////////////////////
//      ΚΛΑΣΣΗ SORCERER
// κληρονομεί την hero
//////////////////////////////////////////////////////////////////////////////////////
class sorcerer : public hero 
{
public:
    // constructor
    sorcerer(const char *nam, int mp = 100, int s = 10, int d = 10, int a = 10) : hero(nam, mp, s, d, a)
    {
        // εκτύπωση σχετικού μηνύματος
        cout << " Here comes a Sorcerer " << endl;
        cout << "       abra kadabra!!!!! " << endl;
    }

    void levelup(const int up = 1)
    {
        
        increase_strength(up*2);
        increase_dexterity(up*5);
        increase_agility(up*4);
        set_health(100);
        set_level(up);
        hero :: level_up(up);
    }

    // destructor
    ~sorcerer(){

     }
};
#endif