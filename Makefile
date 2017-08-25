#Default compile
CC=g++
#Include directory
INC=./include

all:
	$(CC) -I$(INC) src/utilities.cpp src/map.cpp src/configuration.cpp src/person.cpp src/societysimulator.cpp -o SocietySimulator.out
clean:
	rm -f *.out
