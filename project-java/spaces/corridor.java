////////////////////////////////////////////////////////////////////////
//                  ΔΙΑΔΡΟΜΟΣ
//
///////////////////////////////////////////////////////////////////
package spaces;

import people.student.*; 


public class corridor extends area{

    private student corridor_student;   // μαθητής που βρίσκεται στο διάδρομο

    //////////////////////////////////////////////////////////////////////////////////////////////

    // constructor
    public corridor(){

        // κλήση του constructor της area
        super();

        // αρχικοποίηση της corridor_student
        corridor_student = null;

        // εκτύπωση σχετικού μηνύματος
        System.out.println(" A New Corridor has been created! ");
    }

    // δέχεται σας όρισμα έναν μαθητή και τον προσθέτει στο διάδρομο
    public void enter(student s){
        
        // εκτύπωση σχετικού μηνύματος
        System.out.println(s.get_name() + " enters corridor ");

        // προσθήκη του μαθητή στο διάδρομο
        corridor_student = s;
    }

    // βγάζει έναν μαθητή από το διάδρομο και τον επιστρέφει
    public student exit(){

        student s = corridor_student;

        // εκτύπωση σχετικού μηνύματος
        System.out.println(corridor_student.get_name() + " exits corridor ");

        // αφαίρεση του μαθητή
        corridor_student = null;

        // επιστέφει τον μαθητή
        return s;
    }
}