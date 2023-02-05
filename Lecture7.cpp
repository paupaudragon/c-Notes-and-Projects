#include<iostream>
//using namespace std; std has max function
using  std::cout;
using  std::endl;;


template<typename T>
    T max(T val1, T val2){
        if(val1>val2)
            return val1;
        else return val2;
    }

int main(){
    int biggest = max(5,2);
    cout<< biggest << endl;
}

