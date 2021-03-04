////////////////////////////////////////////////////////////////////////////
//              ΑΦΗΡΗΜΕΝΗ ΚΛΑΣΣΗ ΑΝΘΡΩΠΟΣ
//  την κληρονομούν οι teacher και student
///////////////////////////////////////////////////////////////////////////
package people;

public abstract class person{

    private String name;    // το όνομα του ανθρώπου

    ///////////////////////////////////////////////////////////////

    // constructor
    public person(String nam){

        // εκτύπωση σχετικού μηνύματος
        System.out.println("person constructor");

        // αρχικοποίηση του πεδίου
        name = nam;
    }

    // επιστρέφει το όνομα του ανθρώπου
    public String get_name()
    {

        return name;
    }

    public abstract void print();
}