#include <cstring>
#include <iostream>

#include "student.h"


using namespace std;
/////////////////////////////////////////////////////////
//          ΔΙΑΔΡΟΜΟΣ
//
//////////////////////////////////////////////////////////////////////////
class corridor
{
private:
    student **corridor_array;                   // πίνακας με δείκτες στου μαθητές του διαδρόμου
    int capacity_corridor;                      // το μέγεθος του διαδρόμου
    int current_students_in_corridor;           // ο αριθμός των μαθητών που βρίσκονται στο διάδρομο

public:

    // constructor
    corridor(int Ccorr) : capacity_corridor(Ccorr), current_students_in_corridor(0)
    {

        // δέσμευση χώρου για τον πίνακα
        corridor_array = new student *[Ccorr];

        for(int i = 0; i < Ccorr; i++){

            corridor_array[i] = NULL;
        }

        // εκτύπωση σχετικού μηνύματος
        cout << "A New Corridor has been created! " << endl;
    }


    // επιστρέφει τον πίνακα με του μαθητές του διαδρόμου
    student **get_corridor_array()
    {

        return corridor_array;
    }


    // επιστρέφει των αριθμό των μαθητών που βρίσκονται στο διάδρομο
    int get_current_students_in_corridor()
    {

        return current_students_in_corridor;
    }


    // κάνει τον αριθμό των μαθητών του διαδρόμου ίσο με current
    void set_current_students_in_corridor(int current)
    {

        current_students_in_corridor = current;
    }


    // βάζει έναν μαθητή στο διάδρομο
    void enter(student *s)
    {

        // εκτύπωση σχετικού μηνύματος
        cout << s->get_name() << " enters corridor!" << endl;

        // ενημέρωση του state
        s->set_state(2);

        // προσθήκη του μαθητή στο διάδρομο
        corridor_array[current_students_in_corridor - 1] = s;
    }


    // αφαίρεση του τελευταίου μαθητή από το διάδρομο
    student *exit()
    {

        // προσπέλαση του πίνακα
        for (int i = capacity_corridor-1; i >= 0; i--)
        {

            if (corridor_array[i] != NULL)
            {

                student *s = corridor_array[i];

                // εκτύπωση σχετικού μηνύματος
                cout << corridor_array[i]->get_name() << " exits corridor!" << endl;
                
                // αφαίρεση του μαθητή
                corridor_array[i] = NULL;

                // επιστέφει τον μαθητή
                return s;
            }
        }
    }


    void print(){

        // εκτύπωση σχετικού μηνύματος
        cout << "People in corridor are: " << endl;

        // προσπέλαση του πίνακα
        for(int i = 0; i < capacity_corridor; i++){

            if(corridor_array[i] != NULL){

                // εκτύπωση σχετικού μηνύματος
                cout << corridor_array[i]->get_name() << endl;
            }
        }
    }


    // destructor
    ~corridor()
    {

        // εκτύπωση σχετικού μηνύματος
        cout << "A Corridor to be destroyed! " << endl;

        // αποδέσμευση χώρου του πίνακα
        delete[] corridor_array;
    }
};
