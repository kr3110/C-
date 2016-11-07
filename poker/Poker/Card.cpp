//
//  Card.cpp
//  Poker
//
//  Created by Kevin Reinoso on 11/18/15.
//  Copyright © 2015 kr3110. All rights reserved.
//
#include<iostream>
#include "Card.hpp"
#include <string>
Card::Card(): suit(rand()%4), rank(rand()%13)
{}
Card::Card(int s,int r): suit(s),rank(r)
{/*empty*/}

//Accessors
int Card::getSuit() {return suit;}
int Card::getRank() {return rank;}

//Mutators
void Card::setSuit(int s)
{
    suit=s;
    while(s<0||s>3)
        suit=overbound(s);
}
void Card::setRank(int r)
{
    rank=r;
    while(r<0||r>13)
        rank=overbound(r);
}

//Functions
int Card::overbound(int p)
{
    cout << "Number " << p
         << " exceeds the limits. Please re-enter your number";
    int x;
    cin >> x;
    return x;
}
int Card::compareByRank(const Card& other)
{
    if(rank<other.rank)         return 1;
    else if(rank==other.rank)   return 0;
    else                        return -1;
}
int Card::compareBySuit(const Card & other)
{
    if(suit<other.suit)         return 1;
    else if(suit==other.suit)   return 0;
    else                        return -1;
}
string Card::getRankAsString() const
{
    string y;
    int size=rank+1;
    
    if(size==11)        y="J";
    else if(size==12)   y="Q";
    else if(size==13)   y="K";
    else if(size==1)    y="A";
    else                y=to_string(size);
    return y;
}
string Card::getSuitAsString() const
{
    string y;
    switch(suit)
    {
        case 0:
            y+=" \u2665";
            break;
        case 1:
            y+=" \u2663";
            break;
        case 2:
            y+=" \u2666";
            break;
        case 3:
            y+=" \u2660";
            break;
    }
    return y;
}
string Card::display()
{
    string y;
    int size=rank+1;
    
    if(size==11)        y="J";
    else if(size==12)   y="Q";
    else if(size==13)   y="K";
    else if(size==1)    y="A";
    else                y=to_string(size);
    
    switch(suit)
    {
        case 0:
            y+=" \u2665";
            break;
        case 1:
            y+=" \u2663";
            break;
        case 2:
            y+=" \u2666";
            break;
        case 3:
            y+=" \u2660";
            break;
    }
    return y;
}
ostream& operator << (ostream& out, const Card& other)
{
    string y;
    int size=other.rank+1;
    
    if(size==11)        y="J";
    else if(size==12)   y="Q";
    else if(size==13)   y="K";
    else if(size==1)    y="A";
    else                y=to_string(size);
    
    switch(other.suit)
    {
        case 0:
            y+=" \u2665";
            break;
        case 1:
            y+=" \u2663";
            break;
        case 2:
            y+=" \u2666";
            break;
        case 3:
            y+=" \u2660";
            break;
    }
    out << y << endl;
    return out;
}


