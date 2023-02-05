#include "Character.h"
using namespace std;

int main()
{
    Character c1; 
    c1.insert("potion");
    c1.insert("crossbow");
    c1.insert("candle");
    c1.insert("cloak");
    c1.insert("sword");
    //c1.insert("book of spells");

    cout<<c1<<endl;
}