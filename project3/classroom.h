#include <cstring>
#include <iostream>

#include "area.h"
#include "student.h"
#include "teacher.h"


using namespace std;
///////////////////////////////////////////////////////////////////////////////////////
//              ΤΑΞΗ
//
/////////////////////////////////////////////////////////////////////////////////////
class classroom : public area
{
private:
    student **class_array;                      // πίνακας με δείκτες στους μαθητές που είναι στη τάξη 
    teacher* class_teacher;                     // δείκτης σε teacher
    int current_students_in_classroom;          // ο αριθμός των μαθητών που είναι στη τάξη
    int capacity_class;                         // το μέγεθος της τάξης

public:

    // constructor
    classroom(int Cclass) : area(), current_students_in_classroom(0), capacity_class(Cclass)
    {

        // δέσμευση χώρου για τον πίνακα
        class_array = new student *[Cclass];

        for(int i = 0; i < Cclass; i++){

            class_array[i] = NULL;
        }

        class_teacher = NULL;

        // εκτύπωση σχετικού μηνύματος
        cout << "A New classroom has been created!  " << endl;
    }

    // βάζει έναν μαθητή στη τάξη
    void enter(student* s){

        // εκτύπωση σχετικού μηνύματος
        cout << s->get_name() << " enters classroom!" <<  endl;

        // ενημέρωση του state
        s->set_state(1);

        // προσθήκη του μαθητή στο πίνακα
        class_array[current_students_in_classroom] = s;
        current_students_in_classroom++;
    }


    void print(int number){

        // εκτύπωση σχετικού μηνύματος
        cout << "People in class " << number << " are " << endl;

        // προσπέλαση του πίνακα 
        for(int i = 0; i < capacity_class; i++){

            if(class_array[i] != NULL){
                
                // κλήση της print του μαθητή
                class_array[i]->print();
            }
        }

        // αν υπάρχει καθηγητής
        if(class_teacher != NULL){

            // κλήση της print του καθηγητή
            class_teacher->print();
        }
    }

    // δέχεται σαν όρισμα τις ώρες που λειτουργεί μία τάξη
    void operate(int hours){

        // προσπέλαση του πίνακα 
        for(int i = 0; i < capacity_class; i++){

            if(class_array[i] != NULL){
                
                // κλήση της attend του μαθητή
                class_array[i]->attend(hours);
            }
        }

        // κλήση της teach του δασκάλου
        class_teacher->teach(hours);
    }

    // δέχεται έναν δείκτη σε teacher
    void place(teacher* t){

        // αλλάζει το state του δασκάλου
        t->set_state(1);

        // τοποθέτηση του teacher στη τάξη
        class_teacher = t;
    }

    //destructor
    ~classroom()
    {

        // εκτύπωση σχετικού μηνύματος
        cout << "A classroom to be destroyed! " << endl;

        // αποδέσμευση χώρου του πίνακα
        delete[] class_array;
    }
};
