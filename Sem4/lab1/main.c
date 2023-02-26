#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct _day_weather {
    int   num_day;     // день в году по счету
    float temp;        // цельсия
    float humidity;    // [0,1]
    float rain_mm;     // количество осадков
} day_weather;

void printarr(day_weather* array, int n){
    for(int i = 0; i<n; i++){
        printf("%d record:\n", i+1);
        printf(" Day: %d\n", array[i].num_day);
        printf(" Temp: %f\n", array[i].temp);
        printf(" Humidity: %f\n", array[i].humidity);
        printf(" Rain mm.: %f\n", array[i].rain_mm);
        printf("\n");
    }
}

int bubble_sort(day_weather* array, int N){
    int tmp;
    bool noSwap;
    for (int i = N - 1; i >= 0; i--){
        noSwap = 1;
        for (int j = 0; j < i; j++){
            if (array[j].num_day > array[j + 1].num_day){
                tmp = array[j].num_day;
                array[j].num_day = array[j + 1].num_day;
                array[j + 1].num_day = tmp;
                noSwap = 0;
            }
        }
        if (noSwap == 1)
            break;
    }
}

int binarysearch(int desired, day_weather* array, int n){
    int low, high, middle;
    low = 0;
    high = n - 1;
    while (low <= high){
        middle = (low + high) / 2;
        if (desired < array[middle].num_day)
            high = middle - 1;
        else if (desired > array[middle].num_day)
            low = middle + 1;
        else 
            return middle;
    }
    return -1;
}

int main(int argc, char** argv) {
    // Чтение файла
    if( argc != 2) {
	printf("usage %s in-file\n", argv[0]);
	return 0;
    }
    
    FILE* file = fopen(argv[1], "rb+");

    char head[4];
    fread(head, sizeof(char), 3, file);
    head[3]='\0';
    if(strcmp(head, "WTH") != 0) {
	    printf("invalid file\n: expected header WTH got %s\n", head);
	    return 0;
    }

    int amount_of_records;
    fread(&amount_of_records, sizeof(int), 1, file);

    // Создание массива записей
    day_weather day;
    day_weather arr[amount_of_records];
    for( int i = 0; i < amount_of_records; i++){
        fread(&day, sizeof(day_weather), 1, file);
        arr[i].num_day = day.num_day;
        arr[i].temp = day.temp;
        arr[i].humidity = day.humidity;
        arr[i].rain_mm = day.rain_mm;
    }

    // Вызов функций 
    printarr(arr, amount_of_records);
    bubble_sort(arr, amount_of_records);    
    printarr(arr, amount_of_records);
    int desired = 288;
    int N = binarysearch(desired, arr, amount_of_records);
    if (N != -1)
        printf("Day %d its record number %d\n", desired, N + 1);
    else
        printf("Day %d not found\n", desired);
    return 0;
}
