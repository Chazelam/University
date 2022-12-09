/* 
Построить в динамической памяти линейный связанный список 
одного из типов данных:
    строкового;
    символьного;
    целочисленного;
    вещественного.
Количество элементов списка заранее неизвестно. 
Список строить в прямом порядке, окончание ввода – введение
условного символа. Символ этот в список не включается.

Выполнить добавления и удаления элемента:
1. В лексикографически упорядоченный список таким образом, чтобы не нарушить его упорядоченность;
2. n-м по порядку (кроме первого и последнего), число n ввести;
3. Перед цифрой 5 (кроме первого и последнего);
4. После буквы “g” (кроме первого и последнего);
5. Предпредпоследнего элемента (в списке больше трех элементов);
6. Предпоследнего элемента (в списке больше двух элементов);
7. Вретьего по порядку (в списке больше трех элементов);
8. Второго по порядку (в списке больше двух элементов);
9. В конце списка;
10. В начале списка;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
    int value;
    struct _node *next;
}Node;

void printList(Node *head){
    while(head){
        printf("%d", head -> value);
        head = head -> next;
    }
    printf("\n");
}

void create(Node *head, int data){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp -> value = data;
    head -> next = temp;
    temp -> next = NULL;
    head = head -> next;
}

Node* getLast(Node *head){
    if (head == NULL)
        return NULL;
    while (head -> next)
        head = head -> next;
    return head;
}

void addInEnd(Node *head, int value){
    Node *last = getLast(head);
    Node *temp = (Node*)malloc(sizeof(Node));
    temp -> value = value;
    temp -> next = NULL;
    last ->next = temp;
}

int main(){
    int data;
    scanf("%d", &data);
    Node *head = (Node*)malloc(sizeof(Node));
    head -> value = data;
    head -> next = NULL;
    while(1){
        scanf("%d", &data);
        addInEnd(head, data);
        printList(head);
    }
}