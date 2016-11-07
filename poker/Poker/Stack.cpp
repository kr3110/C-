//
//  Stack.cpp
//  Poker
//
//  Created by Kevin Reinoso on 11/18/15.
//  Copyright © 2015 kr3110. All rights reserved.
//
#include "Stack.hpp"
#include "Card.hpp"
#include <iostream>
using namespace std;

//Constructor
Stack::Stack()
{
    stack = new Card*[52];
    capacity = 52;
    size = 0;
}
Stack::Stack(int c)
{
    stack = new Card*[c];
    capacity = c;
    size = 0;
}
//Mutator
void Stack::setSize(int s)  {size = s;}
//Accessor
int Stack::getSize()        {return size;}
//Stack
bool Stack::isEmpty()       {return size == 0;}
bool Stack::isFull()        {return size == capacity;}
Card* Stack::peek()//Check
{
    if (!isEmpty())
    {
        return stack[size-1];
    }
    else
    {
        return NULL;
    }
}
Card* Stack::pop()
{
    if (!isEmpty())
    {
        return stack[--size];
        
    }
    else
    {
        
        return NULL;
    }
}
void Stack::push(Card* c)
{
    if (!isFull())
    {
        stack[size] = c;
        size++;
        
    }
    else
    {
        cout << "Stack is full!" << endl;
    }
}
void Stack::display()
{
    for (int i =0;i<52; i++)
    {
        //display is a card function
        stack[i]->display();
    }
}
const Card* Stack::getStack(){
    return *stack;
}
