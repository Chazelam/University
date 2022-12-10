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
        printf("%d ", head -> value);
        head = head -> next;
    }
    printf("\n\n");
}

int nofTheLast = 0;
Node* getLast(Node *head){
    if (head == NULL)
        return NULL;
    else nofTheLast = 2;
    while (head -> next){
        head = head -> next;
        nofTheLast++;
    }
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

void addNth(Node *head, int value, int n){
    Node *before = getNth(head, n-2); 
    Node *Nth = (Node*)malloc(sizeof(Node));
    Node *after = before -> next;
    Nth -> value = value;
    Nth -> next = after;
    before -> next = Nth;
}
Node* removeNth(Node *head, int n){
    if (n == 1){
        Node *first =(Node*)malloc(sizeof(Node));
        first = head -> next;
        free(head);
        return first;
    return first;

    }
    else{
        Node *temp = head, *beforeTemp =NULL;
        Node *Nth = getNth(head, n);
        while(temp && temp -> next != Nth){
            beforeTemp = temp;
            temp = temp -> next;
        }
        beforeTemp -> next = temp -> next;
        free(temp);
        return head;
    }
}    
void addBefore5(Node *head, int value){
    if (findFive(head) != -1){
        Node *beforeFive = getNth(head, findFive(head) - 2);
        Node *new = (Node*)malloc(sizeof(Node));
        Node *Five = beforeFive -> next;
        new -> value = value;
        new -> next = Five;
        beforeFive -> next = new;
    }
}
void addBeforeBeforeLast(Node *head, int value){
    getLast(head);
    addNth(head, value, (nofTheLast - 2));
}
void addBeforeLast(Node *head, int value){
    getLast(head);
    addNth(head, value, (nofTheLast) - 1);
}
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
Node* addInBegin(Node *head, int value){
    Node *new = (Node*)malloc(sizeof(Node));
    new -> value = value;
    new -> next = head;
    return new;
}
Node* removeFirst(Node *head){
    Node *first =(Node*)malloc(sizeof(Node));
    first = head -> next;
    free(head);
    return first;
}

int main(){
    int n;
    char data[100];
    printf("Creating list\n");
    printf("Enter the value: ");
    scanf("%s", data);
    Node *head = (Node*)malloc(sizeof(Node));
    head -> value = atoi(data);
    head -> next = NULL;
    printf("Current list: ");
    printList(head);
    while(1){
        printf("Enter the value: ");
        scanf("%s", data);
        if (atoi(data) != 0 || data[0] == '0'){
            addInEnd(head, atoi(data));
            printf("Current list: ");
            printList(head);
        }
        else{
            printf("exit\n");
            break;
        }
    }
    char arg[1025];
    while(arg[0]  != 'q') {
        printf("Select an action.\n"
                "\t\t1. Add element;\n"
                "\t\t2. Remove element;\n"
                "\t\tq - Exit\nEnter:");
        scanf("%1024s", arg);
        switch(arg[0]){
        case '1':        
            while(arg[0]  != 'q') {
                printf("Select an action.\n"
                        "\t\tx. Add in alphabet order;\n"
                        "\t\t2. Add element on Nth place;\n"
                        "\t\t3. Add element before 5;\n"
                        "\t\tx. Add element after g;\n"
                        "\t\t5. Add element before before last;\n"
                        "\t\t6. Add element before last;\n"
                        "\t\t7. Add 3th element;\n"
                        "\t\t8. Add 2th element;\n"
                        "\t\t9. Add element in end of list;\n"
                        "\t\t0. Add element to the begining of list;\n"
                        "\t\tq  Exit\nEnter:");
                scanf("%1024s", arg);
                switch(arg[0]){
                case '1':
                    //alfOrder();
                    //printList(head);
                    printf("Not done yet.\n");
                    break;
                case '2':
                    printf("Value: ");
                    scanf("%s", data);
                    printf("On the place: ");
                    scanf("%d", &n);
                    addNth(head, atoi(data), n);
                    printList(head);
                    break;
                case '3':
                    printf("Value: ");
                    scanf("%s", data);
                    addBefore5(head, atoi(data));
                    printList(head);
                    break;
                case '4':
                    //scanf("%s", data);
                    //addAfterg(head, atoi(data));
                    //printList(head);
                    printf("Not done yet.\n");
                    break;
                case '5':
                    printf("Value: ");
                    scanf("%s", data);
                    addBeforeBeforeLast(head, atoi(data));
                    printList(head);
                    break;
                case '6':
                    printf("Value: ");
                    scanf("%s", data);
                    addBeforeLast(head, atoi(data));
                    printList(head);
                    break;
                case '7':
                    printf("Value: ");
                    scanf("%s", data);
                    add3th(head, atoi(data));
                    printList(head);
                    break;
                case '8':
                    printf("Value: ");
                    scanf("%s", data);
                    add2th(head, atoi(data));
                    printList(head);
                    break;
                case '9':
                    printf("Value: ");
                    scanf("%s", data);
                    addInEnd(head, atoi(data));
                    printList(head);
                    break;
                case '0':
                    printf("Value: ");
                    scanf("%s", data);
                    head = addInBegin(head, atoi(data));
                    printList(head);
                    break;
                case 'q':
                    break;
                }
            }
        case '2':
            while(arg[0]  != 'q') {
                printf("Select an action.\n"
                        "\t\tx. Remove in alphabet order;\n"
                        "\t\t2. Remove element on Nth place;\n"
                        "\t\t3. Remove element before 5;\n"
                        "\t\tx. Remove element after g;\n"
                        "\t\t5. Remove element before before last;\n"
                        "\t\t6. Remove element before last;\n"
                        "\t\t7. Remove 3th element;\n"
                        "\t\t8. Remove 2th element;\n"
                        "\t\t9. Remove element in end of list;\n"
                        "\t\t0. Remove element in the begining of list;\n"
                        "\t\tq - Exit\nEnter:");
                scanf("%1024s", arg);
                switch(arg[0]){
                case '1':
                    printf("Not done yet.\n");
                    break;
                case '2':
                    printf("Remove on the place: ");
                    scanf("%d", &n);
                    head = removeNth(head, n);
                    printList(head);
                    break;
                case '3':
                    if (findFive(head) != -1 && findFive(head) != 1){
                        head = removeNth(head, findFive(head) - 1);
                        printList(head);
                    }else{
                        printf("cant do this\n");    
                        printList(head);
                    }
                    break;
                case '4':
                    printf("Not done yet.\n");
                    break;
                case '5':
                    getLast(head);
                    removeNth(head, nofTheLast - 3);
                    printList(head);
                    break;
                case '6':
                    getLast(head);
                    removeNth(head, nofTheLast - 2);
                    printList(head);
                    break;
                case '7':
                    head = removeNth(head, 3);
                    printList(head);
                    break;
                case '8':
                    head = removeNth(head, 2);
                    printList(head);
                    break;
                case '9':
                    getLast(head);
                    removeNth(head, nofTheLast - 1);
                    printList(head);
                    break;
                case '0':
                    head = removeFirst(head);
                    printList(head);
                    break;
                case 'q':
                    break;
                }
            }
        case 'q':
            printf("exit\n");
            break;
        default:
            continue;
        }
    }  
}