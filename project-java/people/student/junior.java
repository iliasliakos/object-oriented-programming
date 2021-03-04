////////////////////////////////////////////////////////////////
//              JUNIOR
//  κληρονομεί τη student
////////////////////////////////////////////////////////////////
package people.student;

public class junior extends student{

    private int Lj; // οι μονάδες που αυξάνεται ανά ώρα ο βαθμός κούρασης ενός junior

    ////////////////////////////////////////////////////////////////////////////////////////

    // constructor
    public junior(String nam, int f, int c, int l){

        // κλήση του constructor της student
        super( nam, f, c);

        // αρχικοποίηση του Lj
        Lj = l;
    }

    // δέχεται σαν όρισμα τις ώρες που παρακολουθεί ένας μαθητής
    public void attend(int hours)
    {
        
        // καλεί την attend του student
        super.attend(Lj * hours);
    }
}
