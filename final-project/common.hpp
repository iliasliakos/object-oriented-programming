#include <cstring>
#include <iostream>
#include <string>

#include "block.hpp"
#include "monster.hpp"
#include "dragon.hpp"
#include "exoskeleton.hpp"
#include "spirit.hpp"


using namespace std;

typedef struct monster_info
{

    string type;
    string name;
    int health;
    int mindam;
    int maxdam;
    int defence;
    int avoid;
} monsterinfo;

/////////////////////////////////////////////////////////////////////////////////////
//                ΚΛΑΣΣΗ COMMON
//      κληρονομεί την block
/////////////////////////////////////////////////////////////////////////////////////
class common : public block
{
public:
    // constructor
    common(int x, int y) : block(x, y)
    {

    }

    void display_map(){

        cout << "[ ] ";
    }


    void interact_with(Party p)
    {

        // ενημέρωση των συντεταγμένων
        p->coordinates_of_party->x = get_x();
        p->coordinates_of_party->y = get_y();

        // εκτύπωση σχετικού μηνύματος
        cout << " Your party moved to a common block " << endl;

        int possibility;
        srand(time(NULL));

        // βρίσκει έναν αριθμό από το 1 μέχρι το 5
        possibility = rand() % 5 + 1;

        // η πιθανότητα ο αριθμός που βρήκε να είναι 1
        // είναι 20%
        if (possibility == 1)
        {

            // κλήση της battle
            int y = battle(p) + 1;

            // κλήση της exp για κάθε ήρωα
            for(int i = 0; i < p->heroes.size(); i++){

                p->heroes.at(i)->exp(y);
            }
        }
    }

    // αυξάνει τη ζωή των ηρώων που μετά τη μάχη έμειναν
    // με λιγότερο από μισή ζωή
    void revive(Party p){
        
        for (int i=0;i <3;i++){

            if(p->heroes.at(i)->get_health()<=50)
            { 

                cout << "Somebody have fainted out" << p->heroes.at(i)->get_name() << "feels dizzy after geting up" << endl;

                int t = 50 - p->heroes.at(i)->get_health();

                p->heroes.at(i)->increase_health( t);
            }
        }
    } 

    // επιστρέφει το άθροισμα των levels όλων των ηρώων
    int max( Party p){

        int l=0;
        for (int i = 0; i < 3; i++){

            if(p->heroes.at(i)->get_level() > l)
            {
                
                l = l + p->heroes.at(i)->get_level();
            }
        }
        return l;
    }

    // η μάχη
    int battle(Party p)
    {

        int count = 1;

        // vector με τα monsters που θα πολεμήσουν 
        // οι ήρωες
        vector<monster *> monsters;

        // σε αυτό το vector θα αποθηκευτούν προσωρινά
        // πληροφορίες για τα monsters
        // που θα πάρουμε από το file2.txt
        vector<monsterinfo *> m_info;

        cout << endl;
        cout << "         Some creatures have entered the surroundings" << endl;
        cout << "         Weapons unsheathed in an instance towards bones and scales" << endl;
        cout << endl;
        cout << "     Its time to battle !!" << endl;
        cout << endl;

        ifstream file("file2.txt");
        string line;

        while (getline(file, line))
        {

            stringstream linestream(line);
            string str1;
            string nam;
            int h, mind, maxd, d, a;

            linestream >> str1 >> nam >> h >> mind >> maxd >> d >> a;

            monsterinfo *mi = new monsterinfo();
            mi->type.assign(str1);
            mi->name.assign(nam);
            mi->health = h;
            mi->mindam = mind;
            mi->maxdam = maxd;
            mi->defence = d;
            mi->avoid = a;

            m_info.push_back(mi);
        }

        cout << endl;
        cout << " All monsters' level are equal to heroe's level " << endl;

        // επιλογή 3 τυχέων τεράτων
        srand(time(NULL));

        int f = rand() % 15;    //
        int k = rand() % 15;    //  βρίσκει έναν τυχαίο αριθμό από το 0 μέχρι το 14
        int h = rand() % 15;    //  

        // δημιουργία των 3 τεράτων και εισαγωγή τους
        // στο vector monsters
        int y;
        for (int i = 0; i < 3; i++)
        {

            if (i == 0)
            {

                y = f;
            }
            else if (i == 1)
            {

                y = k;
            }
            else if (i == 2)
            {

                y = h;
            }

            // αν είναι dragon
            if (m_info.at(y)->type.compare("d") == 0)
            {

                char *mo_name = &m_info.at(y)->name[0];

                cout << " Dragon" << endl;

                monsters.push_back(new dragon(mo_name, m_info.at(y)->mindam, m_info.at(y)->maxdam, m_info.at(y)->defence, m_info.at(y)->avoid));
            }
            //αν είναι exoskeleton
            else if (m_info.at(y)->type.compare("e") == 0)
            {

                char *mo_name = &m_info.at(y)->name[0];

                cout << " Exoskeleton " << endl;

                monsters.push_back(new exoskeleton(mo_name, m_info.at(y)->mindam, m_info.at(y)->maxdam, m_info.at(y)->defence, m_info.at(y)->avoid));
            }
            // αν είναι spirit
            else if (m_info.at(y)->type.compare("g") == 0)
            {

                char *mo_name = &m_info.at(y)->name[0];

                cout << " Spirit " << endl;

                monsters.push_back(new spirit(mo_name, m_info.at(y)->mindam, m_info.at(y)->maxdam, m_info.at(y)->defence, m_info.at(y)->avoid));
            }
        }


        // αποδέσμευση μνήμης των στοιχείων του m_info
        for (vector<monsterinfo *>::iterator r = m_info.begin(); r != m_info.end(); ++r)
        {

            delete *r;
        }

        m_info.clear();

        // ενημέρωση των level των τεράτων
        for (vector<monster *>::iterator r = monsters.begin(); r != monsters.end(); ++r)
        {

            (*r)->level_up(p->heroes.at(0)->get_level());
        }


        int turn = 0;   // το round στο οποίο βρισκόμαστε
        while (1)
        {

            //////////////////////////////////////////////////////////////////////
            //  επίθεση των ηρώων
            //
            //////////////////////////////////////////////////////////////////////

            for (int l = 0; l < p->heroes.size(); l++)
            {

                while (1)
                {
                    cout << "Round   " << turn << endl;
                    cout << "Press 1 if you want to see the heroe's stats" << endl;
                    cout << "Press 2 if you want to see the heroe's equipped items" << endl;
                    cout << "Press 3 if you want to see monster's stats " << endl;
                    cout << "Press 4 if you want to continue " << endl;

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
                        if (no < 1 || no > 4)
                        {

                            cout << "There is no such an option , please try again " << endl;
                        }
                        else
                        {

                            break;
                        }
                    }

                    // αν διάλεξε να δει στατιστικά του ήρωα
                    if (no == 1)
                    {

                        p->heroes.at(l)->display_stats();
                    }
                    // αν διάλεξε να δει τα αντικείμενα που έχει κάνει
                    // equip ο ήρωας
                    else if (no == 2)
                    {

                        p->heroes.at(l)->print_equipment();
                    }
                    // αν διάλεξε να δει τα στατιστικά των τεράτων
                    else if (no == 3)
                    {

                        for (int w = 0; w < monsters.size(); w++)
                        {

                            monsters.at(w)->print_all();
                        }
                    }
                    // αν διάλεξε να κάνει continue
                    else
                    {

                        break;
                    }
                }

                cout << "Choose your action for hero    ";
                p->heroes.at(l)->print_name();

                cout << "Press 1 if you want to use a potion " << endl;
                cout << "Press 2 if you want to equip an armor or a weapon" << endl;
                cout << "Press 3 if you want a regular attack " << endl;
                cout << "Press 4 if you want an attack with spell " << endl;

                // έλεγχος αν ο ήρωας είναι ζωντανός
                if (p->heroes.at(l)->get_health() > 0)
                {

                    string input;
                    while (1)
                    {

                        // διάβασμα εισόδου
                        cin >> input;

                        // μετατροπή της εισόδου σε int
                        stringstream convert_input(input);
                        convert_input >> y;

                        // έλεγχος εισόδου
                        if (y < 1 || y > 4)
                        {

                            cout << "There is no such an option , please try again " << endl;
                        }
                        else
                        {

                            break;
                        }
                    }

                    switch (y){
                        // αν επέλεξε να κάνει use
                        case 1:{

                            p->heroes.at(l)->use();
                            break;
                        }
                        // αν επέλεξε να κάνει equip
                        case 2:{

                            p->heroes.at(l)->equip();
                            break;
                        }
                        // αν επέλεξε να κάνει regular attack
                        case 3:{

                            cout << "Which of the following monsters you would like to attack  " << endl;

                            for (int w = 0; w < monsters.size(); w++)
                            {
                                cout << w + 1 << "  ]" << endl;
                                monsters.at(w)->print_all();
                            }

                            cout << "Press the number of monster you would like to attack  " << endl;


                            int i = 0;
                            while (1)
                            {
                                string input1;

                                // διάβασμα εισόδου
                                cin >> input1;

                                // μετατροπή της εισόδου σε int
                                stringstream convert_input1(input1);
                                convert_input1 >> i;

                                // έλεγχος εισόδου
                                if (i < 1 || i > monsters.size())
                                {

                                    cout << "There is no such an option , please try again " << endl;
                                }
                                else
                                {

                                    break;
                                }
                            }

                            // αν το τέρας δεν απέφυγε το χτύπημα
                            if (rand() % 101 >= monsters.at(i - 1)->getavoid())
                            {

                                int dam;

                                // βρίσκουμε τη ζημιά που έκανε ο ήρωας
                                dam = p->heroes.at(l)->attack();

                                // μείωση της ζημιάς που δέχεται το τέρας
                                // ανάλογα με το defence του
                                dam = dam - monsters.at(i - 1)->getdefence();

                                // άπαξ και πετύχει , να σκάει τουλάχιστον
                                // 1 damage τιμής ένεκεν
                                if (dam < 0)
                                {
                                    dam = 1;
                                }

                                // μείωση της ζωής του τέρατος
                                monsters.at(i - 1)->decrease_health(dam);

                                // εκτύπωση σχετικού μηνύματος
                                p->heroes.at(l)->print_name();
                                cout << " attacked " << monsters.at(i - 1)->get_name() << "and inflicted " << dam << "  damage " << endl;
                            }
                            // αν το τέρας απέφυγε το χτύπημα
                            else
                            {

                                // εκτύπωση σχετικών μηνυμάτων
                                p->heroes.at(l)->print_name();
                                cout << " attacked " << monsters.at(i - 1)->get_name() << " but the monster dodged in a friction of the eye " << endl;
                            }

                            break;
                        }
                        // αν επέλεξε να κάνει επίθεση με spell
                        case 4:{

                            cout << "Which of the following monsters you would like to attack  " << endl;

                            for (int w = 0; w < monsters.size(); w++)
                            {
                                cout << w + 1 << "  ]" << endl;
                                monsters.at(w)->print_all();
                            }

                            cout << "Press the number of monster you would like to attack  " << endl;

                            int i = 0;
                            while (1)
                            {
                                string input1;

                                // διάβασμα εισόδου
                                cin >> input1;

                                // μετατροπή εισόδου σε int
                                stringstream convert_input1(input1);
                                convert_input1 >> i;

                                // έλεγχος εισόδου
                                if (i < 1 || i > monsters.size())
                                {

                                    cout << "There is no such an option , please try again " << endl;
                                }
                                else
                                {

                                    break;
                                }
                            }

                            // αν το τέρας δεν απέφυγε το χτύπημα
                            if (rand() % 101 > monsters.at(i - 1)->getavoid())
                            {

                                int dam;
                                // υπολογισμός του damage που σκάει ο ήρωας με το spell
                                dam = p->heroes.at(l)->castspell();

                                // μείωση της ζημιάς που δέχεται το τέρας
                                // ανάλογα με το defence του
                                dam = dam - monsters.at(i - 1)->getdefence();

                                // ο ήρωας σκάει τουλάχιστον 5 damage
                                if (dam < 0)
                                {
                                    dam = 5;
                                }

                                // μείωση της ζωής του τέρας
                                monsters.at(i - 1)->decrease_health(dam);

                                // εκύπωση σχετικών μηνυμάτων
                                p->heroes.at(l)->print_name();
                                cout << " spelled " << monsters.at(i - 1)->get_name() << "and inflicted " << dam << "  damage " << endl;
                            }
                            // αν απέφυγε το χτύπημα
                            else
                            {

                                // εκτύπωση σχετικών μηνυμάτων
                                p->heroes.at(l)->print_name();
                                cout << " spelled " << monsters.at(i - 1)->get_name() << " but the monster succed to avoid the attack" << endl;
                            }

                            break;
                        }
                    }
                }
            }

            // έλεγχος αν πέθαναν όλα τα τέρατα
            bool dead = true;
            for (int i = 0; i < monsters.size(); i++)
            {
                
                if (monsters.at(i)->get_health() > 0)
                {

                    cout << "at least a monster is alive" << endl;
                    dead = false;
                    break;
                }
            }

            // αν πέθαναν όλα
            if (dead == true)
            {

                // εκτύπωση σχετικών μηνυμάτων
                cout << "Congratulations !! Heroes have won the fight at turn " << turn << endl;

                // κλήση της revive
                revive(p);


                int number_of_monsters = monsters.size();

                // αποδέσμευση μνήμης των monsters
                for (vector<monster *>::iterator r = monsters.begin(); r != monsters.end(); ++r)
                {

                    delete *r;
                }

                monsters.clear();

                // επιστρέφει τα πόσα level τεράτψν νικήθηκαν συν 1
                return number_of_monsters * max(p) + 1; //epistrefei ta posa lvl teratwn nikithikan +4 epi tis ousias
            }

            //////////////////////////////////////////////////////////////////
            //  επίθεση των τεράτων
            //
            //////////////////////////////////////////////////////////////////


            for (int l = 0; l < monsters.size(); l++)
            { 

                // έλεγχος αν το τέρας είναι ζωντανό
                if (monsters.at(l)->get_health() > 0)
                {

                    // βρισκεί τυχαία ποιόν ήρωα θα χτυπήσει
                    int t = rand() % p->heroes.size();
                    cout << monsters.at(l)->get_name() << "      attacked  at  "
                         << p->heroes.at(t)->get_name() << endl;

                    // αν ο ήρωας δεν απέφυγε το χτύπημα
                    if ((rand() % 101) >= (p->heroes.at(t)->get_agility()))
                    {

                        // υπολογισμός του damage που έκανε το τέρας
                        int dam = monsters.at(l)->attack();

                        // μείωση του damage στην περίπτωση που ο ήρωας
                        // φοράει κάποιο armor
                        dam = dam - p->heroes.at(t)->defend();

                        if (dam < 0)
                        {
                            dam = 0;
                        }

                        // μείωση της ζωής του ήρωα
                        p->heroes.at(t)->decrease_health(dam);

                        // εκτύπωση σχετικού μηνύματος
                        cout << " and inflicted  " << dam << "  damage" << endl;
                    }
                    // αν ο ήρωας απέφυγε το χτύπημα
                    else
                    {

                        // εκτύπωση σχετικών μηνυμάτων
                        cout << " moving a bit slower than the speed of shadow ";

                        p->heroes.at(t)->print_name();

                        cout << " made the monster lose the chance to bruise" << endl;
                    }
                }
                // αν το monster έχει πεθάνει
                else
                {

                    // εκτύπωση σχετικού μηνύματος
                    monsters.at(l)->print_name();
                    cout << "is a lying mass of pain ,can't attack" << endl;
                }
            }

            // έλεγχος αν πέθαναν όλοι οι ήρωες
            dead = true;
            for (int i = 0; i < p->heroes.size(); i++)
            {
                
                if (p->heroes.at(i)->get_health() > 0)
                {

                    cout << "at least a hero is alive" << endl;

                    dead = false;

                    break;
                }
            }
            // αν πέθαναν όλοι
            if (dead)
            {

                // εκτύπωση σχετικού μηνύματος
                cout << "unfortunately this battle had a negative outcome for the heroes.Keep trying u will made it" << endl;

                // κλήση της lose για κάθε ήρωα
                for (int i = 0; i < p->heroes.size(); i++)
                {
                    p->heroes.at(i)->lose();
                }

                int number_of_monsters = monsters.size();

                // αποδέσμευση μνήμης των monsters
                for (vector<monster *>::iterator r = monsters.begin(); r != monsters.end(); ++r)
                {

                    delete *r;
                }

                monsters.clear();

                return number_of_monsters * 2 + 1;
            }

            cout << "Every alive monster gets 2 life points" << endl;
            for (int j = 0; j < monsters.size(); j++)
            {

                if (monsters.at(j)->get_health() <= 0)
                {

                    monsters.at(j)->set_health(0);
                }
                else
                {

                    if (monsters.at(j)->get_health() >= 98)
                    {

                        monsters.at(j)->set_health(100);
                    }
                    else
                    {

                        monsters.at(j)->increase_health(2);
                    }
                }
            }

            turnhealth(p);
            turnmagic(p);

            // ενημέρωση του turn
            turn++;
        }
    }

    void turnhealth(Party p)
    {   

        cout<<"Every alive hero gets 7 health points "<<endl;
        for (int i = 0; i < p->heroes.size(); i++)
        {

            if (p->heroes.at(i)->get_health() <= 0)
            {

                p->heroes.at(i)->set_health(0);
            }
            else 
            {

                if (p->heroes.at(i)->get_health() >= 93)
                {

                    p->heroes.at(i)->set_health(100);
                }
                else{

                    p->heroes.at(i)->increase_health(7);
                }
            }

        }
    }


    void turnmagic(Party p)
    {   
        
        cout<<"Every alive hero gets 20 magic"<<endl;

        for (int i = 0; i < p->heroes.size(); i++)
        {

            if(p->heroes.at(i)->get_health() > 0){

                p->heroes.at(i)->increase_magic_power(20);
            }
        }
    }

    // destructor
    ~common()
    {

    }
};