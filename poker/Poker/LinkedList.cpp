//
//  LinkedList.cpp
//  BlackJack
//
//  Created by Joshua McSorley on 11/9/15.
//  Copyright © 2015 Joshua McSorley. All rights reserved.
//

#include "LinkedList.hpp"
#include "Node.hpp"

LinkedList::LinkedList()
{
    head=nullptr;
    tail=nullptr;
    size=0;
}
LinkedList::LinkedList(LinkedList& otherList)
{
    size=otherList.size;
    Node * x=otherList.head;
    head->setData(x->getData());
    for(int i=0;i<size;i++)
    {
        x=x->getNext();
        insertAtTail(x->getData());
    }
    
}
Card* LinkedList::getHead()     {return head->getData();}
Card* LinkedList::getTail()     {return tail->getData();}
Card* LinkedList::getAtIndex(int iter)
{
    if(iter>size||iter<0)   return NULL;
    else if(iter==0)        return head->getData();
    else if(iter==size-1)   return tail->getData();
    else
    {
        Node* helper = head;
        for(int i=0;i<iter-1;i++){
            helper=helper->getNext();
        }
        return helper->getData();
    }
}

int LinkedList::getSize(){return size;}
void LinkedList::Insert(Card* data)
{
    if(size==0){
        insertAtHead(data);
        tail=head;
    }
    else{
        insertAtTail(data);
    }
 }
void LinkedList::insertAtHead(Card* data)
{
    Node* x=new Node;
    x->setData(data);
    x->setNext(head);
    head= x;
    size++;
}
void LinkedList::insertAtTail(Card* data)
{   Node * x=new Node;
    x->setData(data);
    tail->setNext(x);
    tail=x;
    size++;
}
bool LinkedList::insertAtIndex(Card* data, int index)
{
    Node* helper=head;
    Node* x=new Node;
    x->setData(data);
    for(int i=0; i<index; i++){
        helper=helper->getNext();
    }
    x->setNext(helper->getNext());
    helper->setNext(x);
    if(helper->getNext()==x){
        size++;
        return true;
    }
    else
        return false;
    
}
Card* LinkedList::removeAtHead()
{
    Node* x=head->getNext();
    Card* temp=x->getData();
    delete head;
    head=x;
    size--;
    return temp;
}
Card* LinkedList::removeAtTail()
{  Node* x=head;
    Card* temp=tail->getData();
    for(int i=1; i<size;i++)
    {
        x=x->getNext();
    }
    delete tail;
    tail=x;
    size--;
    return temp;
}
Card* LinkedList::removeAtIndex(int index)
{
    Node* helper;
    Node* x=head;
    for(int i=1; i<index-1;i++){
        x=x->getNext();
    }
    helper=x->getNext();
    x->setNext(x);
    x->setNext(helper->getNext());
    Card* temp=helper->getData();
    delete helper;
    size--;
    return temp;
}
Card* LinkedList::remove(Card* data)
{
    Node* helper=head;
    Node* temp = nullptr;
    bool flag=false;
    for (int i=0;i<size;i++){
        if(helper->getData()==data){
            flag= true;
            temp->setNext(helper->getNext());
            delete helper;
            helper->setNext(temp->getNext());
            break;
        }
        temp=helper;
        helper=helper->getNext();
        
    }
    if(flag==true)      return data;
    else                return NULL;
}
bool LinkedList::constrains(Card* data)
{
    return false;
}
int LinkedList::search(Card* data)
{
    Node* x=head;
    int i=0;
    while (data==x->getData()){
        x=x->getNext();
        i++;
    }
    return i;
}
bool LinkedList::isEmpty()
{
    if(head==NULL)
        return true;
    else
        return false;
}
const Card& LinkedList::operator[](int index)
{
    Node x=*head;
    for(int i=1; i<index;i++){
        x= *(x.getNext());
    }
    return *(x.getData());
}
ostream& operator<<(ostream& out,LinkedList& list )
{
    Node* x=list.head;
    for(int i=0;i<list.size;i++){
        Card* helper=x->getData();
        out<<*helper<<endl;
        x=x->getNext();
    }
    return out;
}
LinkedList& LinkedList::operator=(const LinkedList& otherList)
{
    Node* x=head;
    for(int i=0;i<size;i++){
        Node* helper=x->getNext();
        delete x;
        x=helper;
    }
    
    size=otherList.size;
    x=otherList.head;
    head->setData(x->getData());
    
    for(int i=0;i<size;i++){
        x=x->getNext();
        insertAtTail(x->getData());
    }
    return *this;
}
LinkedList::~LinkedList()
{
    Node* x=head;
    for(int i=0;i<size;i++){
        Node* helper=x->getNext();
        delete x;
        x=helper;
    }
    
}
