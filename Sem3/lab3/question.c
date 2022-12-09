#include<stdio.h>

int read(float res[]){
    float num;//, res[180];
    int i = 0;
    FILE *outFile = fopen("out.txt", "r");
    if (outFile == NULL){
      printf("Failed to open file");
      return -1;
    }
    while ((num = fgetc(outFile)) != EOF){
        res[i] = num;
        i++;
    }
    //return res;
}

int main(){

    argv[1] == "-p"
    argv[2] == "3"

    while (true) {
	printf("VVedite>> "
	fscanf(str);
	if str == "view"
	if str == "1p" ...
        if str == "corr" .... 
    }
    
    float res[100];
    read(res);
    //float res = read(r);
    //float m = Max(res, 180);
    float m = -20;
    for(int i = 0; i < 180; i++){
        if (m < res[i] && res[i] < 0)
        m = res[i];
    }
    return m;
    printf("maximum negative number is %0.1f\n", m);
}
