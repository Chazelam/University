#include "binarytrees.h"
#include "stack.h"

void inOrder(Node *root){
  /* set current to root of binary tree */
  Node *current = root;
  struct Stack *s = NULL;  /* Initialize stack s */
  bool done = 0;
 
  while (!done){
    /* Reach the left most Node of the current Node */
    if(current !=  NULL)
    {
      /* place pointer to a tree node on the stack before traversing
        the node's left subtree */
      push(&s, current);                                              
      current = current->left; 
    }
        
    /* backtrack from the empty subtree and visit the Node
       at the top of the stack; however, if the stack is empty,
      you are done */
    else                                                             
    {
      if (!isEmpty(s))
      {
        current = pop(&s);
        printf("%d ", current -> value);
 
        /* we have visited the node and its left subtree.
          Now, it's right subtree's turn */
        current = current -> right;
      }
      else
        done = 1;
    }
  } /* end of while */ 
}    