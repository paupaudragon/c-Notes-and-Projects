#include<iostream>
using namespace std; 

int main(){
    int array[10] {1}; //only set the first elemnet
    cout << array[0] << endl;
    cout << array[9] << endl;
}

// see PointDrive.cpp

//Design Rules for .h files

/**
 * #ifndef EX_H
 * #define EX_H
 * class Ex {
 * }; 
 * #endif
 *
*/


//g++ -c Point.cpp to make into .o file 
// ls Point.o = *.o
// cpp => .o => executable


// Make file 
// “Thing to make”: “what it depends on” “How to make it”

//
