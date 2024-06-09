#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "tree.h"

struct DoublyLinkedList {
    Node* ptrHead;
    Node* ptrTail;
};

DoublyLinkedList* createList();
void destroyList(DoublyLinkedList* ptrList);
void insertBack(DoublyLinkedList* ptrList, int iPayload);
int deleteFront(DoublyLinkedList* ptrList);
bool isEmpty(DoublyLinkedList* ptrList);

#endif // DOUBLY_LINKED_LIST_H
