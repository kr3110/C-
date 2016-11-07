//
//  Deck.cpp
//  Poker
//
//  Created by Kevin Reinoso on 11/19/15.
//  Copyright © 2015 kr3110. All rights reserved.
//
#include <iostream>
#include "Deck.hpp"
using namespace std;

Deck::Deck(){
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            deck.push(new Card(i, j));
        }
    }
}
void Deck::shuffle()
{
    Card* helper[52];
    int i=0;
    while(!deck.isEmpty())
    {
        helper[i]=deck.pop();
        i++;
    }
    for (int k = 0 ; k < 52 ; k++)
    {
        int l = k + int( (51-k)*(rand()/(RAND_MAX+1.0)) );
        swap(helper[k], helper[l]);
    }
    
    while(!(deck.isFull()))
    {
        i--;
        deck.push(helper[i]);
    }
    
}

int Deck::getCount()
{
    return deck.getSize();
}
Card* Deck::deal()
{
    return deck.pop();
}

const Card* Deck::deal(int x)
{
    return NULL;
}
//REVIEW the display...
ostream& operator << (ostream& out,  Deck& other)
{
    Card* helper[52];
    int i=51;
    
    while(!other.deck.isEmpty())
    {
        helper[i]=other.deck.pop();
        --i;
    }
    i=51;
    
    while(!(other.deck.isFull()))
    {   cout << *helper[i];
        other.deck.push(helper[i]);
        i--;
    }
    return out;
}
void Deck::ReturnCard(Card* other)
{
    deck.push(other);
}