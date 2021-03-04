#ifndef PERSON_H
#define PERSON_H


#include <cstring>
#include <iostream>


using namespace std;
///////////////////////////////////////////////////////////////////////////////////////
//              ΑΦΗΡΗΜΕΝΗ ΚΛΑΣΗ SPACE
//
/////////////////////////////////////////////////////////////////////////////////////
class person{

private:
    char* name;

public:

    // constructor
    person(const char *nam){

        cout << "person constructor" << endl;

        // δέσμευση χώρου για το name
        name = new char[strlen(nam) + 1];

        // αντιγραφή του string nam στο name
        strcpy(name, nam);
    }

    // επιστρέφει το όνομα του ανθρώπου
    char *get_name()
    {

        return name;
    }

    virtual void print() = 0;

    // destructor
    virtual ~person(){

        cout << "person des" << endl;
        // αποδέσμευση χώρου του name
        delete[] name;
    }
};

#endif
