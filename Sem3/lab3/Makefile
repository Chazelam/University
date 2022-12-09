# собираем программу main из объектного файла main.o
main: main.o
	gcc -g -O0 -o main main.o
	rm main.o

main.o: main.c
	gcc -g -O0 -c main.c

# собираем программу max из объектного файла max.o
max: max.o
	gcc -g -O0 -o max max.o
	rm max.o

max.o: max.c
	gcc -g -O0 -c max.c

#Форматирование текста	
indent:
	indent -kr -nut -ts4 main.c
