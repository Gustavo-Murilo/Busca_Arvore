#ifndef TREE_H
#define TREE_H

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

typedef struct Node
{
    int iPayload;
    Node* ptrLeft = nullptr;
    Node* ptrRight = nullptr;
} Node;

Node* createNode(int);
Node* createTreeByArray();
Node* insertNode(Node*, int);
void deleteTree(Node*);
void deleteNode(Node*);
Node* lesserLeaf(Node*);
Node* higherLeaf(Node*);
void printTree(Node*);

#endif // TREE_H