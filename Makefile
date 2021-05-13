
flags = -g -O3 -Wall -I ./includes -std=c99 -pedantic #-Werror

#all 

all: server

#linking

server: ./obj/main.o ./obj/parser.o ./obj/sharedqueue.o
	gcc ./obj/main.o ./obj/parser.o ./obj/sharedqueue.o -o ./server -pthread

#obj file

./obj/main.o: ./src/main.c
	gcc ./src/main.c $(flags) -c -o ./obj/main.o

./obj/parser.o: ./src/parser.c
	gcc ./src/parser.c $(flags) -c -o ./obj/parser.o

./obj/sharedqueue.o: ./src/sharedqueue.c
	gcc ./src/sharedqueue.c $(flags) -c -o ./obj/sharedqueue.o