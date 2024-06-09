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