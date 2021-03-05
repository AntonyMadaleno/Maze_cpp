//Madaleno Antony

#include "Bot.h"
#include <cstdlib>
#include <iostream>
#include <time.h>

Maze *env;
unsigned int col_pos;
unsigned int row_pos;

Bot::Bot(Maze *laby)
{
    env = laby;
}

void Bot::setPosition(unsigned int col, unsigned int row)
{
    if ((*env).getStateAt(col, row) == 0)
    {
        col_pos = col;
        row_pos = row;
    }
    else
    {
        printf("\nerreur la cellule selectionner est bloquer !\n");
    }
}

void Bot::setAtRandom()
{

    unsigned int col;
    unsigned int row;

	do
	{
		col = rand()%(*env).getColsCount();
		row = rand()%(*env).getRowsCount();
	} while ((*env).getStateAt(col, row) != 0);

	(*this).setPosition(col, row);

}

unsigned int Bot::getPosition()
{
	return (*env).getId(col_pos, row_pos);
}

unsigned int Bot::getRow()
{
	return row_pos;
}

unsigned int Bot::getCol()
{
	return col_pos;
}

void Bot::moveLeft()
{
	(*this).setPosition(col_pos -1, row_pos);
}

void Bot::moveRight()
{
	(*this).setPosition(col_pos +1, row_pos);
}

void Bot::moveDown()
{
	(*this).setPosition(col_pos, row_pos +1);
}

void Bot::moveUp()
{
	(*this).setPosition(col_pos, row_pos +1);
}
