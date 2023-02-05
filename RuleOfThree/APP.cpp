#include "Character.h"
using namespace std;
Character exampleCopyConstructor(Character tempC)
{
    cout << "Copy Constructor is called twice." << endl;
    cout << "Once for the formal param passed by value." << endl;
    cout << "Once for the return value" << endl;
    return tempC;
}

int main()
{
    Character c1;
    c1.insert("potion");
    c1.insert("crossbow");
    c1.insert("candle");
    c1.insert("cloak");
    c1.insert("sword");
    c1.insert("book of spells");

    // Output of this:
    //     Tool is full
    // Character Johnhas the following tools:
    // | potion | crossbow | candle | cloak | sword |

    // Destructor called for John at this mem locaton0x7ffcf9fcf9a0
    cout << c1 << endl; // c1 is on the stack and once main is done, destructor is called.

    // Output of this:
    //     Tool is full
    // Character Johnhas the following tools:
    // | potion | crossbow | candle | cloak | sword |

    // =============
    // Copy Constructor called // *1
    // Copy Constructor is called twice.
    // Once for the formal param passed by value.
    // Once for the return value
    // Copy Constructor called  //*3
    // Destructor called for Bob at this mem locaton0x7ffc8c886080 //*4
    // Destructor called for Bob at this mem locaton0x7ffc8c886050 //*5
    // Destructor called for Bob at this mem locaton0x7ffc8c886020 //*6
    // Destructor called for John at this mem locaton0x7ffc8c885ff0
    Character c2("Bob", 5);
    c2.insert("axe");
    cout << "=============" << endl;
    exampleCopyConstructor(c2); // Result in *1 to *3. *1 is from the param, and *3 is from the return.
    //*4 is from the param, *5 is the return, *6 is the end of the main.

    cout << "=============" << endl;
    // Copy Constructor is invoked
    Character c3 = c2;
    cout << "=============" << endl;
    // Overlaoded Assignment is invoked
    c2 = c1;

    cout << "c2: " << c2 << endl;
    cout << "c1: " << c1 << endl;
    cout << "c3: " << c3 << endl;
}