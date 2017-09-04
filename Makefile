# Retrieve OS, since MacOS need some specific configuration
OS := $(shell uname)

#Default compile
ifeq ($(OS),Darwin)
CC=c++
else
CC=g++
endif

# Linked lib for macos
ifeq ($(OS),Darwin)
STD=c++11
STDLIB=libc++
endif

#Include directory
INC=./include

all:
	$(CC) -I$(INC) src/*.cpp -o SocietySimulator.out
macos:
	$(CC) -std=$(STD) -stdlib=$(STDLIB) -I$(INC) src/*.cpp -o SocietySimulator.out
macos-debug:
	c++ -std=$(STD) -stdlib=$(STDLIB) -g -I$(INC) src/*.cpp -o SocietySimulator.out
debug:
	$(CC) -g -I$(INC) src/*.cpp -o SocietySimulator.out
clean:
	rm -f *.out
