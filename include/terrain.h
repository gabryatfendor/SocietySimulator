#ifndef TERRAIN_H
#define TERRAIN_H

class Terrain
{
	public:
		char origin;
		char kind;
		int usable;
		bool isRegenerating;
		bool walkable;
		bool villagerHere;
		Terrain() : origin('.'),kind('.'), usable(100),
		isRegenerating(false), walkable(true), villagerHere(false) {};
		~Terrain() {};
};
#endif
