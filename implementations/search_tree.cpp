#include "../headers/search_tree.h"
#include "../headers/doubly_linked_list.h"

// TODO: implementar funções

Node* searchDFS(Node* startingNode, int iValue)
{
    if(startingNode == nullptr) return nullptr;
    else if(iValue == startingNode->iPayload) return startingNode;
    else if(iValue < startingNode->iPayload) return searchDFS(startingNode->ptrLeft, iValue);
    else return searchDFS(startingNode->ptrRight, iValue);
}

Node* searchBFS(Node* startingNode, int iValue) {
    if (startingNode == nullptr) return nullptr;

    DoublyLinkedList* ptrQueue = createList();
    insertBack(ptrQueue, startingNode->iPayload);  // Armazenar o ponteiro do nó como inteiro

    while (!isEmpty(ptrQueue)) {
        Node* ptrCurrent = deleteFront(ptrQueue);

        if (ptrCurrent->iPayload == iValue) {
            destroyList(ptrQueue);
            return ptrCurrent;
        }

        if (ptrCurrent->ptrLeft != nullptr) {
            insertBack(ptrQueue, ptrCurrent->ptrLeft->iPayload);
        }

        if (ptrCurrent->ptrRight != nullptr) {
            insertBack(ptrQueue, (int)ptrCurrent->ptrRight->iPayload);
        }
    }

    destroyList(ptrQueue);
    return nullptr;
}