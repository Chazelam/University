/*
  1. Создать файл, содержащий 180 чисел. Числа получить с помощью генератора
  случайных чисел, должны находиться в диапазоне  [-20, +20], содержать один
  знак после запятой. Найти наибольшее среди отрицательных чисел этого файла.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

float Max(float array[], int n){
  float m = -20;
  for(int i = 0; i < n; i++){
    if (m < array[i] && array[i] < 0)
      m = array[i];
  }
  return m;
}

int main()
{
    int temp;
    float g, res[180];
    FILE *outFile = fopen("out.txt", "w");
    if (outFile == NULL){
      printf("Failed to create file");
      return -1;
    }
    srand(time(NULL));
    for (int i = 0; i < 180; i++){
      temp = rand() % 400 - 200;
      g = temp;
      g = g / 10;
      res[i] = g;
      fprintf(outFile, "%0.1f\n", g);
//       fputc(g, outFile);
//       fputc('\n', outFile);
    }
//     for(int j = 0; j<180; j++)
//       printf("%0.1f\n", res[j]);
    printf("maximum negative number is %0.1f\n", Max(res, 180));
    fclose(outFile);
}
