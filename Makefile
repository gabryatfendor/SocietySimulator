# Retrieve OS, since MacOS need some specific configuration
OS := $(shell uname)

#Linked lib for macos
ifeq ($(OS),Darwin)
CC=c++
STD=c++11
STDLIB=libc++
else
CC=g++
endif

#Include directory
INC=./include

all:
	$(CC) -I$(INC) src/*.cpp -o SocietySimulator.out
macos:
	$(CC) -std=$(STD) -stdlib=$(STDLIB) -I$(INC) src/*.cpp -o SocietySimulator.out
macos-debug:
	$(CC) -std=$(STD) -stdlib=$(STDLIB) -g -I$(INC) src/*.cpp -o SocietySimulator-debug.out
debug:
	$(CC) -g -I$(INC) src/*.cpp -o SocietySimulator-debug.out
clean:
	rm -f *.out
