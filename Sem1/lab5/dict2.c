#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 1023

void remove_karet(char *s, int lenght);

void remove_dollar(char *s, int lenght);

void show_entries(char *pattern, FILE * stream);

char *load_dictionary(char *dictionary, FILE * stream);

char *filter_dictionary(char *pattern, char *dictionary, char *entries);

char *rstrbuf(char *membuf, char *string);

char *strtbuf(char *string, char *buffer);

int main(int argc, char *argv[])
{

    /* Если нет аргументов, завершаем выполнение */
    if (argc == 1) {
        printf("Нет аргумента\n");
        return -1;
    }

    /* Проверим расширение файла */
    char *end = strchr(argv[1], '.');   // Найдём последнее вхождение "." в имени файла
    if (strcmp(end, ".dict") != 0) {    // Если окончание имени не ".dict", функция вернёт не 0
        printf("Это не файл .dict\n");
        return -1;
    }

    /* Файл словаря */
    FILE *dict = NULL;
    dict = fopen(argv[1], "r");
    if (dict == NULL) {
        printf("Ошибка чтения файла");
        return -1;
    }

    /* Вычислим размер файла */
    fseek(dict, 0, SEEK_END);
    long long size = ftell(dict) + 1;
    rewind(dict);

    /* Выделим буфер */
    char *dict_buffer = (char *) calloc(sizeof(char), size);
    char *result_buffer = (char *) calloc(sizeof(char), size);


    if (dict_buffer == NULL || result_buffer == NULL) {
        printf("Ошибка создания буфера");
        return -1;
    }

    /* Чтение файла в буфер */
    dict_buffer = load_dictionary(dict_buffer, dict);

    if (dict_buffer == NULL) {
        printf("Не удалось загрузить словарь");
        return -1;
    }

    char *c_result = NULL;


    while (1) {
        /* Требуемая строка */
        char requested_word_pattern[MAXLINE] = "";
        fgets(requested_word_pattern, MAXLINE, stdin);

        filter_dictionary(requested_word_pattern, dict_buffer,
                          result_buffer);

        for (int i = 0; i < strlen(requested_word_pattern); i++) {
            if (*requested_word_pattern) {
                requested_word_pattern[i] = '\0';
            }
        }

        printf("%s", result_buffer);
    }

    fclose(dict);
    free(dict_buffer);
    free(result_buffer);
    return 0;
}

/* Функция удаляет символ карет (^) из начала строки */
void remove_karet(char *s, int lenght)
{
    for (int k = 0; k < lenght; k++) {
        s[k] = s[k + 1];
    }
}

/* Функция удаляет символ доллара в конце строки */
void remove_dollar(char *s, int lenght)
{
    s[lenght - 2] = '\n';
    s[lenght - 1] = '\0';
}

/* Загрузка словаря в буфер */
char *load_dictionary(char *dictionary, FILE * stream)
{
    /* Определим размер файла в байтах */
    fseek(stream, 0, SEEK_END);
    unsigned long long size = ftell(stream);
    rewind(stream);

    unsigned long long readed = fread(dictionary, 1, size, stream);
    if (readed != size) {
        return NULL;
    } else {
        return dictionary;
    }
}

char *filter_dictionary(char *pattern, char *dictionary, char *entries)
{
    /* Текущая строка */
    char current_line[MAXLINE] = "";

    /* Длина шаблона */
    int pattern_length = strlen(pattern);

    /* Тип шаблона поиска */
    int pattern_type = 0;

    /* Указатель на буфер словаря */
    char *b_dict;
    b_dict = dictionary;

    char *b_result;
    b_result = entries;

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
    while (rstrbuf(b_dict, current_line) != NULL) {
        b_dict = rstrbuf(b_dict, current_line);
        if (!isspace(current_line[0])) {
            if (!strcmp(current_line, pattern) && pattern_type == 0) {
                is_requested_word = 1;
            } else if (pattern_type == -1) {
                /* Поиск совпадений только в начале слова */
                if (strstr(current_line, pattern) == (current_line + 1)
                    || strstr(current_line, pattern) == current_line) {
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
        /* Скопируем в буфер статью построчно */
        char *line;
        if (is_requested_word) {
            /* Первая строка */
            line = current_line;
            while (*line) {
                *(b_result++) = *(line++);
            }

            b_dict = rstrbuf(b_dict, current_line);

            /* Остальные строки */
            while (isspace(current_line[0])) {
                line = current_line;
                while (*line) {
                    *(b_result++) = *(line++);
                }
                b_dict = rstrbuf(b_dict, current_line);
            }
            *(b_result) = '\0';
            is_requested_word = 0;
        }
    }
}

/* Читаем одну строку из буфера не включая \n */
char *rstrbuf(char *membuf, char *string)
{
    /*Бежим побайтово */
    while (*membuf) {
        /* Пока не встречается конец строки и конец буфера, копируем строку из буфера в string */
        /* Цикл будет завершён, когда в следующей ячейке пусто, но последний символ не будет скопирован */
        if (*membuf != '\n' && *(membuf + 1) != '\0') {
            *(string++) = *(membuf++);
        } else {
            /* Копируем последний символ, если встретился конец буфера */
            if (*(membuf + 1) == '\0') {
                *(string++) = *(membuf);
            }
            /*  */
            *(string++) = '\n';
            *string = '\0';
            /* Возвращаем новое положение указателя */
            return membuf + 1;
        }
    }
}
