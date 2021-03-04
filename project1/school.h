#include <iostream>
#include <cstring>

#include "floor.h"
#include "stair.h"
#include "yard.h"
#include "student.h"
#include "teacher.h"


using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
//               ΣΧΟΛΕΙΟ
//
///////////////////////////////////////////////////////////////////////////////////////////
class school
{
private:
    floor *school_array_of_floors[3]; // πίνακας με δείκτες στα 3 floor

    stair school_stair; // το κλιματοστάσιο
    int capacity_stair; // το μέγεθος του κλιματοστασίου

    yard school_yard;  // το προάυλιο
    int capacity_yard; // το μέγεθος του προαυλιού

    int capacity_corridor; // το μέγεθος του διαδρόμου

    int students_have_entered_yard; // counter για το πόσοι μαθητές έχουν μπει ή περάσει από το προάυλιο

public:

    // constructor
    school(int Cclass, int Cyard, int Cstair, int Ccorr) : school_yard(Cyard), school_stair(Cstair), capacity_stair(Cstair), capacity_yard(Cyard), capacity_corridor(Ccorr), students_have_entered_yard(0)
    {

        // δέσμευση χώρου και δημιουργία τριών floor
        for (int i = 0; i < 3; i++)
        {

            school_array_of_floors[i] = new floor(Cclass, Ccorr);
        }

        // εκτύπωση σχετικού μηνύματος
        cout << "A New School has been created! " << endl;
    }
    

    // δέχεται έναν δείκτη σε student και το συνολικό πλήθος των μαθητών
    // επιστρέφει 1 αν ο μαθητής μπήκε στο προάυλιο
    bool enter(student *s, int all_students)
    {
        // γίνεται 1 αν ο μαθητής μπήκε στο προάυλιο
        int flag = 0;

        // έλεγχος για το αν χωράει να μπει στο yard
        int current_yard = school_yard.get_current_students_in_yard();
        if (current_yard != capacity_yard)
        {

            student *ss = s;

            // αύξηση κατά ένα τον μαθητών που είναι στο yard
            current_yard++;
            school_yard.set_current_students_in_yard(current_yard);

            // κλήση της enter του yard
            school_yard.enter(ss);

            // αύξηση κατά ένα των μαθητών που έχουν περάσει από το yard
            students_have_entered_yard++;

            // ενημέρωση του flag
            flag = 1;
        }

        // αν το yard έχει γεμίσει ή αν δεν υπάρχουν άλλοι μαθητές που θέλουν να μπουν σε αυτό
        if (current_yard == capacity_yard || all_students == students_have_entered_yard)
        {

            // όσο το κλιματοστάσιο δεν έχει γεμίσει και όσο υπάρχουν ακόμα μαθητές στο yard
            int current_stair = school_stair.get_current_students_in_stair();
            while (school_yard.get_current_students_in_yard() != 0 && current_stair != capacity_stair)
            {

                // έξοδος μαθητή από το yard με κλήση της exit του yard
                student *s1 = school_yard.exit();

                // μείωση των μαθητών που είναι στο yard κατα ένα
                school_yard.set_current_students_in_yard(school_yard.get_current_students_in_yard() - 1);

                // αύξηση των μαθητών στο κλιματοστάσιο κατα 1
                school_stair.set_current_students_in_stair(school_stair.get_current_students_in_stair() + 1);

                // κλήση της enter του κλιματοστασίου
                school_stair.enter(s1);


                // αν το stair έχει γεμίσει ή αν δεν υπάρχουν άλλοι μαθητές  που θέλουν να μπουν
                if (capacity_stair == school_stair.get_current_students_in_stair() || school_yard.get_current_students_in_yard() == 0)
                {
                    
                    // πίνακας με δείκτες στου μαθητές που είναι στο κλιματοστάσιο
                    student **stair_students = school_stair.get_stair_array();

                    int count_for_floor_1 = 0;      // counter για το πόσοι μαθητές θέλουν να μπουν στο 1 όροφο
                    int count_for_floor_2 = 0;      // counter για το πόσοι μαθητές θέλουν να μπουν στο 2 όροφο
                    int count_for_floor_3 = 0;      // counter για το πόσοι μαθητές θέλουν να μπουν στο 3 όροφο

                    // ο αριθμός των μαθητών που είναι στο stair
                    int new_current = school_stair.get_current_students_in_stair();


                    // προσπέλαση των μαθητών και αύξηση του αντίστοιχου counter ανάλογα με τον όροφο
                    // που θέλει ο μαθητής να πάει
                    for (int y = 0; y < new_current; y++)
                    {

                        // αν θέλει να πάει στο 1 όροφο
                        if (stair_students[y]->get_floor_no() == 1)
                        {

                            count_for_floor_1++;
                        }
                        // αν θέλει να πάει στο 2 όροφο
                        else if (stair_students[y]->get_floor_no() == 2)
                        {

                            count_for_floor_2++;
                        }
                        // αν θέλει να πάει στο 3 όροφο
                        else
                        {
                            count_for_floor_3++;
                        }
                    }


                    // προσπέλαση των μαθητών του κλιματοστασίου
                    for (int y = new_current - 1; y >= 0; y--)
                    {

                        // έλεγχος για τον αν χωράει ο μαθητής να μπεί στο διάδρομο του ορόφου που θέλει
                        int current_cor = school_array_of_floors[stair_students[y]->get_floor_no() - 1]->get_current_students_in_corridor();
                        if (current_cor != capacity_corridor)
                        {

                            // έξοδος μαθητή απο το stair 
                            // με κλήση της exit του κλιματοστασίου
                            student *s2 = school_stair.exit();

                            // μείωση των μαθητών που είναι στο κλιματοστάσιο κατα 1
                            school_stair.set_current_students_in_stair(school_stair.get_current_students_in_stair() - 1);

                            // αύξηση των μαθητών που είναι στο διάδρομο του ορόφου που θέλει
                            // να πάει ο μαθητής που βγήκε από το κλιματοστάσιο
                            school_array_of_floors[s2->get_floor_no() - 1]->set_current_students_in_corridor(current_cor + 1);

                            // αν ο μαθητής θέλει να πάει στο 1 όροφο
                            if (s2->get_floor_no() == 1)
                            {

                                // κλήση της enter αυτού του ορόφου
                                school_array_of_floors[s2->get_floor_no() - 1]->enter(s2, count_for_floor_1);   
                            }
                            // αν ο μαθητής θέλει να πάει στο 2 όροφο
                            else if (s2->get_floor_no() == 2)
                            {

                                // κλήση της enter αυτού του ορόφου
                                school_array_of_floors[s2->get_floor_no() - 1]->enter(s2, count_for_floor_2);
                            }
                            // αν ο μαθητής θέλει να πάει στο 3 όροφο
                            else
                            {

                                // κλήση της enter αυτού του ορόφου
                                school_array_of_floors[s2->get_floor_no() - 1]->enter(s2, count_for_floor_3);
                            }
                        }
                    }
                }

                // ενημέρωση του current_stair
                current_stair = school_stair.get_current_students_in_stair();
            }
        }

        // επιστροφή του flag
        return flag;
    }


    // δέχεται έναν πίνακα με δείκτες σε μαθητές, το μέγεθος αυτού του πίνακα 
    // και των αριθμό όλων των μαθητών
    void mass_enter(student *array[], int size, int all_students)
    {

        int count = school_yard.get_current_students_in_yard();   // ο αριμός των μαθητών που έχει το yard
        int null_count = 0;                                       // μετρητής για το πόσοι μαθητές μπήκαν στο προάυλιο

        // όσο χωράνε μαθητές στο προάυλιο
        //  και όσο δεν έχουν μπεί όλοι οι μαθητές του πίνακα
        while (count != capacity_yard && null_count != size)
        {

            // προσπέλαση των μαθητών
            for (int i = 0; i < size; i++)
            {

                // αν ο μαθητής δεν έχει μπει
                if (array[i] != NULL)
                {

                    // κλήση της enter του σχολείου για αυτόν το μαθητή
                    // αν ο μαθητής μπήκε στο προάυλιο
                    if (enter(array[i], all_students) == 1)
                    {

                        // αφαίρεση από το πίνακα και ενημέρωση του null_count
                        array[i] = NULL;
                        null_count++;

                        // αν μπήκαν όλοι οι μαθητές απο το πίνακα 
                        if (null_count == size)
                        {
                            break;
                        }
                    }
                }
            }

            // ενημέρωση του count
            count = school_yard.get_current_students_in_yard();
        }
    }


    // δέχεται έναν δείκτη σε teacher
    void place(teacher *t)
    {

        // καλεί την place του ορόφου για αυτόν τον teacher
        school_array_of_floors[t->get_floor_no() - 1]->place(t);
    }



    void print()
    {

        // εκτύπωση σχετικού μηνύματος
        cout << "School life consists of:  " << endl;

        // κλήση της print για το yard, το stair και όλους τους ορόφόυς
        school_yard.print();
        school_stair.print();
        school_array_of_floors[0]->print(1);
        school_array_of_floors[1]->print(2);
        school_array_of_floors[2]->print(3);
    }
    

    // destructor
    ~school()
    {

        // εκτύπωση σχετικού μηνύματος
        cout << "A School to be destroyed! " << endl;

        // αποδέσμευση χώρου για τα 3 floor
        for (int i = 0; i < 3; i++)
        {

            delete school_array_of_floors[i];
        }
    }
};
