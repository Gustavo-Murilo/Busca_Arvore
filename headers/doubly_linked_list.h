#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "tree.h"

struct DoublyLinkedList {
    Node* ptrHead;
    Node* ptrTail;
};

DoublyLinkedList* createList();
DoublyLinkedList* createListByArray(int[], int);
void destroyList(DoublyLinkedList*);
void insertBack(DoublyLinkedList*, int);
int deleteFront(DoublyLinkedList*);
bool isEmpty(DoublyLinkedList*);
void printList(DoublyLinkedList*);
Node* searchList(DoublyLinkedList*, int);

#endif // DOUBLY_LINKED_LIST_H
