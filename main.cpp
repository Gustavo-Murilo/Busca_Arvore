#include "headers/tree.h"
#include "headers/search_tree.h"
#include "headers/doubly_linked_list.h"
#include "headers/time_measure.h"

#include <iostream>
using namespace std;

int main()
{
    // Preenchimento da árvore e da lista
    int iSize = 10000;
    int arriValues[iSize];
    for (int i = 0; i < iSize; i++)
    {
        arriValues[i] = i+1;
    }

    // Criação da árvore binária de busca e da lista duplamente encadeada
    Node* root = nullptr;
    DoublyLinkedList* list = nullptr;
    
    // Medição de tempo de criação da árvore e da lista
    double timeCreateTree = measureExecutionTime([&]() 
    { root = createTreeByArray(arriValues, iSize); } );
    
    double timeCreateList = measureExecutionTime([&]() 
    { list = createListByArray(arriValues, iSize); } );

    // Medição de tempo de busca
    double timeSearchDFS = measureExecutionTime([&]() 
    { for (int i = 0; i < iSize; i++) { searchDFS(root, i); } });

    double timeSearchBFS = measureExecutionTime([&]() 
    { for (int i = 0; i < iSize; i++) { searchBFS(root, i); } });

    double timeSearchList = measureExecutionTime([&]() 
    { for (int i = 0; i < iSize; i++) { searchList(list, i); } });


    cout << "Tempo médio de criação da árvore: " << timeCreateTree << " microssegundos" << endl;
    cout << "Tempo médio de criação da lista: " << timeCreateList << " microssegundos" << endl;
    cout << endl;
    cout << "Tempo médio de busca em profundidade: " << timeSearchDFS/iSize << " microssegundos" << endl;
    cout << "Tempo médio de busca em largura: " << timeSearchBFS/iSize << " microssegundos" << endl;    
    cout << "Tempo médio de busca na lista: " << timeSearchList/iSize << " microssegundos" << endl;

    // Limpeza de memória
    destroyTree(root);
    destroyList(list);

    return 0;
}