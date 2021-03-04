#ifndef MONSTER_H
#define MONSTER_H

#include <cstring>
#include <iostream>

#include "living.hpp"

using namespace std;

//////////////////////////////////////////////////////////////////////////////////////
//      ΚΛΑΣΣΗ MONSTER
// κληρονομεί την LIVING
//////////////////////////////////////////////////////////////////////////////////////
class monster : public living
{
private:
	int mindam;	// η μικρότερη ζημιά που μπορεί να κάνει το τέρας
	int maxdam;	// η μεγαλύτερη ζημιά που μπορεί να κάνει το τέρας
	int defence;	// η άμυνα του τέρας
	int avoid;	// η πιθανότητα να αποφύγει ένα χτύπημα

public:
	
	// constructor
	monster(const char *nam, const int mind, const int maxd, const int def, const int av) : living(nam), mindam(mind), maxdam(maxd), defence(def), avoid(av)
	{

	}

	// destructor
	~monster()
	{

	}

	// αυξάνει το maxdam κατά c
	void increase_maxdamage(const int c = 3)
	{

		maxdam += c;
	}

	// μειώνει το maxdamage κατά c
	void decrease_maxdamage(const int c = 3)
	{

		maxdam -= c;
	}

	// αυξάνει το mindam κατά c
	void increase_mindamage(const int c = 3)
	{

		mindam += c; 
	}

	// μειώνει το mindam κατά c
	void decrease_mindamage(const int c = 3)
	{

		mindam -= c; 
	}

	// αυξάνει το defence κατά c
	void increase_defence(const int c = 5){

		defence += c; 
	}

	// μειώνει το defence κατά c
	void decrease_defence(const int c = 2){

		defence -= c; 
	}

	// αυξάνει το avoid κατά c
	void increase_avoid(const int c = 10){

		avoid += 10; 
	}

	// μειώνει το avoid κατά c
	void decrease_avoid(const int c = 10){

		avoid -= 10; 
	}

	virtual void level_up(const int c)
	{
		
		set_level(c);
	}

	virtual void print() const
	{
		cout << "Name  :" << endl;

		cout << "LEVEL 	:" << endl;

		cout << "Health Points  = " << endl;
	}

	virtual void print_all()
	{

		cout << "  Monster\n"
			 << get_name() << "\nLevel :  " << get_level() << endl;

		cout << "__Statistics __ \nRange :" << mindam << " -- " << maxdam << "\nDefence  :"
			 << defence << "\nChance to avoid  :" << avoid << "%\n"
			 << "Life Points :     " << get_health() << endl;
	}

	// επιστρέφει το defence
	int getdefence()
    {

		return defence;
	}

	// επιστρέφει το mindam
    int getmindam()
    {

		return mindam;
	}

	// επιστρέφει το maxdam
    int getmaxdam()
    {

		return maxdam;
	}

	// επιστρέφει το avoid
	int getavoid(){

		return avoid;
	}

	// βρίσκει έναν τυχαίο αριθμό που βρίσκεται
	// στο εύρος ζημιάς του και τον επιστρέφει
	int attack(){

        int d,c = 0;

        srand(time(NULL));

        c = 1 + getmaxdam()-getmindam();

        d = rand() % c;

        c = getmindam() + d;

        return c;
	}

	void print_name(){

		cout << get_name() << endl;
	}
};
#endif