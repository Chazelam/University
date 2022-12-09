/*
 1. Дан текстовый файл - программа на языке Си. В тех строках, где встречается  однострочный комментарий,
 заменить обозначение комментария // на символы /* , дописать в конец строки символы закрытия комментария. Результат записать в другой файл.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *oldFile = NULL, *newFile;
    char Buf[120];
    oldFile = fopen("test.c", "r");
    newFile = fopen("output.c", "w");
    //Проверка файла
    if (oldFile == NULL) {
        printf("Не удалось открыть файл");
        return -1;
    }
    //Основной цикл
    while (fgets(Buf, 120, oldFile) != NULL) { //Построчное считывание файла
       if (strstr(Buf, "//") == NULL){ //Проверка наличия "//" в строке
          fputs(Buf, newFile);  //если нет копируем строку
          fputs("\n", newFile);
       }
       else{ //Если "//" входит в строку:
         //Копирование строки в переменную str:
          char str[strlen(Buf)];
          strcpy(str, Buf);
          char *c = str; //Создание указатея на строку str

          int pos = strstr(str, "//")-str; //Нахождение позиции вхождения "//"
//          printf("%d\n", pos);

          //Нахождени начала строки
          char firstPart[pos];
          strncpy(firstPart, str, pos);
//          printf("%s\n", firstPart);

          //Нахождение остатка сроки
          c = c + pos + 2; //Сдвиг указателя на место сразу после "//"
          char secondPart[strlen(str)-pos];
          strncpy(secondPart, c, strlen(str)-pos-3);  //остаток строки
          printf("%s\n", secondPart);

          //Изменение файла
          fputs(firstPart, newFile);
          fputs("/* ", newFile);
          fputs(secondPart, newFile);
          fputs(" */", newFile);
          fputs("\n", newFile);
      }
   }
    fclose(oldFile);
    fclose(newFile);
    return 0;
}
