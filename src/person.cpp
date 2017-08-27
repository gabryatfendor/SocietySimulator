#include <utilities.h>

using namespace std;

void Person::fishing()
{
 if(checkAround(this->position[0],this->position[1],'-'))
 {
	 this->working = true;
	 fish++;
 }
}

void Person::woodcutting()
{
 if(this->underMe=='|')
 {
	 int x = this->position[0];
	 int y = this->position[1];
	 this->working = true;
	 wood++;
	 map[x][y].usable-=25;
	 if(map[x][y].usable<=0)
	 {
		 this->working=false;
		 this->underMe='x';
		 map[x][y].isRegenerating=true;
	 }
 }
}

void Person::farming()
{
 if(this->underMe=='.')
 {
	 int x = this->position[0];
	 int y = this->position[1];
	 this->working = true;
	 food++;
	 map[x][y].usable-=25;
	 if(map[x][y].usable<=0)
	 {
		 this->working=false;
		 this->underMe='x';
		 map[x][y].isRegenerating=true;
	 }
 }
}

void Person::mining()
{
 if(this->underMe=='^')
 {
    int x = this->position[0];
    int y = this->position[1];
		this->working = true;
		stone++;
		map[x][y].usable-=25;
		if(map[x][y].usable<=0)
		{
		 this->working=false;
		 this->underMe='x';
		 map[x][y].isRegenerating=true;
		}
  }
}

void Person::buildVillage()
{
 int k=0, j=0;
 //choose where to build, possibly near water
 if(cfg.mapIsland)
 {
   j=rand() % HEIGHT+1;
	 k=rand() % WIDTH+1;
 }

	 for(;j<HEIGHT;j++)
 {
	 for(;k<WIDTH;k++)
	 {
		 if(map[k][j].origin=='.' && !villageBuilded)
		 {
			 if(checkAroundOrigin(k, j, '-'))
			 {
				 //set village here
				 villageBuilded=true;
				 wood-=200;
				 map[k][j].kind='V';
			 }
		 }
	 }
 }
}

void Person::move()
{
 map[this->position[0]][this->position[1]].villagerHere = false;
 //move along the path
 //if we have an element in the path
 if(!this->pathCoordinates.empty())
 {
   this->position[0] = get<0>(this->pathCoordinates.front());
   this->position[1] = get<1>(this->pathCoordinates.front());
   //remove first element
   this->pathCoordinates.erase (this->pathCoordinates.begin());
 }

 this->underMe = map[this->position[0]][this->position[1]].kind;
 map[this->position[0]][this->position[1]].villagerHere = true;
}

vector<tuple<int, int>> Person::setPath()
{
 vector<tuple<int, int> > path;

 path.emplace_back(0, 0);
 path.emplace_back(1, 1);
 path.emplace_back(2, 2);

 return path;
}
