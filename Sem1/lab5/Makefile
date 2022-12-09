# собираем программу dict1 из объектного файла dict1.o
goldbach: main.o
	gcc -g -O0 -o dict2 dict2.o

main.o: dict2.c
	gcc -g -O0 -c dict2.c

#Удаление временных файлов
clear:
	rm dict2.o

#Форматирование текста	
indent:
	indent -kr -nut -ts4 dict2.c
