#include<stdio.h>

int main(){
    FILE *outFile = fopen("out.txt", "r");
    if (outFile == NULL){
      printf("Failed to open file");
      return -1;
    }

    float num, res[180];
    int i = 0;
    while (fscanf(outFile, "%f", &num) != EOF){
        res[i] = num;
        i++;
    }

    float m = -20;
    for(int i = 0; i < 179; i++){
        if (m < res[i] && res[i] < 0)
        m = res[i];
    }
    printf("maximum negative number is %0.1f\n", m);
    fclose(outFile);
}
