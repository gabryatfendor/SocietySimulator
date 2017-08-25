#include <utilities.h>

/*Check if a certain char is present at any of the 4 cardinal points*/
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

/*Same as before, but check origin instead of kind*/
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
