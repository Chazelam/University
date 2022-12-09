#include <stdio.h>
#include <stdlib.h>
#define bool int

struct Stack{
  Node *top;
  struct Stack *next;
}Stack;

void push(struct Stack** top_ref, Node *top);
Node *pop(struct Stack** top_ref);
bool isEmpty(struct Stack *top);
 
void push(struct Stack** top_ref, Node *top){
  struct Stack* new_tNode = (struct Stack*) malloc(sizeof(struct Stack));
  if(new_tNode == NULL){
     printf("Stack Overflow \n");
     getchar();
     exit(0);
  }           

  new_tNode->top  = top;
  new_tNode->next = (*top_ref);
  (*top_ref)    = new_tNode;
}
 
bool isEmpty(struct Stack *top){
   return (top == NULL)? 1 : 0;
}

Node *pop(struct Stack** top_ref){
  Node *res;
  struct Stack *top;
  if(isEmpty(*top_ref)){
     printf("Stack Underflow \n");
     getchar();
     exit(0);
  }
  else{
     top = *top_ref;
     res = top->top;
     *top_ref = top->next;
     free(top);
     return res;
  }
}