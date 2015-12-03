#include <iostream>
#include <configuration.h>
#include <person.h>
#include <terrain.h>
#include <node.h>

#ifndef UTILITIES_H
#define UTILITIES_H

/*Global variables*/
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
void tellPathToPerson(int personIndex);
#endif
