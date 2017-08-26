#Default compile
CC=g++
#Include directory
INC=./include

all:
	$(CC) -I$(INC) src/*.cpp -o SocietySimulator.out
debug:
	$(CC) -g -I$(INC) src/*.cpp -o SocietySimulator.out
clean:
	rm -f *.out
