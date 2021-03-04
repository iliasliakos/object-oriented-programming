#include <cstring>
#include <iostream>

#include "student.h"


using namespace std;
/////////////////////////////////////////////////////////////////////////////////
//              ΚΛΙΜΑΚΟΣΤΑΣΙΟ
//
/////////////////////////////////////////////////////////////////////////////////
class stair
{
private:
    student **stair_array;                  // πίνακα με δείκτες σε μαθητές του κλιμακοστασίου
    int current_students_in_stair;          // ο αριθμός των μαθητών στο κλιμακοστάσιο
    int capacity_stair;                     // το μέγεθος του κλιμακοστασίου

public:

    // constructor
    stair(int Cstair) : current_students_in_stair(0), capacity_stair(Cstair)
    {

        // δέσμευση χώρου για τον πίνακα
        stair_array = new student *[Cstair];

        for(int i = 0; i < Cstair; i++){

            stair_array[i] = NULL;
        }

        // εκτύπωση σχετικού μηνύματος
        cout << "A New Stair has been created! " << endl;
    }


    // επιστρέφει τον πίνακα με τους μαθητές του κλιμακοστασίου
    student **get_stair_array()
    {

        return stair_array;
    }


    // επιστρέφει τον αριθμό των μαθητών στο κλιμακοστάσιο
    int get_current_students_in_stair()
    {

        return current_students_in_stair;
    }


    // κάνει τον αριθμό των μαθητών στο κλιμακοστάσιο ίσο με current
    void set_current_students_in_stair(int current)
    {

        current_students_in_stair = current;
    }


    // βάζει έναν μαθητή στο κλιμακοστάσιο
    void enter(student *s)
    {

        // εκτύπωση σχετικού μηνύματος
        cout << s->get_name() << " enters stair!" << endl;

        // ενημέρωση του state
        s->set_state(1);

        // προσθήκη του μαθητή στο πίνακα
        stair_array[current_students_in_stair-1] = s;
    }


    // βγάζει τον τελευταίο μαθητή και τον επιστρέφει
    student *exit()
    {

        // προσπέλαση του πίνακα με τους μαθητές
        for (int i = capacity_stair-1; i >= 0; i--)
        {

            if (stair_array[i] != NULL)
            {

                student *s = stair_array[i];

                // εκτύπωση σχετικού μηνύματος
                cout << stair_array[i]->get_name() << " exits stair!" << endl;

                // αφαίρεση του μαθητή
                stair_array[i] = NULL;

                // επιστρέφει το μαθητή
                return s;
            }
        }
    }


    void print(){

        // εκτύπωση σχετικού μηνύματος
        cout << "People in stairs are: " << endl;

        // προσπέλαση του πίνακα με τους μαθητές του κλιμακοστασίου
        for(int i = 0; i < capacity_stair; i++){

            if(stair_array[i] != NULL){

                // εκτύπωση του μαθητή
                cout << stair_array[i]->get_name() << endl;
            }
        }
    }


    // destructor
    ~stair()
    {

        // εκτύπωση σχετικού μηνύματος
        cout << "A Stair to be destroyed! " << endl;

        // αποδέσμευση χώρου του πίνακα
        delete[] stair_array;
    }
};
