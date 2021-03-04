///////////////////////////////////////////////////////////////////
//            ΜΑΘΗΤΗΣ              
//  κληρονομεί τη person
///////////////////////////////////////////////////////////////////
package people.student;

import people.*;

public class student extends person{

    private int class_no; // ο αριθμός της τάξης του μαθητή
    private int floor_no; // ο αριθμός του ορόφου του μαθητή

    // εκτός τάξης = 0
    // εντός τάξης = 1
    private int state; // η κατάσταση του μαθητή
    private int rate;  // βαθμός κούρασης μαθητή

    ////////////////////////////////////////////////////////////////////

    // constructor
    public student(String nam, int f, int c)
    {

        // κλήση constructor της person
        super(nam);

        // αρχικοποίηση των πεδίων
        floor_no = f;
        class_no = c;
        state = 0;
        rate = 0;

        // εκτύπωση σχετικού μηνύματος
        System.out.println("A New Student has been created! ");
        System.out.println("name = " + get_name() + " class = " + class_no + " floor = " + floor_no);
    }

    // επιστρέφει το αριθμό της τάξης του μαθητή
    public int get_class_no()
    {

        return class_no;
    }

    // επιστρέφει το αριθμό του ορόφου του μαθητή
    public int get_floor_no()
    {

        return floor_no;
    }

    // επιστρέφει το state του μαθητή
    public int get_state()
    {

        return state;
    }

    // κάνει το state ίσο με s
    public void set_state(int s)
    {

        state = s;
    }

    // κάνει το βαθμό κούρασης ίσο με r
    public void set_rate(int r)
    {

        rate = r;
    }

    public void print()
    {

        // εκτύπωση σχετικού μηνύματος
        System.out.println(get_name() + " " + rate);
    }

    // κάνει το μαθμό κούρασης του μαθητή ίσο με i
    public void attend(int i){

        set_rate(i);
    }
}