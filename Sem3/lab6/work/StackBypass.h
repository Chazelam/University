#include <stdio.h>
#include <stdlib.h>
#include "binarytrees.h"
#define bool int
 
/* Structure of a stack node. Linked List implementation is used for
   stack. A stack node contains a pointer to tree node and a pointer to
   next stack node */
struct Stack
{
  Node *top;
  struct Stack *next;
}Stack;
 
/* Stack related functions */
void push(struct Stack** top_ref, Node *top);
Node *pop(struct Stack** top_ref);
bool isEmpty(struct Stack *top);
 
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
 
/* UTILITY FUNCTIONS */
/* Function to push an item to Stack*/
void push(struct Stack** top_ref, Node *top)
{
  /* allocate Node */
  struct Stack* new_tNode =
            (struct Stack*) malloc(sizeof(struct Stack));
 
  if(new_tNode == NULL)
  {
     printf("Stack Overflow \n");
     getchar();
     exit(0);
  }           
 
  /* put in the top  */
  new_tNode->top  = top;
 
  /* link the old list of the new Node */
  new_tNode->next = (*top_ref);  
 
  /* move the head to point to the new Node */
  (*top_ref)    = new_tNode;
}
 
/* The function returns true if stack is empty, otherwise false */
bool isEmpty(struct Stack *top)
{
   return (top == NULL)? 1 : 0;
}  
 
/* Function to pop an item from stack*/
Node *pop(struct Stack** top_ref)
{
  Node *res;
  struct Stack *top;
 
  /*If Stack is empty then error */
  if(isEmpty(*top_ref))
  {
     printf("Stack Underflow \n");
     getchar();
     exit(0);
  }
  else
  {
     top = *top_ref;
     res = top->top;
     *top_ref = top->next;
     free(top);
     return res;
  }
}