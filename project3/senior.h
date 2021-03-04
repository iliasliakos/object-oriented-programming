#include <cstring>
#include <iostream>

#include "student.h"

using namespace std;

class senior : public student
{
private:
    int Ls; // οι μονάδες που αυξάνεται ανά ώρα ο βαθμός κούρασης ενός junior

public:
    // constructor
    senior(const char *nam, int f, int c, int l) : student(nam, f, c), Ls(l) {}

    // δέχεται σαν όρισμα τις ώρες που παρακολουθεί ένας μαθητής
    void attend(int hours)
    {

        // καλεί την attend του student
        student :: attend(Ls * hours);
    }

    // destructor
    ~senior() {}
};