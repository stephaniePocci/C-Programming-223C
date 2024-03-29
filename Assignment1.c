#include <stdio.h>
#include <string.h>
/*
Instructions:
Write a program that simulates Tic-Tac-Toe
- Assume all normal vals
- If all spaces are fileld and no player has a match the game results in "Cats Game"
- Space cannot be selected if it is occupied

Start by using a 2D array of chars
Initialize array to char of "blank space"
- will make assignment easier

P1 & P2 should use same code
*/

// display the next player who is playing
void displayPlayerTurn(int playerTurn) {
  if(playerTurn == 1) {
    printf("Player %d turn 'X'\n", playerTurn);
  } else if(playerTurn == 2) {
    printf("Player %d turn 'O'\n", playerTurn);
  }
}

//function to display current board
void display(char arr[3][3]) {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      printf("%c", arr[i][j]);
      if(j != 2) {
        printf("|");
      }
    }
    printf("\n");
    if(i != 2) {
      for(int j = 0; j < 5; j++) {
        printf("-");
      }
      printf("\n");
    }
  }

}

//changes the turn to the next player
int changeTurn(int playerTurn) {
  if(playerTurn == 1) {
    playerTurn = 2;
  } else if(playerTurn == 2) {
    playerTurn = 1;
  }
  return playerTurn;
}

//asks for the player's move
//checks if the place is already taken
//assigns new char value to location if it is empty
char playerMove(int row, int col, int playerTurn, char arr[3][3]) {
  do {
    printf("Which Row would you like?\n");
    scanf("%d", &row);
    printf("Which Col would you like?\n");
    scanf("%d", &col);
    if(arr[row][col] != ' ') { //if the space is already taken
      printf("Illegal Move\n");
    }
  } while(arr[row][col] != ' ');

  if(playerTurn == 1) {
    arr[row][col] = 'X';
  } else if(playerTurn == 2) {
    arr[row][col] = 'O';
  }
}

//function that checks for any win conditions within the array
int checkWin(char arr[3][3]) {
  int winStat = 0;
  //check for a win in any row
  for(int i = 0; i < 3; i++) {
    if(arr[i][0]!= ' ' && arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2]) {
      return 1;
    }
  }
  //check for a win in any column
  for(int i = 0; i < 3; i++) {
    if(arr[0][i] != ' ' && arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i]) {
      return 1;
    }
  }
  //check to see if there is a diagonal win
  if(arr[0][0] != ' ' && arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2]) {
    return 1;
  }
  if(arr[0][2] != ' ' && arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0]) {
    return 1;
  }
  return winStat;
}


int main() {
  int playerTurn = 1;
  int row, col;
  int inputs = 0; //variable to ensure there are not too many inputs (for Cat's Game)
  char arr[3][3] = {' ',' ',' ',' ',' ',' ',' ',' ',' '}; //Declaring 2D array for new game, init to empty

  printf("Welcome to Tic-Tac-Toe\n");
  printf("======================\n");
  displayPlayerTurn(playerTurn); //displays the current player's turn
  display(arr); //displays current board

  while(checkWin(arr) != 1) {
    playerMove(row, col, playerTurn, arr);
    inputs++;
    if(inputs == 9) { //if there are 9 inputs, the array is full - Cat's Game
      printf("Cat's Game!\n");
      display(arr); //display the end game board
      break; //exit the while loop
    }
    playerTurn = changeTurn(playerTurn); //switch to next player
    displayPlayerTurn(playerTurn); //display who is playing next
    display(arr);
  }
  
//check to make sure either "Cat's Game or ' ' Player Wins! is displayed
if(checkWin(arr) == 1) { //If a player won
  playerTurn = changeTurn(playerTurn);
    if(playerTurn == 1) {
      printf("X Player Wins!\n");
      display(arr);
    } else if(playerTurn == 2) {
      printf("O Player Wins!\n");
      display(arr);
    }
} else if(checkWin(arr) == 0) { //If it was a Cat's Game
  return 0;
}

  return 0;
}
