/**
 * \file map.h
 * \brief Contains many utility method that revolve around the map configuration.
 *
 * \author Gabriele Sani (gabryatfendor@gmail.com)
 *
 * \version 0.1
 * \date 25 Aug 2017
 */
#ifndef MAP_H
#define MAP_H

/*! \brief Called at every cycle, reprint the map and call all the method needed to proceed */
/*!
  \sa update()
*/
void update();
/*! \brief Initialize the map, following the configuration file directive*/
/*!
  \sa initMap()
*/
void initMap();
/*! \brief Set lakes in the map*/
/*!
  \sa setWater()
*/
void setWater();
/*! \brief Set woods in the map*/
/*!
  \sa setWood()
*/
void setWood();
/*! \brief Set mountains in the map*/
/*!
  \sa setMountain()
*/
void setMountain();
/*! \brief If we are on an island, transform map border in water*/
/*!
  \sa setIsland()
*/
void setIsland();
/*! \brief Print the map at the console*/
/*!
  \sa printMap()
*/
void printMap();
/*! \brief Initialize all the people into the map*/
/*!
  \sa initPeople()
*/
void initPeople();

#endif
