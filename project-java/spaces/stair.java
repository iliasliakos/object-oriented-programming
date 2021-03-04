/////////////////////////////////////////////////////////////////
//              ΚΛΙΜΑΚΟΣΤΑΣΙΟ
//
/////////////////////////////////////////////////////////////////
package spaces;

import people.student.*; 


public class stair extends area{

    private student stair_student;  // μαθητής που βρίσκεται στο κλιμακοστάσιο

    ////////////////////////////////////////////////////////////////////////////

    // constructor
    public stair(){

        // κλήση του constructor της area
        super();

        // αρχίκοποίηση του μαθητή που βρίσκεται στο κλιμακοστάσιο
        stair_student = null;

        // εκτύπωση σχετικού μηνύματος
        System.out.println(" A New Stair has been created! ");
    }

    // δέχεται σας όρισμα έναν μαθητή και τον προσθέτει στο κλιμακοστάσιο
    public void enter(student s){

        // εκτύπωση σχετικού μηνύματος
        System.out.println(s.get_name() + " enters stair ");

        // είσοδος του μαθητή
        stair_student = s;
    }

    // βγάζει τον μαθητή και τον επιστρέφει
    public student exit()
    {

        student s = stair_student;

        // εκτύπωση σχετικού μηνύματος
        System.out.println(stair_student.get_name() + " exits stair ");
        
        // αφαίρεση του μαθητή
        stair_student = null;

        // επιστρέφει το μαθητή
        return s;
    }
}