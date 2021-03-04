#ifndef STUDENT_H
#define STUDENT_H

#include <cstring>
#include <iostream>


using namespace std;
//////////////////////////////////////////////////////////////////////
//          ΜΑΘΗΤΗΣ
//
//////////////////////////////////////////////////
class student
{
private:
    char *name;   // το όνομα του μαθητή
    int class_no; // ο αριθμός της τάξης του μαθητή
    int floor_no; // ο αριθμός του ορόφου του μαθητή

    // προάυλιο = 0
    // κλιματοστάσιο = 1
    // διάδρομος = 2
    // τάξη = 3
    // εκτός σχολικού χώρου = 4
    int state; // η κατάσταση του μαθητή

public:

    // constructor
    student(const char *nam, int f, int c, int s) : class_no(c), floor_no(f), state(s)
    {

        // δέσμευση χώρου για το name
        name = new char[strlen(nam) + 1];

        // αντιγραφή του string nam στο name
        strcpy(name, nam);

        // εκτύπωση σχετικού μηνύματος
        cout << "A New Student has been created! ";
        cout << "name = " << name << "class = " << class_no << " floor = " << floor_no << endl;
    }


    // επιστρέφει το όνομα του μαθητή
    char *get_name()
    {

        return name;
    }


    // επιστρέφει το αριθμό της τάξης του μαθητή
    int get_class_no()
    {

        return class_no;
    }


    // επιστρέφει το αριθμό του ορόφου του μαθητή
    int get_floor_no()
    {

        return floor_no;
    }


    // επιστρέφει το state του μαθητή
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
    ~student()
    {

        // εκτύπωση σχετικού μηνύματος
        cout << "A Student to be destroyed! ";
        cout << "name = " << name << "class = " << class_no << " floor = " << floor_no << "state = " << state << endl;

        // αποδέσμευση χώρου του name
        delete[] name;
    }
};

#endif
