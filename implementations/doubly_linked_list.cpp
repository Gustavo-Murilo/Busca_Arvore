#include "doubly_linked_list.h"
#include <cstdlib>

// TODO: implementar funções
DoublyLinkedList* createList() {
    DoublyLinkedList* ptrList = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    ptrList->ptrHead = nullptr;
    ptrList->ptrTail = nullptr;
    return ptrList;
}

void destroyList(DoublyLinkedList* ptrList) {
    Node* ptrCurrent = ptrList->ptrHead;
    while (ptrCurrent != nullptr) {
        Node* ptrRight = ptrCurrent->ptrRight;
        free(ptrCurrent);
        ptrCurrent = ptrRight;
    }
    free(ptrList);
}

void insertBack(DoublyLinkedList* ptrList, int iPayload) {
    Node* ptrNewNode = (Node*)malloc(sizeof(Node));
    ptrNewNode->iPayload = iPayload;
    ptrNewNode->ptrRight = nullptr;
    ptrNewNode->ptrLeft = ptrList->ptrTail;
    
    if (ptrList->ptrTail != nullptr) {
        ptrList->ptrTail->ptrRight = ptrNewNode;
    } else {
        ptrList->ptrHead = ptrNewNode;
    }
    
    ptrList->ptrTail = ptrNewNode;
}