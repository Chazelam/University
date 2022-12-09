#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int maxsize;    //максимальная емкость stack
    int top;
    int *items;
}Stack;
 
// Создание Stack
struct stack* createStack(int capacity){
    Stack *head = (Stack*)malloc(sizeof(Stack));
    head -> maxsize = capacity;
    head -> top = -1;
    head -> items = (int*)malloc(sizeof(int) * capacity);
    return head;
}
 
// Вспомогательная функция для возврата размера Stack
int size(Stack *head){
    return head -> top + 1;
}
 
// Вспомогательная функция для проверки, пуст stack или нет
int isEmtempy(Stack *head) {
    return head -> top == -1;                   // или return size(head) == 0;
}
 
// Вспомогательная функция для проверки, заполнен ли stack или нет
int isFull(Stack *head) {
    return head->top == head->maxsize - 1;      // or return size(head) == head->maxsize;
}
 
// Добавлений элемента x в Stack
void push(Stack *head, int x){
    // проверяем, не заполнен ли уже stack.
    if (isFull(head)){
        printf("Overflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }
    printf("Inserting %d\n", x);
    // добавляем элемент и увеличиваем индекс вершины
    head -> items[++head -> top] = x;
}
 
// Вспомогательная функция для возврата верхнего элемента stack
int peek(Stack *head){
    // проверка на пустой stack
    if (!isEmtempy(head))
        return head -> items[head -> top];
    else 
        exit(EXIT_FAILURE);
}
 
// Вспомогательная функция для извлечения верхнего элемента из stack
int pop(Stack *head){
    // проверка на опустошение stack
    if (isEmtempy(head))
    {
        printf("Underflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }
 
    printf("Removing %d\n", peek(head));
 
    // уменьшаем размер stack на 1 и (необязательно) возвращаем извлеченный элемент
    return head -> items[head -> top--];
}