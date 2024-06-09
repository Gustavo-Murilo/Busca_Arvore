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

int deleteFront(DoublyLinkedList* ptrList) {
    if (isEmpty(ptrList)) return -1;  // Retorna -1 se a lista estiver vazia
    Node* ptrTemp = ptrList->ptrHead;
    ptrList->ptrHead = ptrList->ptrHead->ptrRight;
    
    if (ptrList->ptrHead != nullptr) {
        ptrList->ptrHead->ptrLeft = nullptr;
    } else {
        ptrList->ptrTail = nullptr;
    }
    
    int iPayload = ptrTemp->iPayload;
    free(ptrTemp);
    return iPayload;
}