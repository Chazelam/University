#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 1023

void remove_karet(char *s, int lenght);

void remove_dollar(char *s, int lenght);

void show_entries(char *pattern, FILE *stream);

int main(int argc, char *argv[]) {

    /* Если нет аргументов, завершаем выполнение */
    if (argc == 1) {
        printf("Нет аргумента\n");
        return -1;
    }

    /* Проверим расширение файла */
    char *end = strrchr(argv[1], '.'); // Найдём последнее вхождение "." в имени файла
    if(strcmp(end, ".dict") != 0) {     // Если окончание имени не ".dict", функция вернёт не 0
        printf("Это не файл .dict\n");
        return -1;
    }

    /* Файл словаря */
    FILE *dict = NULL;
    dict = fopen(argv[1], "r");

    /* Если указатель на файл пустой, то файл не открылся */
    if (dict == NULL) {
        printf("Не удалось открыть файл");
        return -1;
    }
    /* Требуемая строка */

    
    char requested_word_pattern[MAXLINE] = "";
    fgets(requested_word_pattern, MAXLINE, stdin);

    show_entries(requested_word_pattern, dict);    
    
    return 0;
}


/* Функция удаляет символ карет (^) из начала строки */
void remove_karet(char *s, int lenght) {
    for (int k = 0; k < lenght; k++) {
        s[k] = s[k + 1];
    }
}


/* Функция удаляет символ доллара в конце строки */
void remove_dollar(char *s, int lenght) { 
    s[lenght - 2] = '\n';
    s[lenght - 1] = '\0';
}


void show_entries(char *pattern, FILE *stream) {
    /* Текущая строка */
    char current_line[MAXLINE] = "";

    /* Длина шаблона */
    int pattern_length = strlen(pattern);

    /* Тип шаблона поиска */
    int pattern_type = 0;

    /* Рассмотрим ситуацию, когда шаблон имеет вид ^pattern$ */
    if (pattern[0] == '^') {
        if (pattern[pattern_length - 2] == '$') {
            /* Так как строка имеет вид {'^', 'p', 'a', 't', 't', 'e', 'r', 'n', '$', '\n'}, перенесём '\n' и занулим '$' */
            remove_dollar(pattern, pattern_length);
            /* Получаем строку {'^', 'p', 'a', 't', 't', 'e', 'r', 'n', '\n', '\0'} */

            /* Избавимся от символа '^' в шаблоне */
            remove_karet(pattern, pattern_length);
            /* Получаем строку вида {'p', 'a', 't', 't', 'e', 'r', 'n', '\n', '\0'}, которую теперь можно сравнивать со статьями */
        } else {
            /* Поиск совпадений только в начале */
            pattern_type = -1;

            /* Избавимся от символа '^' в шаблоне */
            remove_karet(pattern, pattern_length);
            
            /* Так как шаблон имеет вид {'^', 'p', 'a', 't', 't', 'e', 'r', 'n', '\n', '\0'}, необходимо избавиться от знака '\n', чтобы функция strstr() нашла вхождение */
            if (strchr(pattern, '\n') != NULL) {
                pattern[strchr(pattern, '\n') - pattern] = '\0';
            }
        }
    } else if (pattern[pattern_length - 2] == '$') {
        pattern_type = 1;
        /* Так как строка имеет вид {'p', 'a', 't', 't', 'e', 'r', 'n', '$', '\n', '\0'}, избавимся от '$' */
        
        remove_dollar(pattern, pattern_length);
        /* Получаем строку {'p', 'a', 't', 't', 'e', 'r', 'n', '\n', '\0'} */
        pattern_length--;
        
    }

    


    int is_requested_word = 0;
    while (fgets(current_line, MAXLINE, stream) != NULL) {
        if (!isspace(current_line[0])) {
            if (!strcmp(current_line, pattern) && pattern_type == 0) {
                is_requested_word = 1;
            } else if (pattern_type == -1) {
                /* Поиск совпадений только в начале слова */
                if (strstr(current_line, pattern) == (current_line + 1) || strstr(current_line, pattern) == current_line) {
                    is_requested_word = 1;
                } else {
                    is_requested_word = 0;
                }
            } else if (pattern_type == 1) {
                if (strstr(current_line, pattern) != NULL) {
                    is_requested_word = 1;
                } else {
                    is_requested_word = 0;
                }
            } else {
                is_requested_word = 0;
            }
        }
        if (is_requested_word) {
            printf("%s", current_line);
        }
    }
}