#include <person.h>
#include <utilities.h>
/*FUNZIONI LAVORO*/
 
 void Person::fishing(int i)
 {
	 int x = people[i].position[0];
	 int y = people[i].position[1];
	 
	 if(map[x-1][y].kind=='-'||map[x][y-1].kind=='-'||map[x][y+1].kind=='-'||map[x+1][y].kind=='-')
	 {
		 people[i].working = true;
		 fish++;
	 }
 }
 
 void Person::woodcutting(int i)
 {	 
	 if(people[i].underme=='|')
	 {
		 int x = people[i].position[0];
		 int y = people[i].position[1];
		 people[i].working = true;
		 wood++;
		 map[x][y].usable=map[x][y].usable-25;
		 if(map[x][y].usable==0)
		 {
			 people[i].working=false;
			 people[i].underme='x';
			 map[x][y].isregenerating=true;
		 }
	 }
 }
 
 void Person::farming(int i)
 {
	 if(people[i].underme=='.')
	 {
		 int x = people[i].position[0];
		 int y = people[i].position[1];
		 people[i].working = true;
		 food++;
		 map[x][y].usable=map[x][y].usable-25;
		 if(map[x][y].usable==0)
		 {
			 people[i].working=false;
			 people[i].underme='x';
			 map[x][y].isregenerating=true;
		 }
	 }
 }
 
 void Person::mining(int i)
 {
	 if(people[i].underme=='^')
	 {
		 int x = people[i].position[0];
		 int y = people[i].position[1];
		 people[i].working = true;
		 stone++;
		 map[x][y].usable=map[x][y].usable-25;
		 if(map[x][y].usable==0)
		 {
			 people[i].working=false;
			 people[i].underme='x';
			 map[x][y].isregenerating=true;
		 }
	 }
 }
 
 void Person::buildvillage(int i)
 {
	 int k,j;
	 if(wood>=200)
	 {
		 //choose where to build, possibly near water
		 if(MAP_ISLAND==0)
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
					 if(map[k-1][j].origin=='-'||map[k][j-1].origin=='-'||map[k][j+1].origin=='-'||map[k+1][j].origin=='-')
					 {
						 //set village here
						 villagebuilded=true;
						 wood=wood-200;
						 map[k][j].kind='V';
					 }
				 }
			 }
		 }
		 if(villagebuilded==false)
		 {
			 for(int j=0;j<HEIGHT;j++)
			 {
				 for(int i=0;i<WIDTH;i++)
				 {
					 if(map[i][j].origin=='.' && villagebuilded==false)
					 {
						 if(map[i-1][j].origin=='-'||map[i][j-1].origin=='-'||map[i][j+1].origin=='-'||map[i+1][j].origin=='-')
						 {
							 //set village here
							 villagebuilded=true;
							 wood=wood-200;
							 map[i][j].kind='V';
						 }
					 }
				 }
			 }
		 }
	 }
 }
