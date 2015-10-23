//
//  DblLinkedList.cpp
//  Program 3
//
//  Created by Kevin Fuerst on 10/21/15.
//  Copyright © 2015 Kevin Fuerst. All rights reserved.
//

#include "DblLinkedList.h"
#include "Point.h"
#include "stdio.h"

using namespace std;

DblLinkedList::DblLinkedList()
{
    current = 0;
    first = 0;
    last = 0;
}

bool DblLinkedList::AtEnd() const
{
    if  (current == 0)
        return true;
    else
        return false;
}
bool DblLinkedList::Empty() const
{
    return (first == 0 && last == 0);
}
void DblLinkedList::Forward()
{
    current = current->succ;
}
void DblLinkedList::Backward()
{
    current = current->pred;
}
NodeData DblLinkedList::CurrentItem()
{
    return current->data;
}
NodeData DblLinkedList::FirstItem()
{
    return first->data;
}
NodeData DblLinkedList::LastItem()
{
    return last->data;
}
void DblLinkedList::InsertItem(const NodeData &d)
{
    
    Node *newNode;
    
    if (Empty())
    {
        cout << "empty" << endl;
        newNode = new(std::nothrow) Node(d,0,0);
        first = newNode;
        last = newNode;
    }
    else if (current->pred == 0 && current->succ != 0)
    {
        cout << "first" << endl;
        newNode = new(std::nothrow) Node(d, 0, first);
        current->pred = newNode;
        first = newNode;
        
    }
    else if (current->succ == 0 && current->pred != 0)
    {
        cout << "last" << endl;
        newNode = new(std::nothrow) Node(d, last);
        last->succ = newNode;
        last = newNode;
        
    }
    else
    {
        cout << "general" << endl;
        newNode = new(std::nothrow) Node(d,current->pred, current);
        //current->pred->succ = newNode;
        current->pred = newNode;
    }
    current = last;
}
void DblLinkedList::DeleteItem()
{
    if (current->pred == 0)
    {
        Node *tempNode;
        tempNode = current ;
        first = current->succ;
        current->succ->pred = 0;
        delete current;
        current = tempNode->succ;
    }
    else if (current->succ == 0)
    {
        current->pred->succ = 0;
        last = current->pred;
        delete current;
        current = 0;
    }
    else if ((current->pred == NULL) && (current->succ == NULL))
    {
        delete current;
    }
    else
    {
        Node *tempNode;
        tempNode = current;
        current->pred->succ = current->succ;
        current->succ->pred = current->pred;
        delete current;
        current = tempNode->succ;
    }
}