#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "common_header.h"
extern const char* header;

int main(int argc, char** argv) {
    if( argc != 2) {
	printf("usage %s in-file\n", argv[0]);
	return 0;
    }
    FILE* in = fopen(argv[1], "rb+");
    assert(in);

    char buf[8];
    
    fread(buf, sizeof(char), 7, in);
    buf[7] = '\0';
    
    if(strcmp(buf, header) != 0) {
	printf("invalid file\n: expected header %s got %s\n", header, buf);
	return 0;
    }
    int amount_of_records;
    fread(&amount_of_records, sizeof(int), 1, in);

    char bf[1024];
    day_weather day;
    int N;
    
    while(bf[0]  != 'q') {
	printf("Выберите действие.\n"
	       "\t\tall - весь файл\n"
	       "\t\tN[число](напр N100) - N-ая запись(нумерация с 0)\n"
	       "\t\tq - выход\nВвод:");
	scanf("%1024s", bf);
	switch(bf[0]){
	case 'a':
	        for( int i = 0; i < amount_of_records; i++){
		    fread(&day, sizeof(day_weather), 1, in);
		    printf("On day %d of the year %d it was %f degrees hot.\n Humidity was %f%% and"
			   "it rained %f mm.\nIt was sunny for %f hours. I've seen %d cats.\n",
			   day.num_day, day.year, day.temp, day.humidity, day.rain_mm, day.sunny_hours,
			   day.cats_seen);
		}
		break;
	case 'N':
	    N = strtol(bf+1, 0, 10);
	    if(N < amount_of_records) {
		fseek(in, N*sizeof(day_weather), SEEK_CUR);
		fread(&day, sizeof(day_weather), 1, in);
		fseek(in, -sizeof(day_weather), SEEK_CUR);

		printf("change year:");
		scanf("%d", &day.year);
		printf("%d\n", day.year);
		
		fwrite(&day, sizeof(day_weather), 1, in);
	    }
	    break;
	default:
	    break;
	}
	fseek(in, 7+sizeof(int), SEEK_SET);
    }

    fclose(in);
    
    return 0;
}
