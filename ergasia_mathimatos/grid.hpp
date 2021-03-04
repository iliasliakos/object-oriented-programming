#ifndef GRID_H
#define GRID_H


#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>



#include "hero.hpp"
#include "warrior.hpp"
#include "paladin.hpp"
#include "sorcerer.hpp"

using namespace std;

struct coordinates
{
    int x;
    int y;
};

typedef struct coordinates *Coordinates;



// ορισμός ενός struct το οποίο αναπαριστά το party με τις συντεταγμένες
// του στο χάρτι και με ένα vector από hero
struct party
{

    Coordinates coordinates_of_party; // οι συντεταγμένες του party
    vector<hero*> heroes;            // vector με του ήρωες
};

typedef struct party *Party;

struct hero_info
{

    string type;
    string name;
    int magic_power;
    int strength;
    int dexterity;
    int agility;
};

typedef struct hero_info *HeroInfo;



struct compare_coordinates
{
    bool operator()(Coordinates a, Coordinates b) const
    {

        if (a->x == b->x)
        {

            return a->y < b->y;
        }

        return a->x < b->x;
    }
};

#include "block.hpp"
#include "market.hpp"
#include "nonAccessible.hpp"
#include "common.hpp"

///////////////////////////////////////////////////////////////////////////////////////
//                ΚΛΑΣΗ GRID
//
///////////////////////////////////////////////////////////////////////////////////////
class grid
{
private:
    // το party
    Party party_of_heroes;

    //  ο χάρτης, ο οποίος περιγράφεται από ένα map
    // το οποίο αντιστοιχίζει τις συντεταγμένες ενός block
    // με το αντίστοιχο block
    map<Coordinates, block *, compare_coordinates> game_map;

public:
    // constructor
    grid()
    {

        // βάζει στο map 5 markets
        while (game_map.size() < 5)
        {

            // βρίσκει 2 τυχαίους αριθμούς από το 0 έως το 9
            int x = rand() % 10;
            int y = rand() % 10;

            struct coordinates search_node = {.x = x, .y = y};

            // αν υπάρχει ήδη στο map block με αυτές τις συντεταγμένες
            // ξανά βρίσκει τυχαίες συντεταγμένες
            // μέχρι να βρεί κάποιες που να μην υπάρχουν στο map ακομά
            while (game_map.find(&search_node) != game_map.end())
            {

                x = rand() % 10;
                y = rand() % 10;

                search_node.x = x;
                search_node.y = y;
            }

            // δέσμευση χώρου για τις συντεταγμένες
            Coordinates c = new struct coordinates;
            // ενημέρωση των συντεταγμένων
            c->x = x;
            c->y = y;

            // είσοδος ενός market με αυτές τις συντεταγμένες στο map
            game_map.insert(pair<Coordinates, block *>(c, new market(c->x, c->y)));
        }

        // βάζει στο map 30 nonAccessibles
        while (game_map.size() < 35)
        {

            // βρίσκει 2 τυχαίους αριθμούς από το 0 έως το 9
            int x = rand() % 10;
            int y = rand() % 10;

            struct coordinates search_node = {.x = x, .y = y};

            // αν υπάρχει ήδη στο map block με αυτές τις συντεταγμένες
            // ξανά βρίσκει τυχαίες συντεταγμένες
            // μέχρι να βρεί κάποιες που να μην υπάρχουν στο map ακομά
            while (game_map.find(&search_node) != game_map.end())
            {

                x = rand() % 10;
                y = rand() % 10;

                search_node.x = x;
                search_node.y = y;
            }

            // δέσμευση χώρου για τις συντεταγμένες
            Coordinates c = new struct coordinates;
            // ενημέρωση των συντεταγμένων
            c->x = x;
            c->y = y;

            // είσοδος ενός nonAccessible με αυτές τις συντεταγμένες στο map
            game_map.insert(pair<Coordinates, block *>(c, new nonAccessible(c->x, c->y)));
        }

        // βάζει στο map 65 common
        while (game_map.size() < 100)
        {

            int x = rand() % 10;
            int y = rand() % 10;

            struct coordinates search_node = {.x = x, .y = y};

            while (game_map.find(&search_node) != game_map.end())
            {

                x = rand() % 10;
                y = rand() % 10;

                search_node.x = x;
                search_node.y = y;
            }

            Coordinates c = new struct coordinates;
            c->x = x;
            c->y = y;
            game_map.insert(pair<Coordinates, block *>(c, new common(c->x, c->y)));
        }

        cout << game_map.size() << endl;

        // δημιουργία του party
        // όταν αρχίζει το παιχνίδι το party
        // βρίσκεται στη θέση (6, 7)
        party_of_heroes = new struct party;
        party_of_heroes->coordinates_of_party = new struct coordinates;
        party_of_heroes->coordinates_of_party->x = 6;
        party_of_heroes->coordinates_of_party->y = 7;

        // εκτύπωση σχετικού μηνύματος
        cout << " a grid just created " << endl;
    }

    void see_map()
    {

        for (map<Coordinates, block *>::iterator it = game_map.begin();
             it != game_map.end();
             ++it)
        {

            if (it->first->x == party_of_heroes->coordinates_of_party->x && it->first->y == party_of_heroes->coordinates_of_party->y)
            {

                cout << "[P] ";
            }
            else
            {

                it->second->display_map();
            }

            if (it->first->y == 9)
            {

                cout << endl;
            }
        }
    }

    void start_game()
    {
        // vector που θα περιέχει τις πληροφορίες για τους ήρωες
        // (τις οποίες παίρνουμε από το αρχείο)
        vector<HeroInfo> info;

        // εκτύπωση σχετικών μηνυμάτων
        cout << " Lets start the game !!!! " << endl;
        cout << " first pick up your heroes " << endl;

        // το αρχείο με τις πληροφορίες των ηρώων
        ifstream file("file.txt");
        string line;

        int i = 1;

        // Διαβάζει όλες τις γραμμές του αρχείου μία μία
        while (getline(file, line))
        {

            stringstream linestream(line);

            string string1;  // Αν είναι "w" είναι warrior, αν είναι "s" είναι sorcerer αλλίως είναι paladin
            string name;     // το όνομα του hero
            int magic_power; //  η μαγική ενέργεία του ήρωα
            int strength;    // η δύναμη του ήρωα
            int dexterity;  // η επιδεξιότητα του ήρωα
            int agility;    // η ευκινησία του ήρωα

            linestream >> string1 >> name >> magic_power >> strength >> dexterity >> agility;

            if (i == 1)
            {

                cout << "       WARRIORS  " << endl;
            }
            else if (i == 6)
            {

                cout << endl;
                cout << "       PALADINS  " << endl;
            }
            else if (i == 11)
            {

                cout << endl;
                cout << "       SORCERERS  " << endl;
            }

            // δέσμευση χώρου και ενημέρωση των πληροφοριών
            // του τρέχων ήρωα
            HeroInfo heroinfo = new struct hero_info;
            heroinfo->type.assign(string1);
            heroinfo->name.assign(name);
            heroinfo->magic_power = magic_power;
            heroinfo->strength = strength;
            heroinfo->dexterity = dexterity;
            heroinfo->agility = agility;

            // είσοδος των πληροφοριών στο vector
            info.push_back(heroinfo);

            // εκτύπωση των πληροφοριών του ήρωα
            cout << i << " name " << name << " magic power " << magic_power << " strength " << strength << " dexterity " << dexterity << " agility " << agility << endl;
            i++;
        }

        // εκτύπωση σχετικών μηνυμάτων
        cout << endl;
        cout << " All heroes are 1 level and have 100 coins " << endl;
        cout << " You can select at most 3 heroes " << endl;
        cout << " To pick up a hero press the the number correspond to the hero.If you dont want to select a hero press 0 " << endl;

        string input;
        int y = 0;
        for (int z = 0; z < 3; z++)
        {

            // εκύπωση σχετικού μηνύματοσ
            cout << " Please select a hero " << endl;

            while (1)
            {

                // διάβασμα της επιλογής του παίχτη
                cin >> input;

                // μετατροπή της εισόδου σε int
                stringstream convert_input(input);
                convert_input >> y;

                // έλεγχος εισόδου
                if (y < 0 || y > i - 1)
                {

                    cout << "There is no such an option , please try again " << endl;
                }
                else
                {

                    break;
                }
            }

            cout << input << endl;

            // αν επέλεξε κάποιο ήρωα
            if (y != 0)
            {
                // είσοδος του ήρωα στο vector του party
                if (info.at(y - 1)->type.compare("w") == 0)
                {

                    char *hero_name = &info.at(y - 1)->name[0];
                    party_of_heroes->heroes.push_back(new warrior(hero_name, info.at(y - 1)->magic_power, info.at(y - 1)->strength, info.at(y - 1)->dexterity, info.at(y - 1)->agility));
                }
                else if (info.at(y - 1)->type.compare("p") == 0)
                {

                    char *hero_name = &info.at(y - 1)->name[0];
                    party_of_heroes->heroes.push_back(new paladin(hero_name, info.at(y - 1)->magic_power, info.at(y - 1)->strength, info.at(y - 1)->dexterity, info.at(y - 1)->agility));
                }
                else
                {
                    char *hero_name = &info.at(y - 1)->name[0];
                    party_of_heroes->heroes.push_back(new sorcerer(hero_name, info.at(y - 1)->magic_power, info.at(y - 1)->strength, info.at(y - 1)->dexterity, info.at(y - 1)->agility));
                }
                cout << info.at(y - 1)->type << info.at(y - 1)->name << endl;
            }
        }

        // διαγραφή της μνήμης που δεσμέυτηκε για κάθε Heroinfo
        for (vector<HeroInfo>::iterator r = info.begin(); r != info.end(); ++r)
        {

            delete *r;
        }

        // clear το vector
        info.clear();


        char ch;
        while (1)
        {

            while (1)
            {

                // εκτύπωση σχετικών μηνυμάτων
                cout << "Press m if you want to see the map " << endl;
                cout << "Press w if you want to go up " << endl;
                cout << "Press s if you want to go down " << endl;
                cout << "Press d if you want to go right " << endl;
                cout << "Press a if you want to go left " << endl;
                cout << "Press c if you want to check your inventory " << endl;
                cout << "Press e if you want to equip an armor or a weapon " << endl;
                cout << "Press u if you want to use a potion " << endl;
                cout << "Press i if you want to see info for a hero " << endl;
                cout << "Press q if you want to quit the game " << endl;

                // διάβασμα της επιλογής του χρήστη
                cin >> ch;

                // έλεγχος εισόδου
                if (ch != 'w' && ch != 's' && ch != 'd' && ch != 'a' && ch != 'm' && ch != 'q' && ch != 'c' && ch != 'e' && ch != 'u' && ch != 'i')
                {

                    cout << "There is no such an option , please try again " << endl;
                }
                else
                {

                    break;
                }
            }

            // αν επέλεξε να κάνει quit
            if (ch == 'q')
            {

                break;
            }
            // αν επέλεξε να δει το χάρτι
            else if (ch == 'm')
            {

               see_map();
            }
            else if(ch == 'i'){

                while(1){

                    cout << " Choose the hero that you want to see his info " << endl;
                    cout << " To choose the hero press his number or press 0 if you dont want to select a hero " << endl;

                    int i = 1;
                    for (vector<hero *>::iterator r = party_of_heroes->heroes.begin(); r != party_of_heroes->heroes.end(); ++r)
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
                        if (number < 0 || number > party_of_heroes->heroes.size())
                        {

                            cout << "There is no such an option , please try again " << endl;
                        }
                        else
                        {

                            break;
                        }
                    }
                    if(number != 0){

                        hero* h = party_of_heroes->heroes.at(number - 1);
                        h->display_stats();
                    }
                    else{

                        break;
                    }
                }
            }
            // αν επέλεξε να δει το inventory του
            else if(ch == 'c'){

                while(1){

                    cout << " Choose the hero that you want to check his inventory " << endl;
                    cout << " To choose the hero press his number or press 0 if you dont want to select a hero " << endl;

                    int i = 1;
                    for (vector<hero *>::iterator r = party_of_heroes->heroes.begin(); r != party_of_heroes->heroes.end(); ++r)
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
                        if (number < 0 || number > party_of_heroes->heroes.size())
                        {

                            cout << "There is no such an option , please try again " << endl;
                        }
                        else
                        {

                            break;
                        }
                    }
                    if(number != 0){

                        hero* h = party_of_heroes->heroes.at(number - 1);
                        h->check_inventory();
                    }
                    else{

                        break;
                    }
                }
            }
            // αν επέλεξε να κάνει use
            else if(ch == 'u'){

                cout << " Choose the hero that you want him to use a potion " << endl;
                cout << " To choose the hero press his number " << endl;

                int i = 1;
                for (vector<hero *>::iterator r = party_of_heroes->heroes.begin(); r != party_of_heroes->heroes.end(); ++r)
                {

                    cout << i << " " << (*r)->get_name() << endl;
                    i++;
                }

                string select;
                int number = 0;
                while (1)
                {

                    // διάβασμα της επιλογής του παίχτη
                    cin >> select;

                    // μετατροπή της εισόδου σε int
                    stringstream convert_select(select);
                    convert_select >> number;

                    // έλεγχος εισόδου
                    if (number < 1 || number > party_of_heroes->heroes.size())
                    {

                        cout << "There is no such an option , please try again " << endl;
                    }
                    else
                    {

                        break;
                    }
                }

                hero* h = party_of_heroes->heroes.at(number - 1);  
                h->use();   
            }
            // αν επέλεξε να κάνει equip
            else if(ch == 'e'){

                cout << " Choose the hero that you want him to equip an armor or a weapon " << endl;
                cout << " To choose the hero press his number " << endl;

                int i = 1;
                for (vector<hero *>::iterator r = party_of_heroes->heroes.begin(); r != party_of_heroes->heroes.end(); ++r)
                {

                    cout << i << " " << (*r)->get_name() << endl;
                    i++;
                }

                string select;
                int number = 0;
                while (1)
                {

                    // διάβασμα της επιλογής του παίχτη
                    cin >> select;

                    // μετατροπή της εισόδου σε int
                    stringstream convert_select(select);
                    convert_select >> number;

                    // έλεγχος εισόδου
                    if (number < 1 || number > party_of_heroes->heroes.size())
                    {

                        cout << "There is no such an option , please try again " << endl;
                    }
                    else
                    {

                        break;
                    }
                }

                hero* h = party_of_heroes->heroes.at(number - 1);  
                h->equip();   
            }
            // αν επέλεξε να μετακινηθεί
            else
            {

                // κλήση της move
                move(ch);
            }
        }
    }


    void move(char motion)
    {

        // προσωρινές συντεταγμένες
        int i;
        int y;

        struct coordinates search_node;

        map<Coordinates, block *>::iterator it;

        // αν επέλεξε να μετακινηθεί προς τα πάνω
        if (motion == 'w')
        {

            // ενημέρωση των προσωρινών συντεταγμένων
            i = party_of_heroes->coordinates_of_party->x - 1;
            y = party_of_heroes->coordinates_of_party->y;
        }
        // αν επέλεξε να μετακινηθεί προς τα κάτω
        else if (motion == 's')
        {

            // ενημέρωση των προσωρινών συντεταγμένων
            i = party_of_heroes->coordinates_of_party->x + 1;
            y = party_of_heroes->coordinates_of_party->y;
        }
        // αν επέλεξε να μετακινηθεί προς τα αριστερά
        else if (motion == 'a')
        {

            // ενημέρωση των προσωρινών συντεταγμένων
            i = party_of_heroes->coordinates_of_party->x;
            y = party_of_heroes->coordinates_of_party->y - 1;
        }
        // αν επέλεξε να μετακινηθεί προς τα δεξιά
        else
        {

            // ενημέρωση των προσωρινών συντεταγμένων
            i = party_of_heroes->coordinates_of_party->x;
            y = party_of_heroes->coordinates_of_party->y + 1;
        }

        search_node.x = i;
        search_node.y = y;

        it = game_map.find(&search_node);

        // έλεγχος αν οι συντεταγμένες στις οποίες θέλει να μετακινηθεί
        // είναι εντός του map
        //  αν είναι εντός
        if (it != game_map.end())
        {

            it->second->interact_with(party_of_heroes);
        }
        // αν οι συντεταγμένες που διάλεξε να μετακινηθεί έιναι εκτός του map
        else
        {

            // εκτύπωση σχετικού μηνύματος
            cout << " You cant move outside the map !!!! " << endl;
        }

        cout << endl;
    }

    // destructor
    ~grid()
    {

        // διαγραφή της μνήμης για κάθε Coordinates και block που δεσμεύτηκε
        for(map<Coordinates, block*>::iterator it = game_map.begin(); it != game_map.end(); ++it){

            delete it->first;
            delete it->second;
        }

        game_map.clear();

        // διαγραφή κάθε hero από το vector
        for (vector<hero *>::iterator r = party_of_heroes->heroes.begin(); r != party_of_heroes->heroes.end(); ++r)
        {

            delete *r;
        }

        party_of_heroes->heroes.clear();

        // αποδέσμευση μνήμης
        delete party_of_heroes->coordinates_of_party;

        // αποδέσμευση μνήμης
        delete party_of_heroes;

        // εκτύπωση σχετικού μηνύματος
        cout << " a grid to be destroyd " << endl;
    }
};

#endif