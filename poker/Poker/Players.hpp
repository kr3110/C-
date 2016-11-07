//
//  Players.hpp
//  Poker
//
//  Created by Kevin Reinoso on 12/12/15.
//  Copyright © 2015 kr3110. All rights reserved.
//

#ifndef Players_hpp
#define Players_hpp
#include "Hand.hpp"
#include <stdio.h>
#include <string>
class Player{
private:
    bool playing;
    int chips;
    string name;
    Hand* hand1;    
public:
    Player();
    Player(int);
    Player(int, Hand*,string);
    Player(string);
    //~Player();

    void SetName(string);
    void setchips(int);
    void Displayhand();
    void addCardtoHand(Card*);
    
    bool isplaying();
    bool lose;
    int goodtogo;
    int round;
    int getchips();
    string getName();
    Hand* GetHand();
    Card* removeCard(int );
};
#endif /* Players_hpp */
