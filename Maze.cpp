//Madaleno Antony

#include "Maze.h"
#include <cstdlib>
#include <iostream>
#include <time.h>

char AFF_VIDE = ' ';
char AFF_MUR = '#';
char AFF_BORD = '0';
char AFF_UNCONNECTED = '!';

unsigned int NB_COL;
unsigned int NB_ROW;
unsigned int Top;

char* Grid;
int* Pile;

Maze::Maze(unsigned int col, unsigned int row)
{

	srand (time(NULL));

    NB_COL = col;
    NB_ROW = row;
    Top = 0;

    Pile = (int*) calloc(NB_ROW*NB_COL, sizeof(int));
    Grid = (char*) calloc(NB_ROW*NB_COL, sizeof(char));

}

void Maze::push(int id)
{
	Pile[Top] = id;
    Top++;
}

int Maze::pop()
{
	int ret = Pile[Top - 1];
    Pile[Top - 1] = -1;

    Top--;

    return ret;
}

int Maze::getId(unsigned int col, unsigned int row)
{
	return col + (NB_COL * row);
}

unsigned int Maze::getRow(int id)
{
	return id / NB_COL;
}

unsigned int Maze::getCol(int id)
{
	return id % NB_COL;
}

void Maze::setStateAtId(int id, char state)
{
	Grid[id] = state;
}

void Maze::setStateAt(unsigned int col,unsigned int row, char state)
{
	setStateAtId(getId(col, row), state);
}

char Maze::getStateAtId(int id)
{
	return Grid[id];
}

char Maze::getStateAt(unsigned int col,unsigned int row)
{
	return getStateAtId(getId(col, row));
}

unsigned int Maze::countState(char state)
{
	unsigned int cnt = 0;

    for (unsigned int i = 0; i < NB_COL*NB_ROW; i++)
    {

        if (Grid[i] == state)
        {
            cnt++;
        }//end if

    }//end for

    return cnt;
}

int Maze::getUpperId(int id)
{

	if (getRow(id) > 0)
	{
		return getId(getCol(id), getRow(id)-1);
	}//end if

	return -1;

}

int Maze::getLowerId(int id)
{

	if (getRow(id) < NB_ROW-1)
	{
		return getId(getCol(id), getRow(id)+1);
	}//end if

	return -1;


}

int Maze::getRightId(int id)
{

	if (getCol(id) < NB_COL-1)
	{
		return getId(getCol(id)+1, getRow(id));
	}//end if

	return -1;

}

int Maze::getLeftId(int id)
{

	if (getCol(id) > 0)
	{
		return getId(getCol(id)-1, getRow(id));
	}//end if

	return -1;

}

unsigned int Maze::getColsCount()
{
	return NB_COL;
}

unsigned int Maze::getRowsCount()
{
	return NB_ROW;
}

unsigned int Maze::getRawDistance(int from, int to)
{
	return abs(getCol(to) - getCol(from)) + abs(getRow(to) - getRow(from));
}

int Maze::getMinDistance(int from, int to)
{

	int* distGrid;
	distGrid = (int*) calloc(NB_ROW*NB_COL, sizeof(int));

	int* openset;
	openset = (int*) calloc(NB_ROW*NB_COL, sizeof(int));

	unsigned int maxI = 0;

	int* closeset;
	closeset = (int*) calloc(NB_ROW*NB_COL, sizeof(int));

	unsigned int maxC = 0;

	for (unsigned int i = 0; i < NB_ROW*NB_COL; i++)
	{

		distGrid[i] = -1; //we set all cells to -1 (undifined)
		openset[i] = -1;
		closeset[i] = -1;

	}//end for

	openset[0] = from;
	maxI++;
	distGrid[from] = 0;

	while (distGrid[to] == -1)
	{

        int current = -1;
		unsigned int temp_index = 0;

		for (unsigned int i = 0; i < NB_ROW*NB_COL; i++)
		{

			if (openset[i] != -1 && current == -1 && distGrid[openset[i]] > -1)
			{
				current = openset[i];
				temp_index = i;
			}

			if (openset[i] != -1 && (distGrid[current] > distGrid[openset[i]] || openset[i] == to) )
			{

				current = openset[i];
				temp_index = i;

			}//end if

		}//end for


		if (getLowerId(current) != -1 && getStateAtId(getLowerId(current)) == 0)
        {
            unsigned int x = getLowerId(current);

            if (distGrid[x] > distGrid[current]+1 || distGrid[x] == -1)
            {

            	distGrid[x] = distGrid[current] + 1;
            	openset[maxI] = x;
            	maxI++;

            }//end if

        }//end if

        if (getLeftId(current) != -1 && getStateAtId(getLeftId(current))== 0)
        {
            unsigned int x = getLeftId(current);

            if (distGrid[x] > distGrid[current]+1 || distGrid[x] == -1)
            {

            	distGrid[x] = distGrid[current] + 1;
            	openset[maxI] = x;
            	maxI++;

            }//end if

        }//end if

        if (getUpperId(current) != -1 && getStateAtId(getUpperId(current)) == 0)
        {
            unsigned int x = getUpperId(current);

            if (distGrid[x] > distGrid[current]+1 || distGrid[x] == -1)
            {

            	distGrid[x] = distGrid[current] + 1;
            	openset[maxI] = x;
            	maxI++;

            }//end if

        }//end if

        if (getRightId(current) != -1 && getStateAtId(getRightId(current)) == 0)
        {
            unsigned int x = getRightId(current);

            if (distGrid[x] > distGrid[current]+1 || distGrid[x] == -1)
            {

            	distGrid[x] = distGrid[current] + 1;
            	openset[maxI] = x;
            	maxI++;

            }//end if

        }//end if

        closeset[maxC] = current;
        maxC++;
        openset[temp_index] = -1;



	}//end while


	int r = distGrid[to];

	//to avoid memory leaks
	free(distGrid);
    free(openset);
    free(closeset);

	return r;

}

bool Maze::connexe()
{

    unsigned int cnt = 0;
    unsigned int emp = 1;

    unsigned int cell = 0; //la case d'id 0 doit être vide !

    for (unsigned int i=1; i < NB_ROW*NB_COL; i++)
    {

        if (Grid[i] == 0)
        {
            emp++;
            Grid[i] = 2;
        }//end if

    }//end for

    if (getStateAtId(getLowerId(0)) == 2)
    {
        push(getLowerId(0));
    }//end if

    if (getStateAtId(getRightId(0)) == 2)
    {
        push(getRightId(0));
    }//end if

    while (Top != 0) //temps que la pile n'est pas vide
    {
        cell = pop();

        setStateAtId(cell, 0);

        if (cell >= 0 && getLowerId(cell) != -1 && getStateAtId(getLowerId(cell)) == 2)
        {
            push(getLowerId(cell));
        }//end if

        if (cell >= 0 && getLeftId(cell) != -1 && getStateAtId(getLeftId(cell))== 2)
        {
            push(getLeftId(cell));
        }//end if

        if (cell >= 0 && getUpperId(cell) != -1 && getStateAtId(getUpperId(cell)) == 2)
        {
            push(getUpperId(cell));
        }//end if

        if (cell >= 0 && getRightId(cell) != -1 && getStateAtId(getRightId(cell)) == 2)
        {
            push(getRightId(cell));
        }//end if


    }//end while

    for (unsigned int i=1; i < NB_ROW*NB_COL; i++)
    {

        if (Grid[i] == 2)
        {
            cnt++;
        }//end if

    }//end for

    if (cnt == 0) {
        return 1;
    }

    return 0;

}

void Maze::genMaze(unsigned int k)
{

	unsigned int blockers = 0;
    unsigned int loopCount = 0;
    unsigned int rn;

    while (blockers != (NB_COL*NB_ROW) - k && loopCount < (NB_COL*NB_ROW)*100 && loopCount < 65536)
    {

        loopCount++;
        rn = 1 + rand()%(NB_COL*NB_ROW - 2);

        if (getStateAtId(rn) != 1)
        {
            blockers++;
            setStateAtId(rn, 1);
        }//end if

        if (connexe() != 1)
        {
            blockers--;
            setStateAtId(rn, 0);
        }//end if

    }//end while

}

void Maze::print()
{

    for (unsigned int i=0; i < 1 + NB_COL; i++)
    {
        std::cout << AFF_BORD;
    }//end for


    for (unsigned int i=0; i < NB_ROW*NB_COL; i++)
    {

        if (i % NB_COL == 0)
        {
            printf("%c\n%c", AFF_BORD, AFF_BORD);
        }//end if

        if ( getStateAt(getCol(i), getRow(i)) == 1)
        {
            printf("%c", AFF_MUR);
        }//end if

        if ( getStateAt(getCol(i), getRow(i)) == 2)
        {
            printf("%c", AFF_UNCONNECTED);
        }//end if

        if ( getStateAt(getCol(i), getRow(i)) == 0)
        {
            printf("%c", AFF_VIDE);
        }//end if

    }//end for

    printf("%c\n", AFF_BORD);

    for (unsigned int i=0; i < 2 + NB_COL; i++)
    {
        printf("%c", AFF_BORD);
    }//end for

}

