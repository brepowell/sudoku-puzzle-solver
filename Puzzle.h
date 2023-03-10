// Created by Breanna Powell
// 501 B / FALL
// SID: 0641962
// Due: 2021 11 24

/** Sudoku Puzzle Board and Solver
    @file Puzzle.h*/
#ifndef PUZZLE_H
#define PUZZLE_H
#include <iostream>

class Puzzle
{
   class Square
   {

   public:
   /**Default constructor for Square
    initializes value_ to 0 and fixed_ to false*/
   Square();

   /** Return the value (0 - 9) contained inside a Square object
    @return The int value_ or -1 if the value is not set */
   int getValue() const;

   /** Set the value contained inside a Square object
    @post  If successful, the value within the Square object
   will be changed or set to the value given as a parameter
    @param newValue the value that will go into the Square
    @return  True if set is successful, or false if not.*/
   bool setValue(int newValue); 

   /** Return whether or not the value is fixed or variable
     within the Square object
    @return The bool contained by fixed_*/
   bool getFixed() const;

   /** Set the value contained inside a Square object
    @post  If successful, the Square object will either be
    set as fixed (true) or variable (false)
    @param isFixed bool that is true if the value is fixed, 
    false if the value is variable
    @return  True if set is successful, or false if not.*/
   bool setFixed(bool isFixed); 

   private:

   //The value that the square holds (between 0 and 9)
   int value_;

   //Indicates whether or not the Square value is fixed or variable
   bool fixed_;

   };//end nested Square class

public:
/** Default Constructor
   This constructor will create a Sudoku puzzle board
   puzzleSize decreases as fixed numbers are added
   numEmptySquares decreases as fixed numbers are added
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
 @param output will take in an ostream 
 @param puzzle will take in a Puzzle object */
friend std::ostream& operator<<(std::ostream& output, const Puzzle& puzzle);

/** Read the input of the puzzle (81 integers)
 @post This will read all of the numbers from the input
 @param input will take in an istream 
 @param puzzle will take in a Puzzle object */
friend std::istream& operator>>(std::istream& input, Puzzle& puzzle);

/** Return the value (0 - 9) contained inside a Square object
  Use the (row, column) location to find the object in the Puzzle array
  Look inside of the Square object by calling getValue().
 @param row the row location of a Square in the Puzzle 2D array
 @param col the column location of a Square in the Puzzle 2D array
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
 @param row the row location of a Square in the Puzzle 2D array
 @param col the column location of a Square in the Puzzle 2D array
 @param newValue the value that will go into the Square
  that will go into the Square
 @return  True if set is successful, or false if not.*/
bool set(int row, int col, int newValue);

/** Check if there is a variable Square in that row.
 @param row the row, passed by reference to be updated
 @param col the column, passed by reference to be updated
 @return  True if a variable Square is found, or false if not.*/
bool findEmpty(int &row, int &col);

/** Solve the Sudoku puzzle using recursive backtracking
 @pre There are no conflicts up to this point, and the
 puzzle is filled in up to the current row and column
 @post  If successful, the Sudoku will be solved 
  and all Squares will hold a value between 1 and 9
 @param row the row, initialized to 0
 @param col the column, initialized to 0
 @return  True if Sudoku is solved, or false if not.*/
bool solve(int row = 0, int col = 0);

private:

/** Check if the value exists already in the row
 @param row the row location of a Square in the Puzzle 2D array
 @param newValue the value that will go into the Square
 @return  True if the value exists in the row, or false if not.*/
bool isInRow(int row, int newValue) const;

/** Check if the value exists already in the column
 @param col the column location of a Square in the Puzzle 2D array
 @param newValue the value that will go into the Square
 @return  True if the value exists in the column, or false if not.*/
bool isInColumn(int col, int newValue) const;

/** Check if the value exists already in the region
 @param row the row location of a Square in the Puzzle 2D array
 @param col the column location of a Square in the Puzzle 2D array
 @param newValue the value that will go into the Square
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

//Helps with exceptions
//will change to false if the puzzle catches an exception
//within the istream operator overload
//then the solve function will return false
bool exceptionFound_;

//A 9x9 array that holds Square objects
Square puzzleBoard_[9][9];

};//end Puzzle class
#endif