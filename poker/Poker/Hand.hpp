//
//  Hand.hpp
//  Poker
//
//  Created by Kevin Reinoso on 12/12/15.
//  Copyright © 2015 kr3110. All rights reserved.
//

#ifndef Hand_hpp
#define Hand_hpp

#include "Card.hpp"
#include "LinkedList.hpp"
using namespace std;

class Hand{
public:
    Hand();
    Hand(Card*);
    Hand(Card*,Card*);
    
    void addcard(Card*);
    void takecard(const int);
    void displayHand();
    
    Card* getCardAtIndex(int);
    bool isempty();
private:
    LinkedList* playerhand;
};
#endif /* Hand_hpp */
