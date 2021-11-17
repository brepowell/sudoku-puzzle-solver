// Created by Breanna Powell
// 501 B / FALL
// SID: 0641962
// Due: 2021 11 24

#include <iostream>
//#include "Square.h"
#include "Puzzle.h"

using namespace std;

int main(int argc, char const *argv[])
{
//test 
//g++ *.cpp -std=c++11 -g -o test
//./test

   Puzzle sudoku;

   //test the output operator overload to see the puzzle
   cout << sudoku;

/*
   //test the input operator overload to see if it takes input
   //423751968759683124168249357945362871872915436316478295537194682691827543284536019
   cout << "Enter a valid Sudoku puzzle of 81 number characters (between 0 and 9): " <<endl;
   cin >> sudoku;
   cout << sudoku;
*/

/*
   //test findEmpty(0,0)
   cout << "Is there an empty Square on the grid? " 
        << sudoku.findEmpty(0,0)  <<endl; //should return true;
   
   //test solve();
   if (sudoku.solve())
      cout << sudoku;
   else
      cout << "This puzzle cannot be solved" <<endl;
*/

/* TESTS PASSED:

   Square s;
   //test all getters and setters for the Square class
   cout << "Is the Square fixed? (true is 1, false is 0): " 
        << s.getFixed() <<endl; //should return 0
   cout << "Does setValue work on a variable square? (true is 1, false is 0): " 
        << s.setValue(8) <<endl; //should return 1
   cout << "Out of bounds value in a variable square? (true is 1, false is 0): " 
        << s.setValue(-10) <<endl; //should return 0
   cout << "Does setFixed work? (true is 1, false is 0): " 
        << s.setFixed(true) <<endl; //should return 1
   cout << "Is the Square fixed? (true is 1, false is 0): " 
        << s.getFixed() <<endl; //should return 1
   cout << "Does set value work on a fixed square? (true is 1, false is 0): " 
        << s.setValue(5) <<endl; //should return 0
   cout << "What value does the square contain? " 
        << s.getValue() <<endl; //should return 8


   //test the getters and setters for the Puzzle class
   cout << "Does set() work? (true is 1, false is 0): " 
        << sudoku.set(0,0,5) <<endl; //should return 1
   cout << "Does get() work? (the value is 5): " 
        << sudoku.get(0,0) << endl; //should return 5
   cout << "What is the puzzle size? " 
        << sudoku.size() <<endl; //should return 81
   cout << "How many squares are empty? " 
        << sudoku.numEmpty() <<endl; //should return 80

   //test the check-for-duplicates functions:
   cout << "Does set() work? (true is 1, false is 0): " 
        << sudoku.set(0,0,5) <<endl; //should return 1
   cout << "Is the value 5 in the column 0? " 
        << sudoku.isInColumn(0,5)  <<endl; //should return true;
   cout << "Is the value 5 in the column 1? " 
        << sudoku.isInColumn(1,5)  <<endl; //should return false;
   cout << "Is the value 5 in the row 0? " 
        << sudoku.isInRow(0,5)  <<endl; //should return true;
   cout << "Is the value 5 in the row 1? " 
        << sudoku.isInRow(1,5) <<endl; //should return false;
   cout << "Is the value 5 in the first region? " 
        << sudoku.isInRegion(0,0,5) <<endl; //should return true;
   cout << "Is the value 5 in the middle region? " 
        << sudoku.isInRegion(5,5,5)  <<endl; //should return false;
*/

}//end main