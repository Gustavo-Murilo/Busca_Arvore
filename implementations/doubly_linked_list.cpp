#include "../headers/doubly_linked_list.h"
#include <cstdlib>

// Cria uma nova lista duplamente encadeada vazia.
DoublyLinkedList* createList() {
    DoublyLinkedList* ptrList = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    ptrList->ptrHead = nullptr; // Inicializa a cabeça da lista como nullptr
    ptrList->ptrTail = nullptr; // Inicializa a cauda da lista como nullptr.
    return ptrList; // Retorna o ponteiro para a nova lista.
}

// Cria uma lista duplamente encadeada a partir de um array de inteiros.
DoublyLinkedList* createListByArray(int iArr[], int iSize) {
    DoublyLinkedList* ptrList = createList(); // Cria uma lista vazia.
    for (int i = 0; i < iSize; i++) {
        insertBack(ptrList, iArr[i]); // Insere cada elemento do array na lista.
    }
    return ptrList; // Retorna a lista preenchida.
}

// Destrói a lista duplamente encadeada liberando todos os nós e a própria lista.
void destroyList(DoublyLinkedList* ptrList) {
    Node* ptrCurrent = ptrList->ptrHead; // Inicia com o primeiro nó.
    while (ptrCurrent != nullptr) {
        Node* ptrRight = ptrCurrent->ptrRight; // Guarda o próximo nó.
        free(ptrCurrent); // Libera o nó atual.
        ptrCurrent = ptrRight; // Move para o próximo nó.
    }
    free(ptrList); // Libera o ponteiro para a lista.
}

// Insere um novo nó com o valor especificado no final da lista.
void insertBack(DoublyLinkedList* ptrList, int iPayload) {
    Node* ptrNewNode = (Node*)malloc(sizeof(Node)); // Aloca um novo nó.
    ptrNewNode->iPayload = iPayload; // Define o valor do nó.
    ptrNewNode->ptrRight = nullptr; // O próximo nó é nullptr.
    ptrNewNode->ptrLeft = ptrList->ptrTail; // O nó anterior é a cauda atual.
    
    if (ptrList->ptrTail != nullptr) {
        ptrList->ptrTail->ptrRight = ptrNewNode; // Liga a cauda atual ao novo nó.
    } else {
        ptrList->ptrHead = ptrNewNode; // Se a lista estava vazia, define como cabeça.
    }
    
    ptrList->ptrTail = ptrNewNode; // Atualiza a cauda da lista.
}

// Remove o primeiro nó da lista e retorna seu ponteiro.
Node* deleteFront(DoublyLinkedList* ptrList) {
    if (isEmpty(ptrList)) return nullptr;  // Retorna nullptr se a lista estiver vazia
    Node* ptrTemp = ptrList->ptrHead; // Guarda o nó a ser removido.
    ptrList->ptrHead = ptrList->ptrHead->ptrRight; // Atualiza a cabeça da lista.
    
    if (ptrList->ptrHead != nullptr) {
        ptrList->ptrHead->ptrLeft = nullptr; // Remove a ligação para o nó antigo.
    } else {
        ptrList->ptrTail = nullptr; // Se a lista ficou vazia, atualiza a cauda também.
    }
    
    return ptrTemp; // Retorna o nó removido.
}

// Verifica se a lista está vazia.
bool isEmpty(DoublyLinkedList* ptrList) {
    return ptrList->ptrHead == nullptr; // Retorna true se a cabeça é nullptr.
}

// Imprime todos os elementos da lista.
void printList(DoublyLinkedList* ptrList) {
    Node* ptrCurrent = ptrList->ptrHead; // Inicia pelo primeiro nó.
    while (ptrCurrent != nullptr) {
        cout << ptrCurrent->iPayload << endl; // Imprime o valor do nó.
        ptrCurrent = ptrCurrent->ptrRight; // Move para o próximo nó.
    }
    cout << endl;
}

// Busca um valor na lista e retorna o nó se encontrado.
Node* searchList(DoublyLinkedList* ptrList, int iValue) {
    Node* ptrCurrent = ptrList->ptrHead; // Inicia pelo primeiro nó.
    while (ptrCurrent != nullptr) {
        if (ptrCurrent->iPayload == iValue) {
            return ptrCurrent; // Retorna o nó se o valor for encontrado.
        }
        ptrCurrent = ptrCurrent->ptrRight; // Move para o próximo nó.
    }
    return nullptr; // Retorna nullptr se o valor não for encontrado.
}