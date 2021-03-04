#include <cstring>
#include <iostream>

#include "student.h"
#include "teacher.h"


using namespace std;
///////////////////////////////////////////////////////////////////////////////////////
//              ΤΑΞΗ
//
/////////////////////////////////////////////////////////////////////////////////////
class classroom
{
private:
    student **class_array;                      // πίνακας με δείκτες στους μαθητές που είναι στη τάξη 
    teacher* class_teacher;                     // δείκτης σε teacher
    int current_students_in_classroom;          // ο αριθμός των μαθητών που είναι στη τάξη
    int capacity_class;                         // το μέγεθος της τάξης

public:

    // constructor
    classroom(int Cclass) : current_students_in_classroom(0), capacity_class(Cclass)
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
    

    // επιστρέφει τον αριθμό των μαθητών που βρίσκονται στη τάξη
    int get_current_students_in_classroom(){

        return current_students_in_classroom;
    }


    // κάνει τον αριθμό των μαθητών της τάξης ίσο με current
    void set_current_students_in_classroom(int current){

        current_students_in_classroom = current;
    }


    // επιστρέφει δείκτη στον καθηγητή της τάξης
    teacher* get_class_teacher(){
        return class_teacher;
    }


    // βάζει έναν μαθητή στη τάξη
    void enter(student* s){

        // εκτύπωση σχετικού μηνύματος
        cout << s->get_name() << " enters classroom!" <<  endl;

        // ενημέρωση του state
        s->set_state(3);

        // προσθήκη του μαθητή στο πίνακα
        class_array[current_students_in_classroom - 1] = s;
    }


    // βάζει τον δείκτη class_teacher να δείχνει στο καθηγητή t
    void place(teacher* t){

        class_teacher = t;
    }


    void print(int number){

        // εκτύπωση σχετικού μηνύματος
        cout << "People in class " << number << " are " << endl;

        // προσπέλαση του πίνακα 
        for(int i = 0; i < current_students_in_classroom; i++){

            if(class_array[i] != NULL){
                
                // εκτύπωση του μαθητή
                cout << class_array[i]->get_name() << endl;
            }
        }

        // αν υπάρχει καθηγητής
        if(class_teacher != NULL){

            // εκτύπωση του καθηγητή
            cout << "The teacher is " << class_teacher->get_name() << endl;
        }
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
