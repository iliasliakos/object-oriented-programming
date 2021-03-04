#ifndef HERO_H
#define HERO_H

#include <cstring>
#include <iostream>
#include <string.h>

#include "living.hpp"
#include "spell.hpp"


using namespace std;

#include "item.hpp"

// ορισμός ενός struct που περιγράφει
// τα αντικείμενα που έχει κανεί equip/use ο ήρωας
typedef struct equipped_items{

    item* hero_armor;
    item* hero_weapon1;
    item* hero_weapon2;

    int free_hands;
}EquippedItems;


//////////////////////////////////////////////////////////////////////////////////////
//      ΚΛΑΣΣΗ HERO
// κληρονομεί την LIVING
//////////////////////////////////////////////////////////////////////////////////////
class hero : public living
{
private:
    // ορισμός του backpack του ήρωα
    typedef struct backpack{

        vector< spell*> spells;
        vector< item*> items;
    }Backpack;


    EquippedItems* equipped_items_of_hero; // εδώ μπαίνουν τα αντικείμενα που κάνει equip ο ήρωας
    Backpack* bag;  // το bag του ήρωα.εδώ μπαίνουν τα items και spells που αγοράζει από το market
    int magic_power;    
    int strength;   
    int dexterity;  
    int agility;    
    int money;
    int experience;

public:
    // constructor
    hero(const char *nam, int mp, int s, int d, int a) : living(nam), magic_power(mp), strength(s), dexterity(d), agility(a), money(200), experience(0)
    {

        // δέσμευση χώρου για το bag του ήρωα
        bag = new Backpack;

        // δέσμευση χώρου για τα equipped_items_of_hero
        // και αρχικοποιηση των αντικειμένων του με NULL
        equipped_items_of_hero = new EquippedItems;
        equipped_items_of_hero->hero_armor = NULL;
        equipped_items_of_hero->hero_weapon1 = NULL;
        equipped_items_of_hero->hero_weapon2 = NULL;
        // αρχικοποιείται με 2 ελεύθερα χέρια
        equipped_items_of_hero->free_hands = 2;
        
        // εκτύπωση σχετικού μηνύματος
        cout << " A new hero created " << endl;
        cout << " with name " << get_name() << endl;
    }

    // επιστρέφει την ποσότητα μαγικής ενέργειας του ήρωα
    int get_magic_power(){

        return magic_power;
    }

    // επιστρέφει τη δύναμη του ήρωα
    int get_strength(){

        return strength;
    }

    // επιστρέφει την επιδεξιότητα του ήρωα
    int get_dexterity(){

        return dexterity;
    }

    // επιστρέφει την ευκινησία του ήρωα
    int get_agility(){

        return agility;
    }

    // επιστρέφει τα λεφτά του ήρωα
    int get_money(){

        return money;
    }

    // επιστρέφει την εμπειρία ενός ήρωα
    int get_experience(){

        return experience;
    }

    // επιστρέφει τα equipped_items_of_hero
    EquippedItems* get_equipped_items(){

        return equipped_items_of_hero;
    }

    // αυξάνει το strength κατά no
    void increase_strength(int no){

        strength = strength + no;
    }

    // αυξάνει το agility κατά no
    void increase_agility(int no){

        agility = agility + no;
    }

    // αυξάνει το dexterity κατά no
    void increase_dexterity(int no){

        dexterity = dexterity + no;
    }

    // αυξάνει το health κατά no
    void increase_health(int no){

        living :: increase_health(no);
    }

    // αυξάνει το magic_power κατά no
    void increase_magic_power(int no){

        magic_power = magic_power + no;
    }


    virtual void level_up(const int c){

        set_level(c);
    }

    // δέχεται σαν όριμα ένα δείκτη σε item
    // βάζει αυτό το item στο bag και ενημερώνει τα λεφτά του ήρωα
    void buy_item(item* i){

        bag->items.push_back(i);
        money = money - i->get_price();

        // εκτύπωση σχετικού μηνύματος
        cout << " Hero with name " << get_name() << " just bought the item with name " << i->get_name() << endl;
    }

    // δέχεται σαν όριμα ένα δείκτη σε spell
    // βάζει αυτό το spell στο bag και ενημερώνει τα λεφτά του ήρωα
    void buy_spell(spell* s){

        bag->spells.push_back(s);
        money = money - s->getcost();

        // εκτύπωση σχετικού μηνύματος
        cout << " Hero with name " << get_name() << " just bought the spell with name " << s->getname() << endl;
    }

    // εκτυπώνει τα item του bag και επιστρέφει
    // των αριθμό των item που έχει στο bag
    int print_items(){

        cout << "           ITEMS" << endl;
        int y = 1;
        for (vector<item *>::iterator z = bag->items.begin(); z != bag->items.end(); ++z)
        {

            cout << y << " ";
            y++;
            (*z)->print();
        }

        return bag->items.size();
    }

    // εκτυπώνει τα spell του bag και επιστρέφει
    // των αριθμό των spell που έχει στο bag
    int print_spells(){

        cout << "           SPELLS" << endl;
        int y = 1;
        for (vector<spell *>::iterator z = bag->spells.begin(); z != bag->spells.end(); ++z)
        {

            cout << y << " ";
            y++;
            (*z)->print();
        }

        return bag->spells.size();
    }

    void sell_items(){

        cout << " Select the item that you want to sell " << endl;
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

            no = no - 1;

            // εκτύπωση σχετικού μηνύματος
            cout << " Hero with name " << get_name() << " just sell the item with name " << bag->items.at(no)->get_name() << endl;

            // ενημέρωση των χρημάτων
            money = money + (bag->items.at(no)->get_price())/2;

            // αφαίρεση του item
            bag->items.erase(bag->items.begin() + no);
        }
    }

    void sell_spells(){

        cout << " Select the spell that you want to sell " << endl;
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
            
            no = no - 1;
            cout << " Hero with name " << get_name() << " just sell the spell with name " << bag->spells.at(no)->getname() << endl;

            // ενημέρωση των χρημάτων
            money = money + (bag->spells.at(no)->getcost())/2;

            // αφαίρεση του spell
            bag->spells.erase(bag->spells.begin() + no);
        }
    }

    // εκτυπώνει τα item και spell που έχει στο bag του ο ήρωας
    void check_inventory(){

        cout << get_name() << "'s bag contains " << endl;

        print_items();

        print_spells();
    }


    void equip(){

        cout << " Select the item that you want to equip " << endl;
        cout << "To select press the right number or press 0 if you dont want to equip " << endl;

        int number_of_products;

        // εκτύπωση των items
        number_of_products = print_items();

        cout << "items size = " << number_of_products << endl;

        string select2;
        int no = 0;

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

            no = no - 1;

            // κλήση της equip του αντικειμένου που διάλεξε να κάνει
            // equip
            bag->items.at(no)->equip(this, no);
        } 
    }


    void use(){

        cout << " Select the item that you want to equip " << endl;
        cout << "To select press the right number or press 0 if you dont want to equip " << endl;

        int number_of_products;

        // εκτύπωση των items
        number_of_products = print_items();

        cout << "items size = " << number_of_products << endl;

        string select2;
        int no = 0;

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

            no = no - 1;

            // κλήση της use του αντικειμένου που διάλεξε να
            // κάνει use
            bag->items.at(no)->use(this, no);
        } 
    }

    // βάζει ένα item στο bag του ήρωα
    void put_in_backpack(item* i){

        bag->items.push_back(i);
    }

    // αφαιρεί ένα item που βρίσκεται στη θέση pos
    // από το bag
    void remove_from_backpack(int pos){

        bag->items.erase(bag->items.begin() + pos);
    }

    // εκτύπωση πληροφοριών του ήρωα
    void display_stats(){

        cout << " Hero with name " << get_name() << " health " << get_health() << " level " << get_level() << " strength " << strength << " agility " << agility << " dexterity " << dexterity << " magic power " << magic_power << " experience " << experience << " money " << money << endl;
    }

    void print_name(){

        cout << get_name() << endl;
    }


    // εκτυπώνει τα αντικείμενα που 
    // έχει κάνει equip
    void print_equipment(){

        int flag = 0;
        if(equipped_items_of_hero->hero_weapon1 != NULL){

            equipped_items_of_hero->hero_weapon1->print();
            flag = 1;
        }

        if(equipped_items_of_hero->hero_weapon2 != NULL){

            equipped_items_of_hero->hero_weapon2->print();
            flag = 1;
        }

        if(equipped_items_of_hero->hero_armor != NULL){

            equipped_items_of_hero->hero_armor->print();
            flag = 1;
        }

        if(flag = 0){

            cout << " Hero have not equipped items " << endl;
        }
    }

    // επιστρέφει τη δύναμη του ήρωα συν
    // το damage του/των weapon που έχει κάνει equip
    // (αν έχει κάνει κάτι equip)
    int attack (){

        if(equipped_items_of_hero->hero_weapon1 != NULL && equipped_items_of_hero->hero_weapon2 != NULL){

            return (equipped_items_of_hero->hero_weapon1->get() + equipped_items_of_hero->hero_weapon2->get() + strength);
        }
        else if(equipped_items_of_hero->hero_weapon1 != NULL){

            return (equipped_items_of_hero->hero_weapon1->get() + strength);
        }
        else if(equipped_items_of_hero->hero_weapon2 != NULL){

            return (equipped_items_of_hero->hero_weapon2->get() + strength);
        }
        else{

            return strength;
        }
    }


    int cast(spell* s){

        // έλεγχος για το αν έχει την απαραίτητη
        // μαγική ενέργεια για να εκτελέσει το spell
    	if (magic_power >= s->getmagic()){

            int r = dexterity / 7; 

            srand(time(0));
            int t = rand();

            t =(t %(s->getmaxdam() - s->getmindam())) + r;

            if (t > s->getmaxdam())
            {

                t = s->getmaxdam();
            }

            // επιστροφή του damage
            return t;
	    }
    	else {

            print_name();
            cout <<" has not enough magic power to cast " << s->getname() << "try using some potion(s) first"<<endl; 
            return 0;
        }
    }

    int castspell(){

        if(bag->spells.size()!=0){

            cout<<"Choose one from these spells to attack"<<endl;

            // εκτύπωση των spells που έχει στο bag
            print_spells();

            cout << "Press the number of the spell you would like to call!" << endl;

            int y = 0;
            while (1)
            {

                string input;

                // διάβασμα εισόδου              
                cin >> input;

                // μετατροπή της εισόδου σε int
                stringstream convert_input(input);
                convert_input >> y;

                // έλεγχος εισόδου
                if(y < 1 || y > bag->spells.size()){

                    cout << "There is no such an option , please try again " << endl;
                }
                else{

                    break;
                }
            }

            // κλήση της cast του spell που διάλεξε
            return cast(bag->spells.at(y - 1));
        }
        else{

            cout << "this hero has no available spells to attack with" << endl;
            return 0;
        }
    }

    int defend(){

        // έλεγχος για το αν φοράει κάποια armor
        if(equipped_items_of_hero->hero_armor != NULL){

            int t = equipped_items_of_hero->hero_armor->get();

            // επιστροφή του ποσού που μειώνεται
            // η ζημιά που δέχεται ο ήρωας
            // λόγο της armor
            return t;
        }

        return 0;
    }

    // μειώνει τα λεφτά του ήρωα
    // στο μισό
    void lose(){

        money = money / 2;
    }


    void exp(const int c)
    { 
        if(c>=0) {

            experience+=c;
            int t = experience / 100;
            cout << get_name() <<"    received "<< c <<"  experience" << endl;
            if (t>0){
                
                this->level_up(t - get_level());
            }    
        }
    }
    

    // destructor
    ~hero(){

        bag->items.clear();
        bag->spells.clear();

        // αποδέσμευση χώρου για το backpack
        delete bag;

        // αποδέσμευση χώρου για τα equipped items του hero
        delete equipped_items_of_hero;

        cout << " A hero with name " << get_name() << " to be destroyed " << endl;
    }
};
#endif