#include <utilities.h>

/*This file will have to be refactored, is a mix up of functions*/
/*Launched 1 time to initialize map checking configuration*/
void init_map()
{
	if(MAX_LAKES>0)
		set_water();
	if(MAX_WOODS>0)
		set_wood();
	if(MAX_MOUNTAINS>0)
		set_mountain();
    if(MAP_ISLAND)
        set_island();
       return;
}

/*At the moment there are 4 kind of terrain:
    a- plain  .
    b- water     -
    c- mountain ^
    d- wood    |
    small groups of the same type are created following DEFINE in configuration.h*/

void set_water()
{
    int lakes = rand() % MAX_LAKES + 1;
    for(int i=0;i<lakes;i++)
    {
        int ray = rand() % MAX_LAKES_RAY + 1;
        int x = rand() % ((WIDTH-(ray-1))-ray);
        int y = rand() % ((HEIGHT-(ray-1))-ray);
        for(int j=x-ray;j<x+ray;j++)
        {
            for(int k=y-ray;k<y+ray;k++)
            {
                map[j][k].kind='-';
                map[j][k].origin='-';
                map[j][k].walkable=false;
            }
        }
    }
    return;
}

void set_wood()
{
	int woods = rand() % MAX_WOODS + 3;
	
	for(int i=0;i<woods;i++)
	{
		/*set ray*/
		int ray = rand() % MAX_WOODS_RAY + 1;
		/*choose center*/
		int x = rand() % ((WIDTH-(ray-1))-ray)+ray;
		int y = rand() % ((HEIGHT-(ray-1))-ray)+ray;
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

void set_mountain()
{
	int mountains = rand() % MAX_MOUNTAINS + 1;
	for(int i=0;i<mountains;i++)
	{
		/*set ray*/
		int ray = rand() % MAX_MOUNTAINS_RAY + 1;
		/*choose center*/
		int x = rand() % ((WIDTH-(ray-1))-ray)+ray;
		int y = rand() % ((HEIGHT-(ray-1))-ray)+ray;
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

void set_island()
{
	if(MAP_ISLAND)
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
void print_map()
{
	for(int j=0;j<HEIGHT;j++)
	{
		for(int i=0;i<WIDTH;i++)
		{
			if(map[i][j].kind=='-')
			{
				std::cout << "\033[1;36m-\033[0m";
			}
			else if (map[i][j].kind=='^')
			{
				std::cout << "\033[1;31m^\033[0m";
			}
			else if (map[i][j].kind=='|')
			{
				std::cout << "\033[1;32m|\033[0m";
			}
			else if (map[i][j].kind=='@')
			{
				std::cout << "\033[1;35m@\033[0m";
			}
			else if (map[i][j].kind=='c')
			{
				std::cout << "\033[1m@\033[0m";
			}
			else if (map[i][j].kind=='x')
			{
				map[i][j].usable++;
				if(map[i][j].usable>=100)
				{
					map[i][j].kind=map[i][j].origin;
				}
				std::cout << "x";
			}
			else
				std::cout << "\033[1m"<<map[i][j].kind<<"\033[0m";
		}
		std::cout << "\n";
	}
	std::cout << "Fish: " << fish << "    Wood: " << wood << "    Food: " << food << "    Stone: " << stone << "\n";
	return;
}

/*Assigning random starting point for people*/
void init_people()
{
	int x,y;
	for(int k=0;k<POPULATION;k++)
	{
		do
		{
			x = rand() % WIDTH;
			y = rand() % HEIGHT;
		} while(map[x][y].kind=='@' || map[x][y].kind=='-');
			
		people[k].position[0]=x;
		people[k].position[1]=y;
		people[k].underme=map[x][y].kind;
		map[x][y].kind='@';
	}
	return;
}

/*Launched every timestep*/
void update()
{
	print_map();
	int k,x,y;
	for(int i=0;i<POPULATION;i++)
	{
		if(people[i].moving==false)
		{
			int destX, destY;
			/*choose destination randomly, should be implemented a reason for moving*/
			do
			{
				destX = rand() % WIDTH;
				destY = rand() % HEIGHT;
			}while(map[destX][destY].walkable==false);
			
			
			people[i].moving=true;
		}
		
		else
		{
			map[people[i].position[0]][people[i].position[1]].kind = people[i].underme;
			map[people[i].position[0]][people[i].position[1]].walkable = true;
			//draw person on map
			map[people[i].position[0]][people[i].position[1]].kind='@';
			map[people[i].position[0]][people[i].position[1]].walkable = false;
		}
	}
	
	if(AUTO)
		sleep(SPEED);
	else
		getchar();
	system("clear");
	return;
}

