#include "lib.h"

const char* input(){
    char word[20];
    printf("Search: ");
    scanf("%s", word);
    const char* s = malloc(strlen(word));
    strcpy(s, word);
    return s;
}

unsigned int get_hash(const char* str){
    unsigned int hash = 2139062143;
    for(; *str; str++)
        hash = 37 * hash + *str;

    return hash;
}