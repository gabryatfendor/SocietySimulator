#include <cstdlib>
#include <iostream>

#ifndef PERSON_H
#define PERSON_H

class Person
{
	public:
        int sector; //0 taglialegna, 1 contadino, 2 pescatore, 3 minatore, 4 architetto
        int tireness;
        int happiness;
        int position[2]; //x e y
        int destination[2]; //x e y
        int path[500];
        int pathIndex;
        char underme;
        bool working;
        bool moving;
        bool tested;
        
        void fishing(int i);
        void farming(int i);
        void woodcutting(int i);
        void mining(int i);
        void buildvillage(int i);
	    
        Person() : sector (rand() % 5), tireness(100), happiness(100), working(false), moving(false), pathIndex(0), tested(false){};
        ~Person() {};
};
#endif
