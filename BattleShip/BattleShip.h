// filename    BattleShip.h
// authors     Loren Anderson

// Specification for class BattleShip
// data object: a 2D dynamic array
// operations, create, destroy, initialize, print, assign ship placement, determine if a ship is sunk, determine if a ship is hit, adjust the contents of an array is evaluated as hit or sunk, return contents of a specified location

#include <fstream>
using namespace std;

#ifndef BATTLESHIPGAME_H
#define BATTLESHIPGAME_H

const int BOARD_SIZE = 10;

struct CarrierShip;
struct BattleShipShip;
struct CruiserShip;
struct SubmarineShip;
struct DestroyerShip;

class BattleShip{

public:
   // Constructor of Class BattleShip
   BattleShip();

   // Destructor of class BattleShip
   // called when isGameFinished
   ~BattleShip();

   // creates the game board
   // pre: board has been declared
   // post: the contents of board have been assigned ' '
   // usage: UserBoard.initializeBoard(board[][BOARD_SIZE])
   void initializeBoard();

   // prints the game board
   // post: the contents of the board is displayed
   // usage: UserBoard.printBoard()
   void printBoard();

   // gets ship location via user input
   // pre: shipSize has been assigned a value
   // post: the ship coordinates are assigned
   // usage: UserBoard.getCoodinates(carrier -> shipSize, carrier -> charRepresentation, carrier -> xLocation, carrier -> yLocation)
   void getCoodinates(int shipSize, char charRepresentation, int* xLocation, int* yLocation);

   // evaluates whether or not a ship has been sunk
   // pre: shipSize has been assigned a value
   // post: true is returned if the ship is sunk, otherwise false is returned
   // usage: if (UserBoard.isSunk(cruiser -> shipSize))
   bool isSunk(int shipSize);

   // evaluates whether or not the ship has been hit
   // pre: row and column have been assigned values from the user
   // post: true is returned if the ship is hit, otherwise false is returned
   // usage: if (isHit(UserBoard, locationX, locationY))
   bool isHit(BattleShip board, int row, int column);

   // displays the the result of a player's turn
   // pre: board is created, row, column, xDamage, yDamage, shipSize, charRepresentation, damageCounter, playerPoints are assigned values. statisticsOutput is open.
   // post: the result of the player's turn is stored in the board, as well as the location that was fired if the ship was hit, the fire location and result of the fire is written to statisticsOutput, and playerPoints, damageCounter are updated if the ship was hit.
   // usage: OpponentBlankBoard.shipDamage(OpponentBoard, locationX, locationY, opponentCarrier -> xDamage, opponentCarrier -> yDamage, opponentCarrier -> shipSize, opponentCarrier -> charRepresentation, opponentCarrier -> damageCounter, userPoints, statisticsOutput)
   void shipDamage(BattleShip board, int row, int column, int*& xDamage, int*& yDamage, int& shipSize, char charRepresentation, int& damageCounter, double& playerPoints, ofstream& statisticsOutput);

   // changes the board such that a ship is shown to be sunk
   // pre: xDamage and yDamage are filled [0... original shipSize - 1], charRepresentation is assigned a value, damageCounter is assigned the value equivalent to the original shipSize
   // post: the values stored in the board at the locations determined by xDamage and yDamge (ex. (xDamage[1], yDamage[1])) are changed to the character specified by charRepresentation
   // usage: displaySunkenShip(xDamage, yDamage, charRepresentation, damageCounter)
   void displaySunkenShip(int* xDamage, int* yDamage, char charRepresentation, int damageCounter);

   // returns the contents of the board at the specified row and column
   // pre: row and column are assigned values by the user
   // post: the character stored at the specified row and column are returned
   // usage: UserBoard.viewArrayContent(locationX, yLocation)
   char viewArrayContent(int row, int column);

   // determines if the placement of a ship is a valid spot
   // pre: shipSize, row, column, and orientation are assigned values
   // post: true is returned if the indicated row and column provide a valid ship placement, returns false otherwise
   // usage: while (isValidSpot(shipSize, shipRow, shipColumn, orientation))
   bool isValidSpot(int shipSize, int row, int column, int orientation);

   // book to determine whether or not the game is finished.
   // assigned to be true at the end of the game
   bool isGameFinished;

private:
   char** shipptr;
};
#endif
