#include <cstdlib>
#include <vector>
#include <tuple>

#ifndef PERSON_H
#define PERSON_H

using namespace std;

class Person
{
	public:
        int sector; //0 woodcutter, 1 farmer, 2 fisher, 3 miner, 4 builder
        int tireness;
        int happiness;
        int position[2]; //x e y
        char underMe;
        bool working;
        bool moving;
        bool tested;
				vector<tuple<int, int>> pathCoordinates;

        void fishing();
        void farming();
        void woodcutting();
        void mining();
        void buildVillage();
				void move();
				vector<tuple<int, int>> setPath();

        Person() : sector (rand() % 5), tireness(100), happiness(100),
				working(false), moving(false), tested(false), pathCoordinates(setPath()){};
        ~Person() {};
};
#endif
