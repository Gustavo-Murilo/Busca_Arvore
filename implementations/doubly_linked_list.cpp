#include "doubly_linked_list.h"
#include <cstdlib>

// TODO: implementar funções
DoublyLinkedList* createList() {
    DoublyLinkedList* ptrList = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    ptrList->ptrHead = nullptr;
    ptrList->ptrTail = nullptr;
    return ptrList;
}