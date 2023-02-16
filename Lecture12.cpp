#include <iostream>
using namespace std;

class Cat
{
public:
    Cat()
    {
        cout << "Cat constructor" << endl;
    }
     int getID(){
        return 2; 
    }
};

class Drawable
{
public:
    Drawable()
    {
        cout << "Drawable" << endl;
    }
    int getID(){
        return 1; 
    }
};

class DrawabbleCat : public Cat, public Drawable
{ // initializing order is the as listed here

public:
    // DrawabbleCat() : Drawable(), Cat()
    DrawabbleCat() : Cat(), Drawable()
    {
        cout << "DrawableCat" << endl;
    }
    int getID(){
        return Cat::getID(); // score specify use it from Cat class.
    }
};

int main()
{
    DrawabbleCat dc;
    cout<<dc.getID()<<endl;
    return 0;
}