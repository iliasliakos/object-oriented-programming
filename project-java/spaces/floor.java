//////////////////////////////////////////////////////////////////////////////////////
//                  ΟΡΟΦΟΣ
//
//////////////////////////////////////////////////////////////////////////////////////
package spaces;

import people.*;
import people.student.*; 


public class floor extends area{

    private corridor floor_corridor;    // ο διάδρομος του ορόφου
    private classroom[] floor_array_of_classrooms = new classroom[6];   // πίνακας με τις τάξεις του ορόφου

    /////////////////////////////////////////////////////////////////////////////////////////////////

    // constructor
    public floor(int Cclass){

        // κλήση του constructor της area
        super();

        // αρχικοποίση του πίνακα με τις τάξεις του ορόφου
        floor_corridor = new corridor();
        for(int i = 0; i < 6; i++){

            floor_array_of_classrooms[i] = new classroom(Cclass);
        }

        // εκτύπωση σχετικού μηνύματος
        System.out.println(" A New Floor has been created! ");
    }

    // δέχεται σας όρισμα έναν μαθητή, τον προωθεί στο διάδρομο, τον βγάζει από εκεί
    // και μέτα καλεί την enter της τάξης του μαθητή
    public void enter(student s){

        // εκτύπωση σχετικού μηνύματος
        System.out.println(s.get_name() + " enters floor " + s.get_floor_no());

        // κλήση της enter του διαδρόμου
        floor_corridor.enter(s);

        // κλήση της exit του διαδρόμου
        student ss = floor_corridor.exit();

        //κλήση της enter της αντίστοιχης τάξης
        floor_array_of_classrooms[ss.get_class_no() - 1].enter(ss);
    }

    // βγάζει έναν μαθητή από όποια τάξη έχει ακόμα μαθητές, και τον επιστρέφει
    // αν έχουν αδειάσει όλες οι τάξεις του ορόφου επιστρέφει null
    public student exit(){

        student s;

        // προσπέλαση του πίνακα των τάξεων
        for(int i = 0; i < 6; i++){

            // κλήση της exit της τάξης
            s = floor_array_of_classrooms[i].exit();

            // αν δεν επέστρεψε null, σημαίνει ότι η τάξη δεν ήταν άδεια
            if(s != null){

                // εκτύπωση σχετικού μηνύματος
                System.out.println(s.get_name() + " starts exiting!");

                // βάζει το μαθητή στο διάδρομο
                floor_corridor.enter(s);

                // βγάζει το μαθητή από το διάδρομο
                student ss = floor_corridor.exit();

                // επιστρέφει το μαθητή
                return ss;
            }
        }

        // αν όλες οι τάξεις είναι άδειες επιστρέφει null
        return null;
    }

    // βγάζει τους δασκάλους από τις τάξεις του ορόφου αυτού
    public void teachers_out(){

        // προσπέλαση του πίνακα των τάξεων
        for(int i = 0; i < 6; i++){

            // αφαίρεση του δασκάλου της τάξης
            floor_array_of_classrooms[i].teachers_out();
        }
    }

    // βάζει το δάσκαλο στη τάξη του
    public void place(teacher t){

        // καλεί την place της τάξης για αυτόν τον teacher
        floor_array_of_classrooms[t.get_class_no() - 1].place(t);
    }


    // δέχεται σαν όρισμα τις ώρες που λειτουργεί ένας όροφος
    public void operate(int hours){

        for(int i = 0; i < 6; i++){

            // κλήση των operate για κάθε τάξη
            floor_array_of_classrooms[i].operate(hours);
        }
    }


    public void print(int no){

        // εκτύπωση σχετικού μηνύματος
        System.out.println("Floor number " + no + " contains ");

        for(int i = 0; i < 6; i++){

            // κλήση της print της τάξης
            floor_array_of_classrooms[i].print(i+1);
        }
    }
}