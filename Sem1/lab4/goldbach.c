/**
 * goldbach.c -- программа для проверки гипотезы Гольдбаха
 *
 * Copyright (c) 2021, Student Name <lyamzin@cs.karelia.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "Primes.h"
#include "isNumberInMassive.h"
int main()
{
    int n = 100;                 //Верхний порог проверки простоты чисел
    int down, up, y, count;
    int primes[n];
    Primes(primes, n);
    printf("Нижний порог:");
    scanf("%d", &down);
    printf("Верхний порог:");
    scanf("%d", &up);
    for (int k = 4; k <= up; k += 2) {
        count = 0;
        for (int x = 2; x <= k / 2; x++) {
            if (isNumberInMassive(x, primes, n) == 1) {
                y = k - x;
                if (isNumberInMassive(y, primes, n) == 1)
                    count++;
            }
        }
        printf("%d %d %d %d\n", k, count, k - y, y);
    }
}
