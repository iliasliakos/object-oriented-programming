/////////////////////////////////////////////////////////////////////
//          ΔΑΣΚΑΛΟΣ
//  κληρονομεί τη person
/////////////////////////////////////////////////////////////////////
package people;

public class teacher extends person{

    private int class_no;   // ο αριθμός της τάξης του δασκάλου
    private int floor_no;   // ο αριθμός του ορόφου του δασκάλου

    // βρίσκεται στη τάξη -> state = 1
    // δεν βρίσκεται στην τάξη -> state - 0
    private int state;

    private int rate;   // βαθμός κούρασης δασκάλου
    private int Lt; // οι μονάδες που αυξάνεται ανά ώρα ο βαθμός κούρασης ενός teacher

    //////////////////////////////////////////////////////////////////////////////////////////

    // constructor
    public teacher(String nam, int f, int c, int l)
    {

        // κλήση του constructor της super
        super(nam);

        // αρχικοποίηση των πεδίων
        class_no = c;
        floor_no = f;
        state = 0;
        rate = 0;
        Lt = l;

        // εκτύπωση σχετικού μηνύματος
        System.out.println("A New Teacher has been created! ");
        System.out.println("name = " + get_name() + " class = " + class_no + " floor = " + floor_no);
    }

    // επιστρέφει τον αριθμό της τάξης του καθηγητή
    public int get_class_no()
    {

        return class_no;
    }


    // επιστρέφει τον αριθμό του ορόφου του καθηγητή
    public int get_floor_no()
    {

        return floor_no;
    }


    // επιστρέφει το state του καθηγητή
    public int get_state()
    {

        return state;
    }

    // κάνει το state ίσο με i
    public void set_state(int i){

        state = i;
    }

    // δέχεται σαν όρισμα τις ώρες που διδάσκει ένας teacher
    public void teach(int hours){

        // ενημερώνει τον βαθμό κούρασης του
        rate = Lt * hours;
    }


    public void print(){
        
        // εκτύπωση σχετικού μηνύματος
        System.out.println("The teacher is " + get_name() + " " + rate);
    }
}