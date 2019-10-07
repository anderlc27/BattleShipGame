# BattleShipGame
The classic game of Battleship is recreated with statistics of the game being played being recorded and written to an output file. Played via command terminal.

## Technical Description
The program uses a class called BattleShip to initilize and update player boards via the heap. As the game progresses, the attacks made by the user and computer are recorded into the 'BattleShipStatistics.txt' file. When the game ends, the number of shots, hits, misses, and ratio of hits to misses are written to the output file. This program utilizes the fstream, ctime, cstdlib, and iomanip libraries.

## Project Background
Although initially a school project, I wanted to dive further into writing in C++ and to begin learning about object-oriented programming. The project initially was going to consist of each ship having its own separate class. However, upon realizing that very little operations would be constantly performed on each ship, it seemed to be more efficient to store the ship information in structs and to use a single class to manipulate the board as a whole.
