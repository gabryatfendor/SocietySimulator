#include <iostream>
#include <unistd.h>
#include <vector>
#include <fstream>
#include <algorithm>

#include <configuration.h>
#include <person.h>
#include <terrain.h>
#include <map.h>

#ifndef UTILITIES_H
#define UTILITIES_H

/*Global variables*/
extern Configuration cfg;
extern Terrain map[WIDTH][HEIGHT];
extern Person people[POPULATION];
extern bool villagebuilded;
extern int wood;
extern int fish;
extern int food;
extern int stone;

bool checkAround(int x, int y, char check);
bool checkAroundOrigin(int x, int y, char check);

#endif
