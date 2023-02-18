#include <iostream>
using namespace std;
class Top{
    int id; 
    public:
     Top(): id(id){
        cout<<"Top"<<endl;
    }
};


class Cat: virtual public Top
{
public:
    Cat():Top(1)
    {
        cout << "Cat constructor" << endl;
    }
     int getID(){
        return 2; 
    }
};

class Drawable : virtual public Top
{
public:
    Drawable(): Top(2)
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
    DrawabbleCat() : Cat(), Drawable(), Top(3)
    {
        cout << "DrawableCat" << endl;
    }
    int getID(){
        return Cat::getID(); // score specify use it from Cat class.
    }
};

int main()
{
    Cat c; 
    DrawabbleCat dc;
    cout<<dc.getID()<<endl;
    cout<<dc.Drawable::getID()<<endl;
    cout<<sizeof(dc)<<endl;
    return 0;
}