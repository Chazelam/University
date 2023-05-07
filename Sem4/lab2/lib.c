#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lib.h"

const char* input(){
    char word[20];
    printf("Search: ");
    scanf("%s", word);
    char* s = malloc(strlen(word));
    strcpy(s, word);
    return s;
}

char* slice(char*s, int from, int to) {
    int j = 0;
    for(int i = from; i <= to; ++i)
        s[j++] = s[i];
    s[j] = 0;
    return s;
}

unsigned int get_hash(const char* str){
    int hash = 0;
    for(; *str; str++)
        hash = hash + *str;
    hash = hash*hash;
    char temp[20];
    itoa(hash, temp, 10);

    int len = strlen(temp);
    int a= 0;
    if ((len % 2) == 0)
        a = 1;
    int st = (int) pow(10, ((abs(4 - len))/2)-1);
    char fin[20];
    strcpy(fin, slice(temp, st+a-1, len-st-1));
    return atoi(fin);
}

int get_index(int hash, int n){
    return hash % n;
}

// int main(){
//     printf("%d\n", get_index(get_hash("Razin"), 40));
//     printf("%d\n", get_hash("byeee"));
//     printf("%d\n", get_hash("esdgd"));
// }