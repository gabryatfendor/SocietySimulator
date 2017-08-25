#ifndef TERRAIN_H
#define TERRAIN_H

class Terrain
{
	public:
		char origin;
		char kind;
		int usable;
		bool isregenerating;
		bool walkable;
		bool villagerHere;
		Terrain() : origin('.'),kind('.'), usable(100),
		isregenerating(false), walkable(true), villagerHere(false) {};
		~Terrain() {};
};
#endif
