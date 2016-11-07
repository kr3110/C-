//
//  deck.hpp
//  Poker
//
//  Created by Kevin Reinoso on 11/18/15.
//  Copyright © 2015 kr3110. All rights reserved.
//
#ifndef DECK_HPP
#define DECK_HPP

#include "Stack.hpp"
#include "Card.hpp"

class Deck {
private:
	Stack deck;
public:
    
	Deck();
	void shuffle();
    void ReturnCard(Card*);
    
    int getCount();
    Card* deal();
	const Card* deal(int);
	
    friend ostream& operator << (ostream&, Deck&);
    
};

#endif