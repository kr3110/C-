//
//  Node.hpp
//  BlackJack
//
//  Created by Joshua McSorley on 11/9/15.
//  Copyright © 2015 Joshua McSorley. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include "Card.hpp"

class Node
{
private:
    Card* data;
    Node* next;
public:
    Node();
    Node(Card*);
    Node(Card*, Node*);
    
    void setData(Card*);
    void setNext(Node*);
    
    Card* getData();
    Node* getNext();
};

#endif /* Node_hpp */
