//
//  stack.cpp
//  Poker
//
//  Created by Kevin Reinoso on 11/18/15.
//  Copyright © 2015 kr3110. All rights reserved.
//

#ifndef STACK_H
#define STACK_H
#include "Card.hpp"

class Stack
{
private:
	Card** stack;
	int capacity;
	int size;
public:
    Stack();
    Stack(int c);
	int getSize();
	void setSize (int s);
	//No accessor or modifier for stack as only access
	//should be through peek, pop, and push
public:
	Card* peek();
	Card* pop();
	void push(Card* c);
    void display();
    
	bool isEmpty();
    bool isFull();
    const Card* getStack();
};

#endif