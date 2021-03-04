#include <cstring>
#include <iostream>

#include "classroom.h"
#include "corridor.h"
#include "student.h"
#include "teacher.h"


using namespace std;
/////////////////////////////////////////////////////////////////
//              ΟΡΟΦΟΣ
//
////////////////////////////////////////////////////////////////////////////////////
class floor
{
private:
    classroom *floor_array_of_classrooms[6];        // πίνακας με δείκτες στις τάξεις του ορόφου
    corridor floor_corridor;                        // ο διάδρομος του ορόφου
    int capacity_corridor;                          // το μέγεθος του ορόφου
    int capacity_class;                             // το μέγεθος της τάξης

public:

    // constructor
    floor(int Cclass, int Ccorr) : floor_corridor(Ccorr), capacity_corridor(Ccorr), capacity_class(Cclass)
    {

        // δέσμευση χώρου και δημιουργία 6 classroom
        for (int i = 0; i < 6; i++)
        {

            floor_array_of_classrooms[i] = new classroom(Cclass);
        }

        // εκτύπωση σχετικού μηνύματος
        cout << "A New floor has been created! " << endl;
    }


    // επιστρέφει τον αριθμό των μαθητών που βρίσκονται στο διάδρομο
    int get_current_students_in_corridor()
    {

        return floor_corridor.get_current_students_in_corridor();
    }


    // κάνει τον αριθμό των μαθητών που βρίσκονται στο διάδρομο ίσο με current
    void set_current_students_in_corridor(int current)
    {

        floor_corridor.set_current_students_in_corridor(current);
    }


    // επιστρέφει τον πίνακα με τους μαθητές του διαδρόμου
    student **get_corridor_array()
    {

        return floor_corridor.get_corridor_array();
    }


    // δέχεται έναν δείκτη σε student
    // και τον αριθμό των μαθητών που θέλου να μπουν σε αυτόν το διάδρομο
    void enter(student *s, int size)
    {
    
        // εκτύπωση σχετικού μηνύματος
        cout << s->get_name() << " enters floor! " << s->get_floor_no() << endl;

        // κλήση της enter του διαδρόμου
        floor_corridor.enter(s);

        // έλεγχος ο διάδρομος έχει γεμίσει ή 
        // αν δεν υπάρχει άλλος μαθητής που να θέλει να μπει στο διάδρομο
        int count = floor_corridor.get_current_students_in_corridor();
        if (count == capacity_corridor || count == size)
        {

            // ο πίνακας με τους μαθητές του διαδρόμου
            student **corridor_students = floor_corridor.get_corridor_array();

            // προσπέλαση του πίνακα
            for (int i = count - 1; i >= 0; i--)
            {

                // ο αριμθός των μαθητών που βρίσκονται στην τάξη που θέλει να πάει ο μαθητής
                int current_class = floor_array_of_classrooms[corridor_students[i]->get_class_no() - 1]->get_current_students_in_classroom();

                // ο δάσκαλος που βρίσκεται στη τάξη
                teacher* t = floor_array_of_classrooms[corridor_students[i]->get_class_no() - 1]->get_class_teacher();

                // αν χωράει μαθητής στη τάξη και αν δεν έχει μπει δάσκαλος
                // σε αυτήν
                if (current_class != capacity_class && t == NULL)
                {

                    // κλήση της exit του διαδρόμου
                    student *s1 = floor_corridor.exit();

                    // μείωση του αριθμού των μαθητών του διαδρόμου κατα 1
                    floor_corridor.set_current_students_in_corridor(floor_corridor.get_current_students_in_corridor() - 1);

                    // αύξηση του αριθμού των μαθήτων της τάξης του μαθητή
                    // που βγήκε από το διάδρομο κατα 1
                    floor_array_of_classrooms[s1->get_class_no() - 1]->set_current_students_in_classroom(current_class + 1);

                    // κλήση της enter της τάξης
                    floor_array_of_classrooms[s1->get_class_no() - 1]->enter(s1);
                }
            }
            
        }
    }


    // δέχεται έναν δείκτη σε teacher
    void place(teacher* t){

        // καλεί την place της τάξης για αυτόν τον teacher
        floor_array_of_classrooms[t->get_class_no() - 1]->place(t);
    }


    void print(int number)
    {

        // εκτύπωση σχετικού μηνύματος
        cout << "Floor number " << number << "contains " << endl;

        // κλήση των print όλων των τάξεων
        floor_corridor.print();
        floor_array_of_classrooms[0]->print(1);
        floor_array_of_classrooms[1]->print(2);
        floor_array_of_classrooms[2]->print(3);
        floor_array_of_classrooms[3]->print(4);
        floor_array_of_classrooms[4]->print(5);
        floor_array_of_classrooms[5]->print(6);
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
