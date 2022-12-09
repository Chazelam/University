#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int value;
    struct tree *left;
    struct tree *right;
    struct tree *parent;
}Node;

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