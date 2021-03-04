#ifndef SPELL_H
#define SPELL_H

#include <cstring>
#include <iostream>

using namespace std;
///////////////////////////////////////////////////////////////////////////////////////
//                ΚΛΑΣΗ SPELL
//
/////////////////////////////////////////////////////////////////////////////////////
class spell
{
private:
    char *name;
    int cost;
    int minlevel;
    int mindam;
    int maxdam;
    int magicpower;

public:

    // constructor
    spell(const char *nam, const int c = 20, const int lvl = 0, const int mind = 10, const int maxd = 35, const int mgc = 15) : cost(c), minlevel(lvl), mindam(mind), maxdam(maxd), magicpower(mgc)
    {

        // δέσμευση χώρου για το name
        name = new char[strlen(nam) + 1];

        // αντιγραφή του string nam στο name
        strcpy(name, nam);
    }

    // destructor
    virtual ~spell()
    {

        // αποδέσμευση χώρου για το name
        delete[] name;

    }

    // επιστρέφει το cost
    int getcost()const
    {

        return cost; 
    }

    // επιστρέφει το level
    int getlevel() const 
    { 
        
        return minlevel; 
    }

    // επιστρέφει το mindam
    int getmindam() const 
    { 
        
        return mindam; 
    }

    // επιστρέφει το maxdam
    int getmaxdam() const 
    { 
        
        return maxdam; 
    }

    // επιστρέφει το magicpower
    int getmagic() const 
    { 
        
        return magicpower; 
    }

    // επιστρέφει το name
    char *getname() const 
    { 
        
        return name; 
    }


    virtual void print() = 0;
};
#endif