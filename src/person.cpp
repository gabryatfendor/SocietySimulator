#include <utilities.h>

using namespace std;

/*JOB Function*/
/*All those functions check if the person is on a spot
that it can work on. If that's true, the person starts working
and depleting resources*/
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

 /*This is a bit different from the others, it checks if there is enough wood stored.
 If true and if no village has been built, it checks a random spot near water
 and build the village here*/
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

/*TODO: this method should move the person along a path already
designed. At the moment it's just increasing x and y of the
person until it hit the map border*/
 void Person::move()
 {
   map[this->position[0]][this->position[1]].villagerHere = false;
   //move random
   if(position[0] < WIDTH-1)
    this->position[0]++;
   if(position[1] < HEIGHT-1)
    this->position[1]++;

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
