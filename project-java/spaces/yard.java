/////////////////////////////////////////////////////////////////////
//              ΠΡΟΑΥΛΙΟ
//
/////////////////////////////////////////////////////////////////////
package spaces;

import people.student.*; 


class yard extends area{

    private student yard_student;   // μαθητής που βρίσκεται στο προάυλιο

    ///////////////////////////////////////////////////////////////////////////

    // constructor
    public yard(){

        // κλήση του constructor της area
        super();

        // αρχικοποίηση του μαθητή που βρίσκεται στη τάξη
        yard_student = null;

        // εκτύπωση σχετικού μηνύματος
        System.out.println(" A New Yard has been created! ");
    }

    // δέχεται σας όρισμα έναν μαθητή και τον προσθέτει στο προάυλιο
    public void enter(student s){

        // εκτύπωση σχετικού μηνύματος
        System.out.println(s.get_name() + " enters schoolyard ");

        // είσοδος του μαθητή
        yard_student = s;
    }

    // βγάζει τον μαθητή από το προάυλιο και τον επιστέφει
    public student exit()
    {

        student s = yard_student;

        // εκτύπωση σχετικού μηνύματος
        System.out.println(s.get_name() + " exits schoolyard ");

        // αφαίρεση του μαθητή
        yard_student = null;

        // επιστρέφει τον μαθητή
        return s;
    }
}