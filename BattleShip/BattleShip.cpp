// filename   BattleShip.cpp
// author     Loren Anderson
#include "BattleShip.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Constructor of Class BattleShip
BattleShip::BattleShip() {
   shipptr = new char*[BOARD_SIZE];
   for (int row = 0; row < BOARD_SIZE; row++) {
      shipptr[row] = new char[BOARD_SIZE];
   }
   isGameFinished = false;
}

// Destructor of class BattleShip
BattleShip::~BattleShip() {
   if (isGameFinished) {
      char** delptr = shipptr;
      for (int row = 0; row < BOARD_SIZE; row++) {
         for (int column = 0; column < BOARD_SIZE; column++) {
            delptr[row][column] = '\0';
         }
      }
      shipptr = nullptr;
      delete [] delptr;
   }

}

// creates the game board
// pre: board has been declared
// post: the contents of board have been assigned ' '
// usage: UserBoard.initializeBoard(board[][BOARD_SIZE])
void BattleShip::initializeBoard() {
   for (int row = 0; row < BOARD_SIZE; row++) {
      for (int column = 0; column < BOARD_SIZE; column++) {
         shipptr[row][column] = '-';
      }
   }
}

// prints the game board
// post: the contents of the board is displayed
// usage: UserBoard.printBoard()
void BattleShip::printBoard() {
   cout << "  ";
   for (int column = 0; column < BOARD_SIZE; column++) {
      cout << column << " ";
   }
   cout << endl;
   for (int row = 0; row < BOARD_SIZE; row++) {
      cout << row << " ";
      for (int column = 0; column < BOARD_SIZE; column++) {
         cout << shipptr[row][column] << " ";
      }
      cout << endl;
   }

}

// gets ship location via user input
// pre: shipSize has been assigned a value
// post: the ship coordinates are assigned
// usage: UserBoard.getCoodinates(carrier -> shipSize, carrier -> charRepresentation, carrier -> xLocation, carrier -> yLocation)
void BattleShip::getCoodinates(int shipSize, char charRepresentation, int* xLocation, int* yLocation) {
   int shipRow, shipColumn, orientation;
   do {
      do {
         shipColumn = rand() % 10; // randomly choose the column to place the first piece of the ship
         shipRow = rand() % (10 - (shipSize - 1)); // randomly choose a row to place the ship
      } while (shipptr[shipRow][shipColumn] != '-');

      if (shipColumn > (10 - shipSize))
         orientation  = 0;
      else
         orientation = rand()%2; // 0 is veritcal orientation of the ship, 1 is horizontal orientation

   } while (!isValidSpot(shipSize, shipRow, shipColumn, orientation));

   switch (orientation) {
      case 0: // vertical orientation
            for (int i = 0; i < shipSize; i++) {
               shipptr[shipRow + i][shipColumn] = charRepresentation;
               xLocation[i] = shipRow + i;
               yLocation[i] = shipColumn;
            }
      break;
      case 1: // horizontal orientation
            for (int i = 0; i < shipSize; i++) {
               shipptr[shipRow][shipColumn + i] = charRepresentation;
               xLocation[i] = shipRow;
               yLocation[i] = shipColumn + i;
            }
      break;
    }

}

// evaluates whether or not a ship has been sunk
// pre: shipSize has been assigned a value
// post: true is returned if the ship is sunk, otherwise false is returned
// usage: if (UserBoard.isSunk(cruiser -> shipSize))
bool BattleShip::isSunk(int shipSize) {
   return shipSize == 0;
}

// evaluates whether or not the ship has been hit
// pre: row and column have been assigned values from the user
// post: true is returned if the ship is hit, otherwise false is returned
// usage: if (isHit(UserBoard, locationX, locationY))
bool BattleShip::isHit(BattleShip board, int row, int column) {
   return board.shipptr[row][column] != '-';
}

// displays the the result of a player's turn
// pre: board is created, row, column, xDamage, yDamage, shipSize, charRepresentation, damageCounter, playerPoints are assigned values. statisticsOutput is open.
// post: the result of the player's turn is stored in the board, as well as the location that was fired if the ship was hit, the fire location and result of the fire is written to statisticsOutput, and playerPoints, damageCounter are updated if the ship was hit.
// usage: OpponentBlankBoard.shipDamage(OpponentBoard, locationX, locationY, opponentCarrier -> xDamage, opponentCarrier -> yDamage, opponentCarrier -> shipSize, opponentCarrier -> charRepresentation, opponentCarrier -> damageCounter, userPoints, statisticsOutput)
void BattleShip::shipDamage(BattleShip board, int row, int column, int*& xDamage, int*& yDamage, int& shipSize, char charRepresentation, int& damageCounter, double& playerPoints, ofstream& statisticsOutput) {
   if (isHit(board, row, column) and board.shipptr[row][column] == charRepresentation) {
      shipptr[row][column] = '*';
      shipSize--;
      xDamage[damageCounter] = row;
      yDamage[damageCounter] = column;
      damageCounter++;
      playerPoints++;
      statisticsOutput << "(" << row << "," << column<< "): HIT!!!";
   }
   else {
      shipptr[row][column] = 'x';
      statisticsOutput << "(" << row << "," << column << "): MISS";

   }
   if (shipSize == 0) {
      displaySunkenShip(xDamage, yDamage, charRepresentation, damageCounter);
      shipSize--;
      statisticsOutput << "  The ship has successfully sunk!!";
   }


}

// changes the board such that a ship is shown to be sunk
// pre: xDamage and yDamage are filled [0... original shipSize - 1], charRepresentation is assigned a value, damageCounter is assigned the value equivalent to the original shipSize
// post: the values stored in the board at the locations determined by xDamage and yDamge (ex. (xDamage[1], yDamage[1])) are changed to the character specified by charRepresentation
// usage: displaySunkenShip(xDamage, yDamage, charRepresentation, damageCounter);
void BattleShip::displaySunkenShip(int* xDamage, int* yDamage, char charRepresentation, int damageCounter) {
   for (int i = 0; i < damageCounter; i++) {
      shipptr[xDamage[i]][yDamage[i]] = charRepresentation;
   }
}

// returns the contents of the board at the specified row and column
// pre: row and column are assigned values by the user
// post: the character stored at the specified row and column are returned
// usage: UserBoard.viewArrayContent(locationX, yLocation)
char BattleShip::viewArrayContent(int row, int column) {
   return shipptr[row][column];
}

// determines if the placement of a ship is a valid spot
// pre: shipSize, row, column, and orientation are assigned values
// post: true is returned if the indicated row and column provide a valid ship placement, returns false otherwise
// usage: while (isValidSpot(shipSize, shipRow, shipColumn, orientation))
bool BattleShip::isValidSpot(int shipSize, int row, int column, int orientation) {
   int sizeTracker = 0;
   bool isValid = true;
   while (sizeTracker < shipSize && isValid) {
      switch (orientation) {
         case 0: // vertical orientation
            isValid = (shipptr[row + sizeTracker][column] == '-');
         break;
         case 1:
            isValid = (shipptr[row][column + sizeTracker] == '-');
         break;
      }
      sizeTracker++;
   }
   return isValid;
}
