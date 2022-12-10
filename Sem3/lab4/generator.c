#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "common_header.h"

int main(int argc, char** argv) {
    if( argc != 3) {
	printf("usage %s out-file num_records\n", argv[0]);
	return 0;
    }

    int num_records = strtol(argv[2], 0, 10);
    
    FILE* out = fopen(argv[1], "wb");
    assert(out);

    fwrite(header, sizeof(char), 7, out);
    fwrite(&num_records, sizeof(int), 1, out);
    
    srand(time(NULL));
    for(int i = 0; i < num_records; i++){
	day_weather day;
	day.num_day = rand()%366 + 1;
	day.year = rand()%53 + 1970;
	day.temp = ((float)rand())/((float)RAND_MAX)*100.0;
	day.humidity = (float)rand()/(float)RAND_MAX;
	day.rain_mm = ((float)rand())/((float)RAND_MAX)*10.0;
	day.sunny_hours = ((float)rand())/((float)RAND_MAX)*24.0;
	day.cats_seen = rand() + 1;

	fwrite(&day, sizeof(day_weather), 1, out);
    }
    
    return 0;
}

    
