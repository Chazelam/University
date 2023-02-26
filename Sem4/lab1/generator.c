#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef struct _day_weather {
    int   num_day;     // день в году по счету
    float temp;        // цельсия
    float humidity;    // [0,1]
    float rain_mm;     // количество осадков
} day_weather;

int main(int argc, char** argv) {
    if( argc != 3) {
        printf("usage %s out-file num_records\n", argv[0]);
        return 0;
    }

    int num_records = strtol(argv[2], 0, 10);
    FILE* out = fopen(argv[1], "wb");

    fwrite("WTH", sizeof(char), 3, out);
    fwrite(&num_records, sizeof(int), 1, out);
    
    srand(time(NULL));
    for(int i = 0; i < num_records; i++){
        day_weather day;
        day.num_day = rand()%366 + 1;
        day.temp = ((float)rand())/((float)RAND_MAX)*100.0;
        day.humidity = (float)rand()/(float)RAND_MAX;
        day.rain_mm = ((float)rand())/((float)RAND_MAX)*10.0;

        fwrite(&day, sizeof(day_weather), 1, out);
    }
    
    return 0;
}

    
