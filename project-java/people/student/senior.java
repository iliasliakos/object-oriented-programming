////////////////////////////////////////////////////////////////////
//              SENIOR
//  κληρονομεί τη student
////////////////////////////////////////////////////////////////////
package people.student;

public class senior extends student{

    private int Ls; // οι μονάδες που αυξάνεται ανά ώρα ο βαθμός κούρασης ενός senior

    ///////////////////////////////////////////////////////////////////////////////////////

    // constructor
    public senior(String nam, int f, int c, int l){

        // κλήση του constructor της student
        super( nam, f, c);

        // αρχικοποίηση του Ls
        Ls = l;
    }

    // δέχεται σαν όρισμα τις ώρες που παρακολουθεί ένας μαθητής
    public void attend(int hours)
    {

        // καλεί την attend του student
        super.attend(Ls * hours);
    }
}
