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
     map[x][y].kind = 'x';
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
     map[x][y].kind = 'x';
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
     map[x][y].kind = 'x';
		}
  }
}

void Person::move()
{
 map[this->position[0]][this->position[1]].villagerHere = false;
 //move along the path
 //if we don't have a path we create it
 if(this->pathCoordinates.empty())
 {
   cout << "Arrived, looking for another path" << endl;
   this->pathCoordinates = this->setPath();
 }
 this->position[0] = get<0>(this->pathCoordinates.front());
 this->position[1] = get<1>(this->pathCoordinates.front());
 //remove first element
 this->pathCoordinates.erase (this->pathCoordinates.begin());

 this->underMe = map[this->position[0]][this->position[1]].kind;
 map[this->position[0]][this->position[1]].villagerHere = true;
}

vector<tuple<int, int>> Person::setPath()
{
 vector<tuple<int, int> > path;
 tuple<int, int> objective = findOneFree(this->preferredTerrain);

 //at the moment, since everything is walkable, move right/left until
 //pos[x] is equal to objective one, then move straight to objective
 int x = this->position[0];
 int y = this->position[1];
 int objectiveX = get<0>(objective);
 int objectiveY = get<1>(objective);
 while(x != objectiveX)
 {
   if(x < objectiveX)
    x++;
   else
    x--;
   path.emplace_back(x,y);
 }
 while(y != objectiveY)
 {
   if(y < objectiveY)
    y++;
   else
    y--;
   path.emplace_back(x,y);
 }

 if(path.empty())
  path.emplace_back(this->position[0], this->position[1]);
 return path;
}

char Person::setPreferredTerrain()
{
  char terrain;
  switch(this->sector)
  {
    case 0:
      terrain = '|';
      break;
    case 1:
      terrain = '.';
      break;
    case 2:
      terrain = '-';
      break;
    case 3:
      terrain = '^';
      break;
    default:
      break;
  }

  return terrain;
}

void Person::work()
{
  switch(this->sector)
  {
    case 0:
      this->woodcutting();
      break;
    case 1:
      this->farming();
      break;
    case 2:
      this->fishing();
      break;
    case 3:
      this->mining();
      break;
    default:
      break;
  }
  return;
}
