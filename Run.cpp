#include "Machine.h"
#include "Game.h"
#include <iostream>
#include <stdlib.h>

#define LENGTH 30
#define CONTINUE_SIZE 40
using namespace std;


char playerSymbol='X';
char machineSymbol='O';

void printMenu(Game g){
  char choosenSymbol=' ';

  for(int i=0;i<LENGTH;i++){
    cout<<"-";
  }
  cout<<endl;

  //Choose the symbol
  while(choosenSymbol!='X' && choosenSymbol!='O'){
    cout<<"Choose your symbol (X or O): ";
    cin >>choosenSymbol;
    if(choosenSymbol=='X'){
      g.playerSymbol='X';
      playerSymbol='X';
      g.machineSymbol='O';
      machineSymbol='O';
    }
    else if(choosenSymbol=='O'){
      g.playerSymbol='O';
      playerSymbol='O';
      g.machineSymbol='X';
      machineSymbol='X';
    }
  }
}

int main(){

  //Array we save some content if we want to continue
  char *wannaContinue=new char[CONTINUE_SIZE];
  int row=15,col=15;

  //We create the game
  Game fun(machineSymbol,playerSymbol);

  while(true){

    //Print the menu
    printMenu(fun);

    cout<<"PLAYER: "<<playerSymbol<<" MACHINE: "<<machineSymbol<<endl;
    //Create the machine part
    Machine mach(machineSymbol,playerSymbol);

    //Play until some one loses
    while(true){

      if(fun.someOneWins()==1){
        fun.printArr();
        cout<<"Player Wins!"<<endl;
        return 0;
      }
      else if(fun.someOneWins()==2){
        fun.printArr();
        cout<<"Machine Wins!"<<endl;
        fun.resetArray();
        return 0;
      }
      else if(fun.someOneWins()==3){
        fun.printArr();
        cout<<"No one wins!"<<endl;
        fun.resetArray();
        return 0;
      }

      do{
        cout<<"Choose row and col: ";
        cin>>row;
        cin>>col;
      }while(row>SIZE-1 || col>SIZE-1 || row <0 || col <0 || fun.isFilled(row,col));

      //Set element
      fun.setElement(row,col);
      fun.printArr();
      mach.machineThink(fun.ticArray,playerSymbol,machineSymbol);
      fun.printArr();
    }

  }

  //Free Memory
  fun.freeMemory();
}
