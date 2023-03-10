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
   puzzleSize decreases as fixed numbers are added
   numEmptySquares decreases as fixed numbers are added
   that holds 9-by-9 Square objects.*/
Puzzle::Puzzle() 
   :  puzzleSize_(9*9), 
   numEmptySquares_ (9*9),
   exceptionFound_(false)
{
}//end default constructor

/** Return the number of variable Squares in the puzzle
  based off of the original input, where 0’s represented
  variable Squares.
 @return int puzzleSize_*/
int Puzzle::size() const
{
   return puzzleSize_;
}//end size()

/** Return the current number of empty Squares 
  in the puzzle (this number will change)
 @return int numEmptySquares_*/
int Puzzle::numEmpty() const
{
   return numEmptySquares_;
}//end numEmpty()

/** Prints every square in the Sudoku puzzle
 @post This will print out the entire puzzle 
 @param output will take in an ostream 
 @param puzzle will take in a Puzzle object */
ostream& operator<<(ostream& output, const Puzzle& puzzle)
{
   //loop through the entire puzzle
   for (int row = 0; row < puzzle.MAXSQUARES_; row++){
      for (int col = 0; col < puzzle.MAXSQUARES_; col++){
         //output the vertical dividers:
         if(col == 2 || col == 5){
            output << puzzle.get(row, col);
            output << "|";
         }else if (col == 3 || col == 6){
            output << puzzle.get(row, col);           
         }else if (col == 0){
            output << " " << puzzle.get(row, col);
         }else if (col == 8){
            output << puzzle.get(row, col) << " " ;
         }else{
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

   output << endl;
   return output;
}//end ostream overload

/** Read the input of the puzzle (81 integers)
 @post This will read all of the numbers from the input
 @param input will take in an istream 
 @param puzzle will take in a Puzzle object */
istream& operator>>(istream& input, Puzzle& puzzle)
{
   char c; //for holding the input of each char
   int newValue; //for converting to an int and setting the value
            
   try
   {   
      for (int row = 0; row < puzzle.MAXSQUARES_; row++){
         for (int col = 0; col < puzzle.MAXSQUARES_; col++){
   
            //take in an input, using the istream get() method
            input.get(c);  //store it in ‘c’ variable

            //check if the char is a digit
            if(isdigit(c)){
               newValue = c - '0'; //cast the char into an int

               //set will check there are no conflicts as the value is added
               if(puzzle.set(row, col, newValue)){
                  if (newValue != 0){
                     //These are the fixed squares for the puzzle
                     puzzle.puzzleBoard_[row][col].setFixed(true);
                     //decrease the puzzle size as fixed values are added
                     puzzle.puzzleSize_--; 
                  }//end inner if
               }else{
                  puzzle.exceptionFound_ = true;
                  throw std::logic_error("Error: This puzzle is not legal");
                  return input;
               }
            }else{
               //if the character was not a digit, or cannot be added,
               //repeat the get() step for that column.
               col--;
            }//end else
         }//end inner for
      }//end outer for
   }//end try
   catch(std::logic_error logErr)
   {
      std::cout << logErr.what() << std::endl;  // Display error message      
   }

  puzzle.numEmptySquares_ = puzzle.puzzleSize_;
  return input;
}//end istream operator overload

/** Return the value (0 - 9) contained inside a Square object
  Use the (row, column) location to find the object in the Puzzle array
  Look inside of the Square object by calling getValue().
 @param row the row location of a Square in the Puzzle 2D array
 @param col the column location of a Square in the Puzzle 2D array
 @return The int value_ or -1 if the value is not set */
int Puzzle::get(int row, int col) const
{
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
 @param row the row location of a Square in the Puzzle 2D array
 @param col the column location of a Square in the Puzzle 2D array
 @param newValue the value that will go into the Square
  that will go into the Square
 @return  True if set is successful, or false if not.*/
bool Puzzle::set(int row, int col, int newValue)
{
   //If the Square is one of the fixed Squares that is permanent, 
   //it cannot be changed
   if(puzzleBoard_[row][col].getFixed()){
      return false;
   }else if (newValue == 0){
      //If the Square is being reset to 0, increase the number of empty squares
      numEmptySquares_++;
      puzzleBoard_[row][col].setValue(0);   
      return true;
   }else if (isInRow(row, newValue) || isInColumn(col, newValue) 
      || isInRegion(row, col, newValue)){
      //Check if the value exists in the row, column, or region - return false
      return false;
   }else{
      //Set() succeeds if the value is legal for this square 
      puzzleBoard_[row][col].setValue(newValue);
      numEmptySquares_--; //reduce the number of empty squares
      return true;
   }//end else

}//end set

/** Check if the value exists already in the row
 @param row the row location of a Square in the Puzzle 2D array
 @param newValue the value that will go into the Square
 @return  True if the value exists in the row, or false if not.*/
bool Puzzle::isInRow(int row, int newValue) const
{
   for (int col = 0; col < MAXSQUARES_; col++){
      if (get(row, col) == newValue)
         return true;
   }//end for

   return false;
}//end isInRow

/** Check if the value exists already in the column
 @param col the column location of a Square in the Puzzle 2D array
 @param newValue the value that will go into the Square
 @return  True if the value exists in the column, or false if not.*/
bool Puzzle::isInColumn(int col, int newValue) const
{
   for (int row = 0; row < MAXSQUARES_; row++){
      if (get(row, col) == newValue)
         return true;
   }//end for

   return false;
}//end isInColumn

/** Check if the value exists already in the region
 @param row the row location of a Square in the Puzzle 2D array
 @param col the column location of a Square in the Puzzle 2D array
 @param newValue the value that will go into the Square
 @return  True if the value exists in the column, or false if not.*/
bool Puzzle::isInRegion(int row, int col, int newValue) const
{
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
   for (int i = 0; i < 3; i++){
      for (int j = 0; j < 3; j++){
         if (get(i+startRowRegion, j+startColRegion) == newValue){
            return true;
         }//end if
      }//end inner for
   }//end outer for

   //The value was not found in the region
   return false;

}//end isInRegion

/** Check if there is a variable Square in that row.
 @param row the row, passed by reference to be updated
 @param col the column, passed by reference to be updated
 @return  True if a variable Square is found, or false if not.*/
bool Puzzle::findEmpty(int &row, int &col)
{
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
 @param row the row, initialized to 0
 @param col the column, initialized to 0
 @return  True if Sudoku is solved, or false if not.*/
bool Puzzle::solve(int row, int col)
{
   //If the input operator found an exception, return false
   if (exceptionFound_ == true)
      return false;

   //If there are no more empty squares, return true
   if (numEmpty() <= 0) 
      return true;

   //for each value from 1 through 9
   for (int newValue = 1; newValue <= 9; newValue++){
   //find an empty Square
   findEmpty(row, col); 

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


//** Sudoku Square */

/**Default constructor for Square
 initializes value_ to 0 and fixed_ to false*/
Puzzle::Square::Square()
   : value_(0), fixed_(false)
{
}//end default constructor

/** Return the value (0 - 9) contained inside a Square object
 @return The int value_ or -1 if the value is not set */
int Puzzle::Square::getValue() const
{
   if (value_ >= 0 && value_ <= 9){
      return value_;
   }else
      return -1;
}//end getValue

/** Set the value contained inside a Square object
 @post  If successful, the value within the Square object
will be changed or set to the value given as a parameter
 @param newValue the value that will go into the Square
 @return  True if set is successful, or false if not.*/
bool Puzzle::Square::setValue(int newValue)
{
   //Make sure that the Square is variable (not fixed) 
   //and the value is valid
   if (!getFixed() && newValue >= 0 && newValue <= 9){
      value_ = newValue;
      return true;
   }else{
      return false;
   }//end else
}//end setValue

/** Return whether or not the value is fixed or variable
  within the Square object
 @return The bool contained by fixed_*/
bool Puzzle::Square::getFixed() const
{
   return fixed_;
}//end getFixed

/** Set the value contained inside a Square object
 @post  If successful, the Square object will either be
 set as fixed (true) or variable (false)
 @param isFixed bool that is true if the value is fixed, 
 false if the value is variable
 @return  True if set is successful, or false if not.*/
bool Puzzle::Square::setFixed(bool isFixed)
{
   if (isFixed){
      fixed_ = true;
   }else
      fixed_= false;
   return fixed_;
}//end setFixed