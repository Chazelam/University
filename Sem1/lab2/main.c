/**
 * floor.c -- программа для расчета нужного этажа
 *
 * Copyright (c) 2009, Student Name <lyamzin@cs.karelia.ru>
 *
 * This code is licensed under a MIT-style license.
 */ 
 
#include<stdio.h>

int main()
{
    //int flat = 0;
    /* Номер квартиры */
    int flat_number;

    /* Число квартир на этаже */
    int flats_per_floor;
 
    /* Запрашиваем квартиру, в которой проживает адресат */
    printf("Введите номер интересующей квартиры: ");
    scanf("%d", &flat_number);

    /* Запрашиваем число квартир на этаже */
    printf("Введите число квартир на каждом этаже: ");
    scanf("%d", &flats_per_floor);

    /* Рассчитываем и выводим номер этажа */
    int flat;
    if (flat_number%flats_per_floor == 0)
	flat =flat_number / flats_per_floor;
    else
	flat = flat_number / flats_per_floor + 1;
    
    printf("Вам нужно подняться на %d этаж\n", flat);

    return 0;
}
