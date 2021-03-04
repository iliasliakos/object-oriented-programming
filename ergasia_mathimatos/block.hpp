#ifndef BLOCK_H
#define BLOCK_H

#include <cstring>
#include <iostream>

//#include "party.hpp"
#include "grid.hpp"


using namespace std;




/////////////////////////////////////////////////////////////////////////////////////
//                ΚΛΑΣΗ BLOCK
//
/////////////////////////////////////////////////////////////////////////////////////
class block
{
private:
    // συντεταγμένες του τετραγώνου
    int x;
    int y;

public:
    // constructor
    block(int i, int z) : x(i), y(z)
    {

        // εκτύπωση σχετικού μηνύματος
        cout << " block constructor " << endl;
    }

    virtual void interact_with(Party p) = 0;

    // επιστρέφει το x
    int get_x(){

        return x;
    }

    // επιστρέφει το y
    int get_y(){

        return y;
    }

    virtual void display_map() = 0;

    // destructor
    virtual ~block(){

        // εκτύπωση σχετικού μηνύματος
        cout << " block to be destroyd " << endl;
    }
};
#endif