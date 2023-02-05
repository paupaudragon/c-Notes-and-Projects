#include<iostream>
using namespace std;

void odd (int x);
void even (int x);

int main(){

    /**
     * How to run C++ file 
     * 1) Compile c++ by clicking run and it will generate a .exe file along the .cpp.
     * 2) General run command: g++ file.cpp
     * 
    */

//    cout<< "Hello" << endl;

   /**
    * Undefined behavior
    * C++ doesn't show error until it's compiled. 
    * It would assign random value to an integer for example.
    * Use "g++ -Wall Lecture.cpp" to dispaly errors
   */

//    int num;
//    int num2;
//    cout << num << endl;
//    cout << num2 << endl;

    /**
     * Array 
     * 1) block of memory.
     * 2) No object behavior: query for size.
     * 3) Arrays are blocks of static memory whose size must be determined at compile time, before the program runs.
    */

    //1) Declaration and initialization
    //int array [5]; //set a block of memory for int array size 5.
    //int array2 [] {1,2,3,4}; // universal initialization doesn't need =.

    //2) Access arrays 
    // Assigning array element to a variable or vice versa is assigning value not reference.
    // int x = array2[0];
    // cout << x << endl;

    // array2[0] = 10; 
    // cout << array2[0] << endl;
    // cout << x << endl;
    
    // x=2;
    // cout << array2[0] << endl;
    // cout << x << endl;

    //2) Out of bound 
    //Out-of-bound error will not show in compile time. 
    // int array2 [] {1,2,3,4}; // universal initialization doesn't need =.
    // cout << array2[4] << endl; // this would print some random number even thought array size is 4


    /**
     * Function
     * 1) Declartion vs Definition(the code)
     *  - Declaration and definition together before main 
     *  - Declaration before main, place the code after main(necessary when functions call each other)
    */

    //   int i;
    //   do {
    //     cout << "Please, enter number (0 to exit): ";
    //     cin >> i;
    //     odd (i);
    //   } while (i!=0);

    /**
     * IO streams
     * std::cin
     * std::cout
     * std::cerr
     * 
     * $ ls -t > myFiles.txt      redirects stdout to a file //prints out -o file names into text
     * $ sort < myFiles.txt	    turns a file into stdin // print out .txt into terminal
     *  $ ls –lt | more		 stdout of ls to stdin of more //undifined

    */

cout << "hellow" << endl;

    return 0;
}

//Function definition
// void odd (int x)
// {
//   if ((x%2)!=0) cout << "It is odd.\n";
//   else even (x);
// }

// void even (int x)
// {
//   if ((x%2)==0) cout << "It is even.\n";
//   else odd (x);
// }