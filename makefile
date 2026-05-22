derle: program calistir

program: ./lib/Ilce.o ./lib/Kisi.o ./lib/Mahalle.o ./lib/main.o ./lib/Oyun.o ./lib/Sehir.o ./lib/Yerlesim.o
	gcc ./lib/Ilce.o ./lib/Kisi.o ./lib/Mahalle.o ./lib/main.o ./lib/Oyun.o ./lib/Sehir.o ./lib/Yerlesim.o -o ./bin/program

./lib/Ilce.o: ./src/Ilce.c
	gcc -I ./include -c ./src/Ilce.c -o ./lib/Ilce.o

./lib/Kisi.o: ./src/Kisi.c
	gcc -I ./include -c ./src/Kisi.c -o ./lib/Kisi.o

./lib/Mahalle.o: ./src/Mahalle.c
	gcc -I ./include -c ./src/Mahalle.c -o ./lib/Mahalle.o

./lib/main.o: ./src/main.c
	gcc -I ./include -c ./src/main.c -o ./lib/main.o

./lib/Oyun.o: ./src/Oyun.c
	gcc -I ./include -c ./src/Oyun.c -o ./lib/Oyun.o

./lib/Sehir.o: ./src/Sehir.c
	gcc -I ./include -c ./src/Sehir.c -o ./lib/Sehir.o

./lib/Yerlesim.o: ./src/Yerlesim.c
	gcc -I ./include -c ./src/Yerlesim.c -o ./lib/Yerlesim.o

calistir:
	./bin/program

temizle:
	del /Q .\lib\*.o
	del /Q .\bin\program.exe