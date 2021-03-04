#include <cstring>
#include <iostream>

#include "block.hpp"


using namespace std;




/////////////////////////////////////////////////////////////////////////////////////
//                ΚΛΑΣΣΗ NONACCESSIBLE
//      κληρονομεί την block
/////////////////////////////////////////////////////////////////////////////////////
class nonAccessible : public block
{
public:
    // constructor
    nonAccessible(int x, int y) : block(x, y)
    {

        // εκτύπωση σχετικού μηνύματος
        cout << " A nonAccessible just created " << endl;
    }


    void display_map(){

        cout << "[X] ";
    }

    void interact_with(Party p){

        // εκτύπωση σχετικού μηνύματος
        cout << " This block is nonAccessible. You cant move to it " << endl;
    }

    // destructor
    ~nonAccessible(){

        // εκτύπωση σχετικού μηνύματος
        cout << " A nonAccessible to be destroyd" << endl;
    }
};