/////////////////////////////////////////////////////////////////////
//              ΑΦΗΡΗΜΕΝΗ ΚΛΑΣΣΗ ΧΩΡΟΣ
//  την κληρονομούν όλοι οι χώροι εκτός του school
/////////////////////////////////////////////////////////////////////
package spaces;

import people.student.*; 


public abstract class area
{
    // constructor
    public area(){

    }
    
    // βάζει έναν μαθητή στο χώρο
    public abstract void enter(student s);

    // βγάζει έναν μαθητή από το χώρο και τον επιστρέφει
    public abstract student exit();
}