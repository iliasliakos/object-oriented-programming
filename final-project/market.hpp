#include <cstring>
#include <iostream>
#include <vector>

#include "block.hpp"
#include "item.hpp"
#include "weapon.hpp"
#include "armor.hpp"
#include "potion.hpp"
#include "spell.hpp"
#include "firespell.hpp"
#include "icespell.hpp"
#include "lightingspell.hpp"
#include "hero.hpp"

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////
//                ΚΛΑΣΗ MARKET
//      κληρονομεί την block
/////////////////////////////////////////////////////////////////////////////////////
class market : public block
{
private:
    vector<item *> items;   // τα items που διαθέτει το market
    vector<spell *> spells; // τα spells που διαθέτει το market

public:
    // constructor
    market(int x, int y) : block(x, y)
    {

        // δημιουργία των items
        items.push_back(new weapon("Caladbolg", 10, 0, 10, 1));     //
        items.push_back(new weapon("Taming Sword", 10, 0, 10, 2));  //  weapons
        items.push_back(new weapon("Crystal Sword", 10, 0, 10, 1)); //
        items.push_back(new weapon("Excalibur", 10, 0, 10, 2)); //
        items.push_back(new weapon("Astral Sword", 10, 0, 10, 1)); //

        items.push_back(new armor("Endless Road", 10, 0, 2)); //
        items.push_back(new armor("Genji Shield", 10, 0, 1)); //  armors
        items.push_back(new armor("Emblem", 10, 0, 10));       //

        items.push_back(new potion("Hi-Potion", 0, 0, 10, 1));   //
        items.push_back(new potion("X-Potion", 0, 0, 10, 2));    //  potions
        items.push_back(new potion("Mega-Potion", 0, 0, 10, 3)); //
        items.push_back(new potion("Megalixir", 0, 0, 10, 4)); //
        items.push_back(new potion("Phoenix Down", 0, 0, 10, 5)); //
        items.push_back(new potion("Antidote", 10, 10, 10, 1)); //
        items.push_back(new potion("Holy Water", 10, 10, 10, 2)); //
        items.push_back(new potion("Healing Water", 10, 10, 10, 3)); //
        items.push_back(new potion("Candle of Life", 10, 10, 10, 4)); //
        items.push_back(new potion("Frag Grenade", 10, 10, 10, 5)); //

        // δημιουργια των spells
        spells.push_back(new firespell("Flame"));    //
        spells.push_back(new firespell("Inferno"));  //  firespells
        spells.push_back(new firespell("Fireball")); //

        spells.push_back(new icespell("Freeze"));    //
        spells.push_back(new icespell("Frostbite")); //  icespells
        spells.push_back(new icespell("Tsunami"));   //

        spells.push_back(new lightingspell("Light"));       //
        spells.push_back(new lightingspell("Flash"));       //  lightingspells
        spells.push_back(new lightingspell("Bolt Strike")); //
    }

    void display_map(){

        cout << "[M] ";
    }


    // εκτύπωση των items που διαθέτει το market
    int print_items()
    {

        cout << "           ITEMS " << endl;
        int y = 1;
        for (vector<item *>::iterator i = items.begin(); i != items.end(); ++i)
        {

            cout << y << " ";
            y++;
            (*i)->print();
        }

        return items.size();
    }

    // εκύπωση των spells που διαθέτει το market
    int print_spells()
    {

        cout << "           SPELLS" << endl;
        int y = 1;
        for (vector<spell *>::iterator z = spells.begin(); z != spells.end(); ++z)
        {

            cout << y << " ";
            y++;
            (*z)->print();
        }

        return spells.size();
    }

    void buy_spells(hero *h)
    {

        cout << " Select the spell that you want to buy " << endl;
        cout << "To select press the right number or press 0 if you dont want to buy " << endl;

        int number_of_products;

        // εκτύπωση των items
        number_of_products = print_spells();

        cout << "items size = " << number_of_products << endl;

        string select2;
        int no;

        while (1)
        {

            // διάβασμα της επιλογής του παίχτη
            cin >> select2;

            // μετατροπή της εισόδου σε int
            stringstream convert_select2(select2);
            convert_select2 >> no;

            // έλεγχος εισόδου
            if (no < 0 || no > number_of_products)
            {

                cout << "There is no such an option , please try again " << endl;
            }
            else
            {

                break;
            }
        }

        if (no != 0)
        {

            spell *it = spells.at(no - 1);

            // έλεγχος για το αν ο ήρωας έχει τα λεφτά
            // να αγοράσει το spell που επέλεξε
            if (h->get_money() < it->getcost())
            {

                // εκτύπωση σχετικού μηνύματος
                cout << " To buy this item you need " << it->getcost() - h->get_money() << " more coins " << endl;
            }
            else
            {

                // κλήση της buy_spell του ήρωα
                // με όρισμα το spell που διάλεξε ο παίχτης
                h->buy_spell(it);
            }
        }
    }


    void buy_items(hero *h)
    {

        cout << " Select the item that you want to buy " << endl;
        cout << "To select press the right number or press 0 if you dont want to buy " << endl;

        int number_of_products;

        // εκτύπωση των items
        number_of_products = print_items();

        cout << "items size = " << number_of_products << endl;

        string select2;
        int no;

        while (1)
        {

            // διάβασμα της επιλογής του παίχτη
            cin >> select2;

            // μετατροπή της εισόδου σε int
            stringstream convert_select2(select2);
            convert_select2 >> no;

            // έλεγχος εισόδου
            if (no < 0 || no > number_of_products)
            {

                cout << "There is no such an option , please try again " << endl;
            }
            else
            {

                break;
            }
        }

        if (no != 0)
        {

            item* it = items.at(no - 1);

            // έλεγχος για το αν ο ήρωας έχει τα λεφτά
            // να αγοράσει το item που επέλεξε
            if (h->get_money() < it->get_price())
            {

                // εκτύπωση σχετικού μηνύματος
                cout << " To buy this item you need " << it->get_price() - h->get_money() << " more coins " << endl;
            }
            else
            {

                // κλήση της buy_item του ήρωα
                // με όρισμα το item που διάλεξε ο παίχτης
                h->buy_item(it);
            }
        }
    }


    void interact_with(Party p)
    {

        // ενημέρωση των συντεταγμένων του Party
        p->coordinates_of_party->x = get_x();
        p->coordinates_of_party->y = get_y();

        // εκτύπωση σχετικού μηνύματος
        cout << " Your party moved to a market block " << endl;
        

        char entry;
        while (1)
        {

            cout << " Press b if you want to buy spells " << endl;
            cout << " Press n if you want to buy items" << endl;
            cout << " Press s if you want to sell an item " << endl;
            cout << " Press a if you want to sell a spell " << endl;
            cout << " Press q if you want to quit the market's menu " << endl;
            
            while (1)
            {

                // διάβασμα της επιλογής του παίχτη
                cin >> entry;

                // έλεγχος εισόδου
                if (entry != 'b' && entry != 'n' && entry != 's' && entry != 'q' && entry != 'a')
                {

                    cout << "There is no such an option , please try again " << endl;
                }
                else
                {

                    break;
                }
            }

            // αν επέλεξε να κάνει quit
            if (entry == 'q')
            {

                break;
            }
            // αν επέλεξε να κάνει sell
            else if (entry == 's' || entry == 'a')
            {

                cout << " Choose the hero that you want him to sell " << endl;
                cout << " To choose the hero press his number " << endl;

                int i = 1;
                for (vector<hero *>::iterator r = p->heroes.begin(); r != p->heroes.end(); ++r)
                {

                    cout << i << " " << (*r)->get_name() << endl;
                    i++;
                }

                string select;
                int number;
                while (1)
                {

                    // διάβασμα της επιλογής του παίχτη
                    cin >> select;

                    // μετατροπή της εισόδου σε int
                    stringstream convert_select(select);
                    convert_select >> number;

                    // έλεγχος εισόδου
                    if (number < 1 || number > p->heroes.size())
                    {

                        cout << "There is no such an option , please try again " << endl;
                    }
                    else
                    {

                        break;
                    }
                }

                hero *h = p->heroes.at(number - 1);

                // αν ο παίχτης διάλεξε να πουλήσει spell
                if(entry == 'a'){

                    h->sell_spells();
                }
                // αν διάλεξε να πουλήσει item
                else{

                    h->sell_items();
                }
            }
            // αν επέλεξε να κάνει buy
            else
            {

                cout << " Choose the hero that you want him to buy " << endl;
                cout << " To choose the hero press his number " << endl;

                int i = 1;
                for (vector<hero *>::iterator r = p->heroes.begin(); r != p->heroes.end(); ++r)
                {

                    cout << i << " " << (*r)->get_name() << endl;
                    i++;
                }

                string select;
                int number;
                while (1)
                {

                    // διάβασμα της επιλογής του παίχτη
                    cin >> select;

                    // μετατροπή της εισόδου σε int
                    stringstream convert_select(select);
                    convert_select >> number;

                    // έλεγχος εισόδου
                    if (number < 1 || number > p->heroes.size())
                    {

                        cout << "There is no such an option , please try again " << endl;
                    }
                    else
                    {

                        break;
                    }
                }

                hero *h = p->heroes.at(number - 1);

                // αν επέλεξε να αγοράσει spell
                if (entry == 'b')
                {

                    buy_spells(h);
                }
                // αν επέλεξε να αγοράσει item
                else
                {

                    buy_items(h);
                }
            }
        }
    }

    // destructor
    ~market()
    {

        // αποδέσμευση χώρου για τα item
        for (vector<item *>::iterator r = items.begin(); r != items.end(); ++r)
        {

            delete *r;
        }

        items.clear();

        // αποδέσμευση χώρου για τα spell
        for (vector<spell *>::iterator r = spells.begin(); r != spells.end(); ++r)
        {

            delete *r;
        }

        spells.clear();


        // εκτύπωση σχετικού μηνύματος
        cout << " A market to be destroyd " << endl;
    }
};