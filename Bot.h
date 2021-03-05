//Madaleno Antony

#ifndef DEF_BOT
#define DEF_BOT

#include <cstdlib>
#include <iostream>
#include <time.h>
#include "Maze.h"


class Bot
{
    public:

        //méthodes

        Bot(Maze *laby);
        void setPosition(unsigned int col, unsigned int row);
        void setAtRandom();
        unsigned int getPosition();
        unsigned int getRow();
        unsigned int getCol();
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();

    protected:

        //attribut

        Maze *env;
        unsigned int col_pos;
        unsigned int row_pos;

};

#endif // BOT
