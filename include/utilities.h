#include <iostream>
#include <unistd.h>
#include <vector>
#include <fstream>
#include <algorithm>

#include <configuration.h>
#include <person.h>
#include <terrain.h>


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

void update();
void init_map();
void set_water();
void set_wood();
void set_mountain();
void set_island();
void print_map();
void init_people();
bool checkAround(int x, int y, char check);
bool checkAroundOrigin(int x, int y, char check);

#endif
