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
    printInDirectOrder(root -> left);
    printInDirectOrder(root -> right);
}
void printInReverseOrder(Node *root){
    if (root == NULL)
        return;
    printInReverseOrder(root -> left);
    printInReverseOrder(root -> right);
    if (root -> value)
        printf("%d ", root -> value);
}
void printtInSymmetricOrder(Node *root){
    if (root == NULL)
        return;
    printtInSymmetricOrder(root -> left);
    if (root -> value)
        printf("%d ", root -> value);
    printtInSymmetricOrder(root -> right);
}

int countLeafs(Node *root){
    int counter;
    if (root==NULL)
        counter = 0;
    else if ((root->left==NULL)&&(root->right==NULL))
        counter =  1;
    else
        counter = countLeafs(root->left) + countLeafs(root->right);
    return counter;
}
int countNotEnd(Node *root){
    int counter = 0;
    if ((root == NULL) || ((root ->left == NULL) && (root->right == 0)))
        counter = 0;
    else if ((root -> left != NULL) || (root -> right != NULL))
        counter  = 1;
    else
        counter = countNotEnd(root -> left) + countNotEnd(root -> right);
    return counter;
}

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
    printf("This tree has %d leaves.\n", countLeafs(root));
    printf("This tree has %d not end .\n", countNotEnd(root));
    
}