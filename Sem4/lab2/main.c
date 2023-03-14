#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int get_hash(const char* str){
    unsigned int hash = 2139062143;
    for(; *str; str++)
        hash = 37 * hash + *str;

    return hash;
}

int get_index(int hash, int n){
    return hash % n;
}

int main(){
    char table[6][20] = {"Razin", "Lyamzin", "Brusov", "Rootov", "Belonin", "Zinkevich"};
    int hash_table_len = 40;
    char hash_table[hash_table_len][20];
    char overflow[hash_table_len][20];
    int over_num = 0;
    for(int i = 0; i<hash_table_len; i++){
        strcpy(hash_table[i], "***");
        strcpy(overflow[i], "***");
    }

    for(int i = 0; i < 6; i++){
        char key[4]; key[3] = 0;
        strncpy(key, table[i], 3);
        int key_hash = get_hash(key);
        int index = get_index(key_hash, hash_table_len);
        if (!strcmp(hash_table[index], "***"))
            strcpy(hash_table[index], table[i]);
        else{
            strcpy(overflow[over_num], table[i]);
            over_num++;
        }
    }
    printf("Hash:\n");
    for(int i = 0; i < hash_table_len; i++){
        if (strcmp(hash_table[i], "***"))
            printf("%d  %s\n", i, hash_table[i]);
    }
    printf("Over:\n");
    for(int i = 0; i < hash_table_len; i++){
        if (strcmp(overflow[i], "***"))
            printf("%d  %s\n", i, overflow[i]);
    }
    char word[6] = "Brusov";
    char key[4]; key[3] = 0;
    strncpy(key, word, 3);
    int index = get_index(get_hash(key), hash_table_len);
    if (!strcmp(hash_table[index], word)){
        printf("Found in place %d of hash table\n", index);
        return 0;
    }
    else{
        int place = 0;
        for(int i = 0; i < hash_table_len; i++){
            if (!strcmp(overflow[place], word)){
                printf("Found in place %d of overflow\n", place);
                return 0;
           }
           place++;
        }
    }
    printf("Not found\n");
    return 1;
    //printf("%d - %d\n", get_hash("Raz")%40, get_hash("Zin")%40);
}