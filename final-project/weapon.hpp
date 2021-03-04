#include <cstring>
#include <iostream>

#include "item.hpp"
#include "hero.hpp"


using namespace std;




//////////////////////////////////////////////////////////////////////////////////////
//      ΚΛΑΣΣΗ WEAPON
// κληρονομεί την item
//////////////////////////////////////////////////////////////////////////////////////
class weapon : public item
{
private:
    int damage; // η ζημιά που προκαλεί
    // hand == 1 --> απαιτείται ένα χέρι για να χρησιμοποιηθεί
    // hand == 2 --> απαιτούνται 2 χέρια για να χρησιμοποιηθεί
    int number_of_hands;

public:
    // constructor
    weapon(const char *nam, int p, int l, int d, int h) : item(nam, p , l), damage(d), number_of_hands(h)
    {

    }

    // επιστρέφει τη ζημιά που προκαλεί
    int get(){

        return damage;
    }

    void print(){

        cout << " weapon with name " << get_name() << " price " << get_price() << " level " << get_level() << " damage " << damage << " hands needed " << number_of_hands << endl;
    }

    // επιστρέφει το πλήθος των χεριών που χρειάζεται
    int get_number_of_hands(){

        return number_of_hands;
    }

    void equip(hero* h, int pos){

        // αν το level του ήρωα αρκεί για να
        // χρησιμοποιήσει αυτό το weapon
        if(h->get_level() >= get_level()){

            // αφαίρεση του weapon από το backpack του ήρωα
            h->remove_from_backpack(pos);

            EquippedItems* e = h->get_equipped_items();

            // αν ο ήρωας έχει 2 ελεύθερα χέρια
            if(e->free_hands == 2){

                // τον εξοπλίζουμε με το νέο όπλο
                e->hero_weapon1 = this;

                // ενημέρωση των ελεύθερων χεριών
                if(number_of_hands == 2){

                    e->free_hands = 0;
                }
                else{

                    e->free_hands = 1;
                }

                return;
            }

            // αν το όπλο που θέλει να κάνει equip 
            // χρείαζεται 2 χέρια
            if(number_of_hands == 2){

                // αν ο ήρωας χρησιμοποιεί 2 όπλα
                if(e->hero_weapon1 != NULL && e->hero_weapon2 != NULL){

                    // βάζουμε και τα 2 όπλα που χρησιμοποιεί
                    // πίσω στο backpack
                    h->put_in_backpack(e->hero_weapon1);
                    h->put_in_backpack(e->hero_weapon2);

                    // αφαιρούμε τα weapons από τα 
                    // equipped items του ήρωα
                    e->hero_weapon1 = NULL;
                    e->hero_weapon2 = NULL;
                }
                // αν χρησιμοποιεί ένα όπλο
                else if(e->hero_weapon1 != NULL || e->hero_weapon2 != NULL){

                    // βρίσκουμε αυτό το όπλο και το βάζουμε πίσω
                    // στο backpack
                    if(e->hero_weapon1 != NULL){

                        h->put_in_backpack(e->hero_weapon1);

                        // αφαιρούμε το weapon από τα
                        // equipped items του ήρωα
                        e->hero_weapon1 = NULL;
                    }
                    else{

                        h->put_in_backpack(e->hero_weapon2);

                        // αφαιρούμε το weapon από τα
                        // equipped items του ήρωα
                        e->hero_weapon2 = NULL;
                    }
                }

                // εξοπλίζουμε τον ήρωα με το νέο weapon
                e->hero_weapon1 = this;

                // ενημέρωση των ελεύθερων χεριών
                e->free_hands = 0;
            }
            // αν το όπλο που θέλει να κάνει equip
            // χρείαζεται 1 χέρι
            else if(number_of_hands == 1){

                // αν ο ήρωας δεν έχει κανένα
                // ελεύθερο χέρι
                if(e->free_hands == 0){

                    // αν ο ήρωας χρησιμοποιεί 2 όπλα
                    if(e->hero_weapon1 != NULL && e->hero_weapon2 != NULL){

                        // ρωτάμε το χρήστη ποιό όπλο θέλει
                        // να βγάλει για να μπει το νέο στη θέση του

                        cout << " Press the number of the weapon you want to change with the new weapon " << endl;

                        cout << "1 ";
                        e->hero_weapon1->print();
                        cout <<"2 ";
                        e->hero_weapon2->print();

                        string input;
                        int number = 0;
                        while (1)
                        {

                            // διάβασμα της επιλογής του παίχτη
                            cin >> input;

                            // μετατροπή της εισόδου σε int
                            stringstream convert_input(input);
                            convert_input >> number;

                            // έλεγχος εισόδου
                            if (number < 1 || number > 2)
                            {

                                cout << "There is no such an option , please try again " << endl;
                            }
                            else
                            {

                                break;
                            }
                        }    

                        cout << number << endl;

                        if(number == 1){

                            cout << "mpikeeee " << endl;

                            // βάζουμε το όπλο πίσω
                            // στο backpack
                            h->put_in_backpack(e->hero_weapon1);

                            // εξοπλίζουμε τον ήρωα με το νέο weapon
                            e->hero_weapon1 = this;
                        }
                        else{

                            // βάζουμε το όπλο πίσω
                            // στο backpack
                            h->put_in_backpack(e->hero_weapon2);

                            // εξοπλίζουμε τον ήρωα με το νέο weapon
                            e->hero_weapon2 = this;
                        }
                    }
                    // αν χρησιμοποιεί ένα όπλο που χρείαζεται 2 χέρια
                    else if(e->hero_weapon1 != NULL || e->hero_weapon2 != NULL){

                        // βρίσκουμε αυτό το όπλο και το βάζουμε πίσω
                        // στο backpack
                        if(e->hero_weapon1 != NULL){

                            h->put_in_backpack(e->hero_weapon1);

                            // αφαιρούμε το weapon από τα
                            // equipped items του ήρωα
                            e->hero_weapon1 = NULL;
                        }
                        else{

                            h->put_in_backpack(e->hero_weapon2);

                            // αφαιρούμε το weapon από τα
                            // equipped items του ήρωα
                            e->hero_weapon2 = NULL;
                        }

                        // εξοπλίζουμε τον ήρωα με το νέο weapon
                        e->hero_weapon1 = this;

                        // ενημέρωση των ελεύθερων χεριών
                        e->free_hands = 1;
                    }
                }
                // αν ο ήρωας έχει ένα ελεύθερο χέρι
                else if(e->free_hands == 1){

                    // βρίσκουμε την ελεύθερη θέση 
                    // και εξοπλίζουμε τον ήρωα με το νέο
                    // weapon
                    if(e->hero_weapon1 == NULL){

                        e->hero_weapon1 = this;
                    }
                    else{

                        e->hero_weapon2 = this;
                    }

                    // ενημέρωση των ελεύθερων χεριών
                    e->free_hands = 0;
                }
            }

            
        }
        else{

            // εκτύπωση σχετικού μηνύματος
            cout << " Only heroes that are at least " << get_level() << " level can use this weapon " << endl;
        }    
    }

    void use(hero* h, int pos){

        cout << " You cant use a weapon " << endl;
    }

    // destructor
    ~weapon()
    {

    }
};
