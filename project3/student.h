#ifndef STUDENT_H
#define STUDENT_H

#include <cstring>
#include <iostream>

#include "person.h"

using namespace std;
//////////////////////////////////////////////////////////////////////
//          ΜΑΘΗΤΗΣ
//
//////////////////////////////////////////////////
class student : public person
{
private:
    int class_no; // ο αριθμός της τάξης του μαθητή
    int floor_no; // ο αριθμός του ορόφου του μαθητή

    // εκτός τάξης = 0
    // εντός τάξης = 1
    int state; // η κατάσταση του μαθητή
    int rate;  // βαθμός κούρασης μαθητή

public:
    // constructor
    student(const char *nam, int f, int c) : person(nam), class_no(c), floor_no(f), state(0), rate(0)
    {

        // εκτύπωση σχετικού μηνύματος
        cout << "A New Student has been created! ";
        cout << "name = " << get_name() << " class = " << class_no << " floor = " << floor_no << endl;
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

    // κάνει το βαθμό κούρασης ίσο με r
    void set_rate(int r)
    {

        rate = r;
    }

    void print()
    {
        // εκτύπωση σχετικού μηνύματος
        cout << get_name() << " " << rate << endl;
    }

    // κάνει το μαθμό κούρασης του μαθητή ίσο με i
    virtual void attend(int i){

        set_rate(i);
    }

    // destructor
    virtual ~student()
    {

        // εκτύπωση σχετικού μηνύματος
        cout << "A Student to be destroyed! ";
        cout << "name = " << get_name() << " class = " << class_no << " floor = " << floor_no << "state = " << state << endl;
    }
};

#endif
