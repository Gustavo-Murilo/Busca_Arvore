#include "../headers/tree.h"
#include <iostream>

Node* createNode(int iValue)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    
    if (temp == nullptr)
    {
        std::cerr << "Erro em createNode: malloc" << std::endl;
        exit(1);
    }
    
    temp->iPayload = iValue;
    temp->ptrLeft = nullptr;
    temp->ptrRight = nullptr;
    
    return temp;
}

Node* insertNode(Node* startingNode, int iData)
{
    if(startingNode == nullptr)
    {
        return createNode(iData);
    }
    
    if(iData < startingNode->iPayload)
    {
        startingNode->ptrLeft = insertNode(startingNode->ptrLeft, iData);
    }
    else
    {
        startingNode->ptrRight = insertNode(startingNode->ptrRight, iData);
    }
    
    return startingNode;
}

void destroyTree(Node* startingNode)
{
    if(startingNode == nullptr)
    {
        return;
    }
    
    destroyTree(startingNode->ptrLeft);
    destroyTree(startingNode->ptrRight);
    
    free(startingNode);
}

Node* deleteNode(Node* startingNode, int iData)
{
    if (startingNode == nullptr) return nullptr;
    
    if (iData < startingNode->iPayload) startingNode->ptrLeft = deleteNode(startingNode->ptrLeft, iData);
    else if (iData > startingNode->iPayload) startingNode->ptrRight = deleteNode(startingNode->ptrRight, iData);
    else
    {
        Node* ptrTemp = nullptr;
        
        if (startingNode->ptrLeft == nullptr)
        {
            ptrTemp = startingNode->ptrRight;
            free(startingNode);
            return ptrTemp;
        }
        else if (startingNode->ptrRight == nullptr)
        {
            ptrTemp = startingNode->ptrLeft;
            free(startingNode);
            return ptrTemp;            
        }
        
        ptrTemp = lesserLeaf(startingNode->ptrRight);
        
        startingNode->iPayload = ptrTemp->iPayload;
        
        startingNode->ptrRight = deleteNode(startingNode->ptrRight, ptrTemp->iPayload);
    }
    
    return startingNode;
}

Node* lesserLeaf(Node* startingNode)
{
    Node* ptrCurrent = startingNode;
 
    while (ptrCurrent && ptrCurrent->ptrLeft != nullptr) ptrCurrent = ptrCurrent->ptrLeft;
    
    return ptrCurrent;
}

Node* higherLeaf(Node* startingNode)
{
    Node* ptrCurrent = startingNode;
 
    while (ptrCurrent && ptrCurrent->ptrRight != nullptr) ptrCurrent = ptrCurrent->ptrRight;
    
    return ptrCurrent;
}