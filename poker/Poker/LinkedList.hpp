//
//  LinkedList.hpp
//  BlackJack
//
//  Created by Joshua McSorley on 11/9/15.
//  Copyright © 2015 Joshua McSorley. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp
#include "Card.hpp"
#include "Node.hpp"
#include <iosfwd>

class LinkedList
{
private:
    //NODE
    //Card* data;
    //Node* next;
    Node* head;
    Node* tail;
    int size;
public:
    LinkedList();
    LinkedList(LinkedList& otherList);
    ~LinkedList();
    
    Card* getHead() ;
    Card* getTail() ;
    Card* getAtIndex(int);
    int getSize();
    
    void Insert(Card* data);
    void insertAtHead(Card* data);
    void insertAtTail(Card* data);
    bool insertAtIndex(Card* data, int index);
    
    Card* removeAtHead();
    Card* removeAtTail();
    Card* removeAtIndex(int);
    Card* remove(Card* data);
    
    bool constrains(Card* data);
    int search(Card* data);
    bool isEmpty();
    
    const Card& operator[](int index);
    friend ostream& operator<<(ostream&,LinkedList&);
    LinkedList& operator=(const LinkedList& otherList);
};

#endif /* LinkedList_hpp */
