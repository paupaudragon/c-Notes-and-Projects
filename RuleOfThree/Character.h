#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>

class Character
{
     friend std::ostream& operator<<(std::ostream& os, const Character& character);

public:
    static const int DEFAULT_CAPACITY = 5; // tool array size

    // Constructor
    Character(std::string name = "John", int capacity = DEFAULT_CAPACITY);

    // Copy Constructor 
    Character(const Character& source);

    // Overloaded Assignment 
    Character& operator=(const Character& source); //& is for chaining.

    // Destructor 
    ~Character();

    // Insert a new tool into the tool array
    void insert(const std::string& toolName);
private: 
    std::string name; 
    int capacity; 
    int used; 
    std::string* toolHolder;
};

#endif