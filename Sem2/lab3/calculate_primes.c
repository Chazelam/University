/**
 * Primes.h -- программа построения массива простых чисел
 *
 * Copyright (c) 2021, Student Name <lyamzin@cs.karelia.ru>
 *
 * This code is licensed under a MIT-style license.
 */

//Решето Эратосфена (принимает на вход верхний порог и пустой массив, заполняет его 1 и 0 в зависемости от простоты числа):
#include <stdio.h>
#define m 100
int primes[m];
int Sieve(int n, int sieve[])
{
    for (int i = 3; i <= n; i++)
        sieve[i] = 1;
    for (int i = 2; i <= n; i++) {
        if (sieve[i] != 1) {
            continue;
        }
        for (int j = 2; j * i <= n; j++) {
            sieve[j * i] = 0;
        }
    }
    return 0;
}
//Функция постороения массива простых чисел (на вход принемает пустой массив и заполняет его простыми числами):
int calculate_primes(int n)
{
    int g = 0;
    int sieve[n];
    sieve[0] = 0;
    sieve[1] = 0;
    sieve[2] = 1;
    Sieve(n, sieve);
    for (int i = 0; i <= n; i++) {
        if (sieve[i] == 1) {
            primes[g] = i;
            g++;
        }
    }
    return 0;
}

int array_receive(int x){
  int value = primes[x];
  return value;
}
