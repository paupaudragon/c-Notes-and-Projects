
#include<iostream>
#include<exception>
using namespace std;

void A(){

     int * array = new int[10000000000000]; 

}


// class Animal {
//     int age ; 
//     public: 
//     Animal(int age): age(age){
//         cout<<"Animal constructor"<<endl;
//     }

//     /**
//      * 1. vitural makes this method to be overwritten 
//      * 2. =0 makes this method abstract, inheritted classes have to have this method.
//      * 
//     */
//     virtual void speak() = 0; 
//     // { 
//     //     cout<<"Animal speak"<<endl;
//     // }

//     ~ Animal (){
//         cout<<"Animal destrcutor"<<endl;
//     }
// };
// /**
//  * Derived class doesnt get 
//  * 1. constructors ande destructors
//  * 2. static member 
//  * 3. = overloaded
// */
// class Cat : public Animal
// {
//     int lives;

// public:
//     Cat(int age, int lives) : Animal(age)
//     {

//         cout << "Cat constructor" << endl;
//         this->lives = lives;
//     }



//     /**
//      * virtual here doesn't do anything but to remind. 
//      * 
//     */
//     virtual void speak()
//     {
//         cout << "Cat speak" << endl;
//     }
// };

int main (){
    // // Animal things(5); 
    // // Cat c(5,5); 
    // // c.speak();


    // // Animal * animal = new Animal(5); 
    // Animal *animal = new Cat(50,50); // this will remain as Animal not cat. 
    // animal->speak(); 
    
    // Cat me (1,1); 
    // Animal& animals = me;
    // // delete animal;

     try
     {
         A();
     }
     catch (exception &e)
     {
         cout << "caught" << endl;
     }
}