#include <string>
#include <vector>

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#define WIDTH 80 //max for 15" is 166 X
#define HEIGHT 20 //max for 15" is 30 Y
#define POPULATION 5

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
				vector<string> configFile;
        //Screen dimension
        int width;
        int height;
        //People running around
        int population;
        //Max number of natural features
        int maxLakes;
        int maxMountains;
        int maxWoods;
        //Max ray of each feature
        int maxLakesRay;
        int maxMountainsRay;
        int maxWoodsRay;
        //if automated, step every #speed seconds, otherwise press a button to proceed
        bool automated;
        int speed;
        //Do we want an island?
        bool mapIsland;
        //Enable debug for pathing algorithm
        bool pathDebug;

				//configuration file
        vector<string> loadConfiguration(string filename);
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
