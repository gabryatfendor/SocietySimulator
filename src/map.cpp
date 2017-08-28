#include <utilities.h>

using namespace std;

/*Launched every timestep*/
void update()
{
	printMap();
	int k,x,y;
	for(int i=0;i<POPULATION;i++)
	{
		people[i].move();
	}

	if(cfg.automated)
		sleep(cfg.speed);
	else
		getchar();
	system("clear");
	return;
}

/*This file will have to be refactored, is a mix up of functions*/
/*Launched 1 time to initialize map checking configuration*/
void initMap()
{
	if(cfg.maxLakes>0)
		setWater();
	if(cfg.maxWoods>0)
		setWood();
	if(cfg.maxMountains>0)
		setMountain();
  if(cfg.mapIsland)
    setIsland();
  return;
}

/*At the moment there are 4 kind of terrain:
    a- plain  .
    b- water     -
    c- mountain ^
    d- wood    |
    small groups of the same type are created following DEFINE in configuration.h*/

void setWater()
{
    int lakes = randBetween(1, cfg.maxLakes);
    for(int i=0;i<lakes;i++)
    {
        int ray = randBetween(1, cfg.maxLakesRay);
				int x = randBetween(WIDTH-ray, ray);
				int y = randBetween(HEIGHT-ray, ray);
        for(int j=x-ray;j<x+ray;j++)
        {
            for(int k=y-ray;k<y+ray;k++)
            {
                map[j][k].kind='-';
                map[j][k].origin='-';
                map[j][k].walkable=true;
            }
        }
    }
    return;
}

void setWood()
{
	int woods = randBetween(1, cfg.maxWoods);

	for(int i=0;i<woods;i++)
	{
		/*set ray*/
		int ray = randBetween(1, cfg.maxWoodsRay);
		/*choose center*/
		int x = randBetween(WIDTH-ray, ray);
		int y = randBetween(HEIGHT-ray, ray);
		/*mapping*/
		for(int j=x-ray;j<x+ray;j++)
		{
			for(int k=y-ray;k<y+ray;k++)
			{
				map[j][k].kind='|';
				map[j][k].origin='|';
			}
		}
	 }
}

void setMountain()
{
	int mountains = randBetween(1, cfg.maxMountains);
	for(int i=0;i<mountains;i++)
	{
		/*set ray*/
		int ray = randBetween(1, cfg.maxMountainsRay);
		/*choose center*/
		int x = randBetween(WIDTH-ray, ray);
		int y = randBetween(HEIGHT-ray, ray);
		/*mapping*/
		for(int j=x-ray;j<x+ray;j++)
		{
			for(int k=y-ray;k<y+ray;k++)
			{
				map[j][k].kind='^';
				map[j][k].origin='^';
			}
		}
	 }
}

void setIsland()
{
	if(cfg.mapIsland)
	 {
		 for(int i=0;i<WIDTH;i++)
		 {
			for(int j=0;j<HEIGHT;j++)
			{
				if(i<2 || j<2 || i>WIDTH-3 || j>HEIGHT-3)
				{
					map[i][j].kind = '-';
					map[i][j].origin = '-';
					map[i][j].walkable=false;
				}
			}
		 }
	 }
 }

 /*Print map to screen with colours*/
 void printMap()
 {
 	for(int j=0;j<HEIGHT;j++)
 	{
 		for(int i=0;i<WIDTH;i++)
 		{
			if (map[i][j].villagerHere)
 			{
 				cout << "\033[1;35m@\033[0m";
 			}
			else
			{
	 			if(map[i][j].kind=='-')
	 			{
	 				cout << "\033[1;36m-\033[0m";
	 			}
	 			else if (map[i][j].kind=='^')
	 			{
	 				cout << "\033[1;31m^\033[0m";
	 			}
	 			else if (map[i][j].kind=='|')
	 			{
	 				cout << "\033[1;32m|\033[0m";
	 			}
	 			else if (map[i][j].kind=='c')
	 			{
	 				cout << "\033[1m@\033[0m";
	 			}
	 			else if (map[i][j].kind=='x')
	 			{
	 				map[i][j].usable++;
	 				if(map[i][j].usable>=100)
	 				{
	 					map[i][j].kind=map[i][j].origin;
	 				}
	 				cout << "x";
	 			}
	 			else
	 				cout << "\033[1m"<<map[i][j].kind<<"\033[0m";
			}
 		}
 		cout << "\n";
 	}
 	cout << "Fish: " << fish << "    Wood: " << wood << "    Food: " << food << "    Stone: " << stone << "\n";
 	return;
 }

 /*Assigning random starting point for people*/
 void initPeople()
 {
 	int x,y;
 	for(int k=0;k<POPULATION;k++)
 	{
 		do
 		{
 			x = rand() % WIDTH;
 			y = rand() % HEIGHT;
 		} while(map[x][y].villagerHere || map[x][y].kind=='-');

 		people[k].position[0]=x;
 		people[k].position[1]=y;
 		people[k].underMe=map[x][y].kind;
 		map[x][y].villagerHere=true;
		people[k].pathCoordinates = people[k].setPath();
 	}
 	return;
 }
