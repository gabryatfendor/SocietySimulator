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
		Terrain() : origin('.'),kind('.'), usable(100), isregenerating(false), walkable(true) {};
		~Terrain() {};
};
#endif
