#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> values{5, 10, 15};
    for (unsigned i = 0; i < values.size(); i++)
    {
        cout << values[i] << endl;
    }

    for (int value : values)
    {
        cout << value << endl;
    }

    // This can change the value of elements by passing &
    for (int &value : values)
    {
        value = 10;
    }

    
    
    //for (auto it = values.begin()...
    for (vector<int>::iterator it = values.begin();
         it != values.end();
         it++)
    {
        cout << *it << endl;
    }
}
