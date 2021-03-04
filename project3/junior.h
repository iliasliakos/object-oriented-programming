#include <cstring>
#include <iostream>

#include "student.h"

using namespace std;

class junior : public student
{
private:
    int Lj; // οι μονάδες που αυξάνεται ανά ώρα ο βαθμός κούρασης ενός senior

public:
    // constructor
    junior(const char *nam, int f, int c, int l) : student(nam, f, c), Lj(l){

    }

    // δέχεται σαν όρισμα τις ώρες που παρακολουθεί ένας μαθητής
    void attend(int hours)
    {

        // καλεί την attend του student
        student :: attend(hours * Lj);
    }

    // destructor
    ~junior() {}
};