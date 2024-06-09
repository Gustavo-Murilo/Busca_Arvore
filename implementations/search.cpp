#include "../headers/search.h"
#include "../headers/doubly_linked_list.h"

// TODO: implementar funções

Node* searchDFS(Node* startingNode, int iValue)
{
    if(startingNode == nullptr) return nullptr;
    else if(iValue == startingNode->iPayload) return startingNode;
    else if(iValue < startingNode->iPayload) return searchDFS(startingNode->ptrLeft, iValue);
    else return searchDFS(startingNode->ptrRight, iValue);
}

Node* searchBFS(Node* startingNode, int iValue)
{
    return nullptr;
}