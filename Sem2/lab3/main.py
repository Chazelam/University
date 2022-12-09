#main.py -- программа для проверки гипотезы Гольдбаха
#Copyright (c) 2021, Student Name <lyamzin@cs.karelia.ru>
#This code is licensed under a MIT-style license.
 

import ctypes

#Параметры использования функций из C
#gcc -fPIC -shared -o calculate_primes.so calculate_primes.c
calculate_primes = ctypes.CDLL('./calculate_primes.so')
calculate_primes.array_receive.restype = ctypes.c_int
calculate_primes.array_receive.argtypes = [ctypes.c_int, ]

#Получение массива простых чисел из С функции
n = 100
calculate_primes.calculate_primes(n)
primes = []
for i in range(0, n):
    primes.append(calculate_primes.array_receive(i))

#Сама проверка гипотезы
down = int(input("Нижний порог:"))
up = int(input("Верхний порог:"))
for k in range(4, up + 1, 2):
    count = 0
    for i in range(2, int(k/2)+1):
        if i in primes:
            y = k - i
            if y in primes:
                count += 1
    if count != 0:
        print(k, count, k - y, y)
