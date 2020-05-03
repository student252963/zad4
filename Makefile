CPPFLAGS= -Wall -pedantic -std=c++17 -iquote -Iinc

__start__: ./uklad_rownan
	./uklad_rownan

obj:
	mkdir -p obj

uklad_rownan: obj obj/main.o obj/LZespolona.o
	g++ -o ./uklad_rownan obj/main.o obj/LZespolona.o

obj/main.o: src/main.cpp inc/Wektor.hh inc/LZespolona.hh
	g++ -c ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
	g++ -c ${CPPFLAGS} -o obj/LZespolona.o src/LZespolona.cpp
