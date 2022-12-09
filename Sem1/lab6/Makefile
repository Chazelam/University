filter: filter.o bmp_io.o bmp_box_blur.o
	gcc -o filter filter.o bmp_io.o bmp_box_blur.o

filter.o: filter.c bmp.h
	gcc -c -Wall -Wextra filter.c

bmp_gray.o: bmp_box_blur.c bmp.h
	gcc -c -Wall -Wextra bmp_box_blur.c

bmp_io.o: bmp_io.c bmp.h
	gcc -c -Wall -Wextra bmp_io.c
	
clean:
	rm filter.o
	rm bmp_io.o
	rm bmp_box_blur.o