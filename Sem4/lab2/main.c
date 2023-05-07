#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

// Компиляция:
// gcc -g -c lib.c
// gcc -g -c main.c
// gcc -o main main.o lib.o


int main(){
    char table[131][20] = {"Benjamins", "Decker", "Fensel", "Gomez-Perez", "Erdmann", "Fensel", "Studer", "Witten", "Frank", "Mark", "Burling", "Morgan", "Kaufmann", "Clarke", "Fokoue", "Zhang", "Aggarwal", "Atroschenko", "Lisenko", "Petrichenko", "Surtaev", "Chiglikova", "Minnegalieva", "Mukhamedshin", "Rusetski", "Parkalov", "Jeffrey", "Atherton", "Bertalanffy", "Boulding", "Feinstein", "Shivalingaiah", "Matthew", "Smith", "Lindberg", "Poibeau", "Acoulon", "Avaux", "Beroff", "Cadeau", "Calberg", "Delale", "Temmerman", "Guenet", "Huis", "Jamalpour", "Krul", "Marcus", "Picoli", "Plancq", "Hudson", "Lengler", "Cocea", "Hershkovitz", "Aleven", "Hernandez", "Eppler", "Mesarovic", "Watanabe", "Wasson", "Kabassi", "Virvou", "Dorca", "Lopes", "Fernandez", "Rushforth", "Yoder", "Luke", "Cioffi", "Wille", "Ganter", "Revilla", "Pinker", "Rosch", "Sowa", "Panait", "Hawkins", "Lakoff", "Mikhailov", "Kasai", "Yamaguchi", "Nagano", "Mizoguchi", "Sullivan", "Dicheva", "Sosnovsky", "Brusilovsky", "Guha", "Downes", "Novak", "Canas", "Lenat", "Frenster", "Sanchez", "Sands", "Wiskoff", "Pittman", "First", "Spitzer", "Gibbon", "Pratt", "Bercken", "Spiegel", "Nenh", "Shepherd", "Amosig", "Escara", "Martinez", "Paculanang", "Yusoff", "Mavrikis", "Davidson", "Efimenko", "Drobyazko", "Kananykina", "Klintsov", "Lisitsin", "Seledkin", "Starostin", "Vorobyov", "Cunningham", "Maynard", "Bontcheva", "Tablan", "Nirenburg", "Raskin", "Berners-Lee", "Hendler", "Lassila", "Appelt", "Israel"};
    int table_len = 131;
    int hash_table_len = 400;
    char hash_table[hash_table_len][20];
    char overflow[hash_table_len][20];
    int over_num = 0;
    for(int i = 0; i<hash_table_len; i++){
        strcpy(hash_table[i], "***");
        strcpy(overflow[i], "***");
    }

    // Создание таблицы
    for(int i = 0; i < table_len; i++){
        int key_hash = get_hash(table[i]);
        int index = get_index(key_hash, hash_table_len);
        if (!strcmp(hash_table[index], "***"))
            strcpy(hash_table[index], table[i]);
        else{
            strcpy(overflow[over_num], table[i]);
            over_num++;
        }
    }

    // Вывод таблицы
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

    // Поиск
    const char* temp = input();
    char word[20];
    strcpy(word, temp);
    int index = get_index(get_hash(word), hash_table_len);

    printf("index - %d\n", index);
    printf("hash - %s\n", hash_table[index]);
    printf("word - %s\n", word);

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
}