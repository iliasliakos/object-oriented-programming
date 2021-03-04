#include <cstring>
#include <iostream>

#include "item.hpp"
#include "hero.hpp"


using namespace std;




//////////////////////////////////////////////////////////////////////////////////////
//      ΚΛΑΣΣΗ ARMOR
// κληρονομεί την item
//////////////////////////////////////////////////////////////////////////////////////
class armor : public item
{
private:
    // κατά πόσο θα μειωθεί η ζημία που δέχεται ο ήρωας
    int damages_decrease;

public:
    // constructor
    armor(const char *nam, int p, int l, int d) : item(nam, p, l) , damages_decrease(d)
    {

    }

    // επιστρέφει το ποσό που μειώνει τη ζημιά που δέχεται ο ήρωας
    int get(){

        return damages_decrease;
    }

    void print(){

        cout << " armor with name " << get_name() << " price " << get_price() << " level " << get_level() << " decrease the incoming damage from the enemies by " << damages_decrease << endl;
    }

    void equip(hero* h, int pos){

        // αν το level του ήρωα αρκεί για να
        // χρησιμοποιήσει αυτήν την armor
        if(h->get_level() >= get_level()){

            // αφαίρεση του armor από το backpack του ήρωα
            h->remove_from_backpack(pos);

            EquippedItems* e = h->get_equipped_items();

            if(e->hero_armor == NULL){

                e->hero_armor = this;
            }
            else{

                // βάζουμε το armor πίσω στο backpack
                h->put_in_backpack(e->hero_armor);

                // εξοπλίζει τον ήρωα με το νέο armor
                e->hero_armor = this;
            }
        }
        else{

            // εκτύπωση σχετικού μηνύματος
            cout << " Only heroes that are at least " << get_level() << " level can use this armor " << endl;
        }    
    }


    void use(hero* h, int pos){

        cout << " You cant use a armor " << endl;
    }


    // destructor
    ~armor(){

     }
};