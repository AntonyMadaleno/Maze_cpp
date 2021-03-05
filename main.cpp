//Madaleno Antony

#include <iostream>
#include <cstdlib>
#include <time.h>

#include "Maze.h"
#include "Bot.h"

using namespace std;

int main(int argc, char **argv)
{

    srand (time(NULL));

    Maze laby(50,30);
    laby.genMaze(300);

    cout << "is connexe : " << laby.connexe() << endl;

    laby.print();

    cout << endl << "distance from (0,0) to (49,29)" << laby.getMinDistance(laby.getId(0,0), laby.getId(49,29));
    cout << endl << "raw distance from (0,0) to (49,29)" << laby.getRawDistance(laby.getId(0,0), laby.getId(49,29));

    Bot dummy0(&laby);
    dummy0.setAtRandom();

    Bot dummy1(&laby);
    dummy1.setAtRandom();

    cout << endl << "dummy0 position : (" << dummy0.getCol() << "," << dummy0.getRow() << ")";
    cout << endl << "dummy1 position : (" << dummy1.getCol() << "," << dummy1.getRow() << ")";

    cout << endl << "distance from dummy0 to dummy1 : " << laby.getMinDistance(dummy0.getPosition(), dummy1.getPosition());
    cout << endl << "raw distance from dummy0 to dummy1 : " << laby.getRawDistance(dummy0.getPosition(), dummy1.getPosition());

/**

//debug things

    for (unsigned int rw = 0; rw < 10; rw++)
    {
        for (unsigned int cl = 0; cl < 20; cl++)
        {
            cout << endl << "distance from (10,2) to (" << cl << "," << rw << ") : " << laby.getMinDistance(laby.getId(10,2), laby.getId(cl,rw));
        }
    }
**/

    return 0;
}
