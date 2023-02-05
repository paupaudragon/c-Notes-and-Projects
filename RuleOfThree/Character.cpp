#include "Character.h"
using namespace std;

// constructor
Character::Character(string _name, int _capacity)
{
    name = _name;
    capacity = _capacity;
    toolHolder = new string[_capacity];
}

// Copy Constructor
Character::Character(const Character &source)
{
    cout << "Copy Constructor called" << endl;

    this->name = source.name;
    this->capacity = source.capacity;
    this->used = source.used;
    this->toolHolder = new string[source.capacity];                      // need a deep copy, assign space for in on the heap
    copy(source.toolHolder, source.toolHolder + used, toolHolder); // this could be done by a for loop.
}

// Overloaded Assignment Operator
Character &Character::operator=(const Character& source)
{
    cout << "Overloaded Assignment Call" << endl;

    // Check self assignment
    // gc1 = gc1;
    if (this == &source)
    {
        return *this; // this is a ptr, we want to return the actual object not the ptr
    }

    name = source.name;
    capacity = source.capacity;
    used = source.used;
    delete[]toolHolder;
    toolHolder = new string[capacity];
    //copy(source.toolHolder, source.toolHolder + used, this->toolHolder); // this could be done by a for loop.
    for(int i =0; i< capacity; i++){
        toolHolder[i] = source.toolHolder[i];
    }
    return *this;
}

// Destructor
Character::~Character()
{
    cout << "Destructor called for" << this->name
         << "at this mem locaton" << this << endl;

    delete[] toolHolder;
}

// Insert a new tool into toolHolder
void Character::insert(const string& toolName)
{
    if (used == capacity)
    {
        cout << "Tool is full" << endl;
    }
    else
    {
        toolHolder[used] = toolName;
        used++;
    }
}

// Overloaded insertion operator.
std::ostream &operator<<(std::ostream &os, const Character &character)
{
    os << "Character " << character.name << "has the following tools: " << std::endl
       << "| ";
    for (int i = 0; i < character.used; i++)
    {
        os << character.toolHolder[i] + " | ";
    }
    return os << std::endl;
}