#include <utilities.h>

Configuration cfg;
Terrain map[WIDTH][HEIGHT];
Person people[POPULATION];
bool villagebuilded=false;
int wood=0;
int fish=0;
int food=0;
int stone=0;

int main()
{
    srand(time(NULL));
    init_map();
    init_people();
    while(true)
    {
        update();
    }

    return 0;
}
