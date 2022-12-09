/**
 * floorisNumberInMassive.h -- программа для проверки наличья чила в массиве
 *
 * Copyright (c) 2021, Student Name <lyamzin@cs.karelia.ru>
 *
 * This code is licensed under a MIT-style license.
 */

// программа для проверки наличья чила в массиве, на вход
// принемает число наличие которого надо проверитьб, сам
// массив и его размерность и выдает 0 или 1 в зваисимости
// от наличия числа в массиве:
#include <stdio.h>
int isNumberInMassive(int x, int primes[], int size)
{
    for (int i = 0; i < size; i++) {
        if (x == primes[i]) {
            return 1;
        }
    }
    return 0;
}
