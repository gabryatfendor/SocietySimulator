/**
 * \file terrain.h
 * \class Terrain
 * \brief Handles the tiles of the world.
 *
 * The map is composed by a grid of Terrains. In this class
 * we save the datas about every square of this grid.
 * \author Gabriele Sani (gabryatfendor@gmail.com)
 *
 * \version 0.1
 * \date 25 Aug 2017
 */
#ifndef TERRAIN_H
#define TERRAIN_H

class Terrain
{
	public:
		char origin; /**< Original kind of terrain, before any transformation happened */
		char kind; /**< Current kind of terrain */
		int usable; /**< Percentage of usability of the terrain */
		bool isRegenerating; /**< Is the terrain recovering its properties? */
		bool walkable; /**< Is the terrain walkable? */
		bool villagerHere; /**< Is there a villager onto the terrain? */
		bool villagerAimingHere; /**< Is a villager coming here? */
		Terrain() : origin('.'),kind('.'), usable(100),
		isRegenerating(false), walkable(true), villagerHere(false) {};
		~Terrain() {};
};
#endif
