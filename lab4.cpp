#include <iostream>
#include "lab4.h"
using namespace std;

int *getIntptr();

int main()
{
    // int vals[3] {1,2,3};
    // int* vals = new int[3];
    // vals[3] =1;

    // cout<<vals[3]<<endl;

    int *val = new int[4];
    int *same_mem = val;

    std::cout << val << " " << same_mem << std::endl;
    delete[] val;
    // delete same_mem;

    int *ptr = getIntPtr();
    std::cout << ptr << " " << *ptr << std::endl;
}

int *getIntPtr()
{
    int number = 5;
    return &number;
}