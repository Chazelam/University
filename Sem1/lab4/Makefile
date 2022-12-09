# собираем программу test из объектного файла test.o
goldbach: main.o
	gcc -g -O0 -o goldbach goldbach.o

main.o: goldbach.c
	gcc -g -O0 -c goldbach.c

#Удаление временных файлов
clear:
	rm goldbach.o

#Форматирование текста	
indent:
	indent -kr -nut -ts4 goldbach.c