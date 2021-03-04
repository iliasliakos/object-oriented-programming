#include <cstring>
#include <iostream>

#include "area.h"
#include "classroom.h"
#include "corridor.h"
#include "student.h"
#include "teacher.h"


using namespace std;
/////////////////////////////////////////////////////////////////
//              ΟΡΟΦΟΣ
//
////////////////////////////////////////////////////////////////////////////////////
class floor : public area
{
private:
    classroom* floor_array_of_classrooms[6];        // πίνακας με δείκτες στις τάξεις του ορόφου
    corridor floor_corridor;                        // ο διάδρομος του ορόφου

public:

    // constructor
    floor(int Cclass) : area(), floor_corridor()
    {

        // δέσμευση χώρου και δημιουργία 6 classroom
        for (int i = 0; i < 6; i++)
        {

            floor_array_of_classrooms[i] = new classroom(Cclass);
        }

        // εκτύπωση σχετικού μηνύματος
        cout << "A New floor has been created! " << endl;
    }


    // δέχεται έναν δείκτη σε student και προωθεί τον μαθητή στο corridor
    void enter(student *s)
    {
    
        // εκτύπωση σχετικού μηνύματος
        cout << s->get_name() << " enters floor! " << s->get_floor_no() << endl;

        // κλήση της enter του διαδρόμου
        floor_corridor.enter(s);

        // κλήση της exit του διαδρόμου
        student* ss = floor_corridor.exit();

        //κλήση της enter της αντίστοιχης τάξης
        floor_array_of_classrooms[ss->get_class_no() - 1]->enter(ss);
    }

    void print(int no){

        // εκτύπωση σχετικού μηνύματος
        cout << "Floor number " << no << "contains " << endl;

        // κλήση των print για κάθε τάξη
        floor_array_of_classrooms[0]->print(1);
        floor_array_of_classrooms[1]->print(2);
        floor_array_of_classrooms[2]->print(3);
        floor_array_of_classrooms[3]->print(4);
        floor_array_of_classrooms[4]->print(5);
        floor_array_of_classrooms[5]->print(6);
    }

    // δέχεται σαν όρισμα τις ώρες που λειτουργεί ένας όροφος
    void operate(int hours){

        // κλήση των operate για κάθε τάξη
        floor_array_of_classrooms[0]->operate(hours);
        floor_array_of_classrooms[1]->operate(hours);
        floor_array_of_classrooms[2]->operate(hours);
        floor_array_of_classrooms[3]->operate(hours);
        floor_array_of_classrooms[4]->operate(hours);
        floor_array_of_classrooms[5]->operate(hours);
    }

    // δέχεται έναν δείκτη σε teacher
    void place(teacher* t){

        // καλεί την place της τάξης για αυτόν τον teacher
        floor_array_of_classrooms[t->get_class_no() - 1]->place(t);
    }

    // destructor
    ~floor()
    {

        // εκτύπωση σχετικού μηνύματος
        cout << "A floor to be destroyed! " << endl;

        // αποδέσμευση χώρου για τα 6 classroom
        for (int i = 0; i < 6; i++)
        {

            delete floor_array_of_classrooms[i];
        }
    }
};
