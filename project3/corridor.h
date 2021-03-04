#include <cstring>
#include <iostream>

#include "area.h"
#include "student.h"

using namespace std;
/////////////////////////////////////////////////////////
//          ΔΙΑΔΡΟΜΟΣ
//
//////////////////////////////////////////////////////////////////////////
class corridor : public area
{
private:
    student *corridor_student; // δείκτης σε μαθητή που βρίσκονται στο διάδρομο

public:
    // constructor
    corridor() : area()
    {

        corridor_student = NULL;

        // εκτύπωση σχετικού μηνύματος
        cout << "A New Corridor has been created! " << endl;
    }

    // βάζει έναν μαθητή στο διάδρομο
    void enter(student *s)
    {

        // εκτύπωση σχετικού μηνύματος
        cout << s->get_name() << " enters corridor!" << endl;

        // προσθήκη του μαθητή στο διάδρομο
        corridor_student = s;
    }

    // βγάζει τον μαθητή και τον επιστρέφει
    student *exit()
    {

        if (corridor_student != NULL)
        {

            student *s = corridor_student;

            // εκτύπωση σχετικού μηνύματος
            cout << corridor_student->get_name() << " exits corridor!" << endl;

            // αφαίρεση του μαθητή
            corridor_student = NULL;

            // επιστέφει τον μαθητή
            return s;
        }
    }

    // destructor
    ~corridor()
    {

        // εκτύπωση σχετικού μηνύματος
        cout << "A Corridor to be destroyed! " << endl;
    }
};
