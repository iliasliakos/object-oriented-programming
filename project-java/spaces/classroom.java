////////////////////////////////////////////////////////////////////////////////
//                  ΤΑΞΗ
//
////////////////////////////////////////////////////////////////////////////////
package spaces;

import people.*;
import people.student.*; 


public class classroom extends area{

    private student[] array_of_students;    // πίνακας με τους μαθητές της τάξης                        
    private teacher class_teacher;  // ο δάσκαλος της τάξης
    
    private int current_students_in_classroom;  // ο αριθμός των μαθητών που είναι στη τάξη
    private int capacity_class; // το μέγεθος της τάξης

    /////////////////////////////////////////////////////////////////////////////////////

    //constructor
    public classroom(int Cclas){

        // κλήση του constructor της area
        super();

        // αρχικοποιήση της current_students_in_classroom
        current_students_in_classroom = 0;
        // αρχικοποίηση της capacity_class
        capacity_class = Cclas;

        // αρχικοποίηση του πίνακα μαθητών
        array_of_students = new student[Cclas];
        for(int i = 0; i < Cclas; i++){

            array_of_students[i] = null;
        }

        // εκτύπωση σχετικού μηνύματος
        System.out.println(" A New classroom has been created!");
    }

    // δέχεται σας όρισμα έναν μαθητή και τον προσθέτει στη τάξη
    public void enter(student s){

        // εκτύπωση σχετικού μηνύματος
        System.out.println(s.get_name() + " enters classroom! ");

        // ενημέρωση του state
        s.set_state(1);

        // προσθήκη του μαθητή στο πίνακα
        array_of_students[current_students_in_classroom] = s;
        current_students_in_classroom++;
    }

    // βγάζει τον τελευταίο μαθητή από την τάξη και τον επιστρέφει
    // αν δεν υπάρχει άλλος μαθητής στη τάξη επιστρέφει null
    public student exit(){

        // αν έχουν βγει όλοι οι μαθητές 
        if(current_students_in_classroom == 0){

            // επιστρέφει null
            return null;
        }

        student s = array_of_students[current_students_in_classroom - 1];

        // εκτύπωση σχετικού μηνύματος
        System.out.println(s.get_name() + " exits classroom ");

        // αφαίρεση του τελευταίου μαθητή
        array_of_students[current_students_in_classroom - 1] = null;

        // μείωση των μαθητών που είναι στη τάξη κατά ένα
        current_students_in_classroom--;

        // επιστροφή του μαθητή
        return s;  
    }

    // αφαιρεί το δάσκαλο από τη τάξη
    public void teachers_out(){

        // ενημέρωση του state του δασκάλου
        class_teacher.set_state(0);

        // εκτύπωση σχετικού μηνύματος
        System.out.println(class_teacher.get_name() + " teacher is out! ");

        // αφαίρεση του δασκάλου
        class_teacher = null;
    }

    // εκτυπώνει τους μαθητές και το δάσκαλο που βρίσκονται στη τάξη
    public void print(int number){

        // εκτύπωση σχετικού μηνύματος
        System.out.println("People in class " + number + " area ");

        // προσπέλαση του πίνακα 
        for(int i = 0; i < capacity_class; i++){

            if(array_of_students[i] != null){
                
                // κλήση της print του μαθητή
                array_of_students[i].print();
            }
        }

        // αν υπάρχει καθηγητής
        if(class_teacher != null){

            // κλήση της print του καθηγητή
            class_teacher.print();
        }
    }

    // δέχεται σαν όρισμα τις ώρες που λειτουργεί μία τάξη
    public void operate(int hours){

        // προσπέλαση του πίνακα 
        for(int i = 0; i < capacity_class; i++){

            if(array_of_students[i] != null){
                
                // κλήση της attend του μαθητή
                array_of_students[i].attend(hours);
            }
        }

        // κλήση της teach του δασκάλου
        class_teacher.teach(hours);
    }

    // τοποθετεί το δάσκαλο στη τάξη
    public void place(teacher t){

        // αλλάζει το state του δασκάλου
        t.set_state(1);

        // τοποθέτηση του teacher στη τάξη
        class_teacher = t;
    }
}