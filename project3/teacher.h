#ifndef TEACHER_H
#define TEACHER_H

#include <cstring>
#include <iostream>

#include "person.h"


using namespace std;
//////////////////////////////////////////////////////////
//      ΚΑΘΗΓΗΤΗΣ
//  
////////////////////////////////////////////////////////
class teacher : public person
{
private:
    
    int class_no;
    int floor_no;
    // βρίσκεται στη τάξη -> state = 1
    // δεν βρίσκεται στην τάξη -> state - 0
    int state;
    int rate;
    int Lt;

public:
    // constructor
    teacher(const char *nam, int f, int c, int l) : person(nam), class_no(c), floor_no(f), state(0), rate(0), Lt(l)
    {

        // εκτύπωση σχετικού μηνύματος
        cout << "A New Teacher has been created! ";
        cout << "name = " << get_name() << " class = " << class_no << " floor = " << floor_no << endl;
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

    // κάνει το state ίσο με i
    void set_state(int i){

        state = i;
    }

    // δέχεται σαν όρισμα τις ώρες που διδάσκει ένας teacher
    void teach(int hours){

        // ενημερώνει τον βαθμό κούρασης του
        rate = Lt * hours;
    }


    void print(){
        
        cout << "The teacher is " << get_name() << " " << rate << endl;
    }


    // destructor
    ~teacher()
    {

        // εκτύπωση σχετικού μηνύματος
        cout << "A Teacher to be destroyed! ";
        cout << " name = " << get_name() << " class = " << class_no << " floor = " << floor_no << " state = " << state << endl;
    }
};
#endif