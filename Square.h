// Created by Breanna Powell
// 501 B / FALL
// SID: 0641962
// Due: 2021 11 24

/** Sudoku Puzzle Square
    @file Square.h*/
#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>

class Square
{

public:
Square();

/** Return the value (0 - 9) contained inside a Square object
 @return The int value_ or -1 if the value is not set */
int getValue() const;

/** Set the value contained inside a Square object
 @post  If successful, the value within the Square object
will be changed or set to the value given as a parameter
 @param int the newValue that will go into the Square
 @return  True if set is successful, or false if not.*/
bool setValue(int newValue); 

/** Return whether or not the value is fixed or variable
  within the Square object
 @return The bool contained by fixed_*/
bool getFixed() const;

/** Set the value contained inside a Square object
 @post  If successful, the Square object will either be
 set as fixed (true) or variable (false)
 @param bool isFixed (true if the value is fixed, false
 if the value is variable)
 @return  True if set is successful, or false if not.*/
bool setFixed(bool isFixed); 

private:

//The value that the square holds (between 0 and 9)
int value_;

//Indicates whether or not the Square value is fixed or variable
bool fixed_;

};//end Square class
#endif