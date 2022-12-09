#include <stdio.h>
#include <stdlib.h>

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