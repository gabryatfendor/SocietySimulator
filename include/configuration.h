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
        int max_lakes;
        int max_mountains;
        int max_woods;
        //Max ray of each feature
        int max_lakes_ray;
        int max_mountains_ray;
        int max_woods_ray;
        //if automated, step every #speed seconds, otherwise press a button to proceed
        bool automated;
        int speed;
        //Do we want an island?
        bool map_island;
        //Enable debug for pathing algorithm
        bool path_debug;

				//configuration file
        vector<string> loadConfiguration(string filename);
				int value_for_key(vector<string> file, string key);

        Configuration() : configFile(loadConfiguration("config")),
				width(value_for_key(configFile, KWIDTH)), height(value_for_key(configFile, KHEIGHT)),
				population(value_for_key(configFile, KPOPULATION)), max_lakes(value_for_key(configFile, KMAXLAKES)),
				max_mountains(value_for_key(configFile, KMAXMOUNTAINS)), max_woods(value_for_key(configFile, KMAXWOODS)),
				max_lakes_ray(value_for_key(configFile, KLAKESRAY)), max_mountains_ray(value_for_key(configFile, KMOUNTAINSRAY)),
				max_woods_ray(value_for_key(configFile, KWOODSRAY)), automated(value_for_key(configFile, KAUTOMATED)),
				speed(value_for_key(configFile, KSPEED)), map_island(value_for_key(configFile, KMAPISLAND)),
				path_debug(value_for_key(configFile, KPATHDEBUG)){};
        ~Configuration() {};
};
#endif
