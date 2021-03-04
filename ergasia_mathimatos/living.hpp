#ifndef LIVING_H
#define LIVING_H

#include <cstring>
#include <iostream>


using namespace std;




/////////////////////////////////////////////////////////////////////////////////////
//                ΚΛΑΣΗ LIVING
//
/////////////////////////////////////////////////////////////////////////////////////
class living
{
private:
    char* name; // το όνομα του ον
    int level;  // το επίπεδο του ον
    int health;   // η ζωη του ον

public:
    // constructor
    living(const char *nam) : level(0), health(100)
    {

        cout << " living constructor " << endl;

        // δέσμευση χώρου για το name
        name = new char[strlen(nam) + 1];

        // αντιγραφή του string nam στο name
        strcpy(name, nam);
    }

    // επιστρέφει το όνομα του ον
    char* get_name(){

        return name;
    }

    // επιστέφει το επίπεδο του ον
    int get_level(){

        return level;
    }

    // επιστρέφει τη ζωή του ον
    int get_health(){

        return health;
    }

    // αυξάνει το επίπεδο κατά no
    void set_level( int no){

        level = level + no;
    }

    void set_health(int no){

        health = no;
    }

    // αυξάνει τη ζωή του ον κατά c
    virtual void increase_health(int c)
    {

        health = health + c;
    }

    // μειώνει τη ζωη του ον κατά c
    void decrease_health(const int c)
    {
        
        if (health >= c){

            health -= c;
        }
        // αν η μείωση είναι μεγαλύτερη από την τρέχουσα ζωή του ον
        // η ζωή μηδενίζεται
        else{

            health = 0;
        }
    }

    virtual void level_up(const int c) = 0;

    // destructor
    virtual ~living(){

        cout << "living destructor" << endl;

        // αποδέσμευση χώρου του name
        delete[] name;
    }
};

#endif