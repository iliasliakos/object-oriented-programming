#include <cstring>
#include <iostream>

#include "item.hpp"
#include "hero.hpp"


using namespace std;




//////////////////////////////////////////////////////////////////////////////////////
//      ΚΛΑΣΣΗ POTION
// κληρονομεί την item
//////////////////////////////////////////////////////////////////////////////////////
class potion : public item
{
private:
    // ποσό αύξησης του στατιστικού του ήρωα
    int boost;

    // statistic == 1 -> αυξάνει το strength
    // statistic == 2 -> αυξάνει το agility
    // statistic == 3 -> αυξάνει το dexterity
    // statistic == 4 -> αυξάνει το health
    // statistic == 5 -> αυξάνει το magicpower
    int statistic;

public:
    // constructor
    potion(const char *nam, int p, int l, int b, int s) : item(nam, p, l) , boost(b), statistic(s)
    {

        // εκτύπωση σχετικού μηνύματος
        cout << "A New potion has been created! ";
    }

    // επιστρέφει το ποσό που αυξάνεται το στατιστικό του ήρωα
    int get(){

        return boost;
    }

    void print(){

        if(statistic == 1){

            cout << " potion with name " << get_name() << " price " << get_price() << " level " << get_level() << " boost the strength by " << boost << endl;
        }
        else if(statistic == 2){

            cout << " potion with name " << get_name() << " price " << get_price() << " level " << get_level() << " boost  the agility by " << boost << endl;
        }
        else if(statistic == 3){

            cout << " potion with name " << get_name() << " price " << get_price() << " level " << get_level() << " boost  the dexterity by " << boost << endl;
        }
        else if(statistic == 4){

            cout << " potion with name " << get_name() << " price " << get_price() << " level " << get_level() << " boost  the health by " << boost << endl;
        }
        else{

            cout << " potion with name " << get_name() << " price " << get_price() << " level " << get_level() << " boost  the magicpower by " << boost << endl;
        }
    }


    void equip(hero* h, int no){

        cout << " You cant equip a potion " << endl;
    }


    void use(hero* h, int pos){

        // αν το level του ήρωα αρκεί για να
        // χρησιμοποιήσει αυτό το potion
        if(h->get_level() >= get_level()){

            // βγάζουμε το potion από το 
            // backpack
            h->remove_from_backpack(pos);

            if(statistic == 1){

                h->increase_strength(boost);
            }
            else if(statistic == 2){

                h->increase_agility(boost);
            }
            else if(statistic == 3){

                h->increase_dexterity(boost);
            }
            else if(statistic == 4){

                h->increase_health(boost);
            }
            else{

                h->increase_magic_power(boost);
            }
        }
        else{

            // εκτύπωση σχετικού μηνύματος
            cout << " Only heroes that are at least " << get_level() << " level can use this potion " << endl;
        }    
    }

    // destructor
    ~potion(){

        // εκτύπωση σχετικού μηνύματος
        cout << "A potion to be destroyed! ";
    }
};