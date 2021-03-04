#ifndef ITEM_H
#define ITEM_H

#include <cstring>
#include <iostream>



//#include "hero.hpp"
//#include "party.hpp"

class hero;
using namespace std;




///////////////////////////////////////////////////////////////////////////////////////
//                ΚΛΑΣΗ ITEM
//
/////////////////////////////////////////////////////////////////////////////////////
class item
{
private:
    char* name; // όνομα του αντικειμένου
    int price;  // τιμή του αντικειμένου
    int level;  // ελαχιστό επίπεδο που χρειάζεται να έχει ένας ήρωας για να το χρησιμοποιήσει
    
public:

    // constructor
    item(const char *nam, int p, int l) : price(p), level(l)
    {

        cout << " item constructor " << endl;

        // δέσμευση χώρου για το name
        name = new char[strlen(nam) + 1];

        // αντιγραφή του string nam στο name
        strcpy(name, nam);
    }

    // επιστρέφει το όνομα του αντικειμένου
    char *get_name()
    {

        return name;
    }

    // επιστρέφει την τιμή του αντικειμένου
    int get_price(){

        return price;
    }

    // επιστρέφει το επίπεδο
    int get_level(){

        return level;
    }

    virtual void print() = 0;

    virtual void equip(hero* h, int pos) = 0;

    virtual void use(hero* h, int pos) = 0;

    virtual int get() = 0;

    //destructor
    virtual ~item(){

        cout << "item destructor" << endl;

        // αποδέσμευση χώρου του name
        delete[] name;
    }
};

#endif
