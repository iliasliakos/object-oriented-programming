#include <iostream>
#include <cstring>

#include "area.h"
#include "floor.h"
#include "stair.h"
#include "yard.h"
#include "student.h"
#include "teacher.h"

using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
//               ΣΧΟΛΕΙΟ
//
///////////////////////////////////////////////////////////////////////////////////////////
class school : public area
{
private:
    floor *school_array_of_floors[3]; // πίνακας με δείκτες στα 3 floor

    stair school_stair; // το κλιματοστάσιο

    yard school_yard; // το προάυλιο

public:

    // constructor
    school(int Cclass) : area(), school_yard(), school_stair()
    {

        // δέσμευση χώρου και δημιουργία τριών floor
        for (int i = 0; i < 3; i++)
        {

            school_array_of_floors[i] = new floor(Cclass);
        }

        // εκτύπωση σχετικού μηνύματος
        cout << "A New School has been created! " << endl;
    }

    // δέχεται έναν δείκτη σε student και προωθεί τον μαθητή στο yard
    void enter(student *s)
    {

        cout << s->get_name() << " enters school" << endl;

        // κλήση της enter του yard
        school_yard.enter(s);

        // κλήση της exit του yard
        student* ss = school_yard.exit();

        // κλήση της enter του stair
        school_stair.enter(ss);

        // κλήση της exit του stair
        student* sss = school_stair.exit();

        // κλήση της enter του αντίστοιχου floor
        school_array_of_floors[sss->get_floor_no() - 1]->enter(sss);
    }

    void print(){

        // εκτύπωση σχετικού μηνύματος
        cout << "School life consists of:  " << endl;

        // κλήση των print κάθε floor
        school_array_of_floors[0]->print(1);
        school_array_of_floors[1]->print(2);
        school_array_of_floors[2]->print(3);
    }

    // δέχεται σαν όρισμα τις ώρες που λειτουργεί ένα σχολείο
    void operate(int hours){

        // κλήση των συναρτήσεων operate για κάθε όροφο
        school_array_of_floors[0]->operate(hours);
        school_array_of_floors[1]->operate(hours);
        school_array_of_floors[2]->operate(hours);
    }

    // δέχεται έναν δείκτη σε teacher
    void place(teacher* t){

        // καλεί την place του ορόφου για αυτόν τον teacher
        school_array_of_floors[t->get_floor_no() - 1]->place(t);
    }

    // destructor
    ~school()
    {

        // εκτύπωση σχετικού μηνύματος
        cout << "A School to be destroyed! " << endl;

        // αποδέσμευση χώρου για τα 3 floor
        for (int i = 0; i < 3; i++)
        {

            delete school_array_of_floors[i];
        }
    }
};
