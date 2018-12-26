/**
 * \file configuration.h
 * \class Configuration
 * \brief Handles the configuration file.
 *
 *  This class has one variable for every key in the
 *	configuration file.
 * \author Gabriele Sani (gabryatfendor@gmail.com)
 *
 * \version 0.1
 * \date 25 Aug 2017
 */

#include <string>
#include <vector>

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#define WIDTH 80 //max for 15" is 166 X
#define HEIGHT 20 //max for 15" is 30 Y
#define POPULATION 25

//Key for data extraction from config file
#define KWIDTH 				"width"
#define KHEIGHT 			"height"
#define KPOPULATION 	"population"
#define KMAXLAKES			"max_lakes"
#define KMAXMOUNTAINS "max_mountains"
#define KMAXWOODS			"max_woods"
#define KLAKESRAY			"max_lakes_ray"
#define KMOUNTAINSRAY	"max_mountains_ray"
#define KWOODSRAY			"max_woods_ray"
#define KAUTOMATED		"automated"
#define KSPEED				"speed"
#define KMAPISLAND		"map_island"
#define KPATHDEBUG		"path_debug"

using namespace std;

class Configuration
{
	public:
				vector<string> configFile;  /**< Every vector element is a line of the config file */
        int width; /**< Grid width */
        int height; /**< Grid height */
        int population; /**< People running around */
        int maxLakes; /**< Max number of lakes */
        int maxMountains; /**< Max number of mountains */
        int maxWoods; /**< Max number of woods */
        int maxLakesRay; /**< Max ray of any lake */
        int maxMountainsRay; /**< Max ray of any mountain */
        int maxWoodsRay; /**< Max ray of any wood */
        bool automated; /**< If true update is called every #speed seconds */
        int speed;
        bool mapIsland; /**< If tue map will be an island */
        bool pathDebug; /**< If true enables verbose mode for pathing algorithm*/

				/*! \brief Transfer all the config file in configFile variable*/
				/*!
					\sa loadConfiguration()
					\param filename path to the file to be loaded.
				*/
        vector<string> loadConfiguration(string filename);
				/*! \brief Extract value associated to key from configFile*/
				/*!
					\sa valueForKey()
					\param key key associated to the value to be extracted.
				*/
				int valueForKey(string key);

        Configuration() : configFile(loadConfiguration("config")),
				width(valueForKey(KWIDTH)), height(valueForKey(KHEIGHT)),
				population(valueForKey(KPOPULATION)), maxLakes(valueForKey(KMAXLAKES)),
				maxMountains(valueForKey(KMAXMOUNTAINS)), maxWoods(valueForKey(KMAXWOODS)),
				maxLakesRay(valueForKey(KLAKESRAY)), maxMountainsRay(valueForKey(KMOUNTAINSRAY)),
				maxWoodsRay(valueForKey(KWOODSRAY)), automated(valueForKey(KAUTOMATED)),
				speed(valueForKey(KSPEED)), mapIsland(valueForKey(KMAPISLAND)),
				pathDebug(valueForKey(KPATHDEBUG)){};
        ~Configuration() {};
};
#endif
