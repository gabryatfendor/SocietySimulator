#include <utilities.h>

Configuration cfg;
Terrain map[WIDTH][HEIGHT];
Person people[POPULATION];
bool villageBuilded=false;
int wood=0;
int fish=0;
int food=0;
int stone=0;

int main()
{
    srand(time(NULL));
    initMap();
    initPeople();
    while(true)
    {
        update();
    }

    return 0;
}
