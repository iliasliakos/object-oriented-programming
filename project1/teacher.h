#ifndef TEACHER_H
#define TEACHER_H

#include <cstring>
#include <iostream>


using namespace std;
//////////////////////////////////////////////////////////
//      ΚΑΘΗΓΗΤΗΣ
//  
////////////////////////////////////////////////////////
class teacher
{
private:
    char *name;
    int class_no;
    int floor_no;
    // βρίσκεται στη τάξη -> state = 1
    // δεν βρίσκεται στην τάξη -> state - 0
    int state;

public:
    // constructor
    teacher(const char *nam, int f, int c, int s) : class_no(c), floor_no(f), state(s)
    {

        // δέσμευση χώρου για το name
        name = new char[strlen(nam) + 1];

        // αντιγραφή του string nam στο name
        strcpy(name, nam);

        // εκτύπωση σχετικού μηνύματος
        cout << "A New Teacher has been created! ";
        cout << "name = " << name << " class = " << class_no << " floor = " << floor_no << endl;
    }


    // επιστρέφει το όνομα του καθηγητή
    char *get_name()
    {

        return name;
    }


    // επιστρέφει τον αριθμό της τάξης του καθηγητή
    int get_class_no()
    {

        return class_no;
    }


    // επιστρέφει τον αριθμό του ορόφου του καθηγητή
    int get_floor_no()
    {

        return floor_no;
    }


    // επιστρέφει το state του καθηγητή
    int get_state()
    {

        return state;
    }


    // κάνει το state ίσο με s
    void set_state(int s)
    {

        state = s;
    }


    // destructor
    ~teacher()
    {

        // εκτύπωση σχετικού μηνύματος
        cout << "A Teacher to be destroyed! ";
        cout << " name = " << name << " class = " << class_no << " floor = " << floor_no << " state = " << state << endl;

        // αποδέσμευση χώρου του name
        delete[] name;
    }
};
#endif