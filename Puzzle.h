// Created by Breanna Powell
// 501 B / FALL
// SID: 0641962
// Due: 2021 11 24

/** Sudoku Puzzle Board and Solver
    @file Puzzle.h*/
#ifndef PUZZLE_H
#define PUZZLE_H
#include <iostream>
#include "Square.h"

class Puzzle
{

public:
/** Default Constructor
   This constructor will create a Sudoku puzzle board
   that holds 9-by-9 Square objects.*/
Puzzle(); 

/** Return the number of variable Squares in the puzzle
  based off of the original input, where 0’s represented
  variable Squares.
 @return int puzzleSize_*/
int size() const; 

/** Return the current number of empty Squares 
  in the puzzle (this number will change)
 @return int numEmptySquares_*/
int numEmpty() const; 

/** Prints every square in the Sudoku puzzle
 @post This will print out the entire puzzle 
 @param puzzle will take in a Puzzle object */
friend std::ostream& operator<<(std::ostream& output, const Puzzle& puzzle);

/** Read the input of the puzzle (81 integers)
 @post This will read all of the numbers from the input
 @param puzzle will take in a Puzzle object */
friend std::istream& operator>>(std::istream& input, Puzzle& puzzle);

/** Return the value (0 - 9) contained inside a Square object
  Use the (row, column) location to find the object in the Puzzle array
  Look inside of the Square object by calling getValue().
 @param row and col takes in two integer arguments for a (row, column) location
 @return The int value_ or -1 if the value is not set */
int get(int row, int col) const;

/** Check if the value exists within the row, column, or region
  If the location is safe to place a new value, 
  set the value contained inside a Square object
 @post  If successful, the value within the Square object
  at the location (row, column) will be changed or set 
  to the value given as a parameter.
  The number of empty squares will increase or decrease,
  depending on if the newValue is 0 or 1-9.
 @param int row, int column, int the newValue
  that will go into the Square
 @return  True if set is successful, or false if not.*/
bool set(int row, int col, int newValue);

/** Check if there is a variable Square in that row.
 @param int row and col, passed by reference to be updated
 @return  True if a variable Square is found, or false if not.*/
bool findEmpty(int &row, int &col);

/** Solve the Sudoku puzzle using recursive backtracking
 @pre There are no conflicts up to this point, and the
 puzzle is filled in up to the current row and column
 @post  If successful, the Sudoku will be solved 
  and all Squares will hold a value between 1 and 9
 @return  True if Sudoku is solved, or false if not.*/
bool solve(int row = 0, int col = 0);


private:

/** Check if the value exists already in the row
 @param int row, int the newValue
 @return  True if the value exists in the row, or false if not.*/
bool isInRow(int row, int newValue) const;

/** Check if the value exists already in the column
 @param int column, int the newValue
 @return  True if the value exists in the column, or false if not.*/
bool isInColumn(int col, int newValue) const;

/** Check if the value exists already in the region
 @param int column, int the newValue
 @return  True if the value exists in the column, or false if not.*/
bool isInRegion(int row, int col, int newValue) const;

//The maximum number of squares for each side of the board
const int MAXSQUARES_ = 9;

//The initial puzzle size should be 81,
//this will decrease as new fixed Squares are added
int puzzleSize_;

//The current number of squares that are empty
//this will decrease as new fixed Squares are added
//this will also fluxuate as choices are made in solving
int numEmptySquares_;

//A 9x9 array that holds Square objects
Square puzzleBoard_[9][9];

};//end Puzzle class
#endif