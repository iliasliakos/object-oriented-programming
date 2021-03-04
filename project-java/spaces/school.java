//////////////////////////////////////////////////////////////
//              ΣΧΟΛΕΙΟ
//
//////////////////////////////////////////////////////////////
package spaces;

import people.*;
import people.student.*; 


public class school{

    private yard school_yard;   // το προάυλιο του σχολείου
    private stair school_stair; // το κλιμακοστάσιο του σχολείου
    private floor[] school_array_of_floors = new floor[3];  // πίνακας με τους ορόφους του σχολείου

    ///////////////////////////////////////////////////////////////////////////////////////////////////

    // constructor
    public school(int Cclass){
        
        // αρχικοποίηση του προαυλίου
        school_yard = new yard();

        // αρχικοποίηση του κλιμακοστασίου
        school_stair = new stair();

        // αρχικοποίηση του πίνακα
        for(int i = 0; i < 3; i++){

            school_array_of_floors[i] = new floor(Cclass);
        }

        // εκτύπωση σχετικού μηνύματος
        System.out.println(" A New School has been created! ");
    }

    // βάζει το μαθητή στο προάυλιο, τον βγάζει, μετά τον βάζει στο κλιμακοστάσιο
    // και τέλος τον βγάζει από εκεί και τον βάζει στον όροφο του
    public void enter(student s){

        // εκτύπωση σχετικού μηνύματος
        System.out.println(s.get_name() + " enters school ");

        // κλήση της enter του yard
        school_yard.enter(s);

        // κλήση της exit του yard
        student ss = school_yard.exit();

        // κλήση της enter του stair
        school_stair.enter(ss);

        // κλήση της exit του stair
        student sss = school_stair.exit();

        // κλήση της enter του αντίστοιχου floor
        school_array_of_floors[sss.get_floor_no() - 1].enter(sss);
    }

    // αδείαζει το σχολείο
    public void empty(){

        student s;

        // προσπέλαση του πίνακα με τους ορόφους του σχολείου
        for(int i = 0; i < 3; i++){
        
            // επανάλαβε μέχρι να αδειάσει ο όροφος
            while(true){

                // κλήση της exit του ορόφου
                s = school_array_of_floors[i].exit();

                // αν δεν είναι null, σημαίνει ότι ο όροφος δεν έχει αδείασει ακόμα
                if(s != null){

                    // βάζει το μαθητή στο κλιμακοστάσιο
                    school_stair.enter(s);

                    // βγάζει το μαθητή από το κλιμακοστάσιο
                    student ss = school_stair.exit();

                    // βάζει το μαθητή στο προάυλιο
                    school_yard.enter(ss);

                    // βγάζει το μαθητή από το προάυλιο
                    student sss = school_yard.exit();
                }
                else{

                    // break και προχωράει στον επόμενο όροφο
                    break;
                }
            }
        }

        // προσπέλαση του πίνακα με τους ορόφους
        for(int i = 0; i < 3; i++){

            // βγάζει τους δασκάλους κάθε ορόφου
            school_array_of_floors[i].teachers_out();
        }
    }

    // βάζει το δάσκαλο στον όροφο του
    public void place(teacher t){

        // καλεί την place του ορόφου για αυτόν τον teacher
        school_array_of_floors[t.get_floor_no() - 1].place(t);
    }

    // δέχεται σαν όρισμα τις ώρες που λειτουργεί ένα σχολείο
    public void operate(int hours){

        for(int i = 0; i < 3; i++){

            // κλήση των συναρτήσεων operate για κάθε όροφο
            school_array_of_floors[i].operate(hours);
        }
       
    }

    public void print(){

        // εκτύπωση σχετικού μηνύματος
        System.out.println("School life consists of: ");

        for(int i = 0; i < 3; i++){

            // κλήση της print του ορόφου
            school_array_of_floors[i].print(i+1);
        }
    }
}