/*Courtesy of http://code.activestate.com/recipes/577457-a-star-shortest-path-algorithm*/
#include <iomanip>
#include <queue>
#include <math.h>
#include <ctime>
#include <iostream>

#ifndef NODE_H
#define NODE_H

class Node
{
    int xPos;
    int yPos;
    int level;
    int priority;

    public:
        Node(int xp, int yp, int d, int p)
            {xPos=xp; yPos=yp; level=d; priority=p;}

        int getxPos() const;
        int getyPos() const;
        int getLevel() const;
        int getPriority() const;

        void updatePriority(const int & xDest, const int & yDest);
        void nextLevel(const int & i);
        const int & estimate(const int & xDest, const int & yDest) const;
};

bool operator<(const Node &a, const Node &b);
std::string pathFind(const int &xStart, const int &yStart, const int &xFinish, const int &yFinish);
#endif
