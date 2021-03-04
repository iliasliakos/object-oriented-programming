#include <cstring>
#include <iostream>

#include "area.h"
#include "student.h"

using namespace std;
////////////////////////////////////////////////////////////////
//               ΠΡΟΑΥΛΙΟ
//
////////////////////////////////////////////////////////////////////
class yard : public area
{
private:
    student *yard_student; // δείκτης σε μαθητή που βρίσκονται στο πράυλιο

public:
    // constructor
    yard() : area()
    {

        yard_student = NULL;

        // εκτύπωση σχετικού μηνύματος
        cout << "A New Yard has been created! " << endl;
    }

    // βάζει έναν μαθητή στο προάυλιο
    void enter(student *s)
    {

        // εκτύπωση σχετικού μηνύματος
        cout << s->get_name() << " enters schoolyard!" << endl;

        // είσοδος του μαθητή
        yard_student = s;
    }

    // βγάζει τον μαθητή από το προάυλιο και τον επιστέφει
    student *exit()
    {

        if (yard_student != NULL)
        {

            student *s = yard_student;

            // εκτύπωση σχετικού μηνύματος
            cout << yard_student->get_name() << " exits yard!" << endl;

            // αφαίρεση του μαθητή
            yard_student = NULL;

            // επιστρέφει τον μαθητή
            return s;
        }
    }

    // destructor
    ~yard()
    {

        // εκτύπωση σχετικού μηνύματος
        cout << "A Yard to be destroyed! " << endl;
    }
};
