// Created by Breanna Powell
// 501 B / FALL
// SID: 0641962
// Due: 2021 11 24

#include "Square.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
//test 
//g++ *.cpp -std=c++11 -g -o test
//./test

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

}//end main