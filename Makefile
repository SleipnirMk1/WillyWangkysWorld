OBJS	= main.o player.o graph.o mesinkata.o mesinkar.o
SOURCE	= main.c player.c graph.c mesinkata.c mesinkar.c
HEADER	= 
OUT	= output.out
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = -lm

all: $(OBJS)
	gcc main.o player.o graph.o mesinkata.o mesinkar.o -o a

main.o: main.c
	gcc -c main.c 

player.o: player.c
	gcc -c player.c 

graph.o: graph.c
	gcc -c ADT\graph\graph.c 

mesinkata.o: mesinkata.c
	gcc -c ADT\mesinkata\mesinkata.c 

mesinkar.o: mesinkar.c
	gcc -c ADT\mesinkata\mesinkar.c 


clean:
	rm -f *.o output