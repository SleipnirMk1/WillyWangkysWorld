CC = gcc
CFLAGS = -c -Wall
PROFILE_FLAGS = -fprofile-arcs -ftest-coverage
TST_LIBS = -lcheck -lm -lpthread -lrt
COV_LIBS = -lgcov -coverage
SRC_DIR= ADT
SRC_FILES = $(addprefix $(SRC_DIR)/, *.c) 

all: coverage

graph.o:$(addprefix $(SRC_DIR)/graph/, graph.h)
	$(CC) $(CFLAGS) $(SRC_DIR)/graph/graph.c

mesinkata.o:  $(SRC_FILES) $(addprefix $(SRC_DIR)/mesinkata/, mesinkata.h)
	$(CC) $(CFLAGS) $(PROFILE_FLAGS) $(SRC_DIR)/mesinkata/mesinkata.c

mesinkar.o:  $(SRC_FILES) $(addprefix $(SRC_DIR)/mesinkar/, mesinkar.h)
	$(CC) $(CFLAGS) $(PROFILE_FLAGS) $(SRC_DIR)/mesinkata/mesinkar.c

main.o: main.c
	$(CC) $(CFLAGS) $(PROFILE_FLAGS) main.c

aa: graph.o main.o mesinkata.o mesinkar.o
	$(CC) graph.o main.o mesinkata.o mesinkar.o $(TST_LIBS) $(COV_LIBS) -o aa


coverage: aa

clean:
	-rm *.o