// Created by Breanna Powell
// 501 B / FALL
// SID: 0641962
// Due: 2021 11 24

#include <iostream>
#include "Puzzle.h"

using namespace std;

int main(int argc, char const *argv[])
{
//test 
//g++ *.cpp -std=c++11 -g -o test
//./test

   Puzzle sudoku;
   //test the input operator overload to see if it takes input
   /*
   //4237519687596831241682493579453628718
   72915436316478295537194682691827543284536019
   //4237519687590831241682493509453628718
   72910436316478295537194680691827543284536010
   //4237519687590831241$682493509453628718
   7291043631-6478295537194680691827543284536010
   //4237519687590831241$688888888888888888
   24935094536287187291043631-6478295537194680691827543284536010
   */
   cout << "What is the puzzle size? " 
        << sudoku.size() <<endl; //should return 81 (initial size)
   cout << "How many squares are empty? " 
        << sudoku.numEmpty() <<endl; //should return 81

   cout << "Enter a valid Sudoku puzzle of 81 digits (between 0 and 9): " 
        <<endl;
   cin >> sudoku;
   cout << sudoku;

   cout << "What is the puzzle size? " 
        << sudoku.size() <<endl; //should return 6
   cout << "How many squares are empty? " 
        << sudoku.numEmpty() <<endl; //should return 0

   //test solve();
   if (sudoku.solve())
      cout << sudoku;
   else
      cout << "This puzzle cannot be solved" <<endl;

   //test get()
   cout << "What value is in row 8, column 8? (the value is 9): " 
        << sudoku.get(8,8) << endl; //should return 9

}//end main