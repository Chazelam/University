/*
 1. Построить бинарное дерево одного из типов данных:
  а) строкового;
  б) целочисленного;
  в) вещественного.

 2. Выполнить обход дерева  рекурсивным и нерекурсивным (стековым) способами:
  а) в прямом порядке;
  б) в обратном порядке;
  в) в концевом порядке.

 3. При обходе подсчитать:
  а) количество неконцевых вершин дерева;
  б) количество листьев дерева;
  в) количество вершин, имеющих ровно одну не пустую связь;
  г) количество вершин, имеющих хотя бы одну не пустую связь;
  д) количество вершин, имеющих хотя бы одну пустую связь.
*/

#include "StackBypass.h"
#include "counters.h"

int main(){
    Node *root = createTree();
    printf("Tree in direct order: ");
    printInDirectOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    printf("Tree in reverse order: ");
    printInReverseOrder(root);
    printf("\n");
    printf("Tree in symmetric order: ");
    printtInSymmetricOrder(root);
    printf("\n");
    printf("This tree has %d not end nodes.\n", countNonleaf(root));
    printf("This tree has %d leaves.\n", countLeafs(root));
    // printf("This tree has %d nodes with 1 not empty link.\n", count1Empty(root));
    // printf("This tree has %d nodes with at least 1 not empty link.\n", 0);
    // printf("This tree has %d nodes with at least 1 empty link.\n", 0);
}