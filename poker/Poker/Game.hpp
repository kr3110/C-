//
//  Game.hpp
//  Poker
//
//  Created by Kevin Reinoso on 12/12/15.
//  Copyright © 2015 kr3110. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp
#include "Hand.hpp"
#include "Players.hpp"
#include "Deck.hpp"
#include <stdio.h>
class Game{
public:
    Game();
    ~Game();
    void Startgame();
    void menu();
    void Poker();
    void table();
    void round();
    void holdemrepart();
    void holdemgame();
    void WinningHand(int winner);
    void deactivateplayer();
    void betstaking();
    void flop();
    void turn();
    void clean_up();
    void river();
    void evaluateHands();
    
    bool playerstobet();
    int computer(int,int);
    int pokerComputer(int);
    int tryHand(int [], int);
    int getWinner();
    int oneLeft();
    int Score(Card[]);
    
private:
    int bestHand[6][3];
    int position=4;
    int numplayers;
    int gametoplay;
    int turns;
    int bet;
    int bet_on;
    int pot;
    int action;
    int rational;
    int winner;
    int maxPoints;
    int handPoints[6];
    int roundWinner;
    string name;
    Player* players;
    Card* cardstab[5];
    Deck cards;
};
#endif /* Game_hpp */
