#include <cstring>
#include <iostream>

#include "student.h"


using namespace std;
////////////////////////////////////////////////////////////////
//               ΠΡΟΑΥΛΙΟ
//
////////////////////////////////////////////////////////////////////
class yard
{
private:
    student **yard_array;               // πίνακας με δείκτες σε μαθητές που βρίσκονται στο πράυλιο
    int current_students_in_yard;       // ο αριθμός των μαθητών που βρίσκονται στο προάυλιο
    int capacity_yard;                  // το μέγεθος του προαυλίου

public:

    // constructor
    yard(int Cyard) : current_students_in_yard(0), capacity_yard(Cyard)
    {

        // δέσμευση χώρου για τον πίνακα
        yard_array = new student *[Cyard];

        for(int i = 0; i < Cyard; i++){

            yard_array[i] = NULL;
        }

        // εκτύπωση σχετικού μηνύματος
        cout << "A New Yard has been created! " << endl;
    }


    // επιστρέφει το πίνακα με τους μαθητές στου προαυλίου
    student **get_yard_array()
    {

        return yard_array;
    }


    // επιστρέφει τον αριθμό των μαθητών που βρίσκονται στο προάυλιο
    int get_current_students_in_yard()
    {

        return current_students_in_yard;
    }


    // κάνει τον αριθμό των μαθητών που βρίσκονται στο προάυλιο ίσο με current
    void set_current_students_in_yard(int current)
    {

        current_students_in_yard = current;
    }


    // βάζει έναν μαθητή στο προάυλιο
    void enter(student *s)
    {

        // εκτύπωση σχετικού μηνύματος
        cout << s->get_name() << " enters schoolyard!" << endl;

        // ενημέρωση του state
        s->set_state(0);

        // είσοδος του μαθητή στο πίνακα
        yard_array[current_students_in_yard - 1] = s;
    }


    // βγάζει τον τελευταίο μαθητή από το προάυλιο και τον επιστέφει
    student* exit()
    {

        // προσπέλαση του πίνακα με του μαθητές του προαυλίου
        for(int i = capacity_yard-1; i >= 0; i--){

            if(yard_array[i] != NULL){

                student* s = yard_array[i];

                // εκτύπωση σχετικού μηνύματος
                cout << yard_array[i]->get_name() << " exits yard!" << endl;

                // αφαίρεση του μαθητή
                yard_array[i] = NULL;

                // επιστρέφει τον μαθητή
                return s;
            }
        }
       
    }


    void print(){

        // εκτύπωση σχετικού μηνύματος
        cout << "People in schoolyard are:  " << endl;

        // προσπέλαση του πίνακα
        for(int i = 0; i < capacity_yard; i++){

            if(yard_array[i] != NULL){

                // εκτύπωση του μαθητή
                cout << yard_array[i]->get_name() << endl; 
            }
        }
    }


    // destructor
    ~yard()
    {

        // εκτύπωση σχετικού μηνύματος
        cout << "A Yard to be destroyed! " << endl;

        // αποδέσμευση χώρου του πίνακα
        delete[] yard_array;
    }
};
