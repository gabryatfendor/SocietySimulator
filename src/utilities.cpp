#include <utilities.h>

using namespace std;

bool checkAround(int x, int y, char check)
{
	bool isCheckAroundMe = false;

	if(map[x-1][y].kind==check||
		 map[x][y-1].kind==check||
		 map[x][y+1].kind==check||
		 map[x+1][y].kind==check)
		 {
			 isCheckAroundMe = true;
		 }

	 return isCheckAroundMe;
}

bool checkAroundOrigin(int x, int y, char check)
{
	bool isCheckAroundMe = false;

	if(map[x-1][y].origin==check||
		 map[x][y-1].origin==check||
		 map[x][y+1].origin==check||
		 map[x+1][y].origin==check)
		 {
			 isCheckAroundMe = true;
		 }

	 return isCheckAroundMe;
}

int randBetween(int min, int max)
{
	return rand() % (max-min+1)+min;
}

tuple<int, int> findOneFree(char kind)
{
	tuple<int, int> free;
	for(int j=0;j<HEIGHT;j++)
 	{
 		for(int i=0;i<WIDTH;i++)
 		{
			if (map[i][j].kind == kind &&
				  !map[i][j].villagerAimingHere)
 			{
				free = make_tuple(i, j);
				map[i][j].villagerAimingHere = true;
				goto returnme; //ykes, but from c++ standards this seems to remain the last kind of place in which goto
											 //it's still good to use, to exit double for loop
			}
		}
	}

	returnme:
	return free;
}
