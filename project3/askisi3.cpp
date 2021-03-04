#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "school.h"
#include "student.h"
#include "teacher.h"
#include "junior.h"
#include "senior.h"


using namespace std;




int main(int argc, char *argv[])
{

    // Δημιουργία του school
    school s(atoi(argv[1]));

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

        linestream2 >> string2 >> name >> number_of_floor >> number_of_class;

        // αν είναι student
        if (string2.compare("s") == 0)
        {

            char *student_name = &name[0];

            // αν είναι junior
            if(number_of_class <=3){

                // δημιουργία νέου student junior
                students_array[i] = new junior(student_name, number_of_floor, number_of_class, atoi(argv[2]));
                
            }
            else{

                // δημιουργία νέου student junior
                students_array[i] = new senior(student_name, number_of_floor, number_of_class, atoi(argv[3]));
            }
            
            i++;
        }
        else{

            char *teacher_name = &name[0];

            // δημιουργία νέου teacher
            teachers_array[y] = new teacher(teacher_name, number_of_floor, number_of_class, atoi(argv[4]));
            y++;
        }

    }

    // κλήση της enter της school για κάθε μαθητή
    for(int z = 0; z < count_students; z++){

        s.enter(students_array[z]);
    }

    // κλήση της place της school για κάθε καθηγητή
    for(int k = 0; k < count_teachers; k++){

        s.place(teachers_array[k]);
    }
   
    // κλήση της operate της school 
    s.operate(atoi(argv[5]));

    // κλήση της print της school
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