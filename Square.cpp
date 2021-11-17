// Created by Breanna Powell
// 501 B / FALL
// SID: 0641962
// Due: 2021 11 24

//** Sudoku Square */
#include <iostream>
#include "Square.h"
using namespace std;

//Default constructor - initializes value_ to 0 and fixed_ to false
Square::Square()
   : value_(0), fixed_(false)
{
}//end default constructor

/** Return the value (0 - 9) contained inside a Square object
 @return The int value_ or -1 if the value is not set */
int Square::getValue() const{
   if (value_ >= 0 && value_ <= 9){
      return value_;
   }//end if
   else
      return -1;
}//end getValue

/** Set the value contained inside a Square object
 @post  If successful, the value within the Square object
will be changed or set to the value given as a parameter
 @param int the newValue that will go into the Square
 @return  True if set is successful, or false if not.*/
bool Square::setValue(int newValue){
   //Make sure that the Square is variable (not fixed) 
   //and the value is valid
   if (!getFixed() && newValue >= 0 && newValue <= 9){
      value_ = newValue;
      return true;
   }//end if
   else{
      return false;
   }//end else
}//end setValue

/** Return whether or not the value is fixed or variable
  within the Square object
 @return The bool contained by fixed_*/
bool Square::getFixed() const{
   return fixed_;
}//end getFixed

/** Set the value contained inside a Square object
 @post  If successful, the Square object will either be
 set as fixed (true) or variable (false)
 @param bool isFixed (true if the value is fixed, false
 if the value is variable)
 @return  True if set is successful, or false if not.*/
bool Square::setFixed(bool isFixed){
   if (isFixed){
      fixed_ = true;
   }//end if
   else
      fixed_= false;
   return fixed_;
}//end setFixed