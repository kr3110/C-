//
//  Hand.cpp
//  Poker
//
//  Created by Kevin Reinoso on 12/12/15.
//  Copyright © 2015 kr3110. All rights reserved.
//

#include "Hand.hpp"
#include "Card.hpp"
#include "LinkedList.hpp"
using namespace std;
Hand::Hand()
{
    playerhand=new LinkedList;
}
Hand::Hand(Card* first)
{
    playerhand->insertAtHead(first);
}
Hand::Hand(Card* first,Card* second)
{
    playerhand->insertAtHead(first);
    playerhand->insertAtTail(second);
}
void Hand::addcard(Card* card)
{
    playerhand->Insert(card);
}
void Hand::takecard(const int index)
{
    if(index==0)
        playerhand->removeAtHead();
    else if(index==playerhand->getSize()-1)
    {
        playerhand->removeAtTail();
    }
    else
        playerhand->removeAtIndex(index);
}
void Hand::displayHand()
{
    cout<<*playerhand;
}
Card* Hand::getCardAtIndex(int index)
{
    return playerhand->getAtIndex(index);
    
}
bool Hand::isempty()
{
    return playerhand->isEmpty();
}
