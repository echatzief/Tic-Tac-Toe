#include <iostream>
#include <stdlib.h>
#define SIZE 3

using namespace std;

#ifndef __GAME__H__
#define __GAME__H__

class Game{
  public:
    char machineSymbol;
    char playerSymbol;
    char **ticArray;

    Game(char symbolM,char symbolP);
    void initArr();
    void freeMemory();
    void printArr();
    int someOneWins();
    void setElement(int row,int col);
    int isFilled(int row,int col);
    void resetArray();
};

#endif
