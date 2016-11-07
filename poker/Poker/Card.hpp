//
//  main.cpp
//  Poker
//
//  Created by Kevin Reinoso on 11/18/15.
//  Copyright © 2015 kr3110. All rights reserved.
//

#ifndef CARD_HPP
#define CARD_HPP

#include<iostream>
using namespace std;

class Card
{
private:
	//suit is represented with values 0-3
    //0 to hearts,1 club, 2 diamonds, 3 spades
    int         suit;
	//rank is represented with values 0-12
    //0 is A, 1 is 2,...., 10 is J, 11 Q, 12 K..
    int         rank;
    
public:
    Card ();
    Card (int, int);
    
	void setSuit (int);
	void setRank (int);
    
    int getSuit ();
    int getRank ();
    int overbound (int);
	int compareByRank (const Card&);
    //
    //Compare functions will return 1 if caller is greater 0 if they
    //      are equal, -1 if the parameter is greater.
    //
	int compareBySuit (const Card&);
	string getRankAsString () const;
	string getSuitAsString () const;
	string display();
	friend ostream& operator << (ostream&, const Card&);
};

#endif