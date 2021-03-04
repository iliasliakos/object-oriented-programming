#include <cstring>
#include <iostream>

#include "monster.hpp"



using namespace std;
//////////////////////////////////////////////////////////////////////////////////////
//      ΚΛΑΣΣΗ SPIRIT
// κληρονομεί την MONSTER
//////////////////////////////////////////////////////////////////////////////////////
class spirit : public monster
{
public:

    // constructor
    spirit(const char *nam, const int mind, const int maxd, const int def, const int av) : monster(nam, mind, maxd, def, av)
    {

        cout << "\nUnseen  haunter has been raised from underworld...\n 			ywahhhhn!" << endl;
        cout << "\n 	..Applying Spiritual effect of better avoidance..." << endl;
    }

    // destructor
    ~spirit()
    {
        
    }

    void print()
    {
        
        cout << "Spirit Monster" << endl;
        monster::print();
    }

    void levelup(const int c)
    {
        if (c >=0)
        {
            increase_maxdamage(c*3);
            increase_mindamage(c*2);
            increase_defence( c*2);
            increase_avoid(c*2);   
            monster :: level_up(c);
        }

        else cout<<"wrong level up input"<<endl;
    }

    void print_all(){
        
        cout<<"Spirit ";
        monster :: print_all();
    }
};