/*Дан символьный файл f. Получить файл g,
образованный из файла f заменой всех его строчных букв прописными. */

#include <stdio.h>

int main()
{
    FILE *f = NULL, *g;
    f = fopen("f.txt", "r");
    g = fopen("g.txt", "w");
    if (f == NULL) {
        printf("Не удалось открыть файл");
        return -1;
    }
    char c, c2;
    while ((c = fgetc(f)) != EOF) {
	printf("%c", c);
        if ((c >= 97) && (c <= 122)) {
            c2 = c - 32;
            putc(c2, g);
        } else
            putc(c, g);

    }
    fclose(f);
    fclose(g);
    return 0;
}
