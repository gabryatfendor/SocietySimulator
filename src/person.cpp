#include <utilities.h>

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
	 if(this->underme=='|')
	 {
		 int x = this->position[0];
		 int y = this->position[1];
		 this->working = true;
		 wood++;
		 map[x][y].usable-=25;
		 if(map[x][y].usable==0)
		 {
			 this->working=false;
			 this->underme='x';
			 map[x][y].isregenerating=true;
		 }
	 }
 }

 void Person::farming()
 {
	 if(this->underme=='.')
	 {
		 int x = this->position[0];
		 int y = this->position[1];
		 this->working = true;
		 food++;
		 map[x][y].usable-=25;
		 if(map[x][y].usable==0)
		 {
			 this->working=false;
			 this->underme='x';
			 map[x][y].isregenerating=true;
		 }
	 }
 }

 void Person::mining()
 {
	 if(this->underme=='^')
	 {
		 int x = this->position[0];
		 int y = this->position[1];
		 this->working = true;
		 stone++;
		 map[x][y].usable-=25;
		 if(map[x][y].usable==0)
		 {
			 this->working=false;
			 this->underme='x';
			 map[x][y].isregenerating=true;
		 }
	 }
 }

 /*This is a bit different from the others, it checks if there is enough wood stored.
 If true and if no village has been built, it checks a random spot near water
 and build the village here*/
 void Person::buildvillage()
 {
	 int k,j;
	 if(wood>=200)
	 {
		 //choose where to build, possibly near water
		 if(cfg.map_island==0)
		 {
			 j=0;
			 k=0;
		 }
		 else
		 {
			 j=rand() % HEIGHT+1;
			 k=rand() % WIDTH+1;
		 }

		 for(;j<HEIGHT;j++)
		 {
			 for(;k<WIDTH;k++)
			 {
				 if(map[k][j].origin=='.' && villagebuilded==false)
				 {
					 if(checkAroundOrigin(k, j, '-'))
					 {
						 //set village here
						 villagebuilded=true;
						 wood=wood-200;
						 map[k][j].kind='V';
					 }
				 }
			 }
		 }
	 }
 }
