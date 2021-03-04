#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "school.h"
#include "student.h"
#include "teacher.h"


using namespace std;


int main(int argc, char *argv[])
{
    // Δημιουργία του school
    school s(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));

    ////////////////////////////////////////////////////////////////////////////////////////////
    // Διάβαζει από ένα αρχείο μαθητές και δασκάλους και μετράει πόσοι είναι οι μαθητές και πόσοι οι δάσκαλοι

    std::ifstream file("file.txt");
    std::string line;

    int count_students = 0; // μετρητής για τους μαθητές
    int count_teachers = 0; // μετρητής για τους καθηγητές

    while (std ::getline(file, line))
    {

        std::stringstream linestream(line);
        std ::string string1;

        linestream >> string1;

        if (string1.compare("s") == 0)
        {

            count_students++;
        }
        else
        {
            count_teachers++;
        }

        cout << string1 << endl;
    }

    //////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////

    
    // Δημιουργία πινάκων με δείκτες σε student και teacher αντίστοιχα
    student *students_array[count_students];
    teacher *teachers_array[count_teachers];

    std ::ifstream file2("file.txt");
    std ::string line2;

    int i = 0;
    int y = 0;

    // Διαβάζει όλες τις γραμμές του αρχείου μία μία
    while (std ::getline(file2, line2))
    {

        std::stringstream linestream2(line2);

        std ::string string2;     // Αν είναι "s" είναι student αλλίως είναι teacher
        std ::string name;        // το όνομα του teacher ή του student
        int number_of_floor;      //  ο όροφος του teacher ή του student
        int number_of_class;      // η τάξη του teacher ή του student
        int state;                // το state του teacher ή του student

        linestream2 >> string2 >> name >> number_of_floor >> number_of_class >> state;

        // αν είναι student
        if (string2.compare("s") == 0)
        {

            char *student_name = &name[0];

            // δημιουργία νέου student
            students_array[i] = new student(student_name, number_of_floor, number_of_class, state);
            i++;
        }
        // αν είναι teacher
        else
        {

            char *teacher_name = &name[0];

            // δημιουργία νέου teacher
            teachers_array[y] = new teacher(teacher_name, number_of_floor, number_of_class, state);
            y++;
        }
    }


    /////////////////////////////////////////////////////////////////////////////////////////////////
    // σε κάθε επανάληψη αποφασίζει πόσοι student θα προσπαθήσουν να μπουν στο κτήριο
    // και καλεί την μαζική enter του σχολείου για αυτούς του μαθητές
    // ύστερα αποφασίζει πόσοι καθηγητές θα μπουν στις τάξεις τους και καλεί την place του σχολείου για αυτούυς
    // η επάναληψη τελείωνει όταν έχουν προσπαθήσει να μπουν όλοι οι μαθητές
    ///////////////////////////////////////////////////////////////////////////////////////


    int max_remaining_students = count_students + 1;   
    int max_remaining_teachers = count_teachers + 1;

    int random;
    int random1;

    int z = 0;
    int t = 0;

    srand(time(0));
    
    while (max_remaining_students != 1)
    {
        random = rand() % max_remaining_students;       // βρίσκει έναν αριθμό από 0 μέχρι όσους μαθητές δεν έχουν μπει ακόμα
        random1 = rand() % max_remaining_teachers;      // βρίσκει έναν αριθμό από 0 μέχρι όσους καθηγητές δεν έχουν μπει ακόμα
        
        // αν υπάρχουν μαθητές που θέλουν να μπουν
        if (random != 0)
        {

            // δημιουργία ενός πίνακα με δείκτες σε student που θέλουν να μπουν
            student *array[random];
            for (int i = 0; i < random; i++)
            {

                array[i] = students_array[z];
                z++;
            }

            // κλήση της mass_enter του σχολείου
            s.mass_enter(array, random, count_students);
        }

        // αν υπάρχουν καθηγητές που θέλουν να μπουν στις τάξεις τους 
        if (random1 != 0)
        {

            for (int i = 0; i < random1; i++)
            {

                // αλλαγή του state
                teachers_array[t]->set_state(1);

                // κλήση της place του σχολείου
                s.place(teachers_array[t]);

                t++;
            }
        }

        // ενημέρωση του max_remaining_teachers
        max_remaining_teachers = max_remaining_teachers - random1;
        // ενημέρωση του max_remaining_students
        max_remaining_students = max_remaining_students - random;
    }


    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////

    // κλήση της print του σχολείου
    s.print();


    // αποδέσμευση των μαθητών
    for (i = 0 ; i < count_students ; i++){

        delete students_array[i];
    }

    // αποδέσμευση των καθηγητών
    for (i = 0 ; i < count_teachers ; i++){

        delete teachers_array[i];
    }
}