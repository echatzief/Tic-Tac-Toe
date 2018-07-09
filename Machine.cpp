#include "Machine.h"

Machine::Machine(char symbolM,char symbolP){
  //Set the symbol of the machine
  this->machineSymbol=symbolM;
  this->playerSymbol=symbolP;
}
void Machine::machineThink(char **arr,char playerSymbol,char machineSymbol){

  //If the horizontal is harmless,we go to down and thne cross
  //We decide our move depending to play passive
  if(horizontalCheck(arr,playerSymbol,machineSymbol,'P')==0){
    if(downCheck(arr,playerSymbol,machineSymbol,'P')==0){
      if(crossCheck(arr,playerSymbol,machineSymbol,'P')==0){
        //Pick the smart to win
        thinkToWin(arr,machineSymbol);
      }
    }
  }
}
int Machine::horizontalCheck(char **ticArray,char playerSymbol,char machineSymbol,char where){
  for(int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
      if(ticArray[i][j]==playerSymbol && ticArray[i][(j+1)%SIZE]==playerSymbol){
        cout<<where<<" : Horizontal: i:"<<i<<" j: "<<(j+2)%SIZE<<endl;

        if(  ticArray[i][(j+2)%SIZE]!=playerSymbol &&   ticArray[i][(j+2)%SIZE]!=machineSymbol){
          ticArray[i][(j+2)%SIZE]=machineSymbol;
          return 1;
        }
      }
    }
  }
  return 0;
}
int Machine::crossCheck(char **ticArray,char playerSymbol,char machineSymbol,char where){
  for(int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
      if(ticArray[i][j]==playerSymbol && ticArray[(i+1)%SIZE][(j+1)%SIZE]==playerSymbol){
        cout<<where<<" : cross"<<endl;
        if(   ticArray[(i+2)%SIZE][(j+2)%SIZE]!=playerSymbol &&     ticArray[(i+2)%SIZE][(j+2)%SIZE]!=machineSymbol){
          ticArray[(i+2)%SIZE][(j+2)%SIZE]=machineSymbol;
          return 1;
        }
      }
    }
  }

  //Diagonial
  if(ticArray[0][SIZE-1] ==playerSymbol &&  ticArray[1][1] ==playerSymbol){

    if(   ticArray[SIZE-1][0]!=playerSymbol &&     ticArray[SIZE-1][0]!=machineSymbol){
      ticArray[SIZE-1][0]=machineSymbol;
      return 1;
    }
  }
  else if(ticArray[SIZE-1][0] ==playerSymbol &&  ticArray[1][1] ==playerSymbol){
    if(   ticArray[0][SIZE-1]!=playerSymbol &&     ticArray[0][SIZE-1]!=machineSymbol){
      ticArray[0][SIZE-1]=machineSymbol;
      return 1;
    }
  }
  else if(ticArray[SIZE-1][0] ==playerSymbol &&  ticArray[0][SIZE-1] ==playerSymbol){
    if(  ticArray[1][1]!=playerSymbol &&     ticArray[1][1]!=machineSymbol){
      ticArray[1][1]=machineSymbol;
      return 1;
    }
  }

  return 0;
}
int Machine::downCheck(char **ticArray,char playerSymbol,char machineSymbol,char where){
  for(int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
      if(ticArray[i][j]==playerSymbol && ticArray[(i+1)%SIZE][j]==playerSymbol){
        cout<<where<<" : Down"<<endl;
        if(  ticArray[(i+2)%SIZE][j]!=playerSymbol &&   ticArray[(i+2)%SIZE][j]!=machineSymbol){
          ticArray[(i+2)%SIZE][j]=machineSymbol;
          return 1;
        }
      }
    }
  }
  return 0;
}
void Machine::thinkToWin(char **arr,char machineSymbol){
  if(horizontalCheck(arr,machineSymbol,machineSymbol,'W')==0){
    if(downCheck(arr,machineSymbol,machineSymbol,'W')==0){
      if(crossCheck(arr,machineSymbol,machineSymbol,'W')==0){
        //Pick the first available
        for(int i=0;i<SIZE;i++){
          for(int j=0;j<SIZE;j++){
            if(arr[i][j]!=playerSymbol && arr[i][j]!=machineSymbol){
              arr[i][j]=machineSymbol;
              cout<<"Random"<<endl;
              return;
            }
          }
        }

      }
    }
  }
}
