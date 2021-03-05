//Madaleno Antony

#ifndef DEF_MAZE
#define DEF_MAZE

#include <cstdlib>
#include <iostream>
#include <time.h>


class Maze
{
    public:

        //m�thodes

        Maze(unsigned int col, unsigned int row);//constructeur
    	void push(int id);
    	int pop();
        void genMaze(unsigned int k); //g�n�re un labyrinthe avec environ K cases blanche
        void print();
        void setStateAt(unsigned int col,unsigned int row, char state); //change l'�tat de la cellule point� par l'�tat donn�
        void setStateAtId(int id, char state); //change l'�tat de la cellule point� par l'�tat donn�
        bool connexe(); //renvoi 0 ou 1 selon si le laby est connexe ou non
        unsigned int countState(char state); //renvoi le nombre de cellule � l'�tat indiqu�
        char getStateAt(unsigned int col,unsigned int row); //renvoi l'�tat de la cellule point�
        char getStateAtId(int id); //renvoi l'�tat de la cellule point�
        int getId(unsigned int col, unsigned int row); //renvoi l'id de la cellule point�
        unsigned int getRow(int id);
        unsigned int getCol(int id);
        int getUpperId(int id); //renvoi l'id de la cellule du dessus
        int getLowerId(int id); //renvoi l'id de la cellule du dessous
        int getRightId(int id); //renvoi l'id de la cellule de droite
        int getLeftId(int id); //renvoi l'id de la cellule de gauche
        unsigned int getColsCount(); //return number of column
        unsigned int getRowsCount(); //return number of raw
        unsigned int getRawDistance(int from, int to); //raw distance (manathan)
        int getMinDistance(int from, int to); //djikastra algo

    private:

        //attribut

        unsigned int NB_COL;
        unsigned int NB_ROW;
        unsigned int Top;

        char* Grid;
        int* Pile;

};

#endif // MAZE_H
