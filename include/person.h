#include <cstdlib>

#ifndef PERSON_H
#define PERSON_H

class Person
{
	public:
        int sector; //0 woodcutter, 1 farmer, 2 fisher, 3 miner, 4 builder
        int tireness;
        int happiness;
        int position[2]; //x e y
        char underme;
        bool working;
        bool moving;
        bool tested;

        void fishing();
        void farming();
        void woodcutting();
        void mining();
        void buildvillage();

        Person() : sector (rand() % 5), tireness(100), happiness(100), working(false), moving(false), tested(false){};
        ~Person() {};
};
#endif
