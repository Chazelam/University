# собираем программу dict1 из объектного файла dict1.o
goldbach: main.o
	gcc -g -O0 -o main main.o

main.o: main.c
	gcc -g -O0 -c main.c

#Удаление временных файлов
clear:
	rm main.o

#Форматирование текста	
indent:
	indent -kr -nut -ts4 main.c
