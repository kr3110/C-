//
//  Node.cpp
//  BlackJack
//
//  Created by Joshua McSorley on 11/9/15.
//  Copyright © 2015 Joshua McSorley. All rights reserved.
//

#include "Node.hpp"

Node::Node():                 data(nullptr), next(nullptr){}
Node::Node(Card* c):          data(c),       next(nullptr){}
Node::Node(Card* c, Node* n): data(c),       next(n)      {}

void Node::setData(Card* c)   {data = c;}
void Node::setNext(Node* n)   {next = n;}

Card* Node::getData()         {return data;}
Node* Node::getNext()         {return next;}