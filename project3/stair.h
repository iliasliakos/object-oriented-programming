#include <cstring>
#include <iostream>

#include "area.h"
#include "student.h"

using namespace std;
/////////////////////////////////////////////////////////////////////////////////
//              ΚΛΙΜΑΚΟΣΤΑΣΙΟ
//
/////////////////////////////////////////////////////////////////////////////////
class stair : public area
{
private:
    student *stair_student; // δείκτης σε μαθητή που βρίσκονται στο κλιμακοστάσιο

public:

    // constructor
    stair() : area()
    {

        stair_student = NULL;

        // εκτύπωση σχετικού μηνύματος
        cout << "A New Stair has been created! " << endl;
    }

    // βάζει έναν μαθητή στο κλιμακοστάσιο
    void enter(student *s)
    {

        // εκτύπωση σχετικού μηνύματος
        cout << s->get_name() << " enters stair!" << endl;

        // είσοδος του μαθητή
        stair_student = s;
    }

    // βγάζει τον μαθητή και τον επιστρέφει
    student *exit()
    {

        if (stair_student != NULL)
        {

            student *s = stair_student;

            // εκτύπωση σχετικού μηνύματος
            cout << stair_student->get_name() << " exits stair!" << endl;

            // αφαίρεση του μαθητή
            stair_student = NULL;

            // επιστρέφει το μαθητή
            return s;
        }
    }

    // destructor
    ~stair()
    {

        // εκτύπωση σχετικού μηνύματος
        cout << "A Stair to be destroyed! " << endl;
    }
};
