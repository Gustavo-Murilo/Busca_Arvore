#ifndef TREE_H
#define TREE_H

typedef struct Node
{
    int iPayload;
    Node* ptrLeft = nullptr;
    Node* ptrRight = nullptr;
} Node;

Node* createNode(int);
Node* insertNode(Node*, int);
void deleteTree(Node*);
void deleteNode(Node*);
Node* lesserLeaf(Node*);
Node* higherLeaf(Node*);

#endif // TREE_H