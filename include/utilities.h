/**
 * \file utilities.h
 * \brief All the global variables are stored here.
 *
 * \author Gabriele Sani (gabryatfendor@gmail.com)
 *
 * \version 0.1
 * \date 25 Aug 2017
 */
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
extern Configuration cfg; /**< Configuration used by the whole application */
extern Terrain map[WIDTH][HEIGHT]; /**< Map saved as a grid of Terrain */
extern Person people[POPULATION]; /**< Array of people running around */
extern bool villageBuilded; /**< Will remove this one, used for testing some feature */
extern int wood; /**< Wood gathered */
extern int fish; /**< Fish gathered */
extern int food; /**< Food gathered */
extern int stone; /**< Stone gathered */

/*! \brief Check at the 4 cardinal point if a particular kind of terrain is present*/
/*!
  \sa checkAround()
  \param x x coordinate of the caller.
  \param y y coordinate of the caller.
  \param check kind of terrain to check.
*/
bool checkAround(int x, int y, char check);
/*! \brief Check at the 4 cardinal point if a particular origin of terrain is present*/
/*!
  \sa checkAroundOrigin()
  \param x x coordinate of the caller.
  \param y y coordinate of the caller.
  \param check kind of original terrain to check.
*/
bool checkAroundOrigin(int x, int y, char check);
/*! \brief Simplify C++ standard syntax. Return random between 2 integers*/
/*!
  \sa randBetween()
  \param min lower bound.
  \param max higher bound.
*/
int randBetween(int min, int max);
/*! \brief Find one free kind of terrain, starting from top left corner of map*/
/*!
  \sa findOneFree()
  \param kind kind of terrain we are looking.
*/
tuple<int, int> findOneFree(char kind);

#endif
