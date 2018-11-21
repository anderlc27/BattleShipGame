// filename    BattleShipGame.cpp
// author      Loren Anderson
// description The game of Battle Ship is recreated with statistics of the game being played are recorded

#include "BattleShip.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int POINTS_TO_WIN = 17;

struct CarrierShip {
   int shipSize = 5;
   char charRepresentation = 'c';
   int* xLocation = new int [shipSize];
   int* yLocation = new int [shipSize];
   int* xDamage = new int[shipSize];
   int* yDamage = new int[shipSize];
   int damageCounter = 0;
};

struct BattleShipShip {
   int shipSize = 4;
   char charRepresentation = 'b';
   int* xLocation = new int [shipSize];
   int* yLocation = new int [shipSize];
   int* xDamage = new int[shipSize];
   int* yDamage = new int[shipSize];
   int damageCounter = 0;
};

struct CruiserShip {
   int shipSize = 3;
   char charRepresentation = 'r';
   int* xLocation = new int [shipSize];
   int* yLocation = new int [shipSize];
   int* xDamage = new int[shipSize];
   int* yDamage = new int[shipSize];
   int damageCounter = 0;
};

struct SubmarineShip {
   int shipSize = 3;
   char charRepresentation = 's';
   int* xLocation = new int [shipSize];
   int* yLocation = new int [shipSize];
   int* xDamage = new int[shipSize];
   int* yDamage = new int[shipSize];
   int damageCounter = 0;
};

struct DestroyerShip {
   int shipSize = 2;
   char charRepresentation = 'd';
   int* xLocation = new int [shipSize];
   int* yLocation = new int [shipSize];
   int* xDamage = new int[shipSize];
   int* yDamage = new int[shipSize];
   int damageCounter = 0;
};

// sets the game board
// pre: board, carrier, battleShip, cruiser, submarine, and destroyer have been declared
// post: the board now contains the placement of the ships
// usage: setGameBoard(UserBoard, carrier, battleShip, cruiser, submarine, destroyer)
void setGameBoard(BattleShip& board, CarrierShip* carrier, BattleShipShip* battleShip, CruiserShip* cruiser, SubmarineShip* submarine, DestroyerShip* destroyer);

// gets the location of where the player wants to fire
// pre: locationX and locationY have been declared
// post: the values of the player are assigned to locationX and locationY
// usage getUserFireLocation(locaitonX, locationY)
void getUserFireLocation(int& locationX, int& locationY);

// prints new lines in the output file
// pre: DesiredNumber have been assigned a value, statisticsOutput has been openned
// post: new lines are printed in the output file
// usage printNewLines(2, statisticsOutput)
void printNewLines(int DesiredNumber, ofstream& statisticsOutput);

// prints a message based on who won
// pre: userPoints  and opponentPoints have been assigned a value, statisticsOutput has been openned
// post: a message is displayed on the screen and written in the output file
// usage: winCondition(userPoints, opponentPoints, statisticsOutput)
void winCondition(int userPoints, int opponentPoints, ofstream& statisticsOutput);

int main() {
   BattleShip UserBoard;
   BattleShip OpponentBoard;
   BattleShip OpponentBlankBoard;
   CarrierShip* carrier = new CarrierShip;
   BattleShipShip* battleShip = new BattleShipShip;
   CruiserShip* cruiser = new CruiserShip;
   SubmarineShip* submarine = new SubmarineShip;
   DestroyerShip* destroyer = new DestroyerShip;

   CarrierShip* opponentCarrier = new CarrierShip;
   BattleShipShip* opponentBattleShip = new BattleShipShip;
   CruiserShip* opponentCruiser = new CruiserShip;
   SubmarineShip* opponentSubmarine = new SubmarineShip;
   DestroyerShip* opponentDestroyer = new DestroyerShip;

   double opponentPoints = 0;
   double userPoints = 0;
   int locationX, locationY;
   double totalNumberOfShots = 0;

   ofstream statisticsOutput;
   statisticsOutput.open("BattleShipStatistics.txt");

   srand(time(0));

   UserBoard.initializeBoard();
   OpponentBoard.initializeBoard();
   OpponentBlankBoard.initializeBoard();

   setGameBoard(UserBoard, carrier, battleShip, cruiser, submarine, destroyer);
   setGameBoard(OpponentBoard, opponentCarrier, opponentBattleShip, opponentCruiser, opponentSubmarine, opponentDestroyer);

/*----------- GAME LOOP -----------*/

   while (opponentPoints < 17 && userPoints < 17) {
      system("clear");

      OpponentBoard.printBoard();
      cout << endl << endl << endl;

      OpponentBlankBoard.printBoard();
      cout << endl << endl << endl;

      UserBoard.printBoard();
      cout << endl << endl << endl;

      do {
         getUserFireLocation(locationX, locationY);
      } while (OpponentBlankBoard.viewArrayContent(locationX, locationY) != '-');

      if (OpponentBoard.viewArrayContent(locationX, locationY) == opponentCarrier -> charRepresentation) {
         statisticsOutput << "User Fire: ";

         OpponentBlankBoard.shipDamage(OpponentBoard, locationX, locationY, opponentCarrier -> xDamage, opponentCarrier -> yDamage, opponentCarrier -> shipSize, opponentCarrier -> charRepresentation, opponentCarrier -> damageCounter, userPoints, statisticsOutput);

         printNewLines(1, statisticsOutput);
      }

      else if (OpponentBoard.viewArrayContent(locationX, locationY) == opponentBattleShip -> charRepresentation) {
         statisticsOutput << "User Fire: ";

         OpponentBlankBoard.shipDamage(OpponentBoard, locationX, locationY, opponentBattleShip -> xDamage, opponentBattleShip -> yDamage, opponentBattleShip -> shipSize, opponentBattleShip -> charRepresentation, opponentBattleShip -> damageCounter, userPoints, statisticsOutput);

         printNewLines(1, statisticsOutput);
      }

      else if (OpponentBoard.viewArrayContent(locationX, locationY) == opponentCruiser -> charRepresentation) {
         statisticsOutput << "User Fire: ";

         OpponentBlankBoard.shipDamage(OpponentBoard, locationX, locationY, opponentCruiser -> xDamage, opponentCruiser -> yDamage, opponentCruiser -> shipSize, opponentCruiser -> charRepresentation, opponentCruiser -> damageCounter, userPoints, statisticsOutput);

         printNewLines(1, statisticsOutput);
      }

      else if (OpponentBoard.viewArrayContent(locationX, locationY) == opponentSubmarine -> charRepresentation) {
         statisticsOutput << "User Fire: ";

         OpponentBlankBoard.shipDamage(OpponentBoard, locationX, locationY, opponentSubmarine -> xDamage, opponentSubmarine -> yDamage, opponentSubmarine -> shipSize, opponentSubmarine -> charRepresentation, opponentSubmarine -> damageCounter, userPoints, statisticsOutput);

         printNewLines(1, statisticsOutput);
      }

      else {
         statisticsOutput << "User Fire: ";

         OpponentBlankBoard.shipDamage(OpponentBoard, locationX, locationY, opponentDestroyer -> xDamage, opponentDestroyer -> yDamage, opponentDestroyer -> shipSize, opponentDestroyer -> charRepresentation, opponentDestroyer -> damageCounter, userPoints, statisticsOutput);

         printNewLines(1, statisticsOutput);
      }

      do {
         locationX = rand() % 10;
         locationY = rand() % 10;
      } while (UserBoard.viewArrayContent(locationX, locationY) == '*' && UserBoard.viewArrayContent(locationX, locationY) == 'x');

      if (UserBoard.viewArrayContent(locationX, locationY) == carrier -> charRepresentation) {
         statisticsOutput << "Opponent Fire: ";

         UserBoard.shipDamage(UserBoard, locationX, locationY, carrier -> xDamage, carrier -> yDamage, carrier -> shipSize, carrier -> charRepresentation, carrier -> damageCounter, opponentPoints, statisticsOutput);

         printNewLines(2, statisticsOutput);
      }

      else if (UserBoard.viewArrayContent(locationX, locationY) == battleShip -> charRepresentation) {
         statisticsOutput << "Opponent Fire: ";

         UserBoard.shipDamage(UserBoard, locationX, locationY, battleShip -> xDamage, battleShip -> yDamage, battleShip -> shipSize, battleShip -> charRepresentation, battleShip -> damageCounter, opponentPoints, statisticsOutput);

         printNewLines(2, statisticsOutput);
      }

      else if (UserBoard.viewArrayContent(locationX, locationY) == cruiser -> charRepresentation) {
         statisticsOutput << "Opponent Fire: ";

         UserBoard.shipDamage(UserBoard, locationX, locationY, cruiser -> xDamage, cruiser -> yDamage, cruiser -> shipSize, cruiser -> charRepresentation, cruiser -> damageCounter, opponentPoints, statisticsOutput);

         printNewLines(2, statisticsOutput);
      }

      else if (UserBoard.viewArrayContent(locationX, locationY) == submarine -> charRepresentation) {
         statisticsOutput << "Opponent Fire: ";

         UserBoard.shipDamage(UserBoard, locationX, locationY, submarine -> xDamage, submarine -> yDamage, submarine -> shipSize, submarine -> charRepresentation, submarine -> damageCounter, opponentPoints, statisticsOutput);

         printNewLines(2, statisticsOutput);
      }

      else {
         statisticsOutput << "Opponent Fire: ";

         UserBoard.shipDamage(UserBoard, locationX, locationY, destroyer -> xDamage, destroyer -> yDamage, destroyer -> shipSize, destroyer -> charRepresentation, destroyer -> damageCounter, opponentPoints, statisticsOutput);

         printNewLines(2, statisticsOutput);
      }
      totalNumberOfShots++;
   }

   UserBoard.isGameFinished = true;
   OpponentBlankBoard.isGameFinished = true;
   OpponentBoard.isGameFinished = true;
   winCondition(userPoints, opponentPoints, statisticsOutput);

   statisticsOutput << "*** User Stats ***\n";
	statisticsOutput << fixed << setprecision(0) << "Number of Hits: " << userPoints << endl;
	statisticsOutput << "Number of Misses: " << totalNumberOfShots - userPoints << endl;
   statisticsOutput << "Total Number of Shots: " << totalNumberOfShots << endl;
	statisticsOutput << "Hit to Miss Ratio: ";
   statisticsOutput << fixed << setprecision(2) << (userPoints / (totalNumberOfShots - userPoints)) * 100.0 << "% " << endl;

   printNewLines(3, statisticsOutput);

   statisticsOutput << "*** Opponent Stats ***\n";
	statisticsOutput << fixed << setprecision(0) << "Number of Hits: " << opponentPoints << endl;
	statisticsOutput << "Number of Misses: " << totalNumberOfShots - opponentPoints << endl;
   statisticsOutput << "Total Number of Shots: " << totalNumberOfShots << endl;
	statisticsOutput << "Hit to Miss Ratio: ";
   statisticsOutput << fixed << setprecision(2) << (opponentPoints / (totalNumberOfShots - opponentPoints)) * 100.0 << "% " << endl;

   return 0;
}

// prints new lines in the output file
// pre: DesiredNumber have been assigned a value, statisticsOutput has been openned
// post: new lines are printed in the output file
// usage printNewLines(2, statisticsOutput)
void printNewLines(int DesiredNumber, ofstream& statisticsOutput) {
   for (int count = 0; count < DesiredNumber; count++) {
      statisticsOutput << endl;
   }
}

// sets the game board
// pre: board, carrier, battleShip, cruiser, submarine, and destroyer have been declared
// post: the board now contains the placement of the ships
// usage: setGameBoard(UserBoard, carrier, battleShip, cruiser, submarine, destroyer)
void setGameBoard(BattleShip& board, CarrierShip* carrier, BattleShipShip* battleShip, CruiserShip* cruiser, SubmarineShip* submarine, DestroyerShip* destroyer) {

   board.getCoodinates(carrier -> shipSize, carrier -> charRepresentation, carrier -> xLocation, carrier -> yLocation);
   board.getCoodinates(battleShip -> shipSize, battleShip -> charRepresentation, battleShip -> xLocation, battleShip -> yLocation);
   board.getCoodinates(cruiser -> shipSize, cruiser -> charRepresentation, cruiser -> xLocation, cruiser -> yLocation);
   board.getCoodinates(submarine -> shipSize, submarine -> charRepresentation, submarine -> xLocation, submarine -> yLocation);
   board.getCoodinates(destroyer -> shipSize, destroyer -> charRepresentation, destroyer -> xLocation, destroyer -> yLocation);
}

// gets the location of where the player wants to fire
// pre: locationX and locationY have been declared
// post: the values of the player are assigned to locationX and locationY
// usage getUserFireLocation(locaitonX, locationY)
void getUserFireLocation(int& locationX, int& locationY) {
   cout << "Please enter fire location:" << endl;
   cout << "row ->";
   cin >> locationX;
   cout << "column ->";
   cin >> locationY;
}

// prints a message based on who won
// pre: userPoints  and opponentPoints have been assigned a value, statisticsOutput has been openned
// post: a message is displayed on the screen and written in the output file
// usage: winCondition(userPoints, opponentPoints, statisticsOutput)
void winCondition(int userPoints, int opponentPoints, ofstream& statisticsOutput) {
	if (userPoints == POINTS_TO_WIN) {
		cout << endl << endl << "Congrats! You have defeated your opponent in this war!!" << endl;
		statisticsOutput << "\nUser wins, Opponent loses\n\n";
	}
	if (opponentPoints == POINTS_TO_WIN) {
		cout << endl << endl << "I'm Sorry, but your opponent has destroyed all of the ships in your arsenal..." << endl;
		statisticsOutput << "\nOpponent wins, User loses\n\n";
	}
}
