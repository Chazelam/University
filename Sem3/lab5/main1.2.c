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
7. Третьего по порядку (в списке больше трех элементов);
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

Node* getLast(Node *head){
    if (head == NULL)
        return NULL;
    while (head -> next)
        head = head -> next;
    return head;
}
Node* getNth(Node *head, int n){
    int counter = 0;
    while(counter < n && head){
        head = head -> next;
        counter++;
    }
    return head;
}
int findFive(Node *head){
    int n = 1;
    while(head){
        if (head -> value == 5)
            return n;
        else{
            head = head -> next;
            n++;
        }
    }
    return -1;
}

void alfOrder(){}
void addNth(Node *head, int value, int n){
    Node *before = getNth(head, n-2); 
    Node *Nth = (Node*)malloc(sizeof(Node));
    Node *after = before -> next;
    Nth -> value = value;
    Nth -> next = after;
    before -> next = Nth;
}
void addAfter5(Node *head, int value){
    if (findFive(head) != -1){
        Node *beforeFive = getNth(head, findFive(head) - 1);
        Node *new = (Node*)malloc(sizeof(Node));
        Node *afterFive = beforeFive -> next;
        new -> value = value;
        new -> next = afterFive;
        beforeFive -> next = new;
    }
}
void addAfterg(){}
void addBeforeBeforeLast(){}
void addBeforeLast(){}
void add3th(Node *head, int value){
    addNth(head, value, 3);
}
void add2th(Node *head, int value){
    addNth(head, value, 2);
}
void addInEnd(Node *head, int value){
    Node *last = getLast(head);
    Node *temp = (Node*)malloc(sizeof(Node));
    temp -> value = value;
    temp -> next = NULL;
    last ->next = temp;
}
void addInBegin(Node *head, int value){

}

int main(){
    int n;
    char data[100];
    scanf("%s", &data);
    Node *head = (Node*)malloc(sizeof(Node));
    head -> value = atoi(data);
    head -> next = NULL;
    while(1){
        scanf("%s", &data);
        if (atoi(data) != 0){
            addInEnd(head, atoi(data));
            printList(head);
        }
        else{
            printf("exit");
            break;
        }
    }
    printf("Value: ");
    scanf("%s", data);
    printf("On the place: ");
    scanf("%d", &n);
    addNth(head, atoi(data), n);
    // addNth(head, 0, 3);
    printList(head);
}    