// Created by Breanna Powell
// 501 B / FALL
// SID: 0641962
// Due: 2021 11 24

//** Sudoku Puzzle and Solver */
#include <iostream>
#include "Puzzle.h"
using namespace std;

/** Default Constructor
   This constructor will create a Sudoku puzzle board
   that holds 9-by-9 Square objects.*/
Puzzle::Puzzle() 
   :  puzzleSize_(9*9), 
   numEmptySquares_ (9*9)
{
   //puzzleSize decreases as fixed numbers are added
   //numEmptySquares decreases as fixed numbers are added
}//end default constructor

/** Return the number of variable Squares in the puzzle
  based off of the original input, where 0’s represented
  variable Squares.
 @return int puzzleSize_*/
int Puzzle::size() const{
   return puzzleSize_;
}//end size()

/** Return the current number of empty Squares 
  in the puzzle (this number will change)
 @return int numEmptySquares_*/
int Puzzle::numEmpty() const{
   return numEmptySquares_;
}//end numEmpty()

/** Prints every square in the Sudoku puzzle
 @post This will print out the entire puzzle 
 @param This will take in a Puzzle object */
ostream& operator<<(ostream& output, const Puzzle& puzzle){
   //loop through the entire puzzle
   for (int row = 0; row < puzzle.MAXSQUARES_; row++){
      for (int col = 0; col < puzzle.MAXSQUARES_; col++){
         //output the vertical dividers:
         if(col == 2 || col == 5){
            output << puzzle.get(row, col);
            output << "|";
         }
         else if (col == 3 || col == 6){
            output << puzzle.get(row, col);           
         }
         else if (col == 0){
            output << " " << puzzle.get(row, col);
         }
         else if (col == 8){
            output << puzzle.get(row, col) << " " ;
         }
         else{
            output << " " << puzzle.get(row, col) << " " ;    
         }

      }//end inner for loop

      //output the horizontal dividers
      if(row == 2 || row == 5){
         output << endl;
         output << "------+-----+------";
      }
      output << endl;
   }//end outer for loop
   return output;

}//end ostream overload

/** Read the input of the puzzle (81 integers)
 @post This will read all of the numbers from the input
 @param This will take in a Puzzle object */
istream& operator>>(istream& input, Puzzle& puzzle){
   char c; //for holding the input of each char
   int newValue; //for converting to an int and setting the value

   for (int row = 0; row < puzzle.MAXSQUARES_; row++){
      for (int col = 0; col < puzzle.MAXSQUARES_; col++){
         //take in an input, using the istream get() method
         input.get(c);  //store it in ‘c’ variable

         //check if the char is a digit
         if(isdigit(c)){
            newValue = c - '0'; //cast the char into an int
            
            //set will check if the entry has no conflicts as the value is added
            if(puzzle.set(row, col, newValue)){
               if (newValue != 0){
                  //These are the fixed squares for the puzzle
                  puzzle.puzzleBoard_[row][col].setFixed(true);
                  puzzle.puzzleSize_--; //decrease the puzzle size as fixed values are added
               }//end inner if
            }//end outer if

         }//end if
         else{
             //if the character was not a digit, or cannot be added,
             //repeat the get() step for that column.
             col--;
         }//end else

      }//end inner for
   }//end outer for
  return input;
}//end istream operator overload

/** Return the value (0 - 9) contained inside a Square object
  Use the (row, column) location to find the object in the Puzzle array
  Look inside of the Square object by calling getValue().
 @param Takes in two integer arguments for a (row, column) location
 @return The int value_ or -1 if the value is not set */
int Puzzle::get(int row, int col) const{
   return puzzleBoard_[row][col].getValue();
}//end get

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
bool Puzzle::set(int row, int col, int newValue){
   //If the Square is one of the fixed Squares that is permanent, it cannot be changed
   if(puzzleBoard_[row][col].getFixed()){
      return false;
   }

   //If the Square is being reset to 0, increase the number of empty squares
   else if (newValue == 0){
      if (numEmpty() < (MAXSQUARES_ * MAXSQUARES_))
         numEmptySquares_++; //This value should not increase beyond 81
      puzzleBoard_[row][col].setValue(0);
      return true;
   }

   //Check if the value exists in the row, column, or region - return false
   else if (isInRow(row, newValue) || isInColumn(col, newValue) || isInRegion(row, col, newValue)){
      return false;
   }

   //Set() succeeds if the value is legal for this square 
   else{
      puzzleBoard_[row][col].setValue(newValue);
      numEmptySquares_--; //reduce the number of empty squares
      return true;
   }

}//end set

/** Check if the value exists already in the row
 @param int row, int the newValue
 @return  True if the value exists in the row, or false if not.*/
bool Puzzle::isInRow(int row, int newValue) const{
   for (int col = 0; col < MAXSQUARES_; col++){
      if (get(row, col) == newValue)
         return true;
   }
   return false;
}//end isInRow

/** Check if the value exists already in the column
 @param int column, int the newValue
 @return  True if the value exists in the column, or false if not.*/
bool Puzzle::isInColumn(int col, int newValue) const{
   for (int row = 0; row < MAXSQUARES_; row++){
      if (get(row, col) == newValue)
         return true;
   }
   return false;
}//end isInColumn

/** Check if the value exists already in the region
 @param int column, int the newValue
 @return  True if the value exists in the column, or false if not.*/
bool Puzzle::isInRegion(int row, int col, int newValue) const{
   //Figure out which region to use - by row
   int startRowRegion = 0; //temp variable for start row
   int startColRegion = 0; //temp variable for start column

   if (row >= 3 && row < 6)
      startRowRegion = 3;
   else if (row >= 6)
      startRowRegion = 6;

   //Figure out which region to use - by column
   int startCol = 0; //temp variable for start column
   if (col >= 3 && col < 6)
      startColRegion = 3;
   else if (col >= 6)
      startColRegion = 6;

   //Iterate through the region, from start point in upper left corner
   for (int i= 0; i< 3; i++){
      for (int j= 0; j< 3; j++){
         if (get(i+startRowRegion, j+startColRegion) == newValue){
            return true;
         }//end if
      }//end inner for
   }//end outer for

   //The value was not found in the region
   return false;

}//end isInRegion

/** Check if there is a variable Square in that row.
 @param int row and col, passed by reference to be updated
 @return  True if a variable Square is found, or false if not.*/
bool Puzzle::findEmpty(int &row, int &col){
   for (row = 0; row < MAXSQUARES_; row++){
      for (col = 0; col < MAXSQUARES_; col++){
         if (get(row, col)  == 0)
            return true;
      }//end inner for
   }//end outer for
   return false;
}//end findEmpty

/** Solve the Sudoku puzzle using recursive backtracking
 @pre There are no conflicts up to this point, and the
 puzzle is filled in up to the current row and column
 @post  If successful, the Sudoku will be solved 
  and all Squares will hold a value between 1 and 9
 @return  True if Sudoku is solved, or false if not.*/
bool Puzzle::solve(int row, int col){

   //If there are no more empty squares, return true
   if (numEmpty() <= 0) 
      return true;
   //find an empty Square
   findEmpty(row, col); 

   //for each value from 1 through 9
   for (int newValue = 1; newValue <= 9; newValue++){
   //choose:
      if (set(row, col, newValue)){  //if value is legal, set square to it
         //explore:
         if (solve(row + 1, col))
            return true;
         //unchoose:
         set(row, col, 0); //erase square value
      }//end outer if
   }//end for
   return false;
}//end solve