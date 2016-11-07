//
//  Players.cpp
//  Poker
//
//  Created by Kevin Reinoso on 12/12/15.
//  Copyright © 2015 kr3110. All rights reserved.
//
#include "Players.hpp"
#include <string>
Player::Player()
{
    chips=1000;
    hand1=new Hand;
    name="";
    playing=true;
    round =1;
    lose=false;
    
}
Player::Player(string nam)
{
    name=nam;
    chips=1000;
    hand1 = new Hand;
}
Player::Player(int money)
{
    chips = money;
}
Player::Player(int money,Hand* Cards,string nam)
{
    name=nam;
    hand1=Cards;
    chips=money;
    
}
//Player::~Player()
//{
//    delete hand1;
//}
void Player::addCardtoHand(Card* newCard)
{
    hand1->addcard(newCard);
}
Card* Player:: removeCard(int index)
{
    Card* move=hand1->getCardAtIndex(index);
    hand1->takecard(index);
    return move;
}
void Player::Displayhand()      {hand1->displayHand();}
void Player::SetName(string nam){name=nam;}
void Player::setchips(int money){chips=money;}
int Player::getchips()          {return chips;}
string Player::getName()        {return name;}
Hand* Player::GetHand()         {return hand1;}
bool Player::isplaying()        {return playing;}