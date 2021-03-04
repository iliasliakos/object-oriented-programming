#include <cstring>
#include <iostream>

#include "monster.hpp"

using namespace std;

//////////////////////////////////////////////////////////////////////////////////////
//      ΚΛΑΣΣΗ EXOSKELETON
// κληρονομεί την MONSTER
//////////////////////////////////////////////////////////////////////////////////////
class exoskeleton : public monster
{
public:
    
    // constructor
    exoskeleton(const char *nam, const int mind, const int maxd, const int def, const int av) : monster(nam, mind, maxd, def, av)
    {

    }

    // destructor
    ~exoskeleton()
    {

    }

    void print()
    {
        cout << "Exoskeleton Monster" << endl;
        monster::print();
    }

    void print_all(){
        
        cout<<"Exoskeleton ";
        monster :: print_all();
    }

    void levelup(const int c)
    {
        if (c >=0)
        {
            
            increase_maxdamage(c*3);
            increase_mindamage(c*2);
            increase_defence(c*4);
            increase_avoid(c);   
            monster :: level_up(c);
        }

        else cout<<"wrong level up input"<<endl;
    }
};