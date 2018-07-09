#include "Game.h"

Game::Game(char symbolM,char symbolP){
  this->machineSymbol=symbolM;
  this->playerSymbol=symbolP;

  //Memory allocation for array
  initArr();
}
void Game::initArr(){
  //Initialize the ticArray
  this->ticArray=new char*[SIZE];
  if(this->ticArray==NULL){
    cout<<"Memory allocation failed."<<endl;
    exit(1);
  }

  //Initialize the columns
  for(int i=0;i<SIZE;i++){
    this->ticArray[i]=new char[SIZE];
    if(this->ticArray[i] == NULL) {
      cout < "Memory allocation error!\n";
      exit(1);
    }
  }


  //Initialize with 0
  for(int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
      this->ticArray[i][j]='\0';
    }
  }
}
void Game::freeMemory(){
  delete this->ticArray;
}
void Game::printArr(){
  for(int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
      if(this->ticArray[i][j]=='\0'){
        cout<<"| ";
      }
      else{
        cout <<"|"<<this->ticArray[i][j];
      }
    }
    cout<<endl;
  }
}
int Game::someOneWins(){

  int howMuchEmpty=0;

  for(int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
      //We create if we see one symbol at every point
      if(this->ticArray[i][j]==this->playerSymbol || this->ticArray[i][j]==this->machineSymbol){
        howMuchEmpty++;
      }

    }
  }

  if(howMuchEmpty==SIZE*SIZE){
    return 3;
  }


  int playerWins=0;
  int machineWins=0;

  //We check Horizontal
  for(int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
      //We create if we see one symbol at every point
      if(this->ticArray[i][j]==this->playerSymbol){
        playerWins++;
      }
      else if(this->ticArray[i][j]==this->machineSymbol){
        machineWins++;
      }

    }


      //Player Wins return 1
      if(playerWins==SIZE){
        cout<<"Horizontal Win: "<<playerWins<<endl;
        return 1;
      }
      else if(machineWins==SIZE){
        return 2;
      }

    playerWins=0;
    machineWins=0;
  }


  //Initialize the variables
  playerWins=0;
  machineWins=0;

  //We check Down
  for(int j=0;j<SIZE;j++){
    for(int i=0;i<SIZE;i++){
      //We create if we see one symbol at every point
      if(this->ticArray[i][j]==this->playerSymbol){
        playerWins++;
      }
      else if(this->ticArray[i][j]==this->machineSymbol){
        machineWins++;
      }

    }

    //Player Wins return 1
    if(playerWins==SIZE){
      cout<<"Down Win"<<endl;
      return 1;
    }
    else if(machineWins==SIZE){
      return 2;
    }

    playerWins=0;
    machineWins=0;
  }

  return 0;
}
void Game::setElement(int row,int col){
  this->ticArray[row][col]=this->playerSymbol;
}
int Game::isFilled(int row,int col){
  if(this->ticArray[row][col]==playerSymbol || this->ticArray[row][col]==machineSymbol){
    return 1;
  }
  return 0;
}

void Game::resetArray(){
  //Initialize with 0
  for(int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
      this->ticArray[i][j]='\0';
    }
  }
}
