#define SIZE 3
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#ifndef MACHINE_H__
#define MACHINE_H__

class Machine{
  public:
    char machineSymbol;
    char playerSymbol;

    //Constructor
    Machine(char symbolM,char symbolP);
    void machineThink(char **ticArray,char playerSymbol,char machineSymbol);
    int horizontalCheck(char **ticArray,char playerSymbol,char machineSymbol,char where);
    int crossCheck(char **ticArray,char playerSymbol,char machineSymbol,char where);
    int downCheck(char **ticArray,char playerSymbol,char machineSymbol,char where);
    void thinkToWin(char **arr,char machineSymbol);
};

#endif
