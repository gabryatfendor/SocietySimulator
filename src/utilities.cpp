#include <utilities.h>

/*Lanciata 1 volta per inizializzare la mappa*/
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

/*Al momento ci sono 4 tipi di terreno:
    a- pianura  .
    b- mare     -
    c- montagna ^
    d- bosco    |
    vengono creati piccoli gruppi dello stesso tipo
    seguendo i define in configuration.h*/

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
		/*scegli il raggio*/
		int ray = rand() % MAX_WOODS_RAY + 1;
		/*scegli il centro*/
		int x = rand() % ((WIDTH-(ray-1))-ray)+ray;
		int y = rand() % ((HEIGHT-(ray-1))-ray)+ray;
		/*mappo*/
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
		/*scegli il raggio*/
		int ray = rand() % MAX_MOUNTAINS_RAY + 1;
		/*scegli il centro*/
		int x = rand() % ((WIDTH-(ray-1))-ray)+ray;
		int y = rand() % ((HEIGHT-(ray-1))-ray)+ray;
		/*mappo*/
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
 
/*Stampa la mappa a schermo con i colori*/
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

/*-------------SOCIAL-------------------
  * Parte sociale, per ora fa solo muovere
  * gli omini, ma andra' implementato ogni 
  * aspetto delle relazioni interpersonali
  * e interculturali, oltre ai vari lavori 
  * -------------------------------------*/
  
/*Assegnazione random dei punti di partenza delle varie persone*/

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

/*Lanciata ogni volta che premi un tasto o in auto*/
void update()
{
	print_map();//stampo
	int k,x,y;
	for(int i=0;i<POPULATION;i++)
	{
		if(people[i].moving==false && people[i].tested==false)
		{
			int destX, destY;
			//choose destination
			do
			{
				destX = rand() % WIDTH;
				destY = rand() % HEIGHT;
			}while(map[destX][destY].walkable==false);
			
			people[i].destination[0]=destX;
			people[i].destination[1]=destY;
			map[destX][destY].kind='X';
			if(PATH_DEBUG)
				std::cout << "Destination for " << i+1 << " set to " << people[i].destination[0] << " , " << people[i].destination[1] << std::endl; 
			tellPathToPerson(i);
			people[i].moving=true;
		}
		
		else if(people[i].position[0]==people[i].destination[0] && people[i].position[1]==people[i].destination[1])
		{
			people[i].tested=true;
			people[i].moving=false;
		}
		
		else if(people[i].moving==true && people[i].tested==false)
		{

			//redo A* 
			if(PATH_DEBUG)
				std::cout << "REDO A* FOR " << i+1 << std::endl;
			tellPathToPerson(i);
			map[people[i].position[0]][people[i].position[1]].kind = people[i].underme;
			map[people[i].position[0]][people[i].position[1]].walkable = true;
			//scrivo le nuove posizioni nella struct
			people[i].position[0]=people[i].path[people[i].pathIndex];
			people[i].position[1]=people[i].path[people[i].pathIndex+1];	
			people[i].underme=map[people[i].path[people[i].pathIndex]][people[i].path[people[i].pathIndex+1]].kind;
			//disegno l'omino sulla mappa
			map[people[i].position[0]][people[i].position[1]].kind='@';
			map[people[i].position[0]][people[i].position[1]].walkable = false;
			//aggiorno indexPath
			people[i].pathIndex=people[i].pathIndex+2;
		}
	}
	
	if(AUTO)
		sleep(SPEED);
	else
		getchar();
	system("clear");
	return;
}


void tellPathToPerson(int personIndex)
{
    std::string completePath;
    int tempX = people[personIndex].position[0];
    int tempY = people[personIndex].position[1];
    int j = 0;
    people[personIndex].pathIndex=0;
    //1 in basso a dx
    //2 in basso
    //3 in basso a sx ecc ecc
    completePath=pathFind(people[personIndex].position[0],people[personIndex].position[1],people[personIndex].destination[0],people[personIndex].destination[1]);
    if(PATH_DEBUG)
    {
		std::cout << "Path returned from A* for " <<  personIndex+1 << " is " << completePath << std::endl;
		std::cout << "Saved path for " << personIndex+1 << " with destination " << people[personIndex].destination[0]  << " , " << people[personIndex].position[1] << " is " << std::endl;
	}
    for(int i=0;i<completePath.length();i++)
    {
		int switcher = completePath.at(i) - '0';
        //trasferisco la path calcolata in quella che l'omino deve fare, ma tradotta in coppie di coordinate
        switch(completePath.at(i) - '0')
        {
			case 0:
				j=j-2;
				break;
            case 1:
               people[personIndex].path[j] = tempX+1;
               people[personIndex].path[j+1] = tempY+1;
               tempX++;
               tempY++;
               break;
            case 2:
                people[personIndex].path[j] = tempX;
                people[personIndex].path[j+1] = tempY+1;
                tempY++;
                break;
            case 3:
                people[personIndex].path[j] = tempX-1;
                people[personIndex].path[j+1] = tempY+1;
                tempX--;
                tempY++;
                break;
            case 4:
                people[personIndex].path[j] = tempX-1;
                people[personIndex].path[j+1] = tempY;
                tempX--;
                break;
            case 5:
                people[personIndex].path[j] = tempX-1;
                people[personIndex].path[j+1] = tempY-1;
                tempX--;
                tempY--;
                break;
            case 6:
                people[personIndex].path[j] = tempX;
                people[personIndex].path[j+1] = tempY-1;
                tempY--;
                break;
            case 7:
                people[personIndex].path[j] = tempX+1;
                people[personIndex].path[j+1] = tempY-1;
                tempX++;
                tempY--;
                break;
            case 8:
                people[personIndex].path[j] = tempX+1;
                people[personIndex].path[j+1] = tempY;
                tempX++;
                break;
            default:
                break;
        }
        if(PATH_DEBUG)
			std::cout << people[personIndex].path[j] << " , " << people[personIndex].path[j+1] << ";";
        j=j+2;
        
    }
    return;
}

