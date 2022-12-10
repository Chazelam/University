#ifndef CMN_HDR_H
#define CMN_HDR_H
const char* header = "BRUWTHR\0";

typedef struct _day_weather {
    int   num_day; // день в году по счету
    int   year; // день в неделе по счету
    float temp; // цельсия
    float humidity; // [0,1]
    float rain_mm; // количество осадков
    float sunny_hours; // солнечных часов
    int   cats_seen; // 
} day_weather;


#endif
