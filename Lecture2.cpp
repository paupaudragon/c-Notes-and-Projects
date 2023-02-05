#include<iostream>
#include "Point.h"
using namespace std;

Point ::Point(double x, double y) : x(x), y(y) {}
Point Point::operator*(double scalar)
{
    Point scaledPoint; // compiler takes care of this mem waste
    scaledPoint.x = x * scalar;
    scaledPoint.y = y * scalar;
    return scaledPoint;
}

double Point ::getX()
{
    return x;
}
double Point ::getY()
{
    return y;
}
void Point ::setX(double _x)
{
    x =  _x;
}
void Point ::setY(double _y)
{
    y =  _y;
}




// void setSign(int number, int& sign);


// class Point {

// // private: // explicitly define
//     //instance variables and data members
// public:
//      double x, y; // c++ default private

//      // Could initialize values here 
// public:
//     Point (double intX, double intY) : x(intX), y(intY){ // 
//     // Point (double intX, double intY) : x{x}, y{y}{ // 
//         // x = intX;
//         // y = intY;

//         // initializing in the body could be expensive
//         // it construct a arbitury object and use the instance to assign ti the field

//         // this -> x; 
//         // (*this)
//     }

// // Constructor(sys default)
//     Point()= default;

//     Point operator*(double scalar){
//         Point scaledPoint; // compiler takes care of this mem waste
//         scaledPoint.x = x * scalar; 
//         scaledPoint.y = y * scalar; 
//         return scaledPoint;
//     }

//     //1/19
//     Point operator*(double scale){
//     Point result(this->x* scale, this -> x* scale); 
//     return result; 

//     //Destructor
//     //Destructors are needed when the class has acquired resources that need to be cleaned up
//     // memory
//     // open files/network connections/etc.

//     // ~Point (){

//     // }
// }
// };

// int main(){

//     // int f;
//     // setSign(1, f);
//     // cout << f << endl;
//     // setSign(-1, f);
//     // cout << f << endl;


//     // Point p; // error if using default constructor
//     // cout << p.x << endl;

//     Point p1(1.0, 2.0);
//     cout << p1.x << endl;


//     Point* ptPtr = &p1;
//     ptPtr -> x; 
//     //(&ptPtr) -> x; 
//     (*ptPtr).x;




//     /**
//      * New and Delete
//      * 
//     */

//     int* p = new int(4); 
//     delete p;
//     return 0;

//     //1/19


// }
// void setSign(int number, int& sign)
// {
//     if(number > 0)
//         sign =1;

//     if(number < 0)
//         sign = -1;
// }

/**
 * OOP
 * Encapsulation - API(DATA)
 * Abstarction - hide details of code
 * Inheritance -
 * Polymorphism
*/

/**
 * Struct : collect data into named type structure
 * bad abstraction and encapsulation(internal exposed)
 *
*/


