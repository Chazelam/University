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

#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int value;
    struct tree *left;
    struct tree *right;
    struct tree *parent;
}Node;

typedef struct comp{
    int value;
    struct comp *next;
}Stack;

Node* createRoot(Node *root, int value){
    Node *temp = malloc(sizeof(Node));
    temp -> value = value;
    temp -> right = temp -> left = NULL;
    temp -> parent = NULL;
    root = temp;
    return root;
}
Node* addNode(Node *root, int value){
    if (root == NULL){
        root = createRoot(root, value);
        return root;
    }
    else{
        Node *current = root, *previous = NULL;
        Node *new = malloc(sizeof(Node));
        new -> value = value;
        while(current != NULL){
            previous = current;
            if (value < current -> value)
                current = current -> left;
            else    
                current = current -> right;
        }
        new -> parent = previous;
        new  -> left = new -> right = NULL;
        if (value < previous -> value) 
            previous -> left = new;
        else
            previous -> right = new;
        return root;
    }
}

void printInDirectOrder(Node *root){
    if (root == NULL)
        return;
    if (root -> value)
        printf("%d ", root -> value);
    printInDirectOrder(root -> right);
    printInDirectOrder(root -> left);
}
void printInReverseOrder(Node *root){
    if (root == NULL)
        return;
    printInReverseOrder(root -> left);
    if (root -> value)
        printf("%d ", root -> value);
    printInReverseOrder(root -> right);
}
void printtInSymmetricOrder(Node *root){
    if (root == NULL)
        return;
    printtInSymmetricOrder(root -> left);
    printtInSymmetricOrder(root -> right);
    if (root -> value)
        printf("%d ", root -> value);
}

int countLeafs(Node *root){
    if (root == NULL)
        return 0;
    else if ((root -> left == NULL) && (root -> right == NULL))
        return 1;
    return countLeafs(root -> left) + countLeafs(root -> right);
}
int countNonleaf(Node *root){
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    return 1 + countNonleaf(root->left) + countNonleaf(root->right);
}
// int count1Empty(Node *root){
//     int counter;
//     if (root == NULL)
//         counter = 0;
//     else if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
//         counter = 1;
//     else 
//         return counter + count1Empty(root->left) + count1Empty(root->right);
    
// }


Node* createTree(){
    Node *root = malloc(sizeof(Node));
    root = NULL;
    char input[100];
    while(1){
        printf("New value: ");
        scanf("%s", input);
        if (atoi(input) != 0 || input[0] == '0'){
            root = addNode(root, atoi(input));
            printf("Current tree: ");
            printInDirectOrder(root);
            printf("\n");
        }
        else{
            printf("stop\n");
            break;
        }
    }
    return root;
}

int main(){
    Node *root = createTree();
    printf("Tree in direct order: ");
    printInDirectOrder(root);
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