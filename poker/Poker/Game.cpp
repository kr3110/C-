//
//  Game.cpp
//  Poker
//
//  Created by Kevin Reinoso on 12/12/15.
//  Copyright © 2015 kr3110. All rights reserved.
//

#include "Game.hpp"
#include <cstdlib>
#include "Players.hpp"
#include <iostream>
#include "Deck.hpp"
#include <time.h>
#include "Card.hpp"
#include <iomanip>
#include <string>
using namespace std;
Game::Game()
{
    menu();
}
Game::~Game()
{
    delete[] players;
}
void Game::menu()
{
    cout<<"*******************************************"<<endl
        <<"*************** CARD GAME *****************"<<endl
        <<"*******************************************"<<endl
        <<"\t\tSelect a Game to Play."<<endl
        <<"\t\t\t1) Hold'em Texas Poker"<<endl
        <<"\t\t\t2) Exit"<<endl;
    cin>>gametoplay;
    
    while (gametoplay<1||gametoplay>2)
    {
        cout<<"***********************************************************"<<endl
            <<"Invalid Number... Try again.."<<endl
            << "\t\t\t*****CARD GAME*****"<<endl
            <<"\tSelect the Game to Play."<<endl
            <<"\t\t\t1) Hold'em Texas Poker"<<endl
            <<"\t\t\t2) Exit"<<endl;
        cin>>gametoplay;
    }
    switch (gametoplay)
    {
        case 1:
            Poker();
            break;
        case 2:
            cout<<"***********************************************************"<<endl
                <<"Thanks for playing Our game ";
            exit(1);
    }
    
}
void Game::Poker()
{
    cout<<"*******************************************"<<endl
        <<"*********** Hold'em Texas Poker ***********"<<endl
        <<"*******************************************"<<endl
        <<"Enter Your name: ";
    cin>>name;
    cout<<"*******************************************"<<endl
        <<"*******************************************"<<endl;
    
    numplayers=6;
    players=new Player[numplayers];
    srand(time(0));
    
    for(int i=0;i<numplayers;i++)
    {
        string temp="Player ";
        if(i!=position-1)
        {
            
            temp=temp+to_string(i+1);
            players[i].SetName(temp);
        }
        else
            players[position-1].SetName(name);
    }
    
    for(int i=0;i<5;i++)
    
    cardstab[i]=nullptr;
    cout<<name<< ", Your Seat Number Is: 4"<<endl;
    players[position-1].SetName(name);
    cout<<"Ready in 3...."<<endl;
    //sleep(1);
    cout<<"2............."<<endl;
    //sleep(1);
    cout<<"1............."<<endl;
    //sleep(1);
    turns =1;
    
    while(numplayers>1)
    {
        cards.shuffle();
        cout<<"TURN "<<turns<<":"<<endl;
        holdemgame();
        clean_up();
        if(players[3].lose==true)
        {cout<<"You lose";
            exit(1);
        }
        if(players[0].lose==true&&players[1].lose==true&&players[2].lose==true&&players[4].lose==true&&players[5].lose==true)
            
        {
            cout<<"you win"<<endl;
            cout<<"you the best";
            exit(0);
        }
    }
}
void Game::table()
{
    
    
    cout << "  " << ((players[0].isplaying()) ? (players[0].getName()) : "      ")
    << "         " << ((players[1].isplaying()) ? (players[1].getName()) : "     ")
    << "           "
    << ((players[2].isplaying()) ? (players[2].getName()) : "    ") << endl;
    
    cout << "   $" << setw(4) << ((players[0].isplaying()) ? (players[0].getchips()) : 0)
    << "         $" << setw(4) << ((players[1].isplaying()) ? (players[1].getchips()) : 0)
    << "           $" << setw(4) << ((players[2].isplaying()) ? (players[2].getchips()) : 0) << endl;
    
    cout << "     *****************************" << endl;
    cout << "    *                             *" << endl;
    cout << "   *  ___   ___   ___   ___   ___  *" << endl;
    cout << "   * | " << ((cardstab[0]!=nullptr) ? cardstab[0]->getRankAsString() : " ")
    << " | | " << ((cardstab[1]!=nullptr) ? cardstab[1]->getRankAsString() : " ")
    << " | | " << ((cardstab[2]!=nullptr) ? cardstab[2]->getRankAsString() : " ")
    << " | | " << ((cardstab[3]!=nullptr) ? cardstab[3]->getRankAsString() : " ")
    << " | | " << ((cardstab[4]!=nullptr) ? cardstab[4]->getRankAsString() : " ")
    << " |  *" << endl;
    
    cout << "   * | " << ((cardstab[0]!=nullptr) ? cardstab[0]->getSuitAsString() : "  ")
    << "| | " << ((cardstab[1]!=nullptr) ? cardstab[1]->getSuitAsString() : "  ")
    << "| | " << ((cardstab[2]!=nullptr) ? cardstab[2]->getSuitAsString() : "  ")
    << "| | " << ((cardstab[3]!=nullptr)? cardstab[3]->getSuitAsString() : "  ")
    << "| | " << ((cardstab[4]!=nullptr) ? cardstab[4]->getSuitAsString() : "  ")
    << "|  *" << endl;
    
    cout << "   * |___| |___| |___| |___| |___| *" << endl;
    cout << "   *                               *" << endl;
    cout << "   *	       Pot = $" << setw(4) << pot << "         *" << endl;
    cout << "    *                             *" << endl;
    cout << "     *****************************" << endl;
    cout << endl;
    
    cout << "  " << ((players[5].isplaying()) ? (players[5].getName()) : "      ")
    << "          " << ((players[4].isplaying()) ? (players[4].getName()) : "      ")
    << "         "
    << ((players[3].isplaying()) ? (players[3].getName()) : "    ") << endl;
    
    cout << "   $" << setw(4) << ((players[5].isplaying()) ? (players[5].getchips()) : 0)
    << "          $" << setw(4) << ((players[4].isplaying()) ? (players[4].getchips()) : 0)
    << "         $" << setw(4) << ((players[3].isplaying()) ? (players[3].getchips()) : 0) << endl;
    cout << endl;
    
    Hand* temp=players[3].GetHand();
    if(!temp->isempty())
    {
        cout << "   Your hand:" << endl;
        cout << "    ___    ___" << endl;
        cout << "   |" << temp->getCardAtIndex(0)->getRankAsString() << " |  | " << temp->getCardAtIndex(1)->getRankAsString()  << " |" << endl;
        cout << "   |" << temp->getCardAtIndex(0)->getSuitAsString() << " |  | " << temp->getCardAtIndex(1)->getSuitAsString() << " |" << endl;
        cout << "   |___|  |___|" << endl << endl;
    }
    //sleep(2);
}

void Game::holdemrepart()
{
    for (int i=0;i<2;i++)
    {
        for (int j=0;j<numplayers;j++)
        {
            players[j].addCardtoHand(cards.deal());
        }
    }
    
}
void Game::holdemgame()
{
    holdemrepart();
    round();
}
void Game::round()
{
    bet=20;
    pot=0;
    table();
    betstaking();
    
    if (oneLeft())
    {
        winner = getWinner();
        cout << players[winner].getName() << " wins $" << pot << endl << endl;
        turns++;
        return;
    }
    
    /* flop */
    flop();
    cout << endl;
    betstaking();
    if (oneLeft()){
        winner = getWinner();
        cout << players[winner].getName() << " wins $" << pot << endl << endl;
        turns++;
        return;
    }
    
    /* turn */
    turn();
    cout << endl;
    betstaking();
    if (oneLeft()){
        winner = getWinner();
        cout << players[winner].getName() << " wins $" << pot << endl << endl;
        turns++;
        return;
    }
    
    /* river */
    river();
    cout << endl;
    betstaking();
    evaluateHands();

    /*find and declare round winner*/
    maxPoints = 0;
    for (int l=0;l<6;l++){
        if(players[l].round){
            if (handPoints[l]>maxPoints){
                maxPoints = handPoints[l];
                roundWinner = l;
            }
        }
    }
    cout << endl;
    cout << players[roundWinner].getName() << " wins $" << pot << " with ";
    if (maxPoints<30)       cout << "HIGH CARD";
    else if (maxPoints<50)  cout << "SINGLE PAIR";
    else if (maxPoints<70)  cout << "TWO PAIRS";
    else if (maxPoints<90)  cout << "THREE OF A KIND";
    else if(maxPoints<110)  cout << "STRAIGHT";
    else if(maxPoints<130)  cout << "FLUSH";
    else if(maxPoints<150)  cout << "FULL HOUSE";
    else if(maxPoints<170)  cout << "FOUR OF A KIND";
    else                    cout << "STRAIGHT FLUSH";
    cout << endl << endl;
    
    WinningHand(roundWinner);
    players[roundWinner].setchips(players[roundWinner].getchips()+pot);
    turns++;
}
int  Game::computer(int game,int player)
{
    switch (game) {
        case 1:
            return pokerComputer(player);
            break;
    }
    return -1;
    
}
int Game::pokerComputer(int player)
{
    Hand* temp=players[player].GetHand();
    if (temp->getCardAtIndex(0)->getRank() < 8 && temp->getCardAtIndex(1)->getRank() < 8){
        if (temp->getCardAtIndex(0)->getRank()!=temp->getCardAtIndex(1)->getRank())
            return 0;
        else
            return 1;
    }
    if (temp->getCardAtIndex(0)->getRank() < 10 && temp->getCardAtIndex(1)->getRank() < 10){
        if (temp->getCardAtIndex(0)->getRank()!=temp->getCardAtIndex(1)->getRank())
            return 1;
        else
            return 2;
    }
    else{
        return 2;
    }
}


void Game::betstaking()
{
    bet_on = 0;
    for (int k=0;k<6;k++)
        players[k].goodtogo = 0;
    
    for (int k=1;k<7;k++)
    {
        
        /* human actions */
        if (k%6==3 &&players[3].round){
            if (bet_on)
            {
                cout << "Your action: (1) FLOP (3) BET/CALL ";
                cin >> action;
                while (action!=1&&action!=3){
                    cout << "Invalid number pressed." << endl;
                    cout << "Your action: (1) FLOP (3) BET/CALL ";
                    cin >> action;
                }
            }
            else{
                cout << "Your action: (1) FLOP (2) CHECK (3) BET/CALL ";
                cin >> action;
                while (action<1||action>3){
                    cout << "Invalid number pressed." << endl;
                    cout << "Your action: (1) FLOP (2) CHECK (3) BET/CALL ";
                    cin >> action;
                }
            }
            cout << endl;
            
            if (action==1)
                players[3].round = 0;
            else if(action==2)
                continue;
            else{
                if (bet_on){
                    pot+=bet_on;
                    players[3].setchips(players[3].getchips()-bet_on);
                    players[3].goodtogo = 1;
                }
                else{
                    cout << "How much do you want to bet: ";
                    cin >> bet;
                    while (bet>players[3].getchips()||bet<1){
                        cout << "Invalid number to bet." << endl;
                        cout << "How much do you want to bet: ";
                        cin >> bet;
                        cout << endl << endl;
                    }
                    pot+=bet;
                    players[3].setchips(players[3].getchips()-bet);
                    bet_on = bet;
                    players[3].goodtogo = 1;
                }
            }
        }
        /* computers actions */
        else{
            if(players[k%6].lose==true)
                break;
            if (players[k%6].round==0)
                continue;
            
            rational = rand() % 2;
            if (rational){
                action = pokerComputer(k%6);
            }
            else{
                action = rand() % 3;
            }
            if (action==0){
                players[k%6].round=0;
                cout << players[k%6].getName() << " flops..." << endl << endl;
            }
            else if (action==1&&bet_on==0){
                cout << players[k%6].getName() << " checks." << endl << endl;
                continue;
            }
            else{
                if (bet_on){
                    pot+=bet_on;
                    players[k%6].setchips(players[k%6].getchips()-bet_on);
                    cout << players[k%6].getName() << " calls!" << endl << endl;
                    players[k%6].goodtogo
                    = 1;
                }
                else{
                    bet = (rand() % (players[k%6].getchips() / 3) + 10);
                    pot+=bet;
                    players[k%6].setchips(players[k%6].getchips()- bet);
                    cout << '\a';
                    cout << players[k%6].getName() << " bets " << bet << endl << endl;
                    bet_on = bet;
                    players[k%6].goodtogo = 1;
                }
            }
            //sleep(1);
        }
    }
    
    if (bet_on&&playerstobet()){
        for (int k=1;k<7;k++){
            if (k%6==4){
                if (players[4].round&&players[4].goodtogo==0){
                    cout << "Your action: (1) FLOP (3) BET/CALL ";
                    cin >> action;
                    while (action!=1&&action!=3){
                        cout << "Invalid number pressed." << endl;
                        cout << "Your action: (1) FLOP (3) BET/CALL ";
                        cin >> action;
                        cout << endl << endl;
                    }
                    if (action==1)
                        players[4].round = 0;
                    else{
                        
                        pot+=bet_on;
                        players[4].setchips(players[4].getchips()-bet_on);
                        players[4].goodtogo = 1;
                    }
                }
            }
            else{
                if (players[k%6].round==0||players[k%6].goodtogo==1)
                    continue;
                action = rand() % 2;
                if (action==0){
                    players[k%6].round=0;
                    cout << players[k%6].getName() << " flops..." << endl << endl;
                }
                else{
                    pot+=bet_on;
                    players[k%6].setchips(players[k%6].getchips()-bet_on);
                    cout << players[k%6].getName() << " calls!" << endl << endl;
                    players[k%6].goodtogo = 1;
                }
            }
        }
    }
}
void Game::clean_up()
{
    for(int i=0;i<5;i++)
    {
        if(cardstab[i]!=nullptr)
        {
            cards.ReturnCard(cardstab[i]);
            cardstab[i]=nullptr;
        }
    }
    for (int i=0;i<2;i++)
    {
        for (int j=0;j<numplayers;j++)
        {
            if(players[j].isplaying())
            {
                cards.ReturnCard(players[j].removeCard(1-i));
            }
        }
    }
    cards.shuffle();
}
bool Game::playerstobet(){
    for (int i = 0;i<6;i++)
        if (players[i].round==1&&players[i].goodtogo==0)
            return 1;
    
    return 0;
}
void Game::flop()
{
    for(int i=0;i<3;i++)
    {
        cardstab[i]=cards.deal();
    }
    table();
}
void Game::turn()
{
    cardstab[3] = cards.deal();
    table();
}
void Game::river()
{
    cardstab[4]=cards.deal();
    table();
}
int Game::oneLeft(){
    int count = 0;
    for (int k=0;k<6;k++)
        if (players[k].round)
            count++;
    if (count==1)
        return 1;
    else
        return 0;
}
int Game::getWinner(){
    int winner = 0;
    for (int k=0;k<6;k++)
        if (players[k].round)
            winner = k;
    return winner;
}
int Game::Score(Card hand[]){
    int straight,flush,three,four,full,pairs,high;
    int k;
    
    straight = flush = three = four = full = pairs = high = 0;
    k = 0;
    
    /*checks for flush*/
    while (k<4&&hand[k].getSuit()==hand[k+1].getSuit())
        k++;
    if (k==4)
        flush = 1;
    
    /* checks for straight*/
    k=0;
    while (k<4&&hand[k].getRank()==hand[k+1].getRank()-1)
        k++;
    if (k==4)
        straight = 1;
    
    /* checks for fours */
    for (int i=0;i<2;i++){
        k = i;
        while (k<i+3&&hand[k].getRank()==hand[k+1].getRank())
            k++;
        if (k==i+3){
            four = 1;
            high = hand[i].getRank();
        }
    }
    
    /*checks for threes and fullhouse*/
    if (!four){
        for (int i=0;i<3;i++){
            k = i;
            while (k<i+2&&hand[k].getRank()==hand[k+1].getRank())
                k++;
            if (k==i+2){
                three = 1;
                high=hand[i].getRank();
                if (i==0){
                    if (hand[3].getRank()==hand[4].getRank())
                        full=1;
                }
                else if(i==1){
                    if (hand[0].getRank()==hand[4].getRank())
                        full=1;
                }
                else{
                    if (hand[0].getRank()==hand[1].getRank())
                        full=1;
                }
            }
        }
    }
    
    if (straight&&flush)return 170 + hand[4].getRank();
    else if(four)       return 150 + high;
    else if(full)       return 130 + high;
    else if(flush)      return 110;
    else if(straight)   return 90 + hand[4].getRank();
    else if(three)      return 70 + high;
    
    /* checks for pairs*/
    for (k=0;k<4;k++)
        if (hand[k].getRank()==hand[k+1].getRank()){
            pairs++;
            if (hand[k].getRank()>high)
                high = hand[k].getRank();
        }
    if (pairs==2)   return 50 + high;
    else if(pairs)  return 30 + high;
    else            return hand[4].getRank();
}
int Game::tryHand(int array[],int player){
    Card hand[5];
    
    /* get cards from table and player */
    for (int i=1;i<4;i++)
        hand[i-1] = *cardstab[array[i]];
    Hand temp=*players[player].GetHand();
    for (int i=0;i<2;i++)
        hand[i+3] = *temp.getCardAtIndex(i);
    
    return Score(hand);
    
}
void Game::evaluateHands(){
    int stack[10],k;
    int currentPoints;
    
    for (int q=0;q<6;q++){
        if (players[q].round){
            stack[0]=-1; /* -1 is not considered as part of the set */
            k = 0;
            while(1){
                if (stack[k]<4){
                    stack[k+1] = stack[k] + 1;
                    k++;
                }
                
                else{
                    stack[k-1]++;
                    k--;
                }
                
                if (k==0)
                    break;
                
                if (k==3){
                    currentPoints = tryHand(stack,q);
                    
                    if (currentPoints>handPoints[q]){
                        handPoints[q] = currentPoints;
                        for (int x=0;x<3;x++)
                            bestHand[q][x] = stack[x+1];
                    }
                }
            }
        }
    }
}
void Game::WinningHand(int winner){
    Card winningHand[5];
    for (int i=0;i<3;i++)
        winningHand[i] = *cardstab[bestHand[winner][i]];
    Hand *temp= players[winner].GetHand();
    for (int i=0;i<2;i++)
        winningHand[i+3] = *temp->getCardAtIndex(i);
    
    cout << "   The winning hand:" << endl;
    cout << "   ___   ___   ___   ___   ___" << endl;
    cout << "  | " << winningHand[0].getRankAsString() << " | | " << winningHand[1].getRankAsString() << " | | " << winningHand[2].getRankAsString() << " | | " << winningHand[3].getRankAsString() << " | | " << winningHand[4].getRankAsString() << " |" << endl;
    cout << "  | " << winningHand[0].getSuitAsString() << " | | " << winningHand[1].getSuitAsString() << " | | " << winningHand[2].getSuitAsString() << " | | " << winningHand[3].getSuitAsString() << " | | " << winningHand[4].getSuitAsString() << " |" << endl;
    cout << "  |___| |___| |___| |___| |___|" << endl;
    cout << endl << endl;
    //sleep(3);
}
void Game::deactivateplayer()
{
    for(int i=0;i<6;i++)
    {
        if(players[i].getchips()==0)
            players[i].lose=true;
    }
}
